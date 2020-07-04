#ifndef Matrix_h
#define Matrix_h

#include "Vector.h"

namespace Apollo
{

  ////////////////////////////////////////////////////////////
  ///// Matrix3 //////////////////////////////////////////////
  ////////////////////////////////////////////////////////////

  struct Matrix3
  {
    Vector3 LeftCol, MiddleCol, RightCol;

    Matrix3(float x)
        : LeftCol(x, 0.0f, 0.0f), MiddleCol(0.0f, x, 0.0f), RightCol(0.0f, 0.0f, x) {}

    Matrix3(const Vector3 &leftCol, const Vector3 &middleCol, const Vector3 &rightCol)
        : LeftCol(leftCol), MiddleCol(middleCol), RightCol(rightCol) {}

    ///// Comparison ///////////////////////////////////////////
    bool Equals(const Matrix3 &matrix) const
    {
      return matrix.LeftCol == LeftCol && matrix.MiddleCol == MiddleCol && matrix.RightCol == RightCol;
    }

    bool operator==(const Matrix3 &matrix) const
    {
      return Equals(matrix);
    }

    bool operator!=(const Matrix3 &matrix) const
    {
      return !Equals(matrix);
    }

    ///// Transposition ////////////////////////////////////////
    Matrix3 Transpose() const
    {
      return Matrix3(Vector3(LeftCol.X, MiddleCol.X, RightCol.X),  // First Column
                     Vector3(LeftCol.Y, MiddleCol.Y, RightCol.Y),  // Second Column
                     Vector3(LeftCol.Z, MiddleCol.Z, RightCol.Z)); // Third Column
    }

    void Transpose()
    {
      (*this) = Matrix3(Vector3(LeftCol.X, MiddleCol.X, RightCol.Z),  // First Column
                        Vector3(LeftCol.Y, MiddleCol.Y, RightCol.Z),  // Second Column
                        Vector3(LeftCol.Z, MiddleCol.Z, RightCol.Z)); // Third Column
    }

    ///// Determinant //////////////////////////////////////////
    Scalar Determinant() const
    {
      return (LeftCol.X * ((MiddleCol.Y * RightCol.Z) - (RightCol.Y * MiddleCol.Z))) - (MiddleCol.X * ((LeftCol.Y * RightCol.Z) - (RightCol.Y * LeftCol.Z))) + (RightCol.X * ((LeftCol.Y * MiddleCol.Z) - (MiddleCol.Y * LeftCol.Z)));
    }

    ///// Addition /////////////////////////////////////////////
    Matrix3 Add(const Matrix3 &matrix) const
    {
      return Matrix3(this->LeftCol + matrix.LeftCol, this->MiddleCol + matrix.MiddleCol, this->RightCol + matrix.RightCol);
    }

    Matrix3 operator+(const Matrix3 &matrix) const
    {
      return this->Add(matrix);
    }

    ///// Subtraction //////////////////////////////////////////
    Matrix3 Subract(const Matrix3 &matrix) const
    {
      return Matrix3(this->LeftCol - matrix.LeftCol, this->MiddleCol - matrix.MiddleCol, this->RightCol - matrix.RightCol);
    }

    Matrix3 operator-(const Matrix3 &matrix) const
    {
      return this->Subract(matrix);
    }

    ///// Scaling //////////////////////////////////////////////
    Matrix3 Scale(Scalar scalar) const
    {
      return Matrix3(LeftCol.Scale(scalar),
                     MiddleCol.Scale(scalar),
                     RightCol.Scale(scalar));
    }

    Matrix3 operator*(Scalar scalar) const
    {
      return Matrix3(LeftCol.Scale(scalar),
                     MiddleCol.Scale(scalar),
                     RightCol.Scale(scalar));
    }

    ///// Multiplication ///////////////////////////////////////
    Matrix3 Multiply(const Matrix3 &matrix) const
    {
      Matrix3 horizontal = this->Transpose();

      return Matrix3(Vector3(horizontal.LeftCol * matrix.LeftCol, horizontal.MiddleCol * matrix.LeftCol, horizontal.RightCol * matrix.LeftCol),       // First Column
                     Vector3(horizontal.LeftCol * matrix.MiddleCol, horizontal.MiddleCol * matrix.MiddleCol, horizontal.RightCol * matrix.MiddleCol), // Second Column
                     Vector3(horizontal.LeftCol * matrix.RightCol, horizontal.MiddleCol * matrix.RightCol, horizontal.RightCol * matrix.RightCol));   // Third Column
    }

