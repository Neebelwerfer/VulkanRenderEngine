file(GLOB IMGUI_SRC CONFIGURE_DEPENDS "src/*.cpp")

add_library(imgui STATIC ${IMGUI_SRC})

target_include_directories(imgui
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${EXTERNAL_LIBRARIES_SOURCE_PATH}/glad/include
        ${EXTERNAL_LIBRARIES_SOURCE_PATH}/glfw/include
)

target_link_libraries(imgui
    PRIVATE
        glfw
        Vulkan::Vulkan
)

set_target_properties(imgui PROPERTIES FOLDER "ThirdParty")