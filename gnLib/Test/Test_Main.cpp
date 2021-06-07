//#include "../gnLib.h"

// 1 : �E�C���h�E���̂̕\��
// 2 : �}�E�X�̓��̓e�X�g
// 3 : �X�v���C�g�̕`��
// 4 : �}�`�̕`��
// 5 : �A�j���[�V�����̕`��
// 6 : ����炷

/*
enum class Mode {
	Nomal,
	Mouse,
	SpriteRender,
	ShapeRender,
	Animation,
	Music
};

void gnMain() {
	// App�N���X�̐錾
	App app;

	// �Q�[�����[�h
	Mode mode = Mode::Nomal;

	// Font�N���X�̐錾
	// �t�H���g�̑傫�� : 24�A�t�H���g : MS ����
	Font font{ 24, "MS ����" };

	// �l�p�`�̃N���X
	Rect rect;

	// �~�̃N���X
	Circle circle;

	// �e�N�X�`���̍쐬
	auto texture{ Texture::createTexture("Assets/img/char.png") };
	Sprite sprite{};
	sprite.setTexture(texture);

	// �A�j���[�V�����̍쐬
	auto animTexture{Texture::createTexture("Assets/img/Numbers.png") };
	AnimSprite animSprite{ 10, 1, 6.0f };	// �R���X�g���N�^(�摜�̏c�̐�, �摜�̉��̐�, �A�j���[�V������FPS�l)
	animSprite.setTexture(animTexture);

	// ���y�t�@�C���̓ǂݍ���
	AudioSource source;
	source.load("Assets/bgm/test.wav");

	while (app.update()) {
		app.begin();

		if (Input::getKey(Key::KEY_1)) {
			mode = Mode::Nomal;
		}
		else if (Input::getKey(Key::KEY_2)) {
			mode = Mode::Mouse;
		}
		else if (Input::getKey(Key::KEY_3)) {
			mode = Mode::SpriteRender;
		}
		else if (Input::getKey(Key::KEY_4)) {
			mode = Mode::ShapeRender;
		}
		else if (Input::getKey(Key::KEY_5)) {
			mode = Mode::Animation;
		}
		else if (Input::getKey(Key::KEY_6)) {
			mode = Mode::Music;
		}

		switch (mode)
		{
		case Mode::Nomal:
		{
			font.drawText(0, 0, "GameMode = Nomal");
		}
			break;

		case Mode::Mouse:
		{
			font.drawText(0, 0, "GameMode = Mouse");

			font.drawText(0, 24, Color::Black, "Mouse Left_Button = %d", Input::getLeftButton());
			font.drawText(0, 48, Color::Black, "Mouse Middle_Button = %d", Input::getMiddleButton());
			font.drawText(0, 72, Color::Black, "Mouse Right_Button = %d", Input::getRightButton());
		}
			break;

		case Mode::SpriteRender:
		{
			font.drawText(0, 0, "GameMode = SpriteRender");

			// �X�v���C�g�̕`��
			sprite.draw(app.getPos().half(), Vector2::One, 0.0f);
		}
			break;

		case Mode::ShapeRender:
		{
			font.drawText(0, 0, "GameMode = ShapeRender");

			// �}�`�̕`��
			rect.setPos({ 200.0f, 200.0f });
			rect.setSize(100.0f);
			rect.setColor(Color::Green);
			rect.draw();

			circle.setPos(Input::getPos());
			circle.setRadius(30.0f);
			circle.setColor(Color::Red);
			circle.draw();
		}
			break;
		case Mode::Animation:
		{
			font.drawText(0, 0, "GameMode = Animation");

			// �A�j���[�V�����̕`��
			animSprite.draw(app.getPos().half(), { 3.0f, 3.0f }, 0.0f);
		}
			break;
		case Mode::Music:
		{
			font.drawText(0, 0, "GameMode = Music");

			// ���y�t�@�C���̍Đ�
			source.play();
		}
			break;
		default:
			break;
		}

		app.end();
	}
}
*/