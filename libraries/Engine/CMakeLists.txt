
# Collect all .cpp and .h files
file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_LIST_DIR}/Engine/*.cpp
)
file(GLOB_RECURSE ENGINE_HEADERS CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_LIST_DIR}/Engine/*.h
)

# Combine all files
set(ENGINE_FILES ${ENGINE_SOURCES} ${ENGINE_HEADERS})

# Group files in IDE by folder structure
foreach(file ${ENGINE_FILES})
    file(RELATIVE_PATH rel_path "${CMAKE_CURRENT_LIST_DIR}/Engine" "${file}")
    get_filename_component(dir "${rel_path}" DIRECTORY)
    string(REPLACE "/" "\\" group "${dir}")  # For Visual Studio
    source_group("${group}" FILES "${file}")
endforeach()

# Create the engine library
add_library(Engine STATIC ${ENGINE_FILES})

# Expose headers to other targets
target_include_directories(Engine PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Engine
)

target_link_libraries(Engine PUBLIC glm stb glfw imgui VulkanGL)
set_target_properties(Engine PROPERTIES FOLDER "Libraries")
target_precompile_headers(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/pch.h)
set_lib_output_dirs(Engine)