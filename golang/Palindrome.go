package main

import (
	"fmt"
)

func checkPalindrome(num int) string {
	input_num := num
	var remainder int
	res := 0
	for num > 0 {
		remainder = num % 10
		res = (res * 10) + remainder
		num = num / 10
	}
	if input_num == res {
		return "Palindrome"
	} else {
		return "Not a Palindrome"
	}
}

func main() {
	fmt.Println("Enter the number to check if it is a palindrome or not: ")
	var i int
	_, err := fmt.Scanf("%d", &i)
	if err != nil {
		fmt.Println("Error in input")
	}
	fmt.Println(checkPalindrome(i))
}
