/**
 * \file globals.hpp
 *
 * Contains all includes and functionality
 * that is global across the entire project.
 *
 * \author Tyler Petresky <hello@tylerpetresky.com>
 * \date 12-14-16
 */

/**
 * \defgroup Utilities Utilities
 *
 * Package containing all of the extraneous
 * functionalities that are necessary across most of
 * the program. This includes things like:
 *  - Singletons
 *  - Logger
 *  - Sol2 (Lua)
 *  - TermColor
 *  - Global Definitions
 */

/**
 * \defgroup SystemEngine SystemEngine
 */

/**
 * \defgroup ModeEngine
 */

/**
 * \defgroup ScriptEngine
 */

/**
 * \defgroup VideoEngine VideoEngine
 */

// C++ Standard Libraries
#include <iostream>
  using std::cout;
  using std::cerr;
  using std::endl;
#include <iomanip>
  using std::setw;
#include <fstream>
  using std::ifstream;
  using std::ofstream;
#include <vector>
  using std::vector;
#include <stack>
  using std::stack;
#include <queue>
  using std::queue;
#include <map>
  using std::map;
#include <string>
  using std::string;
  using std::to_string;
#include <cmath>
#include <ctime>

// SFML Libraries
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// Additional External Libraries
#include "termcolor.hpp"
#include "logger.hpp"
  using rpg_utils::Log;

// Environment Variables
#define DEBUG_MODE true

// Absolute path to the project folder
const string HOME_PATH = "~/Documents/dev/cpp/proj/final-fantasy-clone";
