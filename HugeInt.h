#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class HugeInt
{
	int* A;
	int size;
	bool Sign;
	bool GreaterInQuantity(const HugeInt&)const;
	bool LessInQuantity(const HugeInt&)const;
	bool EqualInQuantity(const HugeInt&)const;
	HugeInt Add(const HugeInt& H)const;
	HugeInt Sub(const HugeInt& H)const;
	bool Continue(int* temp, int size)const;
	void decrement(int* &temp, int size)const;
	void Trim();
public:
	HugeInt();
	HugeInt(const char*);
	HugeInt(int num);
	int operator[](int i)const;
	int operator()(int i)const;
	int& operator[](int i);
	int& operator()(int i);
	HugeInt(const HugeInt& other);
	const HugeInt operator++(int);			//post 
	const HugeInt operator--(int);
	HugeInt& operator++();					//pre
	HugeInt& operator--();
	ostream& operator<<(ostream& Cwritter)const;
	istream& operator>>(istream& Creader)const;
	friend ostream& operator<<(ostream& COUT, const HugeInt&);
	friend istream& operator>>(istream& CIN, const HugeInt&);
	bool operator==(const HugeInt& H2)const;
	bool operator!=(const HugeInt& H2)const;
	bool operator<(const HugeInt& H2)const;
	bool operator>(const HugeInt& H2)const;
	bool operator<=(const HugeInt& H2)const;
	bool operator>=(const HugeInt& H2)const;
	HugeInt operator+(const HugeInt& other)const;
	void operator+=(const HugeInt& other);
	HugeInt operator-(const HugeInt& other)const;
	void operator-=(const HugeInt& other);
	HugeInt operator*(const HugeInt& other)const;
	void operator*=(const HugeInt& other);
	HugeInt operator/(const HugeInt& other) const;
	void operator/=(const HugeInt& other);
	HugeInt operator%(const HugeInt& other) const;
	void operator%=(const HugeInt& other);
	const HugeInt operator=(const HugeInt& H2);
	const HugeInt operator=(int num);
	const HugeInt operator=(const char* ptr);
	void Print()const;
	~HugeInt();
};