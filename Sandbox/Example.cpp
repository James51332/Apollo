#include <Apollo/Apollo.h>
#include "Platform/OpenGL/OpenGLLoader.h"
#include "Renderer/Shader.h"

#include <iostream>
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

    Apollo::Shader *shader = Apollo::Shader::Create(vertexSource, fragmentSource);
    shader->Bind();

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    float vertices[] = {0.0f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f};
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), (uint32_t *)vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &ibo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    uint32_t indices[] = {0, 1, 2};
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), (uint32_t *)indices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, 12, (void *)0);
  }

  void Update() override
  {
  }

  void Draw() override
  {
    glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
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