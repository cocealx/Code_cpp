#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<math.h>
class Complex
{
public:

	Complex(const double dReal, const double dlmage) :_dReal(dReal), _dlmage(dlmage){};
	Complex(const Complex&complex)
	{
		_dReal = complex._dReal;
		_dlmage = complex._dlmage;
	};
	~Complex(){};

	Complex&operator=(const Complex& complex);
	Complex operator+(const Complex& complex);
	Complex operator-(const Complex& complex);
	Complex operator*(const Complex& complex);
	Complex operator/(const Complex& complex);

	Complex&operator+=(const Complex& complex);
	Complex&operator-=(const Complex& complex);
	Complex&operator*=(const Complex& complex);
	Complex&operator/=(const Complex& complex);

	bool operator< (const Complex& complex)const;
	bool operator<=(const Complex& complex)const;
	bool operator> (const Complex& complex)const;
	bool operator>=(const Complex& complex)const;
	bool operator==(const Complex& complex)const;
	bool operator!=(const Complex& complex)const;
private:
	double _dReal;
	double _dlmage;
};
Complex& Complex::operator=(const Complex& complex)
{
	_dReal = complex._dReal;
	_dlmage = complex._dlmage;
	return *this;
}
Complex  Complex::operator+(const Complex& complex)
{
	Complex ret(_dReal + complex._dReal, _dlmage + complex._dlmage);
	return ret;
}
Complex  Complex::operator-(const Complex& complex)
{
	Complex ret(_dReal - complex._dReal, _dlmage - complex._dlmage);
	return ret;
}
Complex  Complex::operator*(const Complex& complex)
{
	Complex ret(_dReal * complex._dReal - _dlmage * complex._dlmage , _dlmage*complex._dReal + _dReal*complex._dlmage);
	return ret;
}
Complex  Complex::operator/(const Complex& complex)
{
	Complex ret((_dReal * complex._dReal + _dlmage * complex._dlmage) / (complex._dlmage*complex._dlmage + complex._dReal*complex._dReal)
		, (_dlmage*complex._dReal - _dReal*complex._dlmage) / (complex._dlmage*complex._dlmage + complex._dReal*complex._dReal));
	return ret;
}
Complex& Complex::operator+=(const Complex& complex)
{
	_dReal  += complex._dReal;
	_dlmage += complex._dlmage;
	return *this;
}
Complex& Complex::operator-=(const Complex& complex)
{
	_dReal  -= complex._dReal;
	_dlmage -= complex._dlmage;
	return *this;
}
Complex& Complex::operator*=(const Complex& complex)
{
	*this = (*this).operator*(complex);
	return *this;
}
Complex& Complex::operator/=(const Complex& complex)
{
	*this = (*this).operator/(complex);
	return *this;
}

bool  Complex::operator< (const Complex& complex)const
{
	if (sqrt(_dReal*_dReal + _dlmage*_dlmage)<sqrt(complex._dlmage*complex._dlmage + complex._dReal*complex._dReal))
		return true;
	return false;
}
bool  Complex::operator<=(const Complex& complex)const
{
	if (sqrt(_dReal*_dReal + _dlmage*_dlmage)<=sqrt(complex._dlmage*complex._dlmage + complex._dReal*complex._dReal))
		return true;
	return false;
}
bool  Complex::operator> (const Complex& complex)const
{
	if (sqrt(_dReal*_dReal + _dlmage*_dlmage) > sqrt(complex._dlmage*complex._dlmage + complex._dReal*complex._dReal))
		return true;
	return false;
}
bool  Complex::operator>=(const Complex& complex)const
{
	if (sqrt(_dReal*_dReal + _dlmage*_dlmage) >= sqrt(complex._dlmage*complex._dlmage + complex._dReal*complex._dReal))
		return true;
	return false;
}
bool  Complex::operator==(const Complex& complex)const
{
	if (sqrt(_dReal*_dReal + _dlmage*_dlmage) == sqrt(complex._dlmage*complex._dlmage + complex._dReal*complex._dReal))
		return true;
	return false;
}
bool  Complex::operator!=(const Complex& complex)const
{
	if (sqrt(_dReal*_dReal + _dlmage*_dlmage) != sqrt(complex._dlmage*complex._dlmage + complex._dReal*complex._dReal))
		return true;
	return false;
}
int main()
{
	Complex com1(1, 2);
	Complex com2(1, 2);
	Complex com3(com1 + com2);
	com3 = com1 - com2;
	com3 = com1 * com2;
	com3 = com1 / com2;
	if (com1 == com2)
	{
		std::cout << "相等" << std::endl;
	}
	if (com2 != com3)
	{
		std::cout << "不相等" << std::endl;
	}
	if (com2< com3)
	{
		std::cout << "第一个小于第二个" << std::endl;
	}
	if (com1 > com2)
	{
		std::cout << "第一个大于第二个" << std::endl;
	}

}