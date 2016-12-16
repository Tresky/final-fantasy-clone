/**
 * \file video.hpp
 *
 * Contains a singleton class for manageing all
 * video rendering and window resources. This class
 * is global across the application and even contains
 * helper functions to render specific types of
 * objects like lines, rectangles, and grids.
 *
 * \author Tyler Petresky <hello@tylerpetresky.com>
 * \date 12-15-16
 */

#ifndef VIDEO_HPP
#define VIDEO_HPP

#include "../utils/singleton.hpp"

namespace rpg_video
{

class VideoEngine;
extern VideoEngine* VideoManager;
extern bool VIDEO_DEBUG;

class VideoEngine : public rpg_utils::Singleton<VideoEngine>
{
  friend class rpg_utils::Singleton<VideoEngine>;
public:
  /**
   * Destructor
   */
  ~VideoEngine();

  /**
   * Inherited from Singleton; initializes the
   * VideoManager singleton object.
   * \return True if successful, false otherwise
   */
  bool InitSingleton();

  /**
   * Generate an SFML window handle based on parameters.
   * \param _width  Width of the window
   * \param _height Height of the window
   * \param _title  Title to give the window
   */
  void CreateWindow(unsigned int _width, unsigned int _height, string _title);

  /**
   * Returns a pointer to the SFML window handle.
   * \return Pointer to the SFML window handle
   */
  sf::RenderWindow* GetWindowHandle() const
  {
    return window;
  }

  /**
   * Clear the SFML window with the default color black.
   */
  void Clear() const
  {
    Clear(sf::Color::Black);
  }

  /**
   * Clear the SFML window with an arbitrary color.
   * @param _color sf::Color to clear the screen with
   */
  void Clear(const sf::Color _color) const
  {
    window->clear(_color);
  }

  /**
   * Mainly only updates the FPS calculations.
   */
  void Update();

  /**
   * Draws all debug information to the screen.
   */
  void DrawDebugInfo() const;

  /**
   * Returns the current width of the screen window.
   * \return Integer of the screen width
   */
  int GetScreenWidth() const;

  /**
   * Returns the current height of the screen window.
   * \return Integer of the screen height
   */
  int GetScreenHeight() const;

  /**
   * Draws an SFML sprite to the window.
   * \param _sprite SFML sprite to draw
   */
  void DrawSprite(sf::Sprite& _sprite) const;

  /**
   * Draws an SFML shape to the window.
   * \param _shape SFML shape to draw
   */
  void DrawShape(sf::Shape& _shape) const;

  /**
   * Display all objects that have been drawn
   * onto the window handle.
   *
   * \note Nothing will appear on the screen
   * until this function is called; call it once
   * every frame after drawing.
   */
  void Display() const;

  /**
   * Closes the SFML window handle.
   */
  void Close() const;

  /**
   * Tells whether or not the application should
   * or should not draw debug information to the
   * screen. This includes collision rectangles,
   * FPS counters, etc.
   * \return True if debug is enabled, false otherwise
   */
  const bool IsDebug() const
  {
    return debug;
  }

private:
  /**
   * Default private constructor
   */
  VideoEngine();

  /**
   * Private function to calculate the FPS
   * every game cycle.
   */
  void UpdateFPS();

  /**
   * Draw the FPS to the SFML window handle.
   */
  void DrawFPS() const;

  //! SFML window handle
  sf::RenderWindow* window;

  //! Text object to display the fps in debug mode
  sf::Text fps_text;
  //! Font object to associate to the FPS text
  sf::Font font;

  //! Whether or not to draw debug info (collision boxes, etc)
  bool debug;
};

}

#endif // VIDEO_HPP
