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
    
    void SetCallback(const Window::EventCallbackFn &callback);

  protected:
    void *m_View;
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

  private:
    void *m_Context;
  };

} // namespace Apollo

#endif /* end of include guard: CocoaContext_h */