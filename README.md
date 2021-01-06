# wavefront-obj-file-loader
wavefront .objファイルを読み込むためのc++ヘッダオンリーライブラリ  

## 登場するクラス
|ヘッダーファイル|名前空間|クラス名|備考|
|---|---|---|---|
|<obj_loader/obj_loader.hpp>|obj_loader|ObjFile|objファイルのパスとmtl検索ディレクトリとテクスチャ検索ディレクトリから3dモデルの情報を取得するクラス。頂点情報やuvマップ情報などの浮動小数点で管理しなければならないデータをfloatで管理する|
|<obj_loader/obj_loader.hpp>|obj_loader|ObjFileD|上記ObjFileクラス内で管理する頂点情報やuvマップ情報などの浮動小数点で管理しなければならないデータをdoubleで管理するクラス|

## メソッド
メソッドについてはObjFileクラスもObjFileDクラスも同じである
ため以降ObjFileクラスのメソッドの解説以外行わない。

## 初期化系メソッド
---
|メソッド名|戻り値解説|引数解説|備考|
|---|---|---|---|
|ObjFile()|-|-|デフォルトコンストラクタ|
|void open(const std::string& obj_path, const std::string& mtl_dir, const std::string& texture_dir)|-|第一引数はobjファイルのパス。第二引数はmtlファイルの検索ディレクトリ。第三引数はテクスチャ検索ディレクトリ|objファイルとmtlファイルとテクスチャを検索して読み込む。ファイルがない場合例外を投げる|
|ObjFile(const std::string& obj_path, const std::string& mtl_dir, const std::string& texture_dir)|-|上記openメソッドと同じ|オブジェクト生成時にobjファイル読み込みも行う引数付きコンストラクタ|

## 頂点情報系メソッド
---
|メソッド名|戻り値解説|引数解説|備考|
|---|---|---|---|
|std::size_t size()const noexcept|読み込んだ1つのオブジェクトファイルに記載されているオブジェクトの数|-|特になし|
|const float* vertex_pointer(const std::size_t index)const|頂点の配列の先頭ポインタ|オブジェクトのインデックス|ObjFileDの場合戻り値がdoubleとなる|
|float* vertex_pointer(const std::size_t index)|上記同様|上記同様|上記同様のメソッドであるが非constのオブジェクトからvertex_pointerメソッドを呼べば非constのポインタが戻り値となる。|
|std::size_t vertex_size(const std::size_t index)const|頂点の数|-|特になし|
|std::size_t vertex_byte_size(const std::size_t index)const|vertex_pointerメソッドで得られる頂点の配列の長さ|オブジェクトのインデックス|特になし|

## UVマップ系メソッド
---
|メソッド名|戻り値解説|引数解説|備考|
|---|---|---|---|
|||||

## メンバ型
---
|メンバ型名|備考|
|---|---|
|ElementType|ObjFileクラスではfloatが入り、ObjFileDクラスではdoubleが入る|

サンプルコード  
```c++
#include <obj_loader/obj_loader.hpp>

int main()
{
   	auto f = typename obj_loader::ObjFile::ElementType();
    auto d = typename obj_loader::ObjFileD::ElementType();

    return 0;
}
```