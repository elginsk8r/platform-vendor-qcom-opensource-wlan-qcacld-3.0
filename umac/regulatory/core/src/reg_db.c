/*
 * Copyright (c) 2017-2018 The Linux Foundation. All rights reserved.
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

/**
 * DOC: reg_db.c
 * This file provides regulatory data base
 */

#include <qdf_types.h>
#include <qdf_trace.h>
#include "reg_db.h"

enum country_code {
	CTRY_AFGHANISTAN = 4,
	CTRY_ALBANIA = 8,
	CTRY_ALGERIA = 12,
	CTRY_AMERICAN_SAMOA = 16,
	CTRY_ANGUILLA = 660,
	CTRY_ARGENTINA = 32,
	CTRY_ARMENIA = 51,
	CTRY_ARUBA = 533,
	CTRY_AUSTRALIA = 36,
	CTRY_AUSTRIA = 40,
	CTRY_AZERBAIJAN = 31,
	CTRY_BAHAMAS = 44,
	CTRY_BAHRAIN = 48,
	CTRY_BANGLADESH = 50,
	CTRY_BARBADOS = 52,
	CTRY_BELARUS = 112,
	CTRY_BELGIUM = 56,
	CTRY_BELIZE = 84,
	CTRY_BERMUDA = 60,
	CTRY_BHUTAN = 64,
	CTRY_BOLIVIA = 68,
	CTRY_BOSNIA_HERZ = 70,
	CTRY_BRAZIL = 76,
	CTRY_BRUNEI_DARUSSALAM = 96,
	CTRY_BULGARIA = 100,
	CTRY_BURKINA_FASO = 854,
	CTRY_CAMBODIA = 116,
	CTRY_CANADA = 124,
	CTRY_CAYMAN_ISLANDS = 136,
	CTRY_CENTRAL_AFRICA_REPUBLIC = 140,
	CTRY_CHAD = 148,
	CTRY_CHILE = 152,
	CTRY_CHINA = 156,
	CTRY_CHRISTMAS_ISLAND = 162,
	CTRY_COLOMBIA = 170,
	CTRY_COSTA_RICA = 188,
	CTRY_COTE_DIVOIRE = 384,
	CTRY_CROATIA = 191,
	CTRY_CYPRUS = 196,
	CTRY_CZECH = 203,
	CTRY_DENMARK = 208,
	CTRY_DOMINICA = 212,
	CTRY_DOMINICAN_REPUBLIC = 214,
	CTRY_ECUADOR = 218,
	CTRY_EGYPT = 818,
	CTRY_EL_SALVADOR = 222,
	CTRY_ESTONIA = 233,
	CTRY_ETHIOPIA = 231,
	CTRY_FINLAND = 246,
	CTRY_FRANCE = 250,
	CTRY_FRENCH_GUIANA = 254,
	CTRY_FRENCH_POLYNESIA = 258,
	CTRY_GEORGIA = 268,
	CTRY_GERMANY = 276,
	CTRY_GHANA = 288,
	CTRY_GIBRALTAR = 292,
	CTRY_GREECE = 300,
	CTRY_GREENLAND = 304,
	CTRY_GRENADA = 308,
	CTRY_GUADELOUPE = 312,
	CTRY_GUAM = 316,
	CTRY_GUATEMALA = 320,
	CTRY_GUYANA = 328,
	CTRY_HAITI = 332,
	CTRY_HONDURAS = 340,
	CTRY_HONG_KONG = 344,
	CTRY_HUNGARY = 348,
	CTRY_ICELAND = 352,
	CTRY_INDIA = 356,
	CTRY_INDONESIA = 360,
	CTRY_IRAQ = 368,
	CTRY_IRELAND = 372,
	CTRY_ISRAEL = 376,
	CTRY_ITALY = 380,
	CTRY_JAMAICA = 388,
	CTRY_JORDAN = 400,
	CTRY_KAZAKHSTAN = 398,
	CTRY_KENYA = 404,
	CTRY_KOREA_ROC = 410,
	CTRY_KUWAIT = 414,
	CTRY_LATVIA = 428,
	CTRY_LEBANON = 422,
	CTRY_LESOTHO = 426,
	CTRY_LIECHTENSTEIN = 438,
	CTRY_LITHUANIA = 440,
	CTRY_LUXEMBOURG = 442,
	CTRY_MACAU = 446,
	CTRY_MACEDONIA = 807,
	CTRY_MALAWI = 454,
	CTRY_MALAYSIA = 458,
	CTRY_MALDIVES = 462,
	CTRY_MALTA = 470,
	CTRY_MARSHALL_ISLANDS = 584,
	CTRY_MARTINIQUE = 474,
	CTRY_MAURITANIA = 478,
	CTRY_MAURITIUS = 480,
	CTRY_MAYOTTE = 175,
	CTRY_MEXICO = 484,
	CTRY_MICRONESIA = 583,
	CTRY_MOLDOVA = 498,
	CTRY_MONACO = 492,
	CTRY_MONGOLIA = 496,
	CTRY_MONTENEGRO = 499,
	CTRY_MOROCCO = 504,
	CTRY_NAMIBIA = 516,
	CTRY_NEPAL = 524,
	CTRY_NETHERLANDS = 528,
	CTRY_NETHERLANDS_ANTILLES = 530,
	CTRY_NEW_ZEALAND = 554,
	CTRY_NIGERIA = 566,
	CTRY_NORTHERN_MARIANA_ISLANDS = 580,
	CTRY_NICARAGUA = 558,
	CTRY_NORWAY = 578,
	CTRY_OMAN = 512,
	CTRY_PAKISTAN = 586,
	CTRY_PALAU = 585,
	CTRY_PANAMA = 591,
	CTRY_PAPUA_NEW_GUINEA = 598,
	CTRY_PARAGUAY = 600,
	CTRY_PERU = 604,
	CTRY_PHILIPPINES = 608,
	CTRY_POLAND = 616,
	CTRY_PORTUGAL = 620,
	CTRY_PUERTO_RICO = 630,
	CTRY_QATAR = 634,
	CTRY_REUNION = 638,
	CTRY_ROMANIA = 642,
	CTRY_RUSSIA = 643,
	CTRY_RWANDA = 646,
	CTRY_SAINT_BARTHELEMY = 652,
	CTRY_SAINT_KITTS_AND_NEVIS = 659,
	CTRY_SAINT_LUCIA = 662,
	CTRY_SAINT_MARTIN = 663,
	CTRY_SAINT_PIERRE_AND_MIQUELON = 666,
	CTRY_SAINT_VINCENT_AND_THE_GRENADIENS = 670,
	CTRY_SAMOA = 882,
	CTRY_SAUDI_ARABIA = 682,
	CTRY_SENEGAL = 686,
	CTRY_SERBIA = 688,
	CTRY_SINGAPORE = 702,
	CTRY_SLOVAKIA = 703,
	CTRY_SLOVENIA = 705,
	CTRY_SOUTH_AFRICA = 710,
	CTRY_SPAIN = 724,
	CTRY_SURINAME = 740,
	CTRY_SRI_LANKA = 144,
	CTRY_SWEDEN = 752,
	CTRY_SWITZERLAND = 756,
	CTRY_TAIWAN = 158,
	CTRY_TANZANIA = 834,
	CTRY_THAILAND = 764,
	CTRY_TOGO = 768,
	CTRY_TRINIDAD_Y_TOBAGO = 780,
	CTRY_TUNISIA = 788,
	CTRY_TURKEY = 792,
	CTRY_TURKS_AND_CAICOS = 796,
	CTRY_UGANDA = 800,
	CTRY_UKRAINE = 804,
	CTRY_UAE = 784,
	CTRY_UNITED_KINGDOM = 826,
	CTRY_UNITED_STATES = 840,
	CTRY_URUGUAY = 858,
	CTRY_UZBEKISTAN = 860,
	CTRY_VANUATU = 548,
	CTRY_VENEZUELA = 862,
	CTRY_VIET_NAM = 704,
	CTRY_VIRGIN_ISLANDS = 850,
	CTRY_WALLIS_AND_FUTUNA = 876,
	CTRY_YEMEN = 887,
	CTRY_ZIMBABWE = 716,
	CTRY_JAPAN = 392,
	CTRY_JAPAN15 = 4015,
	CTRY_XA = 4100,
};

enum reg_domain {
	NULL1_WORLD = 0x03,

	FCC1_FCCA = 0x10,
	FCC1_WORLD = 0x11,
	FCC2_FCCA = 0x20,
	FCC2_WORLD = 0x21,
	FCC2_ETSIC = 0x22,
	FCC3_FCCA = 0x3A,
	FCC3_WORLD = 0x3B,
	FCC3_ETSIC = 0x3F,
	FCC4_FCCA = 0x12,
	FCC5_FCCA = 0x13,
	FCC6_WORLD = 0x23,
	FCC6_FCCA = 0x14,
	FCC8_FCCA = 0x16,
	FCC11_WORLD = 0x19,
	FCC13_WORLD = 0xE4,
	FCC14_FCCB = 0xE6,

