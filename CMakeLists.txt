#----------------------------------------------------------------
# @brief - Build project 'main' and 'test' for demo
# @author - Pratik Parvati (pratikparvati@gmail.com)
#----------------------------------------------------------------

cmake_minimum_required(VERSION 3.10.2)  # CMake version check
project(main)                           # Create project "main"

# Add main.c file of project root directory as source file
set(SOURCE_FILES main.c)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(main ${SOURCE_FILES})

project(etest)                         #Create project "etest"

#Add test.c file of project root directory as source file
set(SOURCE_FILES test.c)

#Add executable target with source files listed in SOURCE_FILES variable
add_executable(etest ${SOURCE_FILES})

