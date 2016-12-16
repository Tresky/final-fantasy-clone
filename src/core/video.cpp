#include "../utils/globals.hpp"
#include "video.hpp"

#include "system.hpp"

namespace rpg_video
{

VideoEngine* VideoManager = nullptr;
bool VIDEO_DEBUG = true;

VideoEngine::VideoEngine()
  : window(nullptr)
  , debug(true)
{
  Log->Debug("VideoEngine constructor called", LOCATION, VIDEO_DEBUG);

  if (!font.loadFromFile("data/fonts/default.ttf"))
    Log->Error("Failed to load font for FPS counter", LOCATION);
  else
    fps_text.setFont(font);
  fps_text.setPosition(5, 5);
  fps_text.setColor(sf::Color::White);
  fps_text.setCharacterSize(24);
}

VideoEngine::~VideoEngine()
{
  Log->Debug("VideoEngine destructor called", LOCATION, VIDEO_DEBUG);

  if (window->isOpen())
    window->close();
  if (window)
    delete window;
}

bool VideoEngine::InitSingleton()
{
  Log->Debug("Initializing VideoEngine", LOCATION, VIDEO_DEBUG);
  return true;
}

void VideoEngine::CreateWindow(unsigned int _width, unsigned int _height, string _title)
{
  if (!window)
  {
    window = new sf::RenderWindow(sf::VideoMode(_width, _height), _title);
    window->setFramerateLimit(60);
    Log->Debug("SFML window created", LOCATION, VIDEO_DEBUG);
  }
  else
    Log->Debug("SFML window already exists", LOCATION, VIDEO_DEBUG);
}

void VideoEngine::Update()
{
  UpdateFPS();
}

void VideoEngine::DrawDebugInfo() const
{
  DrawFPS();
}

int VideoEngine::GetScreenWidth() const
{
  if (window)
    return window->getSize().x;

  Log->Warning("Window is not initialized", LOCATION);
  return 0;
}

int VideoEngine::GetScreenHeight() const
{
  if (window)
    return window->getSize().y;

  Log->Warning("Window is not initialized", LOCATION);
  return 0;
}

void VideoEngine::DrawSprite(sf::Sprite& _sprite) const
{
  window->draw(_sprite);
}

void VideoEngine::DrawShape(sf::Shape& _shape) const
{
  window->draw(_shape);
}

void VideoEngine::Display() const
{
  window->display();
}

void VideoEngine::Close() const
{
  window->close();
}

void VideoEngine::UpdateFPS()
{
  int current_fps = 1000 / rpg_system::SystemManager->GetUpdateTime();
  fps_text.setString("FPS: " + std::to_string(current_fps));
}

void VideoEngine::DrawFPS() const
{
  window->draw(fps_text);
}

}
