/**
    FMath Library

    Copyright (c) 2020 - 2021
    Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com
*/

// C++
#include <iostream>
#include <vector>


// Developer
#include "Vector3D.hxx"
#include "Matrix.hxx"

using Row = std::vector<double>;
using Column = std::vector<double>;

namespace FMath
{

#ifndef MATRIX3D_H
#define MATRIX3D_H

class Matrix3D : public FMath::Matrix
{
	public:
	
	/// Default constructor
	Matrix3D();

	/// Parameter constructor
	/// @param value : Value of all index locations in the matrix
	Matrix3D(double value);

	/// Parameter constructor
	/// @param row1 : Row 1 Vector3D object
	/// @param row2 : Row 2 Vector3D object
	/// @param row3 : Row 3 Vector3D object
	Matrix3D(const Vector3D& row1, const Vector3D& row2, const Vector3D& row3);

	/// Parameter constructor
	/// @param a : Row 1 std::vector<double>
	/// @param b : Row 2 std::vector<double>
	/// @param c : Row 3 std::vector<double>
	Matrix3D(const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c);

	/// Destructor
	~Matrix3D();

	/// Returns a Vector3D object row  at 'row' index in the matrix
	/// @param row : Row index to return vector from
	const Vector3D& GetRow(int row) const;

	/// Returns a Vector3D object column at 'col' index in the matrix
	/// @param col : Column index to return vector from
    const Vector3D& GetColumn(int col) const;
};
#endif

}