# Collect all .cpp and .h files
file(GLOB_RECURSE RENDERER_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_LIST_DIR}/Rendering/*.cpp
)
file(GLOB_RECURSE RENDERER_HEADERS CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_LIST_DIR}/Rendering/*.h
)

# Combine all files
set(RENDERER_FILES ${RENDERER_SOURCES} ${RENDERER_HEADERS})

# Group files in IDE by folder structure
foreach(file ${RENDERER_FILES})
    file(RELATIVE_PATH rel_path "${CMAKE_CURRENT_LIST_DIR}/Rendering" "${file}")
    get_filename_component(dir "${rel_path}" DIRECTORY)
    string(REPLACE "/" "\\" group "${dir}")  # For Visual Studio
    source_group("${group}" FILES "${file}")
endforeach()

# Create the engine library
add_library(VulkanRendering STATIC ${RENDERER_FILES})

# Expose headers to other targets
target_include_directories(VulkanRendering PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Rendering
)

# Optional: If Engine depends on other libraries, link them here
target_link_libraries(VulkanRendering PUBLIC glm glfw imgui Vulkan::Vulkan)
set_target_properties(VulkanRendering PROPERTIES FOLDER "Libraries")
set_lib_output_dirs(VulkanRendering)