#include "VertexArray.h"
#include "Renderer.h"

#include "OpenGL/OpenGLVertexArray.h"

namespace Apollo
{

  Ref<VertexArray> VertexArray::Create()
  {
    switch (Renderer::GetCurrentApi())
    {
    case RenderingApi::Api::None:
      break;

    case RenderingApi::Api::OpenGL:
      return CreateRef<OpenGLVertexArray>();
    }

    return nullptr;
  }

  VertexArray::~VertexArray()
  {
  }

} // namespace Apollo
