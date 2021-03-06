#ifndef COREFUNCTIONS_H
#define COREFUNCTIONS_H

/*
======================================================================
Includes
======================================================================
*/
#include "Core/Console.h"
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>

/*
======================================================================
Preprocessor
======================================================================
*/
#define deallocate(p) \
   Deallocate( (void **) p)

/*
======================================================================
Data
======================================================================
*/
typedef enum ComparisonType
{
   DifferentFrom, EqualTo,
   GreaterThan, LessThan,
   GreaterOrEqual, LessOrEqual
} ComparisonType;

/*
======================================================================
Function Declarations
======================================================================
*/
void Deallocate(void **p);
int getRandom(int min, int max);
bool compareValue(const double number1, const ComparisonType type,
                  const double number2);
void coreFunctios_init(void);
void coreFunctios_exit(void);

/*
======================================================================
Function Implementations
======================================================================
*/
void Deallocate(void **p)
{
   free(*p);
   *p = NULL;
}

int getRandom(int min, int max)
{
   int range = max - min + 1;
   if(range == 0)
      return min;
   else
      return rand()%range + min;
}

bool compareValue(const double number1, const ComparisonType type,
                  const double number2)
{
   switch(type)
   {
      case EqualTo: return fabs(number1 - number2) < DBL_EPSILON;
      case DifferentFrom: return !compareValue(number1, EqualTo, number2);
      case LessThan: return compareValue(number1, DifferentFrom, number2)
               && number1 < number2;
      case GreaterThan: return compareValue(number1, DifferentFrom, number2)
               && number1 > number2;
      case LessOrEqual: return compareValue(number1, LessThan, number2)
               || compareValue(number1, EqualTo, number2);
      case GreaterOrEqual: return compareValue(number1, GreaterThan, number2)
               || compareValue(number1, EqualTo, number2);
      default: return false;
   }
}

void coreFunctios_init(void)
{
   time_t t;
   srand((unsigned) time(&t));
}

void coreFunctios_exit(void)
{
#if Borland502
   pause_Ln(2u);
#endif
}

#endif /*COREFUNCTIONS_H*/