	ETSI1_WORLD = 0x37,
	ETSI3_WORLD = 0x36,
	ETSI4_WORLD = 0x30,
	ETSI8_WORLD = 0x3D,
	ETSI9_WORLD = 0x3E,
	ETSI11_WORLD = 0x26,
	ETSI12_WORLD = 0x28,
	ETSI13_WORLD = 0x27,
	ETSI14_WORLD = 0x29,

	APL1_WORLD = 0x52,
	APL1_ETSIC = 0x55,
	APL2_WORLD = 0x45,
	APL2_ETSIC = 0x56,
	APL4_WORLD = 0x42,
	APL6_WORLD = 0x5B,
	APL8_WORLD = 0x5D,
	APL9_WORLD = 0x5E,
	APL10_WORLD = 0x5F,
	APL11_FCCA = 0x4F,
	APL12_WORLD = 0x51,
	APL13_WORLD = 0x5A,
	APL14_WORLD = 0x57,
	APL15_WORLD = 0x59,
	APL16_WORLD = 0x70,
	APL17_ETSID = 0xE0,
	APL19_ETSIC = 0x71,
	APL20_WORLD = 0xE5,
	APL23_WORLD = 0xE3,

	MKK3_MKKC = 0x82,
	MKK5_MKKA = 0x99,
	MKK5_MKKC = 0x88,
	MKK11_MKKC = 0xD7,
	MKK16_MKKC = 0xDF,

	WORLD_60 = 0x60,
	WORLD_61 = 0x61,
	WORLD_62 = 0x62,
	WORLD_63 = 0x63,
	WORLD_65 = 0x65,
	WORLD_64 = 0x64,
	WORLD_66 = 0x66,
	WORLD_69 = 0x69,
	WORLD_67 = 0x67,
	WORLD_68 = 0x68,
	WORLD_6A = 0x6A,
	WORLD_6C = 0x6C,
};

