set(GLSLC_EXECUTABLE "C:/VulkanSDK/1.4.313.0/bin/glslc.exe")

function(compile_glsl_shader input_file output_file)
    add_custom_command(
        OUTPUT ${output_file}
        COMMAND glslc ${input_file} -o ${output_file}
        DEPENDS ${input_file}
        COMMENT "Compiling GLSL shader: ${input_file} -> ${output_file} with glslc"
        VERBATIM
    )
endfunction()


function(compile_shaders output_root)
    file(GLOB_RECURSE GLSL_SHADERS
        "${PROJECT_SOURCE_DIR}/resources/shaders/*.vert"
        "${PROJECT_SOURCE_DIR}/resources/shaders/*.frag"
        # Add other shader types here if needed
    )

    set(compiled_shaders "")
    file(MAKE_DIRECTORY "${output_root}/shaders")

    foreach(src IN LISTS GLSL_SHADERS)
        get_filename_component(name ${src} NAME)
        set(out "${output_root}/shaders/${name}.spv")

        add_custom_command(
            OUTPUT ${out}
            COMMAND glslc ${src} -o ${out}
            DEPENDS ${src}
            COMMENT "Compiling shader ${name}"
            VERBATIM
        )
        list(APPEND compiled_shaders ${out})
    endforeach()

    # Create a custom target that depends on all compiled shaders
    add_custom_target(Shaders ALL DEPENDS ${compiled_shaders})

    return()
endfunction()