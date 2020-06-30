#include "VertexArray.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Apollo
{

  VertexArray *VertexArray::Create()
  {
    return new OpenGLVertexArray();
  }

  VertexArray::~VertexArray()
  {
  }

} // namespace Apollo
