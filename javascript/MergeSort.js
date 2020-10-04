//ES6 syntax
//create a function to merge the arrays first
const merge = (arr1, arr2) => {
  let sorted = [];

  while (arr1.length && arr2.length) {
    if (arr1[0] < arr2[0]) sorted.push(arr1.shift());
    else sorted.push(arr2.shift());
  };

  return sorted.concat(arr1.slice().concat(arr2.slice()));
};

//recursively merge and sort
const mergeSort = arr => {
  if (arr.length <= 1) return arr;
  let mid = Math.floor(arr.length / 2),
      left = mergeSort(arr.slice(0, mid)),
      right = mergeSort(arr.slice(mid));

  return merge(left, right);
};

//test case
let unsortedArr = [1,23,4,5,6,32,2,4,12,3,5,25,3,5,1,23,4,5,6,32,2,4,12,3,5,25,3,5,1,23,4,5,6,32,2,4,12,3,5,25,3,5];

//output: [1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 12, 12, 12, 23, 23, 23, 25, 25, 25, 32, 32, 32]
console.log(mergeSort(unsortedArr));
