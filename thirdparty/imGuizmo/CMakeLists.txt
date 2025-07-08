include_directories(include)

file(GLOB target_src "*.cpp" )
add_library(imGuizmo STATIC ${target_src})
set_target_properties(imGuizmo PROPERTIES FOLDER "ThirdParty")