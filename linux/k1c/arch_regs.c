/*
 * Copyright (c) 2016-2019 The strace developers.
 * Copyright (c) 2019 Kalray
 * All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

static struct user_regs_struct k1c_regs;
#define ARCH_REGS_FOR_GETREGSET k1c_regs
#define ARCH_PC_REG k1c_regs.spc
#define ARCH_SP_REG k1c_regs.gpr_regs[12]
