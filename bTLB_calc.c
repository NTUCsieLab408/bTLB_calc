/**
 * This file is part of bTLB_calc.
 *
 * bTLB_calc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * bTLB_Calc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with bTLB_Calc.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdint.h>

#include "bTLB_calc.h"

uint32_t bTLB_calc_exact(uint8_t k, uint8_t l)
{
	uint8_t i;
	uint64_t nprev = k;	// each VM has one region of min allocation unit
	uint64_t cur;

	/* min allocation can't be zero */
	if(l == 0)	return 0;

	/* # of entries is limited to the number of min allocation regions */
	if(nprev > ((uint64_t)1 << (l - 1)))	return ((uint64_t)1 << (l - 1));

	/* finding the highest level which might have colored leaf nodes */
	for(i=2;i<l;i++){
		cur = (nprev + 1) / 2 + (uint64_t)k;
		if(cur > ((uint64_t)1 << (l - i)))	break;
	}

	/* total # of entries is k * # of levels have leaf nodes,
	 * except the highest level, which might have leaf nodes less than k
	 * */
	return (uint32_t)(i - 1) * (uint32_t)k + (k - (uint32_t)(cur - ((uint64_t)1 << (l - i))));
}

uint32_t bTLB_calc_fast(uint8_t k, uint8_t l)
{
	/* min allocation can't be zero */
	if(l == 0)	return 0;

	/* # of entries is limited to the number of min allocation regions */
	if(k > ((uint64_t)1 << (l - 1)))	return ((uint64_t)1 << (l - 1));

	/* upper bound is k * ceiling( l - log2(k) ).
	 * the latter term can be replaced by l - (CLZ(1) - CLZ(k)), where CLZ is # of leading zeros
	 */

	return (uint32_t)k * (l - (__builtin_clz(1) - __builtin_clz(k)));
}
