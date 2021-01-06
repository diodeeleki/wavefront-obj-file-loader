# wavefront-obj-file-loader
wavefront .objファイルを読み込むためのc++ヘッダオンリーライブラリ  

## 登場するクラス
|ヘッダーファイル|名前空間|クラス名|備考|
|---|---|---|---|
|<obj_loader/obj_loader.hpp>|obj_loader|ObjFile|objファイルのパスとmtl検索ディレクトリとテクスチャ検索ディレクトリから3dモデルの情報を取得するクラス。頂点情報やuvマップ情報などの浮動小数点で管理しなければならないデータをfloatで管理する|
|<obj_loader/obj_loader.hpp>|obj_loader|ObjFileD|上記ObjFileクラス内で管理する頂点情報やuvマップ情報などの浮動小数点で管理しなければならないデータをdoubleで管理するクラス|

サンプルコード  
```c++

```