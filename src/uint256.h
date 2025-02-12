/*******************************************************************************
 *   Ledger Ethereum App
 *   (c) 2016-2019 Ledger
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/

// Adapted from https://github.com/calccrypto/uint256_t

#ifndef _UINT256_H_
#define _UINT256_H_

#include <stdint.h>
#include <stdbool.h>
#include "os.h"
#include "cx.h"

typedef struct uint128_t {
    uint64_t elements[2];
} uint128_t;

typedef struct uint256_t {
    uint128_t elements[2];
} uint256_t;

_Static_assert(sizeof(uint128_t) == 128 / 8, "128 bit unsigned is wrong size");
_Static_assert(sizeof(uint256_t) == 256 / 8, "256 bit unsigned is wrong size");

_Static_assert(_Alignof(uint128_t) == 8, "128 bit unsigned is wrong alignment");
_Static_assert(_Alignof(uint256_t) == 8, "256 bit unsigned is wrong alignment");

#define UPPER_P(x) x->elements[0]
#define LOWER_P(x) x->elements[1]
#define UPPER(x)   x.elements[0]
#define LOWER(x)   x.elements[1]

void readu128BE(const uint8_t *buffer, uint128_t *target);
void readu256BE(const uint8_t *buffer, uint256_t *target);
bool zero128(const uint128_t *number);
bool zero256(const uint256_t *number);
void copy128(uint128_t *target, const uint128_t *number);
void copy256(uint256_t *target, const uint256_t *number);
void clear128(uint128_t *target);
void clear256(uint256_t *target);
void shiftl128(const uint128_t *number, const uint32_t value, uint128_t *target);
void shiftr128(const uint128_t *number, const uint32_t value, uint128_t *target);
void shiftl256(const uint256_t *number, const uint32_t value, uint256_t *target);
void shiftr256(const uint256_t *number, const uint32_t value, uint256_t *target);
uint32_t bits128(const uint128_t *number);
uint32_t bits256(const uint256_t *number);
bool equal128(const uint128_t *number1, const uint128_t *number2);
bool equal256(const uint256_t *number1, const uint256_t *number2);
bool gt128(const uint128_t *number1, const uint128_t *number2);
bool gt256(const uint256_t *number1, const uint256_t *number2);
bool gte128(const uint128_t *number1, const uint128_t *number2);
bool gte256(const uint256_t *number1, const uint256_t *number2);
void add128(const uint128_t *number1, const uint128_t *number2, uint128_t *target);
void add256(const uint256_t *number1, const uint256_t *number2, uint256_t *target);
void minus128(const uint128_t *number1, const uint128_t *number2, uint128_t *target);
void minus256(const uint256_t *number1, const uint256_t *number2, uint256_t *target);
void or128(const uint128_t *number1, const uint128_t *number2, uint128_t *target);
void or256(const uint256_t *number1, const uint256_t *number2, uint256_t *target);
void mul128(const uint128_t *number1, const uint128_t *number2, uint128_t *target);
void mul256(const uint256_t *number1, const uint256_t *number2, uint256_t *target);
void divmod128(const uint128_t *l, const uint128_t *r, uint128_t *div, uint128_t *mod);
void divmod256(const uint256_t *l, const uint256_t *r, uint256_t *div, uint256_t *mod);
size_t tostring128(const uint128_t *number, size_t base, char *out, size_t outLength);
size_t tostring256(const uint256_t *number, size_t base, char *out, size_t outLength);
size_t tostring256_fixed_point(const uint256_t *number, size_t baseParam, size_t digits_of_resolution, char *out, size_t outLength);

#endif /* _UINT256_H_ */
