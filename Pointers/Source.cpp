#include<iostream>
using namespace std;
//#define START
//#define POINTER_ARITHIMETICS
void main()
{
	setlocale(LC_ALL, "russian");

#ifdef START
	int a = 2; //объявление переменной
	int* pa = &a; // pointer to 'a'
	cout << a << endl;// вывод переменной 'а' на экран
	cout << &a << endl;// получение адреса 'а' при выводе
	cout << pa << endl;//выавод адреса 'а', хран.го в указателе 'pa'
	cout << *pa << endl;//Разыменование указателя 'pa' и получение значение


	int* pointer;
	int b = 3;
	pointer = &b;
	/*------
	int -int;
	int* -указатель на int

	double -double;
	double*- указатель double

	*/
	double price = 2.5;
	double* p = price = &price;
#endif // START
#ifdef POINTER_ARITHIMETICS
	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };

	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}

#endif // POINTER_ARITHIMETICS
	// Reference - это переменная, которая содержит адрес другой переменной.
	
	int a = 2;
	int& ra=a;
	ra += 3;
	std:: cout << &a << endl;
	std:: cout << &ra << endl;
}