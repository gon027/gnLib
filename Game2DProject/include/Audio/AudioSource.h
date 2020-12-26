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

		// Audioファイルを読み込み
		virtual bool load(std::string _filePath) override;

		// 音を鳴らす
		virtual void play(PlayType _type = PlayType::Nomal) override;

		// 一時停止
		virtual void pause() override;

		// 停止
		virtual void stop() override;

	private:
		IDirectSoundBuffer* soundBuffer = nullptr;
	};

}

#endif // !AUDIOSOURCE_H