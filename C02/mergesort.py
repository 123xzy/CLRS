def merge(A,p,q,r):
	n1 = q-p+1;
	n2 = r-q;
	R = []
	L = []
	for i in range(n1):
		L.append(A[p+i-1])
	for j in range(n2):
		R.append(A[q+j])
	L.append(float("inf"))
	R.append(float("inf"))
	i = 0
	j = 0
	for k in range(p,r+1):
		if L[i] <= R[j]:
			A[k] = L[i]
			i += 1
		else:
			A[k] = R[j]
			j += 1

def merge_sort(A,p,r):
	if p < r:
		q = (p+r)/2
		merge_sort(A,p,q)
		merge_sort(A,q+1,r)
		merge(A,p,q,r)

if __name__ == '__main__':
	A = [5,1,2,15,12,2,3,7]
	merge_sort(A,0,7)
	print(A)


