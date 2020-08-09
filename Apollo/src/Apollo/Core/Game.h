#ifndef Game_h
#define Game_h

#include "Core/Application.h"
#include "Core/Window.h"
#include "Core/LayerStack.h"
#include "Core/Layer.h"
#include "Core/Timestep.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace Apollo
{

    class Game
    {
    public:
        Game();
        virtual ~Game();

        void PushLayer(Layer *layer);
        void PushOverlay(Layer *overlay);

        void SetWindowDescription(const WindowDescription &desc);

        void OnEvent(Event &event);
        bool OnWindowClose(WindowCloseEvent &event);

        void Run();

    private:
        Application *m_Application;
        Window *m_Window;

        LayerStack m_LayerStack;
        Timestep m_LastTime;

        bool m_Running = true;
    };

} // namespace Apollo

#endif /* end of include guard: Game_h */
