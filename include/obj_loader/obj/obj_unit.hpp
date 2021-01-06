/*-------------------------------------------------------------------------
    Copyright diode 2021.
    Use, modification and distribution are subject to the
    Boost Software License, Version 1.0.  (See accompanying file
    LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*///-----------------------------------------------------------------------

#pragma once

#include <concepts>
#include <string>
#include <array>
#include <vector>
#include <memory>

template<std::floating_point Type> 
struct obj_loader::ObjFile_<Type>::ObjParse::ObjUnit
{
	struct MtlParse;

	std::vector<std::array<Type, 3>> v;         // 頂点リスト
	std::vector<std::array<Type, 2>> vt;        // uvマップリスト
	std::vector<std::array<Type, 3>> vn;        // 法線リスト
	typename MtlParse::MtlUnit mtl;             // マテリアル情報
	
	using ElementType = Type;
	
	ObjUnit() = default;
	
	ObjUnit& operator=(const ObjUnit& obj_unit)
	{
		this->v = obj_unit.v;
		this->vt = obj_unit.vt;
		this->vn = obj_unit.vn;
		this->mtl = obj_unit.mtl;
		return *this;
	}
	
	ObjUnit& operator=(ObjUnit&& obj_unit)noexcept
	{
		this->v = std::move(obj_unit.v);
		this->vt = std::move(obj_unit.vt);
		this->vn = std::move(obj_unit.vn);
		this->mtl = std::move(obj_unit.mtl);
		return *this;
	}
	
	ObjUnit(const ObjUnit& obj_unit)
	{
		*this = obj_unit;
	}
	
	ObjUnit(ObjUnit&& obj_unit)
	{
		*this = std::move(obj_unit);
	}
};
