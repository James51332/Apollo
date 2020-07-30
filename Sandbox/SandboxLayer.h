#ifndef SandboxLayer_h
#define SandboxLayer_h

#include <Apollo.h>

class SandboxLayer : public Apollo::Layer
{
public:
  SandboxLayer();
  ~SandboxLayer();

  void OnUpdate();
  void OnEvent(Apollo::Event &event);
};

#endif /* end of include guard: SandboxLayer_h */
