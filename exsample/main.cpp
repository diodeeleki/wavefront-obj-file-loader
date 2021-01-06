/*-------------------------------------------------------------------------
    Copyright diode 2021.
    Use, modification and distribution are subject to the
    Boost Software License, Version 1.0.  (See accompanying file
    LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*///-----------------------------------------------------------------------

#include <iostream>
#include <stdexcept>
#include <obj_loader/obj_loader.hpp>

int main()
{
   	auto obj = obj_loader::ObjFile();
   	
   	try
   	{
   		// モデルのロードにはopenメソッドを使用
   		// 第一引数にはobjファイルまでのパス
   		// 第二引数にはmtlファイル検索ディレクトリ
   		// 第三引数にはテクスチャ検索ディレクトリ
   		// モデルのロードに問題がある場合例外発生
   		obj.open("../obj/ground.obj", "../obj/", "../obj/texture/");
   	}catch(std::runtime_error e)
   	{
   		std::cout << e.what() << std::endl;
   	}
   	
   	std::cout << "size:" << obj.size() << std::endl;//指定したobjファイルに記載されているobj数
   	
   	for(unsigned i=0; i<obj.size(); ++i)
   	{
   		std::cout 	
   		<< "--------------------------------------------" << '\n'
   		<< "obj num:" << i << '\n'
   		<< "vertex_num:" << obj.vertex_size(i) << '\n'               
   		<< "vertex_all_byte_size:" << obj.vertex_byte_size(i) << '\n'
   		<< "uv_num:" << obj.uv_size(i) << '\n'                      
   		<< "uv_all_byte_size:" << obj.uv_byte_size(i) << '\n'       
   		<< "norm_num:" << obj.norm_size(i) << '\n'                   
   		<< "norm_all_byte_size:" << obj.norm_byte_size(i) << '\n'   
   		<< "mtl_name:" << obj.mtl_name(i) << std::endl;              
   		
   		std::cout << "ambient color:";                               
   		for(auto& itr:obj.ambient_color(i)) std::cout << itr << " "; 
   		std::cout << std::endl;                                      
   		
   		std::cout << "diffuse color:";                               
   		for(auto& itr:obj.diffuse_color(i)) std::cout << itr << " "; 
   		std::cout << std::endl;                                      
   		
   		std::cout << "specular_color:";                               
   		for(auto& itr:obj.specular_color(i)) std::cout << itr << " "; 
   		std::cout << std::endl;                                       
   		
   		std::cout
   		<< "specular exponent:" << obj.specular_exponent(i) << '\n'
   		<< "opacity:" << obj.opacity(i) << '\n'
   		<< "translucency:" << obj.translucency(i) << '\n'
   		<< "index_refraction:" << obj.index_refraction(i) << '\n'
   		<< "illum:" << obj.lighting_model(i) << '\n'
   		<< "ambient_texture_path:" << obj.ambient_texture_path(i) << '\n'
   		<< "diffuse_texture_path:" << obj.diffuse_texture_path(i) << '\n'
   		<< "specular_texture_path:" << obj.specular_texture_path(i) << '\n'
   		<< "specular_hilight_texture_path:" << obj.specular_hilight_texture_path(i) << '\n'
   		<< "opacity_texture_path:" << obj.opacity_texture_path(i) << '\n'
   		<< "bump_map_texture_path:" << obj.bump_map_texture_path(i) << '\n'
   		<< "bump_texture_path:" << obj.bump_texture_path(i) << '\n'
   		<< "disp_texture_path:" << obj.disp_texture_path(i) << '\n'
   		<< "decal_texture_path:" << obj.decal_texture_path(i) << std::endl;
   	}
   	
   	

    return 0;
}
