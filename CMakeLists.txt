cmake_minimum_required(VERSION 3.15)
project(workshop)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE my_exe_list RELATIVE ${CMAKE_SOURCE_DIR} "*.cpp")

foreach(file_path ${my_exe_list})
    string( REPLACE ".cpp" "" new_name ${file_path} )
    get_filename_component(filename ${new_name} NAME)

    # replace all special symbols with _, because sometimes cmake will give error
    string(REGEX REPLACE "[^a-zA-Z0-9]" "_" filename ${filename})

    # to check if correct strings are matched
#    message(STATUS "${filename} ${filepath} ${new_name}")
    add_executable( ${filename} ${file_path} )
endforeach()
