#include <Apollo.h>
#include <string>

class SandboxLayer : public Apollo::Layer
{
public:
  SandboxLayer()
      : Layer("Sandbox"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f)
  {
    float vertices[4 * 6] = {
        0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f,   // top right
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, // bottom left
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f   // top left
    };
    Apollo::VertexBuffer *vertexBuffer = Apollo::VertexBuffer::Create(vertices, sizeof(vertices));

    Apollo::BufferLayout layout = {
        {Apollo::ShaderDataType::Float3, "a_Pos"}, // position
        {Apollo::ShaderDataType::Float3, "a_Pos"}  // color
    };
    vertexBuffer->SetLayout(layout);

    uint32_t indices[2 * 3] = {0, 1, 3, 1, 2, 3};
    Apollo::IndexBuffer *indexBuffer = Apollo::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));

    vertexArray = Apollo::VertexArray::Create();
    vertexArray->AddVertexBuffer(vertexBuffer);
    vertexArray->SetIndexBuffer(indexBuffer);

    std::string vertexSource = R"(#version 330 core

      layout(location = 0) in vec3 a_Pos;
      layout(location = 1) in vec3 a_Color;
      out vec3 v_Color;
      
      uniform mat4 u_Camera;

      void main() {
        v_Color = a_Color;
        gl_Position = u_Camera * vec4(a_Pos, 1.0);
      })";

    std::string fragmentSource = R"(#version 330 core

      out vec4 FragColor;
      in vec3 v_Color;

      void main()
      {
        FragColor = vec4(v_Color, 1.0);
      })";

    shader = Apollo::Shader::Create(vertexSource, fragmentSource);
  }

  ~SandboxLayer()
  {
  }

  void OnUpdate() override
  {
    glm::vec3 pos = m_Camera.GetPosition();
      
    if (Apollo::Input::IsKeyDown(Apollo::KeyW))
      pos += glm::vec3(0.0f, 0.05f, 0.0f);
      
    if (Apollo::Input::IsKeyDown(Apollo::KeyA))
      pos += glm::vec3(-0.05f, 0.0f, 0.0f);
      
    if (Apollo::Input::IsKeyDown(Apollo::KeyS))
      pos += glm::vec3(0.0f, -0.05f, 0.0f);
      
    if (Apollo::Input::IsKeyDown(Apollo::KeyD))
      pos += glm::vec3(0.05f, 0.0f, 0.0f);
      
    m_Camera.SetPosition(pos);
      
    float rot = m_Camera.GetRotation();
      
    if (Apollo::Input::IsKeyDown(Apollo::KeyRight))
      rot += 2.0f;
      
    if (Apollo::Input::IsKeyDown(Apollo::KeyLeft))
      rot -= 2.0f;
      
    m_Camera.SetRotation(rot);

    Apollo::RenderCommand::ClearColor(0.2f, 0.2f, 0.2f);
    Apollo::RenderCommand::Clear();

    Apollo::Renderer::Begin(m_Camera);
    Apollo::Renderer::Submit(shader, vertexArray);
    Apollo::Renderer::End();
  }

  void OnEvent(Apollo::Event &event) override
  {
    std::cout << event << std::endl;
  }

private:
  Apollo::Shader *shader;
  Apollo::VertexArray *vertexArray;
  Apollo::OrthographicCamera m_Camera;
};

class Sandbox : public Apollo::Game
{
public:
  Sandbox()
  {
    SetWindowDescription({1280, 720, "Sandbox"});
    PushLayer(new SandboxLayer());
  }
};

Apollo::Game *Apollo::CreateGame()
{
  return new Sandbox();
}
