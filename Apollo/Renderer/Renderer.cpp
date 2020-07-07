#include "Renderer.h"
#include "RenderCommand.h"

namespace Apollo
{
  RenderingApi::Api Renderer::m_Api = RenderingApi::Api::OpenGL;
  Matrix4 Renderer::m_ProjectionView = Matrix4(1.0f);

  void Renderer::Begin(const OrthographicCamera &camera)
  {
    m_ProjectionView = camera.GetProjectionViewMatrix();
  }

  void Renderer::Submit(Shader *shader, VertexArray *vertexArray)
  {
    shader->UploadMatrix4("u_Camera", m_ProjectionView);
    shader->Bind();
    RenderCommand::DrawIndexed(vertexArray);
  }

  void Renderer::End()
  {
  }

} // namespace Apollo
