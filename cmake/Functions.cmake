include(${PROJECT_SOURCE_DIR}/cmake/Shaders.cmake)

function(copy_or_symlink_resources target_name)
    set(resource_dest "$<TARGET_FILE_DIR:${target_name}>/resources")

    if(WIN32)
        message(STATUS "Windows detected: Using copy instead of symlink for resources")
        add_custom_command(TARGET ${target_name} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
                "${PROJECT_SOURCE_DIR}/resources"
                "${resource_dest}"
            COMMENT "Copying resources to ${resource_dest}"
        )
    else()
        add_custom_command(TARGET ${target_name} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E create_symlink
                "${PROJECT_SOURCE_DIR}/resources"
                "${resource_dest}"
            COMMENT "Linking resources to ${resource_dest}"
        )
    endif()
endfunction()

# Setup app output
function(set_app_output_dirs target_name)
    set(output_root "${PROJECT_SOURCE_DIR}/bin/${target_name}/$<CONFIG>")

    set_target_properties(${target_name} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${output_root}"
        PDB_OUTPUT_DIRECTORY     "${output_root}/debug"
    )

    # Call resource setup only once — works per config thanks to generator expressions
    copy_or_symlink_resources(${target_name})
endfunction()

# Setup library output
function(set_lib_output_dirs target_name)
    set(output_root "${PROJECT_SOURCE_DIR}/bin/libs/$<CONFIG>")

    set_target_properties(${target_name} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${output_root}"
        LIBRARY_OUTPUT_DIRECTORY "${output_root}"
        PDB_OUTPUT_DIRECTORY     "${output_root}"
    )
endfunction()