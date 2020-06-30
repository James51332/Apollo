#ifndef Buffer_h
#define Buffer_h

#include <cstdint>
#include <initializer_list>
#include <vector>
#include <string>

namespace Apollo
{
  ////////////////////////////////////////////////////////////
  ///// ShaderDataType ///////////////////////////////////////
  ////////////////////////////////////////////////////////////

  enum class ShaderDataType
  {
    None = 0,
    Float,
    Float2,
    Float3,
    Float4,
    Mat3,
    Mat4,
    Int,
    Int2,
    Int3,
    Int4
  };

  static uint32_t
  ShaderDataTypeSize(ShaderDataType type)
  {
    switch (type)
    {
    case ShaderDataType::None:
      return 0;
      break;
    case ShaderDataType::Float:
      return 4;
      break;
    case ShaderDataType::Float2:
      return 4 * 2;
      break;
    case ShaderDataType::Float3:
      return 4 * 3;
      break;
    case ShaderDataType::Float4:
      return 4 * 4;
      break;
    case ShaderDataType::Mat3:
      return 4 * 3 * 3;
      break;
    case ShaderDataType::Mat4:
      return 4 * 4 * 4;
      break;
    case ShaderDataType::Int:
      return 4;
      break;
    case ShaderDataType::Int2:
      return 4 * 2;
      break;
    case ShaderDataType::Int3:
      return 4 * 3;
      break;
    case ShaderDataType::Int4:
      return 4 * 4;
      break;
    }
  }

  ////////////////////////////////////////////////////////////
  ///// BufferLayout /////////////////////////////////////////
  ////////////////////////////////////////////////////////////

  struct BufferElement
  {
    ShaderDataType Type;
    std::string Name;
    uint32_t Offset;
    uint32_t Size;
    bool Normalized;

    BufferElement(ShaderDataType type, const std::string &name, bool normalized = false)
        : Type(type), Name(name), Offset(0), Size(ShaderDataTypeSize(type)), Normalized(normalized) {}

    uint32_t GetElementCount() const
    {
      switch (Type)
      {
      case ShaderDataType::None:
        return 0;
      case ShaderDataType::Float:
        return 1;
      case ShaderDataType::Float2:
        return 2;
      case ShaderDataType::Float3:
        return 3;
      case ShaderDataType::Float4:
        return 4;
      case ShaderDataType::Mat3:
        return 3 * 3;
      case ShaderDataType::Mat4:
        return 4 * 4;
      case ShaderDataType::Int:
        return 1;
      case ShaderDataType::Int2:
        return 2;
      case ShaderDataType::Int3:
        return 3;
      case ShaderDataType::Int4:
        return 4;
      }
    }
  };

  class BufferLayout
  {
  public:
    BufferLayout(std::initializer_list<BufferElement> elements)
        : m_Elements(elements) {}
    BufferLayout() {}

    inline uint32_t GetStride() const { return m_Stride; }
    inline const std::vector<BufferElement> &GetElements() const { return m_Elements; }

  private:
    void CalculateOffsetsAndStride()
    {
      m_Stride = 0;
      for (auto &element : m_Elements)
      {
        element.Offset = m_Stride;
        m_Stride += element.Size;
      }
    }

    std::vector<BufferElement> m_Elements;
    uint32_t m_Stride;
  };

  ////////////////////////////////////////////////////////////
  ///// VertexBuffer /////////////////////////////////////////
  ////////////////////////////////////////////////////////////

  class VertexBuffer
  {
  public:
    static VertexBuffer *Create(float *vertices, uint32_t size);
    virtual ~VertexBuffer();

    virtual void Bind() = 0;
    virtual void Unbind() = 0;

    void SetLayout(const BufferLayout &layout) { m_Layout = layout; }
    const BufferLayout &GetLayout() const { return m_Layout; }

  protected:
    BufferLayout m_Layout;
  };

  ////////////////////////////////////////////////////////////
  ///// IndexBuffer //////////////////////////////////////////
  ////////////////////////////////////////////////////////////

  class IndexBuffer
  {
  public:
    static IndexBuffer *Create(uint32_t *indices, uint32_t count);
    virtual ~IndexBuffer();

    virtual void Bind() = 0;
    virtual void Unbind() = 0;

    const uint32_t GetCount() const { return m_Count; }

  protected:
    uint32_t m_Count;
  };

} // namespace Apollo

#endif /* end of include guard: Buffer_h */