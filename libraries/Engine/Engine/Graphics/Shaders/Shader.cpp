#include "Shader.h"
#include <fstream>
#include <string>
#include <vector>

static std::vector<char> readFile(const std::string& filename)
{
	std::ifstream file(filename, std::ios::ate | std::ios::binary);

	if (!file.is_open()) {
		throw std::runtime_error("failed to open file!");
	}

	size_t fileSize = (size_t)file.tellg();
	std::vector<char> buffer(fileSize);

	file.seekg(0);
	file.read(buffer.data(), fileSize);
	file.close();

	return buffer;
}

Shader::Shader(const Device& device, const char* filename, ShaderTypes type)
	: m_device(device)
	, m_type(type)
{
	auto shaderCode = readFile(filename);

	m_shaderModule = CreateShaderModule(shaderCode);
}

Shader::~Shader()
{
	vkDestroyShaderModule(m_device.GetHandle(), m_shaderModule, nullptr);
}

VkShaderModule Shader::CreateShaderModule(const std::vector<char>& code)
{
	VkShaderModuleCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
	createInfo.codeSize = code.size();
	createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

	VkShaderModule shaderModule;
	if (vkCreateShaderModule(m_device.GetHandle(), &createInfo, nullptr, &shaderModule) != VK_SUCCESS) {
		throw std::runtime_error("failed to create shader module!");
	}
	return shaderModule;
}