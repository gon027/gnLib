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

		// Audio�t�@�C����ǂݍ���
		virtual bool load(std::string _filePath) override;

		// ����炷
		virtual void play(PlayType _type = PlayType::Nomal) override;

		// �ꎞ��~
		virtual void pause() override;

		// ��~
		virtual void stop() override;

	private:
		IDirectSoundBuffer* soundBuffer = nullptr;
	};

}

#endif // !AUDIOSOURCE_H