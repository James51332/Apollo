#ifndef Renderer_h
#define Renderer_h

#include "RenderingApi.h"
#include "Shader.h"
#include "VertexArray.h"
#include "Camera.h"

#include <glm/glm.hpp>

namespace Apollo
{

  class Renderer
  {
  public:
    inline static RenderingApi::Api GetCurrentApi()
    {
      return s_Api;
    }
    inline static void SetCurrentApi(RenderingApi::Api api)
    {
      s_Api = api;
    }

    static void Begin(const OrthographicCamera &camera);
    static void Submit(Shader *shader, VertexArray *array, const glm::mat4 &transform = glm::mat4(1.0f));
    static void End();

  private:
    static RenderingApi::Api s_Api;
    static glm::mat4 s_ProjectionView;
  };

} // namespace Apollo

#endif /* end of include guard: Renderer_h */