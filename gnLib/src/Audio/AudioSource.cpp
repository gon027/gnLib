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

		// WAV�t�@�C�������[�h
		HMMIO hSrc;
		hSrc = mmioOpenA((LPSTR)(_filePath.c_str()), nullptr, MMIO_ALLOCBUF | MMIO_READ | MMIO_COMPAT);
		if (!hSrc) {
			return false;
		}

		// 'WAVE'�`�����N�`�F�b�N
		MMCKINFO mSrcWaveFile;
		ZeroMemory(&mSrcWaveFile, sizeof(mSrcWaveFile));
		hr = mmioDescend(hSrc, &mSrcWaveFile, NULL, MMIO_FINDRIFF);
		if (mSrcWaveFile.fccType != mmioFOURCC('W', 'A', 'V', 'E')) {
			mmioClose(hSrc, 0);
			return false;
		}

		// 'fmf'�`�����N�`�F�b�N
		MMCKINFO mSrcWaveFmt;
		ZeroMemory(&mSrcWaveFmt, sizeof(mSrcWaveFmt));
		hr = mmioDescend(hSrc, &mSrcWaveFmt, &mSrcWaveFile, MMIO_FINDCHUNK);
		if (mSrcWaveFmt.ckid != mmioFOURCC('f', 'm', 't', ' ')) {
			mmioClose(hSrc, 0);
			return false;
		}

		// �w�b�_�T�C�Y�̌v�Z
		int iSrcHeaderSize = mSrcWaveFmt.cksize;
		if (iSrcHeaderSize < sizeof(WAVEFORMATEX)) {
			iSrcHeaderSize = sizeof(WAVEFORMATEX);
		}

		// �w�b�_�������m��
		LPWAVEFORMATEX wf2;
		wf2 = (LPWAVEFORMATEX)malloc(iSrcHeaderSize);
		if (!wf2) {
			mmioClose(hSrc, 0);
			return false;
		}

		// WAVE�t�H�[�}�b�g�̃��[�h
		hr = mmioRead(hSrc, (char*)wf2, mSrcWaveFmt.cksize);
		if (FAILED(hr)) {
			free(wf2);
			mmioClose(hSrc, 0);
			return false;
		}

		// fmt�`�����N�ɖ߂�
		mmioAscend(hSrc, &mSrcWaveFmt, 0);

		// data�`�����N��T��
		MMCKINFO mSrcWaveData;
		ZeroMemory(&mSrcWaveData, sizeof(mSrcWaveData));
		while (1) {
			// ����
			hr = mmioDescend(hSrc, &mSrcWaveData, &mSrcWaveFile, 0);
			if (FAILED(hr)) {
				free(wf2);
				mmioClose(hSrc, 0);
				return false;
			}

			if (mSrcWaveData.ckid == mmioStringToFOURCCA("data", 0)) {
				break;
			}

			// ���̃`�����N��
			hr = mmioAscend(hSrc, &mSrcWaveData, 0);
		}

		// �T�E���h�o�b�t�@�̍쐬
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

		// ���b�N�J�n
		LPVOID pMem1, pMem2;
		DWORD dwSize1, dwSize2;
		hr = soundBuffer->Lock(0, mSrcWaveData.cksize, &pMem1, &dwSize1, &pMem2, &dwSize2, 0);
		if (FAILED(hr)) {
			free(wf2);
			mmioClose(hSrc, 0);
			return false;
		}

		// �f�[�^��������
		mmioRead(hSrc, (char*)pMem1, dwSize1);
		mmioRead(hSrc, (char*)pMem2, dwSize2);

		// ���b�N����
		soundBuffer->Unlock(pMem1, dwSize1, pMem2, dwSize2);

		// �w�b�_�p�����������
		free(wf2);

		// WAV�����
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
