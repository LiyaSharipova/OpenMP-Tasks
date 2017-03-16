//
// Created by liya on 02.03.17.
//

#include <iostream>
#include <stdio.h>
#include <cmath>
//#include <mpi.h>

using namespace std;

class CVector {
public:
	int n;
	double* v;
	CVector(int n);
	~CVector();
	double norm();
};

// CVector::CVector(int n) : n(n)
CVector::CVector(int n)
{
	this->n=n;
	v = new double[n];
}

CVector::~CVector()
{
	delete v;
}

// Наследование - CVec2 наследует CVector
// class CVec2 : CVector ...

double CVector::norm()
{
	double result=0;
	for (int i=0; i<n; i++)
	{
		result+=v[i]*v[i];
	}
	return sqrt(result);
}
int main()
{
	int n;
	cout << "Input vector length: ";
	cin >> n;
	CVector vec(n);

	cout << "Input vector entries: ";
	for (int i=0; i<n; i++)
	{
		cin >> vec.v[i];
	}

	double norm = vec.norm();

	printf("norm - %f\n", vec.norm());

	if (norm > 1)
	{
		printf("Vector is too large\n");
	}

	return 0;
}