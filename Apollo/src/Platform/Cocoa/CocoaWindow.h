#ifndef CocoaWindow_h
#define CocoaWindow_h

#include "Core/Window.h"

namespace Apollo
{

  class CocoaWindow : public Window
  {
  public:
    CocoaWindow(const WindowDescription &desc);
    ~CocoaWindow();

    void Update();
    void SetContext(RenderingContext *context);

    int GetWidth();
    int GetHeight();

    void SetDesc(const WindowDescription &desc);
    void Show();

  private:
    void *m_Object;
    void *m_Delegate;
  };

} // namespace Apollo

#endif /* end of include guard: CocoaWindow_h */
