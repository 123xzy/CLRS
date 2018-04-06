#include<stdio.h>

void insertsort(int* a,int len)
{
	for (int i = 1; i < len; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
	return ;
}
int main()
{
	int a[] = { 4,1,5,2,6,1,3 };
	insertsort(a,7);
	for (int i = 0; i < 7; i++)
		printf("%d ", a[i]);
	return 0;
}
