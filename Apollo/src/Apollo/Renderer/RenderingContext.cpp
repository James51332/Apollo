#include "RenderingContext.h"

#include "Cocoa/CocoaContext.h"
#include "OpenGL/OpenGLLoader.h"

#include <iostream>

namespace Apollo
{

  bool RenderingContext::s_IsOpenGLInitialized = false;

  Ref<RenderingContext> RenderingContext::Create(RenderingApi::Api api)
  {

#ifdef APOLLO_MACOS
    Ref<CocoaContext> ctxt(CocoaContext::Create(api));
#endif

    if (api == RenderingApi::Api::OpenGL && !RenderingContext::s_IsOpenGLInitialized)
    {
      InitializeOpenGL();
      RenderingContext::s_IsOpenGLInitialized = true;
    }

    return ctxt;
  }

  RenderingContext::~RenderingContext()
  {
  }

} // namespace Apollo
