use std::time::{Instant};

fn main() {

    let max:i32 = 100000;
    let mut prime_numbers:i32 = 0;
    let mut prime:i32 = 1;
    let i:i32 = 2;
    
    println!("starting... ");
    let start = Instant::now();

    for x in 2..(max + 1) {   

        if x % 2 != 0 || x % 5 != 0 || x % 3 != 0 {

            for i in i..=(x / 2) {

                if x % i == 0 {

                    prime = 0;
                    break;
                }
            }
            if prime == 1 {
                
                prime_numbers += 1;
            }
            prime = 1;
        }
    }

    let duration = start.elapsed();
    println!("It took {:?} seconds. Found {} prime numbers", duration, prime_numbers);
}