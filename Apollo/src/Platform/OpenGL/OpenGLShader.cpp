#include "OpenGLShader.h"
#include "OpenGLLoader.h"

#include <iostream>
#include <glm/gtc/type_ptr.hpp>

namespace Apollo
{
  OpenGLShader::OpenGLShader(const std::string &vertexSrc, const std::string &fragmentSrc)
  {
    const char *vertexSource = vertexSrc.c_str();
    GLuint vertexID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexID, 1, &vertexSource, 0);
    glCompileShader(vertexID);

    const char *fragmentSource = fragmentSrc.c_str();
    GLuint fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentID, 1, &fragmentSource, 0);
    glCompileShader(fragmentID);

    int vertSuccess, fragSuccess;
    glGetShaderiv(vertexID, GL_COMPILE_STATUS, &vertSuccess);
    glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &fragSuccess);

    if (!vertSuccess)
    {
      char infoLog[512];
      glGetShaderInfoLog(vertexID, 512, 0, infoLog);
      std::cout << infoLog << std::endl;
    }

    if (!fragSuccess)
    {
      char infoLog[512];
      glGetShaderInfoLog(fragmentID, 512, 0, infoLog);
      std::cout << infoLog << std::endl;
    }

    m_RendererID = glCreateProgram();
    glAttachShader(m_RendererID, vertexID);
    glAttachShader(m_RendererID, fragmentID);
    glLinkProgram(m_RendererID);

    int linkSuccess;
    glGetProgramiv(m_RendererID, GL_LINK_STATUS, &linkSuccess);
    if (!linkSuccess)
    {
      char infoLog[512];
      glGetProgramInfoLog(m_RendererID, 512, 0, infoLog);
      std::cout << infoLog << std::endl;
    }
  }

  OpenGLShader::~OpenGLShader()
  {
    glDeleteProgram(m_RendererID);
  }

  void OpenGLShader::Bind()
  {
    glUseProgram(m_RendererID);
  }

  void OpenGLShader::Unbind()
  {
    glUseProgram(0);
  }

  void OpenGLShader::UploadMatrix3(const std::string &name, const glm::mat3 &matrix)
  {
    GLint location = glGetUniformLocation(m_RendererID, name.c_str());
    glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
  }

  void OpenGLShader::UploadMatrix4(const std::string &name, const glm::mat4 &matrix)
  {
    GLint location = glGetUniformLocation(m_RendererID, name.c_str());
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
  }

  void OpenGLShader::UploadFloat(const std::string &name, float value)
  {
    GLint location = glGetUniformLocation(m_RendererID, name.c_str());
    glUniform1f(location, value);
  }

  void OpenGLShader::UploadFloat2(const std::string &name, const glm::vec2 &vector)
  {
    GLint location = glGetUniformLocation(m_RendererID, name.c_str());
    glUniform2f(location, vector.x, vector.y);
  }

  void OpenGLShader::UploadFloat3(const std::string &name, const glm::vec3 &vector)
  {
    GLint location = glGetUniformLocation(m_RendererID, name.c_str());
    glUniform3f(location, vector.x, vector.y, vector.z);
  }

  void OpenGLShader::UploadFloat4(const std::string &name, const glm::vec4 &vector)
  {
    GLint location = glGetUniformLocation(m_RendererID, name.c_str());
    glUniform4f(location, vector.x, vector.y, vector.z, vector.w);
  }

} // namespace Apollo
