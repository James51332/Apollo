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

    void AddVertexBuffer(const Ref<VertexBuffer> &vertexBuffer);
    void SetIndexBuffer(const Ref<IndexBuffer> &indexBuffer);

  private:
    uint32_t m_RendererID;
    uint32_t m_Index = 0;
  };

} // namespace Apollo

#endif /* end of include guard: OpenGLVertexArray_h */