#ifndef Camera_h
#define Camera_h

#include "Math/Matrix.h"

namespace Apollo
{

  class OrthographicCamera
  {
  public:
    OrthographicCamera(float left, float right, float bottom, float top);

    const Matrix4 &GetProjectionViewMatrix() const { return m_ProjectionView; }

  private:
    void CalculateProjectionView();

    Matrix4 m_Projection;
    Matrix4 m_View;
    Matrix4 m_ProjectionView;

    Vector3 m_Position;
  };

} // namespace Apollo

#endif /* end of include guard: Camera_h */