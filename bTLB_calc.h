/**
 * @file
 * @author Yuan-Cheng Lee <d00944007@csie.ntu.edu.tw>
 * @version 1.0
 *
 * @section LICENSES
 *
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
 *
 * @section DESCRIPTION
 *
 * This file contains the API of bTLB_calc.
 * The API consists of two functions bTLB_calc_exact() and bTLB_calc_fast().
 */
#ifndef _BTLB_CALC_H_
#define _BTLB_CALC_H_

/**
 * Compute the exact upper bound of bTLB entries.
 *
 * @param k Number of VMs.
 * @param l Number of types of allocation chunks.
 * @return The exact upper bound of bTLB entries for \a k VMs and \a l types of allocation chunks.
 */
uint32_t bTLB_calc_exact(uint8_t k, uint8_t l);

/**
 * Compute the approximation of the upper bound of bTLB entries using a closed-form formula.
 *
 * @param k Number of VMs.
 * @param l Number of types of allocation chunks.
 * @return The approximation of the upper bound of bTLB entries for \a k VMs and \a l types of allocation chunks.
 */
uint32_t bTLB_calc_fast(uint8_t k, uint8_t l);

#endif /* _BTLB_CALC_H_ */
