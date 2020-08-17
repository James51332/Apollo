#ifndef Window_h
#define Window_h

#include <string>
#include <functional>

#include "Core/Base.h"

#include "Events/Event.h"
#include "Renderer/RenderingContext.h"

namespace Apollo
{

  struct WindowDescription
  {
    int Width, Height;
    std::string Title;

    bool Resizable = true;
    RenderingApi::Api ContextApi = RenderingApi::Api::OpenGL;

    WindowDescription(int width = 800, int height = 600, const std::string &title = "Apollo Game")
        : Width(width), Height(height), Title(title) {}
  };

  class Window
  {
  public:
    using WindowEventFn = std::function<void(Event &)>;

    static Scope<Window> Create(const WindowDescription &desc = WindowDescription());
    virtual ~Window();

    virtual void Show() = 0;
    virtual void Update() = 0;
    virtual void Close() = 0;

    virtual void SetEventCallback(const WindowEventFn &callback) = 0;
    virtual void SetContext(const Ref<RenderingContext> &context) = 0;
    virtual void SetDesc(const WindowDescription &desc) = 0;

    virtual int GetWidth() = 0;
    virtual int GetHeight() = 0;

  protected:
    Ref<RenderingContext> m_Context;
    WindowEventFn m_Callback;
  };

} // namespace Apollo

#endif /* end of include guard: Window_h */
