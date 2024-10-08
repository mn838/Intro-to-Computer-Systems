#include <stdio.h>

/*
print Celsius-Fahrenheit table
    for cel = 0, 20, ..., 300
*/

int main()
{
    float fahr, celsius ;
    int lower, upper, step ;

    lower = 0 ;
    upper = 300 ;
    step = 20;

    celsius = lower ;

    while (celsius <= upper) {
        fahr = (9.0 / 5.0) * celsius + 32.0 ;
        printf("%3.0f %6.1f\n", celsius, fahr) ;
        celsius = celsius + step ;
    }

    return 0 ;
}