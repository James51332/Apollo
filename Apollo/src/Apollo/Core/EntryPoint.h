#ifndef EntryPoint_h
#define EntryPoint_h

#ifdef APOLLO_MACOS

#include "Game.h"

namespace Apollo {
extern Game *CreateGame();
} // namespace Apollo

int main()
{
    auto app = Apollo::CreateGame();
    app->Run();
    delete app;
}

#endif

#endif /* end of include guard: EntryPoint_h */
