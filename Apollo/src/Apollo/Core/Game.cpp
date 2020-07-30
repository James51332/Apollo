#include "Game.h"

namespace Apollo
{

  Game::Game()
      : Camera(-1.6f, 1.6f, -0.9f, 0.9f)
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

  void Game::Run()
  {
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
