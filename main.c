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

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "bTLB_calc.h"

int main(int argc, char* argv[])
{
	uint8_t i, to;

	if(argc != 4){
		fprintf(stderr, "Usage: %s num_VMs num_chunk_types_from num_chunk_types_to\n", argv[0]);
		return 1;
	}
	
	to = (uint8_t)atoi(argv[1]);
	to = (uint8_t)atoi(argv[3]);

	fprintf(stdout, "# of VMs\tExact\tFast\n");

	for(i=(uint8_t)atoi(argv[2]);i<=to;i++){
		fprintf(stdout, "%8u\t%5u\t%4u\n", i, bTLB_calc_exact(5, i), bTLB_calc_fast(5, i));
	}

	return 0;
}
