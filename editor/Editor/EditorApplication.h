#include <Engine/Core/Application.h>
#include <Engine/Utility/ImGuiManager.h>


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
	ImGuiManager m_imgui;
};