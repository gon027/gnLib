#ifndef IAUDIOSOURCE_H
#define IAUDIOSOURCE_H

#include <string>

namespace gnLib {

	/// <summary>
	/// 音楽を再生するときにループ再生するかどうか
	/// </summary>
	enum class PlayType : unsigned long {
		Nomal = 0x00000000,    // 普通に再生
		Loop  = 0x00000001,    // ループ再生
	};

	/// <summary>
	/// AudioSourceのインターフェース
	/// </summary>
	struct IAudioSource
	{
		virtual ~IAudioSource() = default;

		// Audioファイルを読み込み
		virtual bool load(std::string _filePath) = 0;

		// 音を鳴らす
		virtual void play(PlayType _type = PlayType::Nomal) = 0;

		// 音量を調整する
		virtual void setVolume(long _volume) = 0;

		// 音量を取得
		virtual long getVolume() = 0;

		// 再生位置を設定する
		virtual void setPosition(unsigned long _position) = 0;

		// 一時停止
		virtual void pause() = 0;

		// 停止
		virtual void stop() = 0;
	};

}

#endif // !IAUDIOSOURCE_H