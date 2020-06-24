#include <Apollo/Apollo.h>

class Example : public Apollo::Game
{
public:
  void Initialize() override
  {
  }

  void Update() override
  {
  }

  void Draw() override
  {
  }

  void Deinitialize() override
  {
  }
};

int main()
{
  Example *instance = new Example();
  instance->Run();
  delete instance;

  return 0;
}