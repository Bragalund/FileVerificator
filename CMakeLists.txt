cmake_minimum_required(VERSION 3.8)
project(losning)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c ValidateInput.c ValidateInput.h FileWriter.c FileWriter.h FileReader.c FileReader.h main.h Util.c Util.h md5.c md5.h)
add_executable(losning ${SOURCE_FILES})