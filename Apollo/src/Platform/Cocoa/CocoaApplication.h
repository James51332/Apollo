#ifndef CocoaApplication_h
#define CocoaApplication_h

#include "Core/Application.h"

#ifdef APOLLO_OBJC_PLUS_PLUS
#include <mach/mach_time.h>
#endif

namespace Apollo
{

  class CocoaApplication : public Application
  {
  public:
    CocoaApplication();
    ~CocoaApplication();

    void Update();
    void Terminate();

    float GetTime();

  private:
    void *m_App;
#ifdef APOLLO_OBJC_PLUS_PLUS
    mach_timebase_info_data_t m_TimeInfo;
#endif
  };

} // namespace Apollo

#endif /* end of include guard: CocoaApplication_h */
