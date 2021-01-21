# gnLib

## 概要
DirectX9を使った自作のゲームライブラリです。

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
  App app{"Window", 640, 480};
  
  while(app.update()){
    app.begin();
    
    app.end();
  }
}
```