    Matrix3 operator*(const Matrix3 &matrix) const
    {
      Matrix3 horizontal = this->Transpose();

      return Matrix3(Vector3(horizontal.LeftCol * matrix.LeftCol, horizontal.MiddleCol * matrix.LeftCol, horizontal.RightCol * matrix.LeftCol),       // First Column
                     Vector3(horizontal.LeftCol * matrix.MiddleCol, horizontal.MiddleCol * matrix.MiddleCol, horizontal.RightCol * matrix.MiddleCol), // Second Column
                     Vector3(horizontal.LeftCol * matrix.RightCol, horizontal.MiddleCol * matrix.RightCol, horizontal.RightCol * matrix.RightCol));   // Third Column
    }
  };

  ////////////////////////////////////////////////////////////
  ///// Matrix4 //////////////////////////////////////////////
  ////////////////////////////////////////////////////////////

  struct Matrix4
  {
    Vector4 LCol, LMCol, RMCol, RCol;
    float glArray[16];

    Matrix4(float x)
        : LCol(x, 0.0, 0.0, 0.0), LMCol(0.0, x, 0.0, 0.0), RMCol(0.0, 0.0, x, 0.0), RCol(0.0, 0.0, 0.0, x) {}

    Matrix4(const Vector4 &l, const Vector4 &lm, const Vector4 &rm, const Vector4 &r)
        : LCol(l), LMCol(lm), RMCol(rm), RCol(r) {}

    ///// Comparison ///////////////////////////////////////////
    float *GetUniformArray()
    {
      glArray[0] = LCol.X;
      glArray[1] = LCol.Y;
      glArray[2] = LCol.Z;
      glArray[3] = LCol.W;
      glArray[4] = LMCol.X;
      glArray[5] = LMCol.Y;
      glArray[6] = LMCol.Z;
      glArray[7] = LMCol.W;
      glArray[8] = RMCol.X;
      glArray[9] = RMCol.Y;
      glArray[10] = RMCol.Z;
      glArray[11] = RMCol.W;
      glArray[12] = RCol.X;
      glArray[13] = RCol.Y;
      glArray[14] = RCol.Z;
      glArray[15] = RCol.W;

      return (float *)glArray;
    }

    ///// Comparison ///////////////////////////////////////////
    bool Equals(const Matrix4 &matrix) const
    {
      return matrix.LCol == LCol && matrix.LMCol == LMCol && matrix.RMCol == RMCol && matrix.RCol == RCol;
    }

    bool operator==(const Matrix4 &matrix) const
    {
      return Equals(matrix);
    }

    bool operator!=(const Matrix4 &matrix) const
    {
      return !Equals(matrix);
    }

    ///// Determinant //////////////////////////////////////////
    Scalar Determinant() const
    {
      Scalar l, lm, rm, r;

      l = (Matrix3(Vector3(LMCol.Y, LMCol.Z, LMCol.W), Vector3(RMCol.Y, RMCol.Z, RMCol.W), Vector3(RCol.Y, RCol.Z, RCol.W))).Determinant();
      lm = (Matrix3(Vector3(LCol.Y, LCol.Z, LCol.W), Vector3(RMCol.Y, RMCol.Z, RMCol.W), Vector3(RCol.Y, RCol.Z, RCol.W))).Determinant();
      rm = (Matrix3(Vector3(LCol.Y, LMCol.Z, LMCol.W), Vector3(LMCol.Y, LMCol.Z, LMCol.W), Vector3(RCol.Y, RCol.Z, RCol.W))).Determinant();
      r = (Matrix3(Vector3(LCol.Y, LMCol.Z, LMCol.W), Vector3(LMCol.Y, LMCol.Z, LMCol.W), Vector3(RMCol.Y, RMCol.Z, RMCol.W))).Determinant();

      return l - lm + rm - r;
    }

    ///// Inverse //////////////////////////////////////////
    Matrix4 Inverse() const
    {
      return Transpose() * (1 / Determinant());
    }

