# Python program for implementation of Selection Sort 

arr = [98, 12, 89, 2, 84]

for i in range(len(arr)):
    min_idx = i
    for j in range(i+1, len(arr)):
        if arr[min_idx] > arr[j]:
            min_idx = j
 
    arr[i], arr[min_idx] = arr[min_idx], arr[i]
    
for i in range(len(arr)): 
    print(arr[i])
