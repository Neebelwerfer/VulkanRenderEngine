#include <iostream>
#include <GLFW/glfw3.h>

#include <vulkan/vulkan.h>>
#include "EditorApplication.h"
int main()
{
    EditorApplication app(800, 600);
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::cout << extensionCount << " extensions supported\n";

    app.Run();


    glm::mat4 matrix{};
    glm::vec4 vec{};
    auto test = matrix * vec;

	return 0;
}
