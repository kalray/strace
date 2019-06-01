/*
 * Copyright (c) 2016-2019 The strace developers.
 * Copyright (c) 2019 Kalray
 * All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include "negated_errno.h"

static void
arch_get_error(struct tcb *tcp, const bool check_errno)
{
	if (check_errno && is_negated_errno(k1c_regs.gpr_regs[0])) {
		tcp->u_rval = -1;
		tcp->u_error = -k1c_regs.gpr_regs[0];
	} else {
		tcp->u_rval = k1c_regs.gpr_regs[0];
	}
}
