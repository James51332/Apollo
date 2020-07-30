#ifndef CocoaApplication_h
#define CocoaApplication_h

#include "Core/Application.h"

namespace Apollo
{

  class CocoaApplication : public Application
  {
  public:
    CocoaApplication();
    ~CocoaApplication();

    void Update();
    void Terminate();

  private:
    void *m_App;
  };

} // namespace Apollo

#endif /* end of include guard: CocoaApplication_h */