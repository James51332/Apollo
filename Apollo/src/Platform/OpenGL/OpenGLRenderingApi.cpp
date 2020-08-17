#include "OpenGLRenderingApi.h"
#include "OpenGLLoader.h"

namespace Apollo
{

  OpenGLRenderingApi::OpenGLRenderingApi()
  {
  }

  OpenGLRenderingApi::~OpenGLRenderingApi()
  {
  }

  void OpenGLRenderingApi::ClearColor(float red, float green, float blue, float alpha)
  {
    glClearColor(red, green, blue, alpha);
  }

  void OpenGLRenderingApi::Clear()
  {
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
  }

  void OpenGLRenderingApi::DrawIndexed(const Ref<VertexArray> &vertexArray)
  {
    glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
  }

} // namespace Apollo
