#ifndef Renderer_h
#define Renderer_h

#include "RenderingApi.h"
#include "Shader.h"
#include "VertexArray.h"
#include "Camera.h"

namespace Apollo
{

  class Renderer
  {
  public:
    inline static RenderingApi::Api GetCurrentApi() { return m_Api; }
    inline static void SetCurrentApi(RenderingApi::Api api) { m_Api = api; }

    static void Begin(const OrthographicCamera &camera);
    static void Submit(Shader *shader, VertexArray *array);
    static void End();

  private:
    static RenderingApi::Api m_Api;
    static Matrix4 m_ProjectionView;
  };

} // namespace Apollo

#endif /* end of include guard: Renderer_h */