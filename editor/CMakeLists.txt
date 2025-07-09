
set(libraries imgui Engine)

# Collect all .h/.cpp from Editor root and subfolders
file(GLOB_RECURSE EDITOR_HEADERS CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_LIST_DIR}/Editor/*.h
)
file(GLOB_RECURSE EDITOR_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_LIST_DIR}/Editor/*.cpp
)

# Combine files
set(EDITOR_FILES ${EDITOR_HEADERS} ${EDITOR_SOURCES})

# Source group mapping (IDE folder view)
foreach(file ${EDITOR_FILES})
    file(RELATIVE_PATH rel_path "${CMAKE_CURRENT_LIST_DIR}/Editor" "${file}")
    get_filename_component(dir "${rel_path}" DIRECTORY)
    string(REPLACE "/" "\\" group "${dir}")
    source_group("${group}" FILES "${file}")
endforeach()

add_executable(Editor ${EDITOR_FILES})
target_include_directories(Editor PUBLIC ${CMAKE_CURRENT_LIST_DIR}/Editor)
target_link_libraries(Editor PRIVATE ${libraries})
# set_target_properties(Editor PROPERTIES FOLDER "Applications")
set_app_output_dirs(Editor)
