#ifndef Vector_h
#define Vector_h

namespace Apollo
{
  ////////////////////////////////////////////////////////////
  ///// Scalar ///////////////////////////////////////////////
  ////////////////////////////////////////////////////////////

  typedef float Scalar;

  ////////////////////////////////////////////////////////////
  ///// Vector2 //////////////////////////////////////////////
  ////////////////////////////////////////////////////////////

  struct Vector2
  {
    float X, Y;

    Vector2(float x)
        : X(x), Y(x) {}

    Vector2(float x, float y)
        : X(x), Y(y) {}

    ///// Overload ////////////////////////////////////////////
    void operator=(const Vector2 &vector)
    {
      this->X = vector.X;
      this->Y = vector.Y;
    }

    ///// Addition /////////////////////////////////////////////
    Vector2 Add(const Vector2 &vector) const
    {
      return Vector2(this->X + vector.X, this->Y + vector.Y);
    }

    Vector2 operator+(const Vector2 &vector) const
    {
      return this->Add(vector);
    }

    ///// Subtraction //////////////////////////////////////////
    Vector2 Subtract(const Vector2 &vector) const
    {
      return Vector2(this->X - vector.X, this->Y - vector.Y);
    }

    Vector2 operator-(const Vector2 &vector) const
    {
      return this->Subtract(vector);
    }

    ///// Multiplication ///////////////////////////////////////
    Scalar Multiply(const Vector2 &vector) const
    {
      return this->X * vector.X + this->Y * vector.Y;
    }

    Scalar operator*(const Vector2 &vector) const
    {
      return this->Multiply(vector);
    }

    ///// Scaling //////////////////////////////////////////////
    Vector2 Scale(Scalar scalar) const
    {
      return Vector2(this->X * scalar, this->Y * scalar);
    }

    void Scale(Scalar scalar)
    {
      (*this) = Vector2(this->X * scalar, this->Y * scalar);
    }

    Vector2
    operator*(Scalar scalar) const
    {
      return this->Scale(scalar);
    }
  };

  ////////////////////////////////////////////////////////////
  ///// Vector2 and Scalar ///////////////////////////////////
  ////////////////////////////////////////////////////////////

  Vector2 operator*(Scalar scalar, const Vector2 &vector)
  {
    return vector.Scale(scalar);
  }

  ////////////////////////////////////////////////////////////
  ///// Vector3 //////////////////////////////////////////////
  ////////////////////////////////////////////////////////////

  struct Vector3
  {
    float X, Y, Z;

    Vector3(float x)
        : X(x), Y(x), Z(x) {}

    Vector3(float x, float y, float z)
        : X(x), Y(y), Z(z) {}

    ///// Overload ////////////////////////////////////////////
    void operator=(const Vector3 &vector)
    {
      this->X = vector.X;
      this->Y = vector.Y;
      this->Z = vector.Z;
    }

    ///// Addition /////////////////////////////////////////////
    Vector3 Add(const Vector3 &vector) const
    {
      return Vector3(this->X + vector.X, this->Y + vector.Y, this->Z + vector.Z);
    }

    Vector3 operator+(const Vector3 &vector) const
    {
      return this->Add(vector);
    }

    ///// Subtraction //////////////////////////////////////////
    Vector3 Subtract(const Vector3 &vector) const
    {
      return Vector3(this->X - vector.X, this->Y - vector.Y, this->Z - vector.Z);
    }

    Vector3 operator-(const Vector3 &vector) const
    {
      return this->Subtract(vector);
    }

    ///// Multiplication ///////////////////////////////////////
    Scalar Multiply(const Vector3 &vector) const
    {
      return this->X * vector.X + this->Y * vector.Y + this->Z * vector.Z;
    }

    Scalar operator*(const Vector3 &vector) const
    {
      return this->Multiply(vector);
    }

    ///// Scaling //////////////////////////////////////////////
    Vector3 Scale(Scalar scalar) const
    {
      return Vector3(this->X * scalar, this->Y * scalar, this->Z * scalar);
    }

    void Scale(Scalar scalar)
    {
      (*this) = Vector3(this->X * scalar, this->Y * scalar, this->Z * scalar);
    }

    Vector3 operator*(Scalar scalar) const
    {
      return this->Scale(scalar);
    }
  };

  ////////////////////////////////////////////////////////////
  ///// Vector3 And Scalar ///////////////////////////////////
  ////////////////////////////////////////////////////////////

  Vector3 operator*(Scalar scalar, const Vector3 &vector)
  {
    return vector.Scale(scalar);
  }

  ////////////////////////////////////////////////////////////
  ///// Vector4 //////////////////////////////////////////////
  ////////////////////////////////////////////////////////////

  struct Vector4
  {
    float X, Y, Z, W;

    Vector4(float x)
        : X(x), Y(x), Z(x), W(x) {}

    Vector4(float x, float y, float z)
        : X(x), Y(y), Z(z), W(1.0) {}

    Vector4(float x, float y, float z, float w)
        : X(x), Y(y), Z(z), W(w) {}

    ///// Overload ////////////////////////////////////////////
    void operator=(const Vector4 &vector)
    {
      this->X = vector.X;
      this->Y = vector.Y;
      this->Z = vector.Z;
      this->W = vector.W;
    }

    ///// Addition /////////////////////////////////////////////
    Vector4 Add(const Vector4 &vector) const
    {
      return Vector4(this->X + vector.X, this->Y + vector.Y, this->Z + vector.Z, this->W + vector.W);
    }

    Vector4 operator+(const Vector4 &vector) const
    {
      return this->Add(vector);
    }

    ///// Subtraction //////////////////////////////////////////
    Vector4 Subtract(const Vector4 &vector) const
    {
      return Vector4(this->X - vector.X, this->Y - vector.Y, this->Z - vector.Z, this->W - vector.W);
    }

    Vector4 operator-(const Vector4 &vector) const
    {
      return this->Subtract(vector);
    }

    ///// Multiplication ///////////////////////////////////////
    Scalar Multiply(const Vector4 &vector) const
    {
      return this->X * vector.X + this->Y * vector.Y + this->Z * vector.Z + this->W * vector.W;
    }

    Scalar operator*(const Vector4 &vector) const
    {
      return this->Multiply(vector);
    }

    ///// Scaling //////////////////////////////////////////////
    Vector4 Scale(Scalar scalar) const
    {
      return Vector4(this->X * scalar, this->Y * scalar, this->Z * scalar, this->W * scalar);
    }

    void Scale(Scalar scalar)
    {
      (*this) = Vector4(this->X * scalar, this->Y * scalar, this->Z * scalar, this->W * scalar);
    }

    Vector4 operator*(Scalar scalar) const
    {
      return this->Scale(scalar);
    }
  };

  ////////////////////////////////////////////////////////////
  ///// Vector4 And Scalar ///////////////////////////////////
  ////////////////////////////////////////////////////////////

  Vector4 operator*(Scalar scalar, const Vector4 &vector)
  {
    return vector.Scale(scalar);
  }

} // namespace Apollo

#endif /* end of include guard: Vector_h */