/**
    FMath Library

    Copyright (c) 2020 - 2021
    Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com
*/

#include <iostream>
#include <iomanip>
#include <memory>

#include "Matrix.hxx"

using Row = std::vector<double>;
using Column = std::vector<double>;

namespace FMath
{

Matrix::Matrix() : FMath::Matrix(3, 3, 0.0)
{
    // Alternatively prohibit calling this constructor
}

Matrix::Matrix(const std::size_t nRows, const std::size_t nCols) : FMath::Matrix(nRows, nCols, 0.0)
{
    // This constructor calls another constructor
}

Matrix::Matrix(const std::size_t nRows, const std::size_t nCols, const double value)
{
    m_MatrixRows = new std::vector<Row>;

    Row row(nCols, value);

    for (std::size_t i = 0; i < nRows; i++)
    {
        m_MatrixRows->push_back(row);
    }
}

Matrix::Matrix(const Matrix& matrix)
{
    m_MatrixRows = new std::vector<Row>;
    *m_MatrixRows = *matrix.m_MatrixRows;
}

Matrix::Matrix(Matrix&& matrix)
{
    m_MatrixRows = new std::vector<Row>;
    m_MatrixRows = matrix.m_MatrixRows;
    matrix.m_MatrixRows = nullptr;
}

Matrix& Matrix::operator =(const Matrix& matrix)
{
	if (this != &matrix)
    {
        *m_MatrixRows = *(matrix.m_MatrixRows);
    }
    return *this;
}

Matrix& Matrix::operator =(Matrix&& matrix)
{
	if (this != &matrix)
    {
        m_MatrixRows = matrix.m_MatrixRows;
        matrix.m_MatrixRows = nullptr;
    }
    return *this;
}

Matrix::~Matrix()
{
    if (!m_MatrixRows->empty()) m_MatrixRows->clear();

    delete m_MatrixRows;
    m_MatrixRows = nullptr;
}

Matrix& Matrix::operator +(const Matrix& matrix)
{
    if (m_MatrixRows->size() != matrix.m_MatrixRows->size() ||
        m_MatrixRows[0].size() != matrix.m_MatrixRows[0].size())
    {
        std::cout << "input matrix dimensions do not match" << std::endl;
        throw new std::runtime_error("input matrix dimensions do not match");
    }

    FMath::Matrix *m_ = new FMath::Matrix(this->GetRowCount(), this->GetColumnCount(), 0.0);
    
    for (std::size_t i = 0; i < this->GetRowCount(); i++)
    {
        for (std::size_t j = 0; j < this->GetColumnCount(); j++)
        {
            m_->m_MatrixRows->at(i).at(j) = m_MatrixRows->at(i).at(j) + matrix.m_MatrixRows->at(i).at(j); 
        }
    }
    
    return *m_;

    delete m_;
    m_ = nullptr;
}

Matrix& Matrix::operator -(const Matrix& matrix)
{
    if (m_MatrixRows->size() != matrix.m_MatrixRows->size() ||
        m_MatrixRows[0].size() != matrix.m_MatrixRows[0].size())
    {
        std::cout << "input matrix dimensions do not match" << std::endl;
        throw new std::runtime_error("input matrix dimensions do not match");
    }

    FMath::Matrix *m_ = new FMath::Matrix(this->GetRowCount(), this->GetColumnCount(), 0.0);
    
    for (std::size_t i = 0; i < this->GetRowCount(); i++)
    {
        for (std::size_t j = 0; j < this->GetColumnCount(); j++)
        {
            m_->m_MatrixRows->at(i).at(j) = m_MatrixRows->at(i).at(j) - matrix.m_MatrixRows->at(i).at(j); 
        }
    }
    
    return *m_;

    delete m_;
    m_ = nullptr;
}

Matrix& Matrix::operator *(double val)
{
    FMath::Matrix *m_ = new FMath::Matrix(this->GetRowCount(), this->GetColumnCount(), 0.0);

    for (std::size_t i = 0; i < this->GetRowCount(); i++)
    {
        for (std::size_t j = 0; j < this->GetColumnCount(); j++)
        {
            m_->m_MatrixRows->at(i).at(j) = m_MatrixRows->at(i).at(j) * val; 
        }
    }

    return *m_;

    delete m_;
    m_ = nullptr;
}

Matrix& Matrix::operator /(double val)
{
    val = 1.0 / val;
    FMath::Matrix *m_ = new FMath::Matrix(this->GetRowCount(), this->GetColumnCount(), 0.0);

    for (std::size_t i = 0; i < this->GetRowCount(); i++)
    {
        for (std::size_t j = 0; j < this->GetColumnCount(); j++)
        {
            m_->m_MatrixRows->at(i).at(j) = m_MatrixRows->at(i).at(j) * val; 
        }
    }

    return *m_;

    delete m_;
    m_ = nullptr;
}

Matrix& Matrix::operator +=(const Matrix& matrix)
{
    if (m_MatrixRows->size() != matrix.m_MatrixRows->size() ||
        m_MatrixRows[0].size() != matrix.m_MatrixRows[0].size())
    {
        std::cout << "input matrix dimensions do not match" << std::endl;
        throw new std::runtime_error("input matrix dimensions do not match");
    }

    for (std::size_t i = 0; i < this->GetRowCount(); i++)
    {
        for (std::size_t j = 0; j < this->GetColumnCount(); j++)
        {
            this->m_MatrixRows->at(i).at(j) += matrix.m_MatrixRows->at(i).at(j);
        }
    }

    return *this;
}

Matrix& Matrix::operator -=(const Matrix& matrix)
{
    if (m_MatrixRows->size() != matrix.m_MatrixRows->size() ||
        m_MatrixRows[0].size() != matrix.m_MatrixRows[0].size())
    {
        std::cout << "input matrix dimensions do not match" << std::endl;
        throw new std::runtime_error("input matrix dimensions do not match");
    }

    for (std::size_t i = 0; i < this->GetRowCount(); i++)
    {
        for (std::size_t j = 0; j < this->GetColumnCount(); j++)
        {
            this->m_MatrixRows->at(i).at(j) -= matrix.m_MatrixRows->at(i).at(j);
        }
    }

    return *this;
}

Matrix& Matrix::operator *=(double val)
{
    for (std::size_t i = 0; i < this->GetRowCount(); i++)
    {
        for (std::size_t j = 0; j < this->GetColumnCount(); j++)
        {
            m_MatrixRows->at(i).at(j) *= val; 
        }
    }

    return *this;
}

Matrix& Matrix::operator /=(double val)
{
    val = 1.0/val;
    for (std::size_t i = 0; i < this->GetRowCount(); i++)
    {
        for (std::size_t j = 0; j < this->GetColumnCount(); j++)
        {
            m_MatrixRows->at(i).at(j) *= val; 
        }
    }

    return *this;
}

Row& Matrix::operator [](std::size_t row)
{   
    if (row > this->GetRowCount() - 1)
    {
        std::cout << "requested row index outside matrix range" << std::endl;
        throw new std::runtime_error("requested row index outside matrix range");
    }

    return m_MatrixRows->at(row);
}

const Row& Matrix::GetRow(std::size_t row) const
{
    if (row > this->GetRowCount() - 1)
    {
        std::cout << "requested row index outside matrix range" << std::endl;
        throw new std::runtime_error("requested row index outside matrix range");
    }

    return m_MatrixRows->at(row);
}

const Column& Matrix::GetColumn(std::size_t col) const
{
    if (col > this->GetColumnCount() - 1)
    {
        std::cout << "requested column index outside matrix range" << std::endl;
        throw new std::runtime_error("requested column index outside matrix range");
    }

    Column *column = new Column;

    for (std::size_t row = 0; row < this->GetRowCount(); row++)
    {
        column->push_back(m_MatrixRows->at(row).at(col));
    }

    return *column;

    delete column;
    column = nullptr;
}

std::size_t Matrix::GetRowCount() const
{
    return m_MatrixRows->size();
}

std::size_t Matrix::GetColumnCount() const
{
    return m_MatrixRows->at(0).size();
}

std::vector<std::size_t> Matrix::GetShape()
{
    std::vector<std::size_t> shape;
    shape.push_back(this->GetRowCount());
    shape.push_back(this->GetColumnCount());
    return shape;
}

void Matrix::Reshape(const std::size_t nRows, const std::size_t nCols)
{
    // Copy existing matrix data into a vector of doubles
    std::vector<double> matrixData;
    std::size_t newDataCount = nRows * nCols;
    std::size_t oldDataCount = this->GetRowCount() * this->GetColumnCount();
    
    for(std::size_t r = 0; r < this->GetRowCount(); r++)
    {
        for(std::size_t c = 0; c < this->GetColumnCount(); c++)
        {
            matrixData.push_back((*this)[r][c]);
        }
    }
    this->ClearMatrixData();

    if (newDataCount > oldDataCount)
    {
        for (int i = 0; i < (newDataCount - oldDataCount); i++)
        {
            matrixData.push_back(0.0); // Pad matrix data with zeros
        }
    }

    Row row;
    std::size_t index;
    for(std::size_t r = 0; r < nRows; r++)
    {
        for(std::size_t c = 0; c < nCols; c++)
        {
           index = c + r * nRows;
           row.push_back(matrixData.at(index)); 
        }
        this->m_MatrixRows->push_back(row);
        row.clear();
    }

    matrixData.clear();
}

void Matrix::Transpose()
{
    std::vector<Row> newMatrixRows;
    Row newRow; // == old column

    for (std::size_t j = 0; j < this->GetColumnCount(); j++)
    {
        for(std::size_t i = 0; i < this->GetRowCount(); i++)
        {
            newRow.push_back(m_MatrixRows->at(i).at(j));
        }
        newMatrixRows.push_back(newRow);
        newRow.clear();
    }

    m_MatrixRows->clear();

    for (auto row_ : newMatrixRows)
    {
       m_MatrixRows->push_back(row_);
    }
}

Matrix& Matrix::T()
{
    return this->GetTranspose();
}

Matrix& Matrix::GetTranspose()
{
    Matrix *m = new Matrix(*this);
    m->Transpose();
    return *m;

    delete m;
    m = nullptr;
}

void Matrix::Print()
{
    this->Print(10);
}

void Matrix::Print(const int colWidth)
{
    for (std::size_t i = 0; i < this->GetRowCount(); i++)
    {
        for (std::size_t j = 0; j < this->GetColumnCount(); j++)
        {
            std::cout << std::left << std::setw(colWidth) << this->m_MatrixRows->at(i).at(j);
        }
        std::cout << std::endl;
    }
}

void Matrix::ClearMatrixData()
{
    if (!(this->m_MatrixRows->empty())) this->m_MatrixRows->clear();
}

void Matrix::AppendRow(const std::vector<double>& row)
{
    if (m_MatrixRows->size() > 0)
    {
        if (m_MatrixRows->at(0).size() != row.size())
        {
            std::cout << "new row size does not match existing row size" << std::endl;
            throw new std::runtime_error("new row size does not match existing row size");
        }

        m_MatrixRows->push_back(row);
    }
    else
    {
        m_MatrixRows->push_back(row);
    }
}

} // End of namespace FMath
