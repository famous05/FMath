#include <iostream>
#include <memory>
#include <vector>

#include "../Matrix3D.hxx"
#include "../Matrix.hxx"
#include "../Vector3D.hxx"

using Vector3D = FMath::Vector3D;
using Matrix = FMath::Matrix;
using Matrix3D = FMath::Matrix3D;

int main()
{
	Matrix3D *m1 = new Matrix3D(2.5);
	auto m2 = *m1;

    std::cout << " " << std::endl;
    std::cout << "Printing m2" << std::endl;
	m2.Print();

	std::cout << " " << std::endl;
    std::cout << "Printing m1" << std::endl;
	m1->Print();

	auto m3 = std::make_unique<Matrix3D>(0.34);

	std::cout << " " << std::endl;
    std::cout << "Printing m3" << std::endl;
	m3->Print();

	// Modify m3
	for(int row = 0; row < m3->GetRowCount(); row++)
	{
		for (int col = 0; col < m3->GetColumnCount(); col++)
		{
			(*m3)[row][col] += (row + col);
		}
	}

    std::cout << " " << std::endl;
    std::cout << "Printing m3 after modification" << std::endl;
	m3->Print();

	// Set up vectors
	Vector3D v1(0.01, 0.3, 0.85);
	Vector3D v2(0.1, 1.3, 0.55);
	Vector3D v3(1, 0.93, 0.05);

	std::cout << " " << std::endl;
    std::cout << "Printing v3" << std::endl;
	v3.Print();

	Matrix3D *m4 = new Matrix3D(v1, v2, v3);

    std::cout << " " << std::endl;
    std::cout << "Printing m4" << std::endl;
	m4->Print();

	// Polymorphic initialization
	Matrix *m5 = new Matrix3D(-1);

	std::cout << " " << std::endl;
    std::cout << "Printing m5" << std::endl;
	m5->Print();

	auto row_m4 = m4->GetRow(1);  // Returns Vector3D
	auto row_m5 = m5->GetRow(1);  // Returns std::vector<double>

    std::cout << " " << std::endl;
    std::cout << "Printing m4 row 1" << std::endl;
	row_m4.Print(); 
	// row_m5 does not have the Print() function

	std::cout << " " << std::endl;
    std::cout << "Printing m4 row 1 after modification" << std::endl;
	row_m4[1] = -123.0;
	row_m4.Print(); 

	std::cout << " " << std::endl;
    std::cout << "Printing m4 after modification via row_m4" << std::endl;
	m4->Print();

	auto row2_m4 = (*m4)[2];

	std::cout << " " << std::endl;
    std::cout << "Printing m4 row 2" << std::endl;
	for (auto value : row2_m4) std::cout << value << std::endl;

	(*m4)[2][1] = 1000;
    std::cout << " " << std::endl;
    std::cout << "Printing m4 again" << std::endl;
	m4->Print();

	Matrix m6(6,6,10);

	std::cout << " " << std::endl;
    std::cout << "Printing m6" << std::endl;
	m6.Print();

	m6[3][4] = 100000;
	std::cout << " " << std::endl;
    std::cout << "Printing m6 again" << std::endl;
	m6.Print(20);

	delete m4;
	delete m5;
	delete m1;
	m4 = nullptr;
	m5 = nullptr;
	m1 = nullptr;

	return 0;
};
