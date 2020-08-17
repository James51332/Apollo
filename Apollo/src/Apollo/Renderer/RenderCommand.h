#ifndef RenderCommand_h
#define RenderCommand_h

#include "RenderingApi.h"

namespace Apollo
{

  class RenderCommand
  {
  public:
    static void ClearColor(float red, float green, float blue, float alpha = 1.0);
    static void Clear();
    static void DrawIndexed(const Ref<VertexArray> &vertexArray);

  private:
    static RenderingApi *s_RenderingApi;
  };

} // namespace Apollo

#endif /* end of include guard: RenderCommand_h */