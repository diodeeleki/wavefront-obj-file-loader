/*-------------------------------------------------------------------------
    Copyright diode 2021.
    Use, modification and distribution are subject to the
    Boost Software License, Version 1.0.  (See accompanying file
    LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*///-----------------------------------------------------------------------

#pragma once

#include <concepts>
#include <string>
#include <vector>
#include <fstream>
#include <array>
#include <sstream>
#include <stdexcept>

template<std::floating_point Type> 
struct obj_loader::ObjFile_<Type>::ObjParse
{
	struct ObjUnit;
	
	std::string texture_dir;
	std::vector<ObjUnit> obj_list;
	
	void open(const std::string& obj_path, const std::string& mtl_dir, const std::string& texture_dir)noexcept(false)
	{
		auto ifs = std::ifstream(obj_path, std::ios_base::in);
		
		this->texture_dir = texture_dir;
		
		if(!ifs.is_open())
		{
			auto e = std::runtime_error(".obj file is not found");
			throw e;
		}
		
		std::vector<std::array<Type, 3>> v;// すべての頂点リスト
		std::vector<std::array<Type, 2>> vt;// すべてのuvマップリスト
		std::vector<std::array<Type, 3>> vn;// すべての法線リスト
		
		auto mtl_loader = typename ObjUnit::MtlParse();
		auto buff = std::string();
		
		this->texture_dir = texture_dir;
		
		while(!ifs.eof())
		{
			ifs >> buff;
			if(buff == "mtllib")
			{
				ifs >> buff;
				try
				{
					mtl_loader.open(mtl_dir + buff);
				}catch(std::runtime_error e)
				{
					throw e;
				}
			}
			
			if(buff == "v")
			{
				v.resize(v.size() + 1);
				for(auto& itr:v[v.size() - 1]) ifs >> itr;
			}
			
			if(buff == "vt")
			{
				vt.resize(vt.size() + 1);
				for(auto& itr:vt[vt.size() - 1]) ifs >> itr;
			}
			
			if(buff == "vn")
			{
				vn.resize(vn.size() + 1);
				for(auto& itr:vn[vn.size() - 1]) ifs >> itr;
			}
			
			if(buff == "usemtl")
			{
				this->obj_list.resize(this->obj_list.size() + 1);
				ifs >> buff;
				this->obj_list[this->obj_list.size() - 1].mtl = mtl_loader[buff];
			}
			
			if(buff == "f")
			{
				auto ss = std::stringstream();
				
				for(std::uint8_t i=0; i<3; ++i)
				{
					ifs >> buff;
					std::replace(buff.begin(), buff.end(), '/', ' ');
					ss << buff + ' ';
				} 
				
				std::size_t index;
				
				for(std::uint8_t i=0; i<3; ++i)
				{
					ss >> index;
					this->obj_list[this->obj_list.size() - 1].v.push_back(v[index - 1]);
					
					ss >> index;
					this->obj_list[this->obj_list.size() - 1].vt.push_back(vt[index - 1]);
					
					ss >> index;
					this->obj_list[this->obj_list.size() - 1].vn.push_back(vn[index - 1]);
				}
			}
		}
		
		ifs.close();
	}
	
	ObjParse(const std::string& obj_path, const std::string& mtl_dir, const std::string& texture_dir)noexcept(false)
	{
		try{this->open(obj_path, mtl_dir, texture_dir);}
		catch(std::runtime_error e){throw e;}
	}
	
	ObjParse() = default;
};