#ifndef CONFIG_MCL_REGDB
const struct country_code_to_reg_domain g_all_countries[] = {
	{CTRY_AFGHANISTAN, ETSI1_WORLD, "AF", 40, 160, 0},
	{CTRY_ALBANIA, ETSI1_WORLD, "AL", 40, 160, 0},
	{CTRY_ALGERIA, APL13_WORLD, "DZ", 40, 160, 0},
	{CTRY_AMERICAN_SAMOA, FCC3_FCCA, "AS", 40, 160, 0},
	{CTRY_ANGUILLA, ETSI1_WORLD, "AI", 40, 160, 0},
	{CTRY_ARGENTINA, APL16_WORLD, "AR", 40, 160, 0},
	{CTRY_ARMENIA, ETSI4_WORLD, "AM", 40, 20, 0},
	{CTRY_ARUBA, ETSI1_WORLD, "AW", 40, 160, 0},
	{CTRY_AUSTRALIA, FCC6_WORLD, "AU", 40, 160, 0},
	{CTRY_AUSTRIA, ETSI1_WORLD, "AT", 40, 160, 0},
	{CTRY_AZERBAIJAN, ETSI4_WORLD, "AZ", 40, 160, 0},
	{CTRY_BAHAMAS, FCC3_WORLD, "BS", 40, 160, 0},
	{CTRY_BAHRAIN, APL15_WORLD, "BH", 40, 20, 0},
	{CTRY_BANGLADESH, APL1_WORLD, "BD", 40, 160, 0},
	{CTRY_BARBADOS, FCC2_WORLD, "BB", 40, 160, 0},
	{CTRY_BELARUS, ETSI1_WORLD, "BY", 40, 160, 0},
	{CTRY_BELGIUM, ETSI1_WORLD, "BE", 40, 160, 0},
	{CTRY_BELIZE, ETSI8_WORLD, "BZ", 40, 160, 0},
	{CTRY_BERMUDA, FCC3_FCCA, "BM", 40, 160, 0},
	{CTRY_BHUTAN, ETSI1_WORLD, "BT", 40, 160, 0},
	{CTRY_BOLIVIA, APL8_WORLD, "BO", 40, 160, 0},
	{CTRY_BOSNIA_HERZ, ETSI1_WORLD, "BA", 40, 160, 0},
	{CTRY_BRAZIL, FCC3_ETSIC, "BR", 40, 160, 0},
	{CTRY_BRUNEI_DARUSSALAM, APL6_WORLD, "BN", 40, 160, 0},
	{CTRY_BULGARIA, ETSI1_WORLD, "BG", 40, 160, 0},
	{CTRY_BURKINA_FASO, FCC3_WORLD, "BF", 40, 160, 0},
	{CTRY_CAMBODIA, ETSI1_WORLD, "KH", 40, 160, 0},
	{CTRY_CANADA, FCC6_FCCA, "CA", 40, 160, 0},
	{CTRY_CAYMAN_ISLANDS, FCC3_WORLD, "KY", 40, 160, 0},
	{CTRY_CENTRAL_AFRICA_REPUBLIC, FCC3_WORLD, "CF", 40, 40, 0},
	{CTRY_CHAD, ETSI1_WORLD, "TD", 40, 160, 0},
	{CTRY_CHILE, APL23_WORLD, "CL", 40, 160, 0},
	{CTRY_CHINA, APL14_WORLD, "CN", 40, 160, 0},
	{CTRY_CHRISTMAS_ISLAND, FCC3_WORLD, "CX", 40, 160, 0},
	{CTRY_COLOMBIA, FCC3_WORLD, "CO", 40, 160, 0},
	{CTRY_COSTA_RICA, FCC3_WORLD, "CR", 40, 20, 0},
	{CTRY_COTE_DIVOIRE, FCC3_WORLD, "CI", 40, 160, 0},
	{CTRY_CROATIA, ETSI1_WORLD, "HR", 40, 160, 0},
	{CTRY_CYPRUS, ETSI1_WORLD, "CY", 40, 160, 0},
	{CTRY_CZECH, ETSI1_WORLD, "CZ", 40, 160, 0},
	{CTRY_DENMARK, ETSI1_WORLD, "DK", 40, 160,  0},
	{CTRY_DOMINICA, FCC1_FCCA, "DM", 40, 160, 0},
	{CTRY_DOMINICAN_REPUBLIC, FCC1_FCCA, "DO", 40, 160, 0},
	{CTRY_ECUADOR, FCC3_WORLD, "EC", 40, 20, 0},
	{CTRY_EGYPT, ETSI3_WORLD, "EG", 40, 160, 0},
	{CTRY_EL_SALVADOR, FCC1_WORLD, "SV", 40, 20, 0},
	{CTRY_ESTONIA, ETSI1_WORLD, "EE", 40, 160, 0},
	{CTRY_ETHIOPIA, ETSI1_WORLD, "ET", 40, 160, 0},
	{CTRY_FINLAND, ETSI1_WORLD, "FI", 40, 160, 0},
	{CTRY_FRANCE, ETSI1_WORLD, "FR", 40, 160, 0},
	{CTRY_FRENCH_GUIANA, ETSI1_WORLD, "GF", 40, 160, 0},
	{CTRY_FRENCH_POLYNESIA, ETSI1_WORLD, "PF", 40, 160, 0},
	{CTRY_GEORGIA, ETSI4_WORLD, "GE", 40, 160, 0},
	{CTRY_GERMANY, ETSI1_WORLD, "DE", 40, 160, 0},
	{CTRY_GHANA, FCC3_WORLD, "GH", 40, 160, 0},
	{CTRY_GIBRALTAR, ETSI1_WORLD, "GI", 40, 160, 0},
	{CTRY_GREECE, ETSI1_WORLD, "GR", 40, 160, 0},
	{CTRY_GREENLAND, ETSI1_WORLD, "GL", 40, 160, 0},
	{CTRY_GRENADA, FCC3_FCCA, "GD", 40, 160, 0},
	{CTRY_GUADELOUPE, ETSI1_WORLD, "GP", 40, 160, 0},
	{CTRY_GUAM, FCC3_FCCA, "GU", 40, 160, 0},
	{CTRY_GUATEMALA, ETSI1_WORLD, "GT", 40, 160, 0},
	{CTRY_GUYANA, APL1_ETSIC, "GY", 40, 160, 0},
	{CTRY_HAITI, FCC3_FCCA, "HT", 40, 160, 0},
	{CTRY_HONDURAS, FCC3_WORLD, "HN", 40, 160, 0},
	{CTRY_HONG_KONG, FCC3_WORLD, "HK", 40, 160, 0},
	{CTRY_HUNGARY, ETSI1_WORLD, "HU", 40, 160, 0},
	{CTRY_ICELAND, ETSI1_WORLD, "IS", 40, 160, 0},
	{CTRY_INDIA, APL15_WORLD, "IN", 40, 160, 0},
	{CTRY_INDONESIA, APL2_ETSIC, "ID", 40, 20, 0},
	{CTRY_IRAQ, ETSI1_WORLD, "IQ", 40, 160, 0},
	{CTRY_IRELAND, ETSI1_WORLD, "IE", 40, 160, 0},
	{CTRY_ISRAEL, ETSI3_WORLD, "IL", 40, 160, 0},
	{CTRY_ITALY, ETSI1_WORLD, "IT", 40, 160,  0},
	{CTRY_JAMAICA, FCC13_WORLD, "JM", 40, 160, 0},
	{CTRY_JORDAN, APL4_WORLD, "JO", 40, 160, 0},
	{CTRY_KAZAKHSTAN, NULL1_WORLD, "KZ", 40, 0, 0},
	{CTRY_KENYA, APL12_WORLD, "KE", 40, 160, 0},
	{CTRY_KOREA_ROC, APL9_WORLD, "KR", 40, 160, 0},
	{CTRY_KUWAIT, ETSI3_WORLD, "KW", 40, 160, 0},
	{CTRY_LATVIA, ETSI1_WORLD, "LV", 40, 160, 0},
	{CTRY_LEBANON, FCC3_WORLD, "LB", 40, 160, 0},
	{CTRY_LESOTHO, ETSI1_WORLD, "LS", 40, 160, 0},
	{CTRY_LIECHTENSTEIN, ETSI1_WORLD, "LI", 40, 160, 0},
	{CTRY_LITHUANIA, ETSI1_WORLD, "LT", 40, 160, 0},
	{CTRY_LUXEMBOURG, ETSI1_WORLD, "LU", 40, 160, 0},
	{CTRY_MACAU, FCC3_WORLD, "MO", 40, 160, 0},
	{CTRY_MACEDONIA, ETSI1_WORLD, "MK", 40, 160, 0},
	{CTRY_MALAWI, ETSI1_WORLD, "MW", 40, 160, 0},
	{CTRY_MALAYSIA, FCC11_WORLD, "MY", 40, 160, 0},
	{CTRY_MALDIVES, APL6_WORLD, "MV", 40, 160, 0},
	{CTRY_MALTA, ETSI1_WORLD, "MT", 40, 160, 0},
	{CTRY_MARSHALL_ISLANDS, FCC3_FCCA, "MH", 40, 160, 0},
	{CTRY_MARTINIQUE, ETSI1_WORLD, "MQ", 40, 160, 0},
	{CTRY_MAURITANIA, ETSI1_WORLD, "MR", 40, 160, 0},
	{CTRY_MAURITIUS, ETSI1_WORLD, "MU", 40, 160, 0},
	{CTRY_MAYOTTE, ETSI1_WORLD, "YT", 40, 160, 0},
	{CTRY_MEXICO, FCC3_ETSIC, "MX", 40, 160, 0},
	{CTRY_MICRONESIA, FCC3_FCCA, "FM", 40, 160, 0},
	{CTRY_MOLDOVA, ETSI1_WORLD, "MD", 40, 160, 0},
	{CTRY_MONACO, ETSI1_WORLD, "MC", 40, 160, 0},
	{CTRY_MONGOLIA, FCC3_WORLD, "MN", 40, 160, 0},
	{CTRY_MONTENEGRO, ETSI1_WORLD, "ME", 40, 160, 0},
	{CTRY_MOROCCO, ETSI3_WORLD, "MA", 40, 160, 0},
	{CTRY_NAMIBIA, APL20_WORLD, "NA", 40, 160, 0},
	{CTRY_NEPAL, APL23_WORLD, "NP", 40, 160, 0},
	{CTRY_NETHERLANDS, ETSI1_WORLD, "NL", 40, 160, 0},
	{CTRY_NETHERLANDS_ANTILLES, ETSI1_WORLD, "AN", 40, 160, 0},
	{CTRY_NEW_ZEALAND, FCC3_ETSIC, "NZ", 40, 160, 0},
	{CTRY_NIGERIA, APL8_WORLD, "NG", 40, 160, 0},
	{CTRY_NORTHERN_MARIANA_ISLANDS, FCC3_FCCA, "MP", 40, 160, 0},
	{CTRY_NICARAGUA, FCC3_FCCA, "NI", 40, 160, 0},
	{CTRY_NORWAY, ETSI1_WORLD, "NO", 40, 160, 0},
	{CTRY_OMAN, ETSI1_WORLD, "OM", 40, 160, 0},
	{CTRY_PAKISTAN, APL1_ETSIC, "PK", 40, 160, 0},
	{CTRY_PALAU, FCC3_FCCA, "PW", 40, 160, 0},
	{CTRY_PANAMA, FCC14_FCCB, "PA", 40, 160, 0},
	{CTRY_PAPUA_NEW_GUINEA, FCC3_WORLD, "PG", 40, 160, 0},
	{CTRY_PARAGUAY, FCC3_WORLD, "PY", 40, 160, 0},
	{CTRY_PERU, FCC3_WORLD, "PE", 40, 160, 0},
	{CTRY_PHILIPPINES, FCC3_WORLD, "PH", 40, 160, 0},
	{CTRY_POLAND, ETSI1_WORLD, "PL", 40, 160, 0},
	{CTRY_PORTUGAL, ETSI1_WORLD, "PT", 40, 160, 0},
	{CTRY_PUERTO_RICO, FCC3_FCCA, "PR", 40, 160, 0},
	{CTRY_QATAR, ETSI14_WORLD, "QA", 40, 160, 0},
	{CTRY_REUNION, ETSI1_WORLD, "RE", 40, 160, 0},
	{CTRY_ROMANIA, ETSI1_WORLD, "RO", 40, 160, 0},
	{CTRY_RUSSIA, ETSI8_WORLD, "RU", 40, 160, 0},
	{CTRY_RWANDA, FCC3_WORLD, "RW", 40, 160, 0},
	{CTRY_SAINT_BARTHELEMY, ETSI1_WORLD, "BL", 40, 160, 0},
	{CTRY_SAINT_KITTS_AND_NEVIS, APL10_WORLD, "KN", 40, 160, 0},
	{CTRY_SAINT_LUCIA, APL10_WORLD, "LC", 40, 160, 0},
	{CTRY_SAINT_MARTIN, ETSI1_WORLD, "MF", 40, 160, 0},
	{CTRY_SAINT_PIERRE_AND_MIQUELON, ETSI1_WORLD, "PM", 40, 160, 0},
	{CTRY_SAINT_VINCENT_AND_THE_GRENADIENS, ETSI1_WORLD,
	 "VC" , 40, 160, 0},
	{CTRY_SAMOA, ETSI1_WORLD, "WS", 40, 40, 0},
	{CTRY_SAUDI_ARABIA, ETSI1_WORLD, "SA", 40, 160, 0},
	{CTRY_SENEGAL, FCC13_WORLD, "SN", 40, 160, 0},
	{CTRY_SERBIA, ETSI1_WORLD, "RS", 40, 160, 0},
	{CTRY_SINGAPORE, FCC3_WORLD, "SG", 40, 160, 0},
	{CTRY_SLOVAKIA, ETSI1_WORLD, "SK", 40, 160, 0},
	{CTRY_SLOVENIA, ETSI1_WORLD, "SI", 40, 160, 0},
	{CTRY_SOUTH_AFRICA, FCC3_WORLD, "ZA", 40, 160, 0},
	{CTRY_SPAIN, ETSI1_WORLD, "ES", 40, 160, 0},
	{CTRY_SURINAME, ETSI1_WORLD, "SR", 40, 160, 0},
	{CTRY_SRI_LANKA, FCC3_WORLD, "LK", 40, 20, 0},
	{CTRY_SWEDEN, ETSI1_WORLD, "SE", 40, 160, 0},
	{CTRY_SWITZERLAND, ETSI1_WORLD, "CH", 40, 160, 0},
	{CTRY_TAIWAN, FCC3_FCCA, "TW", 40, 160, 0},
	{CTRY_TANZANIA, APL1_WORLD, "TZ", 40, 160, 0},
	{CTRY_THAILAND, FCC3_WORLD, "TH", 40, 160, 0},
	{CTRY_TOGO, ETSI1_WORLD, "TG", 40, 40, 0},
	{CTRY_TRINIDAD_Y_TOBAGO, FCC3_WORLD, "TT", 40, 160, 0},
	{CTRY_TUNISIA, ETSI3_WORLD, "TN", 40, 160, 0},
	{CTRY_TURKEY, ETSI1_WORLD, "TR", 40, 160, 0},
	{CTRY_TURKS_AND_CAICOS, FCC3_WORLD, "TC", 40, 160, 0},
	{CTRY_UGANDA, FCC3_WORLD, "UG", 40, 160, 0},
	{CTRY_UKRAINE, ETSI9_WORLD, "UA", 40, 160, 0},
	{CTRY_UAE, FCC3_WORLD, "AE", 40, 160, 0},
	{CTRY_UNITED_KINGDOM, ETSI1_WORLD, "GB", 40, 160, 0},
	{CTRY_UNITED_STATES, FCC8_FCCA, "US", 40, 160, 0},
	{CTRY_URUGUAY, FCC2_WORLD, "UY", 40, 160, 0},
	{CTRY_UZBEKISTAN, ETSI3_WORLD, "UZ", 40, 160, 0},
	{CTRY_VANUATU, FCC3_WORLD, "VU", 40, 160, 0},
	{CTRY_VENEZUELA, FCC2_ETSIC, "VE", 40, 160, 0},
	{CTRY_VIET_NAM, FCC3_WORLD, "VN", 40, 80, 0},
	{CTRY_VIRGIN_ISLANDS, FCC3_FCCA, "VI", 40, 160, 0},
	{CTRY_WALLIS_AND_FUTUNA, ETSI1_WORLD, "WF", 40, 160, 0},
	{CTRY_YEMEN, NULL1_WORLD, "YE", 40, 0, 0},
	{CTRY_ZIMBABWE, ETSI1_WORLD, "ZW", 40, 160, 0},
	{CTRY_JAPAN, MKK5_MKKC, "JP", 40, 160, 0},
	{CTRY_JAPAN15, MKK5_MKKC, "JP", 40, 160, 0},
};
#else
const struct country_code_to_reg_domain g_all_countries[] = {
	{CTRY_AFGHANISTAN, ETSI1_WORLD, "AF", 40, 160, 0},
	{CTRY_ALBANIA, ETSI13_WORLD, "AL", 40, 160, 0},
	{CTRY_ALGERIA, APL13_WORLD, "DZ", 40, 160, 0},
	{CTRY_AMERICAN_SAMOA, FCC3_FCCA, "AS", 40, 160, 0},
	{CTRY_ANGUILLA, ETSI1_WORLD, "AI", 40, 160, 0},
	{CTRY_ARGENTINA, APL17_ETSID, "AR", 40, 160, 0},
	{CTRY_ARMENIA, ETSI4_WORLD, "AM", 40, 20, 0},
	{CTRY_ARUBA, ETSI1_WORLD, "AW", 40, 160, 0},
	{CTRY_AUSTRALIA, FCC6_WORLD, "AU", 40, 160, 0},
	{CTRY_AUSTRIA, ETSI13_WORLD, "AT", 40, 160, 0},
	{CTRY_AZERBAIJAN, ETSI4_WORLD, "AZ", 40, 160, 0},
	{CTRY_BAHAMAS, FCC3_WORLD, "BS", 40, 160, 0},
	{CTRY_BAHRAIN, APL15_WORLD, "BH", 40, 20, 0},
	{CTRY_BANGLADESH, APL1_WORLD, "BD", 40, 160, 0},
	{CTRY_BARBADOS, FCC2_WORLD, "BB", 40, 160, 0},
	{CTRY_BELARUS, ETSI1_WORLD, "BY", 40, 160, 0},
	{CTRY_BELGIUM, ETSI13_WORLD, "BE", 40, 160, 0},
	{CTRY_BELIZE, ETSI8_WORLD, "BZ", 40, 160, 0},
	{CTRY_BERMUDA, FCC3_FCCA, "BM", 40, 160, 0},
	{CTRY_BHUTAN, ETSI1_WORLD, "BT", 40, 160, 0},
	{CTRY_BOLIVIA, APL8_WORLD, "BO", 40, 160, 0},
	{CTRY_BOSNIA_HERZ, ETSI13_WORLD, "BA", 40, 160, 0},
	{CTRY_BRAZIL, FCC3_ETSIC, "BR", 40, 160, 0},
	{CTRY_BRUNEI_DARUSSALAM, APL6_WORLD, "BN", 40, 160, 0},
	{CTRY_BULGARIA, ETSI13_WORLD, "BG", 40, 160, 0},
	{CTRY_BURKINA_FASO, FCC3_WORLD, "BF", 40, 160, 0},
	{CTRY_CAMBODIA, ETSI1_WORLD, "KH", 40, 160, 0},
	{CTRY_CANADA, FCC3_FCCA, "CA", 40, 160, 0},
	{CTRY_CAYMAN_ISLANDS, FCC3_WORLD, "KY", 40, 160, 0},
	{CTRY_CENTRAL_AFRICA_REPUBLIC, FCC3_WORLD, "CF", 40, 40, 0},
	{CTRY_CHAD, ETSI1_WORLD, "TD", 40, 160, 0},
	{CTRY_CHILE, APL23_WORLD, "CL", 40, 160, 0},
	{CTRY_CHINA, APL14_WORLD, "CN", 40, 160, 0},
	{CTRY_CHRISTMAS_ISLAND, FCC3_WORLD, "CX", 40, 160, 0},
	{CTRY_COLOMBIA, FCC3_WORLD, "CO", 40, 160, 0},
	{CTRY_COSTA_RICA, FCC3_WORLD, "CR", 40, 20, 0},
	{CTRY_COTE_DIVOIRE, FCC3_WORLD, "CI", 40, 160, 0},
	{CTRY_CROATIA, ETSI13_WORLD, "HR", 40, 160, 0},
	{CTRY_CYPRUS, ETSI13_WORLD, "CY", 40, 160, 0},
	{CTRY_CZECH, ETSI13_WORLD, "CZ", 40, 160, 0},
	{CTRY_DENMARK, ETSI13_WORLD, "DK", 40, 160,  0},
	{CTRY_DOMINICA, FCC2_FCCA, "DM", 40, 160, 0},
	{CTRY_DOMINICAN_REPUBLIC, FCC2_FCCA, "DO", 40, 160, 0},
	{CTRY_ECUADOR, FCC3_WORLD, "EC", 40, 20, 0},
	{CTRY_EGYPT, ETSI3_WORLD, "EG", 40, 160, 0},
	{CTRY_EL_SALVADOR, FCC2_WORLD, "SV", 40, 20, 0},
	{CTRY_ESTONIA, ETSI13_WORLD, "EE", 40, 160, 0},
	{CTRY_ETHIOPIA, ETSI1_WORLD, "ET", 40, 160, 0},
	{CTRY_FINLAND, ETSI13_WORLD, "FI", 40, 160, 0},
	{CTRY_FRANCE, ETSI13_WORLD, "FR", 40, 160, 0},
	{CTRY_FRENCH_GUIANA, ETSI13_WORLD, "GF", 40, 160, 0},
	{CTRY_FRENCH_POLYNESIA, ETSI13_WORLD, "PF", 40, 160, 0},
	{CTRY_GEORGIA, ETSI4_WORLD, "GE", 40, 160, 0},
	{CTRY_GERMANY, ETSI13_WORLD, "DE", 40, 160, 0},
	{CTRY_GHANA, FCC3_WORLD, "GH", 40, 160, 0},
	{CTRY_GIBRALTAR, ETSI1_WORLD, "GI", 40, 160, 0},
	{CTRY_GREECE, ETSI13_WORLD, "GR", 40, 160, 0},
	{CTRY_GREENLAND, ETSI1_WORLD, "GL", 40, 160, 0},
	{CTRY_GRENADA, FCC3_FCCA, "GD", 40, 160, 0},
	{CTRY_GUADELOUPE, ETSI1_WORLD, "GP", 40, 160, 0},
	{CTRY_GUAM, FCC3_FCCA, "GU", 40, 160, 0},
	{CTRY_GUATEMALA, ETSI1_WORLD, "GT", 40, 160, 0},
	{CTRY_GUYANA, APL1_ETSIC, "GY", 40, 160, 0},
	{CTRY_HAITI, FCC3_FCCA, "HT", 40, 160, 0},
	{CTRY_HONDURAS, FCC13_WORLD, "HN", 40, 160, 0},
	{CTRY_HONG_KONG, FCC3_WORLD, "HK", 40, 160, 0},
	{CTRY_HUNGARY, ETSI13_WORLD, "HU", 40, 160, 0},
	{CTRY_ICELAND, ETSI13_WORLD, "IS", 40, 160, 0},
	{CTRY_INDIA, APL15_WORLD, "IN", 40, 160, 0},
	{CTRY_INDONESIA, APL2_ETSIC, "ID", 40, 20, 0},
	{CTRY_IRAQ, ETSI1_WORLD, "IQ", 40, 160, 0},
	{CTRY_IRELAND, ETSI13_WORLD, "IE", 40, 160, 0},
	{CTRY_ISRAEL, ETSI3_WORLD, "IL", 40, 160, 0},
	{CTRY_ITALY, ETSI13_WORLD, "IT", 40, 160,  0},
	{CTRY_JAMAICA, FCC13_WORLD, "JM", 40, 160, 0},
	{CTRY_JORDAN, APL4_WORLD, "JO", 40, 160, 0},
	{CTRY_KAZAKHSTAN, NULL1_WORLD, "KZ", 40, 0, 0},
	{CTRY_KENYA, APL12_WORLD, "KE", 40, 160, 0},
	{CTRY_KOREA_ROC, APL9_WORLD, "KR", 40, 160, 0},
	{CTRY_KUWAIT, ETSI3_WORLD, "KW", 40, 160, 0},
	{CTRY_LATVIA, ETSI13_WORLD, "LV", 40, 160, 0},
	{CTRY_LEBANON, FCC3_WORLD, "LB", 40, 160, 0},
	{CTRY_LESOTHO, ETSI1_WORLD, "LS", 40, 160, 0},
	{CTRY_LIECHTENSTEIN, ETSI13_WORLD, "LI", 40, 160, 0},
	{CTRY_LITHUANIA, ETSI13_WORLD, "LT", 40, 160, 0},
	{CTRY_LUXEMBOURG, ETSI13_WORLD, "LU", 40, 160, 0},
	{CTRY_MACAU, FCC3_WORLD, "MO", 40, 160, 0},
	{CTRY_MACEDONIA, ETSI13_WORLD, "MK", 40, 160, 0},
	{CTRY_MALAWI, ETSI1_WORLD, "MW", 40, 160, 0},
	{CTRY_MALAYSIA, FCC11_WORLD, "MY", 40, 160, 0},
	{CTRY_MALDIVES, APL6_WORLD, "MV", 40, 160, 0},
	{CTRY_MALTA, ETSI13_WORLD, "MT", 40, 160, 0},
	{CTRY_MARSHALL_ISLANDS, FCC3_FCCA, "MH", 40, 160, 0},
	{CTRY_MARTINIQUE, ETSI13_WORLD, "MQ", 40, 160, 0},
	{CTRY_MAURITANIA, ETSI1_WORLD, "MR", 40, 160, 0},
	{CTRY_MAURITIUS, ETSI13_WORLD, "MU", 40, 160, 0},
	{CTRY_MAYOTTE, ETSI1_WORLD, "YT", 40, 160, 0},
	{CTRY_MEXICO, FCC3_ETSIC, "MX", 40, 160, 0},
	{CTRY_MICRONESIA, FCC3_FCCA, "FM", 40, 160, 0},
	{CTRY_MOLDOVA, ETSI13_WORLD, "MD", 40, 160, 0},
	{CTRY_MONACO, ETSI13_WORLD, "MC", 40, 160, 0},
	{CTRY_MONGOLIA, FCC3_WORLD, "MN", 40, 160, 0},
	{CTRY_MONTENEGRO, ETSI13_WORLD, "ME", 40, 160, 0},
	{CTRY_MOROCCO, ETSI3_WORLD, "MA", 40, 160, 0},
	{CTRY_NAMIBIA, APL20_WORLD, "NA", 40, 160, 0},
	{CTRY_NEPAL, APL23_WORLD, "NP", 40, 160, 0},
	{CTRY_NETHERLANDS, ETSI13_WORLD, "NL", 40, 160, 0},
	{CTRY_NETHERLANDS_ANTILLES, ETSI13_WORLD, "AN", 40, 160, 0},
	{CTRY_NEW_ZEALAND, FCC3_ETSIC, "NZ", 40, 160, 0},
	{CTRY_NIGERIA, APL8_WORLD, "NG", 40, 160, 0},
	{CTRY_NORTHERN_MARIANA_ISLANDS, FCC3_FCCA, "MP", 40, 160, 0},
	{CTRY_NICARAGUA, FCC3_FCCA, "NI", 40, 160, 0},
	{CTRY_NORWAY, ETSI13_WORLD, "NO", 40, 160, 0},
	{CTRY_OMAN, ETSI1_WORLD, "OM", 40, 160, 0},
	{CTRY_PAKISTAN, APL1_ETSIC, "PK", 40, 160, 0},
	{CTRY_PALAU, FCC3_FCCA, "PW", 40, 160, 0},
	{CTRY_PANAMA, FCC14_FCCB, "PA", 40, 160, 0},
	{CTRY_PAPUA_NEW_GUINEA, FCC3_WORLD, "PG", 40, 160, 0},
	{CTRY_PARAGUAY, FCC3_WORLD, "PY", 40, 160, 0},
	{CTRY_PERU, FCC3_WORLD, "PE", 40, 160, 0},
	{CTRY_PHILIPPINES, FCC3_WORLD, "PH", 40, 160, 0},
	{CTRY_POLAND, ETSI13_WORLD, "PL", 40, 160, 0},
	{CTRY_PORTUGAL, ETSI13_WORLD, "PT", 40, 160, 0},
	{CTRY_PUERTO_RICO, FCC3_FCCA, "PR", 40, 160, 0},
	{CTRY_QATAR, ETSI14_WORLD, "QA", 40, 160, 0},
	{CTRY_REUNION, ETSI1_WORLD, "RE", 40, 160, 0},
	{CTRY_ROMANIA, ETSI13_WORLD, "RO", 40, 160, 0},
	{CTRY_RUSSIA, ETSI8_WORLD, "RU", 40, 160, 0},
	{CTRY_RWANDA, FCC3_WORLD, "RW", 40, 160, 0},
	{CTRY_SAINT_BARTHELEMY, ETSI1_WORLD, "BL", 40, 160, 0},
	{CTRY_SAINT_KITTS_AND_NEVIS, APL10_WORLD, "KN", 40, 160, 0},
	{CTRY_SAINT_LUCIA, APL10_WORLD, "LC", 40, 160, 0},
	{CTRY_SAINT_MARTIN, ETSI1_WORLD, "MF", 40, 160, 0},
	{CTRY_SAINT_PIERRE_AND_MIQUELON, ETSI13_WORLD, "PM", 40, 160, 0},
	{CTRY_SAINT_VINCENT_AND_THE_GRENADIENS, ETSI13_WORLD, "VC",
	 40, 160, 0},
	{CTRY_SAMOA, ETSI1_WORLD, "WS", 40, 40, 0},
	{CTRY_SAUDI_ARABIA, ETSI1_WORLD, "SA", 40, 160, 0},
	{CTRY_SENEGAL, FCC13_WORLD, "SN", 40, 160, 0},
	{CTRY_SERBIA, ETSI13_WORLD, "RS", 40, 160, 0},
	{CTRY_SINGAPORE, FCC3_WORLD, "SG", 40, 160, 0},
	{CTRY_SLOVAKIA, ETSI13_WORLD, "SK", 40, 160, 0},
	{CTRY_SLOVENIA, ETSI13_WORLD, "SI", 40, 160, 0},
	{CTRY_SOUTH_AFRICA, FCC3_WORLD, "ZA", 40, 160, 0},
	{CTRY_SPAIN, ETSI13_WORLD, "ES", 40, 160, 0},
	{CTRY_SURINAME, ETSI1_WORLD, "SR", 40, 160, 0},
	{CTRY_SRI_LANKA, FCC3_WORLD, "LK", 40, 20, 0},
	{CTRY_SWEDEN, ETSI13_WORLD, "SE", 40, 160, 0},
	{CTRY_SWITZERLAND, ETSI13_WORLD, "CH", 40, 160, 0},
	{CTRY_TAIWAN, FCC3_FCCA, "TW", 40, 160, 0},
	{CTRY_TANZANIA, APL1_WORLD, "TZ", 40, 160, 0},
	{CTRY_THAILAND, FCC3_WORLD, "TH", 40, 160, 0},
	{CTRY_TOGO, ETSI1_WORLD, "TG", 40, 40, 0},
	{CTRY_TRINIDAD_Y_TOBAGO, FCC3_WORLD, "TT", 40, 160, 0},
	{CTRY_TUNISIA, ETSI3_WORLD, "TN", 40, 160, 0},
	{CTRY_TURKEY, ETSI13_WORLD, "TR", 40, 160, 0},
	{CTRY_TURKS_AND_CAICOS, FCC3_WORLD, "TC", 40, 160, 0},
	{CTRY_UGANDA, FCC3_WORLD, "UG", 40, 160, 0},
	{CTRY_UKRAINE, ETSI9_WORLD, "UA", 40, 160, 0},
	{CTRY_UAE, FCC3_WORLD, "AE", 40, 160, 0},
	{CTRY_UNITED_KINGDOM, ETSI13_WORLD, "GB", 40, 160, 0},
	{CTRY_UNITED_STATES, FCC8_FCCA, "US", 40, 160, 0},
	{CTRY_URUGUAY, FCC2_WORLD, "UY", 40, 160, 0},
	{CTRY_UZBEKISTAN, ETSI3_WORLD, "UZ", 40, 160, 0},
	{CTRY_VANUATU, FCC3_WORLD, "VU", 40, 160, 0},
	{CTRY_VENEZUELA, FCC2_ETSIC, "VE", 40, 160, 0},
	{CTRY_VIET_NAM, FCC3_WORLD, "VN", 40, 80, 0},
	{CTRY_VIRGIN_ISLANDS, FCC3_FCCA, "VI", 40, 160, 0},
	{CTRY_WALLIS_AND_FUTUNA, ETSI1_WORLD, "WF", 40, 160, 0},
	{CTRY_YEMEN, NULL1_WORLD, "YE", 40, 0, 0},
	{CTRY_ZIMBABWE, ETSI1_WORLD, "ZW", 40, 160, 0},
	{CTRY_JAPAN, MKK5_MKKC, "JP", 40, 160, 0},
	{CTRY_XA, MKK5_MKKA, "XA", 40, 160, 0},
};
#endif

