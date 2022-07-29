#include "HugeInt.h"

int HugeInt::operator[](int i)const		//get values
{
	if (i >= this->size)
		return 0;
	return A[i];
}

int& HugeInt::operator[](int i)			//updates values
{
	return A[i];
}

bool HugeInt::GreaterInQuantity(const HugeInt& other) const
{
	if (this->size > other.size)
		return true;
	if (this->size < other.size)
		return false;

	for (int i = size - 1; i >= 0; i--)
	{
		if ((*this)[i] > other[i])
			return true;
		else if ((*this)[i] < other[i])
			return false;
	}
	return false;
}

bool HugeInt::LessInQuantity(const HugeInt& other) const
{
	if (this->size < other.size)
		return true;
	if (this->size > other.size)
		return false;

	for (int i = size - 1; i >= 0; i--)
	{
		if ((*this)[i] < other[i])
			return true;
		if ((*this)[i] > other[i])
			return false;
	}
	return false;
}

bool HugeInt::EqualInQuantity(const HugeInt& other) const
{
	if (this->size == other.size)
	{
		for (int i = size - 1; i >= 0; i--)
		{
			if ((*this)[i] != other[i])
				return false;
		}
		return true;
	}
	return false;
}

HugeInt HugeInt::Add(const HugeInt& H) const
{
	int carry = 0;
	HugeInt Result;
	Result.size = this->size + 1;
	Result.Sign = this->Sign;
	Result.A = new int[Result.size]{ 0 };
	for (int i = 0; i < Result.size; i++)
	{
		if (i < Result.size - 1)
		{
			if (i < H.size)
			{
				Result[i] = ((*this)[i] + H[i] + carry) % 10;
				carry = ((*this)[i] + H[i] + carry) / 10;
			}
			else
			{
				Result[i] = ((*this)[i] + carry) % 10;
				carry = ((*this)[i] + carry) / 10;
			}

		}
		else
		{
			Result[i] = carry;
		}

	}
	Result.Trim();
	return Result;
}

HugeInt HugeInt::Sub(const HugeInt& H) const
{
	int carry = 0;
	HugeInt Result;
	Result.size = this->size;
	Result.Sign = this->Sign;
	Result.A = new int[Result.size]{ 0 };
	for (int i = 0; i < Result.size; i++)
	{
		if (i < H.size)
		{
			Result[i] = (*this)[i] - H[i] - carry;
			if (Result.A[i] < 0)
			{
				Result[i] = Result[i] + 10;
				carry = 1;
			}
			else
				carry = 0;
		}
		else
		{
			Result[i] = (*this)[i] - carry;
			if (Result[i] < 0)
			{
				Result[i] = Result[i] + 10;
				carry = 1;
			}
			else
				carry = 0;
		}
	}
	Result.Trim();
	return Result;
}

void HugeInt::Trim()
{
	int si = 0, d = 0;
	for (int i = size - 1; i >= 0; i--, d++)
	{
		if ((*this)[i] != 0)
		{
			si = i;
			break;
		}
	}

	if (this->size != d)
	{
		this->size = this->size - d;
		int* temp = A;
		A = new int[this->size]{ 0 };
		for (int i = size - 1, j = si; i >= 0; i--, j--)
		{
			(*this)[i] = temp[j];
		}
		delete[] temp;
		temp = nullptr;
	}
	else
	{
		this->size = this->size - d + 1;
		int* temp = A;
		A = new int[this->size]{ 0 };
		for (int i = size - 1, j = si; i >= 0; i--, j--)
		{
			(*this)[i] = temp[j];
		}
		delete[] temp;
		temp = nullptr;

	}
}

HugeInt::HugeInt()
{
	this->A = nullptr;
	this->size = 0;
	this->Sign = false;
}

HugeInt::HugeInt(const char* C)
{
	size = strlen(C);
	size--;
	if (C[0] == '-')
		this->Sign = true;
	else
		this->Sign = false;

	A = new int[size] {0};
	for (int i = size, j = 0; i > 0; i--, j++)
	{
		A[j] = C[i] - '0';
	}
}

HugeInt::HugeInt(int num):size(num++)
{
	int r = 0, q = 0;
	this->size = 1;

	if (num >= 0)
		this->Sign = false;
	else
		this->Sign = true;

	r = num % 10;
	q = num / 10;
	while (q > 0)
	{
		this->size++;
		r = q % 10;
		q = q / 10;

	}

	this->A = new int[this->size]{ 0 };
	this->A[0] = num % 10;
	q = num / 10;

	int i = 1;
	while (q > 0)
	{
		A[i] = (q % 10);
		q = q / 10;
		i = i + 1;
	}
}

