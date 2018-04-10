#include<iostream>
#include<algorithm>

using namespace std;


int find_max_cross_subarray(int* A, int low, int mid, int high)
{
	int i,
		left_sum = -1000,
		right_sum = -1000,
		sum = 0;
	for (i = mid; i >= low; i--)
	{
		sum += A[i];
		if (sum > left_sum)
			left_sum = sum;
	}

	sum = 0;
	for (i = mid + 1; i <= high; i++)
	{
		sum += A[i];
		if (sum > right_sum)
			right_sum = sum;
	}
	return (left_sum + right_sum);
}

int find_max_subarray(int*  A, int low, int high)
{
	if (high == low)
		return A[low];
	int mid = (low + high) / 2,
		left_sum,
		right_sum,
		cross_sum;
	left_sum = find_max_subarray(A, low, mid);
	right_sum = find_max_subarray(A, mid + 1, high);
	cross_sum = find_max_cross_subarray(A, low, mid, high);
	if (left_sum >= right_sum && left_sum >= cross_sum)
		return left_sum;
	else if (right_sum >= left_sum && right_sum >= cross_sum)
		return right_sum;
	else return cross_sum;
}
int main()
{
	//int A[] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	int A[] = { -2,-5,-6,-4 };
	int max = find_max_subarray(A, 0, 15);
	cout << max;
	return 0;
}
