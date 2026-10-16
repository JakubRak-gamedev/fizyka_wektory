// Fizyka_Wektory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#define PI 3.14159265358979323846f
class Vector
{

 

public:

    Vector(float x, float y) : x(x), y(y) {}
 
    Vector operator+ (const Vector& A)
    {
		x = x + A.x;
		y = y + A.y;

		return Vector(x, y);
    }

    Vector operator- (const Vector& A)
    {
        x = x - A.x;
        y = y - A.y;

		return Vector(x, y);
    }

    static float DotProduct(const Vector& A, const Vector& B)
    {
        return B.x * A.x + B.y * A.y;
	}

    static std::string PrintVector(const Vector A)
    {
        return  "(" + std::to_string(A.x) + ", " + std::to_string(A.y) + ")";
	}

    float VectorLength() const
    {
        return sqrt(x * x + y * y);
    }

    float CalculateAngle(const Vector& A)
    {
        float dot = DotProduct(*this, A);
        float lengthA = VectorLength();
        float lengthB = A.VectorLength();
        return acos(dot / (lengthA * lengthB)) * 180.f / PI;
    }

private:

    float x, y;
};

int main()
{
	Vector A = Vector(0, 2);
	Vector B = Vector(-2, -2);

	std::cout << "A + B = " << Vector::PrintVector(A + B) << "\n";
    std::cout << "A - B = " << Vector::PrintVector(A - B) << "\n";
    std::cout << "Dot product (A * B) = " << Vector::DotProduct(A, B) << std::endl;
	std::cout << "Length of A = " << A.VectorLength() << std::endl;
	std::cout << "Length of B = " << B.VectorLength() << std::endl;
	std::cout << "Angle between A and B = " << A.CalculateAngle(B) << std::endl;
}
