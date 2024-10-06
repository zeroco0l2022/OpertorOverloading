// OperatorOverloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;

class Vector
{
public:
    Vector() 
    {
        x = 0;
        y = 0;
        z = 0;
    }
    Vector(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    friend Vector operator+(const Vector& a, const Vector& b);
    friend Vector operator-(const Vector& a, const Vector& b);
    friend Vector operator*(const Vector& a, const Vector& b);
    friend ostream& operator<<(ostream& out, const Vector& v);
    friend istream& operator>>(istream& in, Vector& v);
    float operator[](int index) 
    {
        switch (index)
        {
        case 0:
            return x;
            break;
        case 1:
            return y;
            break;
        case 2:
            return z;
            break;
        default:
            std::cout << "index error";
            return 0;
            break;
        }
    }

    friend bool operator>(const Vector& a, const Vector& b);
    operator float()
    {
        return sqrt(x * x + y * y + z * z);
    }

private:
    float x;
    float y;
    float z;


};

Vector operator+(const Vector& a, const Vector& b)
{
    return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}
Vector operator-(const Vector& a, const Vector& b)
{
    return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector operator*(const Vector& a, const Vector& b)
{
    return Vector(a.x * b.x, a.y * b.y, a.z * b.z);
}

ostream& operator<<(ostream& out, const Vector& v) 
{
    out << ' ' << v.x << ' ' << v.y << ' ' << v.z;
    return out;
}

istream& operator>>(istream& in, Vector& v)
{
    in >> v.x >> v.y >> v.z;
    return in;
}

bool operator>(const Vector& a, const Vector& b)
{
    return false;
}

int main()
{
    Vector v1(0, 1, 2);
    Vector v2(3, 4, 5);
    Vector v3;
    Vector v4;
    v3 = v1 * v2;
    cout << v3<<'\n';
    cout << "v3 length "<<float(v3) << '\n';
    cin >> v4;
    cout << v4;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file