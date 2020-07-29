#include "Renderer.h"
#include "RenderCommand.h"

namespace Apollo
{
  RenderingApi::Api Renderer::s_Api = RenderingApi::Api::OpenGL;
  glm::mat4 Renderer::s_ProjectionView = glm::mat4(1.0f);

  void Renderer::Begin(const OrthographicCamera &camera)
  {
    s_ProjectionView = camera.GetProjectionView();
  }

  void Renderer::Submit(Shader *shader, VertexArray *vertexArray)
  {
    shader->UploadMat4("u_Camera", s_ProjectionView);
    shader->Bind();
    RenderCommand::DrawIndexed(vertexArray);
  }

  void Renderer::End()
  {
  }

} // namespace Apollo
