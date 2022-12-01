cmake_minimum_required(VERSION 3.16)
project(yamlTest)
find_package(yaml-cpp REQUIRED)

include_directories(${YAML_CPP_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})

ADD_DEFINITIONS(-DYAML_DIR="${CMAKE_CURRENT_SOURCE_DIR}/")

add_executable(test.out test.cpp)

target_link_libraries(test.out ${YAML_CPP_LIBRARIES})