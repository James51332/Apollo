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

    void UploadMat4(const std::string &name, Matrix4 &matrix);

  private:
    unsigned int m_RendererID;
  };

} // namespace Apollo

#endif /* end of include guard: OpenGLShader_h */