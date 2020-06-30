#ifndef Buffer_h
#define Buffer_h

#include <cstdint>

namespace Apollo
{

  ////////////////////////////////////////////////////////////
  ///// VertexBuffer /////////////////////////////////////////
  ////////////////////////////////////////////////////////////

  class VertexBuffer
  {
  public:
    static VertexBuffer *Create(float *vertices, uint32_t size);
    virtual ~VertexBuffer();

    virtual void Bind() = 0;
    virtual void Unbind() = 0;
  };

  ////////////////////////////////////////////////////////////
  ///// IndexBuffer //////////////////////////////////////////
  ////////////////////////////////////////////////////////////

  class IndexBuffer
  {
  public:
    static IndexBuffer *Create(uint32_t *indices, uint32_t count);
    virtual ~IndexBuffer();

    virtual void Bind() = 0;
    virtual void Unbind() = 0;
  };

} // namespace Apollo

#endif /* end of include guard: Buffer_h */