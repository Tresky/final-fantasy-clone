/**
 * \file modes.hpp
 *
 * Contains a class representing a GameMode to be
 * inherited by other classes. Also, a singleton class
 * for managing all of the GameMode objects is
 * defined in this file.
 *
 * \author Tyler Petresky <hello@tylerpetresky.com>
 * \date 12-15-16
 */

#ifndef MODES_HPP
#define MODES_HPP

#include "../utils/singleton.hpp"

namespace rpg_modes
{

class ModeEngine;

extern ModeEngine* ModeManager;
extern bool MODES_DEBUG;

class GameMode
{
public:
  /**
   * Default constructor
   */
  GameMode();

  /**
   * Destructor
   */
  virtual ~GameMode();

  /**
   * Update the game mode.
   */
  virtual void Update();

  /**
   * Draw anything that pertains to the current
   * game mode.
   */
  virtual void Draw() = 0;

  /**
   * Reset the current game state to be reused.
   */
  virtual void Reset() = 0;

  virtual void Deactivate() {}

private:
  /**
   * Delete the copy functions so they are not used.
   */
  GameMode(const GameMode& _copy) = delete;
  GameMode& operator=(GameMode& _copy) = delete;
};

class ModeEngine : public rpg_utils::Singleton<ModeEngine>
{
  friend class rpg_utils::Singleton<ModeEngine>;
public:
  /**
   * Destructor
   */
  ~ModeEngine();

  /**
   * Inherited from Singleton; initialize the
   * ModeEngine singleton object.
   * \return True if successful, false otherwise
   */
  bool InitSingleton();

  /**
   * Pop a single GameMode off of the stack with
   * optional transition fades between modes.
   * \param _fade_out True if want to fade out
   * \param _fade_in  True if want to fade into next mode
   */
  void Pop(bool _fade_out = false, bool _fade_in = false);

  /**
   * Pop all of the GameModes from the stack.
   */
  void PopAll();

  /**
   * Push a single GameMode onto the stack.
   * \param _game_mode Pointer to GameMode to push
   * \param _fade_out  True if want to fade out
   * \param _fade_in   True if want to fade into next mode
   */
  void Push(GameMode* _game_mode, bool _fade_out = false, bool _fade_in = false);

  /**
   * Returns pointer to the top GameMode (current)
   * \return Pointer to the current GameMode
   */
  GameMode* GetTop();

  /**
   * Update the current GameMode
   */
  void Update();

  /**
   * Render the current GameMode
   */
  void Draw();

private:
  /**
   * Default constructor
   */
  ModeEngine();

  //! Vector representing the official GameMode stack.
  //! A std::vector is used instead of a std::stack just
  //! in case a debug stack is ever needed to print.
  vector<GameMode*> mode_stack;

  //! Vector containing the GameMode objects to be pushed
  //! onto the official stack during the next call to Update().
  vector<GameMode*> push_stack;

  //! True if a state change has occurred and we need to
  //! change the active GameMode
  bool state_change;

  //! Number of game modes to pop during next call to Update()
  unsigned int pop_count;

  //! True if a fade in transition needs to happen.
  bool fade_in;
  //! True if a fade out transition needs to happen.
  bool fade_out;
  //! True if the previous fade out transition is completed.
  bool fade_out_finished;
}; // class ModeEngine

} // namespace rpg_modes

#endif // MODES_HPP
