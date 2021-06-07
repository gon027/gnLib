#include "../../include/Audio/AudioListener.h"
#include "../../include/Common/Macro.h"
#include "../../include/Window/Window.h"
#include "../../include/GameCore/GameCore.h"

namespace gnLib {

	AudioListener::AudioListener()
		: audioDevice()
	{
	}

	AudioListener::~AudioListener()
	{
		RELEASE(audioDevice.dSound);
		RELEASE(audioDevice.primary);
	}

	const bool AudioListener::init()
	{
		if (!initSoundDevice()) {
			return false;
		}

		if (!createPrimaryBuffer()) {
			return false;
		}

		return true;
	}

	const AudioDevice* AudioListener::getSoundDevice()
	{
		return &audioDevice;
	}

	bool AudioListener::initSoundDevice()
	{
		HRESULT hr;

		// �T�E���h�f�o�C�X�̍쐬
		hr = DirectSoundCreate8(nullptr, &audioDevice.dSound, nullptr);
		if (FAILED(hr)) {
			return false;
		}

		// �������x����ݒ�
		hr = audioDevice.dSound->SetCooperativeLevel(GCWindow->getHWnd(), DSSCL_EXCLUSIVE | DSSCL_PRIORITY);
		if (FAILED(hr)) {
			return false;
		}

		return true;
	}

	bool AudioListener::createPrimaryBuffer()
	{
		HRESULT hr;

		// �v���C�}���T�E���h�o�b�t�@�̍쐬
		DSBUFFERDESC dsDesc{};
		dsDesc.dwSize = sizeof(DSBUFFERDESC);
		dsDesc.dwFlags = DSBCAPS_PRIMARYBUFFER;
		dsDesc.dwBufferBytes = 0;
		dsDesc.lpwfxFormat = NULL;
		hr = audioDevice.dSound->CreateSoundBuffer(&dsDesc, &audioDevice.primary, nullptr);
		if (FAILED(hr)) {
			return false;
		}

		// �v���C�}���o�b�t�@�̃X�e�[�^�X������
		WAVEFORMATEX wf;
		wf.cbSize = sizeof(WAVEFORMATEX);
		wf.wFormatTag = WAVE_FORMAT_PCM;
		wf.nChannels = 2;
		wf.nSamplesPerSec = 44100;
		wf.wBitsPerSample = 16;
		wf.nBlockAlign = wf.nChannels * wf.wBitsPerSample / 8;
		wf.nAvgBytesPerSec = wf.nSamplesPerSec * wf.nBlockAlign;
		hr = audioDevice.primary->SetFormat(&wf);  // �Ԃ�l��DS_OK�ƂȂ�
		if (hr == DS_OK) {
			return false;
		}

		return true;
	}

}