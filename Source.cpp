#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
void show_arr(T arr[], int lenght) {
	cout << "[";
	for (int i = 0; i < lenght; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

template <typename T>
void fill_arr(T arr[], int lenght, T begin, T end) {
	srand(time(0));
	for (int i = 0; i < lenght; i++)
		arr[i] = rand() % (end - begin) + begin;
}

template <typename T>
void resize_arr(T*& arr, int &length, int &length2) {
	if (length2 <= 0)
		return;

	if (length2 > length) {
		T* tmp = new T[length + length2]{};
		for (int i = 0; i < length; i++) {
			tmp[i] = arr[i];
		}
		delete[] arr;
		arr = tmp;
	}
	else
		if (length2 < length){
		T* tmp = new T[length2];	
		for (int i = 0; i < length2; i++) {
			tmp[i] = arr[i];	
		}
	delete[] arr;	
	arr = tmp;
}


}


int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	// ������ 1
	cout << "������ 1.\n������� ����� 1 ������� -> ";
	cin >> n;
	cout << "������� ����� 2 ������� -> ";
	cin >> m;
	int* A = new int[n];
	int* B = new int[m];
	fill_arr(A, n, -10, 20);
	fill_arr(B, m, -5, 35);
	cout << "������ 1:\n";
	show_arr(A, n);
	cout << "������ 2:\n";
	show_arr(B, m);
	int *C = new int[n + m];
	for (int i = 0; i < n; i++)
		C[i] = A[i];
	for (int i = n; i < n + m; i++)
		C[i] = B[i - n];
	cout << "������ 3:\n";
	show_arr(C, n + m);
	delete[] A;
	delete[] B;
	cout << endl;

	// ������ 2
	cout << "������ 2.\n������� ������ ����� �������(����������� 10):";
	int len1 = 10,len2;
	cin >> len2;
	int* K = new int[len1];	// ���������� � len2 �� len1
	fill_arr(K, len1, 5, 30);
	cout << "����������� ������:\n";
	show_arr(K, len1);
	cout << "�������� ������:\n";	
	resize_arr(K, len1, len2);
	show_arr(K, len2);
	delete[] K;

	return 0;
}