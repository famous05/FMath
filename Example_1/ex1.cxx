#include <iostream>
#include <memory>
#include <vector>

#include "../Vector3D.hxx"

using Vector3D = FMath::Vector3D;

int main()
{
    auto v1 = std::make_unique<Vector3D>(1.5, 2, 2);
    auto v2 = std::make_unique<Vector3D>(0, -1, 0);
    auto v3 = std::make_unique<Vector3D>(0.0, 1, -1);
    auto v4 = std::make_unique<Vector3D>(*v1);

    v1->Print();
    v2->Print();
    v3->Print();
    v4->Print();

    auto v5 = *v1 + *v2;
    v5.Print();

    auto v6 = *v1 - *v2;
    v6.Print();

    auto v7 = std::make_unique<Vector3D>();

    v7->Print();

    *v7 += v5;

    v7->Print();

    *v7 /= 100;

    v7->Print();

    v7->SetXYZ(0, 3, 4);

    *v7 *= 10;
    v7->Print();

    std::cout << "Magnitude of v7 = " << v7->GetMagnitude() << std::endl;

    v7->Normalise();

    std::cout << "Magnitude of v7 = " << v7->GetMagnitude() << std::endl;

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

	return 0;
};
