#include <iostream>
#include <memory>
#include <vector>

#include "../Vector3D.hxx"

using Vector3D = FMath::Vector3D;

int main()
{
    std::vector<double> vals = {0.0, -1.0, 0.0};
    auto v1 = std::make_unique<Vector3D>(1.5, 2, 2);
    auto v2 = std::make_unique<Vector3D>(vals);
    auto v3 = std::make_unique<Vector3D>(0.0, 1, -1);
    auto v4 = std::make_unique<Vector3D>(*v1);

    std::cout << " " << std::endl;
    std::cout << "Printing v1 " << std::endl;
    v1->Print();

    std::cout << " " << std::endl;
    std::cout << "Printing v2 " << std::endl;
    v2->Print();

    std::cout << " " << std::endl;
    std::cout << "Printing v3 " << std::endl;
    v3->Print();

    std::cout << " " << std::endl;
    std::cout << "Printing v4 " << std::endl;
    v4->Print();

    auto v5 = *v1 + *v2;

    std::cout << " " << std::endl;
    std::cout << "Printing v5 " << std::endl;
    v5.Print();

    auto v6 = *v1 - *v2;

    std::cout << " " << std::endl;
    std::cout << "Printing v6 " << std::endl;
    v6.Print();

    auto v7 = std::make_unique<Vector3D>();

    std::cout << " " << std::endl;
    std::cout << "Printing v7 " << std::endl;
    v7->Print();

    *v7 += v5;

    std::cout << " " << std::endl;
    std::cout << "Printing v7 again" << std::endl;
    v7->Print();

    *v7 /= 100;

    v7->Print();

    v7->SetComponents(0, 3, 4);

    *v7 *= 10;
    v7->Print();

    std::cout << "Magnitude of v7 = " << v7->Mag() << std::endl;

    v7->Normalise();

    std::cout << "Magnitude of v7 = " << v7->Mag() << std::endl;

    Vector3D V1(1, 2, 3);
    Vector3D V2(3, -4, 2);

    auto V3 = V1 + V2;
    V3.Print();

    std::cout << "Magnitude of V3 = " << V3.GetMagnitude() << std::endl;
    auto V4 = V3.GetNormalisedVector();
    V3.Print();
    V4.Print();

    V3[0] = 100;
    V3.Print();

    double a = V1[1];
    std::cout << "a = " << a << std::endl;

    V4 = V4/a;
    V4.Print();

    std::cout << "Printing unit vector of V4 " <<std::endl;
    V4.U().Print();
    
    return 0;
};
