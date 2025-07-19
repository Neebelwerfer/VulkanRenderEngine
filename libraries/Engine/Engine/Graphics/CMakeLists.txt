
set(GRAPHICS_FILES
    GraphicsManager.cpp
    GraphicsManager.h
    Swapchain.cpp
    Swapchain.h
)
list(TRANSFORM GRAPHICS_FILES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")

# Gather all the sub_directory files
add_subdirectory(Device)
add_subdirectory(Shaders)
add_subdirectory(Interfaces)
add_subdirectory(Windows)
add_subdirectory(Renderer)
add_subdirectory(Textures)
add_subdirectory(Utility)
add_subdirectory(Base)

set(ENGINE_FILES ${ENGINE_FILES} ${GRAPHICS_FILES} PARENT_SCOPE)

