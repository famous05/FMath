/**
    FMath Library

    Copyright (c) 2020 - 2021
    Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com
*/

#include <iostream>
#include <vector>
#include <memory>

#include "Vector3D.hxx"
#include "Matrix.hxx"
#include "Matrix3D.hxx"

using Row = std::vector<double>;

namespace FMath
{

#ifndef MATRIXVECTOROPERATION_H
#define MATRIXVECTOROPERATION_H

class MatrixVectorOperation
{
	public:
	
	/// Default constructor
	MatrixVectorOperation();

	/// Returns the dot product of two vectors
	/// @param a : First Vector3D object
	/// @param b : Second Vector3D object
	static double Dot(const Vector3D& a, const Vector3D& b);

	/// Returns the dot product of two vectors
	/// @param a : x, y, z components of first vector as array of doubles
	/// @param b : x, y, z components of second vector as array of doubles
	static double Dot(double a[3], double b[3]);

	/// Returns the dot product of two vectors
	/// @param a : x, y, z components of first vector as vector of doubles
	/// @param b : x, y, z components of second vector as vector of doubles
	static double Dot(std::vector<double> a, std::vector<double> b);

	/// Returns the cross product of two vectors
	/// @param a : First Vector3D object
	/// @param b : Second Vector3D object
	static Vector3D& Cross(const Vector3D& a, const Vector3D& b);

	/// Returns the cross product of two vectors
	/// @param a : x, y, z components of first vector as array of doubles
	/// @param b : x, y, z components of second vector as array of doubles
	static Vector3D& Cross(double a[3], double b[3]);

	/// Returns the cross product of two vectors
	/// @param a : x, y, z components of first vector as vector of doubles
	/// @param b : x, y, z components of second vector as vector of doubles
	static Vector3D& Cross(std::vector<double> a, std::vector<double> b);

	/// Returns the scalar triple product of three vectors
	/// @param a : First Vector3D object
	/// @param b : Second Vector3D object
	/// @param c : Third Vector3D object
	static double ScalarTripleProduct(const Vector3D& a, const Vector3D& b, const Vector3D& c);

	/// Returns the scalar triple product of three vectors
	/// @param a : x, y, z components of first vector as array of doubles
	/// @param b : x, y, z components of second vector as array of doubles
	/// @param c : x, y, z components of third vector as array of doubles
	static double ScalarTripleProduct(double a[3], double b[3], double c[3]);

	/// Returns the scalar triple product of three vectors
	/// @param a : x, y, z components of first vector as vector of doubles
	/// @param b : x, y, z components of second vector as vector of doubles
	/// @param c : x, y, z components of third vector as vector of doubles
	static double ScalarTripleProduct(std::vector<double> a, std::vector<double> b, std::vector<double> c);

	/// Returns a Matrix multiple of two matrices
	/// @param A : First matrix
	/// @param B : Second matrix
	static Matrix& Multiply(Matrix& A, Matrix& B);

	/// Returns a Vector3D multiple of a Matrix3D and Vector3D
	/// @param A : Matrix3D object
	/// @param B : Vector3D object
	static Vector3D& Multiply(Matrix3D& M, Vector3D& v);

	/// Returns a Vector3D project of vector a on vector b
	/// @param a : Vector3D object to project onto another vector
	/// @param b : Vector3D object projected onto by vector a
	static Vector3D& Project(Vector3D& a, Vector3D& b);

	/// Returns a Vector3D reject of vector a on vector b
	/// @param a : Vector3D object to reject on another vector
	/// @param b : Vector3D object rejected on vector b
	static Vector3D& Reject(Vector3D& a, Vector3D& b);

    /// Returns the determinant of the Matrix3D object
	/// @param M : Matrix3D determinant to be calculated
	static double GetDeterminant(Matrix3D& M);

	/// Returns the inverse of the Matrix3D object
	/// @param M : Matrix3D inverse to be calculated
	static Matrix3D& GetInverse(Matrix3D& M); // Inverse and GetInverse should go to Matrix3D class

	/// Returns a rotation Matrix3D object about the X-axis by a given degree
	/// @param deg : Angle of rotation in degrees
	static Matrix3D& MakeRotationX(double deg);

	/// Returns a rotation Matrix3D object about the Y-axis by a given degree
	/// @param deg : Angle of rotation in degrees
	static Matrix3D& MakeRotationY(double deg);

	/// Returns a rotation Matrix3D object about the Z-axis by a given degree
	/// @param deg : Angle of rotation in degrees
	static Matrix3D& MakeRotationZ(double deg);

	/// Returns a rotation Matrix3D object about an arbitrary axis by a given degree
	/// @param deg : Angle of rotation in degrees
	/// @param v   : Vector3D object representing the axis. Must be a unit vector
	static Matrix3D& MakeRotation(double deg, Vector3D& v);

	//static void TransposeMatrix(Matrix& M);
};
#endif
}