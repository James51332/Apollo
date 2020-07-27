#include "OpenGLLoader.h"

#ifdef APOLLO_MACOS
#include <dlfcn.h>
#endif

#define GL_FUNC(ret, name, ...) \
  name##proc name;

GL_FUNCS

#undef GL_FUNC

void InitializeOpenGL()
{
#ifdef APOLLO_MACOS

  void *libgl = dlopen("/System/Library/Framework/OpenGL.framework/OpenGL", RTLD_LAZY | RTLD_LOCAL);
#define GL_FUNC(ret, name, ...) \
  *(void **)(&name) = dlsym(libgl, #name);

  GL_FUNCS

#undef GL_FUNC

#endif
}
