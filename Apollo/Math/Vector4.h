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
    inline const Scalar &operator[](int index) const { return Elements[index]; }
    inline const Scalar *GetUniformPointer() const { return &(Elements[0]); }

    ///// Math Operations //////////////////////////////////////
    inline const Vector4 Add(const Vector4 &vector) const { return Vector4(X + vector.X, Y + vector.Y, Z + vector.Z, W + vector.W); }
    inline const Vector4 operator+(const Vector4 &vector) const { return Add(vector); }

    inline const Vector4 Subtract(const Vector4 &vector) const { return Vector4(X - vector.X, Y - vector.Y, Z - vector.Z, W - vector.W); }
    inline const Vector4 operator-(const Vector4 &vector) const { return Subtract(vector); }

    inline const Scalar Multiply(const Vector4 &vector) const { return X * vector.X + Y * vector.Y + Z * vector.Z + W * vector.W; }
    inline const Scalar operator*(const Vector4 &vector) const { return Multiply(vector); }

    inline const Vector4 Scale(Scalar scalar) const { return Vector4(X * scalar, Y * scalar, Z * scalar, W * scalar); }
    inline const Vector4 operator*(Scalar scalar) const { return Scale(scalar); }

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