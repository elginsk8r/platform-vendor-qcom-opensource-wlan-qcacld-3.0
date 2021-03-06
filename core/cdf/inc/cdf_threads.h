/*
 * Copyright (c) 2014-2015 The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * This file was originally distributed by Qualcomm Atheros, Inc.
 * under proprietary terms before Copyright ownership was assigned
 * to the Linux Foundation.
 */

#if !defined(__CDF_THREADS_H)
#define __CDF_THREADS_H

/**
 * DOC:  cdf_threads
 *
 * Connectivity driver framework (CDF) thread related APIs
 *
 */

/* Include Files */
#include <cdf_types.h>

/* Preprocessor definitions and constants */

/* Type declarations */

/* Function declarations and documenation */

/**
 *  cdf_sleep() - sleep
 *  @msInterval : Number of milliseconds to suspend the current thread.
 *  A value of 0 may or may not cause the current thread to yield.
 *
 *  This function suspends the execution of the current thread
 *  until the specified time out interval elapses.
 *
 *  Return: nothing
 */
void cdf_sleep(uint32_t msInterval);

/**
 *  cdf_sleep_us() - sleep
 *  @usInterval : Number of microseconds to suspend the current thread.
 *  A value of 0 may or may not cause the current thread to yield.
 *
 *  This function suspends the execution of the current thread
 *  until the specified time out interval elapses.
 *
 *  Return : nothing
 */
void cdf_sleep_us(uint32_t usInterval);

/**
 *  cdf_busy_wait() - busy wait
 *  @usInterval : Number of microseconds to busy wait.
 *
 *  This function places the current thread in busy wait until the specified
 *  time out interval elapses. If the interval is greater than 50us on WM, the
 *  behaviour is undefined.
 *
 *  Return : nothing
 */
void cdf_busy_wait(uint32_t usInterval);

#endif /* __CDF_THREADS_H */
