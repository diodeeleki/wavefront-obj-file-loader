/*-------------------------------------------------------------------------
    Copyright diode 2021.
    Use, modification and distribution are subject to the
    Boost Software License, Version 1.0.  (See accompanying file
    LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*///-----------------------------------------------------------------------

/*-------------------------------------------------------------------------
照明モデルの種類:
	0. 色 有効 かつ アンビエント 無効
	1. 色 有効 かつ アンビエント 有効
	2. ハイライト 有効
	3. 反射 有効 かつ レイトレース 有効
	4. 透過: グラス 有効, 反射: レイトレース 有効
	5. 反射: フレネル 有効 かつ レイトレース 有効
	6. 透過: 反射 有効, 反射: フレネル 無効 かつ レイトレース 有効
	7. 透過: 反射 有効, 反射: フレネル 有効 かつ レイトレース 有効
	8. 反射 有効 かつ レイトレース 無効
	9. 透過: ガラス 有効, 反射: レイトレース 無効
	10. 不可視面に影を投影
*///-----------------------------------------------------------------------

#pragma once

#include <concepts>
#include <string>
#include <array>
#include <cstdint>

template<std::floating_point Type> 
struct obj_loader::ObjFile_<Type>::ObjParse::ObjUnit::MtlParse::MtlUnit
{
	std::string newmtl;    // マテリアル名
	std::array<Type, 3> Ka;// 環境光色
	std::array<Type, 3> Kd;// 拡散反射光色
	std::array<Type, 3> Ks;// 鏡面反射光色
	Type Ns;               // スペキュラ指数
	Type d;                // 非透過率(0に近いほど透明)
	Type Tr;               // 透過率(1に近いほど透明)
	Type Ni;               // 屈折率
	std::uint8_t illum;    // 使用する照明モデル
		
	std::string map_Ka;    // 環境光テクスチャの名前
	std::string map_Kd;    // 拡散反射光テクスチャの名前
	std::string map_Ks;    // 鏡面反射光テクスチャの名前
	std::string map_Ns;    // スペキュラハイライト成分テクスチャの名前
	std::string map_d;     // 透過率テクスチャの名前
	std::string map_bump;  // バンプマップテクスチャの名前
	std::string bump;      // バンプマップテクスチャの名前
	std::string disp;      // ディスプレースメントマップテクスチャの名前
	std::string decal;     // ステンシルデカールテクスチャの名前
	
	bool operator==(const std::string& mtl_name)const
	{
		return this->newmtl == mtl_name;
	}
	
	MtlUnit() = default;
	
	MtlUnit& operator=(const MtlUnit& mtl_unit)
	{
		this->newmtl = mtl_unit.newmtl;
		this->Ka = mtl_unit.Ka;
		this->Kd = mtl_unit.Kd;
		this->Ks = mtl_unit.Ks;
		this->Ns = mtl_unit.Ns;
		this->d = mtl_unit.d;
		this->Tr = mtl_unit.Tr;
		this->Ni = mtl_unit.Ni;
		this->illum = mtl_unit.illum;
		
		this->map_Ka = mtl_unit.map_Ka;
		this->map_Kd = mtl_unit.map_Kd;
		this->map_Ks = mtl_unit.map_Ks;
		this->map_Ns = mtl_unit.map_Ns;
		this->map_d = mtl_unit.map_d;
		this->map_bump = mtl_unit.map_bump;
		this->bump = mtl_unit.bump;
		this->disp = mtl_unit.disp;
		this->decal = mtl_unit.decal;
		return *this;
	}
	
	MtlUnit& operator=(MtlUnit&& mtl_unit)noexcept
	{
		this->newmtl = std::move(mtl_unit.newmtl);
		this->Ka = mtl_unit.Ka;
		this->Kd = mtl_unit.Kd;
		this->Ks = mtl_unit.Ks;
		this->Ns = mtl_unit.Ns;
		this->d = mtl_unit.d;
		this->Tr = mtl_unit.Tr;
		this->Ni = mtl_unit.Ni;
		this->illum = mtl_unit.illum;
		
		this->map_Ka = std::move(mtl_unit.map_Ka);
		this->map_Kd = std::move(mtl_unit.map_Kd);
		this->map_Ks = std::move(mtl_unit.map_Ks);
		this->map_Ns = std::move(mtl_unit.map_Ns);
		this->map_d = std::move(mtl_unit.map_d);
		this->map_bump = std::move(mtl_unit.map_bump);
		this->bump = std::move(mtl_unit.bump);
		this->disp = std::move(mtl_unit.disp);
		this->decal = std::move(mtl_unit.decal);
		return *this;
	}
	
	MtlUnit(const MtlUnit& mtl_unit)
	{
		*this = mtl_unit;	
	}
	
	MtlUnit(MtlUnit&& mtl_unit)noexcept
	{
		*this = std::move(mtl_unit);	
	}
};
