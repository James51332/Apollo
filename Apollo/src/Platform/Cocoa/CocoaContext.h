#ifndef CocoaContext_h
#define CocoaContext_h

#include "Core/Window.h"

#include "Renderer/RenderingContext.h"

namespace Apollo
{

  ////////////////////////////////////////////////////////////
  ///// CocoaContext /////////////////////////////////////////
  ////////////////////////////////////////////////////////////

  class CocoaContext : public RenderingContext
  {
  public:
    static Ref<CocoaContext> Create(RenderingApi::Api api);
    virtual ~CocoaContext();

    virtual void OnUpdate() = 0;

    virtual void SetEventCallback(const Window::WindowEventFn &callback) = 0;
    virtual void SetWindow(void *window) = 0;

  protected:
    Window::WindowEventFn m_Callback;
  };

  ////////////////////////////////////////////////////////////
  ///// CocoaOpenGLContext ///////////////////////////////////
  ////////////////////////////////////////////////////////////

  class CocoaOpenGLContext : public CocoaContext
  {
  public:
    CocoaOpenGLContext();
    ~CocoaOpenGLContext();

    void OnUpdate();

    void SetEventCallback(const Window::WindowEventFn &callback);
    void SetWindow(void *window);

  private:
    void *m_View;
    void *m_Context;
  };

} // namespace Apollo

#endif /* end of include guard: CocoaContext_h */
