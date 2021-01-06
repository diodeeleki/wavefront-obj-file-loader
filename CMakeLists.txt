#////////////////////////////////////////////////////////////////////////////////////
#//    Copyright 2021 diodeeleki
#//
#//    Licensed under the Apache License, Version 2.0 (the “License”);
#//    you may not use this file except in compliance with the License.
#//    You may obtain a copy of the License at
#//
#//    http://www.apache.org/licenses/LICENSE-2.0
#//
#//    Unless required by applicable law or agreed to in writing, software
#//    distributed under the License is distributed on an “AS IS” BASIS,
#//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#//    See the License for the specific language governing permissions and
#//    limitations under the License.
#////////////////////////////////////////////////////////////////////////////////////

cmake_minimum_required(VERSION 3.15)
project(obj_loader CXX)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message("In-source build is not possible.")
endif()

add_library(obj_loader INTERFACE)
target_compile_features(obj_loader INTERFACE cxx_std_20)#   c++20以上でのコンパイルにしか対応しない

include(GNUInstallDirs)#    下記installで必要な変数定義

target_include_directories(
    obj_loader INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include># ./include
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>#   /usr/local/include
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/exsample)

install(TARGETS obj_loader EXPORT obj_loader-config)

install(
    EXPORT obj_loader-config 
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/obj_loader#   /usr/local/lib/cmake/obj_loader
)

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/obj_loader/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/obj_loader#   /usr/local/include/obj_loader
)
