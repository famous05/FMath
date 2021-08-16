/*------------------------------------------------------------------------------
FMath Library

Copyright (c) 2020 - 2021

Author : Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com

Class
    FMath::Matrix

Description
    A Matrix class
------------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <memory>

using Row = std::vector<double>;
using Column = std::vector<double>;

namespace FMath
{

#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
	public:
	
	Matrix();

	Matrix(std::size_t nRows, std::size_t nColumns);

	Matrix(std::size_t nRows, std::size_t nColumns, double value);

	Matrix(const Matrix& matrix);

    Matrix(Matrix&& matrix);

    Matrix& operator =(const Matrix& matrix);

    Matrix& operator =(Matrix&& matrix);

	virtual ~Matrix();

    Matrix& operator +(const Matrix& matrix);

    Matrix& operator -(const Matrix& matrix);

    Matrix& operator *(double val);

    Matrix& operator /(double val);

    Matrix& operator +=(const Matrix& matrix);
    
    Matrix& operator -=(const Matrix& matrix);   
    
    Matrix& operator *=(double val);
   
    Matrix& operator /=(double val);

    virtual Row& operator [](std::size_t i);

    Row& GetRow(std::size_t row);

    Column& GetColumn(std::size_t column);

	std::size_t GetRowCount() const;

	std::size_t GetColumnCount() const;

	std::vector<std::size_t> GetShape();

	void Transpose();

    void Print();

    void Print(int columnWidth);

protected:
    std::vector<Row> *m_MatrixRows = new std::vector<Row>;	
};
#endif

}
