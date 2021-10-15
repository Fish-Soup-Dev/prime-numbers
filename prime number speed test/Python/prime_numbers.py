import time

def main():

    max = 100000
    prime_numbers = 0
    prime = 1
    
    print("starting... ")
    start = time.time()

    for x in range(2, max):

        if x % 2 != 0 or x % 5 != 0 or x % 3 != 0:

            for i in range(2, x):

                if x % i == 0:

                    prime = 0
                    break

            if prime == 1:

                prime_numbers += 1

            prime = 1

    end = time.time()

    print("It took ", round(end - start, 3), " seconds. Found ", prime_numbers, " prime numbers")

if __name__ == "__main__":
    main()