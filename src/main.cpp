#include "utils/globals.hpp"

#include "core/system.hpp"

using namespace rpg_system;

bool InitializeSingletons();
void DeconstructSingletons();

int main()
{
  PRINT_DEBUG << "Starting engine" << endl;
  atexit(DeconstructSingletons);

  if (!InitializeSingletons())
  {
    PRINT_ERROR << "Failed to initialize singletons" << endl;
    DeconstructSingletons();
    exit(100);
  }

  PRINT_DEBUG << "Starting loop" << endl;
  while (!SystemManager->IsExiting())
  {
    // Capture Events and input

    // Video clear
    // Mode Draw
    // Video draw fade effects

    // updates
  }

  //close

  return 0;
}

bool InitializeSingletons()
{
  SystemManager = SystemEngine::CreateSingleton();

  if (!SystemManager->InitSingleton())
  {
    PRINT_ERROR << "Failed to initialize SystemEngine singleton" << endl;
    return false;
  }

  return true;
}

void DeconstructSingletons()
{
  SystemEngine::DestroySingleton();
}
