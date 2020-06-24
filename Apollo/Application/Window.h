#ifndef Window_h
#define Window_h

#include <string>

namespace Apollo
{

  struct WindowDescription
  {
    int Width, Height;
    std::string Title;

    bool Resizable = true;

    WindowDescription(int width = 800, int height = 600, const std::string &title = "Apollo Game")
        : Width(width), Height(height), Title(title) {}
  };

  class Window
  {
  public:
    static Window *Create(const WindowDescription &desc = WindowDescription());
    virtual ~Window();

    virtual void Update() = 0;

    bool IsOpen() const { return m_Open; }

  protected:
    bool m_Open = false;
  };

} // namespace Apollo

#endif /* end of include guard: Window_h */