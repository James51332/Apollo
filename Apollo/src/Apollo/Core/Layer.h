#ifndef Layer_h
#define Layer_h

#include <string>

#include "Events/Event.h"

namespace Apollo
{

  class Layer
  {
  public:
    Layer(const std::string &debugName = "Layer");
    virtual ~Layer();

    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void OnUpdate() {}
    virtual void OnEvent(Event &event) {}

    inline const std::string &GetName() const { return m_DebugName; }

  private:
    std::string m_DebugName;
  };

} // namespace Apollo

#endif /* end of include guard: Layer_h */