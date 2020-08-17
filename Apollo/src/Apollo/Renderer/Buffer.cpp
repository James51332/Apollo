#include "Buffer.h"
#include "OpenGL/OpenGLBuffer.h"

namespace Apollo
{

  ////////////////////////////////////////////////////////////
  ///// VertexBuffer /////////////////////////////////////////
  ////////////////////////////////////////////////////////////

  Ref<VertexBuffer> VertexBuffer::Create(float *vertices, uint32_t size)
  {
    return CreateRef<OpenGLVertexBuffer>(vertices, size);
  }

  VertexBuffer::~VertexBuffer()
  {
  }

  ////////////////////////////////////////////////////////////
  ///// IndexBuffer //////////////////////////////////////////
  ////////////////////////////////////////////////////////////

  Ref<IndexBuffer> IndexBuffer::Create(uint32_t *indices, uint32_t count)
  {
    return CreateRef<OpenGLIndexBuffer>(indices, count);
  }

  IndexBuffer::~IndexBuffer()
  {
  }

} // namespace Apollo
