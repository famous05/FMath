
/**
    FMath Library

    Copyright (c) 2020 - 2021
    Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com
*/

#include "Vector3D.hxx"

namespace FMath
{

Vector3D::Vector3D() : FMath::Vector3D(0, 0, 0)
{
    // This constructor calls another constructor
}

Vector3D::Vector3D(const double x, const double y, const double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3D::Vector3D(const std::vector<double> values)
{
    if (values.size() != 3)
    {
        std::cout << "invalid size of vector to initialize Vector3D class" << std::endl;
        throw new std::runtime_error("invalid size of vector to initialize Vector3D class");
        FMath::Vector3D(0, 0, 0);
    }

    this->x = values[0];
    this->y = values[1];
    this->z = values[2];

}

Vector3D::Vector3D(const Vector3D& v) : FMath::Vector3D(v.x, v.y, v.z)
{

}

Vector3D& Vector3D::operator =(const Vector3D& v)
{
	if (&v != this)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
	}
	return *this;
}

Vector3D::~Vector3D()
{

}

Vector3D& Vector3D::operator +(const Vector3D& v)
{
    auto vector = new FMath::Vector3D(0,0,0);
    vector->x = this->x + v.x;
    vector->y = this->y + v.y;
    vector->z = this->z + v.z;
    return *vector;

    delete vector;
    vector = nullptr;
}

Vector3D& Vector3D::operator -(const Vector3D& v)
{
    auto vector = new FMath::Vector3D(0,0,0);
    vector->x = this->x - v.x;
    vector->y = this->y - v.y;
    vector->z = this->z - v.z;
    return *vector;

    delete vector;
    vector = nullptr;
}

Vector3D& Vector3D::operator *(double val)
{
    auto vector = new FMath::Vector3D(0,0,0);
    vector->x = this->x * val;
    vector->y = this->y * val;
    vector->z = this->z * val;
    return *vector;

    delete vector;
    vector = nullptr;
}

Vector3D& Vector3D::operator /(double val)
{
    auto vector = new FMath::Vector3D(0,0,0);
    val = 1.0/val;
    vector->x = this->x * val;
    vector->y = this->y * val;
    vector->z = this->z * val;
    return *vector;

    delete vector;
    vector = nullptr;
}

Vector3D& Vector3D::operator +=(const Vector3D& v)
{
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
    return *this;
}

Vector3D& Vector3D::operator -=(const Vector3D& v)
{
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
    return *this;
}

Vector3D& Vector3D::operator *=(double val)
{
    this->x *= val;
    this->y *= val;
    this->z *= val;
    return *this;
}

Vector3D& Vector3D::operator /=(double val)
{
    val = 1.0/val;
    this->x *= val;
    this->y *= val;
    this->z *= val;
    return *this;
}

double& Vector3D::operator [](const int i)
{
    if ((i > 2) || (i < 0))
    {
        std::cout << "invalid Vector3D index requested" << std::endl;
        throw new std::runtime_error("invalid Vector3D index requested");
    }
    else
    {
        if (i == 0) return this->x;

        if (i == 1) return this->y;

        if (i == 2) return this->z;  
    }

    return this->x;
}

const double& Vector3D::operator [](const int i) const
{
    if ((i > 2) || (i < 0))
    {
        std::cout << "invalid Vector3D index requested" << std::endl;
        throw new std::runtime_error("invalid Vector3D index requested");
    }
    else
    {
        if (i == 0) return this->x;

        if (i == 1) return this->y;

        if (i == 2) return this->z;  
    }

    return this->x;
}

void Vector3D::SetComponents(const double x, const double y, const double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vector3D::Print()
{
    Print(10);
}

void Vector3D::Print(const int colWidth)
{
    std::cout << std::left << std::setw(colWidth) << this->x;
    std::cout << std::left << std::setw(colWidth) << this->y;
    std::cout << std::left << std::setw(colWidth) << this->z;
    std::cout << std::endl;
}

void Vector3D::Normalise()
{
    *this = *this / this->GetMagnitude();
}

Vector3D& Vector3D::GetNormalisedVector()
{
   Vector3D *v = new FMath::Vector3D(*this);
   v->Normalise();
   return *v;

   delete v;
   v = nullptr;
}

Vector3D& Vector3D::GetUnitVector()
{
    return this->GetNormalisedVector();
}

Vector3D& Vector3D::U()
{
    return this->GetNormalisedVector();
}

double Vector3D::GetMagnitude()
{
    return (sqrt(this->x * this->x + this->y * this->y + this->z * this->z));
}

double Vector3D::Mag()
{
    return this->GetMagnitude();
}

} // End of namespace FMath
