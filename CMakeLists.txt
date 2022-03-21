cmake_minimum_required(VERSION 3.19)
project(SimpleServer)

set(CMAKE_CXX_STANDARD 11)

add_executable(SimpleServer src/main.cpp src/lock/lock.cpp include/lock/lock.h src/thread_pool/thread_pool.cpp include/lock/thread_pool.h src/server/webServer.cpp include/server/webServer.h)