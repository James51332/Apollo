#include <Apollo/Apollo.h>
#include "Platform/OpenGL/OpenGLLoader.h"

#include "Renderer/Shader.h"
#include "Renderer/Buffer.h"
#include "Renderer/VertexArray.h"

#include <string>

class Example : public Apollo::Game
{
public:
  void Initialize() override
  {
    WindowDescription = Apollo::WindowDescription(1280, 720, "Example");

    std::string vertexSource =
        R"(#version 330 core

    layout(location = 0) in vec3 a_Pos;
    out vec3 v_Color;

    void main() {
      v_Color = vec3(1.0, 1.0, 1.0);
      gl_Position = vec4(a_Pos, 1.0);
    })";

    std::string fragmentSource =
        R"(#version 330 core

    out vec4 FragColor;
    in vec3 v_Color;

    void main()
    {
      FragColor = vec4(v_Color, 1.0f);
    })";

    Apollo::VertexArray *vertexArray = Apollo::VertexArray::Create();

    float vertices[] = {0.0f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f};
    Apollo::VertexBuffer *vertexBuffer = Apollo::VertexBuffer::Create(vertices, sizeof(vertices));
    Apollo::BufferLayout layout = {{Apollo::ShaderDataType::Float3, "a_Pos"}};
    vertexBuffer->SetLayout(layout);
    vertexArray->AddVertexBuffer(vertexBuffer);

    uint32_t indices[] = {0, 1, 2};
    Apollo::IndexBuffer *indexBuffer = Apollo::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
    vertexArray->SetIndexBuffer(indexBuffer);

    Apollo::Shader *shader = Apollo::Shader::Create(vertexSource, fragmentSource);
    shader->Bind();
  }

  void Update() override
  {
  }

  void Draw() override
  {
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
  }

  void Deinitialize() override
  {
  }

private:
  GLuint vao, vbo, ibo, vshader, fshader;
};

int main()
{
  Example *instance = new Example();
  instance->Run();
  delete instance;

  return 0;
}