#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "../Common/Lib.h"
#include "../Window/Window.h"
#include "../Color/Color.h"

namespace gnLib {
	class Graphics {
	public:
		Graphics();
		~Graphics();

		// Graphicの作成
		bool init(gnLib::Window* _window) noexcept;

		void begin() noexcept;		//描画開始

		void end() noexcept;		//描画終了

		// 背景色の設定
		void setColor(const Color& _color);

		IDirect3D9* getInterface() const;
		IDirect3DDevice9* getDevice() const;

	private:
		IDirect3D9*		pD3D9;		    // Direct3Dデバイス生成用オブジェクト
		IDirect3DDevice9*	device;	    // Direct3Dのデバイス
		Color color;
	};
}

#endif // !GRAPHICS_H
