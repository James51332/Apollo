#ifndef Camera_h
#define Camera_h

#include "Math/Matrix4.h"
#include "Math/Vector3.h"

namespace Apollo
{

  class OrthographicCamera
  {
  public:
    OrthographicCamera(float left, float right, float bottom, float top);
    ~OrthographicCamera();

    void SetBounds(float left, float right, float bottom, float top);

    const Matrix4 &GetProjectionViewMatrix() const { return m_ProjectionView; }

    void SetPosition(const Vector3 &position)
    {
      m_Position = position;
      CalculateProjectionView();
    }
    const Vector3 &GetPosition() const { return m_Position; }

    void SetRotation(float rotation)
    {
      m_Rotation = rotation;
      CalculateProjectionView();
    }
    const float &GetRotation() const { return m_Rotation; }

  private:
    void CalculateProjectionView();

    Vector3 m_Position;
    float m_Rotation;

    Matrix4 m_Projection, m_View;
    Matrix4 m_ProjectionView;
  };

} // namespace Apollo

#endif /* end of include guard: Camera_h */