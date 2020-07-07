#ifndef Vector2_h
#define Vector2_h

#include "Scalar.h"

namespace Apollo
{

  class Vector2
  {
  public:
    Scalar X, Y;
    Scalar Elements[2];

    Vector2(float x, float y)
        : X(x), Y(y) { SetArrayValues(); }

    Vector2(float x)
        : Vector2(x, x) {}

    ///// Access Operations ////////////////////////////////////
    inline const Scalar &operator[](int index) const { return Elements[index]; }
    inline const Scalar *GetUniformPointer() const { return &(Elements[0]); }

    ///// Math Operations //////////////////////////////////////
    inline Vector2 Add(const Vector2 &vector) const { return Vector2(X + vector.X, Y + vector.Y); }
    inline Vector2 operator+(const Vector2 &vector) const { return Add(vector); }

    inline Vector2 Subtract(const Vector2 &vector) const { return Vector2(X - vector.X, Y - vector.Y); }
    inline Vector2 operator-(const Vector2 &vector) const { return Subtract(vector); }

    inline Scalar Multiply(const Vector2 &vector) const { return X * vector.X + Y * vector.Y; }
    inline Scalar operator*(const Vector2 &vector) const { return Multiply(vector); }

    inline Vector2 Scale(Scalar scalar) const { return Vector2(X * scalar, Y * scalar); }
    inline Vector2 operator*(Scalar scalar) const { return Scale(scalar); }

  private:
    inline void SetArrayValues()
    {
      Elements[0] = X;
      Elements[1] = Y;
    }
  };

} // namespace Apollo

#endif /* end of include guard: Vector2_h */