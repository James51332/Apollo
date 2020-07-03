#include "Game.h"

#include <memory>
#include <iostream>

namespace Apollo
{

  Game::Game()
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
  }

} // namespace Apollo
