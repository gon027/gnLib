#include <Audio/AudioSource.h>
#include <Common/Macro.h>
#include <Audio/AudioListener.h>
#include <GameCore/GameCore.h>
#include <Common/Math.h>

namespace gnLib {

    AudioSource::AudioSource()
        : soundBuffer(nullptr)
		, volume(0)
    {
    }

    AudioSource::~AudioSource()
    {
        RELEASE(soundBuffer);
    }

    bool AudioSource::load(std::string _filePath)
    {
		HRESULT hr;

		// WAVファイルをロード
		HMMIO hSrc;
		hSrc = mmioOpenA((LPSTR)(_filePath.c_str()), nullptr, MMIO_ALLOCBUF | MMIO_READ | MMIO_COMPAT);
		if (!hSrc) {
			return false;
		}

		// 'WAVE'チャンクチェック
		MMCKINFO mSrcWaveFile;
		ZeroMemory(&mSrcWaveFile, sizeof(mSrcWaveFile));
		hr = mmioDescend(hSrc, &mSrcWaveFile, NULL, MMIO_FINDRIFF);
		if (mSrcWaveFile.fccType != mmioFOURCC('W', 'A', 'V', 'E')) {
			mmioClose(hSrc, 0);
			return false;
		}

		// 'fmf'チャンクチェック
		MMCKINFO mSrcWaveFmt;
		ZeroMemory(&mSrcWaveFmt, sizeof(mSrcWaveFmt));
		hr = mmioDescend(hSrc, &mSrcWaveFmt, &mSrcWaveFile, MMIO_FINDCHUNK);
		if (mSrcWaveFmt.ckid != mmioFOURCC('f', 'm', 't', ' ')) {
			mmioClose(hSrc, 0);
			return false;
		}

		// ヘッダサイズの計算
		int iSrcHeaderSize = mSrcWaveFmt.cksize;
		if (iSrcHeaderSize < sizeof(WAVEFORMATEX)) {
			iSrcHeaderSize = sizeof(WAVEFORMATEX);
		}

		// ヘッダメモリ確保
		LPWAVEFORMATEX wf2;
		wf2 = (LPWAVEFORMATEX)malloc(iSrcHeaderSize);
		if (!wf2) {
			mmioClose(hSrc, 0);
			return false;
		}

		// WAVEフォーマットのロード
		hr = mmioRead(hSrc, (char*)wf2, mSrcWaveFmt.cksize);
		if (FAILED(hr)) {
			free(wf2);
			mmioClose(hSrc, 0);
			return false;
		}

		// fmtチャンクに戻る
		mmioAscend(hSrc, &mSrcWaveFmt, 0);

		// dataチャンクを探す
		MMCKINFO mSrcWaveData;
		ZeroMemory(&mSrcWaveData, sizeof(mSrcWaveData));
		while (1) {
			// 検索
			hr = mmioDescend(hSrc, &mSrcWaveData, &mSrcWaveFile, 0);
			if (FAILED(hr)) {
				free(wf2);
				mmioClose(hSrc, 0);
				return false;
			}

			if (mSrcWaveData.ckid == mmioStringToFOURCCA("data", 0)) {
				break;
			}

			// 次のチャンクへ
			hr = mmioAscend(hSrc, &mSrcWaveData, 0);
		}

		// サウンドバッファの作成
		DSBUFFERDESC dsDesc{};
		dsDesc.dwSize = sizeof(DSBUFFERDESC);
		dsDesc.dwFlags = DSBCAPS_GETCURRENTPOSITION2 | DSBCAPS_STATIC | DSBCAPS_LOCDEFER | DSBCAPS_CTRLVOLUME;
		dsDesc.dwBufferBytes = mSrcWaveData.cksize;
		dsDesc.lpwfxFormat = wf2;
		dsDesc.guid3DAlgorithm = DS3DALG_DEFAULT;
		hr = GCAudio->getSoundDevice()->dSound->CreateSoundBuffer(&dsDesc, &soundBuffer, nullptr);
		if (FAILED(hr)) {
			free(wf2);
			mmioClose(hSrc, 0);
			return false;
		}

		// ロック開始
		LPVOID pMem1, pMem2;
		DWORD dwSize1, dwSize2;
		hr = soundBuffer->Lock(0, mSrcWaveData.cksize, &pMem1, &dwSize1, &pMem2, &dwSize2, 0);
		if (FAILED(hr)) {
			free(wf2);
			mmioClose(hSrc, 0);
			return false;
		}

		// データ書き込み
		mmioRead(hSrc, (char*)pMem1, dwSize1);
		mmioRead(hSrc, (char*)pMem2, dwSize2);

		// ロック解除
		soundBuffer->Unlock(pMem1, dwSize1, pMem2, dwSize2);

		// ヘッダ用メモリを解放
		free(wf2);

		// WAVを閉じる
		mmioClose(hSrc, 0);

		return true;
    }

    void AudioSource::play(PlayType _type)
    {
        soundBuffer->Play(0, 0, static_cast<DWORD>(_type));
    }

	void AudioSource::setVolume(long _volume)
	{
		_volume = clamp(_volume, -10000L, 0L);
		soundBuffer->SetVolume(_volume);
	}

	long AudioSource::getVolume()
	{
		soundBuffer->GetVolume(&volume);
		return volume;
	}

	void AudioSource::setPosition(unsigned long _position)
	{
		soundBuffer->SetCurrentPosition(_position);
	}

    void AudioSource::pause()
    {
    }

    void AudioSource::stop()
    {
        soundBuffer->Stop();
    }
}
