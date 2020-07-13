#include "Graphics.h"

#include "Macro.h"

Graphics::Graphics()
{
}

Graphics::Graphics(window::Window* _window)
	: pD3D9(nullptr)
	, device(nullptr)
	, win(_window)
{

}

Graphics::~Graphics()
{
	RELEASE(pD3D9);
	RELEASE(device);
}

bool Graphics::create(window::Window& _win) noexcept
{
	//Direct3D9�̃I�u�W�F�N�g�̍쐬
	pD3D9 = Direct3DCreate9(D3D_SDK_VERSION);

	if (pD3D9 == nullptr) {
		MessageBox(NULL,
			TEXT("IDirect3D9�̃I�u�W�F�N�g�𐶐��ł��܂���ł����D"),
			TEXT("���s"),
			MB_OK
		);

		return false;
	}

	//�f�B�X�v���C���̎擾
	D3DDISPLAYMODE D3DDisplay;
	pD3D9->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &D3DDisplay);

	//�X���b�v�`�F�C���̐ݒ�
	D3DPRESENT_PARAMETERS D3DParam = {
		_win.width,
		_win.height,
		D3DDisplay.Format,
		1,
		D3DMULTISAMPLE_NONE,
		0,
		D3DSWAPEFFECT_DISCARD,
		_win.hwnd,
		TRUE,
		TRUE,
		D3DFMT_D24S8,
		0,
		0,
		D3DPRESENT_INTERVAL_DEFAULT
	};

	// HAL���[�h��3D�f�o�C�X�쐬
	if (FAILED(pD3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, D3DParam.hDeviceWindow,
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED, &D3DParam, &device))) {
		if (FAILED(pD3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, D3DParam.hDeviceWindow,
			D3DCREATE_MIXED_VERTEXPROCESSING | D3DCREATE_MULTITHREADED, &D3DParam, &device))) {
			// REF���[�h��3D�f�o�C�X�쐬
			if (FAILED(pD3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, D3DParam.hDeviceWindow,
				D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED, &D3DParam, &device))) {
				if (FAILED(pD3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, D3DParam.hDeviceWindow,
					D3DCREATE_SOFTWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED, &D3DParam, &device))) {
					// 3D�f�o�C�X�쐬���s
					RELEASE(pD3D9);
					return false;
				}
			}
		}
	}

	return true;
}

void Graphics::begin() noexcept {
	device->BeginScene();
}

void Graphics::end() noexcept {
	device->EndScene();
	device->Present(NULL, NULL, NULL, NULL);
}