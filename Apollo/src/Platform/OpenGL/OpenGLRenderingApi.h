#ifndef OpenGLRenderingApi_h
#define OpenGLRenderingApi_h

#include "Renderer/RenderingApi.h"

namespace Apollo
{

    class OpenGLRenderingApi : public RenderingApi
    {
    public:
        OpenGLRenderingApi();
        virtual ~OpenGLRenderingApi();

        void ClearColor(float red, float green, float blue, float alpha);
        void Clear();

        void DrawIndexed(VertexArray *vertexArray);
    };

} // namespace Apollo

#endif /* end of include guard: OpenGLRenderingApi_h */