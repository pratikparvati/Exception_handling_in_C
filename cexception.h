/**
 * @file cexcepton.h
 * @author Pratik Parvati (pratikparvati@gmail.com)
 * @version 1.0
 */

#pragma once

#include <setjmp.h>  

// Exception preprocessor macros
#define TRY do{                       \
                 jmp_buf buf;         \
                 if( !setjmp(buf) )   \
                 {    
#define CATCH }                       \
              else                    \
              {                       

#define END_TRY }                     \
                   }while(0)  

#define THROW longjmp(buf, 1)



