#ifndef AUDIOLISTENER_H
#define AUDIOLISTENER_H

#include <dsound.h>

#pragma comment(lib, "dsound.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")

namespace gnLib {

	struct AudioDevice {
		IDirectSound8* dSound = nullptr;        // �T�E���h�f�o�C�X
		IDirectSoundBuffer* primary = nullptr;  // �v���C�}���T�E���h�o�b�t�@
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