//#include "../gnLib.h"

// 1 : ウインドウ自体の表示
// 2 : マウスの入力テスト
// 3 : スプライトの描画
// 4 : 図形の描画
// 5 : アニメーションの描画
// 6 : 音を鳴らす

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
	// Appクラスの宣言
	App app;

	// ゲームモード
	Mode mode = Mode::Nomal;

	// Fontクラスの宣言
	// フォントの大きさ : 24、フォント : MS 明朝
	Font font{ 24, "MS 明朝" };

	// 四角形のクラス
	Rect rect;

	// 円のクラス
	Circle circle;

	// テクスチャの作成
	auto texture{ Texture::createTexture("Assets/img/char.png") };
	Sprite sprite{};
	sprite.setTexture(texture);

	// アニメーションの作成
	auto animTexture{Texture::createTexture("Assets/img/Numbers.png") };
	AnimSprite animSprite{ 10, 1, 6.0f };	// コンストラクタ(画像の縦の数, 画像の横の数, アニメーションのFPS値)
	animSprite.setTexture(animTexture);

	// 音楽ファイルの読み込み
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

			// スプライトの描画
			sprite.draw(app.getPos().half(), Vector2::One, 0.0f);
		}
			break;

		case Mode::ShapeRender:
		{
			font.drawText(0, 0, "GameMode = ShapeRender");

			// 図形の描画
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

			// アニメーションの描画
			animSprite.draw(app.getPos().half(), { 3.0f, 3.0f }, 0.0f);
		}
			break;
		case Mode::Music:
		{
			font.drawText(0, 0, "GameMode = Music");

			// 音楽ファイルの再生
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