package main

import (
	"fmt"
	"time"
)

func main() {

	max := 100000
	prime_numbers := 0
	prime := 1

	fmt.Println("starting... ")
	start := time.Now()

	for x := 2; x <= max; x++ {

		if x%2 != 0 || x%5 != 0 || x%3 != 0 {

			for i := 2; i <= x/2; i++ {

				if x%i == 0 {

					prime = 0
					break
				}
			}
			if prime == 1 {

				prime_numbers++
			}
			prime = 1
		}
	}

	end := time.Since(start)
	fmt.Printf("It took %.3s seconds. Found %d prime numbers", end, prime_numbers)
}
