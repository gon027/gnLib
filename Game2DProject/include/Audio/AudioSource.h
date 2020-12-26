#ifndef AUDIOSOURCE_H
#define AUDIOSOURCE_H

#include <dsound.h>
#include "IAudioSource.h"

#pragma comment(lib, "dsound.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")

namespace gnLib {

	class AudioSource : public IAudioSource {
	public:
		AudioSource();
		~AudioSource();

		// Audioƒtƒ@ƒCƒ‹‚ğ“Ç‚İ‚İ
		virtual bool load(std::string _filePath) override;

		// ‰¹‚ğ–Â‚ç‚·
		virtual void play(PlayType _type = PlayType::Nomal) override;

		// ˆê’â~
		virtual void pause() override;

		// ’â~
		virtual void stop() override;

	private:
		IDirectSoundBuffer* soundBuffer = nullptr;
	};

}

#endif // !AUDIOSOURCE_H