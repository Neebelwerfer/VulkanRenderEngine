#include <iostream>
#include <GLFW/glfw3.h>

#include <vulkan/vulkan.h>>
#include <Application/Application.h>

int main()
{
    Application app(800, 600, "vulkan window");
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::cout << extensionCount << " extensions supported\n";

    app.run();


    glm::mat4 matrix{};
    glm::vec4 vec{};
    auto test = matrix * vec;

	return 0;
}
