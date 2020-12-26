#ifndef AUDIOLISTENER_H
#define AUDIOLISTENER_H

#include <dsound.h>

#pragma comment(lib, "dsound.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")

namespace gnLib {

	struct AudioDevice {
		IDirectSound8* dSound = nullptr;        // サウンドデバイス
		IDirectSoundBuffer* primary = nullptr;  // プライマリサウンドバッファ
	};

	class AudioListener {
	public:
		AudioListener();
		~AudioListener();

		const bool init();

		const AudioDevice* getSoundDevice();

	private:
		bool initSoundDevice();
		bool createPrimaryBuffer();

	private:
		AudioDevice audioDevice;
	};
}

#endif // !AUDIOLISTENER_H