set(STB_DIR ${CMAKE_CURRENT_LIST_DIR}/../stb)

add_library(stb INTERFACE)

target_include_directories(stb INTERFACE ${STB_DIR})

set_target_properties(stb PROPERTIES FOLDER "ThirdParty")