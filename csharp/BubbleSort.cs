using System;
class BubbleSort {
    static void Main(string[] args) {

         int[] arr = { 78, 55, 45, 98, 13, 8, 5, 4, 8, 1 };
         int temp;

        Console.WriteLine("Original array: ");
        foreach (int p in arr)
        Console.WriteLine(p + " ");

        for (int j = 0; j <= arr.Length - 2; j++) {

            for (int i = 0; i <= arr.Length - 2; i++) {

                if (arr[i] > arr[i + 1]) {
                    temp= arr[i + 1];
                    arr[i + 1] = arr[i];
                    arr[i] = temp;
                }
            }
        }

            Console.WriteLine("Sorted Array:");
            foreach (int p in arr)
            Console.WriteLine(p + " ");
            Console.Read();
    }
}