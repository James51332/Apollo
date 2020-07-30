#include <Apollo.h>

#include "SandboxLayer.h"

class Sandbox : public Apollo::Game
{
public:
  Sandbox()
  {
    WindowDescription = Apollo::WindowDescription(1280, 720, "Sandbox");

    PushLayer(new SandboxLayer());
  }
};

int main()
{
  Sandbox *instance = new Sandbox();
  instance->Run();
  delete instance;

  return 0;
}
