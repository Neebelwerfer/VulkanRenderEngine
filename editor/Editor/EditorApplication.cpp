#include "EditorApplication.h"
#include <iostream>
#include <imgui.h>
#include <vector>

EditorApplication::EditorApplication()
	: Application(800, 600, "Editor")
	, m_instance(nullptr)
{
}

EditorApplication::~EditorApplication()
{
}

void EditorApplication::Initialize()
{
	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
	std::cout << extensionCount << " extensions supported\n";


	glm::mat4 matrix{};
	glm::vec4 vec{};
	auto test = matrix * vec;
	//m_imgui.Initialize(GetMainWindow());

	InitVulkan();
}

void EditorApplication::Update() 
{

}

void EditorApplication::Render()
{
	RenderGUI();
}

void EditorApplication::Cleanup()
{
	vkDestroyInstance(m_instance, nullptr);
	Application::Cleanup();
	//m_imgui.Cleanup();
}

void EditorApplication::RenderGUI()
{
	//m_imgui.BeginFrame();

	//m_imgui.EndFrame();
}

void EditorApplication::InitVulkan()
{
	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Hello Triangle";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "Vulkan Render Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(0, 1, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;

	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	createInfo.enabledExtensionCount = glfwExtensionCount;
	createInfo.ppEnabledExtensionNames = glfwExtensions;
	createInfo.enabledLayerCount = 0;

	VkResult result = vkCreateInstance(&createInfo, nullptr, &m_instance);

	if (vkCreateInstance(&createInfo, nullptr, &m_instance) != VK_SUCCESS) {
		throw std::runtime_error("failed to create instance!");
	}

	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
	std::vector<VkExtensionProperties> extensions(extensionCount);
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
	std::cout << "available extensions:\n";

	for (const auto& extension : extensions) {
		std::cout << '\t' << extension.extensionName << '\n';
	}
}
