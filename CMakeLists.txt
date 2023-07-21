cmake_minimum_required(VERSION 3.0.0)
project(chilly_gb_emu VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(chilly_gb_emu main.c cartridge.c)
