/**
 * @file main.c
 * @brief Demonstrate the working of macros
 * @author Pratik Parvati (pratikparvati@gmail.com)
 * @version 1.0
 */

#include <stdio.h>
#include "cexception.h"

int main()
{
    TRY
    {
        printf("Inside try statement.\r\n");
        // Lets throw an exception for here!
        THROW;
        printf("This will never be printed.\r\n");
    }
    CATCH
    {
        printf("Caught exception!\r\n");
    }
    END_TRY;
    return 0;
}