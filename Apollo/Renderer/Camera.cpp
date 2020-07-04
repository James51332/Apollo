#include "Camera.h"

#include <cmath>

namespace Apollo
{

  OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
      : m_View(1.0), m_Position(0.0f), m_Projection(0.0f), m_ProjectionView(0.0f)
  {
    m_Projection = Matrix4(Vector4(2 / (right - left), 0, 0, 0),
                           Vector4(0, 2 / (top - bottom), 0, 0),
                           Vector4(0, 0, -1, 0),
                           Vector4(-((right + left) / (right - left)), -((top + bottom) / (top - bottom)), 0, 1));

    CalculateProjectionView();
  }

  void OrthographicCamera::CalculateProjectionView()
  {
    Matrix4 translation = Matrix4(Vector4(1, 0, 0, 0),
                                  Vector4(0, 1, 0, 0),
                                  Vector4(0, 0, 1, 0),
                                  Vector4(m_Position.X, m_Position.Y, m_Position.Z, 1));

    Matrix4 rotation = Matrix4(Vector4(cos(m_Rotation / 180 * M_PI), -sin(m_Rotation / 180 * M_PI), 0, 0),
                               Vector4(sin(m_Rotation / 180 * M_PI), cos(m_Rotation / 180 * M_PI), 0, 0),
                               Vector4(0, 0, 1, 0),
                               Vector4(0, 0, 0, 1));

    Matrix4 transform = translation * rotation;

    m_View = transform.Inverse();

    m_ProjectionView = m_Projection * transform;
  }

} // namespace Apollo
