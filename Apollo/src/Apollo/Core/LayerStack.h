#ifndef LayerStack_h
#define LayerStack_h

#include "Layer.h"

#include <vector>

namespace Apollo
{

  class LayerStack
  {
  public:
    LayerStack();
    ~LayerStack();

    void PushLayer(Layer *layer);
    void PushOverlay(Layer *overlay);

    void PopLayer(Layer *layer);
    void PopOverlay(Layer *overlay);

    std::vector<Layer *>::iterator begin() { return m_Layers.begin(); }
    std::vector<Layer *>::iterator end() { return m_Layers.end(); }

    std::vector<Layer *>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
    std::vector<Layer *>::reverse_iterator rend() { return m_Layers.rend(); }

  private:
    std::vector<Layer *>::iterator m_LayerInsert;
    std::vector<Layer *> m_Layers;
  };

} // namespace Apollo

#endif /* end of include guard: LayerStack_h */