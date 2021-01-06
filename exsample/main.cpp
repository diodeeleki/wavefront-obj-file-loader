/*-------------------------------------------------------------------------
    Copyright diode 2021.
    Use, modification and distribution are subject to the
    Boost Software License, Version 1.0.  (See accompanying file
    LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*///-----------------------------------------------------------------------

#include <iostream>
#include <obj_loader/obj_loader.hpp>

int main()
{
   	auto obj = obj_loader::ObjFile("../../obj/ground.obj", "../../obj/", "../../obj/texture/");
   	std::cout << "size:" << obj.size() << std::endl;
   	
   	for(unsigned i=0; i<obj.size(); ++i)
   	{
   		std::cout 	<< "--------------------------------------------" << '\n'
   					<< "obj num:" << i << '\n'
   				  	<< "vertex_num:" << obj.vertex_size(i) << '\n'
   				  	<< "vertex_all_byte_size:" << obj.vertex_byte_size(i) << '\n'
   				  	<< "uv_num:" << obj.uv_size(i) << '\n'
   				  	<< "uv_all_byte_size:" << obj.uv_byte_size(i) << '\n'
   				  	<< "norm_num:" << obj.norm_size(i) << '\n'
   				  	<< "norm_all_byte_size:" << obj.norm_byte_size(i) << '\n'
   				  	<< "mtl_name:" << obj.mtl_name(i) << '\n'
   				  	<< "ambient color:[" << obj.ambient_color(i)[0] << "," << obj.ambient_color(i)[1] << "," << obj.ambient_color(i)[2] << "]" << '\n'
   				  	<< "diffuse color:[" << obj.diffuse_color(i)[0] << "," << obj.diffuse_color(i)[1] << "," << obj.diffuse_color(i)[2] << "]" << '\n'
   				  	<< "specular color:[" << obj.specular_color(i)[0] << "," << obj.specular_color(i)[1] << "," << obj.specular_color(i)[2] << "]" << '\n'
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
