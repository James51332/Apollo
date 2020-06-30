#ifndef OpenGLVertexArray_h
#define OpenGLVertexArray_h

#include "Renderer/VertexArray.h"

namespace Apollo
{

  class OpenGLVertexArray : public VertexArray
  {
  public:
    OpenGLVertexArray();
    ~OpenGLVertexArray();

    void Bind();
    void Unbind();

    void AddVertexBuffer(VertexBuffer *vertexBuffer);
    void SetIndexBuffer(IndexBuffer *indexBuffer);

    IndexBuffer *GetIndexBuffer();

  private:
    uint32_t m_RendererID;
    uint32_t m_Index;
  };

} // namespace Apollo

#endif /* end of include guard: OpenGLVertexArray_h */