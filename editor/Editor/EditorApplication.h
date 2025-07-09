#include <Application/Application.h>
#include <Utility/ImGuiManager.h>

class EditorApplication : public Application
{
public:
	EditorApplication(int width, int height);
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