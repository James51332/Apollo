#include "RenderingContext.h"

#include "Platform/Cocoa/CocoaContext.h"
#include "Platform/OpenGL/OpenGLLoader.h"

namespace Apollo
{

  bool RenderingContext::s_IsOpenGLInitialized = false;

  RenderingContext *RenderingContext::Create(RenderingApi::Api api)
  {
    RenderingContext *ctxt = nullptr;

#ifdef APOLLO_COCOA
    ctxt = CocoaContext::Create(api);
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
