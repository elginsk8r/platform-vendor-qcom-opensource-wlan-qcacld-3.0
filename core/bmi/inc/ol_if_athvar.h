/*
 * Copyright (c) 2014 The Linux Foundation. All rights reserved.
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

/*
 * Defintions for the Atheros Wireless LAN controller driver.
 */
#ifndef _DEV_OL_ATH_ATHVAR_H
#define _DEV_OL_ATH_ATHVAR_H

#include <osapi_linux.h>
#include "cdf_types.h"
#include "cdf_lock.h"
#include "wmi_unified_api.h"
#include "htc_api.h"
#include "bmi_msg.h"
#include "ol_txrx_api.h"
#include "ol_txrx_ctrl_api.h"
#include "ol_txrx_osif_api.h"
#include "ol_params.h"
#include <wdi_event_api.h>

#ifdef CONFIG_CNSS
#include <net/cnss.h>
#endif

#include "ol_ctrl_addba_api.h"
typedef void *hif_handle_t;

struct ol_version {
	uint32_t host_ver;
	uint32_t target_ver;
	uint32_t wlan_ver;
	uint32_t wlan_ver_1;
	uint32_t abi_ver;
};

typedef enum _ol_target_status {
	OL_TRGET_STATUS_CONNECTED = 0,  /* target connected */
	OL_TRGET_STATUS_RESET,  /* target got reset */
	OL_TRGET_STATUS_EJECT,  /* target got ejected */
	OL_TRGET_STATUS_SUSPEND /*target got suspend */
} ol_target_status;

enum ol_ath_tx_ecodes {
	TX_IN_PKT_INCR = 0,
	TX_OUT_HDR_COMPL,
	TX_OUT_PKT_COMPL,
	PKT_ENCAP_FAIL,
	TX_PKT_BAD,
	RX_RCV_MSG_RX_IND,
	RX_RCV_MSG_PEER_MAP,
	RX_RCV_MSG_TYPE_TEST
};

/*
 * structure to hold the packet error count for CE and hif layer
 */
struct ol_ath_stats {
	int hif_pipe_no_resrc_count;
	int ce_ring_delta_fail_count;
};

#endif /* _DEV_OL_ATH_ATHVAR_H  */
