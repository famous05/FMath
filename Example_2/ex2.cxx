#include <iostream>
#include <memory>
#include <vector>

#include "../Matrix.hxx"

using Matrix = FMath::Matrix;

int main()
{
    Matrix *m1 = new Matrix(4, 5, 1.5);
    auto m2 = Matrix(*m1 * 3);
    
    std::cout << " " << std::endl;
    std::cout << "Printing m1" << std::endl;
    m1->Print();

    std::cout << " " << std::endl;
    std::cout << "Printing m2" << std::endl;
    m2.Print();

   
    FMath::Matrix m3;
    
    m3 = *m1 - m2;
    std::cout << " " << std::endl;
    std::cout << "Printing m3" << std::endl;
    m3.Print();

    m3 /= 100;

    std::cout << " " << std::endl;
    std::cout << "Printing m3" << std::endl;
    m3.Print();

    auto row = m3[3];
    std::cout << " " << std::endl;
    std::cout << "Printing m3[3]" << std::endl;
    for (auto val : row) std::cout << val << std::endl;

    // Modify the matrices
    for (int r = 0; r < m3.GetRowCount(); r++)
    {
        for (int c = 0; c < m3.GetRowCount(); c++)
        {
            //std::cout << (*m1)[r][c] << std::endl;
            (*m1)[r][c] *= (c * r);
            m3[r][c] /= c;
            m2[r][c] *= (c + r);
        }
    }

    std::cout << " " << std::endl;
    std::cout << "Printing m1 after modification" << std::endl;
    m1->Print();

    std::cout << " " << std::endl;
    std::cout << "Printing m2 after modification" << std::endl;
    m2.Print();

    std::cout << " " << std::endl;
    std::cout << "Printing m3 after modification" << std::endl;
    m3.Print();

    auto rr = m2.GetColumn(1);
    
    std::cout << " " << std::endl;
    std::cout << "Printing m2 column 1" << std::endl;
    for (auto val : rr) std::cout << val << std::endl;


    std::cout << "Before transpose: m2 column count = " << m2.GetColumnCount();
    std::cout << "  row count = " << m2.GetRowCount() << std::endl;

    auto m2t = m2.GetTranspose();  // Get the transpose without transposing m2
    m2.Transpose(); // Transponse m2

    std::cout << "After transpose: m2 column count = " << m2.GetColumnCount();
    std::cout << "  row count = " << m2.GetRowCount() << std::endl;

    std::cout << " " << std::endl;
    std::cout << "Printing m2 after transpose" << std::endl;
    m2.Print();

    // This should throw error as shapes are different
    m3 += m2t;

    delete m1;
    m1 = nullptr;
    
    return 0;
};
