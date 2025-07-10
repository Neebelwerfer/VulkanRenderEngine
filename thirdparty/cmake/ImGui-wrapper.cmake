set(IMGUI_DIR ${CMAKE_CURRENT_LIST_DIR}/../imgui)

file(GLOB IMGUI_SRC
    "${IMGUI_DIR}/imgui.cpp"
    "${IMGUI_DIR}/imgui_draw.cpp"
    "${IMGUI_DIR}/imgui_widgets.cpp"
    "${IMGUI_DIR}/imgui_tables.cpp"
    "${IMGUI_DIR}/imgui_demo.cpp"
    "${IMGUI_DIR}/backends/imgui_impl_vulkan.cpp"
    "${IMGUI_DIR}/backends/imgui_impl_glfw.cpp"
)

add_library(imgui STATIC ${IMGUI_SRC})

target_include_directories(imgui PUBLIC 
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
)

target_link_libraries(imgui
    PRIVATE glfw Vulkan::Vulkan
)

set_target_properties(imgui PROPERTIES FOLDER "ThirdParty")