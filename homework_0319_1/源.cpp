#include<iostream>
#include<cmath>

class Complex 
{
	double real, image;
public:
	Complex(double r = 0, double i = 0) { real = r; image = i; };
	friend std::ostream& operator<<(std::ostream& output, const Complex& obj);
};

std::ostream& operator<<(std::ostream& output, const Complex& obj)
{
	output << obj.real << obj.image; 
	return output;
}
int main()
{
	Complex c; 
	std::cout<<c; 
	return 0;
}