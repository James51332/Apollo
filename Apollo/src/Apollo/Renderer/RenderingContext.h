#ifndef RenderingContext_h
#define RenderingContext_h

#include "Core/Base.h"

#include "RenderingApi.h"

namespace Apollo
{

  //Each platform will subclass this to create a platformcontext
  //type which will be more suited for its window type.
  //These will in turn be subclassed to allow multiple api's per platform
  class RenderingContext
  {
  public:
    //TODO: Accept Rendering Api for creation of
    static Ref<RenderingContext> Create(RenderingApi::Api api);
    virtual ~RenderingContext();

    virtual void OnUpdate() = 0;

    RenderingApi::Api GetApi() const { return m_Api; }

  protected:
    RenderingApi::Api m_Api;

  private:
    static bool s_IsOpenGLInitialized;
  };

} // namespace Apollo

#endif /* end of include guard: RenderingContext_h */
