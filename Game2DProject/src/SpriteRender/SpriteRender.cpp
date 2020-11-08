#include "../../include/SpriteRender/SpriteRender.h"
#include "../../include/Common/Macro.h"
#include "../../include/GameCore/GameCore.h"
#include "../../include/Graphics/Graphics.h"

#include <assert.h>

namespace gnLib {

	SpriteRender::SpriteRender()
		: lpSprite(nullptr)
	{
	}

	SpriteRender::~SpriteRender()
	{
		RELEASE(lpSprite);
	}

	bool SpriteRender::init()
	{
		HRESULT hr;

		// スプライトの作成
		hr = D3DXCreateSprite(
			GCGraphics,
			&lpSprite
		);
		
		assert(!hr);

		if (FAILED(hr)) {
			return false;
		}

		return true;
	}

	void SpriteRender::begin()
	{
		lpSprite->Begin(NULL);
	}

	void SpriteRender::end()
	{
		lpSprite->End();
	}

	LPD3DXSPRITE SpriteRender::getSprite() const
	{
		return lpSprite;
	}

}