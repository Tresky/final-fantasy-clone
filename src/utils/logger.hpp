#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
  using std::cout;
  using std::endl;
#include <string>
  using std::string;
#include <fstream>
  using std::ofstream;

#define S1(x) #x
#define S2(x) S1(x)
#define LOCATION __FILE__ " @ " S2(__LINE__)

#define FORCE_LOG true

#include "env.hpp"
#include "termcolor.hpp"
#include "singleton.hpp"

namespace rpg_utils
{

class Logger;
extern Logger* Log;

class Logger : public rpg_utils::Singleton<Logger>
{
  friend class rpg_utils::Singleton<Logger>;
public:
  /**
   * Destructor
   */
  ~Logger() {}

  /**
   * Initialize the Singleton.
   * @return True if successful, false otherwise
   */
  bool InitSingleton()
  {
    ShouldPrintFile(true || FORCE_LOG);
    ShouldPrintConsole(true || FORCE_LOG);

    return true;
  }

  /**
   * Set whether the logger should print to the console.
   * @param _flag True if logs should be printed to console, false otherwise
   */
  void ShouldPrintConsole(bool _flag)
  {
    print_console = true || FORCE_LOG;
  }

  /**
   * Set whether the logger should print to the log file.
   * @param _flag True if logs should be printed to a log file, false otherwise
   */
  void ShouldPrintFile(bool _flag)
  {
    print_file = true || FORCE_LOG;

    time_t t; time(&t);

    // Open file if need be, or close one
    if (print_file)
    {
      log_file.open("logs/log.txt", ofstream::out | ofstream::app);
      log_file << "-----------------------------------" << endl;
      log_file << "-----      Captain's Log      -----" << endl;
      log_file << "-----------------------------------" << endl;
      log_file << "Stardate: " << ctime(&t);
    }
    else if (log_file.is_open())
      log_file.close();
  }

  /**
   * Print a debug message to the appropriate channels.
   * @param _message Message to print to debug
   * @param _show    Pass a conditional that will conditionally print
   */
  void Debug(string _message, const char* _metadata, bool _show = true);

  /**
   * Print a warning message to the appropriate channels.
   * @param _message Message to print to warning
   * @param _show    Pass a conditional that will conditionally print
   */
  void Warning(string _message, char const* _context, bool _show = true);

  /**
   * Print an error message to the appropriate channels.
   * @param _message Message to print to warning
   * @param _show    Pass a conditional that will conditionally print
   */
  void Error(string _message, char const* _context, bool _show = true);

private:
  /**
   * Constructor
   */
  Logger() {}

  //! Whether or not logs should be printed to a log file
  bool print_file;
  //! Whether or not logs should be printed to the console window
  bool print_console;

  //! If logs go to a file, this stores the file stream
  ofstream log_file;
};

} // namespace rpg_utils

#endif // LOGGER_HPP
