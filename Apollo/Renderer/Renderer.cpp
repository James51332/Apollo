#include "Renderer.h"
#include "RenderCommand.h"

namespace Apollo
{
  RenderingApi::Api Renderer::m_Api = RenderingApi::Api::OpenGL;

  void Renderer::Begin()
  {
  }

  void Renderer::Submit(Shader *shader, VertexArray *vertexArray)
  {
    shader->Bind();
    RenderCommand::DrawIndexed(vertexArray);
  }

  void Renderer::End()
  {
  }

} // namespace Apollo
