#ifndef Shader_h
#define Shader_h

#include "Math/Matrix4.h"

#include <string>

namespace Apollo
{

  class Shader
  {
  public:
    static Shader *Create(const std::string &vertexSrc, const std::string &fragmentSrc);
    virtual ~Shader();

    virtual void Bind() = 0;
    virtual void Unbind() = 0;

    virtual void UploadMatrix4(const std::string &name, const Matrix4 &matrix) = 0;
  };

} // namespace Apollo

#endif /* end of include guard: Shader_h */