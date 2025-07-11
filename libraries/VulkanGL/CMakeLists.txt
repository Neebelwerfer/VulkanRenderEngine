# Collect all .cpp and .h files
file(GLOB_RECURSE RENDERER_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_LIST_DIR}/VulkanGL/*.cpp
)
file(GLOB_RECURSE RENDERER_HEADERS CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_LIST_DIR}/VulkanGL/*.h
)

# Combine all files
set(RENDERER_FILES ${RENDERER_SOURCES} ${RENDERER_HEADERS})

# Group files in IDE by folder structure
foreach(file ${RENDERER_FILES})
    file(RELATIVE_PATH rel_path "${CMAKE_CURRENT_LIST_DIR}/VulkanGL" "${file}")
    get_filename_component(dir "${rel_path}" DIRECTORY)
    string(REPLACE "/" "\\" group "${dir}")  # For Visual Studio
    source_group("${group}" FILES "${file}")
endforeach()

# Create the engine library
add_library(VulkanGL STATIC ${RENDERER_FILES})

# Expose headers to other targets
target_include_directories(VulkanGL PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

# Optional: If Engine depends on other libraries, link them here
target_link_libraries(VulkanGL PUBLIC glm glfw imgui VulkanMemoryAllocator Vulkan::Vulkan)
set_target_properties(VulkanGL PROPERTIES FOLDER "Libraries")
set_lib_output_dirs(VulkanGL)