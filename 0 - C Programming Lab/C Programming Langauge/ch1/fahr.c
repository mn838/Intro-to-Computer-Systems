#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

int main()
{
    float fahr, celsuis ;
    int lower, upper, step ;

    lower = 0 ;
    upper = 300 ;
    step = 20 ;

    fahr = lower ;
    printf("####   Fahrenheit to Celsius conversion   ####\n") ;
    while (fahr <= lower) {
        celsuis = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsuis) ;
        fahr = fahr + step ;
    }

    return 0 ;
}