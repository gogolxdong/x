/* { dg-do compile } */
/* { dg-options "-O3 -march=z14 -mzvector -mzarch" } */

#include "autovec.h"

AUTOVEC_FLOAT (SIGNALING_LE);

/* { dg-final { scan-assembler {\n\tvfkhesb\t} } } */
