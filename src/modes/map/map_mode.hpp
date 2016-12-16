/**
 * \file map_mode.hpp
 *
 * This file contains a class representing a child class
 * of the GameMode class (found in core/modes.hpp). This
 * class is used to represent the state of the game when
 * then player is exploring a local map (dungeons, towns,
 * castles, etc).
 *
 * \author Tyler Petresky <hello@tylerpetresky.com>
 * \date 12-16-16
 */

#ifndef MAP_MODE_HPP
#define MAP_MODE_HPP

namespace rpg_map_mode
{

class MapMode : public rpg_modes::GameMode
{
public:
  /**
   * Constructor
   */
  MapMode(const std::string& _map_name);

  /**
   * Destructor
   */
  ~MapMode();

  /**
   * Returns the current instance of the MapMode object.
   * \note This function is static
   *
   * \return Pointer to the current instance
   */
  static MapMode* CurrentInstance()
  {
    return current_instance;
  }

  /**
   * Updates the current MapMode instance.
   */
  void Update();

  /**
   * Draws the current MapMode instance.
   */
  void Draw();

  /**
   * Reset the current MapMode instance.
   */
  void Reset();

  /**
   * Deactivate the current MapMode instance.
   */
  void Deactivate();

private:
  /**
   * Delete the copy functions
   */
  MapMode(const MapMode& _copy) = delete;
  MapMode& operator=(MapMode& _copy) = delete;

  //! Static pointer to the current instance of the map mode
  static MapMode* current_instance;

  //! Name of the map currently being displayed
  std::string map_name;

  //! Flag telling if the current GameMode is still active
  bool active;
}; // class MapMode

} // namespace rpg_map_mode

#endif // MAP_MODE_HPP
