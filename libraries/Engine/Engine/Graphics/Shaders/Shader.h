#pragma once
#include <vulkan/vulkan.h>
#include <Engine/Graphics/Device/Device.h>

class Shader
{
public:
	enum ShaderTypes
	{
		Vertex,
		Fragment
	};

	Shader(const std::shared_ptr<Device> device, const char* filename, ShaderTypes type);
	~Shader();

	inline VkShaderModule GetHandle() { return m_shaderModule; }
	const inline VkShaderModule GetHandle() const { return m_shaderModule; }
private:
	VkShaderModule CreateShaderModule(const std::vector<char>& code);

private:
	VkShaderModule m_shaderModule;
	ShaderTypes m_type;
	const std::shared_ptr<Device> m_device;
};