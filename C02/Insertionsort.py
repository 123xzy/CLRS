array = [5,2,4,6,1,3]

for j in range(1,len(array)):
	key = array[j]
	i = j-1
	while i >= 0 and array[i] > key:
		array[i+1] = array[i]
		i = i - 1
	array[i+1] = key
	print(array)
print(array)
