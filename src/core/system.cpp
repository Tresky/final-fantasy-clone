#include "../utils/globals.hpp"
#include "system.hpp"

using namespace rpg_utils;
// using namespace rpg_mode_manager;

namespace rpg_system
{

SystemEngine *SystemManager = nullptr;
bool SYSTEM_DEBUG = true;

/*********************************
 * SystemTimer Class Definitions *
 *********************************/

SystemTimer::SystemTimer()
  : timer_state(TIMER_INVALID)
  , duration(0)
  , loops(0)
  , time_expired(0)
  , times_completed(0)
  // , mode_owner(nullptr)
{
  Log->Debug("SystemTimer default constructor called", LOCATION, SYSTEM_DEBUG);
}

SystemTimer::SystemTimer(const unsigned int _duration, const unsigned int _loops)
  : timer_state(TIMER_INITIAL)
  , duration(_duration)
  , loops(_loops)
  , time_expired(0)
  , times_completed(0)
  // , mode_owner(nullptr)
{
  Log->Debug("SystemTimer constructor called", LOCATION, SYSTEM_DEBUG);
}

SystemTimer::~SystemTimer()
{
  Log->Debug("SystemTimer destructor called", LOCATION, SYSTEM_DEBUG);
}

void SystemTimer::InitTimer(const unsigned int _duration, const unsigned int _loops)
{
  timer_state = TIMER_INITIAL;
  duration = _duration;
  loops = _loops;
  time_expired = 0;
  times_completed = 0;
  // mode_owner = nullptr;

  Log->Debug("SystemTimer initialized", LOCATION, SYSTEM_DEBUG);
}

void SystemTimer::Update()
{
  Update(SystemManager->GetUpdateTime());
}

void SystemTimer::Update(const unsigned int _time)
{
  if (!IsRunning())
    return;

  UpdateTimer(_time);
}

void SystemTimer::SetDuration(const unsigned int _duration)
{
  if (!IsInitial())
  {
    Log->Warning("Duration tried to set when timer not in initial state", LOCATION, SYSTEM_DEBUG);
    return;
  }

  duration = _duration;
}

void SystemTimer::SetTimeExpired(const unsigned int _time_expired)
{
  if (_time_expired <= duration)
    time_expired = _time_expired;
  else
    time_expired = duration;
}

void SystemTimer::SetNumberOfLoops(const unsigned int _loops)
{
  if (!IsInitial())
  {
    Log->Warning("Loops tried to set when timer not in initial state", LOCATION, SYSTEM_DEBUG);
    return;
  }

  loops = _loops;
}

// void SystemTimer::SetModeOwner(rpg_mode_manager::GameMode* _mode_owner)
// {
//   if (_mode_owner)
//     mode_owner = _mode_owner;
//   else
//     PRINT_WARNING << "Attempted to set mode owner to nullptr" << endl;
// }

void SystemTimer::UpdateTimer(const unsigned int _time)
{
  time_expired += _time;

  if(time_expired >= duration)
  {
    times_completed++;

    // Check if infinite looping is enabled
    if(loops < 0)
        time_expired -= duration;

    // Check if the last loop has been completed
    if(times_completed >= static_cast<uint32_t>(loops))
    {
      time_expired = 0;
      timer_state = TIMER_FINISHED;
    }
    // Otherwise there are still additional loops to complete
    else
      time_expired -= duration;
  }
}

/**********************************
 * SystemEngine Class Definitions *
 **********************************/
SystemEngine::SystemEngine()
  : last_update(0)
  , update_time(1)
  , hours_played(0)
  , minutes_played(0)
  , seconds_played(0)
  , milliseconds_played(0)
  , is_exiting(false)
{
  Log->Debug("SystemEngine constructor called", LOCATION, SYSTEM_DEBUG);

  InitGameTimers();
}

SystemEngine::~SystemEngine()
{
  Log->Debug("SystemEngine destructor called", LOCATION, SYSTEM_DEBUG);
}

bool SystemEngine::InitSingleton()
{
  Log->Debug("Initializing SystemEngine", LOCATION, SYSTEM_DEBUG);
  return true;
}

void SystemEngine::InitGameTimers()
{
    last_update = global_time.getElapsedTime().asMilliseconds();
    update_time = 1;
    hours_played = 0;
    minutes_played = 0;
    seconds_played = 0;
    milliseconds_played = 0;
}

// TODO - Sort our global timer for this function
void SystemEngine::UpdateTimers()
{

  // Update the update game timer
  unsigned int tmp = last_update;
  last_update = global_time.getElapsedTime().asMilliseconds();
  //cout << last_update << "   ";

  //global_timer.UpdateTimer()
  //last_update = SDL_GetTicks();
  //cout << tmp << endl;
  update_time = last_update - tmp;

  // Update the game play timer
  // milliseconds_played += update_time;
  // if(milliseconds_played >= 1000)
  // {
  //     seconds_played += milliseconds_played / 1000;
  //     milliseconds_played = milliseconds_played % 1000;
  //     if(seconds_played >= 60)
  //     {
  //         minutes_played += seconds_played / 60;
  //         seconds_played = seconds_played % 60;
  //         if(minutes_played >= 60)
  //         {
  //             hours_played += minutes_played / 60;
  //             minutes_played = minutes_played % 60;
  //         }
  //     }
  // }
  //

  // Update all SystemTimer objects
  //for(std::set<SystemTimer *>::iterator i = auto_system_timers.begin(); i != auto_system_timers.end(); ++i)
      //(*i)->AutoUpdate();
}

void SystemEngine::ExamineSystemTimers()
{
  //GameMode* active_mode = ModeManager->GetTop();

  // for(std::set<SystemTimer *>::iterator i = auto_system_timers.begin(); i != auto_system_timers.end(); ++i)
  // {
  //   GameMode* timer_mode = (*i)->GetModeOwner();
  //   if(timer_mode == nullptr)
  //     continue;
  //
  //   if(timer_mode == active_mode)
  //     (*i)->Run();
  //   else
  //     (*i)->Pause();
  // }
}

}
