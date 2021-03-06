/*
 * Copyright (c) 2017-2018 The strace developers.
 * All rights reserved.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "tests.h"
#include <asm/unistd.h>

#ifdef __NR_getppid

# include <stdio.h>
# include <unistd.h>

int
main(void)
{
	printf("getppid() = %ld\n", syscall(__NR_getppid));
	puts("+++ exited with 0 +++");
	return 0;
}

#else

SKIP_MAIN_UNDEFINED("__NR_getppid")

#endif
