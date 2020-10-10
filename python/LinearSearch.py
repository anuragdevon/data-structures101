def linearsearch(arr, x):
   for i in range(len(arr)):
      if arr[i] == x:
         return i
   return -1
# Usage
arr = ['y','a','s','h']
x = 'a'
print("element found at index "+str(linearsearch(arr,x)))
