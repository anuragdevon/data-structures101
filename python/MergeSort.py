def merge(arr, L, R): 
  i = j = k = 0

  # Copy data to temp arrays L[] and R[] 
  while i < len(L) and j < len(R): 
      if L[i] < R[j]: 
          arr[k] = L[i] 
          i+= 1
      else: 
          arr[k] = R[j] 
          j+= 1
      k+= 1
    
  # Checking if any element was left 
  while i < len(L): 
      arr[k] = L[i] 
      i+= 1
      k+= 1
    
  while j < len(R): 
      arr[k] = R[j] 
      j+= 1
      k+= 1

def mergeSort(arr):
  if len(arr) > 1: 
    mid = len(arr)//2   # Finding the mid of the array 
    L = arr[:mid]       # Dividing the array elements into 2 halves  
    R = arr[mid:]    

    mergeSort(L) # Sorting the first half 
    mergeSort(R) # Sorting the second half
    merge(arr, L, R) # Merging the 2 halves
  
  
# Code to print the list 
def printList(arr): 
  for i in range(len(arr)):         
      print(arr[i], end =" ") 
  print() 
  
# driver code to test the above code 
if __name__ == '__main__': 
  arr = [1,23,4,5,6,32,2,4,12,3,5,25,3,5,1,23,4,5,6,32,2,4,12,3,5,25,3,5,1,23,4,5,6,32,2,4,12,3,5,25,3,5];  
  print ("Given array is", end ="\n")  
  printList(arr) 
  mergeSort(arr) 
  print("Sorted array is: ", end ="\n") 
  printList(arr) 