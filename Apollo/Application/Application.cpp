#include "Application.h"

#include "Platform/Cocoa/CocoaApplication.h"

namespace Apollo
{

  Application *Application::Create()
  {
    return new CocoaApplication();
  }

  Application::~Application()
  {
  }

} // namespace Apollo
