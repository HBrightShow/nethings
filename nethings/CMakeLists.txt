
# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)


message(STATUS "Project binary dir: " ${PROJECT_BINARY_DIR})
message(STATUS "Project source dir:  " ${PROJECT_SOURCE_DIR})

#表示工程根目录的CMakeLists.txt文件路径
message(STATUS "Cmake source dir: " ${CMAKE_SOURCE_DIR})


# 项目信息
project (Nethings)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DSTATICLIB")

set(CXX_FLAGS
    -g
    # -DVALGRIND
    #-DCHECK_PTHREAD_RETURN_VALUE
    #-D_FILE_OFFSET_BITS=64
    -Wall
    #-Wextra
    -Werror
    #-Wconversion
    #-Wno-unused-parameter
    #-Wold-style-cast
    #-Woverloaded-virtual
    #-Wpointer-arith
    #-Wshadow
    #-Wwrite-strings
    #-march=native
    # -MMD
    -std=c++11
    #-rdynamic
    #-I /usr/local/include
    #-L /usr/local/lib
    
    #-lpthread
    #-lprotobuf
    #-lmuduo_base_cpp11
   
 )

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

#添加第三方头文件
include_directories(./build/release-install-cpp11/include)

#添加需要链接的库文件目录,参数是全路径
#link_directories(/home/hml/xiaozhong/code/nethings/build/release-install-cpp11/lib  /usr/lib)
link_directories(~/xiaozhong/code/nethings/nethings/build/release-install-cpp11/lib  /usr/lib)


# 指定生成目标
add_executable(Nethings ${DIR_SRCS})
#target_link_libraries(Nethings ${SYSTEM_LIB})
target_link_libraries(Nethings libmuduo_net.a libmuduo_base.a libmuduo_curl.a libpthread.so) 

