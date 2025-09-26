cmake_minimum_required(VERSION 3.30)
project(WEBSCRAPERCPP)

set(CMAKE_CXX_STANDARD 17)

find_package(CURL REQUIRED)

add_executable(WEBSCRAPERCPP main.cpp)

target_include_directories(WEBSCRAPERCPP PRIVATE ${CURL_INCLUDE_DIR})
target_link_libraries(WEBSCRAPERCPP PRIVATE ${CURL_LIBRARIES})




