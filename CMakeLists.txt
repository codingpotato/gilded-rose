cmake_minimum_required(VERSION 3.16)

project(
  gilded-rose
  VERSION 0.1
  DESCRIPTION "Gilded rose"
  LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(gilded_rose main.cpp)
target_include_directories(gilded_rose PUBLIC include)
target_compile_options(gilded_rose PUBLIC -Wall -Werror -Wextra -Wpedantic
                                          -pedantic-errors)