enum reg_domains_2g {
	FCCA,
	FCCB,
	WORLD,
	MKKA,
	MKKC,
	ETSIC,
	ETSID,
	WORLD_2G_1,
	WORLD_2G_2,
	WORLD_2G_3,
};

enum reg_domains_5g {
	NULL1,
	FCC1,
	FCC2,
	FCC3,
	FCC4,
	FCC5,
	FCC6,
	FCC8,
	FCC11,
	FCC13,
	FCC14,
	ETSI1,
	ETSI3,
	ETSI4,
	ETSI8,
	ETSI9,
	ETSI11,
	ETSI12,
	ETSI13,
	ETSI14,
	APL1,
	APL2,
	APL4,
	APL6,
	APL8,
	APL9,
	APL10,
	APL11,
	APL12,
	APL13,
	APL14,
	APL15,
	APL16,
	APL17,
	APL19,
	APL20,
	APL23,
	MKK3,
	MKK4,
	MKK5,
	MKK9,
	MKK10,
	MKK11,
	MKK16,
	WORLD_5G_1,
	WORLD_5G_2,
};


const struct reg_domain_pair g_reg_dmn_pairs[] = {
	{NULL1_WORLD, NULL1, WORLD},

	{FCC1_FCCA, FCC1, FCCA},
	{FCC1_WORLD, FCC1, WORLD},
	{FCC2_FCCA, FCC2, FCCA},
	{FCC2_WORLD, FCC2, WORLD},
	{FCC2_ETSIC, FCC2, ETSIC},
	{FCC3_FCCA, FCC3, FCCA},
	{FCC3_WORLD, FCC3, WORLD},
	{FCC3_ETSIC, FCC3, ETSIC},
	{FCC4_FCCA, FCC4, FCCA},
	{FCC5_FCCA, FCC5, FCCA},
	{FCC6_WORLD, FCC6, WORLD},
	{FCC6_FCCA, FCC6, FCCA},
	{FCC8_FCCA, FCC8, FCCA},
	{FCC11_WORLD, FCC11, WORLD},
	{FCC13_WORLD, FCC13, WORLD},
	{FCC14_FCCB, FCC14, FCCB},

	{ETSI1_WORLD, ETSI1, WORLD},
	{ETSI3_WORLD, ETSI3, WORLD},
	{ETSI4_WORLD, ETSI4, WORLD},
	{ETSI8_WORLD, ETSI8, WORLD},
	{ETSI9_WORLD, ETSI9, WORLD},
	{ETSI11_WORLD, ETSI11, WORLD},
	{ETSI12_WORLD, ETSI12, WORLD},
	{ETSI13_WORLD, ETSI13, WORLD},
	{ETSI14_WORLD, ETSI14, WORLD},

	{APL1_WORLD, APL1, WORLD},
	{APL1_ETSIC, APL1, ETSIC},
	{APL2_WORLD, APL2, WORLD},
	{APL2_ETSIC, APL2, ETSIC},
	{APL4_WORLD, APL4, WORLD},
	{APL6_WORLD, APL6, WORLD},
	{APL8_WORLD, APL8, WORLD},
	{APL9_WORLD, APL9, WORLD},
	{APL10_WORLD, APL10, WORLD},
	{APL11_FCCA, APL11, FCCA},
	{APL12_WORLD, APL12, WORLD},
	{APL13_WORLD, APL13, WORLD},
	{APL14_WORLD, APL14, WORLD},
	{APL15_WORLD, APL15, WORLD},
	{APL16_WORLD, APL16, WORLD},
	{APL17_ETSID, APL17, ETSID},
	{APL19_ETSIC, APL19, ETSIC},
	{APL20_WORLD, APL20, WORLD},
	{APL23_WORLD, APL23, WORLD},

	{MKK3_MKKC, MKK3, MKKC},
	{MKK5_MKKA, MKK5, MKKA},
	{MKK5_MKKC, MKK5, MKKC},
	{MKK11_MKKC, MKK11, MKKC},
	{MKK16_MKKC, MKK16, MKKC},

	{WORLD_60, WORLD_5G_2, WORLD_2G_3},
	{WORLD_61, WORLD_5G_2, WORLD_2G_3},
	{WORLD_62, WORLD_5G_2, WORLD_2G_3},
	{WORLD_63, WORLD_5G_1, WORLD_2G_2},
	{WORLD_65, WORLD_5G_1, WORLD_2G_2},
	{WORLD_64, WORLD_5G_1, WORLD_2G_1},
	{WORLD_66, WORLD_5G_2, WORLD_2G_1},
	{WORLD_69, WORLD_5G_2, WORLD_2G_1},
	{WORLD_67, WORLD_5G_2, WORLD_2G_2},
	{WORLD_68, WORLD_5G_2, WORLD_2G_2},
	{WORLD_6A, WORLD_5G_2, WORLD_2G_2},
	{WORLD_6C, WORLD_5G_2, WORLD_2G_2},
};

