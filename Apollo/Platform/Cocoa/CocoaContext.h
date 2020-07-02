#ifndef CocoaContext_h
#define CocoaContext_h

#include "Renderer/RenderingContext.h"
#include "Application/Window.h"

namespace Apollo
{

  ////////////////////////////////////////////////////////////
  ///// CocoaContext /////////////////////////////////////////
  ////////////////////////////////////////////////////////////

  class CocoaContext : public RenderingContext
  {
  public:
    static CocoaContext *Create(RenderingApi::Api api);
    virtual ~CocoaContext();

    virtual void Update() = 0;
    virtual void SetWindow(void *window) = 0;
    virtual void SetCallback(const Window::EventCallbackFn &callback) = 0;
  };

  ////////////////////////////////////////////////////////////
  ///// CocoaOpenGLContext ///////////////////////////////////
  ////////////////////////////////////////////////////////////

  class CocoaOpenGLContext : public CocoaContext
  {
  public:
    CocoaOpenGLContext();
    ~CocoaOpenGLContext();

    void Update();
    void SetWindow(void *window);
    void SetCallback(const Window::EventCallbackFn &callback);

  private:
    void *m_View;
    void *m_Context;
  };

} // namespace Apollo

#endif /* end of include guard: CocoaContext_h */