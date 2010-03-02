/* Software-Based Trusted Platform Module (TPM) Emulator for Linux
 * Copyright (C) 2010 Google, Inc.
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

#include "tpmemu.h"

/* Gets all the extra functions we need and gets rid of duplicate "main".
 *
 * TODO: this is the simplest change that achieves this functionality.
 * I am sending it back to Mario to have it integrated better.
 */
#define main very_sorry_about_this
#include "tpmd.c"

#include <tss/tcs.h>

void tpmemu_execute(uint8_t *in, uint32_t in_len,
                    uint8_t *out, uint32_t *pout_len)
{
    if (in_len <= 0) {
        error("invalid command length (%d)", in_len);
    } else {
        uint8_t *result = NULL;
        uint32_t result_len;
        int res;
        res = tpm_handle_command(in, in_len, &result, &result_len);
        if (res < 0) {
            error("tpm_handle_command() failed");
        } else {
            debug("received %d bytes", result_len);
            if (result_len >= *pout_len) {
                error("tpm result too large for output buffer");
            } else {
                *pout_len = result_len;
                memmove(out, result, result_len);
            }
            tpm_free(result);
        }
    }
}

void tpmemu_init(void)
{
    info("initializing TPM Emulator (1.2.%d.%d)", VERSION_MAJOR, VERSION_MINOR);

    init_random();
    mkdirs(opt_storage_file);
    debug("initializing TPM emulator: %d", tpm_startup);
    tpm_emulator_init(TPM_ST_CLEAR, 0);
}