enum reg_rules_2g {

	CHAN_1_11_1,
	CHAN_1_11_2,
	CHAN_1_11_3,
	CHAN_1_13_1,
	CHAN_1_13_2,
	CHAN_1_13_3,
	CHAN_1_13_4,
	CHAN_12_13_1,
	CHAN_14_1,
	CHAN_14_2,
};

const struct regulatory_rule reg_rules_2g[] = {

	[CHAN_1_11_1] = {2402, 2472, 40, 30, 0},
	[CHAN_1_11_2] = {2402, 2472, 40, 20, 0},
	[CHAN_1_11_3] = {2402, 2472, 40, 36, 0},
	[CHAN_1_13_1] = {2402, 2482, 40, 20, 0},
	[CHAN_1_13_2] = {2402, 2482, 40, 30, 0},
	[CHAN_1_13_3] = {2402, 2482, 40, 36, 0},
	[CHAN_1_13_4] = {2402, 2482, 40, 23, 0},
	[CHAN_12_13_1] = {2457, 2482, 40, 30, REGULATORY_CHAN_NO_IR},
	[CHAN_14_1] = {2474, 2494, 20, 23, REGULATORY_CHAN_NO_OFDM},
	[CHAN_14_2] = {2474, 2494, 20, 20,
		       REGULATORY_CHAN_NO_OFDM | REGULATORY_CHAN_NO_IR},
};


