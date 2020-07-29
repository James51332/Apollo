#ifndef Camera_h
#define Camera_h

#include <glm/glm.hpp>

namespace Apollo
{

  class OrthographicCamera
  {
  public:
    OrthographicCamera(float left, float right, float bottom, float top);

    const glm::vec3 &GetPosition() const { return m_Position; }
    void SetPosition(const glm::vec3 &position);

    float GetRotation() const { return m_Rotation; }
    void SetRotation(float rotation);

    const glm::mat4 &GetProjectionView() const { return m_ProjectionView; }

  private:
    void CalculateViewMatrix();

  private:
    glm::vec3 m_Position;
    float m_Rotation;

    glm::mat4 m_Projection, m_View;
    glm::mat4 m_ProjectionView;
  };

} // namespace Apollo

#endif /* end of include guard: Camera_h */
