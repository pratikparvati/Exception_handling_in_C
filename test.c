/**
 * @file test.c
 * @author Pratik Parvati (pratikparvati@gmail.com)
 * @version 1.0
 */

#include <stdio.h>
#include "cexception.h"

/**
 * Divide two float numbers
 * @param a  Dividend 
 * @param b  Divisor
 * @return Division result
 */
int divide(float a, float b)
{
    TRY
    {
        if(b == 0)                                            //check for divisor
            THROW;                                            //throw exception
        printf("%f/%f = %f\n", a, b, a/b);
    }
    CATCH                                                     //handle the exception here
    {
        fprintf (stderr, "Error: "
                 "Divide by Zero Exception!! "
                 "at %s, line %d.\n", __FILE__, __LINE__);
    }
    END_TRY;
    return a/b;
}

int main()
{
    divide(5.0, 2.0);                                         // No exception
    divide(9.0, 0.0);                                         // exception
    return 0;
}