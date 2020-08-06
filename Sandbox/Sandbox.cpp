#include <Apollo.h>
#include <string>

class SandboxLayer : public Apollo::Layer
{
public:
  SandboxLayer()
      : Layer("Sandbox"), m_Camera(-16.0f, 16.0f, -9.0f, 9.0f)
  {
    // Create the vertex array
    m_VertexArray = Apollo::VertexArray::Create();

    float vertices[] = {
        5.0f, 5.0f, 0.0f, 1.0f, 0.0f, 0.0f,  // top right
        5.0f, -5.0f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom right
        -5.0f, -5.0f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom left
        -5.0f, 5.0f, 0.0f, 1.0f, 1.0f, 1.0f // top left
    };
    Apollo::VertexBuffer *vertexBuffer = Apollo::VertexBuffer::Create(vertices, sizeof(vertices));
    vertexBuffer->SetLayout({
        {Apollo::ShaderDataType::Float3, "a_Pos"}, // pos
        {Apollo::ShaderDataType::Float3, "a_Color"} // color
    });
    m_VertexArray->AddVertexBuffer(vertexBuffer);

    uint32_t indices[] = {0, 1, 3, 2, 3, 1};
    Apollo::IndexBuffer *indexBuffer = Apollo::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
    m_VertexArray->SetIndexBuffer(indexBuffer);

      
    // create the second vertex array
      m_TriangleVa = Apollo::VertexArray::Create();
      
    float vertex[] = {
          0.0f, 2.0f, 0.0f, 1.0f, 1.0f, 1.0f,  // top
          2.0f, -2.0f, 0.0f, 1.0f, 1.0f, 1.0f, // bottom right
          -2.0f, -2.0f, 0.0f, 1.0f, 1.0f, 1.0f, // bottom left
    };
      Apollo::VertexBuffer *vb = Apollo::VertexBuffer::Create(vertex, sizeof(vertex));
      vb->SetLayout({
          {Apollo::ShaderDataType::Float3, "a_Pos"}, // pos
          {Apollo::ShaderDataType::Float3, "a_Color"} // color
      });
      m_TriangleVa->AddVertexBuffer(vb);
      
      uint32_t index[] = {
          0, 1, 2
      };
      Apollo::IndexBuffer *ib = Apollo::IndexBuffer::Create(index, sizeof(index) / sizeof(uint32_t));
      m_TriangleVa->SetIndexBuffer(ib);
      
    // create the shader
    std::string vertexSrc = R"(
      #version 330 core

      layout(location = 0) in vec3 a_Pos;
      layout(location = 1) in vec3 a_Color;
      
      uniform mat4 u_Camera;

      out vec3 v_Color;

      void main() {
        v_Color = a_Color;
        gl_Position = u_Camera * vec4(a_Pos, 1.0);
      }
    )";

    std::string fragmentSrc = R"(
      #version 330 core

      in vec3 v_Color;

      layout(location = 0) out vec4 f_Color;

      void main() {
        f_Color = vec4(v_Color, 1.0);
      }
    )";

      m_Shader = Apollo::Shader::Create(vertexSrc, fragmentSrc);
  }

  ~SandboxLayer()
  {
  }

  void OnUpdate(Apollo::Timestep time) override
  {
    Apollo::RenderCommand::ClearColor(0.2f, 0.2f, 0.2f);
    Apollo::RenderCommand::Clear();

    Apollo::Renderer::Begin(m_Camera);
    Apollo::Renderer::Submit(m_Shader, m_VertexArray);
    Apollo::Renderer::Submit(m_Shader, m_TriangleVa);
    Apollo::Renderer::End();
  }

private:
  Apollo::OrthographicCamera m_Camera;

  Apollo::Shader *m_Shader;
  Apollo::VertexArray *m_VertexArray, *m_TriangleVa;
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
