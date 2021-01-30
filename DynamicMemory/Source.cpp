#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[], int& n, int value);// протатив
int* push_front(int arr[], int& n, int value);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int* insert(int arr[], int& n, int value,int index);
int* erase(int arr[], int& n, int index);

void main()
{
	setlocale(LC_ALL, "");
	int n; // размер массива
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);

	int value;// добавлаемое значение
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);// вызов
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);// вызов
	Print(arr, n);
	

	int index;
	cout << "Введите добавляемое значение : "; cin >> value;
	cout << "Введите индекс массива : "; cin >> index;
	arr = insert(arr, n, value, index);// вызов
	Print(arr, n);



	arr = pop_back(arr, n);// вызов
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);
	
	
	cout << "Введите индекс массива : "; cin >> index;
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

int* push_back(int arr[], int& n, int value)// реализация
{
	//1) создаем буфер массив нужного размера (на 1 элемент больше)
	int* buffer = new int[n + 1];
	//2 Копируем все значения в новый массив

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3 удаляем исх массив
	delete[]arr;
	// 4 подменяем исх массив
	arr = buffer;
	//5 Добавляем значение в конец массива; 
	arr[n] = value;
	//6 После того, как в массиве добавляем элемент
	// количество его элементов на 1+
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