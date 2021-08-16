#include <iostream>
#include <memory>
#include <vector>

#include "../Matrix.hxx"

int main()
{
    FMath::Matrix *m1 = new FMath::Matrix(4, 5, 1.5);
    m1->Print();

    auto m2 = FMath::Matrix(*m1 * 3);
    //m2.Print();

    FMath::Matrix m3;
    m3 = *m1 / 3;
    //m3.Print();

    m3 = *m1 - m2;
    //m1->Print();
    //m2.Print();
    //m3.Print();

    m3 /= 100;
    m3.Print();

    auto row = m3[3];
    for (auto val : row) std::cout << val << std::endl;

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

    m1->Print();
    m2.Print();
    m3.Print();

    auto rr = m2.GetColumn(1);
    for (auto val : rr) std::cout << val << std::endl;

    m2.Transpose();
    m2.Print();
    return 0;
};
