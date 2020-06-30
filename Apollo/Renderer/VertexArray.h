#ifndef VertexArray_h
#define VertexArray_h

#include "Buffer.h"

#include <vector>

namespace Apollo
{

  class VertexArray
  {
  public:
    static VertexArray *Create();
    virtual ~VertexArray();

    virtual void Bind() = 0;
    virtual void Unbind() = 0;

    virtual void AddVertexBuffer(VertexBuffer *vertexBuffer) = 0;
    virtual void SetIndexBuffer(IndexBuffer *indexBuffer) = 0;

    virtual IndexBuffer *GetIndexBuffer() = 0;

  protected:
    std::vector<VertexBuffer *> m_VertexBuffers;
    IndexBuffer *m_IndexBuffer;
  };

} // namespace Apollo

#endif /* end of include guard: VertexArray_h */