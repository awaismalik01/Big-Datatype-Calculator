#include"HugeInt.h"

void load(ifstream& fin, HugeInt** Num, int size)
{
	char* C = new char[50];
	for (int i = 0; i < size; i++)
	{
		fin >> C;
		Num[i] = new HugeInt(C);
	}
	delete[] C;
}

void display(HugeInt** Num, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Value " << i + 1 << ": ";
		cout << *Num[i];
	}
	cout << endl << endl;
}

int main()
{
	int size = 0;

	ifstream fin;
	fin.open("Hs.txt");
	if (!fin.is_open())
	{
		cout << "File not found" << endl;
		return 0;
	}

	fin >> size;
	HugeInt** Num = new HugeInt * [size];


	load(fin, Num, size);
	display(Num, size);

	HugeInt Result1;

	/*Result1 = (*Num[0]) + (*Num[1]);
	cout << "Num[0] + Num[1] = ";
	Result1.Print();
	cout << endl;

	Result1 = (*Num[0]) - (*Num[1]);
	cout << "Num[0] - Num[1] = ";
	Result1.Print();
	cout << endl;

	Result1 = (*Num[0]) * (*Num[1]);
	cout << "Num[0] * Num[1] = ";
	Result1.Print();
	cout << endl;

	Result1 = (*Num[0]) / (*Num[1]);
	cout << "Num[0] / Num[1] = ";
	Result1.Print();
	cout << endl;

	Result1 = (*Num[0]) % (*Num[1]);
	cout << "Num[0] % Num[1] = ";
	Result1.Print();
	cout << endl;
	
	(*Num[0]) += (*Num[1]);
	cout << "Num[0] += Num[1] = ";
	(*Num[0]).Print();
	cout << endl;

	(*Num[0]) -= (*Num[1]);
	cout << "Num[0] -= Num[1] = ";
	(*Num[0]).Print();
	cout << endl;
	
	(*Num[0]) *= (*Num[1]);
	cout << "Num[0] *= Num[1] = ";
	(*Num[0]).Print();
	cout << endl;
	
	(*Num[0]) /= (*Num[1]);
	cout << "Num[0] /= Num[1] = ";
	(*Num[0]).Print();
	cout << endl;
	
	(*Num[0]) %= (*Num[1]);
	cout << "Num[0] %= Num[1] = ";
	(*Num[0]).Print();
	cout << endl;

	cout << "Num[0] != Num[1] :- " << boolalpha << ((*Num[0]) != (*Num[1])) << endl << endl;*/

	cout << "Pre-decrement Num[0]: " << --(*Num[0]) << endl;
	cout << "Pre-Increment Num[1]: " << ++(*Num[1]) << endl;

	cout << "Post-decrement Num[0]: " << (*Num[0])++ << endl;		
	cout << "Post-Increment Num[1]: " << (*Num[1])-- << endl;		

	cout << "Post-decrement Num[0]: " << (*Num[0])++ << endl;
	cout << "Post-Increment Num[1]: " << (*Num[1])-- << endl;

	/*HugeInt& operator++();
	const HugeInt operator++(int n);*/
	delete[] Num;


	return 0;
}