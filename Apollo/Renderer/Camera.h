#ifndef Camera_h
#define Camera_h

#include "Math/Matrix.h"

#include <cmath>

namespace Apollo
{

  class OrthographicCamera
  {
  public:
    OrthographicCamera(float left, float right, float bottom, float top);

    const Matrix4 &GetProjectionViewMatrix() const { return m_ProjectionView; }

    const Vector3 &GetPosition() const { return m_Position; }
    const float &GetRotation() const { return m_Rotation; }

    void SetPosition(const Vector3 &position)
    {
      m_Position = position;
      CalculateProjectionView();
    }
    void SetRotation(float &rotation)
    {
      m_Rotation = rotation;
      CalculateProjectionView();
    }

  private:
    void CalculateProjectionView();

    Matrix4 m_Projection;
    Matrix4 m_View;
    Matrix4 m_ProjectionView;

    Vector3 m_Position;
    float m_Rotation;
  };

} // namespace Apollo

#endif /* end of include guard: Camera_h */