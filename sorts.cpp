#include <array>
#include <vector>
#include <iostream>
#include <random>

using namespace std;
const int len = 100000;

void insertion_sort(array<int,len>& arr) {
	int n = len;
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i]) {
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}

/*template <typename T, size_t longueur>
void merge(array<T,longueur>& arr, size_t beg, size_t mid, size_t end) {
	const int long1 = mid-beg, long2 = end-mid;
	array<T,long1> A;
	array<T,long2> B;
	for (int i=0;i<mid-beg;i++) {
		A[i] = arr[beg+i];
	};
	for (int i=0;i<end-mid;i++) {
		B[i] = arr[mid+i];
	};
	int i = 0, j = 0, k = beg;
	while (i<mid-beg && j<end-mid) {
		if (A[i] <= B[j]) {
			arr[k] = A[i];
			i++;
		}
		else {
			arr[k] = B[j];
			j++;
		};
		k++;
	};
	if (i<mid-beg) {
		while (i<mid-beg) {
			arr[k] = A[i];
			i++;
		};
	};
};*/

void merge(vector<int>& arr, int beg, int mid, int end) {
	int long1 = mid - beg;
	int long2 = end - mid;
	vector<int> A(long1);
	vector<int> B(long2);
	for (int i = 0;i<long1;i++) {
		A[i] = arr[beg+i];
	};
	for (int j=0;j<long2;j++) {
		B[j] = arr[mid+j];
	};
	int i = 0, j = 0, k = beg;
	while (i < long1 && j < long2) {
		if (A[i] <= B[j]) {
			arr[k] = A[i];
			i++;
		}
		else {
			arr[k] = B[j];
			j++;
		}
		k++;
	};
	while (i<long1) {
		arr[k] = A[i];
		i++, k++;
	};
};

void merge_sort(vector<int>& arr, int beg, int end) {
	if (beg == end - 2 && arr[0]>arr[1]) {
		int temp=arr[beg];
		arr[beg]=arr[end];
		arr[end]=temp;
	}
	else if (end - beg >2)
	{
		int mid = (beg+end)/2;
		merge_sort(arr, beg, mid);
		merge_sort(arr, mid, end);
		merge(arr, beg, mid, end);
	};
};

/*template <typename T, size_t longueur>
void merge_sort(array<T,longueur>& arr, int begin = 0, int end = -1) {
	if (arr.size()>2) {
		if (len%2==0) {
			const int halflen = len/2;
			array<int, halflen> A;
			array<int, halflen> B;
			for (int i=0;i<halflen;i++) {
				A[i]=arr[i];
				B[i]=arr[halflen+i];
			};
		} 
		else {
			const int halflen = len/2;
			array<int, halflen> A;
			array<int, halflen+1> B;
			for (int i=0;i<halflen;i++) {
				A[i]=arr[i];
				B[i]=arr[halflen+i];
			};
			B[-1] = arr[-1];
			merge_sort(A);
			merge_sort(B);
		};
	}
	else if (len==2 && arr[0] > arr[1])
	{
		int temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
	};
}*/

int main(void) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1, 10000);
	array<int, len> arr;
	vector<int> vec(len);
	for (int i=0;i<len;i++) {
		arr[i] = dist(gen);
		vec[i] = arr[i];
	}

//	insertion_sort(arr);

	merge_sort(vec, 0, len);
//	cout << arr[15] << " " << arr[16] << " " << arr[17];
	cout << vec[0] << " " << vec[1] << " " << vec[2] << " " << vec[3] << " " << vec[4];
	return 0;
}