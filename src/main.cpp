#include "utils/globals.hpp"
  using namespace rpg_utils;
#include "core/system.hpp"
  using namespace rpg_system;
#include "core/video.hpp"
  using namespace rpg_video;

bool InitializeSingletons();
void DeconstructSingletons();

// Main function
int main()
{
  atexit(DeconstructSingletons);

  if (!InitializeSingletons())
  {
    if (Log)
      Log->Error("Failed to initialize singletons", LOCATION);

    DeconstructSingletons();
    exit(100);
  }
  Log->Debug("Starting engine", LOCATION);

  sf::RenderWindow *window = VideoManager->GetWindowHandle();

  while (!SystemManager->IsExiting())
  {
    sf::Event evt;
    while (window->pollEvent(evt))
    {
      if (evt.type == sf::Event::Closed)
        SystemManager->ExitGame();
    }

    VideoManager->Clear();

    VideoManager->Display();
  }

  return 0;
}

// Initializes all of the singletons used across the game
bool InitializeSingletons()
{
  // Need to create and initialize the logger before anything else
  // so we can use it in the other constructors and initializers.
  Log = Logger::CreateSingleton();
  if (!Log->InitSingleton())
  {
    cout << "Failed to initialize Logger" << endl;
    return false;
  }

  SystemManager = SystemEngine::CreateSingleton();
  VideoManager = VideoEngine::CreateSingleton();

  if (!SystemManager->InitSingleton())
  {
    Log->Error("Failed to initialize SystemEngine", LOCATION);
    return false;
  }

  if (!VideoManager->InitSingleton())
  {
    Log->Error("Failed to initialize VideoEngine", LOCATION);
    return false;
  }
  VideoManager->CreateWindow(1024, 720, "Title Here");

  Log->Debug("All singletons initialized", LOCATION);
  return true;
}

// Clean up all of the singletons. Each one manages its own resources.
void DeconstructSingletons()
{
  Log->Debug("Deconstructing singletons", LOCATION);

  VideoEngine::DestroySingleton();
  SystemEngine::DestroySingleton();
  Logger::DestroySingleton();
}
