#ifndef Game_h
#define Game_h

#include "Application/Application.h"
#include "Application/Window.h"

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

  private:
    Application *m_Application;
    Window *m_Window;

  protected:
    WindowDescription WindowDescription;
  };

} // namespace Apollo

#endif /* end of include guard: Game_h */