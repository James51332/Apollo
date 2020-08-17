#ifndef Shader_h
#define Shader_h

#include "Core/Base.h"

#include <string>
#include <glm/glm.hpp>

namespace Apollo
{

  class Shader
  {
  public:
    static Ref<Shader> Create(const std::string &vertexSrc, const std::string &fragmentSrc);
    virtual ~Shader();

    virtual void Bind() = 0;
    virtual void Unbind() = 0;
  };

} // namespace Apollo

#endif /* end of include guard: Shader_h */
