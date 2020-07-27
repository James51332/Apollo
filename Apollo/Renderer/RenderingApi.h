#ifndef RenderingApi_h
#define RenderingApi_h

#include "VertexArray.h"

namespace Apollo
{

  class RenderingApi
  {
  public:
    enum class Api
    {
#ifdef APOLLO_MACOS
      None = 0,
      OpenGL
#else
      None = 0
#endif
    };

  public:
    virtual ~RenderingApi() {}

    virtual void ClearColor(float red, float green, float blue, float alpha) = 0;
    virtual void Clear() = 0;

    virtual void DrawIndexed(VertexArray *vertexArray) = 0;
  };

} // namespace Apollo

#endif /* end of include guard: RenderingApi_h */