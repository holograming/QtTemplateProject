# ./app/CMakeLists.txt -- More Modern CMake

# Requires CMake 3.12, but also works with 3.13 policies set.
cmake_minimum_required( VERSION 3.12...3.13 )

project( ColorBar
         VERSION 1.0
         DESCRIPTION "Project1 test qt project" )

cmake_policy (SET CMP0074 NEW)

SET(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/install)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package (Qt5 COMPONENTS Widgets Core CONFIG REQUIRED)

add_executable(${PROJECT_NAME} WIN32)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE "app.cpp" "ui/ColorBarDialog.h" "ui/ColorBarDialog.cpp" )
target_link_libraries (${PROJECT_NAME}  PRIVATE Qt5::Widgets Qt5::Core)