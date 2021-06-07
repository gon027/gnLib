#ifndef IAUDIOSOURCE_H
#define IAUDIOSOURCE_H

#include <string>

namespace gnLib {

	/// <summary>
	/// ���y���Đ�����Ƃ��Ƀ��[�v�Đ����邩�ǂ���
	/// </summary>
	enum class PlayType : unsigned long {
		Nomal = 0x00000000,    // ���ʂɍĐ�
		Loop  = 0x00000001,    // ���[�v�Đ�
	};

	/// <summary>
	/// AudioSource�̃C���^�[�t�F�[�X
	/// </summary>
	struct IAudioSource
	{
		virtual ~IAudioSource() = default;

		// Audio�t�@�C����ǂݍ���
		virtual bool load(std::string _filePath) = 0;

		// ����炷
		virtual void play(PlayType _type = PlayType::Nomal) = 0;

		// ���ʂ𒲐�����
		virtual void setVolume(long _volume) = 0;

		// ���ʂ��擾
		virtual long getVolume() = 0;

		// �Đ��ʒu��ݒ肷��
		virtual void setPosition(unsigned long _position) = 0;

		// �ꎞ��~
		virtual void pause() = 0;

		// ��~
		virtual void stop() = 0;
	};

}

#endif // !IAUDIOSOURCE_H