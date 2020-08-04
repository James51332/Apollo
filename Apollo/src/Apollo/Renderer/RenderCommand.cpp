#include "RenderCommand.h"

#include "OpenGL/OpenGLRenderingApi.h"

namespace Apollo
{

  RenderingApi *RenderCommand::s_RenderingApi = new OpenGLRenderingApi();

  void RenderCommand::ClearColor(float red, float blue, float green, float alpha)
  {
    s_RenderingApi->ClearColor(red, green, blue, alpha);
  }

  void RenderCommand::Clear()
  {
    s_RenderingApi->Clear();
  }

  void RenderCommand::DrawIndexed(VertexArray *vertexArray)
  {
      vertexArray->Bind();
    s_RenderingApi->DrawIndexed(vertexArray);
  }

} // namespace Apollo
