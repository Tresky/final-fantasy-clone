#include "../../utils/globals.hpp"
#include "../../core/modes.hpp"
  using rpg_modes::MODES_DEBUG;
#include "map_mode.hpp"

namespace rpg_map_mode
{

MapMode* MapMode::current_instance = nullptr;

MapMode::MapMode(const string& _map_name)
  : GameMode()
  , map_name(_map_name)
  , active(true)
{
  Log->Debug("MapMode constructor called", LOCATION, MODES_DEBUG);

  current_instance = this;
}

MapMode::~MapMode()
{
  Log->Debug("MapMode destructor called", LOCATION, MODES_DEBUG);
}

void MapMode::Update()
{
  GameMode::Update();
}

void MapMode::Draw()
{

}

void MapMode::Reset()
{

}

void MapMode::Deactivate()
{
  if (active)
    active = false;
  else
    Log->Warning("MapMode is already deactivated", LOCATION, MODES_DEBUG);
}

}
