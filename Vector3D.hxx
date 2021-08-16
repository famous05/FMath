
/*------------------------------------------------------------------------------
FMath Library

Copyright (c) 2020 - 2021

Author : Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com

Class
    FMath::Vector3D

Description
    A 3D vector 
------------------------------------------------------------------------------*/


// C++ Headers
#include <iostream>
#include <cmath>
#include <iomanip>


namespace FMath
{

#ifndef VECTOR3D
#define VECTOR3D

class Vector3D
{
    public:

        /// Default constructor
        Vector3D();

        /// Parameter constructor
        /// @param double x, y, z. X, Y & Z components of vector
        Vector3D(double x, double y, double z);

        /// Copy constructor
        /// @param vector. Vector3D object to be copied
        Vector3D(const Vector3D& vector);

        /// Copy assignment operator
        /// @param vector. Vector3D object to be moved
        Vector3D& operator =(const Vector3D& vector);

        /// Destructor
        virtual ~Vector3D();

        Vector3D& operator +(const Vector3D& v);

        Vector3D& operator -(const Vector3D& v);

        Vector3D& operator *(double val);

        Vector3D& operator /(double val);

        Vector3D& operator +=(const Vector3D& v);

        Vector3D& operator -=(const Vector3D& v);  

        Vector3D& operator *=(double val);

        Vector3D& operator /=(double val);

        double& operator [](int i);

        const double& operator [](int i) const;
   
        void SetComponents(double x, double y, double z);

        virtual void Print();

        virtual void Print(int columnWidth);

        void Normalise();

        Vector3D& GetNormalisedVector();

        Vector3D& GetUnitVector();

        double GetMagnitude();

        double x, y, z;
};
#endif

}
