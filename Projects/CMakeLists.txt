#./CMakeLists.txt -- More Modern CMake

# Requires CMake 3.12, but also works with 3.13 policies set.
cmake_minimum_required( VERSION 3.12...3.13 )

set(VCPKG_ROOT "" CACHE PATH "Insert vcpkg installed path.")

if (NOT VCPKG_ROOT)
	message(FATAL_ERROR "Need vcpkg installed path.")
else()
	message(STATUS "------------------")
	message(STATUS "    Find vcpkg    ")
	message(STATUS "------------------")
	set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE FILEPATH "Auto-generation file after execute bootstrap-vcpkg.bat.")
	if (NOT EXISTS ${CMAKE_TOOLCHAIN_FILE})
		message(FATAL_ERROR "First execute bootstrap-vcpkg.bat and read first how to install vcpkg.")
	endif()
	set(VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "target configuration set" FORCE)
	set(VCPKG_INSTALL_PREFIX "${VCPKG_ROOT}/installed/" CACHE PATH "Package install directory." FORCE)
endif()

project( QtTemplateProject
         VERSION 1.0
         DESCRIPTION "Qt example project for More Modern CMake (using CMake 3.12 or newer).")

# Common project environment settings
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

# Let's nicely support folders in IDEs
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Declaration qt path to find_package.
SET(Qt5_DIR ${VCPKG_INSTALL_PREFIX}/${VCPKG_TARGET_TRIPLET}/)
list (APPEND CMAKE_PREFIX_PATH ${Qt5_DIR})

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# Create the targets for the entire example-app.
add_subdirectory( HelloQT )
add_subdirectory( ColorBar )