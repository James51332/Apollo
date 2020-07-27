#ifndef EntryPoint_h
#define EntryPoint_h

#include "Game.h"

#ifdef APOLLO_MACOS

namespace Apollo
{

  extern Game *CreateApplication();

} // namespace Apollo

int main()
{
  Apollo::Game *app = Apollo::CreateApplication();
  app->Run();
  delete app;

  return 0;
}

#endif

#endif /* end of include guard: EntryPoint_h */