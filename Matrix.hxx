/**
    FMath Library

    Copyright (c) 2020 - 2021
    Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com
*/

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
	
    /// Default constructor
	Matrix();

    /// Parameter constructor
    /// @param nRows : Number of rows
    /// @param nColumns: Number of columns
	Matrix(const std::size_t nRows, const std::size_t nColumns);

    /// Parameter constructor
    /// @param nRows : Number of rows
    /// @param nColumns: Number of columns
    /// @param value : Initial values in matrix
	Matrix(const std::size_t nRows, const std::size_t nColumns, const double value);

    /// Copy constructor
    /// @param matrix : Matrix to be copied into new Matrix object
	Matrix(const Matrix& matrix);

    /// Move constructor
    /// @param matrix : Matrix to be copied into new Matrix object
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

    /// Returns the row at row index 'row'
    /// @param row : Index of row to return
    Row& operator [](const std::size_t row);

    /// Returns the row at row index 'row'
    /// @param row : Index of row to return
    const Row& GetRow(const std::size_t row) const;

    /// Returns the column at column index 'column'
    /// @param column : Index of column to return
    const Column& GetColumn(const std::size_t column) const;

    /// Returns number of rows in the matrix
	std::size_t GetRowCount() const;

    /// Returns number of columns in the matrix
	std::size_t GetColumnCount() const;

    /// Returns the shape of the matrix (x, y)
	std::vector<std::size_t> GetShape();

    /// Reshapes the matrix to nRows, nCols
    /// Possible loss of data !!!
    void Reshape(const std::size_t nRows, const std::size_t nCols);

    /// Transposes the matrix in situ
	void Transpose();

    /// Returns the transpose without transposing it in situ
	Matrix& GetTranspose();

    /// Returns the transpose without transposing it in situ
	Matrix& T();

    /// Prints the matrix to screen
    void Print();

    /// Prints the matrix to the screen
    /// @param columnWidth : Width of print columns
    void Print(const int columnWidth);

    /// Removes all rows and columns in the matrix
    void ClearMatrixData();

    void AppendRow(const std::vector<double>& row);

protected:
    std::vector<Row> *m_MatrixRows = nullptr;	
};
#endif

}
