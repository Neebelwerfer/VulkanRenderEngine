add_subdirectory(spdlog)
set_target_properties(spdlog PROPERTIES FOLDER "ThirdParty")

add_subdirectory(glfw)
set_target_properties(glfw PROPERTIES FOLDER "ThirdParty")

add_subdirectory(glm)
set_target_properties(glm PROPERTIES FOLDER "ThirdParty")

add_subdirectory(tinyobjloader)
set_target_properties(tinyobjloader PROPERTIES FOLDER "ThirdParty")

add_subdirectory(json)

add_subdirectory(VulkanMemoryAllocator)
set_target_properties(VulkanMemoryAllocator PROPERTIES FOLDER "ThirdParty")

add_subdirectory(flecs)
set_target_properties(flecs PROPERTIES FOLDER "ThirdParty")

if (POLICY CMP0167)
  cmake_policy (SET CMP0167 OLD)
endif ()

#find_package(Boost REQUIRED)
#add_subdirectory(cereal)
#add_subdirectory(asio)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/ImGui.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/imGuizmo.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/stb.cmake)
