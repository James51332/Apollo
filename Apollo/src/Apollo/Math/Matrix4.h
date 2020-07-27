#ifndef Matrix4_h
#define Matrix4_h

#include "Scalar.h"
#include "Vector4.h"

namespace Apollo
{

  class Matrix4
  {
  public:
    Vector4 RowX, RowY, RowZ, RowW;
    Scalar Elements[16];

    Matrix4(const Vector4 &r1, const Vector4 &r2, const Vector4 &r3, const Vector4 &r4)
        : RowX(r1), RowY(r2), RowZ(r3), RowW(r4) { SetArrayValues(); }

    Matrix4(Scalar scalar)
        : Matrix4({scalar, 0.0, 0.0, 0.0}, {0.0, scalar, 0.0, 0.0}, {0.0, 0.0, scalar, 0.0}, {0.0, 0.0, 0.0, scalar}) {}

    ///// Access Operations ////////////////////////////////////
    inline Vector4 &operator[](int index)
    {
      switch (index)
      {
      case 0:
        return RowX;
      case 1:
        return RowY;
      case 2:
        return RowZ;
      case 3:
        return RowW;
      default:
        return RowX;
      }
    }
    inline Scalar *GetUniformPointer()
    {
      SetArrayValues();
      return &(Elements[0]);
    }

    ///// Assignment Operations /////////////////////////////////
    inline void operator=(const Matrix4 &m)
    {
      RowX = m.RowX;
      RowY = m.RowY;
      RowZ = m.RowZ;
      RowW = m.RowW;
      SetArrayValues();
    }

    ///// Matrix Operations ////////////////////////////////////
    inline const Matrix4 Transpose() const
    {
      return Matrix4(Vector4(RowX.X, RowY.X, RowZ.X, RowW.X),
                     Vector4(RowX.Y, RowY.Y, RowZ.Y, RowW.Y),
                     Vector4(RowX.Z, RowY.Z, RowZ.Z, RowW.Z),
                     Vector4(RowX.W, RowY.W, RowZ.W, RowW.W));
    }

    ///// Math Operations //////////////////////////////////////
    inline Matrix4 Add(const Matrix4 &matrix) const { return Matrix4(RowX + matrix.RowX, RowY + matrix.RowY, RowZ + matrix.RowZ, RowW + matrix.RowW); }
    inline Matrix4 operator+(const Matrix4 &matrix) const { return Add(matrix); }

    inline Matrix4 Subtract(const Matrix4 &matrix) const { return Matrix4(RowX - matrix.RowX, RowY - matrix.RowY, RowZ - matrix.RowZ, RowW - matrix.RowW); }
    inline Matrix4 operator-(const Matrix4 &matrix) const { return Subtract(matrix); }

    inline Matrix4 Multiply(const Matrix4 &matrix) const
    {
      return Matrix4(Vector4(RowX * matrix.RowX, RowY * matrix.RowX, RowZ * matrix.RowX, RowW * matrix.RowX),
                     Vector4(RowX * matrix.RowY, RowY * matrix.RowY, RowZ * matrix.RowY, RowW * matrix.RowY),
                     Vector4(RowX * matrix.RowZ, RowY * matrix.RowZ, RowZ * matrix.RowZ, RowW * matrix.RowZ),
                     Vector4(RowX * matrix.RowW, RowY * matrix.RowW, RowZ * matrix.RowW, RowW * matrix.RowW));
    }
    inline Matrix4 operator*(const Matrix4 &matrix) const { return Multiply(matrix); }

    inline Matrix4 Scale(Scalar scalar) const { return Matrix4(RowX * scalar, RowY * scalar, RowZ * scalar, RowW * scalar); }
    inline Matrix4 operator*(Scalar scalar) const { return Scale(scalar); }

  private:
    void SetArrayValues()
    {
      Elements[0] = RowX.X; // Column 1
      Elements[1] = RowY.X;
      Elements[2] = RowZ.X;
      Elements[3] = RowW.X;

      Elements[4] = RowX.Y; // Column 2
      Elements[5] = RowY.Y;
      Elements[6] = RowZ.Y;
      Elements[7] = RowW.Y;

      Elements[8] = RowX.Z; // Column 3
      Elements[9] = RowY.Z;
      Elements[10] = RowZ.Z;
      Elements[11] = RowW.Z;

      Elements[12] = RowX.W; // Column 4
      Elements[13] = RowY.W;
      Elements[14] = RowZ.W;
      Elements[15] = RowW.W;
    }
  };

} // namespace Apollo

#endif /* end of include guard: Matrix4_h */