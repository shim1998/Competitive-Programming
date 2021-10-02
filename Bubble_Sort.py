# Bubble Sort in Python -> Time Complexity - O(N^2)

def BubbleSort(Array):
	Length = len(Array)

	for i in range(Length - 1):
		for j in range(0, Length - i-1):
            
            # Traversing the Array from 0th index to (n - i - 1)th index and swapping if the element found is greater than the next element
            
			if Array[j] > Array[j + 1] :
				Array[j], Array[j + 1] = Array[j + 1], Array[j]

# Main Code, where function will be called :
A = [74, 3, 34, 57, 82, 1, 10, 22]

BubbleSort(A)

print ("SORTED ARRAY : ")
for i in range(len(A)):
	print (A[i], end = " ")
