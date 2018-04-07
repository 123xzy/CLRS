#include<stdio.h>
#include<stdlib.h>
void merge(int A[], int low, int mid,int high)
{
	int len = high - low + 1;
	int *temp = (int*)malloc(len * sizeof(int));
	int i = low, j = mid+1, k=0;
	while (i <= mid && j <= high)
	{
		if (A[i] <= A[j])
		{
			temp[k] = A[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = A[j];
			k++;
			j++;
		}
	}
	while(i<=mid)
		temp[k++] = A[i++];
	while(j<=high)
		temp[k++] = A[j++];
	for (int i = low, k = 0; i <= high; i++)
		A[i] = temp[k++];
}
void merge_sort(int A[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		merge_sort(A, low, mid);
		merge_sort(A, mid + 1, high);
		merge(A, low, mid, high);
	}
}
int main()
{
	int A[] = { 1,53,2,8,5,20,3,6 };
	for (int i = 0; i < 8; i++)
		printf("%d ",A[i]);
	merge_sort(A, 0, 7);
	printf("\n");
	for (int i = 0; i < 8; i++)
		printf("%d ", A[i]);
	return 0;
}