const struct regdomain regdomains_2g[] = {

	[FCCA] = {CTL_FCC, DFS_UNINIT_REG, 0, 6, 1, {CHAN_1_11_1} },
	[FCCB] = {CTL_FCC, DFS_UNINIT_REG, 0, 6, 1, {CHAN_1_11_3} },
	[WORLD] = {CTL_ETSI, DFS_UNINIT_REG, 0, 0, 1, {CHAN_1_13_1} },
	[MKKA] = {CTL_MKK, DFS_UNINIT_REG, 0, 0, 2, {CHAN_1_13_4, CHAN_14_1} },
	[MKKC] = {CTL_MKK, DFS_UNINIT_REG, 0, 0, 1, {CHAN_1_13_4} },
	[ETSIC] = {CTL_ETSI, DFS_UNINIT_REG, 0, 0, 1, {CHAN_1_13_2} },
	[ETSID] = {CTL_ETSI, DFS_UNINIT_REG, 0, 0, 1, {CHAN_1_13_3} },
	[WORLD_2G_1] = {CTL_NONE, DFS_UNINIT_REG, 0, 0, 1, {CHAN_1_11_2} },
	[WORLD_2G_2] = {CTL_NONE, DFS_UNINIT_REG, 0, 0, 2,
			{CHAN_1_11_2, CHAN_12_13_1} },
	[WORLD_2G_3] = {CTL_NONE, DFS_UNINIT_REG, 0, 0, 3,
			{CHAN_1_11_2, CHAN_12_13_1, CHAN_14_2} },
};


enum reg_rules_5g {

	CHAN_4910_4990_1,
	CHAN_4940_4990_1,
	CHAN_5030_5090_1,
	CHAN_5170_5250_1,
	CHAN_5170_5250_2,
	CHAN_5170_5250_3,
	CHAN_5170_5250_4,
	CHAN_5170_5250_5,
	CHAN_5170_5250_6,
	CHAN_5170_5250_7,
	CHAN_5170_5250_8,
	CHAN_5170_5250_9,
	CHAN_5170_5330_1,
	CHAN_5170_5330_2,
	CHAN_5250_5330_1,
	CHAN_5250_5330_2,
	CHAN_5250_5330_3,
	CHAN_5250_5330_4,
	CHAN_5250_5330_5,
	CHAN_5250_5330_6,
	CHAN_5250_5330_7,
	CHAN_5250_5330_8,
	CHAN_5250_5330_9,
	CHAN_5250_5330_10,
	CHAN_5250_5330_11,
	CHAN_5250_5330_12,
	CHAN_5250_5330_13,
	CHAN_5490_5730_1,
	CHAN_5490_5730_2,
	CHAN_5490_5730_3,
	CHAN_5490_5730_4,
	CHAN_5490_5730_5,
	CHAN_5490_5730_6,
	CHAN_5490_5730_7,
	CHAN_5490_5710_1,
	CHAN_5490_5710_2,
	CHAN_5490_5710_3,
	CHAN_5490_5710_4,
	CHAN_5490_5710_5,
	CHAN_5490_5710_6,
	CHAN_5490_5710_7,
	CHAN_5490_5590_1,
	CHAN_5490_5590_2,
	CHAN_5490_5590_3,
	CHAN_5490_5570_1,
	CHAN_5490_5650_2,
	CHAN_5490_5670_1,
	CHAN_5490_5670_2,
	CHAN_5490_5630_1,
	CHAN_5650_5730_1,
	CHAN_5650_5730_2,
	CHAN_5650_5730_3,
	CHAN_5735_5835_1,
	CHAN_5735_5835_2,
	CHAN_5735_5835_3,
	CHAN_5735_5835_4,
	CHAN_5735_5835_5,
	CHAN_5735_5835_6,
	CHAN_5735_5835_7,
	CHAN_5735_5875_1,
	CHAN_5735_5875_2,
	CHAN_5735_5875_3,
	CHAN_5735_5875_4,
	CHAN_5735_5875_5,
	CHAN_5735_5815_1,
	CHAN_5735_5775_1,
	CHAN_5835_5855_1,
	CHAN_5855_5875_1,
};

