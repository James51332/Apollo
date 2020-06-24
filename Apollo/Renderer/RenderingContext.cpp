#include "RenderingContext.h"

#include "Platform/Cocoa/CocoaContext.h"

namespace Apollo
{

  RenderingContext *RenderingContext::Create(RenderingApi api)
  {
#ifdef APOLLO_COCOA
    return CocoaContext::Create(api);
#endif

    return nullptr;
  }

  RenderingContext::~RenderingContext()
  {
  }

} // namespace Apollo
