cmake_minimum_required(VERSION 3.19)
project(SimpleServer)

set(CMAKE_CXX_STANDARD 11)
add_definitions(-std=c++11) #设置使用c11标准编译程序

set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O -Wall -g -ggdb -fpermissive")#在debug下不优化,即采用最低级别的O0
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")#在release下采用最高级别优化

include_directories(
    ${PROJECT_SOURCE_DIR}/include/http_conn
    ${PROJECT_SOURCE_DIR}/include/server
    ${PROJECT_SOURCE_DIR}/include/lock
    ${PROJECT_SOURCE_DIR}/include/thread_pool
)

#link_directories(/usr/lib/i386-linux-gnu/)

aux_source_directory(${PROJECT_SOURCE_DIR}/src/server src)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/http_conn src)
aux_source_directory(${PROJECT_SOURCE_DIR}/src src)

MESSAGE(STATUS "this is ${src}")

add_executable(SimpleServer ${src})
target_link_libraries(
        SimpleServer
        -lpthread
        -lcrypto
        -lmysqlclient
)