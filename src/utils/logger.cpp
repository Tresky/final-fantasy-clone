#include "logger.hpp"

namespace rpg_utils
{

Logger *Log = nullptr;

void Logger::Debug(string _message, char const* _context, bool _show)
{
  if (_show)
  {
    if (print_console)
      cout << termcolor::green << "DEBUG: " << _context << termcolor::reset << " -- " << _message << endl;
    if (print_file)
      log_file << "DEBUG: " << _context << " -- " << _message << endl;
  }
}

void Logger::Warning(string _message, char const* _context, bool _show)
{
  if (_show)
  {
    if (print_console)
      cout << termcolor::yellow << "WARNING: " << _context << termcolor::reset << " -- " << _message << endl;
    if (print_file)
      log_file << "WARNING: " << _context << " -- " << _message << endl;
  }
}

void Logger::Error(string _message, char const* _context, bool _show)
{
  if (print_console)
    cout << termcolor::red << "ERROR: " << _context << termcolor::reset << " -- " << _message << endl;
  if (print_file)
    log_file << "ERROR: " << _context << " -- " << _message << endl;
}

}
