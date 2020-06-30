#ifndef OpenGLBuffer_h
#define OpenGLBuffer_h

#include "Renderer/Buffer.h"

namespace Apollo
{
  ////////////////////////////////////////////////////////////
  ///// OpenGLVertexBuffer ///////////////////////////////////
  ////////////////////////////////////////////////////////////

  class OpenGLVertexBuffer : public VertexBuffer
  {
  public:
    OpenGLVertexBuffer(float *vertices, uint32_t size);
    ~OpenGLVertexBuffer();

    void Bind();
    void Unbind();

    void SetLayout(const BufferLayout &layout);

  private:
    unsigned int m_RendererID;
  };

  ////////////////////////////////////////////////////////////
  ///// OpenGLIndexBuffer ////////////////////////////////////
  ////////////////////////////////////////////////////////////

  class OpenGLIndexBuffer : public IndexBuffer
  {
  public:
    OpenGLIndexBuffer(uint32_t *vertices, uint32_t count);
    ~OpenGLIndexBuffer();

    void Bind();
    void Unbind();

  private:
    unsigned int m_RendererID;
  };
} // namespace Apollo

#endif /* end of include guard: OpenGLBuffer_h */