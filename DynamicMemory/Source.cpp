#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[], int& n, int value);// ��������
int* push_front(int arr[], int& n, int value);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int* insert(int arr[], int& n, int value,int index);
int* erase(int arr[], int& n, int index);

void main()
{
	setlocale(LC_ALL, "");
	int n; // ������ �������
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);

	int value;// ����������� ��������
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_back(arr, n, value);// �����
	Print(arr, n);

	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_front(arr, n, value);// �����
	Print(arr, n);
	

	int index;
	cout << "������� ����������� �������� : "; cin >> value;
	cout << "������� ������ ������� : "; cin >> index;
	arr = insert(arr, n, value, index);// �����
	Print(arr, n);



	arr = pop_back(arr, n);// �����
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);
	
	
	cout << "������� ������ ������� : "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
	cout << endl;
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;

}

int* push_back(int arr[], int& n, int value)// ����������
{
	//1) ������� ����� ������ ������� ������� (�� 1 ������� ������)
	int* buffer = new int[n + 1];
	//2 �������� ��� �������� � ����� ������

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3 ������� ��� ������
	delete[]arr;
	// 4 ��������� ��� ������
	arr = buffer;
	//5 ��������� �������� � ����� �������; 
	arr[n] = value;
	//6 ����� ����, ��� � ������� ��������� �������
	// ���������� ��� ��������� �� 1+
	++n;
	return arr;

}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}



int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	return buffer;
}

int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[]arr;
	return buffer;

}

int* insert(int arr[], int& n, int value, int index)
{
	if (index >= n)return arr;
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	
	arr[index] = value;
	n++;
	return arr;
}
int* erase(int arr[],int &n ,int index)
{
	if (index >= n)return arr;
	int* buffer = new int[--n];
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < n; i++)
		buffer[i]=arr[i + 1];
	delete[]arr;
	return buffer;
}