#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Apollo
{

  OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
      : m_Projection(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)), m_Rotation(0.0f), m_Position(0.0f), m_View(1.0f), m_ProjectionView(1.0f)
  {
    CalculateViewMatrix();
  }

  void OrthographicCamera::SetPosition(const glm::vec3 &position)
  {
    m_Position = position;
    CalculateViewMatrix();
  }

  void OrthographicCamera::SetRotation(float rotation)
  {
    m_Rotation = rotation;
    CalculateViewMatrix();
  }

  void OrthographicCamera::CalculateViewMatrix()
  {
    m_View = glm::rotate(glm::mat4(1.0f), glm::radians(-m_Rotation), glm::vec3(0, 0, 1)) *
             glm::translate(glm::mat4(1.0f), -m_Position);
      
    m_ProjectionView = m_Projection * m_View;
  }

} // namespace Apollo
