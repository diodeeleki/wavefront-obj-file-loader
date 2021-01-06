/*-------------------------------------------------------------------------
    Copyright diode 2021.
    Use, modification and distribution are subject to the
    Boost Software License, Version 1.0.  (See accompanying file
    LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*///-----------------------------------------------------------------------

#pragma once

#include <concepts>
#include <string>
#include <cstddef>
#include <cassert>
#include <array>
#include <cstdint>

namespace obj_loader
{
	template<std::floating_point Type> class ObjFile_;
	using ObjFile = class ObjFile_<float>;
	using ObjFileD = class ObjFile_<double>;
}

template<std::floating_point Type> 
class obj_loader::ObjFile_
{
	struct ObjParse;
	ObjParse obj_parse_;
	
public:
	using ElementType = Type;
	
	ObjFile_()noexcept = default;
	
	void open(const std::string& obj_path, const std::string& mtl_dir, const std::string& texture_dir)noexcept(false)
	{
		try{this->obj_parse_.open(obj_path, mtl_dir, texture_dir);}
		catch(std::exception e){throw e;}
	}
	
	ObjFile_(const std::string& obj_path, const std::string& mtl_dir, const std::string& texture_dir)noexcept(false)
	{
		try{this->open(obj_path, mtl_dir, texture_dir);}
		catch(std::exception e){throw e;}
	}
	
	/*------------------------------------
	
		ここからオブジェクト関連の情報取得
	
	*///----------------------------------
	
	// オブジェクト数取得
	std::size_t size()const noexcept
	{
		return this->obj_parse_.obj_list.size();
	}
	
	/*------------------------------------
	
		ここから頂点関連の情報取得
	
	*///----------------------------------
	
	// 頂点配列の先頭番地取得
	const Type* vertex_pointer(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].v[0].data();
	}
	
	Type* vertex_pointer(const std::size_t index)
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].v[0].data();
	}
	
	// 頂点数取得
	std::size_t vertex_size(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].v.size();
	}
	
	// 頂点配列の全サイズ(バイト数取得)
	std::size_t vertex_byte_size(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].v.size() * this->obj_parse_.obj_list[index].v[0].size() * sizeof(Type);
	}
	
	/*------------------------------------
	
		ここからUVマップ関連の情報取得
	
	*///----------------------------------
	
	// 頂点配列の先頭番地取得
	const Type* uv_pointer(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].vt[0].data();
	}
	
	Type* uv_pointer(const std::size_t index)
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].vt[0].data();
	}
	
	// 頂点数取得
	std::size_t uv_size(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].vt.size();
	}
	
	// 頂点配列の全サイズ(バイト数取得)
	std::size_t uv_byte_size(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].vt.size() * this->obj_parse_.obj_list[index].vt[0].size() * sizeof(Type);
	}
	
	/*------------------------------------
	
		ここから法線関連の情報取得
	
	*///----------------------------------
	
	// 頂点配列の先頭番地取得
	const Type* norm_pointer(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].vn[0].data();
	}
	
	Type* norm_pointer(const std::size_t index)
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].vn[0].data();
	}
	
	// 頂点数取得
	std::size_t norm_size(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].vn.size();
	}
	
	// 頂点配列の全サイズ(バイト数取得)
	std::size_t norm_byte_size(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].vn.size() * this->obj_parse_.obj_list[index].vn[0].size() * sizeof(Type);
	}
	
	/*------------------------------------
	
		ここからマテリアル関連の情報取得
	
	*///----------------------------------
	
	// マテリアル名取得
	const std::string& mtl_name(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].mtl.newmtl;
	}
	
	// 環境色取得
	const std::array<Type, 3>& ambient_color(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].mtl.Ka;
	}
	
	// 拡散色取得
	const std::array<Type, 3>& diffuse_color(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].mtl.Kd;
	}
	
	// 反射色取得
	const std::array<Type, 3>& specular_color(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].mtl.Ks;
	}
	
	// スペキュラ指数取得
	Type specular_exponent(const std::size_t index)const 
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].mtl.Ns;
	}
	
	// 非透過率の逆数取得
	Type opacity(const std::size_t index)const 
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].mtl.d;
	}
	
	// 透過率の逆数取得
	Type translucency(const std::size_t index)const 
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].mtl.Tr;
	}
	
	// 屈折率取得
	Type index_refraction(const std::size_t index)const 
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].mtl.Ni;
	}
	
	// 使用する照明モデル
	std::uint8_t lighting_model(const std::size_t index)const 
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return this->obj_parse_.obj_list[index].mtl.illum;
	}
	
	/*------------------------------------
	
		ここからテクスチャ関連の情報取得
	
	*///----------------------------------
	
	// 環境光テクスチャのパス取得
	std::string ambient_texture_path(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return  this->obj_parse_.obj_list[index].mtl.map_Ka != "" ? 
			this->obj_parse_.texture_dir + this->obj_parse_.obj_list[index].mtl.map_Ka :
			std::string("None");
	}
	
	// 拡散反射光テクスチャのパス取得
	std::string diffuse_texture_path(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return  this->obj_parse_.obj_list[index].mtl.map_Kd != "" ? 
			this->obj_parse_.texture_dir + this->obj_parse_.obj_list[index].mtl.map_Kd :
			std::string("None");
	}
	
	// 鏡面反射光テクスチャのパス取得
	std::string specular_texture_path(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return  this->obj_parse_.obj_list[index].mtl.map_Ks != "" ? 
			this->obj_parse_.texture_dir + this->obj_parse_.obj_list[index].mtl.map_Ks :
			std::string("None");
	}
	
	// スペキュラハイライト成分テクスチャのパス取得
	std::string specular_hilight_texture_path(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return  this->obj_parse_.obj_list[index].mtl.map_Ns != "" ? 
			this->obj_parse_.texture_dir + this->obj_parse_.obj_list[index].mtl.map_Ns :
			std::string("None");
	}
	
	// 透過率テクスチャのパス取得
	std::string opacity_texture_path(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return  this->obj_parse_.obj_list[index].mtl.map_d != "" ? 
			this->obj_parse_.texture_dir + this->obj_parse_.obj_list[index].mtl.map_d :
			std::string("None");
	}
	
	// バンプマップテクスチャのパス取得
	std::string bump_map_texture_path(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return  this->obj_parse_.obj_list[index].mtl.map_bump != "" ? 
			this->obj_parse_.texture_dir + this->obj_parse_.obj_list[index].mtl.map_bump :
			std::string("None");
	}
	
	// バンプマップテクスチャのパス取得
	std::string bump_texture_path(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return  this->obj_parse_.obj_list[index].mtl.bump != "" ? 
			this->obj_parse_.texture_dir + this->obj_parse_.obj_list[index].mtl.bump :
			std::string("None");
	}
	
	// ディスプレースメントマップテクスチャのパス取得
	std::string disp_texture_path(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return  this->obj_parse_.obj_list[index].mtl.disp != "" ? 
			this->obj_parse_.texture_dir + this->obj_parse_.obj_list[index].mtl.disp :
			std::string("None");
	}
	
	// ステンシルデカールテクスチャのパス取得
	std::string decal_texture_path(const std::size_t index)const
	{
		assert(this->obj_parse_.obj_list.size() > index);
		return  this->obj_parse_.obj_list[index].mtl.decal != "" ? 
			this->obj_parse_.texture_dir + this->obj_parse_.obj_list[index].mtl.decal :
			std::string("None");
	}
	
};
