#ifndef SPRITERENDER_H
#define SPRITERENDER_H

#include "../Common/Lib.h"

namespace gnLib {

	class SpriteRender {
	public:
		SpriteRender();
		~SpriteRender();

		bool init();

		void begin();
		void end();

		LPD3DXSPRITE getSprite() const;

	private:
		LPD3DXSPRITE lpSprite;
	};

}

#endif // !SPRITERENDER_H
