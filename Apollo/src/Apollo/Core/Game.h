#ifndef Game_h
#define Game_h

#include "Core/Application.h"
#include "Core/Window.h"

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

  private:
    Application *m_Application;
    Window *m_Window;

  protected:
    OrthographicCamera Camera;
    WindowDescription WindowDescription;
  };

} // namespace Apollo

#endif /* end of include guard: Game_h */
