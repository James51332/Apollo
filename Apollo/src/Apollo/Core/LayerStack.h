#ifndef LayerStack_h
#define LayerStack_h

#include <vector>

#include "Layer.h"

namespace Apollo
{

  class LayerStack
  {
  public:
    LayerStack();
    ~LayerStack();

    void PushLayer(Layer *layer);
    void PopLayer(Layer *layer);
    void PushOverlay(Layer *layer);
    void PopOverlay(Layer *layer);

    std::vector<Layer *>::iterator begin() { return m_Layers.begin(); }
    std::vector<Layer *>::iterator end() { return m_Layers.end(); }

  private:
    std::vector<Layer *> m_Layers;
    std::vector<Layer *>::iterator m_LayerInsert;
  };

} // namespace Apollo

#endif /* end of include guard: LayerStack_h */
