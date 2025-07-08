# ---------------------------------------------------------------------------------
# Projects Settings
# ---------------------------------------------------------------------------------
project(Vulkan-Rendering-Engine)
cmake_minimum_required(VERSION 3.3)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(${PROJECT_SOURCE_DIR}/cmake/Config.cmake)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)


# -------------------------------------------------------
# External dependencies
# -------------------------------------------------------
include(${PROJECT_SOURCE_DIR}/cmake/Functions.cmake)
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
