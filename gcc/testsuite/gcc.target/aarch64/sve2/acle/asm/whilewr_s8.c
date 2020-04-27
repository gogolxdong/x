/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" { target { ! ilp32 } } } } */

#include "test_sve_acle.h"

/*
** whilewr_rr_s8:
**	whilewr	p0\.b, x0, x1
**	ret
*/
TEST_COMPARE_S (whilewr_rr_s8, const int8_t *,
		p0 = svwhilewr_s8 (x0, x1),
		p0 = svwhilewr (x0, x1))

/*
** whilewr_0r_s8:
**	whilewr	p0\.b, xzr, x1
**	ret
*/
TEST_COMPARE_S (whilewr_0r_s8, const int8_t *,
		p0 = svwhilewr_s8 ((const int8_t *) 0, x1),
		p0 = svwhilewr ((const int8_t *) 0, x1))

/*
** whilewr_cr_s8:
**	mov	(x[0-9]+), #?1073741824
**	whilewr	p0\.b, \1, x1
**	ret
*/
TEST_COMPARE_S (whilewr_cr_s8, const int8_t *,
		p0 = svwhilewr_s8 ((const int8_t *) 1073741824, x1),
		p0 = svwhilewr ((const int8_t *) 1073741824, x1))

/*
** whilewr_r0_s8:
**	whilewr	p0\.b, x0, xzr
**	ret
*/
TEST_COMPARE_S (whilewr_r0_s8, const int8_t *,
		p0 = svwhilewr_s8 (x0, (const int8_t *) 0),
		p0 = svwhilewr (x0, (const int8_t *) 0))

/*
** whilewr_rc_s8:
**	mov	(x[0-9]+), #?1073741824
**	whilewr	p0\.b, x0, \1
**	ret
*/
TEST_COMPARE_S (whilewr_rc_s8, const int8_t *,
		p0 = svwhilewr_s8 (x0, (const int8_t *) 1073741824),
		p0 = svwhilewr (x0, (const int8_t *) 1073741824))
