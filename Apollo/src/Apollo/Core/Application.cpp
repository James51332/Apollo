#include "Application.h"

#include "Cocoa/CocoaApplication.h"

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
