/*
 * Copyright (c) 2016-2019 The strace developers.
 * Copyright (c) 2019 Kalray
 * All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

static int
arch_set_error(struct tcb *tcp)
{
	kvx_regs.gpr_regs[0] = -tcp->u_error;
	return set_regs(tcp->pid);
}

static int
arch_set_success(struct tcb *tcp)
{
	kvx_regs.gpr_regs[0] = tcp->u_rval;
	return set_regs(tcp->pid);
}
