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
      None = 0,
      OpenGL
    };

  public:
    virtual ~RenderingApi() {}

    virtual void ClearColor(float red, float green, float blue, float alpha) = 0;
    virtual void Clear() = 0;

    virtual void DrawIndexed(const Ref<VertexArray> &vertexArray) = 0;
  };

} // namespace Apollo

#endif /* end of include guard: RenderingApi_h */