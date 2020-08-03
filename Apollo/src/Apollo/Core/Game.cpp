#include "Game.h"

#include <iostream>

namespace Apollo
{

  Game::Game()
      : m_LayerStack()
  {
    m_Application = Application::Create();
    m_Window = Window::Create();

    m_Window->SetEventCallback(std::bind(&Game::OnEvent, this, std::placeholders::_1));
  }

  Game::~Game()
  {
    m_Window->Close();
    delete m_Window;

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
      m_Application->Update();

      for (Layer *layer : m_LayerStack)
        layer->OnUpdate();

      m_Window->Update();
    }
  }

} // namespace Apollo