const struct regulatory_rule reg_rules_5g[] = {

	[CHAN_4910_4990_1] = {4910, 4990, 20, 20, 0},
	[CHAN_4940_4990_1] = {4940, 4990, 20, 33, 0},
	[CHAN_5030_5090_1] = {5030, 5090, 20, 20, 0},
	[CHAN_5170_5250_1] = {5170, 5250, 80, 17, 0},
	[CHAN_5170_5250_2] = {5170, 5250, 80, 23, 0},
	[CHAN_5170_5250_3] = {5170, 5250, 80, 20, 0},
	[CHAN_5170_5250_4] = {5170, 5250, 80, 30, 0},
	[CHAN_5170_5250_5] = {5170, 5250, 80, 24, 0},
	[CHAN_5170_5250_6] = {5170, 5250, 80, 18, 0},
	[CHAN_5170_5250_7] = {5170, 5250, 80, 20, REGULATORY_CHAN_INDOOR_ONLY},
	[CHAN_5170_5250_8] = {5170, 5250, 80, 23, REGULATORY_CHAN_INDOOR_ONLY},
	[CHAN_5170_5250_9] = {5170, 5250, 40, 30, 0},
	[CHAN_5170_5330_1] = {5170, 5330, 160, 20, REGULATORY_CHAN_NO_IR},
	[CHAN_5170_5330_2] = {5170, 5330, 160, 24, 0},
	[CHAN_5250_5330_1] = {5250, 5330, 80, 23, REGULATORY_CHAN_RADAR},
	[CHAN_5250_5330_2] = {5250, 5330, 80, 20, REGULATORY_CHAN_RADAR},
	[CHAN_5250_5330_3] = {5250, 5330, 80, 18, REGULATORY_CHAN_RADAR},
	[CHAN_5250_5330_4] = {5250, 5330, 80, 30, REGULATORY_CHAN_RADAR},
	[CHAN_5250_5330_5] = {5250, 5330, 80, 23, 0},
	[CHAN_5250_5330_6] = {5250, 5330, 80, 30, 0},
	[CHAN_5250_5330_7] = {5250, 5330, 80, 24, REGULATORY_CHAN_RADAR},
	[CHAN_5250_5330_8] = {5250, 5330, 80, 36, 0},
	[CHAN_5250_5330_9] = {5250, 5330, 80, 20, 0},
	[CHAN_5250_5330_10] = {5250, 5330, 80, 24, 0},
	[CHAN_5250_5330_11] = {5250, 5330, 80, 20, REGULATORY_CHAN_INDOOR_ONLY},
	[CHAN_5250_5330_12] = {5250, 5330, 80, 23, REGULATORY_CHAN_RADAR |
						   REGULATORY_CHAN_INDOOR_ONLY},
	[CHAN_5250_5330_13] = {5250, 5330, 40, 30, REGULATORY_CHAN_RADAR},
	[CHAN_5490_5730_1] = {5490, 5730, 160, 24, REGULATORY_CHAN_RADAR},
	[CHAN_5490_5730_2] = {5490, 5730, 160, 20, REGULATORY_CHAN_NO_IR},
	[CHAN_5490_5730_3] = {5490, 5730, 160, 30, 0},
	[CHAN_5490_5730_4] = {5490, 5730, 160, 24, 0},
	[CHAN_5490_5730_5] = {5490, 5730, 160, 30, REGULATORY_CHAN_RADAR},
	[CHAN_5490_5730_6] = {5490, 5730, 160, 23, REGULATORY_CHAN_RADAR},
	[CHAN_5490_5730_7] = {5490, 5730, 160, 20, REGULATORY_CHAN_RADAR},
	[CHAN_5490_5710_1] = {5490, 5710, 160, 30, REGULATORY_CHAN_RADAR},
	[CHAN_5490_5710_2] = {5490, 5710, 160, 20, REGULATORY_CHAN_RADAR},
	[CHAN_5490_5710_3] = {5490, 5710, 160, 27, REGULATORY_CHAN_RADAR},
	[CHAN_5490_5710_4] = {5490, 5710,  40, 30, REGULATORY_CHAN_RADAR},
	[CHAN_5490_5710_5] = {5490, 5710, 160, 24, REGULATORY_CHAN_RADAR},
	[CHAN_5490_5710_6] = {5490, 5710, 160, 26, REGULATORY_CHAN_RADAR},
	[CHAN_5490_5710_7] = {5490, 5710, 160, 23, REGULATORY_CHAN_RADAR},
	[CHAN_5490_5590_1] = {5490, 5590, 80, 24, REGULATORY_CHAN_RADAR},
	[CHAN_5490_5590_2] = {5490, 5590, 80, 30, 0},
	[CHAN_5490_5590_3] = {5490, 5590, 80, 36, 0},
	[CHAN_5490_5570_1] = {5490, 5570, 80, 30, REGULATORY_CHAN_RADAR},
	[CHAN_5490_5650_2] = {5490, 5650, 160, 24, REGULATORY_CHAN_RADAR},
	[CHAN_5490_5670_1] = {5490, 5670, 160, 20, REGULATORY_CHAN_RADAR},
	[CHAN_5490_5670_2] = {5490, 5670, 160, 23, REGULATORY_CHAN_RADAR},
	[CHAN_5490_5630_1] = {5490, 5630, 80, 30, REGULATORY_CHAN_RADAR},
	[CHAN_5650_5730_1] = {5650, 5730, 80, 24, REGULATORY_CHAN_RADAR},
	[CHAN_5650_5730_2] = {5650, 5730, 80, 30, 0},
	[CHAN_5650_5730_3] = {5650, 5730, 80, 36, 0},
	[CHAN_5735_5835_1] = {5735, 5835, 80, 23, 0},
	[CHAN_5735_5835_2] = {5735, 5835, 80, 30, 0},
	[CHAN_5735_5835_3] = {5735, 5835, 80, 20, 0},
	[CHAN_5735_5835_4] = {5735, 5835, 80, 33, 0},
	[CHAN_5735_5835_5] = {5735, 5835, 80, 20, REGULATORY_CHAN_NO_IR},
	[CHAN_5735_5835_6] = {5735, 5835, 80, 24, 0},
	[CHAN_5735_5835_7] = {5735, 5835, 80, 36, 0},
	[CHAN_5735_5875_1] = {5735, 5875, 20, 27, REGULATORY_CHAN_RADAR},
	[CHAN_5735_5875_2] = {5735, 5875, 20, 30, 0},
	[CHAN_5735_5875_3] = {5735, 5875, 80, 30, 0},
	[CHAN_5735_5875_4] = {5735, 5875, 80, 14, 0},
	[CHAN_5735_5875_5] = {5735, 5875, 80, 20, 0},
	[CHAN_5735_5815_1] = {5735, 5815, 80, 30, 0},
	[CHAN_5735_5775_1] = {5735, 5775, 40, 23, 0},
	[CHAN_5835_5855_1] = {5835, 5855, 20, 30, 0},
	[CHAN_5855_5875_1] = {5855, 5875, 20, 30, 0},
};


