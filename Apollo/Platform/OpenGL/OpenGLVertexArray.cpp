#include "OpenGLVertexArray.h"
#include "OpenGLLoader.h"

namespace Apollo
{

  OpenGLVertexArray::OpenGLVertexArray()
  {
    glGenVertexArrays(1, &m_RendererID);
  }

  OpenGLVertexArray::~OpenGLVertexArray()
  {
    glDeleteVertexArray(1, &m_RendererID);
  }

  void OpenGLVertexArray::Bind()
  {
    glBindVertexArray(m_RendererID);
  }

  void OpenGLVertexArray::Unbind()
  {
    glBindVertexArray(0);
  }

  void OpenGLVertexArray::AddVertexBuffer(VertexBuffer *vertexBuffer)
  {
    glBindVertexArray(m_RendererID);
    vertexBuffer->Bind();

    m_VertexBuffers.push_back(vertexBuffer);
  }

  void OpenGLVertexArray::SetIndexBuffer(IndexBuffer *indexBuffer)
  {
    glBindVertexArray(m_RendererID);
    indexBuffer->Bind();

    m_IndexBuffer = indexBuffer;
  }

  IndexBuffer *OpenGLVertexArray::GetIndexBuffer()
  {
    return m_IndexBuffer;
  }

} // namespace Apollo
