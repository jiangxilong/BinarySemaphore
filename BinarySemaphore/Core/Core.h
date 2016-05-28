#ifndef CORE_H
#define CORE_H

#include "Core/CoreData.h"
#include "Core/CoreFunctions.h"

/*
======================================================================
Function Declarations
======================================================================
*/
void core_init(void);
void core_exit(void);

/*
======================================================================
Function Implementations
======================================================================
*/
void core_init(void)
{
   console_init();
   coreFunctios_init();
}

void core_exit(void)
{
   coreFunctios_exit();
}

#endif /*CORE_H*/
