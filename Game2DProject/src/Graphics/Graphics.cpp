#include "../../include/Graphics/Graphics.h"
#include "../../include/Common/Macro.h"

namespace gnLib {
	Graphics::Graphics()
		: pD3D9(nullptr)
		, device(nullptr)
	{

	}

	Graphics::~Graphics()
	{
		RELEASE(pD3D9);
		RELEASE(device);
	}

	bool Graphics::createGraphics(gnLib::Window* _window) noexcept
	{
		//Direct3D9のオブジェクトの作成
		pD3D9 = Direct3DCreate9(D3D_SDK_VERSION);

		if (pD3D9 == nullptr) {
			MessageBox(NULL,
				TEXT("IDirect3D9のオブジェクトを生成できませんでした．"),
				TEXT("失敗"),
				MB_OK
			);

			return false;
		}

		//ディスプレイ情報の取得
		D3DDISPLAYMODE D3DDisplay;
		pD3D9->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &D3DDisplay);

		//スワップチェインの設定
		D3DPRESENT_PARAMETERS D3DParam = {
			(UINT)_window->getWidth(),
			(UINT)_window->getHeight(),
			D3DDisplay.Format,
			1,
			D3DMULTISAMPLE_NONE,
			0,
			D3DSWAPEFFECT_DISCARD,
			_window->getHWnd(),
			TRUE,
			TRUE,
			D3DFMT_D24S8,
			0,
			0,
			D3DPRESENT_INTERVAL_DEFAULT
		};

		// HALモードで3Dデバイス作成
		if (FAILED(pD3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, D3DParam.hDeviceWindow,
			D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED, &D3DParam, &device))) {
			if (FAILED(pD3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, D3DParam.hDeviceWindow,
				D3DCREATE_MIXED_VERTEXPROCESSING | D3DCREATE_MULTITHREADED, &D3DParam, &device))) {
				// REFモードで3Dデバイス作成
				if (FAILED(pD3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, D3DParam.hDeviceWindow,
					D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED, &D3DParam, &device))) {
					if (FAILED(pD3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, D3DParam.hDeviceWindow,
						D3DCREATE_SOFTWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED, &D3DParam, &device))) {
						// 3Dデバイス作成失敗
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
		device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0xFF, 0xFF), 1.0, 0);
	}

	void Graphics::end() noexcept {
		device->EndScene();
		device->Present(NULL, NULL, NULL, NULL);
	}

	IDirect3D9 * Graphics::getInterface() const
	{
		return pD3D9;
	}

	IDirect3DDevice9 * Graphics::getDevice() const
	{
		return device;
	}

}

