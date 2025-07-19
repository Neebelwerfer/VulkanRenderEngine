# Combine all files
set(ENGINE_FILES 
     Core/Application.cpp
     Core/Application.h
)

# Prepend full path
list(TRANSFORM ENGINE_FILES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")
add_subdirectory(Graphics)

# Group files in IDE by folder structure
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ENGINE_FILES})

# Create the engine library
add_library(Engine STATIC ${ENGINE_FILES})

# Expose headers to other targets
get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
target_include_directories(Engine PUBLIC
        ${PARENT_DIR}
)

target_link_libraries(Engine PUBLIC Vulkan::Vulkan glm stb glfw imgui tinyobjloader spdlog nlohmann_json)
set_target_properties(Engine PROPERTIES FOLDER "Libraries")
set_lib_output_dirs(Engine)