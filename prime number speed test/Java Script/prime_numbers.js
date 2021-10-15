
function millisToSeconds(millis) {

    var seconds = ((millis % 60000) / 1000);

    return seconds;
    }

function FindPrime(x, prime_numbers){
    var prime = 1

    if (x % 2 != 0 || x % 5 != 0 || x % 3 != 0) {

        for (i = 2; i <= x / 2; i++) {

            if (x % i == 0) {
                prime = 0;
                break;
            }
        }
        if (prime == 1) {
            prime_numbers ++; 
        }
        prime = 1;
    }
    return prime_numbers;
}

function main(){
    
    var max = 100000;
    var prime_numbers = 0;
    
    console.log("starting... ");
    var start = new Date().getTime();

    for (x = 2; x <= max; x++) {   
        prime_numbers = FindPrime(x, prime_numbers);
    }

    var end = new Date().getTime();
    var time = millisToSeconds(end - start);
    
    console.log("It took " + time +" seconds. Found " + prime_numbers + " prime numbers");
}

main();