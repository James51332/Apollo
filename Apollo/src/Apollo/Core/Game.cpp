#include "Game.h"

#include "Input.h"

#include <iostream>

namespace Apollo
{

    Game::Game()
        : m_LayerStack(), m_LastTime(0.0)
    {
        m_Application = Application::Create();

        Input::Initialize();

        m_Window = Window::Create();
        m_Window->SetEventCallback(std::bind(&Game::OnEvent, this, std::placeholders::_1));
    }

    Game::~Game()
    {
        m_Window->Close();
        delete m_Window;

        Input::Deinitialize();

        m_Application->Terminate();
        delete m_Application;
    }

    void Game::PushLayer(Layer *layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    void Game::PushOverlay(Layer *overlay)
    {
        m_LayerStack.PushOverlay(overlay);
    }

    void Game::SetWindowDescription(const WindowDescription &desc)
    {
        m_Window->SetDesc(desc);
    }

    void Game::OnEvent(Event &event)
    {
        EventDispatcher e(event);

        e.Dispatch<WindowCloseEvent>(std::bind(&Game::OnWindowClose, this, std::placeholders::_1));

        Input::OnEvent(event);

        for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
        {
            if (event.Handled)
                break;
            (*it)->OnEvent(event);
        }
    }

    bool Game::OnWindowClose(WindowCloseEvent &event)
    {
        m_Running = false;
        return true;
    }

    void Game::Run()
    {
        m_Window->Show();

        while (m_Running)
        {
            Timestep deltaTime = m_Application->GetTime() - m_LastTime;
            m_LastTime = m_Application->GetTime();

            m_Application->Update();

            for (Layer *layer : m_LayerStack)
                layer->OnUpdate(deltaTime);

            m_Window->Update();
        }
    }

} // namespace Apollo
