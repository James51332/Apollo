#ifndef Game_h
#define Game_h

#include "Application/Application.h"
#include "Application/Window.h"
#include "Events/ApplicationEvent.h"

#include "Renderer/Camera.h"

namespace Apollo
{

  class Game
  {
  public:
    Game();
    virtual ~Game();

    virtual void Initialize();
    virtual void Update();
    virtual void Draw();
    virtual void Deinitialize();

    void Run();

    void OnEvent(Event &event);
    bool OnWindowResize(WindowResizeEvent &event);

  private:
    Application *m_Application;
    Window *m_Window;

  protected:
    WindowDescription WindowDescription;
    OrthographicCamera Camera;
  };

} // namespace Apollo

#endif /* end of include guard: Game_h */