set(IMGUIZMO_DIR ${CMAKE_CURRENT_LIST_DIR}/../ImGuizmo)

add_library(ImGuizmo STATIC
    ${IMGUIZMO_DIR}/ImGuizmo.cpp
    ${IMGUIZMO_DIR}/ImGuizmo.cpp
    ${IMGUIZMO_DIR}/GraphEditor.cpp
    ${IMGUIZMO_DIR}/ImSequencer.cpp
    ${IMGUIZMO_DIR}/ImCurveEdit.cpp
)

target_include_directories(ImGuizmo
    PUBLIC ${IMGUIZMO_DIR}
)

# Link to imgui
target_link_libraries(ImGuizmo
    PUBLIC imgui
)

set_target_properties(ImGuizmo PROPERTIES FOLDER "ThirdParty")