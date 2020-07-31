#ifndef Layer_h
#define Layer_h

#include "Events/Event.h"

#include <string>

namespace Apollo
{

  class Layer
  {
  public:
    Layer(const std::string &debguName);
    virtual ~Layer();

    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void OnUpdate() {}
    virtual void OnEvent(Event &event) {}

  private:
    std::string m_DebugName;
  };

} // namespace Apollo

#endif /* end of include guard: Layer_h */