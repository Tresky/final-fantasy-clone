#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include "globals.hpp"

namespace std
{ class exception; }

// Utilities namespace
namespace rpg_utils
{

class Exception : public std::exception
{
public:
  /**
   * Constructor
   * @param  _message C-style string message
   */
  explicit Exception(const char* _message)
    : message(_message)
  {}

  /**
   * Constructor
   * @param  _message C++ style string message
   */
  explicit Exception(const std::string& _message)
    : message(_message)
  {}

  /**
   * Destructor
   */
  virtual ~Exception() throw() {}

  /**
   * Returns the error message for this exception.
   * @return C-Style string error message
   */
  virtual const char* what() const throw()
  {
    return message.c_str();
  }

protected:
  //! Error message
  std::string message;
};

}

#endif // EXCEPTION_HPP
