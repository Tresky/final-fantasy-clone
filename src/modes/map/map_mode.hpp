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

  static MapMode* CurrentInstance()
  {
    return current_instance;
  }

  void Update();

  void Draw();

  void Reset();

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
