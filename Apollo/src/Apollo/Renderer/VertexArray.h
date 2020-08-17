#ifndef VertexArray_h
#define VertexArray_h

#include "Core/Base.h"

#include "Buffer.h"

#include <vector>

namespace Apollo
{

  class VertexArray
  {
  public:
    static Ref<VertexArray> Create();
    virtual ~VertexArray();

    virtual void Bind() = 0;
    virtual void Unbind() = 0;

    virtual void AddVertexBuffer(const Ref<VertexBuffer> &vertexBuffer) = 0;
    virtual void SetIndexBuffer(const Ref<IndexBuffer> &indexBuffer) = 0;

    const Ref<IndexBuffer> &GetIndexBuffer() const { return m_IndexBuffer; }

  protected:
    std::vector<Ref<VertexBuffer>> m_VertexBuffers;
    Ref<IndexBuffer> m_IndexBuffer;
  };

} // namespace Apollo

#endif /* end of include guard: VertexArray_h */
