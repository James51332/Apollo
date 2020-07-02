#ifndef Matrix_h
#define Matrix_h

#include "Vector.h"

namespace Apollo
{

  struct Matrix3
  {
    Vector3 LeftCol, MiddleCol, RightCol;

    Matrix3(float x)
        : LeftCol(x, 0.0f, 0.0f), MiddleCol(0.0f, x, 0.0f), RightCol(0.0f, 0.0f, x) {}

    Matrix3(const Vector3 &leftCol, const Vector3 &middleCol, const Vector3 &rightCol)
        : LeftCol(leftCol), MiddleCol(middleCol), RightCol(rightCol) {}

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

} // namespace Apollo

#endif /* end of include guard: Matrix_h */