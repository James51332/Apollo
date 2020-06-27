#include <Apollo/Apollo.h>
#include <OpenGL/gl.h>

class Example : public Apollo::Game
{
public:
  void Initialize() override
  {
    WindowDescription = Apollo::WindowDescription(1280, 720, "Example");
  }

  void Update() override
  {
  }

  void Draw() override
  {
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(-0.5f, -0.5f);
    glEnd();
  }

  void Deinitialize() override
  {
  }

private:
  GLuint test;
  bool bruh = false;
};

int main()
{
  Example *instance = new Example();
  instance->Run();
  delete instance;

  return 0;
}