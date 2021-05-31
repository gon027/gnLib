# gnLib

## 概要
DirectX9を使った自作のゲームライブラリです。

## 開発環境
使用言語: C++  
使用ライブラリ: DirectX9  
エディタ: Visual Studio 2019  

## できること
- ゲームウインドウの生成  
- 図形描画(点、線、矩形、円)    
- テクスチャの描画  
- テクスチャ分割  
- アニメーション  
- Time(時間クラス)  
- 音を鳴らす  
- フォント読み込み  
- 入力(キーボード、マウス)  
- Debug  

## サンプル
- ウインドウの生成  
``` cpp
#include "gnLib"

void gnMain(){
  App::init( "Window", 640, 480 );
  
  while(App::update()){
    App::begin();
    
    App::end();
  }
}
```

- 図形描画
``` cpp
// 矩形
Rect rect {{ 0.0f, 0.0f }, 50.0f, 50.0f};
rect.setColor(Color::Red);
rect.draw();

// 円
Circle circle { { 0.0f, 0.0f }, 50.0f };
circle.setColor(Color::Green);
circle.draw();

// 線
Line line { { 0.0f, 0.0f }, { 100.0f, 100.0f } };
line.setColor(Color::Black);
line.draw();

```

- テクスチャ
``` cpp
// 画像読み込み
TextureSPtr tp { Texture::createTexture("画像パス") };

// スプライト作成
Sprite sp;
sp.setTexture(tp);

// 描画
sp.draw({ 300, 300 }, Vector2::One, 0.0f);
```

- アニメーション
``` cpp
// 画像読み込み
TextureSPtr tp { Texture::createTexture("画像パス") };

// スプライト作成
AnimSprite as;
as.setTexture(tp);

// 描画
as.draw({ 300, 300 }, Vector2::One, 0.0f);
```

- フォント
``` cpp
Font font{ 24, "MS 明朝" };

font.drawText(0, 24, Color::Black, "Number = %d", 100);
```

- 音楽
``` cpp
AudioSource audio;
audio.load("wavファイル");

audio.play();
```

- 入力 (Input)
``` cpp
// マウス
if (Input::getRightButton()) {
  //
}

// キーボード
if(Input::getKey(Key::A)) {
  //
}

```

- デバッグ
``` cpp
// 四角形を描画
Debug::drawRect( { 0.0f, 0.0f }, 50.0f, 50.0f);

// 円を描画
Debug::drawCircle( { 0.0f, 0.0f }, 50.0f);

// 線を描画
Debug::drawLine( { 0.0f, 0.0f }, { 100.0f, 100.0f });

// 文字列描画
Debug::drawText(0.0f, 0.0f, "Test");
```
