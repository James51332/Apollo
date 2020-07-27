#ifndef Vector3_h
#define Vector3_h

#include "Scalar.h"

namespace Apollo
{

  class Vector3
  {
  public:
    Scalar X, Y, Z;
    Scalar Elements[3];

    Vector3(float x, float y, float z)
        : X(x), Y(y), Z(z) { SetArrayValues(); }

    Vector3(float x)
        : Vector3(x, x, x) {}

    ///// Access Operations ////////////////////////////////////
    inline Scalar &operator[](int index) { return Elements[index]; }
    inline const Scalar *GetUniformPointer() const { return &(Elements[0]); }

    ///// Math Operations //////////////////////////////////////
    inline Vector3 Add(const Vector3 &vector) const { return Vector3(X + vector.X, Y + vector.Y, Z + vector.Z); }
    inline Vector3 operator+(const Vector3 &vector) const { return Add(vector); }

    inline Vector3 Subtract(const Vector3 &vector) const { return Vector3(X - vector.X, Y - vector.Y, Z - vector.Z); }
    inline Vector3 operator-(const Vector3 &vector) const { return Subtract(vector); }

    inline Scalar Multiply(const Vector3 &vector) const { return X * vector.X + Y * vector.Y + Z * vector.Z; }
    inline Scalar operator*(const Vector3 &vector) const { return Multiply(vector); }

    inline Vector3 Scale(Scalar scalar) const { return Vector3(X * scalar, Y * scalar, Z * scalar); }
    inline Vector3 operator*(Scalar scalar) const { return Scale(scalar); }

  private:
    inline void SetArrayValues()
    {
      Elements[0] = X;
      Elements[1] = Y;
      Elements[2] = Z;
    }
  };

} // namespace Apollo

#endif /* end of include guard: Vector3_h */