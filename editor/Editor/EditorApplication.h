#include <Engine/Application/Application.h>
#include <Engine/Utility/ImGuiManager.h>

#include <vulkan/vulkan.h>


class EditorApplication : public Application
{
public:
	EditorApplication();
	~EditorApplication();

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;
	void Cleanup() override;

private:
	void RenderGUI();

	void InitVulkan();

private:
	ImGuiManager m_imgui;

	VkInstance m_instance;
};