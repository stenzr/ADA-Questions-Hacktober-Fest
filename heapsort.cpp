#include <bits/stdc++.h>
 
using namespace std;
 
void Heapify(int a[], int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2*i;
 
 	while (j <= n)
	{
		if (j < n && a[j+1] > a[j])
		j = j+1;
		if (temp > a[j])
			break;
		else if (temp <= a[j])
		{
			a[j/2] = a[j];
			j = 2*j;
		}
	}
	a[j/2] = temp;
	return;
}
void HeapSort(int a[], int n)
{
	int i, temp;
	for (i = n; i >= 2; i--)
	{
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		Heapify(a, 1, i - 1);
	}
}
void Build_MaxHeap(int a[], int n)
{
	int i;
	for(i = n/2; i >= 1; i--)
		Heapify(a, i, n);
}
int main()
{
	int n, i;
	cout<<"\nenter the number of elements:\n";
	cin>>n;
	n++;
	int arr[n];
	for(i = 1; i < n; i++)
	{
		cout<<"Enter element "<<i<<": ";
		cin>>arr[i];
	}
	Build_MaxHeap(arr, n-1);
	HeapSort(arr, n-1);
 
	cout<<"\nSorted:";
 
	for (i = 1; i < n; i++)
		cout<<" "<<arr[i]<<" ";
 
	return 0;
}
