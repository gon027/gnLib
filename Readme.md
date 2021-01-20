# gnLib
自作ゲームライブラリ  

使用言語: C++  
使用ライブラリ: DirectX9  
エディタ: Visual Studio 2019  

# gnLib
自作ゲームライブラリ  

使用言語: C++  
使用ライブラリ: DirectX9  
エディタ: Visual Studio 2019  

## 概要

## できること
- ゲームウインドウの生成  
- 図形描画(点、線、矩形、円)    
- テクスチャの描画  
- テクスチャ分割  
- アニメーション  
- Time  
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