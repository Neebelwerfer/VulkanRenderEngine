include_directories(include)

file(GLOB target_src "*.cpp" )
add_library(imGuizmo STATIC ${target_src})
target_link_libraries(imGuizmo PUBLIC imgui)
set_target_properties(imGuizmo PROPERTIES FOLDER "ThirdParty")