HugeInt::HugeInt(const HugeInt& other)
{
	if (!this->A)
		delete[] A;

	this->Sign = other.Sign;
	this->size = other.size;
	this->A = new int[this->size];
	for (int i = 0; i < size; i++)
	{
		this->A[i] = other.A[i];
	}
}

const HugeInt HugeInt::operator=(const HugeInt& other)
{
	if (!this->A)
		delete[] A;

	this->size = other.size;
	this->Sign = other.Sign;
	this->A = new int[this->size];
	for (int i = 0; i < size; i++)
	{
		this->A[i] = other.A[i];
	}
	return *this;
}

const HugeInt HugeInt::operator=(int num)
{
	int r = 0, q = 0;
	this->size = 1;


	r = num % 10;
	q = num / 10;
	while (q > 0)
	{
		this->size++;
		r = q % 10;
		q = q / 10;

	}

	this->A = new int[this->size]{ 0 };
	this->A[0] = num % 10;
	q = num / 10;

	int i = 1;
	while (q > 0)
	{
		A[i] = (q % 10);
		q = q / 10;
		i = i + 1;
	}
	return *this;
}

const HugeInt HugeInt::operator=(const char* C)
{
	size = strlen(C);
	A = new int[size] {0};
	for (int i = size - 1, j = 0; i >= 0; i--, j++)
	{
		A[j] = C[i] - '0';
	}
	return *this;
}

const HugeInt HugeInt::operator++(int n)
{
	HugeInt temp(*this);
	*this = (*this) + 1;
	return temp;
}

const HugeInt HugeInt::operator--(int n)
{
	HugeInt temp(*this);
	*this = *this + 1;
	return temp;
}

HugeInt& HugeInt::operator++()
{
	*this = *this + 1;
	return *this;
}

HugeInt& HugeInt::operator--()
{
	*this = *this - 1;
	return *this;
}

ostream& HugeInt::operator<<(ostream& Cwritter) const
{
	Print();
	return Cwritter;
}

istream& HugeInt::operator>>(istream& Creader) const
{
	return Creader;
}

bool HugeInt::operator==(const HugeInt& H2) const
{
	if (this->EqualInQuantity(H2))
		return true;
	else
		return false;
}

bool HugeInt::operator!=(const HugeInt& H2) const
{
	if (this->EqualInQuantity(H2))
		return false;
	else
		return true;
}

bool HugeInt::operator<(const HugeInt& H2) const
{
	if (this->LessInQuantity(H2))
		return true;
	else
		return false;
}

bool HugeInt::operator>(const HugeInt& H2) const
{
	if (this->GreaterInQuantity(H2))
		return true;
	else
		return false;
}

bool HugeInt::operator<=(const HugeInt& H2) const
{
	if (this->EqualInQuantity(H2) || this->LessInQuantity(H2))
		return true;
	else
		return false;
}

bool HugeInt::operator>=(const HugeInt& H2) const
{
	if (this->EqualInQuantity(H2) || this->GreaterInQuantity(H2))
		return true;
	else
		return false;
}

ostream& operator<<(ostream& COUT, const HugeInt& other)
{
	other.Print();
	return COUT;
}

istream& operator>>(istream& CIN, const HugeInt& other)
{
	return CIN;
}

HugeInt HugeInt::operator+(const HugeInt& other)const
{
	if (this->Sign == other.Sign)
	{
		if (this->GreaterInQuantity(other))
			return this->Add(other);
		else
			return other.Add(*this);
	}
	else
	{
		if (this->GreaterInQuantity(other))
			return this->Sub(other);
		else
			return other.Sub(*this);
	}
}

void HugeInt::operator+=(const HugeInt& other)
{
	if (this->Sign == other.Sign)
	{
		if (this->GreaterInQuantity(other))
			(*this) = this->Add(other);
		else
			(*this) = other.Add(*this);
	}
	else
	{
		if (this->GreaterInQuantity(other))
			(*this) = this->Sub(other);
		else
			(*this) = other.Sub(*this);
	}
}

HugeInt HugeInt::operator-(const HugeInt& other)const
{
	if (this->Sign == other.Sign)
	{
		if (this->GreaterInQuantity(other))
			return this->Sub(other);
		else
			return other.Sub(*this);
	}
	else
	{
		if (this->GreaterInQuantity(other))
			return this->Add(other);
		else
			return other.Add(*this);
	}
}

