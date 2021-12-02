
# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)


message(STATUS "Project binary dir: " ${PROJECT_BINARY_DIR})
message(STATUS "Project source dir:  " ${PROJECT_SOURCE_DIR})

#表示工程根目录的CMakeLists.txt文件路径
message(STATUS "Cmake source dir: " ${CMAKE_SOURCE_DIR})
message(STATUS "Boost_LIBRARY_DIRS dir: " ${Boost_LIBRARY_DIRS})

# 项目信息
project (nethings)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DSTATICLIB")


set(CXX_FLAGS
 -g
 -DCHECK_PTHREAD_RETURN_VALUE
 -D_FILE_OFFSET_BITS=64
 -Wall
 -Wextra
 -Wsign-compare
 -Wunused-variable
 -Wno-unused-parameter
 -Woverloaded-virtual
 -Wpointer-arith
 -Wwrite-strings
 -march=native
 -std=c++11
)

set(IMPORTLIB  


    -lboost_system
    -lboost_program_options
    
    #-lpthread
    #-lprotobuf
    #-lmuduo_base_cpp11
   
 )



#find_package(Boost COMPONENTS program_options)
#include_directories(${Boost_INCLUDE_DIRS})
#link_directories(${Boost_LIBRARY_DIRS})

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_MAIN_SRCS)

#添加第三方头文件
include_directories(./muduobuild/release-install-cpp11/include) 

add_subdirectory(system)

#添加需要链接的库文件目录,参数是全路径
link_directories(~/xiaozhong/code/nethings/muduobuild/release-install-cpp11/lib  /usr/lib /lib/x86_64-linux-gnu)




# 指定生成目标
add_executable(nethings ${DIR_MAIN_SRCS} )
#target_link_libraries(Nethings ${SYSTEM_LIB})
target_link_libraries(nethings system libmuduo_net.a libmuduo_base.a libmuduo_curl.a libpthread.so libboost_program_options.so libboost_system.so libboost_filesystem.so)
