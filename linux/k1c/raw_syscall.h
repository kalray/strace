/*
 * Raw syscalls.
 *
 * Copyright (c) 2019 The strace developers.
 * Copyright (c) 2019 Kalray
 * All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#ifndef STRACE_RAW_SYSCALL_H
#define STRACE_RAW_SYSCALL_H

# include "kernel_types.h"

static inline kernel_ulong_t
raw_syscall_0(const kernel_ulong_t nr, kernel_ulong_t *err)
{
	*err = 0;
	register kernel_ulong_t r6 __asm__("r6") = nr;
	register kernel_ulong_t r0 __asm__("r0");
	__asm__ __volatile__("scall %[rSys]"
			     : "=r"(r0)
			     : [rSys] "r"(r6)
			     : "memory",
			       /* Restored by syscall in theory but better safe
			        * than sorry */
			       "r1", "r2", "r3", "r4", "r5", "r6", "r7",
			       /* Unused arguments */
			        "r8", "r9", "r10", "r11",
			       /* Struct pointer */
			       "r15",
			       /* Veneer registers */
			       "r16", "r17",
			        /* 32 -> 63 are caller-saved */
			       "r32", "r33", "r34", "r35", "r36", "r37", "r38",
			       "r39", "r40", "r41", "r42", "r43", "r44", "r45",
			       "r46", "r47", "r48", "r49", "r50", "r51", "r52",
			       "r53", "r54", "r55", "r56", "r57", "r58", "r59",
			       "r60", "r61", "r62", "r63");
	return r0;
}
# define raw_syscall_0 raw_syscall_0

#endif /* !STRACE_RAW_SYSCALL_H */
