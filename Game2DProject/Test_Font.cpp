/*#include "gnLib.h"
#include "include/GameCore/GameCore.h"
#include "include/Graphics/Graphics.h"
#include "include/Common/Macro.h"
#include <Windows.h>
#include <tchar.h>
#include <locale.h>
#include <wchar.h>
#include "include/Font/Font.h"

/*
void gnMain() {
	App app;

	setlocale(LC_CTYPE, "ja_JP.UTF-8");

	TCHAR a = 'a';

	while (app.update()) {
		app.begin();

		Debug::drawFormatText(320, 240, Color::Black, "%s", _T("���͂悤"));

		app.end();
	}
}
*/

/*
void gnMain() {
	App app;

	HRESULT hr;

	// �t�H���g�̐���
	static const int fontsize = 100;
	LOGFONT logF = {
		fontsize,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		SHIFTJIS_CHARSET,
		OUT_TT_ONLY_PRECIS,
		CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY,
		FIXED_PITCH | FF_MODERN,
		"�l�r �S�V�b�N"
	};

	HFONT hFont{ CreateFontIndirectA(&logF) };
	if (!hFont) {
		return;
	}

	// device�R���e�L�X�g�擾
	// �f�o�C�X�Ƀt�H���g���������Ȃ���GetGlyphOutline�֐��̓G���[�ƂȂ�
	HDC hdc = GetDC(NULL);
	HFONT oldFont = (HFONT)SelectObject(hdc, hFont);

	// �����R�[�h�擾
	const TCHAR* c = "����������";
	UINT code{ 0 };	

#if _UNICODE
	code = (UINT)&c;
#else
	if (IsDBCSLeadByte(*c)) {
		code = (BYTE)c[0] << 8 | (BYTE)c[1];
	}
	else {
		code = c[0];
	}
#endif

	// �t�H���g�r�b�g�}�b�v�̎擾
	TEXTMETRIC tm;
	GetTextMetrics(hdc, &tm);
	GLYPHMETRICS gm;
	const MAT2 mat = { {0,1}, {0, 0}, {0, 0},{0,1} };
	DWORD size = GetGlyphOutline(hdc, code, GGO_GRAY4_BITMAP, &gm, 0, nullptr, &mat);
	BYTE* ptr = new BYTE[size];
	GetGlyphOutline(hdc, code, GGO_GRAY4_BITMAP, &gm, size, ptr, &mat);

	// �f�o�C�X�R���e�L�X�g�ƃt�H���g�n���h���̊J��
	SelectObject(hdc, oldFont);
	DeleteObject(hFont);
	ReleaseDC(NULL, hdc);

	// ���_���
	float a = 1.0f;
	float fTexW = gm.gmCellIncX * a;
	float fTexH = tm.tmHeight * a;
	DWORD fontColor = 0x80ffffff;

	Vertex2D vx[] = {
		{fTexW, 0.0f,  0.0f, 1.0f, fontColor, 1.0f, 0.0f},
		{fTexW, fTexH, 0.0f, 1.0f, fontColor, 1.0f, 1.0f},
		{0.0f,  0.0f,  0.0f, 1.0f, fontColor, 0.0f, 0.0f},
		{0.0f,  fTexH, 0.0f, 1.0f, fontColor, 0.0f, 1.0f}
	};

	// ���_�o�b�t�@�̍쐬
	IDirect3DVertexBuffer9* pVertex;
	hr = GCGraphics->CreateVertexBuffer(
		sizeof(Vertex2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_CUSTOM2D,
		D3DPOOL_MANAGED,
		&pVertex,
		NULL
	);

	if (FAILED(hr)) {
		delete[] ptr;
		return;
	}

	// ���_���̏�������
	void* pData;
	hr = pVertex->Lock(0, sizeof(Vertex2D) * 4, (void**)&pData, 0);
	if (FAILED(hr)) {
		delete[] ptr;
		return;
	}
	memcpy(pData, vx, sizeof(Vertex2D) * 4);
	pVertex->Unlock();

	// �e�N�X�`���̍쐬
	LPDIRECT3DTEXTURE9 pTex;
	hr = GCGraphics->CreateTexture(
		gm.gmCellIncX,
		tm.tmHeight,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_A8R8G8B8,
		D3DPOOL_DEFAULT,
		&pTex,
		NULL
	);
	if (FAILED(hr)) {
		auto hhr = GCGraphics->CreateTexture(
			gm.gmCellIncX,
			tm.tmHeight,
			1,
			0,
			D3DFMT_A8R8G8B8,
			D3DPOOL_MANAGED,
			&pTex,
			nullptr
		);

		if (FAILED(hhr)) {
			delete[] ptr;
			return;
		}
	}

	// �e�N�X�`���Ƀt�H���g�r�b�g�}�b�v��������
	D3DLOCKED_RECT lockedRect;
	if (FAILED(pTex->LockRect(0, &lockedRect, NULL, D3DLOCK_DISCARD))) {
		if (FAILED(pTex->LockRect(0, &lockedRect, NULL, 0))) {
			delete[] ptr;
			return;
		}
	}

	// �t�H���g���̏�������
	auto iOfs_x = gm.gmptGlyphOrigin.x;
	auto iOfs_y = tm.tmAscent - gm.gmptGlyphOrigin.y;
	auto iBmp_w = gm.gmBlackBoxX + (4 - (gm.gmBlackBoxX % 4)) % 4;
	auto iBmp_h = gm.gmBlackBoxY;

	int level = 17;
	DWORD alpha, color;
	FillMemory(lockedRect.pBits, lockedRect.Pitch * tm.tmHeight, 0);
	for (UINT y{ static_cast<UINT>(iOfs_y) }; y < iOfs_y + iBmp_h; ++y) {
		for (UINT x{ static_cast<UINT>(iOfs_x) }; x < iOfs_x + gm.gmBlackBoxX; ++x) {
			alpha = 
				(255 * ptr[x - iOfs_x + iBmp_w * (y - iOfs_y)]) / (level - 1);
			color = 0x00ff0000 | (alpha << 24);
			memcpy((BYTE*)lockedRect.pBits + lockedRect.Pitch * y + 4 * x, &color, sizeof(DWORD));
		}
	}
	pTex->UnlockRect(0);
	delete[] ptr;

	// �e�N�X�`���Z�b�g
	GCGraphics->SetTexture(0, pTex);
	GCGraphics->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	GCGraphics->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	GCGraphics->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	GCGraphics->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	GCGraphics->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	GCGraphics->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	// �����_�����O�X�e�[�g
	//GCGraphics->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	GCGraphics->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	//GCGraphics->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVDESTALPHA);

	Font font1(50, "SODA");

/*
	while (app.update()) {
		app.begin();


		//font.drawText({100, 100}, "aaa", Color::Blue);
		font1.drawText({ 200, 200 }, "fdjeij");

		GCGraphics->SetStreamSource(0, pVertex, 0, sizeof(Vertex2D));
		GCGraphics->SetFVF(FVF_CUSTOM2D);
		GCGraphics->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

		app.end();
	}

	pVertex->Release();
	pTex->Release();
}

*/