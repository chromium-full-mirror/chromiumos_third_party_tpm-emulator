/* Software-Based Trusted Platform Module (TPM) Emulator for Linux
 * Copyright (C) 2010 Google, Inc.
 *
 * This is a library interface to the TPM emulator.  It is used for testing
 * firmware code that talks to the emulator directly bypassing the TCG software
 * stack.  It exists mainly to make debugging easier.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * $Id$
 */

#ifndef TPMEMU_H
#define TPMEMU_H

#include <stdint.h>

/* Initialize the emulator.
 */
void tpmemu_init(void);

/* Execute a TPM command.  The request is a datagram in [in] with length
 * [in_length] bytes.  The response is returned in [out].  [pout_len] is a
 * pointer to a variable containing the maximum length of [out].  Upon return,
 * the variable is set to the actual number of bytes returned.
 */
void tpmemu_execute(uint8_t *in, uint32_t in_len,
                    uint8_t *out, uint32_t *pout_len);

#endif
