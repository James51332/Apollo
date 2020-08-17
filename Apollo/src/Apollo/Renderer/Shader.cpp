#include "Shader.h"
#include "OpenGL/OpenGLShader.h"

namespace Apollo
{

  Ref<Shader> Shader::Create(const std::string &vertexSrc, const std::string &fragmentSrc)
  {
    return CreateRef<OpenGLShader>(vertexSrc, fragmentSrc);
  }

  Shader::~Shader()
  {
  }

} // namespace Apollo
