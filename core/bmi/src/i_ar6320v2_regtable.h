/*
 * Copyright (c) 2014, 2016-2017 The Linux Foundation. All rights reserved.
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

#ifndef _AR6320V2_DBG_REGTABLE_H_
#define _AR6320V2_DBG_REGTABLE_H_

#include "regtable.h"

#define AR6320_REV2_1_REG_SIZE 0x0007F820
#define AR6320_REV3_REG_SIZE   0x0007F820

/*
 * Redefine the register list. To minimize the size of the array, the list must
 * obey the below format. {start0, end0}, {start1, end1}, {start2, end2}.......
 * The value below must obey to "start0 < end0 < start1 < end1 < start2 < ...",
 * otherwise we may encouter error in the dump processing.
 */

static const struct tgt_reg_section ar6320v2_reg_table[] = {
	{0x800, 0x810},
	{0x820, 0x82C},
	{0x830, 0x8F4},
	{0x90C, 0x91C},
	{0xA14, 0xA18},
	{0xA84, 0xA94},
	{0xAA8, 0xAD4},
	{0xADC, 0xB40},
	{0x1000, 0x10A4},
	{0x10BC, 0x111C},
	{0x1134, 0x1138},
	{0x1144, 0x114C},
	{0x1150, 0x115C},
	{0x1160, 0x1178},
	{0x1240, 0x1260},
	{0x2000, 0x207C},
	{0x3000, 0x3014},
	{0x4000, 0x4014},
	{0x5000, 0x5124},
	{0x6000, 0x6040},
	{0x6080, 0x60CC},
	{0x6100, 0x611C},
	{0x6140, 0x61D8},
	{0x6200, 0x6238},
	{0x6240, 0x628C},
	{0x62C0, 0x62EC},
	{0x6380, 0x63E8},
	{0x6400, 0x6440},
	{0x6480, 0x64CC},
	{0x6500, 0x651C},
	{0x6540, 0x6580},
	{0x6600, 0x6638},
	{0x6640, 0x668C},
	{0x66C0, 0x66EC},
	{0x6780, 0x67E8},
	{0x7080, 0x708C},
	{0x70C0, 0x70C8},
	{0x7400, 0x741C},
	{0x7440, 0x7454},
	{0x7800, 0x7818},
	{0x8000, 0x8004},
	{0x8010, 0x8064},
	{0x8080, 0x8084},
	{0x80A0, 0x80A4},
	{0x80C0, 0x80C4},
	{0x80E0, 0x80F4},
	{0x8100, 0x8104},
	{0x8110, 0x812C},
	{0x9000, 0x9004},
	{0x9800, 0x982C},
	{0x9830, 0x9838},
	{0x9840, 0x986C},
	{0x9870, 0x9898},
	{0x9A00, 0x9C00},
	{0xD580, 0xD59C},
	{0xF000, 0xF0E0},
	{0xF140, 0xF190},
	{0xF250, 0xF25C},
	{0xF260, 0xF268},
	{0xF26C, 0xF2A8},
	{0x10008, 0x1000C},
	{0x10014, 0x10018},
	{0x1001C, 0x10020},
	{0x10024, 0x10028},
	{0x10030, 0x10034},
	{0x10040, 0x10054},
	{0x10058, 0x1007C},
	{0x10080, 0x100C4},
	{0x100C8, 0x10114},
	{0x1012C, 0x10130},
	{0x10138, 0x10144},
	{0x10200, 0x10220},
	{0x10230, 0x10250},
	{0x10260, 0x10280},
	{0x10290, 0x102B0},
	{0x102C0, 0x102DC},
	{0x102E0, 0x102F4},
	{0x102FC, 0x1037C},
	{0x10380, 0x10390},
	{0x10800, 0x10828},
	{0x10840, 0x10844},
	{0x10880, 0x10884},
	{0x108C0, 0x108E8},
	{0x10900, 0x10928},
	{0x10940, 0x10944},
	{0x10980, 0x10984},
	{0x109C0, 0x109E8},
	{0x10A00, 0x10A28},
	{0x10A40, 0x10A50},
	{0x11000, 0x11028},
	{0x11030, 0x11034},
	{0x11038, 0x11068},
	{0x11070, 0x11074},
	{0x11078, 0x110A8},
	{0x110B0, 0x110B4},
	{0x110B8, 0x110E8},
	{0x110F0, 0x110F4},
	{0x110F8, 0x11128},
	{0x11138, 0x11144},
	{0x11178, 0x11180},
	{0x111B8, 0x111C0},
	{0x111F8, 0x11200},
	{0x11238, 0x1123C},
	{0x11270, 0x11274},
	{0x11278, 0x1127C},
	{0x112B0, 0x112B4},
	{0x112B8, 0x112BC},
	{0x112F0, 0x112F4},
	{0x112F8, 0x112FC},
	{0x11338, 0x1133C},
	{0x11378, 0x1137C},
	{0x113B8, 0x113BC},
	{0x113F8, 0x113FC},
	{0x11438, 0x11440},
	{0x11478, 0x11480},
	{0x114B8, 0x114BC},
	{0x114F8, 0x114FC},
	{0x11538, 0x1153C},
	{0x11578, 0x1157C},
	{0x115B8, 0x115BC},
	{0x115F8, 0x115FC},
	{0x11638, 0x1163C},
	{0x11678, 0x1167C},
	{0x116B8, 0x116BC},
	{0x116F8, 0x116FC},
	{0x11738, 0x1173C},
	{0x11778, 0x1177C},
	{0x117B8, 0x117BC},
	{0x117F8, 0x117FC},
	{0x17000, 0x1701C},
	{0x17020, 0x170AC},
	{0x18000, 0x18050},
	{0x18054, 0x18074},
	{0x18080, 0x180D4},
	{0x180DC, 0x18104},
	{0x18108, 0x1813C},
	{0x18144, 0x18148},
	{0x18168, 0x18174},
	{0x18178, 0x18180},
	{0x181C8, 0x181E0},
	{0x181E4, 0x181E8},
	{0x181EC, 0x1820C},
	{0x1825C, 0x18280},
	{0x18284, 0x18290},
	{0x18294, 0x182A0},
	{0x18300, 0x18304},
	{0x18314, 0x18320},
	{0x18328, 0x18350},
	{0x1835C, 0x1836C},
	{0x18370, 0x18390},
	{0x18398, 0x183AC},
	{0x183BC, 0x183D8},
	{0x183DC, 0x183F4},
	{0x18400, 0x186F4},
	{0x186F8, 0x1871C},
	{0x18720, 0x18790},
	{0x19800, 0x19830},
	{0x19834, 0x19840},
	{0x19880, 0x1989C},
	{0x198A4, 0x198B0},
	{0x198BC, 0x19900},
	{0x19C00, 0x19C88},
	{0x19D00, 0x19D20},
	{0x19E00, 0x19E7C},
	{0x19E80, 0x19E94},
	{0x19E98, 0x19EAC},
	{0x19EB0, 0x19EBC},
	{0x19F70, 0x19F74},
	{0x19F80, 0x19F8C},
	{0x19FA0, 0x19FB4},
	{0x19FC0, 0x19FD8},
	{0x1A000, 0x1A200},
	{0x1A204, 0x1A210},
	{0x1A228, 0x1A22C},
	{0x1A230, 0x1A248},
	{0x1A250, 0x1A270},
	{0x1A280, 0x1A290},
	{0x1A2A0, 0x1A2A4},
	{0x1A2C0, 0x1A2EC},
	{0x1A300, 0x1A3BC},
	{0x1A3F0, 0x1A3F4},
	{0x1A3F8, 0x1A434},
	{0x1A438, 0x1A444},
	{0x1A448, 0x1A468},
	{0x1A580, 0x1A58C},
	{0x1A644, 0x1A654},
	{0x1A670, 0x1A698},
	{0x1A6AC, 0x1A6B0},
	{0x1A6D0, 0x1A6D4},
	{0x1A6EC, 0x1A70C},
	{0x1A710, 0x1A738},
	{0x1A7C0, 0x1A7D0},
	{0x1A7D4, 0x1A7D8},
	{0x1A7DC, 0x1A7E4},
	{0x1A7F0, 0x1A7F8},
	{0x1A888, 0x1A89C},
	{0x1A8A8, 0x1A8AC},
	{0x1A8C0, 0x1A8DC},
	{0x1A8F0, 0x1A8FC},
	{0x1AE04, 0x1AE08},
	{0x1AE18, 0x1AE24},
	{0x1AF80, 0x1AF8C},
	{0x1AFA0, 0x1AFB4},
	{0x1B000, 0x1B200},
	{0x1B284, 0x1B288},
	{0x1B2D0, 0x1B2D8},
	{0x1B2DC, 0x1B2EC},
	{0x1B300, 0x1B340},
	{0x1B374, 0x1B378},
	{0x1B380, 0x1B384},
	{0x1B388, 0x1B38C},
	{0x1B404, 0x1B408},
	{0x1B420, 0x1B428},
	{0x1B440, 0x1B444},
	{0x1B448, 0x1B44C},
	{0x1B450, 0x1B458},
	{0x1B45C, 0x1B468},
	{0x1B584, 0x1B58C},
	{0x1B68C, 0x1B690},
	{0x1B6AC, 0x1B6B0},
	{0x1B7F0, 0x1B7F8},
	{0x1C800, 0x1CC00},
	{0x1CE00, 0x1CE04},
	{0x1CF80, 0x1CF84},
	{0x1D200, 0x1D800},
	{0x1E000, 0x20014},
	{0x20100, 0x20124},
	{0x21400, 0x217A8},
	{0x21800, 0x21BA8},
	{0x21C00, 0x21FA8},
	{0x22000, 0x223A8},
	{0x22400, 0x227A8},
	{0x22800, 0x22BA8},
	{0x22C00, 0x22FA8},
	{0x23000, 0x233A8},
	{0x24000, 0x24034},

	/*
	 * EFUSE0,1,2 is disabled here
	 * because it's state may be reset
	 *
	 * {0x24800, 0x24804},
	 * {0x25000, 0x25004},
	 * {0x25800, 0x25804},
	 */

	{0x26000, 0x26064},
	{0x27000, 0x27024},
	{0x34000, 0x3400C},
	{0x34400, 0x3445C},
	{0x34800, 0x3485C},
	{0x34C00, 0x34C5C},
	{0x35000, 0x3505C},
	{0x35400, 0x3545C},
	{0x35800, 0x3585C},
	{0x35C00, 0x35C5C},
	{0x36000, 0x3605C},
	{0x38000, 0x38064},
	{0x38070, 0x380E0},
	{0x3A000, 0x3A064},

	/* DBI windows is skipped here, it can be only accessed when pcie
	 * is active (not in reset) and CORE_CTRL_PCIE_LTSSM_EN = 0 &&
	 * PCIE_CTRL_APP_LTSSM_ENALBE=0.
	 * {0x3C000 , 0x3C004},
	 */

	{0x40000, 0x400A4},

	/*
	 * SI register is skiped here.
	 * Because it will cause bus hang
	 *
	 * {0x50000, 0x50018},
	 */

	{0x80000, 0x8000C},
	{0x80010, 0x80020},
};

