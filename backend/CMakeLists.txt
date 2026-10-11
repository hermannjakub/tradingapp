cmake_minimum_required(VERSION 3.20)
project(trading_backend)

# Ustawiamy standard C++
set(CMAKE_CXX_STANDARD 17)

# Tworzymy program wykonywalny z naszego pliku
add_executable(trading_backend server.cpp)