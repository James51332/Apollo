#include <Apollo.h>
#include <string>
#include <glm/glm.hpp>

class Example : public Apollo::Game
{
public:
  void Initialize() override
  {
    WindowDescription = Apollo::WindowDescription(1280, 720, "Example");

    std::string vertexSource = R"(#version 330 core

    layout(location = 0) in vec3 a_Pos;
    out vec3 v_Color;
    
    uniform mat4 u_Camera;

    void main() {
      v_Color = vec3(1.0, 1.0, 1.0);
      gl_Position = u_Camera * vec4(a_Pos, 1.0);
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

    float vertices[] = {
        0.5f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f};
    Apollo::VertexBuffer *vertexBuffer = Apollo::VertexBuffer::Create(vertices, sizeof(vertices));
    Apollo::BufferLayout layout = {{Apollo::ShaderDataType::Float3, "a_Pos"}};
    vertexBuffer->SetLayout(layout);

    uint32_t indices[] = {0, 1, 2, 0, 2, 3};
    Apollo::IndexBuffer *indexBuffer = Apollo::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));

    vertexArray = Apollo::VertexArray::Create();
    vertexArray->AddVertexBuffer(vertexBuffer);
    vertexArray->SetIndexBuffer(indexBuffer);

    Camera.SetPosition({0.25f, 0.25f, 0.0f});
  }

  void Update() override
  {
    Camera.SetRotation(++rotate);
  }

  void Draw() override
  {
    Apollo::RenderCommand::ClearColor(0.2f, 0.2f, 0.2f);
    Apollo::RenderCommand::Clear();

    Apollo::Renderer::Begin(Camera);
    Apollo::Renderer::Submit(shader, vertexArray);
    Apollo::Renderer::End();
  }

  void Deinitialize() override
  {
  }

private:
  Apollo::Shader *shader;
  Apollo::VertexArray *vertexArray;

  float rotate = 0;
};

int main()
{
  Example *instance = new Example();
  instance->Run();
  delete instance;

  return 0;
}
