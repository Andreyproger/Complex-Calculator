#pragma once
#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>

class Complex
{
    typedef double T;
private:
    const double epsilon = std::numeric_limits<T>::epsilon();
    enum typeNumber
    {
        beginType=-1,
        algebraic = 0,
        geometric,
        exponencial,
        endType
    };
    
public:
	Complex();
        
        ~Complex();

	Complex(const T real, const T image);

	void setReal(T realPart);

	void setImage(T imagePart);

	T real() const;

	T image() const;
        
        std::ostream& print();

	friend std::istream& operator>> (std::istream& is, Complex& value);
	
	friend std::ostream& operator<< (std::ostream& os, const Complex& value);	

	Complex& operator- (const Complex& complValue);

	Complex& operator=(const Complex & complValue);
	Complex& operator+=(const Complex & complValue);
	Complex& operator-=(const Complex& complValue);

	Complex& operator*=(const Complex& complValue);
	Complex& operator/=(const Complex& complValue);

	friend bool operator==(const Complex& lhs, const Complex& rhs); ///< in comparison need use epsilon
	friend bool operator==(const Complex& lhs, const double val);
	friend bool operator==(const double val, const Complex& rhs);

	friend bool operator!=(const Complex& lhs, const Complex& rhs);
	friend bool operator!=(const Complex& lhs, const double val);
	friend bool operator!=(const double val, const Complex& rhs);

	friend Complex operator+ (const Complex& compNum1, const Complex& compNum2);
	friend Complex operator+ (const double val, const Complex& compNum);
	friend Complex operator+ (const Complex& compNum, const double val);

	friend Complex operator- (const Complex& compNum1, const Complex& compNum2);
	friend Complex operator- (const double val, const Complex& compNum);
	friend Complex operator- (const Complex& compNum, const double val);

	friend Complex operator* (const Complex& compNum1, const Complex& compNum2);

	friend Complex operator/ (const Complex& compNum1, const Complex& compNum2);
	T abs(const Complex& complValue) const;
	T arg(const Complex& complValue) const;
	T norm(const Complex& complValue) const;

	Complex conj(const Complex& complValue);
	// Complex polar(const Complex& complValue);
	// Complex proj(const Complex& complValue);

	private:
		T m_real;
		T m_image;
};

//if implement template class need implementation specialization