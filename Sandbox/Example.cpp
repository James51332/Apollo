#include <Apollo/Apollo.h>
#include <string>
#include <iostream>
#include <memory>

#include "Math/Matrix.h"

class Example : public Apollo::Game
{
public:
  void Initialize() override
  {
    //WindowDescription = Apollo::WindowDescription(1280, 720, "Example");

    std::string vertexSource = R"(#version 330 core

    layout(location = 0) in vec3 a_Pos;
    out vec3 v_Color;

    void main() {
      v_Color = vec3(1.0, 1.0, 1.0);
      gl_Position = vec4(a_Pos, 1.0);
    })";

    std::string fragmentSource = R"(#version 330 core

    out vec4 FragColor;
    in vec3 v_Color;

    void main()
    {
      FragColor = vec4(v_Color, 1.0f);
    })";

    shader = Apollo::Shader::Create(vertexSource, fragmentSource);
    shader->Bind();

    Apollo::Matrix4 m = Apollo::Matrix4(2.0);
    Apollo::Matrix4 l = Apollo::Matrix4(1.0);

    m = l * m;

    std::cout << m.LCol.X << m.LMCol.X << m.RMCol.X << m.RCol.X << std::endl;
    std::cout << m.LCol.Y << m.LMCol.Y << m.RMCol.Y << m.RCol.Y << std::endl;
    std::cout << m.LCol.Z << m.LMCol.Z << m.RMCol.Z << m.RCol.Z << std::endl;
    std::cout << m.LCol.W << m.LMCol.W << m.RMCol.W << m.RCol.W << std::endl;

    float vertices[] = {0.0f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f};
    Apollo::VertexBuffer *vertexBuffer = Apollo::VertexBuffer::Create(vertices, sizeof(vertices));
    Apollo::BufferLayout layout = {{Apollo::ShaderDataType::Float3, "a_Pos"}};
    vertexBuffer->SetLayout(layout);

    uint32_t indices[] = {0, 1, 2};
    Apollo::IndexBuffer *indexBuffer = Apollo::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));

    vertexArray = Apollo::VertexArray::Create();
    vertexArray->AddVertexBuffer(vertexBuffer);
    vertexArray->SetIndexBuffer(indexBuffer);
  }

  void Update() override
  {
  }

  void Draw() override
  {
    Apollo::RenderCommand::ClearColor(0.2f, 0.2f, 0.2f);
    Apollo::RenderCommand::Clear();

    Apollo::Renderer::Begin();
    Apollo::Renderer::Submit(shader, vertexArray);
    Apollo::Renderer::End();
  }

  void Deinitialize() override
  {
  }

private:
  Apollo::Shader *shader;
  Apollo::VertexArray *vertexArray;
};

int main()
{
  Example *instance = new Example();
  instance->Run();

  return 0;
}