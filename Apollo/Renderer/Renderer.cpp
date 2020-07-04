#include "Renderer.h"
#include "RenderCommand.h"

namespace Apollo
{
  RenderingApi::Api Renderer::m_Api = RenderingApi::Api::OpenGL;
  Matrix4 Renderer::m_ProjectionView = Apollo::Matrix4(1.0f);

  void Renderer::Begin(OrthographicCamera *camera)
  {
    m_ProjectionView = camera->GetProjectionViewMatrix();
  }

  void Renderer::Submit(Shader *shader, VertexArray *vertexArray)
  {
    shader->Bind();
    shader->UploadMat4("u_ProjectionView", m_ProjectionView);
    RenderCommand::DrawIndexed(vertexArray);
  }

  void Renderer::End()
  {
  }

} // namespace Apollo