void HugeInt::operator-=(const HugeInt& other)
{
	if (this->Sign == other.Sign)
	{
		if (this->GreaterInQuantity(other))
			(*this) = this->Sub(other);
		else
			(*this) = other.Sub(*this);
	}
	else
	{
		if (this->GreaterInQuantity(other))
			(*this) = this->Add(other);
		else
			(*this) = other.Add(*this);
	}
}

//These Multiplication, Division operations works on Log-N times.

HugeInt HugeInt::operator*(const HugeInt& other) const
{
	int z = 0;
	if (other == z)
		return z;

	HugeInt Temp = z, TH = other, count = z, Result = z;

	if (this->Sign == true || other.Sign == true)
	{
		Result.Sign = false;
		TH.Sign = false;
	}

	while (TH != 0)
	{
		Result = *this;
		count = 1;
		while (count + count <= TH)
		{
			Result += Result;
			count += count;
		}
		Temp += Result;
		Result = z;
		TH = TH - count;

	}

	if (this->Sign != other.Sign)
	{
		Temp.Sign = true;
	}
	else
	{
		Temp.Sign = false;
	}
	return Temp;
}

void HugeInt::operator*=(const HugeInt& other)
{
	int z = 0;
	if (other == z)
	{
		*this = z;
		return;
	}

	HugeInt Temp = z, TH = other, count = z, Result = z;

	if (this->Sign == true || other.Sign == true)
	{
		Result.Sign = false;
		TH.Sign = false;
	}

	while (TH != 0)
	{
		Result = *this;
		count = 1;
		while (count + count <= TH)
		{
			Result += Result;
			count += count;
		}
		Temp += Result;
		Result = z;
		TH = TH - count;

	}

	if (this->Sign != other.Sign)
	{
		Temp.Sign = true;
	}
	else
	{
		Temp.Sign = false;
	}

	*this = Temp;
}

HugeInt HugeInt::operator/(const HugeInt& other) const
{
	int z = 0;
	if (other == z)
		return z;
		
	HugeInt Temp = z, TH = other, count = z, Result = *this, q = z;

	while (Result >= TH)
	{
		if (this->Sign == true || other.Sign == true)
		{
			Result.Sign = false;
			TH.Sign = false;
		}
		count = 1;
		while (TH + TH <= Result)
		{
			TH += TH;
			count += count;
		}
		q += count;
		Temp = TH;
		TH = other;
		Result = Result - Temp;
	}

	if (this->Sign != other.Sign)
	{
		q.Sign = true;
	}
	else
	{
		q.Sign = false;
	}

	return q;
}

void HugeInt::operator/=(const HugeInt& other)
{
	int z = 0;
	if (other == z)
	{
		(*this) = z;
		return;
	}

	HugeInt Temp = z, TH = other, count = z, Result = *this, q = z;

	

	while (Result >= TH)
	{
		if (this->Sign == true || other.Sign == true)
		{
			Result.Sign = false;
			TH.Sign = false;
		}
		count = 1;
		while (TH + TH <= Result)
		{
			TH += TH;
			count += count;
		}
		q += count;
		Temp = TH;
		TH = other;
		Result = Result - Temp;
	}

	if (this->Sign != other.Sign)
	{
		q.Sign = true;
	}
	else
	{
		q.Sign = false;
	}

	(*this) = q;
}

HugeInt HugeInt::operator%(const HugeInt& other) const
{
	int z = 0;
	if (other == z)
		return *this;

	HugeInt Temp = z, TH = other, count = z, Result = *this, q = z;

	while (Result >= TH)
	{
		if (this->Sign == true || other.Sign == true)
		{
			Result.Sign = false;
			TH.Sign = false;
		}
		count = 1;
		while (TH + TH <= Result)
		{
			TH += TH;
			count += count;
		}
		q += count;
		Temp = TH;
		TH = other;
		Result = Result - Temp;
	}

	if (this->Sign != other.Sign)
	{
		Result.Sign = true;
	}
	else
	{
		Result.Sign = false;
	}

	return Result;
}

