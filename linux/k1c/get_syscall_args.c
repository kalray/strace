/*
 * Copyright (c) 2016-2019 The strace developers.
 * Copyright (c) 2019 Kalray
 * All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

/* Return -1 on error or 1 on success (never 0!). */
static int
arch_get_syscall_args(struct tcb *tcp)
{
	tcp->u_arg[0] = k1c_regs.gpr_regs[0];
	tcp->u_arg[1] = k1c_regs.gpr_regs[1];
	tcp->u_arg[2] = k1c_regs.gpr_regs[2];
	tcp->u_arg[3] = k1c_regs.gpr_regs[3];
	tcp->u_arg[4] = k1c_regs.gpr_regs[4];
	tcp->u_arg[5] = k1c_regs.gpr_regs[5];

	return 1;
}
