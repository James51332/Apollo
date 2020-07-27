#include "Shader.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Apollo
{

  Shader *Shader::Create(const std::string &vertexSrc, const std::string &fragmentSrc)
  {
    return new OpenGLShader(vertexSrc, fragmentSrc);
  }

  Shader::~Shader()
  {
  }

} // namespace Apollo