void HugeInt::operator%=(const HugeInt& other)
{
	int z = 0;
	if (other == z)
		return;

	HugeInt Temp = z, TH = other, count = z, Result = *this, q = z;

	while (Result >= TH)
	{
		if (this->Sign == true || other.Sign == true)
		{
			Result.Sign = false;
			TH.Sign = false;
		}
		count = 1;
		while (TH + TH <= Result)
		{
			TH += TH;
			count += count;
		}
		q += count;
		Temp = TH;
		TH = other;
		Result = Result - Temp;
	}

	if (this->Sign != other.Sign)
	{
		Result.Sign = true;
	}
	else
	{
		Result.Sign = false;
	}

	(*this) = Result;
}

/*these are slow technique process N times. and the above Un-commented are Fast*/
//HugeInt HugeInt::operator*(const HugeInt& other)const
//{
//	int z = 0;
//	HugeInt Result = z;
//
//	if (GreaterInQuantity(other))
//	{
//		for (HugeInt I = z; I < other; I++)
//		{
//			Result = Result + (*this);
//		}
//	}
//	else
//	{
//		for (HugeInt I = z; I < *this; I++)
//		{
//			Result = Result + other;
//		}
//	}
//	if (this->Sign == other.Sign)
//		Result.Sign = false;
//	else
//		Result.Sign = true;
//	return Result;
//}
//
//void HugeInt::operator*=(const HugeInt& other)
//{
//	int z = 0;
//	HugeInt Result;
//
//	if (LessInQuantity(other))
//	{
//		for (HugeInt I = z; I < other; I++)
//		{
//			Result = Result + (*this);
//		}
//	}
//	else
//	{
//		for (HugeInt I = z; I < *this; I++)
//		{
//			Result = Result + other;
//		}
//	}
//	if (this->Sign == other.Sign)
//		Result.Sign = false;
//	else
//		Result.Sign = true;
//
//	(*this) = Result;
//}
//
//HugeInt HugeInt::operator/(const HugeInt& other)const
//{
//	int z = 0;
//	HugeInt Result = z, Temp = *this;
//
//	if (this->Sign != other.Sign)
//	{
//		Temp.Sign = other.Sign;
//	}
//
//	while (Temp >= other)
//	{
//		Temp = Temp - other;
//		Result = Result + 1;
//	}
//
//	if (this->Sign == other.Sign)
//		Result.Sign = false;
//	else
//		Result.Sign = true;
//	return Result;
//}
//
//void HugeInt::operator/=(const HugeInt& other)
//{
//	int z = 0;
//	HugeInt Result = z, Temp = *this;
//	
//	if (this->Sign != other.Sign)
//	{
//		Temp.Sign = other.Sign;
//	}
//
//	while (Temp >= other)
//	{
//		Temp = Temp - other;
//		Result = Result + 1;
//	}
//
//	if (this->Sign == other.Sign)
//		Result.Sign = false;
//	else
//		Result.Sign = true;
//
//	(*this) = Result;
//}
//
//HugeInt HugeInt::operator%(const HugeInt& other)const
//{
//	int z = 0;
//	HugeInt Temp = *this, count = z;
//
//	if (this->Sign != other.Sign)
//	{
//		Temp.Sign = other.Sign;
//	}
//
//	while (Temp >= other)
//	{
//		Temp = Temp - other;
//	}
//	count = Temp;
//	if (this->Sign == other.Sign)
//		count.Sign = false;
//	else
//		count.Sign = true;
//	return count;
//}
//
//void HugeInt::operator%=(const HugeInt& other)
//{
//	int z = 0;
//	HugeInt count = z, Temp = *this;
//
//	if (this->Sign != other.Sign)
//	{
//		Temp.Sign = other.Sign;
//	}
//
//	while (Temp >= other)
//	{
//		Temp = Temp - other;
//	}
//	count = Temp;
//	if (this->Sign == other.Sign)
//		count.Sign = false;
//	else
//		count.Sign = true;
//	(*this) = count;
//}	

bool HugeInt::Continue(int* temp, int size)const
{
	for (int i = 0; i < size; i++)
	{
		if (temp[i] > 0)
			return true;
	}
	return false;
}

void HugeInt::decrement(int* &temp, int size)const
{
	int carry = 0;
	for (int i = 0; i < size; i++)
	{
		temp[i] = temp[i] - 1 - carry;
		if (temp[i] < 0)
		{
			temp[i] = temp[i] + 10;
			carry = 1;
		}
		else
			carry = 0;
	}
}

void HugeInt::Print()const
{
	if (this->Sign == false)
		cout << '+';
	else
		cout << '-';
	for (int i = size - 1; i >= 0; i--)
	{
		cout << A[i];
	}
	cout << endl;
}

HugeInt::~HugeInt()
{
	delete[] A;
	A = nullptr;
}