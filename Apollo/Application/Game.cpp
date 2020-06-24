#include "Game.h"

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
    m_Window = Window::Create(WindowDescription);
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
    Initialize();
    Game::Initialize();

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

} // namespace Apollo