const struct regdomain regdomains_5g[] = {

	[FCC1] = {CTL_FCC, DFS_FCC_REG, 2, 6, 3, {CHAN_5170_5250_1,
					      CHAN_5250_5330_1,
					      CHAN_5735_5835_2} },

	[FCC2] = {CTL_FCC, DFS_FCC_REG, 2, 6, 3, {CHAN_5170_5250_2,
					     CHAN_5250_5330_1,
					     CHAN_5735_5835_2} },

	[FCC3] = {CTL_FCC, DFS_FCC_REG, 2, 6, 4, {CHAN_5170_5250_5,
					      CHAN_5250_5330_7,
					      CHAN_5490_5730_1,
					      CHAN_5735_5835_2} },

	[FCC4] = {CTL_FCC, DFS_FCC_REG, 2, 6, 1, {CHAN_4940_4990_1} },

	[FCC5] = {CTL_FCC, DFS_UNINIT_REG, 2, 6, 2, {CHAN_5170_5250_4,
					      CHAN_5735_5835_2} },

	[FCC6] = {CTL_FCC, DFS_FCC_REG, 2, 6, 5, {CHAN_5170_5250_5,
					      CHAN_5250_5330_7,
					      CHAN_5490_5590_1,
					      CHAN_5650_5730_1,
					      CHAN_5735_5835_2} },

	[FCC8] = {CTL_FCC, DFS_FCC_REG, 2, 6, 4, {CHAN_5170_5250_4,
					      CHAN_5250_5330_7,
					      CHAN_5490_5730_1,
					      CHAN_5735_5835_2} },

	[FCC11] = {CTL_FCC, DFS_FCC_REG, 2, 6, 4, {CHAN_5170_5250_5,
					      CHAN_5250_5330_7,
					      CHAN_5490_5650_2,
					      CHAN_5735_5835_6} },

	[FCC13] = {CTL_FCC, DFS_UNINIT_REG, 2, 0, 4, {CHAN_5170_5330_2,
					      CHAN_5250_5330_10,
					      CHAN_5490_5730_4,
					      CHAN_5735_5835_2} },

	[FCC14] = {CTL_FCC, DFS_UNINIT_REG, 2, 0, 4, {CHAN_5170_5250_4,
					      CHAN_5250_5330_10,
					      CHAN_5490_5730_4,
					      CHAN_5735_5835_2} },

	[ETSI1] = {CTL_ETSI, DFS_ETSI_REG, 2, 0, 3, {CHAN_5170_5250_2,
						 CHAN_5250_5330_1,
						 CHAN_5490_5710_1} },

	[ETSI3] = {CTL_ETSI, DFS_ETSI_REG, 5, 0, 2, {CHAN_5170_5250_2,
						 CHAN_5250_5330_1} },

	[ETSI4] = {CTL_ETSI, DFS_ETSI_REG, 2, 0, 2, {CHAN_5170_5250_6,
						 CHAN_5250_5330_3} },

	[ETSI8] = {CTL_ETSI, DFS_UNINIT_REG, 20, 0, 4, {CHAN_5170_5250_2,
						  CHAN_5250_5330_5,
						  CHAN_5490_5730_3,
						  CHAN_5735_5835_2} },

	[ETSI9] = {CTL_ETSI, DFS_ETSI_REG, 20, 0, 4, {CHAN_5170_5250_2,
						  CHAN_5250_5330_1,
						  CHAN_5490_5710_5,
						  CHAN_5735_5835_6} },

	[ETSI11] = {CTL_ETSI, DFS_ETSI_REG, 10, 0, 4, {CHAN_5170_5250_3,
						  CHAN_5250_5330_2,
						  CHAN_5490_5710_3,
						  CHAN_5735_5875_1} },

	[ETSI12] = {CTL_ETSI, DFS_ETSI_REG, 2, 0, 4, {CHAN_5170_5250_3,
						  CHAN_5250_5330_2,
						  CHAN_5490_5730_6,
						  CHAN_5735_5835_1} },

	[ETSI13] = {CTL_ETSI, DFS_ETSI_REG, 2, 0, 4, {CHAN_5170_5250_2,
						  CHAN_5250_5330_1,
						  CHAN_5490_5730_5,
						  CHAN_5735_5875_4} },

	[ETSI14] = {CTL_ETSI, DFS_ETSI_REG, 2, 0, 4, {CHAN_5170_5250_2,
						  CHAN_5250_5330_1,
						  CHAN_5490_5730_7,
						  CHAN_5735_5875_5} },

	[APL1] = {CTL_ETSI, DFS_UNINIT_REG, 2, 0, 1, {CHAN_5735_5835_2} },

	[APL2] = {CTL_ETSI, DFS_UNINIT_REG, 2, 0, 1, {CHAN_5735_5815_1} },

	[APL4] = {CTL_ETSI, DFS_UNINIT_REG, 2, 0, 2, {CHAN_5170_5250_2,
						  CHAN_5735_5835_1} },

	[APL6] = {CTL_ETSI, DFS_ETSI_REG, 2, 0, 3, {CHAN_5170_5250_3,
						CHAN_5250_5330_2,
						CHAN_5735_5835_3} },

	[APL8] = {CTL_ETSI, DFS_ETSI_REG, 2, 0, 2, {CHAN_5250_5330_4,
						CHAN_5735_5835_2} },

	[APL9] = {CTL_ETSI, DFS_KR_REG, 2, 6, 4, {CHAN_5170_5250_3,
					      CHAN_5250_5330_1,
					      CHAN_5490_5710_1,
					      CHAN_5735_5835_2} },

	[APL10] = {CTL_ETSI, DFS_FCC_REG, 2, 6, 4, {CHAN_5170_5250_2,
						 CHAN_5250_5330_4,
						 CHAN_5490_5710_1,
						 CHAN_5735_5815_1} },

	[APL11] = { CTL_ETSI, DFS_ETSI_REG, 2, 0, 4, {CHAN_5170_5250_9,
						 CHAN_5250_5330_13,
						 CHAN_5490_5710_4,
						 CHAN_5735_5875_2} },

	[APL12] = {CTL_ETSI, DFS_ETSI_REG, 2, 0, 3, {CHAN_5170_5250_2,
						 CHAN_5490_5570_1,
						 CHAN_5735_5775_1} },

	[APL13] = {CTL_ETSI, DFS_ETSI_REG, 2, 0, 3, {CHAN_5170_5250_2,
						 CHAN_5250_5330_1,
						 CHAN_5490_5670_2} },

	[APL14] = {CTL_FCC, DFS_CN_REG, 2, 0, 3, {CHAN_5170_5250_2,
					      CHAN_5250_5330_1,
					      CHAN_5735_5835_4} },

	[APL15] = {CTL_FCC, DFS_UNINIT_REG, 2, 0, 3, {CHAN_5170_5250_2,
					      CHAN_5250_5330_5,
					      CHAN_5735_5835_4} },

	[APL16] = {CTL_FCC, DFS_UNINIT_REG, 2, 0, 5, {CHAN_5170_5250_1,
					    CHAN_5250_5330_6,
					    CHAN_5490_5590_2,
					    CHAN_5650_5730_2,
					    CHAN_5735_5835_2} },

	[APL17] = {CTL_FCC, DFS_UNINIT_REG, 2, 0, 5, {CHAN_5170_5250_2,
					    CHAN_5250_5330_8,
					    CHAN_5490_5590_3,
					    CHAN_5650_5730_3,
					    CHAN_5735_5835_7} },

	[APL19] = {CTL_FCC, DFS_UNINIT_REG, 2, 0, 3, {CHAN_5170_5250_2,
					    CHAN_5250_5330_5,
					    CHAN_5735_5875_3} },

	[APL20] = {CTL_ETSI, DFS_ETSI_REG, 2, 0, 4, {CHAN_5170_5250_8,
					     CHAN_5250_5330_12,
					     CHAN_5490_5730_5,
					     CHAN_5735_5835_4} },

	[APL23] = {CTL_ETSI, DFS_UNINIT_REG, 2, 0, 3, {CHAN_5170_5250_7,
					     CHAN_5250_5330_11,
					     CHAN_5735_5835_3} },

	[MKK3] = {CTL_MKK, DFS_UNINIT_REG, 2, 0, 1, {CHAN_5170_5250_3} },

	[MKK5] = {CTL_MKK, DFS_MKK_REG, 2, 0, 3, {CHAN_5170_5250_2,
					      CHAN_5250_5330_1,
					      CHAN_5490_5710_7} },

	[MKK11] = {CTL_MKK, DFS_MKK_REG, 2, 0, 5, {CHAN_4910_4990_1,
					       CHAN_5170_5250_2,
					       CHAN_5030_5090_1,
					       CHAN_5250_5330_1,
					       CHAN_5490_5710_7} },

	[MKK16] = {CTL_MKK, DFS_MKK_REG, 2, 0, 1, {CHAN_5490_5710_6} },

	[WORLD_5G_1] = {CTL_NONE, DFS_UNINIT_REG, 2, 0, 2, {CHAN_5170_5330_1,
						       CHAN_5735_5835_5} },

	[WORLD_5G_2] = {CTL_NONE, DFS_UNINIT_REG, 2, 0, 3, {CHAN_5170_5330_1,
						       CHAN_5490_5730_2,
						       CHAN_5735_5835_5} },
};

QDF_STATUS reg_get_num_countries(int *num_countries)
{
	*num_countries = QDF_ARRAY_SIZE(g_all_countries);

	return QDF_STATUS_SUCCESS;
}

QDF_STATUS reg_get_num_reg_dmn_pairs(int *num_reg_dmn)
{
	*num_reg_dmn = QDF_ARRAY_SIZE(g_reg_dmn_pairs);

	return QDF_STATUS_SUCCESS;
}

QDF_STATUS reg_get_default_country(uint16_t *default_country)
{
	*default_country = CTRY_UNITED_STATES;

	return QDF_STATUS_SUCCESS;
}

bool reg_etsi13_regdmn(uint8_t reg_dmn)
{
	return reg_dmn == ETSI13;
}
