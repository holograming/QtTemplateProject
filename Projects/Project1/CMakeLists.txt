# ./app/CMakeLists.txt -- More Modern CMake

# Requires CMake 3.12, but also works with 3.13 policies set.
cmake_minimum_required( VERSION 3.12...3.13 )

project( Project1
         VERSION 1.0
         DESCRIPTION "Project1 test qt project" )

# Freely available calculator app.
add_executable( Project1 )
target_sources( Project1 PRIVATE "main.cpp" )