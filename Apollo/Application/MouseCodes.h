#ifndef MouseCodes_h
#define MouseCodes_h

namespace Apollo
{

  enum class Mouse
  {
    Left,
    Right
  };

  static std::string MouseToString(Mouse mouse)
  {
    switch (mouse)
    {
    case Mouse::Left:
      return "Left";
    case Mouse::Right:
      return "Right";
    default:
      return "";
    }
  }

  inline std::ostream &operator<<(std::ostream &os, const Mouse &mouse)
  {
    return os << MouseToString(mouse);
  }

} // namespace Apollo

#endif /* end of include guard: MouseCodes_h */