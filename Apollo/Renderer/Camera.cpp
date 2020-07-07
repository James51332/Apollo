#include "Camera.h"

#include <cmath>

namespace Apollo
{

  OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
      : m_Projection(1.0), m_View(1.0), m_ProjectionView(1.0), m_Position(0.0)
  {
    m_Projection = Matrix4(Vector4(2 / (right - left), 0, 0, -((right + left) / (right - left))),
                           Vector4(0, 2 / (top - bottom), 0, -((top + bottom) / (top - bottom))),
                           Vector4(0, 0, 1, 0),
                           Vector4(0, 0, 0, 1));

    CalculateProjectionView();
  }

  OrthographicCamera::~OrthographicCamera()
  {
  }

  void OrthographicCamera::CalculateProjectionView()
  {
    Matrix4 translation = Matrix4(Vector4(1, 0, 0, -m_Position.X),
                                  Vector4(0, 1, 0, -m_Position.Y),
                                  Vector4(0, 0, 1, -m_Position.Z),
                                  Vector4(0, 0, 0, 1));

    Matrix4 rotation = Matrix4(Vector4(cos(m_Rotation / 180 * M_PI), sin(m_Rotation / 180 * M_PI), 0, 0),
                               Vector4(-sin(m_Rotation / 180 * M_PI), cos(m_Rotation / 180 * M_PI), 0, 0),
                               Vector4(0, 0, 1, 0),
                               Vector4(0, 0, 0, 1));

    // Apparently My Math Library is Reversed somehow so you multiply projection last
    m_View = rotation * translation;
    m_ProjectionView = m_View * m_Projection;
  }

} // namespace Apollo