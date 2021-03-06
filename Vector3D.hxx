
/**
    FMath Library

    Copyright (c) 2020 - 2021
    Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <memory>
#include <vector>

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
        Vector3D(const double x, const double y, const double z);

        /// Parameter constructor
        /// @param std::vector<double> values. Vector array of  X, Y & Z components of vector
        Vector3D(const std::vector<double> values);

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

        ///  Returns value at given index
        ///  @param index : Index of vector
        double& operator [](const int index);

        ///  Returns value at given index
        ///  @param index : Index of vector
        const double& operator [](const int index) const;
   
        /// Set x, y, z components of the vector
        void SetComponents(const double x, const double y, const double z);

        /// Prints the vector to the screen
        virtual void Print();

        /// Prints the vector to the screen
        /// @param columnWidth : Width of print columns
        virtual void Print(const int columnWidth);

        /// Normalises the current vector
        void Normalise();

        /// Returns the normalised vector without normalizing the vector itself.
        Vector3D& GetNormalisedVector();

        /// Returns the unit vector without normalizing the vector itself.
        Vector3D& GetUnitVector();

        /// Returns the unit vector without normalizing the vector itself.
        Vector3D& U();

        /// Returns the magnitude of the vector
        double GetMagnitude();
        
        /// Returns the magnitude of the vector
        double Mag();

        double x, y, z;
};
#endif

}
