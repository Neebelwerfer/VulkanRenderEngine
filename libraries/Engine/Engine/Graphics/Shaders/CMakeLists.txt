set(SHADER_FILES
    Shader.cpp
    Shader.h
)

list(TRANSFORM SHADER_FILES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")
set(GRAPHICS_FILES ${GRAPHICS_FILES} ${SHADER_FILES} PARENT_SCOPE)

