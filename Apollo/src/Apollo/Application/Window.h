#ifndef Window_h
#define Window_h

#include <string>

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
    static Window *Create(const WindowDescription &desc = WindowDescription());
    virtual ~Window();

    virtual void Update() = 0;
    virtual void SetContext(RenderingContext *context) = 0;

    virtual int GetWidth() = 0;
    virtual int GetHeight() = 0;

    virtual void SetDesc(const WindowDescription &desc) = 0;
    virtual void Show() = 0;

    bool
    IsOpen() const
    {
      return m_Open;
    }

  protected:
    RenderingContext *m_Context;

    bool m_Open = false;
  };

} // namespace Apollo

#endif /* end of include guard: Window_h */