/**
    FMath Library

    Copyright (c) 2020 - 2021
    Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com
*/


#include "MatrixVectorOperation.hxx"


const double PI = 3.14159265359;
using Row = std::vector<double>;


namespace FMath
{

MatrixVectorOperation::MatrixVectorOperation()
{

}

double MatrixVectorOperation::Dot(const Vector3D& a, const Vector3D& b)
{
	double a_[3] = {a.x, a.y, a.z};
	double b_[3] = {b.x, b.y, b.z};
	return MatrixVectorOperation::Dot(a_, b_);
}

double MatrixVectorOperation::Dot(double a[3], double b[3])
{
	return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}

double MatrixVectorOperation::Dot(std::vector<double> a, std::vector<double> b)
{
	double a_[3] = {a[0], a[1], a[2]};
	double b_[3] = {b[0], b[1], b[2]};
	return MatrixVectorOperation::Dot(a_, b_);
}

Vector3D& MatrixVectorOperation::Cross(const Vector3D& a, const Vector3D& b)
{
	double a_[3] = {a.x, a.y, a.z};
	double b_[3] = {b.x, b.y, b.z};
	return MatrixVectorOperation::Cross(a_, b_);
}

Vector3D& MatrixVectorOperation::Cross(double a[3], double b[3])
{
	Vector3D *v =  new Vector3D(a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0]);
	return *v;

	delete v;
	v = nullptr;
}

Vector3D& MatrixVectorOperation::Cross(std::vector<double> a, std::vector<double> b)
{
	double a_[3] = {a[0], a[1], a[2]};
	double b_[3] = {b[0], b[1], b[2]};
	return MatrixVectorOperation::Cross(a_, b_);
}

double MatrixVectorOperation::ScalarTripleProduct(const Vector3D& a, const Vector3D& b, const Vector3D& c)
{
	return Dot(Cross(a, b), c);
}

double MatrixVectorOperation::ScalarTripleProduct(double a[3], double b[3], double c[3])
{
	auto v = Cross(a, b);
	double b_[3] = {v.x, v.y, v.z};
	return Dot(b_, c);
}

double MatrixVectorOperation::ScalarTripleProduct(std::vector<double> a, std::vector<double> b, std::vector<double> c)
{
	auto v = Cross(a, b);
	std::vector<double> b_{v.x, v.y, v.z};
	return Dot(b_, c);
}

Matrix& MatrixVectorOperation::Multiply(Matrix& A, Matrix& B)
{
	if (A.GetColumnCount() != B.GetRowCount())
    {
        std::cout << "matrices cannot be multiplied: column count of first matrix not equal to row count of second" << std::endl;
        throw new std::runtime_error("matrices cannot be multiplied: column count of first matrix not equal to row count of second");
    }

    Matrix *M = new Matrix(A.GetRowCount(), B.GetColumnCount());

    for (std::size_t r = 0; r < A.GetRowCount(); r++)
    {
    	for (std::size_t c = 0; c < B.GetColumnCount(); c++)
    	{
    		(*M)[r][c] = A[r][c] * B[c][r];
    	}
    }

    return *M;

	delete M;
	M = nullptr;
}

Vector3D& MatrixVectorOperation::Multiply(Matrix3D& M, Vector3D& v)
{
	Vector3D *vv = new Vector3D(
			M[0][0] * v[0] + M[0][1] * v[1] + M[0][2] * v[2],
			M[1][0] * v[0] + M[1][1] * v[1] + M[1][2] * v[2],
			M[2][0] * v[0] + M[1][1] * v[1] + M[2][2] * v[2]
		);

	return *vv;

	delete vv;
	vv = nullptr;
}

Vector3D& MatrixVectorOperation::Project(Vector3D& a, Vector3D& b)
{
	return (b * (Dot(a, b) / Dot(b, b)));
}

Vector3D& MatrixVectorOperation::Reject(Vector3D& a, Vector3D& b)
{
	return (a - b * (Dot(a, b) / Dot(b, b)));
}

double MatrixVectorOperation::GetDeterminant(Matrix3D& M)
{
	return (M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1])
	      + M[0][1] * (M[1][2] * M[2][0] - M[1][0] * M[2][2])
	      + M[0][2] * (M[1][0] * M[2][1] - M[1][1] * M[2][0]));
}