static const struct tgt_reg_section ar6320v3_reg_table[] = {
	{0x800, 0x810},
	{0x820, 0x82C},
	{0x830, 0x8F4},
	{0x90C, 0x91C},
	{0xA14, 0xA18},
	{0xA84, 0xA94},
	{0xAA8, 0xAD4},
	{0xADC, 0xB40},
	{0x1000, 0x10A4},
	{0x10BC, 0x111C},
	{0x1134, 0x1138},
	{0x1144, 0x114C},
	{0x1150, 0x115C},
	{0x1160, 0x1178},
	{0x1240, 0x1260},
	{0x2000, 0x207C},
	{0x3000, 0x3014},
	{0x4000, 0x4014},
	{0x5000, 0x5124},
	{0x6000, 0x6040},
	{0x6080, 0x60CC},
	{0x6100, 0x611C},
	{0x6140, 0x61D8},
	{0x6200, 0x6238},
	{0x6240, 0x628C},
	{0x62C0, 0x62EC},
	{0x6380, 0x63E8},
	{0x6400, 0x6440},
	{0x6480, 0x64CC},
	{0x6500, 0x651C},
	{0x6540, 0x6580},
	{0x6600, 0x6638},
	{0x6640, 0x668C},
	{0x66C0, 0x66EC},
	{0x6780, 0x67E8},
	{0x7080, 0x708C},
	{0x70C0, 0x70C8},
	{0x7400, 0x741C},
	{0x7440, 0x7454},
	{0x7800, 0x7818},
	{0x8000, 0x8004},
	{0x8010, 0x8064},
	{0x8080, 0x8084},
	{0x80A0, 0x80A4},
	{0x80C0, 0x80C4},
	{0x80E0, 0x80F4},
	{0x8100, 0x8104},
	{0x8110, 0x812C},
	{0x9000, 0x9004},
	{0x9800, 0x982C},
	{0x9830, 0x9838},
	{0x9840, 0x986C},
	{0x9870, 0x9898},
	{0x9A00, 0x9C00},
	{0xD580, 0xD59C},
	{0xF000, 0xF0E0},
	{0xF140, 0xF190},
	{0xF250, 0xF25C},
	{0xF260, 0xF268},
	{0xF26C, 0xF2A8},
	{0x10008, 0x1000C},
	{0x10014, 0x10018},
	{0x1001C, 0x10020},
	{0x10024, 0x10028},
	{0x10030, 0x10034},
	{0x10040, 0x10054},
	{0x10058, 0x1007C},
	{0x10080, 0x100C4},
	{0x100C8, 0x10114},
	{0x1012C, 0x10130},
	{0x10138, 0x10144},
	{0x10200, 0x10220},
	{0x10230, 0x10250},
	{0x10260, 0x10280},
	{0x10290, 0x102B0},
	{0x102C0, 0x102DC},
	{0x102E0, 0x102F4},
	{0x102FC, 0x1037C},
	{0x10380, 0x10390},
	{0x10800, 0x10828},
	{0x10840, 0x10844},
	{0x10880, 0x10884},
	{0x108C0, 0x108E8},
	{0x10900, 0x10928},
	{0x10940, 0x10944},
	{0x10980, 0x10984},
	{0x109C0, 0x109E8},
	{0x10A00, 0x10A28},
	{0x10A40, 0x10A50},
	{0x11000, 0x11028},
	{0x11030, 0x11034},
	{0x11038, 0x11068},
	{0x11070, 0x11074},
	{0x11078, 0x110A8},
	{0x110B0, 0x110B4},
	{0x110B8, 0x110E8},
	{0x110F0, 0x110F4},
	{0x110F8, 0x11128},
	{0x11138, 0x11144},
	{0x11178, 0x11180},
	{0x111B8, 0x111C0},
	{0x111F8, 0x11200},
	{0x11238, 0x1123C},
	{0x11270, 0x11274},
	{0x11278, 0x1127C},
	{0x112B0, 0x112B4},
	{0x112B8, 0x112BC},
	{0x112F0, 0x112F4},
	{0x112F8, 0x112FC},
	{0x11338, 0x1133C},
	{0x11378, 0x1137C},
	{0x113B8, 0x113BC},
	{0x113F8, 0x113FC},
	{0x11438, 0x11440},
	{0x11478, 0x11480},
	{0x114B8, 0x114BC},
	{0x114F8, 0x114FC},
	{0x11538, 0x1153C},
	{0x11578, 0x1157C},
	{0x115B8, 0x115BC},
	{0x115F8, 0x115FC},
	{0x11638, 0x1163C},
	{0x11678, 0x1167C},
	{0x116B8, 0x116BC},
	{0x116F8, 0x116FC},
	{0x11738, 0x1173C},
	{0x11778, 0x1177C},
	{0x117B8, 0x117BC},
	{0x117F8, 0x117FC},
	{0x17000, 0x1701C},
	{0x17020, 0x170AC},
	{0x18000, 0x18050},
	{0x18054, 0x18074},
	{0x18080, 0x180D4},
	{0x180DC, 0x18104},
	{0x18108, 0x1813C},
	{0x18144, 0x18148},
	{0x18168, 0x18174},
	{0x18178, 0x18180},
	{0x181C8, 0x181E0},
	{0x181E4, 0x181E8},
	{0x181EC, 0x1820C},
	{0x1825C, 0x18280},
	{0x18284, 0x18290},
	{0x18294, 0x182A0},
	{0x18300, 0x18304},
	{0x18314, 0x18320},
	{0x18328, 0x18350},
	{0x1835C, 0x1836C},
	{0x18370, 0x18390},
	{0x18398, 0x183AC},
	{0x183BC, 0x183D8},
	{0x183DC, 0x183F4},
	{0x18400, 0x186F4},
	{0x186F8, 0x1871C},
	{0x18720, 0x18790},
	{0x19800, 0x19830},
	{0x19834, 0x19840},
	{0x19880, 0x1989C},
	{0x198A4, 0x198B0},
	{0x198BC, 0x19900},
	{0x19C00, 0x19C88},
	{0x19D00, 0x19D20},
	{0x19E00, 0x19E7C},
	{0x19E80, 0x19E94},
	{0x19E98, 0x19EAC},
	{0x19EB0, 0x19EBC},
	{0x19F70, 0x19F74},
	{0x19F80, 0x19F8C},
	{0x19FA0, 0x19FB4},
	{0x19FC0, 0x19FD8},
	{0x1A000, 0x1A200},
	{0x1A204, 0x1A210},
	{0x1A228, 0x1A22C},
	{0x1A230, 0x1A248},
	{0x1A250, 0x1A270},
	{0x1A280, 0x1A290},
	{0x1A2A0, 0x1A2A4},
	{0x1A2C0, 0x1A2EC},
	{0x1A300, 0x1A3BC},
	{0x1A3F0, 0x1A3F4},
	{0x1A3F8, 0x1A434},
	{0x1A438, 0x1A444},
	{0x1A448, 0x1A468},
	{0x1A580, 0x1A58C},
	{0x1A644, 0x1A654},
	{0x1A670, 0x1A698},
	{0x1A6AC, 0x1A6B0},
	{0x1A6D0, 0x1A6D4},
	{0x1A6EC, 0x1A70C},
	{0x1A710, 0x1A738},
	{0x1A7C0, 0x1A7D0},
	{0x1A7D4, 0x1A7D8},
	{0x1A7DC, 0x1A7E4},
	{0x1A7F0, 0x1A7F8},
	{0x1A888, 0x1A89C},
	{0x1A8A8, 0x1A8AC},
	{0x1A8C0, 0x1A8DC},
	{0x1A8F0, 0x1A8FC},
	{0x1AE04, 0x1AE08},
	{0x1AE18, 0x1AE24},
	{0x1AF80, 0x1AF8C},
	{0x1AFA0, 0x1AFB4},
	{0x1B000, 0x1B200},
	{0x1B284, 0x1B288},
	{0x1B2D0, 0x1B2D8},
	{0x1B2DC, 0x1B2EC},
	{0x1B300, 0x1B340},
	{0x1B374, 0x1B378},
	{0x1B380, 0x1B384},
	{0x1B388, 0x1B38C},
	{0x1B404, 0x1B408},
	{0x1B420, 0x1B428},
	{0x1B440, 0x1B444},
	{0x1B448, 0x1B44C},
	{0x1B450, 0x1B458},
	{0x1B45C, 0x1B468},
	{0x1B584, 0x1B58C},
	{0x1B68C, 0x1B690},
	{0x1B6AC, 0x1B6B0},
	{0x1B7F0, 0x1B7F8},
	{0x1C800, 0x1CC00},
	{0x1CE00, 0x1CE04},
	{0x1CF80, 0x1CF84},
	{0x1D200, 0x1D800},
	{0x1E000, 0x20014},
	{0x20100, 0x20124},
	{0x21400, 0x217A8},
	{0x21800, 0x21BA8},
	{0x21C00, 0x21FA8},
	{0x22000, 0x223A8},
	{0x22400, 0x227A8},
	{0x22800, 0x22BA8},
	{0x22C00, 0x22FA8},
	{0x23000, 0x233A8},
	{0x24000, 0x24034},

	/*
	 * EFUSE0,1,2 is disabled here
	 * because it's state may be reset
	 *
	 * {0x24800, 0x24804},
	 * {0x25000, 0x25004},
	 * {0x25800, 0x25804},
	 */

	{0x26000, 0x26064},
	{0x27000, 0x27024},
	{0x34000, 0x3400C},
	{0x34400, 0x3445C},
	{0x34800, 0x3485C},
	{0x34C00, 0x34C5C},
	{0x35000, 0x3505C},
	{0x35400, 0x3545C},
	{0x35800, 0x3585C},
	{0x35C00, 0x35C5C},
	{0x36000, 0x3605C},
	{0x38000, 0x38064},
	{0x38070, 0x380E0},
	{0x3A000, 0x3A074},

	/*
	 * DBI windows is skipped here, it can be only accessed when pcie
	 * is active (not in reset) and CORE_CTRL_PCIE_LTSSM_EN = 0 &&
	 * PCIE_CTRL_APP_LTSSM_ENALBE=0.
	 * {0x3C000 , 0x3C004},
	 */

	{0x40000, 0x400A4},

	/*
	 * SI register is skiped here.
	 * Because it will cause bus hang
	 *
	 * {0x50000, 0x50018},
	 */

	{0x80000, 0x8000C},
	{0x80010, 0x80020},
};
#endif /* #ifndef _AR6320V2_DBG_REGTABLE_H_ */
