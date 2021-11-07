/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   complex.cpp
 * Author: andrey
 *
 * Created on 1 ноября 2021 г., 18:00
 */

#include "complex.hpp"

Complex::Complex():
    m_real(0),
    m_image(0)
{}

Complex::Complex(const double real, const double image):
    m_real(real),
    m_image(image)
{}

Complex::~Complex()
{}

void Complex::setReal(double realPart)
{
    m_real = realPart;
}

void Complex::setImage(double imagePart)
{
    this->m_image = imagePart;
}

double Complex::real() const
{
    return m_real;
}

double Complex::image() const
{
    return m_image;
}

bool operator==(const Complex& lhs, const Complex& rhs)
{
    return (lhs.real() == rhs.real() && lhs.image() == rhs.image());
}

bool operator==(const Complex& lhs, const double val)
{
    return (lhs.real() == val);
}

bool operator==(const double val, const Complex& rhs)
{
    return (rhs.real() == val);
}

bool operator!=(const Complex& lhs, const Complex& rhs)
{
    return !(operator==(lhs,rhs));
}

bool operator!=(const Complex& lhs, const double val)
{
    return !(operator==(lhs,val));
}

bool operator!=(const double val, const Complex& rhs)
{
    return !(operator==(val,rhs));
}

Complex operator+ (const Complex& compNum1, const Complex& compNum2)
{
    return Complex(compNum1.real() + compNum2.real(), compNum1.m_image + compNum2.m_image);
}

Complex operator+ (const double Num1, const Complex& compNum2)
{
    return Complex(Num1 + compNum2.real(), compNum2.image());
}

Complex operator+ (const Complex& compNum1, const double Num2)
{
    return Complex(compNum1.real() + Num2, compNum1.image());
}

Complex operator- (const Complex& compNum1, const Complex& compNum2)
{
    return Complex(compNum1.real() - compNum2.real(), compNum1.m_image - compNum2.m_image);
}

Complex operator- (const double val, const Complex& compNum)
{
    return Complex(val - compNum.real(), compNum.image());
}

Complex operator- (const Complex& compNum, const double val)
{
    return Complex(compNum.real() - val, compNum.image());
}

Complex operator* (const Complex& compNum1, const Complex& compNum2)
{
    return Complex(compNum1.real()*compNum2.real() - compNum1.image()*compNum2.image(), compNum1.real()*compNum2.image() + compNum1.image()*compNum2.real());
}

Complex operator/ (const Complex& compNum1, const Complex& compNum2)
{
	const double deniminator = compNum2.real()*compNum2.real() + compNum2.image()*compNum2.image();

	return Complex(
			(compNum1.real()*compNum2.real()+compNum1.image()*compNum2.image())/deniminator, 
			(compNum1.image()*compNum2.real() - compNum1.real()*compNum2.image())/deniminator
			);
}

Complex& Complex::operator- (const Complex& complValue)
{
	this->m_image = -complValue.m_image;
	return *this;
}

Complex& Complex::operator+= (const Complex& complValue)
{
	this->m_real += complValue.m_real;
	this->m_image += complValue.m_image;
	return *this;
}

Complex& Complex::operator=(const Complex & complValue)
{
	this->m_real = complValue.m_real;
	this->m_image = complValue.m_image;
	return *this;
}

Complex& Complex::operator-=(const Complex& complValue)
{
	this->m_real -= complValue.m_real;
	this->m_image -= complValue.m_image;
	return *this;
}

Complex& Complex::operator*=(const Complex& complValue)
{
	const double realPart = this->real()*complValue.real() - this->image()*complValue.image();
	const double imagePart = this->real()*complValue.image() + this->image()*complValue.real();

	this->setReal(realPart);
	this->setImage(imagePart);
	return *this;
}

Complex& Complex::operator/=(const Complex& complValue)
{
	const double delimeter = complValue.real()*complValue.real() + complValue.image()*complValue.image();

	if(delimeter == 0)
	{
            std::cout << "Delimeter equal zero!!!" << std::endl;
            throw;
	}

	const double realPart = this->real()*complValue.real() - this->image()*complValue.image();
	const double imagePart = this->real()*complValue.image() + this->image()*complValue.real();
	
	this->setReal(realPart);
	this->setImage(imagePart);	
	return *this;
}

double Complex::abs(const Complex& complValue) const
{
	return std::sqrt(norm(complValue));
}

double Complex::arg(const Complex& complValue) const
{
	return atan2(complValue.image(), complValue.real());
}

double Complex::norm(const Complex& complValue) const
{
	return complValue.real()*complValue.real() + complValue.image()*complValue.image();
}

std::istream& operator>> (std::istream& is, Complex& value)
{
    double real, image;
    is.ignore(256,'(');
    is >> real;
    is.ignore(256,',');
    is >> image;
    is.ignore(256, ')');
    
    if(is.good())
    {
        value.m_real = real;
        value.m_image = image;
    }
    
    return is;
}

std::ostream& operator<< (std::ostream& os, const Complex& value)
{
		return os << "("
                          << value.real()
                          << ", "
                          << value.image()
                          << ")";
}

Complex Complex::conj(const Complex& complValue)
{
    return Complex(complValue.real(), complValue.image());
}

// Complex Complex::conj(const Complex& complValue)
// {
// 	return Complex::operator-(complValue);
// }

