#include "VertexArray.h"
#include "OpenGL/OpenGLVertexArray.h"

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