    ///// Transposition ////////////////////////////////////////
    Matrix4 Transpose() const
    {
      return Matrix4(Vector4(LCol.X, LMCol.X, RMCol.X, RCol.X),  // First Column
                     Vector4(LCol.Y, LMCol.Y, RMCol.Y, RCol.Y),  // Second Column
                     Vector4(LCol.Z, LMCol.Z, RMCol.Z, RCol.Z),  // Third Column
                     Vector4(LCol.W, LMCol.W, RMCol.W, RCol.W)); // Fourth Column
    }

    void Transpose()
    {
      (*this) = Matrix4(Vector4(LCol.X, LMCol.X, RMCol.X, RCol.X),  // First Column
                        Vector4(LCol.Y, LMCol.Y, RMCol.Y, RCol.Y),  // Second Column
                        Vector4(LCol.Z, LMCol.Z, RMCol.Z, RCol.Z),  // Third Column
                        Vector4(LCol.W, LMCol.W, RMCol.W, RCol.W)); // Fourth Column
    }

    ///// Addition /////////////////////////////////////////////
    Matrix4 Add(const Matrix4 &matrix) const
    {
      return Matrix4(this->LCol + matrix.LCol, this->LMCol + matrix.LMCol, this->RMCol + matrix.RMCol, this->RCol + matrix.RCol);
    }

    Matrix4 operator+(const Matrix4 &matrix) const
    {
      return this->Add(matrix);
    }

    ///// Subtraction //////////////////////////////////////////
    Matrix4 Subract(const Matrix4 &matrix) const
    {
      return Matrix4(this->LCol - matrix.LCol, this->LMCol - matrix.LMCol, this->RMCol - matrix.RMCol, this->RCol - matrix.RCol);
    }

    Matrix4 operator-(const Matrix4 &matrix) const
    {
      return this->Subract(matrix);
    }

    ///// Scaling //////////////////////////////////////////////
    Matrix4 Scale(Scalar scalar) const
    {
      return Matrix4(LCol.Scale(scalar),
                     LMCol.Scale(scalar),
                     RMCol.Scale(scalar),
                     RCol.Scale(scalar));
    }

    Matrix4 operator*(Scalar scalar) const
    {
      return Matrix4(LCol.Scale(scalar),
                     LMCol.Scale(scalar),
                     RMCol.Scale(scalar),
                     RCol.Scale(scalar));
    }

    ///// Multiplication ///////////////////////////////////////
    Matrix4 Multiply(const Matrix4 &matrix) const
    {
      Matrix4 horizontal = this->Transpose();

      return Matrix4(Vector4(horizontal.LCol * matrix.LCol, horizontal.LMCol * matrix.LCol, horizontal.RMCol * matrix.LCol, horizontal.RCol * matrix.LCol),     // First Column
                     Vector4(horizontal.LCol * matrix.LMCol, horizontal.LMCol * matrix.LMCol, horizontal.RMCol * matrix.LMCol, horizontal.RCol * matrix.LMCol), // Second Column
                     Vector4(horizontal.LCol * matrix.RMCol, horizontal.LMCol * matrix.RMCol, horizontal.RMCol * matrix.RMCol, horizontal.RCol * matrix.RMCol), // Third Column
                     Vector4(horizontal.LCol * matrix.RCol, horizontal.LMCol * matrix.RCol, horizontal.RMCol * matrix.RCol, horizontal.RCol * matrix.RCol));    // Fourth Column
    }

    Matrix4 operator*(const Matrix4 &matrix) const
    {
      Matrix4 horizontal = this->Transpose();

      return Matrix4(Vector4(horizontal.LCol * matrix.LCol, horizontal.LMCol * matrix.LCol, horizontal.RMCol * matrix.LCol, horizontal.RCol * matrix.LCol),     // First Column
                     Vector4(horizontal.LCol * matrix.LMCol, horizontal.LMCol * matrix.LMCol, horizontal.RMCol * matrix.LMCol, horizontal.RCol * matrix.LMCol), // Second Column
                     Vector4(horizontal.LCol * matrix.RMCol, horizontal.LMCol * matrix.RMCol, horizontal.RMCol * matrix.RMCol, horizontal.RCol * matrix.RMCol), // Third Column
                     Vector4(horizontal.LCol * matrix.RCol, horizontal.LMCol * matrix.RCol, horizontal.RMCol * matrix.RCol, horizontal.RCol * matrix.RCol));    // Fourth Column
    }
  };

} // namespace Apollo

#endif /* end of include guard: Matrix_h */