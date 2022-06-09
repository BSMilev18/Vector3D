#include <iostream>
using namespace std;

namespace Vector3d {
    class Vector3d
    {
    public:
        float x, y, z;
        Vector3d()
        {
            x = 0;
            y = 0;
            z = 0;
        }
        Vector3d(float x1, float y1, float z1 = 0)
        {
            this->x = x1;
            this->y = y1;
            this->z = z1;
        }
        Vector3d(const Vector3d& vec);   
        Vector3d operator+(const Vector3d& vec); 
        Vector3d& operator+=(const Vector3d& vec);
        Vector3d operator-(const Vector3d& vec);
        Vector3d& operator-=(const Vector3d& vec);
        Vector3d operator*(float value);
        Vector3d& operator*=(float value);
        Vector3d operator/(float value);
        Vector3d& operator/=(float value);
        Vector3d& operator=(const Vector3d& vec);
        float dot_product(const Vector3d& vec);
        Vector3d cross_product(const Vector3d& vec);
        float magnitude();
        float square();
        float distance(const Vector3d& vec);
        void displayValue();
    };

    Vector3d::Vector3d(const Vector3d& vec)
    {
        x = vec.x;
        y = vec.y;
        z = vec.z;
    }

    //addition of vectors

    Vector3d Vector3d ::operator+(const Vector3d& vec)
    {
        return Vector3d(x + vec.x, y + vec.y, z + vec.z);
    }

    Vector3d& Vector3d ::operator+=(const Vector3d& vec)
    {
        x += vec.x;
        y += vec.y;
        z += vec.z;
        return *this;
    }

    //substraction of vectors
    Vector3d Vector3d ::operator-(const Vector3d& vec)
    {
        return Vector3d(x - vec.x, y - vec.y, z - vec.z);
    }

    Vector3d& Vector3d::operator-=(const Vector3d& vec)
    {
        x -= vec.x;
        y -= vec.y;
        z -= vec.z;
        return *this;
    }

    //scalar multiplication of vectors

    Vector3d Vector3d ::operator*(float value)
    {
        return Vector3d(x * value, y * value, z * value);
    }

    Vector3d& Vector3d::operator*=(float value)
    {
        x *= value;
        y *= value;
        z *= value;
        return *this;
    }

    //scalar division of vectors
    Vector3d Vector3d ::operator/(float value)
    {
        if (value != 0) {
            return Vector3d(x / value, y / value, z / value);
        }
    }

    Vector3d& Vector3d ::operator/=(float value)
    {
        if (value != 0) {
            x /= value;
            y /= value;
            z /= value;
            return *this;
        }
    }

    Vector3d& Vector3d::operator=(const Vector3d& vec)
    {
        x = vec.x;
        y = vec.y;
        z = vec.z;
        return *this;
    }

    //dot product of vectors
    float Vector3d::dot_product(const Vector3d& vec)
    {
        return x * vec.x + vec.y * y + vec.z * z;
    }

    //cross product of vectors
    Vector3d Vector3d::cross_product(const Vector3d& vec)
    {
        float ni = y * vec.z - z * vec.y;
        float nj = z * vec.x - x * vec.z;
        float nk = x * vec.y - y * vec.x;
        return Vector3d(ni, nj, nk);
    }

    //calculate square
    float Vector3d::square()
    {
        return x * x + y * y + z * z;
    }

    //calculate magintude
    float Vector3d::magnitude()
    {
        return sqrt(square());
    }

    //calculate distance between vectors
    float Vector3d::distance(const Vector3d& vec)
    {
        Vector3d dist = *this - vec;
        return dist.magnitude();
    }

    //display value of vectors
    void Vector3d::displayValue()
    {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
        cout << "z = " << z << endl;
    }
}