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

  void Renderer::Submit(const Ref<Shader> &shader, const Ref<VertexArray> &vertexArray, const glm::mat4 &transform)
  {
    shader->Bind();
    std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadMatrix4("u_Camera", s_ProjectionView);
    std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadMatrix4("u_Transform", transform);

    vertexArray->Bind();
    RenderCommand::DrawIndexed(vertexArray);
  }

  void Renderer::End()
  {
  }

} // namespace Apollo