Matrix3D& MatrixVectorOperation::GetInverse(Matrix3D& M)
{
	const Vector3D& a = M.GetRow(0);
	const Vector3D& b = M.GetRow(1);
	const Vector3D& c = M.GetRow(2);

	Vector3D r0 = Cross(b, c);
	Vector3D r1 = Cross(c, a);
	Vector3D r2 = Cross(a, b);

	double invDet = 1.0F / Dot(r2, c);

	Matrix3D *MM = new Matrix3D(Vector3D(r0.x * invDet, r0.y * invDet, r0.z * invDet),
	                 Vector3D(r1.x * invDet, r1.y * invDet, r1.z * invDet),
	                 Vector3D(r2.x * invDet, r2.y * invDet, r2.z * invDet));

	return *MM;

	delete MM;
	MM = nullptr;
}

Matrix3D& MatrixVectorOperation::MakeRotationX(double deg)
{
	deg = (deg * PI)/180;
	double c = cos(deg);
	double s = sin(deg);

	Matrix3D *M = new Matrix3D(Vector3D(1.0, 0.0, 0.0),
	                           Vector3D(0.0,  c,   -s),
	                           Vector3D(0.0,  s,    c  ));

	return *M;

	delete M;
	M = nullptr;
}

Matrix3D& MatrixVectorOperation::MakeRotationY(double deg)
{
	deg = (deg * PI)/180;
	double c = cos(deg);
	double s = sin(deg);

	Matrix3D *M = new Matrix3D(Vector3D(c,   0.0,  s),
	                           Vector3D(0.0, 1.0, 0.0),
	                           Vector3D(-s,   0.0F,  c  ));

	return *M;

	delete M;
	M = nullptr;
}

Matrix3D& MatrixVectorOperation::MakeRotationZ(double deg)
{
	deg = (deg * PI)/180;
	double c = cos(deg);
	double s = sin(deg);

	Matrix3D *M = new Matrix3D(Vector3D(c,   -s,  0.0),
	                           Vector3D(s,   c,  0.0),
	                           Vector3D(0.0, 0.0, 1.0));

	return *M;

	delete M;
	M = nullptr;
}

Matrix3D& MatrixVectorOperation::MakeRotation(double angle, Vector3D& axisVector)
{
	double deg = (PI * angle) / 180;
	double c = cos(deg);
	double s = sin(deg);
	double mag = axisVector.GetMagnitude();

	Matrix3D *M = new Matrix3D();

	if (mag != 1.0)  // axisVector must be a unit vector
	{
		std::cout << "Error: axis vector supplied in MakeRotation(angle, axisVector) not unit" << std::endl;
		return *M;
	}

	// Construct the matrix. See ref https://en.wikipedia.org/wiki/Rotation_matrix

	// Row 1
	(*M)[0][0] = c + axisVector.x * axisVector.x * (1 - c);
	(*M)[0][1] = axisVector.x * axisVector.y * (1 - c) - (axisVector.z * s);
	(*M)[0][2] = axisVector.x * axisVector.z * (1 - c) + (axisVector.y * s);


	// Row 2
	(*M)[1][0] = axisVector.y * axisVector.x * (1 - c) + (axisVector.z * s);
	(*M)[1][1] = c + axisVector.y * axisVector.y * (1 - c);
	(*M)[1][2] = axisVector.y * axisVector.z * (1 - c) - (axisVector.x * s);

	// Row 3
	(*M)[2][0] = axisVector.z * axisVector.x * (1 - c) - (axisVector.y * s);
	(*M)[2][1] = axisVector.z * axisVector.y * (1 - c) + (axisVector.x * s);
	(*M)[2][2] = c + axisVector.z * axisVector.z * (1 - c);

	return *M;

	delete M;
	M = nullptr;
}
/*
 void MatrixVectorOperation::TransposeMatrix(Matrix& M)
 {
	std::vector<Row> newMatrixRows;
    Row newRow; // == old column

    for (std::size_t j = 0; j < M.GetColumnCount(); j++)
    {
        for(std::size_t i = 0; i < M.GetRowCount(); i++)
        {
            newRow.push_back(M[i][j]);
        }
        newMatrixRows.push_back(newRow);
        newRow.clear();
    }

	M.ClearMatrixData();

    for (auto row_ : newMatrixRows)
    {
       M.AppendRow(row_);
    }
 }
*/

}
	