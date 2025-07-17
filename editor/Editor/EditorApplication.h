#include <Engine/Application/Application.h>
#include <Engine/Utility/ImGuiManager.h>
#include <Engine/Graphics/GraphicsInterface.h>

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

private:
	std::unique_ptr<GraphicsInterface> m_graphicsInterface;
	ImGuiManager m_imgui;
};