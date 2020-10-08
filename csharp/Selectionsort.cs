using System;

public class SelectionSort{
    static void Main(string[] args){

        int[] array = new int[10] {34, 78, 12, 44, 23, 89, 67, 99 ,1 ,56};
        int num = 10;

        Console.WriteLine("Selection Sort!");
        Console.Write("Here is the initial array: ");

        for (int i = 0; i < num; i++){
            Console.Write(array[i] + " ");
        }

        int temp, small;

        for (int i = 0; i < num -1; i++){
            small = i;
            for (int j = i + 1; j < num; j++){
                if (array[j] < array[small]){
                    small = j;
                }
            }

            temp = array[small];
            array[small] = array[i];
            array[i] = temp;
        }

        Console.WriteLine();
        Console.Write("Selection sorted array is: ");
        for (int i = 0; i < num; i++){
            Console.Write(array[i] + " ");
        }

    // for stopping 
    Console.ReadLine();
    }
}