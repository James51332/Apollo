#include "Game.h"

#include <iostream>

namespace Apollo
{

  Game::Game()
      : m_LayerStack()
  {
    m_Application = Application::Create();
    m_Window = Window::Create();
  }

  Game::~Game()
  {
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

  void Game::OnEvent(Event &event)
  {
    for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
    {
      if (event.Handled)
        break;
      (*it)->OnEvent(event);
    }
  }

  void Game::Run()
  {
    m_Window->SetEventCallback(std::bind(&Game::OnEvent, this, std::placeholders::_1));
    m_Window->SetDesc(WindowDescription);
    m_Window->Show();

    while (m_Window->IsOpen())
    {
      m_Application->Update();

      for (Layer *layer : m_LayerStack)
        layer->OnUpdate();

      m_Window->Update();
    }
  }

} // namespace Apollo
