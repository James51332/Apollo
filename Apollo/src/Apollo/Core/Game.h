#ifndef Game_h
#define Game_h

#include "Core/Application.h"
#include "Core/Window.h"

#include "Renderer/Camera.h"

#include "LayerStack.h"

namespace Apollo
{

  class Game
  {
  public:
    Game();
    virtual ~Game();
      
    void PushLayer(Layer *layer);
    void PushOverlay(Layer *overlay);

    void Run();

  private:
    Application *m_Application;
    Window *m_Window;
    LayerStack m_LayerStack;

  protected:
    WindowDescription WindowDescription;
  };

} // namespace Apollo

#endif /* end of include guard: Game_h */
