#include "Camera.h"

namespace Apollo
{

  OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
      : m_View(1.0), m_Position(0.0f), m_Projection(0.0f), m_ProjectionView(0.0f)
  {
    float near = -1.0f;
    float far = 1.0f;

    m_Projection = Matrix4(Vector4(2 / (right - left), 0, 0, 0),
                           Vector4(0, 2 / (top - bottom), 0, 0),
                           Vector4(0, 0, -1, 0),
                           Vector4(-((right + left) / (right - left)), -((top + bottom) / (top - bottom)), -((far + near) / (far - near)), 1));

    m_ProjectionView = m_Projection * m_View;
  }

  void OrthographicCamera::CalculateProjectionView()
  {
    m_ProjectionView = m_Projection * m_View;
  }

} // namespace Apollo
