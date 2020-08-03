#ifndef Application_h
#define Application_h

namespace Apollo
{

  class Application
  {
  public:
    static Application *Create();
    virtual ~Application();

    virtual void Update() = 0;
    virtual void Terminate() = 0;
  };

} // namespace Apollo

#endif /* end of include guard: Application_h */
