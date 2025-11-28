cmake_minimum_required(VERSION 3.30)
project(WEBSCRAPERCPP)

set(CMAKE_CXX_STANDARD 17)

set(prefix /opt/homebrew/opt/gumbo-parser)

include_directories(${prefix}/include)
link_directories(${prefix}/lib)

find_package(CURL REQUIRED)


add_executable(WEBSCRAPERCPP main.cpp)

target_include_directories(WEBSCRAPERCPP PRIVATE ${CURL_INCLUDE_DIRS})
target_link_libraries(WEBSCRAPERCPP PRIVATE ${CURL_LIBRARIES} gumbo)





