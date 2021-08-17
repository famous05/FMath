/**
    FMath Library

    Copyright (c) 2020 - 2021
    Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com
*/

#include <iomanip>

#include "Matrix.hxx"
#include "Vector3D.hxx"
#include "Matrix3D.hxx"

using Row = std::vector<double>;

namespace FMath
{

Matrix3D::Matrix3D() : FMath::Matrix(3, 3, 0.0)
{
    // Calls its base class constructor
}

Matrix3D::Matrix3D(double value) : FMath::Matrix(3, 3, value)
{  
    // Calls it base class constructor
}

Matrix3D::Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c)
{
    this->m_MatrixRows = new std::vector<Row>;

    Row row1 {a.x, a.y, a.z};
    Row row2 {b.x, b.y, b.z};
    Row row3 {c.x, c.y, c.z};

    this->m_MatrixRows->push_back(row1);
    this->m_MatrixRows->push_back(row2);
    this->m_MatrixRows->push_back(row3);
}

Matrix3D::Matrix3D(const std::vector<double>& row1, const std::vector<double>& row2, const std::vector<double>& row3)
{
    this->m_MatrixRows = new std::vector<Row>;

    this->m_MatrixRows->push_back(row1);
    this->m_MatrixRows->push_back(row2);
    this->m_MatrixRows->push_back(row3);
}

Matrix3D::~Matrix3D() 
{

}

const Vector3D& Matrix3D::GetRow(int row) const
{
    if (row > this->GetRowCount() - 1)
    {
        std::cout << "requested row index outside matrix range" << std::endl;
        throw new std::runtime_error("requested row index outside matrix range");
    }

    FMath::Vector3D *v =  new FMath::Vector3D(this->m_MatrixRows->at(row)[0], this->m_MatrixRows->at(row)[1], this->m_MatrixRows->at(row)[2]);
    return *v;

    delete v;
    v = nullptr;
}

const Vector3D& Matrix3D::GetColumn(int col) const
{
    if (col > this->GetColumnCount() - 1)
    {
        std::cout << "requested column index outside matrix range" << std::endl;
        throw new std::runtime_error("requested column index outside matrix range");
    }

    FMath::Vector3D *v =  new FMath::Vector3D(this->m_MatrixRows->at(0)[col], this->m_MatrixRows->at(1)[col], this->m_MatrixRows->at(2)[col]);
    
    return *v;
    
    delete v;
    v = nullptr;
}

} 
