/* { dg-do compile } */
/* { dg-options "-O2" } */

#include <arm_sve.h>

void
test1 (int *last, svbool_t *ptr)
{
  svbool_t res = svptrue_pat_b8 (SV_VL32);
  *last = svptest_last (svptrue_b8 (), res);
  *ptr = res;
}

int
test2 ()
{
  svbool_t res = svptrue_pat_b8 (SV_VL32);
  return svptest_last (svptrue_b8 (), res);
}

/* { dg-final { scan-assembler-times {\tptrues\tp[0-9]+\.b, vl32\n} 2 } } */
/* { dg-final { scan-assembler-not {\tptrue\t} { xfail *-*-* } } } */
/* { dg-final { scan-assembler-not {\tptest\t} } } */
