/*-------------------------------------------------------------------------
    Copyright diode 2021.
    Use, modification and distribution are subject to the
    Boost Software License, Version 1.0.  (See accompanying file
    LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*///-----------------------------------------------------------------------

#pragma once

#include <concepts>
#include <vector>
#include <fstream>
#include <string>
#include <ios>
#include <cassert>

template<std::floating_point Type> 
struct obj_loader::ObjFile_<Type>::ObjParse::ObjUnit::MtlParse
{
	struct MtlUnit;
	
	std::vector<MtlUnit> mtl_units;
	
	MtlParse()noexcept = default;
	
	void open(const std::string& mtl_path)noexcept(false)
	{
		auto ifs = std::ifstream(mtl_path, std::ios_base::in);
		
		if(!ifs.is_open())
		{
			auto e = std::runtime_error(".mtl file is not found");
			throw e;
		}
		
		auto buff = std::string();
		while(!ifs.eof())
		{
			ifs >> buff;
			
			if(buff == "newmtl")
			{
				this->mtl_units.resize(this->mtl_units.size() + 1);
				ifs >> this->mtl_units[this->mtl_units.size() - 1].newmtl;
			}
			
			if(buff == "Ka")
			{
				Type Ka;
				for(auto& itr:this->mtl_units[this->mtl_units.size() - 1].Ka) ifs >> itr;
			}
			
			if(buff == "Kd")
			{
				Type Kd;
				for(auto& itr:this->mtl_units[this->mtl_units.size() - 1].Kd) ifs >> itr;
			}
			
			if(buff == "Ks")
			{
				Type Ks;
				for(auto& itr:this->mtl_units[this->mtl_units.size() - 1].Ks) ifs >> itr;
			}
			
			if(buff == "Ns") ifs >> this->mtl_units[this->mtl_units.size() - 1].Ns;
			if(buff == "d") ifs >> this->mtl_units[this->mtl_units.size() - 1].d;
			if(buff == "Tr") ifs >> this->mtl_units[this->mtl_units.size() - 1].Tr;
			if(buff == "Ni") ifs >> this->mtl_units[this->mtl_units.size() - 1].Ni;
			if(buff == "illum") ifs >> this->mtl_units[this->mtl_units.size() - 1].illum;
			if(buff == "map_Ka") ifs >> this->mtl_units[this->mtl_units.size() - 1].map_Ka;
			if(buff == "map_Kd") ifs >> this->mtl_units[this->mtl_units.size() - 1].map_Kd;
			if(buff == "map_Ks") ifs >> this->mtl_units[this->mtl_units.size() - 1].map_Ks;
			if(buff == "map_Ns") ifs >> this->mtl_units[this->mtl_units.size() - 1].map_Ns;
			if(buff == "map_d") ifs >> this->mtl_units[this->mtl_units.size() - 1].map_d;
			if(buff == "map_bump") ifs >> this->mtl_units[this->mtl_units.size() - 1].map_bump;
			if(buff == "bump") ifs >> this->mtl_units[this->mtl_units.size() - 1].bump;
			if(buff == "disp") ifs >> this->mtl_units[this->mtl_units.size() - 1].disp;
			if(buff == "decal") ifs >> this->mtl_units[this->mtl_units.size() - 1].decal;
		}
		
		ifs.close();
	}
	
	MtlParse(const std::string& mtl_path)noexcept(false)
	{
		try{this->open(mtl_path);}
		catch(std::exception e){throw e;}
	}
	
	MtlParse& operator=(const MtlParse& mlt_parse)
	{
		this->mtl_units = mlt_parse.mtl_units;
		return *this;
	}
	
	MtlParse& operator=(MtlParse&& mlt_parse)noexcept
	{
		this->mtl_units = std::move(mlt_parse.mtl_units);
		return *this;
	}
	
	MtlParse(const MtlParse& mlt_parse)
	{
		*this = mlt_parse;
	}
	
	MtlParse(MtlParse&& mlt_parse)noexcept
	{
		*this = std::move(mlt_parse);
	}
	
	std::size_t size()const noexcept
	{
		return this->mtl_units.size();
	} 
	
	const MtlUnit& operator[](const std::size_t index)const
	{
		assert(this->mtl_units.size() > index);
		return this->mtl_units[index];
	}
	
	MtlUnit operator[](const std::string& mtl_name)const 
	{
		auto find = std::find(this->mtl_units.begin(), this->mtl_units.end(), mtl_name);
		assert(find != this->mtl_units.end());
		return *find;
	}
	
	auto begin()noexcept
	{
		return this->mtl_units.begin();
	}
	
	auto end()noexcept
	{
		return this->mtl_units.end();
	}
	
	auto begin()const noexcept
	{
		return this->mtl_units.begin();
	}
	
	auto end()const noexcept
	{
		return this->mtl_units.end();
	}
};
