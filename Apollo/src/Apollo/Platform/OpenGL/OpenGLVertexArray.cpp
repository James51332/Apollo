#include "OpenGLVertexArray.h"
#include "OpenGLLoader.h"

#include "Renderer/Buffer.h"

namespace Apollo
{

  ////////////////////////////////////////////////////////////
  ///// ShaderDataType ///////////////////////////////////////
  ////////////////////////////////////////////////////////////

  static GLenum ShaderDataTypeToOpenGLEnum(ShaderDataType type)
  {
    switch (type)
    {
    case ShaderDataType::None:
      return 0;
      break;
    case ShaderDataType::Float:
      return GL_FLOAT;
      break;
    case ShaderDataType::Float2:
      return GL_FLOAT;
      break;
    case ShaderDataType::Float3:
      return GL_FLOAT;
      break;
    case ShaderDataType::Float4:
      return GL_FLOAT;
      break;
    case ShaderDataType::Mat3:
      return GL_FLOAT;
      break;
    case ShaderDataType::Mat4:
      return GL_FLOAT;
      break;
    case ShaderDataType::Int:
      return GL_INT;
      break;
    case ShaderDataType::Int2:
      return GL_INT;
      break;
    case ShaderDataType::Int3:
      return GL_INT;
      break;
    case ShaderDataType::Int4:
      return GL_INT;
      break;
    }
  }

  ////////////////////////////////////////////////////////////
  ///// OpenGLVertexArray ////////////////////////////////////
  ////////////////////////////////////////////////////////////

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

    for (const auto &element : vertexBuffer->GetLayout().GetElements())
    {
      glEnableVertexAttribArray(m_Index);
      glVertexAttribPointer(m_Index,
                            element.GetElementCount(),
                            ShaderDataTypeToOpenGLEnum(element.Type),
                            element.Normalized,
                            vertexBuffer->GetLayout().GetStride(),
                            (void *)(unsigned long)element.Offset);

      m_Index++;
    }

    m_VertexBuffers.push_back(vertexBuffer);
  }

  void OpenGLVertexArray::SetIndexBuffer(IndexBuffer *indexBuffer)
  {
    glBindVertexArray(m_RendererID);
    indexBuffer->Bind();

    m_IndexBuffer = indexBuffer;
  }

} // namespace Apollo