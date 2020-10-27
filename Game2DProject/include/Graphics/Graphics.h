#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "../Common/Lib.h"
#include "../Window/Window.h"

namespace gnLib {
	class Graphics {
	public:
		Graphics();
		~Graphics();

		// Graphic�̍쐬
		bool init(gnLib::Window* _window) noexcept;

		void begin() noexcept;		//�`��J�n
		void end() noexcept;		//�`��I��

		IDirect3D9* getInterface() const;
		IDirect3DDevice9* getDevice() const;

	private:
		IDirect3D9*		pD3D9;		    // Direct3D�f�o�C�X�����p�I�u�W�F�N�g
		IDirect3DDevice9*	device;	    // Direct3D�̃f�o�C�X
	};
}

#endif // !GRAPHICS_H
