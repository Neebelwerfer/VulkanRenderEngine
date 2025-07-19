# ---------------------------------------------------------------------------------
# Projects Settings
# ---------------------------------------------------------------------------------
cmake_minimum_required(VERSION 4.0)
project(Rendering-Engine)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include(${PROJECT_SOURCE_DIR}/cmake/Config.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/Functions.cmake)

# -------------------------------------------------------
# External dependencies
# -------------------------------------------------------
find_package(Vulkan REQUIRED) 

add_subdirectory(thirdparty)

# -------------------------------------------------------
# Internal modules
# -------------------------------------------------------
add_subdirectory(libraries)

# -------------------------------------------------------
# Applications
# -------------------------------------------------------
add_subdirectory(editor)
