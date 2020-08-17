#include "Renderer.h"
#include "RenderCommand.h"

#include "OpenGL/OpenGLShader.h"

namespace Apollo
{
  RenderingApi::Api Renderer::s_Api = RenderingApi::Api::OpenGL;
  glm::mat4 Renderer::s_ProjectionView = glm::mat4(1.0f);

  void Renderer::Begin(const OrthographicCamera &camera)
  {
    s_ProjectionView = camera.GetProjectionView();
  }

  void Renderer::Submit(Shader *shader, VertexArray *vertexArray, const glm::mat4 &transform)
  {
    shader->Bind();
    static_cast<OpenGLShader *>(shader)->UploadMatrix4("u_Camera", s_ProjectionView);
    static_cast<OpenGLShader *>(shader)->UploadMatrix4("u_Transform", transform);

    vertexArray->Bind();
    RenderCommand::DrawIndexed(vertexArray);
  }

  void Renderer::End()
  {
  }

} // namespace Apollo
