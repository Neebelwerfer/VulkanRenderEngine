include(${PROJECT_SOURCE_DIR}/cmake/Shaders.cmake)

function(set_work_dir_function pro_name)
    set(options)
    set(oneValueArgs DIR)
    cmake_parse_arguments(SET_WORK_DIR "${options}" "${oneValueArgs}" "" ${ARGN})

    if(NOT TARGET ${pro_name})
        message(FATAL_ERROR "Target '${pro_name}' not found in set_work_dir_function.")
        return()
    endif()

    set(work_dir "${SET_WORK_DIR_DIR}")
    if(NOT work_dir)
        set(work_dir "${PROJECT_SOURCE_DIR}/bin")
    endif()

    if(WIN32)
        set_target_properties(${pro_name}
            PROPERTIES
                VS_DEBUGGER_WORKING_DIRECTORY "${work_dir}"
        )
    endif()
endfunction()

function(copy_or_symlink_resources target_name)
    set(resource_dest "$<TARGET_FILE_DIR:${target_name}>/resources")

    if(WIN32)
        message(STATUS "Windows detected: Using copy instead of symlink for resources")
        add_custom_command(TARGET ${target_name} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
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


function(set_output_dir target_name)
    set(runtime_dir ${PROJECT_SOURCE_DIR}/bin/${target_name})
    set(lib_dir ${runtime_dir}/lib)
    set(build_dir ${runtime_dir}/build)  # Combined folder for pdb, ilks, objs, etc.

    set_target_properties(${target_name} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY                 ${runtime_dir}
        RUNTIME_OUTPUT_DIRECTORY_DEBUG           ${runtime_dir}
        RUNTIME_OUTPUT_DIRECTORY_RELEASE         ${runtime_dir}
        RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO  ${runtime_dir}
        RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL      ${runtime_dir}

        ARCHIVE_OUTPUT_DIRECTORY                 ${lib_dir}
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG           ${lib_dir}
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE         ${lib_dir}
        ARCHIVE_OUTPUT_DIRECTORY_RELWITHDEBINFO  ${lib_dir}
        ARCHIVE_OUTPUT_DIRECTORY_MINSIZEREL      ${lib_dir}

        LIBRARY_OUTPUT_DIRECTORY                 ${runtime_dir}  # DLLs next to EXE
        LIBRARY_OUTPUT_DIRECTORY_DEBUG           ${runtime_dir}
        LIBRARY_OUTPUT_DIRECTORY_RELEASE         ${runtime_dir}
        LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO  ${runtime_dir}
        LIBRARY_OUTPUT_DIRECTORY_MINSIZEREL      ${runtime_dir}

        PDB_OUTPUT_DIRECTORY                     ${build_dir}
        PDB_OUTPUT_DIRECTORY_DEBUG               ${build_dir}
        PDB_OUTPUT_DIRECTORY_RELEASE             ${build_dir}
        PDB_OUTPUT_DIRECTORY_RELWITHDEBINFO      ${build_dir}
        PDB_OUTPUT_DIRECTORY_MINSIZEREL          ${build_dir}

        INTERMEDIATE_OUTPUT_DIRECTORY            ${build_dir}
    )
endfunction()

function(set_app_output_dirs target_name)
    set(output_root "${PROJECT_SOURCE_DIR}/bin/${target_name}/$<CONFIG>")

    set_target_properties(${target_name} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${output_root}"
        PDB_OUTPUT_DIRECTORY     "${output_root}/debug"
    )

    # Call resource setup only once — works per config thanks to generator expressions
    copy_or_symlink_resources(${target_name})

    # Copy DLLs to our executable
    add_custom_command(TARGET ${target_name} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/bin/libs/$<CONFIG>"
        "$<TARGET_FILE_DIR:${target_name}>"
    COMMENT "Copying DLLs to executable directory"
)
endfunction()

function(set_lib_output_dirs target_name)
    set(output_root "${PROJECT_SOURCE_DIR}/bin/libs/$<CONFIG>")

    set_target_properties(${target_name} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${output_root}"
        LIBRARY_OUTPUT_DIRECTORY "${output_root}"
        PDB_OUTPUT_DIRECTORY     "${output_root}"
    )
endfunction()