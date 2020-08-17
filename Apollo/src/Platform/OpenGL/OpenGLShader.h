#ifndef OpenGLShader_h
#define OpenGLShader_h

#include "Renderer/Shader.h"

namespace Apollo
{
  class OpenGLShader : public Shader
  {
  public:
    OpenGLShader(const std::string &vertexSrc, const std::string &fragmentSrc);
    ~OpenGLShader();

    void Bind();

    void Unbind();

    void UploadMatrix3(const std::string &name, const glm::mat3 &matrix);
    void UploadMatrix4(const std::string &name, const glm::mat4 &matrix);

    void UploadFloat(const std::string &name, float value);
    void UploadFloat2(const std::string &name, const glm::vec2 &vector);
    void UploadFloat3(const std::string &name, const glm::vec3 &vector);
    void UploadFloat4(const std::string &name, const glm::vec4 &vector);

  private:
    unsigned int m_RendererID;
  };

} // namespace Apollo

#endif /* end of include guard: OpenGLShader_h */
