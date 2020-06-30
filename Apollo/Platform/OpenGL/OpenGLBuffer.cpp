#include "OpenGLBuffer.h"
#include "OpenGLLoader.h"

namespace Apollo
{

  ////////////////////////////////////////////////////////////
  ///// OpenGLVertexBuffer ///////////////////////////////////
  ////////////////////////////////////////////////////////////

  OpenGLVertexBuffer::OpenGLVertexBuffer(float *vertices, uint32_t size)
  {
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
  }

  OpenGLVertexBuffer::~OpenGLVertexBuffer()
  {
    glDeleteBuffers(1, &m_RendererID);
  }

  void OpenGLVertexBuffer::Bind()
  {
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
  }

  void OpenGLVertexBuffer::Unbind()
  {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }

  ////////////////////////////////////////////////////////////
  ///// OpenGLIndexBuffer ////////////////////////////////////
  ////////////////////////////////////////////////////////////

  OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t *indices, uint32_t count)
  {

    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
  }

  OpenGLIndexBuffer::~OpenGLIndexBuffer()
  {
    glDeleteBuffers(1, &m_RendererID);
  }

  void OpenGLIndexBuffer::Bind()
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
  }

  void OpenGLIndexBuffer::Unbind()
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  }

} // namespace Apollo
