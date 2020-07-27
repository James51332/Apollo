#ifndef Vector4_h
#define Vector4_h

#include "Scalar.h"

namespace Apollo
{

  class Vector4
  {
  public:
    Scalar X, Y, Z, W;
    Scalar Elements[4];

    Vector4(float x, float y, float z, float w)
        : X(x), Y(y), Z(z), W(w) { SetArrayValues(); }

    Vector4(float x)
        : Vector4(x, x, x, x) {}

    ///// Access Operations ////////////////////////////////////
    inline Scalar &operator[](int index) { return Elements[index]; }
    inline Scalar *GetUniformPointer() { return &(Elements[0]); }

    ///// Math Operations //////////////////////////////////////
    inline Vector4 Add(const Vector4 &vector) const { return Vector4(X + vector.X, Y + vector.Y, Z + vector.Z, W + vector.W); }
    inline Vector4 operator+(const Vector4 &vector) const { return Add(vector); }

    inline Vector4 Subtract(const Vector4 &vector) const { return Vector4(X - vector.X, Y - vector.Y, Z - vector.Z, W - vector.W); }
    inline Vector4 operator-(const Vector4 &vector) const { return Subtract(vector); }

    inline Scalar Multiply(const Vector4 &vector) const { return X * vector.X + Y * vector.Y + Z * vector.Z + W * vector.W; }
    inline Scalar operator*(const Vector4 &vector) const { return Multiply(vector); }
    //inline Vector4 operator*(const Vector4 &vector) const { return Vector4(X * vector.X, Y * vector.Y, Z * vector.Z, W * vector.W); }

    inline Vector4 Scale(Scalar scalar) const { return Vector4(X * scalar, Y * scalar, Z * scalar, W * scalar); }
    inline Vector4 operator*(Scalar scalar) const { return Scale(scalar); }

  private:
    inline void SetArrayValues()
    {
      Elements[0] = X;
      Elements[1] = Y;
      Elements[2] = Z;
      Elements[3] = W;
    }
  };

} // namespace Apollo

#endif /* end of include guard: Vector4_h */