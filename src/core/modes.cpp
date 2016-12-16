#include "../utils/globals.hpp"
#include "modes.hpp"

namespace rpg_modes
{

ModeEngine* ModeManager = nullptr;
bool MODES_DEBUG = true;

GameMode::GameMode()
{
  Log->Debug("GameMode constructor called", LOCATION, MODES_DEBUG);
}

GameMode::~GameMode()
{
  Log->Debug("GameMode destructor called", LOCATION, MODES_DEBUG);
}

void GameMode::Update()
{}

ModeEngine::ModeEngine()
  : state_change(false)
  , pop_count(0)
  , fade_in(false)
  , fade_out(false)
  , fade_out_finished(false)
{
  Log->Debug("ModeEngine constructor called", LOCATION, MODES_DEBUG);
}

ModeEngine::~ModeEngine()
{
  Log->Debug("ModeEngine destructor called", LOCATION, MODES_DEBUG);

  // Delete the active game modes
  while (!mode_stack.empty())
  {
    delete mode_stack.back();
    mode_stack.pop_back();
  }

  // Delete the game modes about to be pushed
  while (!push_stack.empty())
  {
    delete push_stack.back();
    push_stack.pop_back();
  }
}

bool ModeEngine::InitSingleton()
{
  Log->Debug("Initializing VideoEngine", LOCATION, MODES_DEBUG);
  return true;
}

void ModeEngine::Pop(bool _fade_out, bool _fade_in)
{
  fade_in = _fade_in;

  ++pop_count;
  state_change = true;

  if (_fade_out)
  {
    // implement later
  }
  else
  {
    // implement later
  }
}

void ModeEngine::PopAll()
{
  pop_count = static_cast<unsigned int>(mode_stack.size());
}

void ModeEngine::Push(GameMode *_game_mode, bool _fade_out, bool _fade_in)
{
  push_stack.push_back(_game_mode);

  state_change = true;

  fade_in = fade_out;

  if (fade_out)
  {
    // implement later
  }
  else
  {

  }
}

GameMode* ModeEngine::GetTop()
{
  if (mode_stack.empty())
    return nullptr;
  return mode_stack.back();
}

void ModeEngine::Update()
{
  // TODO: Implement ModeEngine#Update
}

void ModeEngine::Draw()
{
  if (!mode_stack.empty())
    mode_stack.back()->Draw();
}

}
