#include "utils/globals.hpp"

using namespace rpg_utils;

bool InitializeSingletons();
void DeconstructSingletons();

// Main function
int main()
{
  atexit(DeconstructSingletons);

  if (!InitializeSingletons())
  {
    DeconstructSingletons();
    exit(100);
  }
  Log->Debug("Starting engine", LOCATION);

  return 0;
}

// Initializes all of the singletons used across the game
bool InitializeSingletons()
{
  Log = Logger::CreateSingleton();

  if (!Log->InitSingleton())
  {
    cout << "Failed to Initialize Logger" << endl;
    return false;
  }


  Log->Debug("All singletons initialized", LOCATION);
  return true;
}

// Clean up all of the singletons. Each one manages its own resources.
void DeconstructSingletons()
{
  Log->Debug("Deconstructing singletons", LOCATION);
}
