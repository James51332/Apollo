#include "Game.h"

#include <iostream>

namespace Apollo
{

  Game::Game()
      : Camera(-1.0, 1.0, -1.0, 1.0)
  {
    m_Application = Application::Create();
  }

  Game::~Game()
  {
    delete m_Window;
    delete m_Application;
  }

  void Game::Initialize()
  {
    m_Window = Window::Create();
  }

  void Game::Update()
  {
    m_Application->Update();
  }

  void Game::Draw()
  {
    m_Window->Update();
  }

  void Game::Deinitialize()
  {
    m_Application->Terminate();
  }

  void Game::Run()
  {
    Game::Initialize();
    Initialize();

    m_Window->SetEventCallback(std::bind(&Game::OnEvent, this, std::placeholders::_1));
    Camera.SetBounds(-0.00125 * WindowDescription.Width, 0.00125 * WindowDescription.Width, -0.00125 * WindowDescription.Height, 0.00125 * WindowDescription.Height);
    m_Window->SetDesc(WindowDescription);
    m_Window->Show();

    while (m_Window->IsOpen())
    {
      Game::Update();
      Update();

      Draw();
      Game::Draw();
    }

    Deinitialize();
    Game::Deinitialize();
  }

  void Game::OnEvent(Event &event)
  {
    EventDispatcher e(event);
    e.Dispatch<WindowResizeEvent>(std::bind(&Game::OnWindowResize, this, std::placeholders::_1));
  }

  bool Game::OnWindowResize(WindowResizeEvent &event)
  {

    Camera.SetBounds(-0.00125 * event.GetWidth(), 0.00125 * event.GetWidth(), -0.00125 * event.GetHeight(), 0.00125 * event.GetHeight());
    return true;
  }

} // namespace Apollo
