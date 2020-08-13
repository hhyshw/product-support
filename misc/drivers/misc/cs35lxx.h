/*
 * cs35lxx.h  --  CS35LXX Misc driver
 *
 * Copyright 2020 Cirrus Logic, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __CS35LXX_H__
#define __CS35LXX_H__

#include <linux/regmap.h>

#define CS35LXX_FIRSTREG		0x00000000
#define CS35LXX_LASTREG			0x00E037FC
#define CS35LXX_SW_RESET		0x00000000
#define CS35LXX_SW_REV			0x00000004
#define CS35LXX_HW_REV			0x00000008
#define CS35LXX_TESTKEY_CTRL		0x00000020
#define CS35LXX_USERKEY_CTL		0x00000024
#define CS35LXX_OTP_MEM30		0x00000478
#define CS35LXX_OTP_CTRL1		0x00000500
#define CS35LXX_OTP_CTRL2		0x00000504
#define CS35LXX_OTP_CTRL3		0x00000508
#define CS35LXX_OTP_CTRL4		0x0000050C
#define CS35LXX_OTP_CTRL5		0x00000510
#define CS35LXX_PAC_CTL1		0x00000C00
#define CS35LXX_PAC_CTL2		0x00000C04
#define CS35LXX_PAC_CTL3		0x00000C08
#define CS35LXX_DEVICE_ID		0x00002004
#define CS35LXX_FAB_ID			0x00002008
#define CS35LXX_REV_ID			0x0000200C
#define CS35LXX_PWR_CTRL1		0x00002014
#define CS35LXX_PWR_CTRL2		0x00002018
#define CS35LXX_PWR_CTRL3		0x0000201C
#define CS35LXX_CTRL_OVRRIDE		0x00002020
#define CS35LXX_AMP_OUT_MUTE		0x00002024
#define CS35LXX_OTP_TRIM_STATUS		0x00002028
#define CS35LXX_DISCH_FILT		0x0000202C
#define CS35LXX_OSC_TRIM		0x00002030
#define CS35LXX_PROTECT_REL_ERR		0x00002034
#define CS35LXX_PAD_INTERFACE		0x00002400
#define CS35LXX_PLL_CLK_CTRL		0x00002C04
#define CS35LXX_GLOBAL_CLK_CTRL		0x00002C0C
#define CS35LXX_ADC_CLK_CTRL		0x00002C10
#define CS35LXX_SWIRE_CLK_CTRL		0x00002C14
#define CS35LXX_SP_SCLK_CLK_CTRL	0x00002D00
#define CS35LXX_TST_FS_MON0		0x00002D10
#define CS35LXX_PLL_LOOP_PARAMS		0x00003008
#define CS35LXX_DCO_CTRL		0x00003010
#define CS35LXX_MISC_CTRL		0x00003014
#define CS35LXX_MDSYNC_EN		0x00003404
#define CS35LXX_MDSYNC_TX_ID		0x00003408
#define CS35LXX_MDSYNC_PWR_CTRL		0x0000340C
#define CS35LXX_MDSYNC_DATA_TX		0x00003410
#define CS35LXX_MDSYNC_TX_STATUS	0x0000341C
#define CS35LXX_MDSYNC_RX_STATUS	0x00003420
#define CS35LXX_MDSYNC_ERR_STATUS	0x00003424
#define CS35LXX_BSTCVRT_VCTRL1		0x00003800
#define CS35LXX_BSTCVRT_VCTRL2		0x00003804
#define CS35LXX_BSTCVRT_PEAK_CUR	0x00003808
#define CS35LXX_BSTCVRT_SFT_RAMP	0x0000380C
#define CS35LXX_BSTCVRT_COEFF		0x00003810
#define CS35LXX_BSTCVRT_SLOPE_LBST	0x00003814
#define CS35LXX_BSTCVRT_SW_FREQ		0x00003818
#define CS35LXX_BSTCVRT_DCM_CTRL	0x0000381C
#define CS35LXX_BSTCVRT_DCM_MODE_FORCE	0x00003820
#define CS35LXX_BSTCVRT_OVERVOLT_CTRL	0x00003830
#define CS35LXX_BST_TST_MANUAL		0x0000393C
#define CS35LXX_BST_ANA2_TEST		0x0000394C
#define CS35LXX_VPI_LIMIT_MODE		0x00003C04
#define CS35LXX_VPI_LIMIT_MINMAX	0x00003C08
#define CS35LXX_VPI_VP_THLD		0x00003C0C
#define CS35LXX_VPI_TRACK_CTRL		0x00003C10
#define CS35LXX_VPI_TRIG_MODE_CTRL	0x00003C14
#define CS35LXX_VPI_TRIG_STEPS		0x00003C18
#define CS35LXX_VI_SPKMON_FILT		0x00004004
#define CS35LXX_VI_SPKMON_GAIN		0x00004008
#define CS35LXX_VI_SPKMON_IP_SEL	0x00004100
#define CS35LXX_DTEMP_WARN_THLD		0x00004220
#define CS35LXX_DTEMP_STATUS		0x00004300
#define CS35LXX_VPVBST_FS_SEL		0x00004400
#define CS35LXX_VPVBST_VP_CTRL		0x00004440
#define CS35LXX_VPVBST_VBST_CTRL	0x00004444
#define CS35LXX_ASP_TX_PIN_CTRL		0x00004800
#define CS35LXX_ASP_RATE_CTRL		0x00004804
#define CS35LXX_ASP_FORMAT		0x00004808
#define CS35LXX_ASP_FRAME_CTRL		0x00004818
#define CS35LXX_ASP_TX1_TX2_SLOT	0x0000481C
#define CS35LXX_ASP_TX3_TX4_SLOT	0x00004820
#define CS35LXX_ASP_TX5_TX6_SLOT	0x00004824
#define CS35LXX_ASP_TX7_TX8_SLOT	0x00004828
#define CS35LXX_ASP_RX1_SLOT		0x0000482C
#define CS35LXX_ASP_RX_TX_EN		0x0000483C
#define CS35LXX_ASP_RX1_SEL		0x00004C00
#define CS35LXX_ASP_TX1_SEL		0x00004C20
#define CS35LXX_ASP_TX2_SEL		0x00004C24
#define CS35LXX_ASP_TX3_SEL		0x00004C28
#define CS35LXX_ASP_TX4_SEL		0x00004C2C
#define CS35LXX_ASP_TX5_SEL		0x00004C30
#define CS35LXX_ASP_TX6_SEL		0x00004C34
#define CS35LXX_SWIRE_P1_TX1_SEL	0x00004C40
#define CS35LXX_SWIRE_P1_TX2_SEL	0x00004C44
#define CS35LXX_SWIRE_P2_TX1_SEL	0x00004C60
#define CS35LXX_SWIRE_P2_TX2_SEL	0x00004C64
#define CS35LXX_SWIRE_P2_TX3_SEL	0x00004C68
#define CS35LXX_SWIRE_DP1_FIFO_CFG	0x00005000
#define CS35LXX_SWIRE_DP2_FIFO_CFG	0x00005004
#define CS35LXX_SWIRE_DP3_FIFO_CFG	0x00005008
#define CS35LXX_SWIRE_PCM_RX_DATA	0x0000500C
#define CS35LXX_SWIRE_FS_SEL		0x00005010
#define CS35LXX_SPARE_CP_BITS		0x00005C00
#define CS35LXX_AMP_DIG_VOL_CTRL	0x00006000
#define CS35LXX_VPBR_CFG		0x00006404
#define CS35LXX_VBBR_CFG		0x00006408
#define CS35LXX_VPBR_STATUS		0x0000640C
#define CS35LXX_VBBR_STATUS		0x00006410
#define CS35LXX_OVERTEMP_CFG		0x00006414
#define CS35LXX_AMP_ERR_VOL		0x00006418
#define CS35LXX_CLASSH_CFG		0x00006800
#define CS35LXX_CLASSH_FET_DRV_CFG	0x00006804
#define CS35LXX_NG_CFG			0x00006808
#define CS35LXX_AMP_GAIN_CTRL		0x00006C04
#define CS35LXX_PWM_MOD_IO_CTRL		0x0000706C
#define CS35LXX_PWM_MOD_STATUS		0x00007070
#define CS35LXX_DAC_MSM_CFG		0x00007400
#define CS35LXX_AMP_SLOPE_CTRL		0x00007410
#define CS35LXX_AMP_PDM_VOLUME		0x00007E04
#define CS35LXX_AMP_PDM_RATE_CTRL	0x00007E08
#define CS35LXX_PDM_CH_SEL		0x00007E10
#define CS35LXX_AMP_NG_CTRL		0x00007E14
#define CS35LXX_PDM_HIGHFILT_CTRL	0x00007E3C
#define CS35LXX_INT1_STATUS		0x00D00000
#define CS35LXX_INT2_STATUS		0x00D00004
#define CS35LXX_INT3_STATUS		0x00D00008
#define CS35LXX_INT4_STATUS		0x00D0000C
#define CS35LXX_INT1_RAW_STATUS		0x00D00020
#define CS35LXX_INT2_RAW_STATUS		0x00D00024
#define CS35LXX_INT3_RAW_STATUS		0x00D00028
#define CS35LXX_INT4_RAW_STATUS		0x00D0002C
#define CS35LXX_INT1_MASK		0x00D00040
#define CS35LXX_INT2_MASK		0x00D00044
#define CS35LXX_INT3_MASK		0x00D00048
#define CS35LXX_INT4_MASK		0x00D0004C
#define CS35LXX_INT1_EDGE_LVL_CTRL	0x00D00060
#define CS35LXX_INT3_EDGE_LVL_CTRL	0x00D00068
#define CS35LXX_PAC_INT_STATUS		0x00D00200
#define CS35LXX_PAC_INT_RAW_STATUS	0x00D00210
#define CS35LXX_PAC_INT_FLUSH_CTRL	0x00D00218
#define CS35LXX_PAC_INT0_CTRL		0x00D00220
#define CS35LXX_PAC_INT1_CTRL		0x00D00224
#define CS35LXX_PAC_INT2_CTRL		0x00D00228
#define CS35LXX_PAC_INT3_CTRL		0x00D0022C
#define CS35LXX_PAC_INT4_CTRL		0x00D00230
#define CS35LXX_PAC_INT5_CTRL		0x00D00234
#define CS35LXX_PAC_INT6_CTRL		0x00D00238
#define CS35LXX_PAC_INT7_CTRL		0x00D0023C
#define CS35LXX_PAC_PMEM_WORD0		0x00E02800
#define CS35LXX_PAC_PMEM_WORD1		0x00E02804
#define CS35LXX_PAC_PMEM_WORD1023	0x00E037FC

#define CS35LXX_INTPAC_REG_COUNT	25
#define CS35LXX_CHIP_ID			0x00035A36

#define CS35LXX_INT_OUTPUT_EN_MASK	0x01
#define CS35LXX_INT_GPIO_SEL_MASK	0x02
#define CS35LXX_INT_GPIO_SEL_SHIFT	1
#define CS35LXX_INT_POL_SEL_MASK	0x04
#define CS35LXX_INT_POL_SEL_SHIFT	2
#define CS35LXX_INT_DRV_SEL_MASK	0x20
#define CS35LXX_INT_DRV_SEL_SHIFT	5
#define CS35LXX_IRQ_SRC_MASK		0x08
#define CS35LXX_IRQ_SRC_SHIFT		3

#define CS35LXX_SCLK_MSTR_MASK		0x40
#define CS35LXX_SCLK_MSTR_SHIFT		6
#define CS35LXX_LRCLK_MSTR_MASK		0x01
#define CS35LXX_LRCLK_MSTR_SHIFT	0
#define CS35LXX_SCLK_INV_MASK		0x100
#define CS35LXX_SCLK_INV_SHIFT		8
#define CS35LXX_LRCLK_INV_MASK		0x04
#define CS35LXX_LRCLK_INV_SHIFT		2
#define CS35LXX_SCLK_FRC_MASK		0x80
#define CS35LXX_SCLK_FRC_SHIFT		7
#define CS35LXX_LRCLK_FRC_MASK		0x02
#define CS35LXX_LRCLK_FRC_SHIFT		1
#define CS35LXX_SCLK_FREQ_MASK		0x3F

#define CS35LXX_PDM_MODE_MASK		0x01
#define CS35LXX_PDM_MODE_SHIFT		0

#define CS35LXX_ASP_FMT_MASK		0x07
#define CS35LXX_ASP_FMT_SHIFT		0

#define CS35LXX_ASP_RX_WIDTH_MASK	0xFF0000
#define CS35LXX_ASP_RX_WIDTH_SHIFT	16
#define CS35LXX_ASP_TX_WIDTH_MASK	0xFF
#define CS35LXX_ASP_TX_WIDTH_SHIFT	0
#define CS35LXX_ASP_WIDTH_16		0x10
#define CS35LXX_ASP_WIDTH_24		0x18
#define CS35LXX_ASP_WIDTH_32		0x20

#define CS35LXX_ASP_RX1_SLOT_MASK	0x3F
#define CS35LXX_ASP_RX1_EN_MASK		0x00010000
#define CS35LXX_ASP_RX1_EN_SHIFT	16

#define CS35LXX_ASP_TX1_SLOT_MASK	0x3F
#define CS35LXX_ASP_TX2_SLOT_MASK	0x3F0000
#define CS35LXX_ASP_TX2_SLOT_SHIFT	16
#define CS35LXX_ASP_TX3_SLOT_MASK	0x3F
#define CS35LXX_ASP_TX4_SLOT_MASK	0x3F0000
#define CS35LXX_ASP_TX4_SLOT_SHIFT	16
#define CS35LXX_ASP_TX5_SLOT_MASK	0x3F
#define CS35LXX_ASP_TX6_SLOT_MASK	0x3F0000
#define CS35LXX_ASP_TX6_SLOT_SHIFT	16
#define CS35LXX_ASP_TX7_SLOT_MASK	0x3F
#define CS35LXX_ASP_TX8_SLOT_MASK	0x3F0000
#define CS35LXX_ASP_TX8_SLOT_SHIFT	16
#define CS35LXX_ASP_TX_HIZ_MASK		0x200000

#define CS35LXX_APS_TX_SEL_MASK		0x7F

#define CS35LXX_ASP_TX1_EN_MASK		0x01
#define CS35LXX_ASP_TX2_EN_MASK		0x02
#define CS35LXX_ASP_TX2_EN_SHIFT	1
#define CS35LXX_ASP_TX3_EN_MASK		0x04
#define CS35LXX_ASP_TX3_EN_SHIFT	2
#define CS35LXX_ASP_TX4_EN_MASK		0x08
#define CS35LXX_ASP_TX4_EN_SHIFT	3
#define CS35LXX_ASP_TX5_EN_MASK		0x10
#define CS35LXX_ASP_TX5_EN_SHIFT	4
#define CS35LXX_ASP_TX6_EN_MASK		0x20
#define CS35LXX_ASP_TX6_EN_SHIFT	5
#define CS35LXX_ASP_TX7_EN_MASK		0x40
#define CS35LXX_ASP_TX7_EN_SHIFT	6
#define CS35LXX_ASP_TX8_EN_MASK		0x80
#define CS35LXX_ASP_TX8_EN_SHIFT	7


#define CS35LXX_PLL_CLK_SEL_MASK	0x07
#define CS35LXX_PLL_CLK_SEL_SHIFT	0
#define CS35LXX_PLLSRC_SCLK		0
#define CS35LXX_PLLSRC_LRCLK		1
#define CS35LXX_PLLSRC_SELF		3
#define CS35LXX_PLLSRC_PDMCLK		4
#define CS35LXX_PLLSRC_MCLK		5
#define CS35LXX_PLLSRC_SWIRE		7
#define CS35LXX_REFCLK_FREQ_MASK	0x7E0
#define CS35LXX_REFCLK_FREQ_SHIFT	5
#define CS35LXX_PLL_OPENLOOP_MASK	0x800
#define CS35LXX_PLL_OPENLOOP_SHIFT	11
#define CS35LXX_PLL_REFCLK_EN_MASK	0x10
#define CS35LXX_PLL_REFCLK_EN_SHIFT	4


#define CS35LXX_GLOBAL_FS_MASK		0x1F
#define CS35LXX_GLOBAL_FS_SHIFT		0

#define CS35LXX_HPF_PCM_EN_MASK		0x800
#define CS35LXX_HPF_PCM_EN_SHIFT	15
#define CS35LXX_PCM_RX_SEL_MASK		0x7F
#define CS35LXX_PCM_RX_SEL_SHIFT	0

#define CS35LXX_PCM_RX_SEL_ZERO		0x00
#define CS35LXX_PCM_RX_SEL_PCM		0x08
#define CS35LXX_PCM_RX_SEL_SWIRE	0x10
#define CS35LXX_PCM_RX_SEL_DIAG		0x04

#define CS35LXX_GLOBAL_EN_MASK		0x01
#define CS35LXX_GLOBAL_EN_SHIFT		0x00

#define CS35LXX_AMP_PCM_INV_MASK	0x4000
#define CS35LXX_AMP_PCM_INV_SHIFT	14

#define CS35LXX_AMP_VOL_PCM_MASK	0x3FF8
#define CS35LXX_AMP_VOL_PCM_SHIFT	3
#define CS35LXX_DIGITAL_MUTE		0x04CF

#define CS35LXX_AMP_RAMP_MASK		0x0007
#define CS35LXX_AMP_RAMP_SHIFT		0

#define CS35LXX_AMP_MUTE_MASK		0x0010
#define CS35LXX_AMP_MUTE_SHIFT		4

#define CS35LXX_GLOBAL_RESYNC_FS1_MASK	0x00000200
#define CS35LXX_GLOBAL_RESYNC_FS2_MASK	0x00000400
#define CS35LXX_SYNC_GLOBAL_OVR_MASK	0x00000002
#define CS35LXX_SYNC_GLOBAL_OVR_SHIFT	1

#define CS35LXX_REFCLK_IN_MASK		0x00100000
#define CS35LXX_PLL_UNLOCK_MASK		0x00002000

#define CS35LXX_ASP_RX_UDF_MASK		0x00000040
#define CS35LXX_ASP_RX_OVF_MASK		0x00000080

#define CS35LXX_IMON_POL_MASK		0x02
#define CS35LXX_IMON_POL_SHIFT		1

#define CS35LXX_VMON_POL_MASK		0x01
#define CS35LXX_VMON_POL_SHIFT		0

#define CS35LXX_PDN_DONE		0x40
#define CS35LXX_PDN_DONE_SHIFT		6
#define CS35LXX_PUP_DONE		0x80
#define CS35LXX_PUP_DONE_SHIFT		7
#define CS35LXX_GLOBAL_EN_ASSRT		0x20
#define CS35LXX_PUP_DONE_IRQ_UNMASK	0x7F
#define CS35LXX_PUP_DONE_IRQ_MASK	0xBF

#define CS35LXX_FS1_WINDOW_MASK		0x000007FF
#define CS35LXX_FS2_WINDOW_MASK		0x00FFF800
#define CS35LXX_FS2_WINDOW_SHIFT	12

#define CS35LXX_PLL_FFL_IGAIN_MASK	0x0F
#define CS35LXX_PLL_IGAIN_MASK		0x3F0
#define CS35LXX_PLL_IGAIN_SHIFT		4
#define CS35LXX_PLL_IGAIN		0x04

#define CS35LXX_BST_EN_MASK		0x30
#define CS35LXX_BST_EN			0x02
#define CS35LXX_BST_DIS_VP		0x01
#define CS35LXX_BST_DIS_EXTN		0x00
#define CS35LXX_BST_EN_SHIFT		4
#define CS35LXX_BST_MAN_IPKCOMP_MASK	0x200
#define CS35LXX_BST_MAN_IPKCOMP_SHIFT	9

#define CS35LXX_BST_MAN_IPKCOMP_EN_MASK		0x100
#define CS35LXX_BST_MAN_IPKCOMP_EN_SHIFT	8

#define CS35LXX_BST_IPK_MASK		0x7F
#define CS35LXX_BST_OVP_THLD_MASK	0x3F
#define CS35LXX_BST_OVP_THLD_11V	0x10
#define CS35LXX_BST_OVP_TRIM_MASK	0x00078000
#define CS35LXX_BST_OVP_TRIM_SHIFT	15
#define CS35LXX_BST_OVP_TRIM_11V	0x0C
#define CS35LXX_BST_CTRL_LIM_MASK	0x04
#define CS35LXX_BST_CTRL_LIM_SHIFT	2
#define CS35LXX_BST_CTRL_10V_CLAMP	0x96

#define CS35LXX_NG_AMP_EN_MASK		0x3F00
#define CS35LXX_NG_DELAY_MASK		0x70
#define CS35LXX_NG_DELAY_SHIFT		4
#define CS35LXX_AMP_ZC_SHIFT		10
#define CS35LXX_PDM_LDM_ENTER_SHIFT	3
#define CS35LXX_PDM_LDM_EXIT_SHIFT	4

#define CS35LXX_BSTCVRT_K1_MASK		0xFF
#define CS35LXX_BSTCVRT_K2_MASK		0xFF00
#define CS35LXX_BSTCVRT_K2_SHIFT	8
#define CS35LXX_BSTCVRT_SLOPE_MASK	0xFF00
#define CS35LXX_BSTCVRT_SLOPE_SHIFT	8
#define CS35LXX_BSTCVRT_CCMFREQ_MASK	0x0F
#define CS35LXX_BSTCVRT_LBSTVAL_MASK	0x03
#define CS35LXX_BSTCVRT_CTL_MASK	0xFF
#define CS35LXX_BSTCVRT_CTL_SEL_MASK	0x03
#define CS35LXX_DCM_AUTO_MASK		0x01

#define CS35LXX_INT1_MASK_DEFAULT	0xF9BA7FFF
#define CS35LXX_INT1_MASK_RESET		0xFFFFFFFF
#define CS35LXX_INT3_MASK_DEFAULT	0xFFFFEFFF
#define CS35LXX_INT3_MASK_RESET		0xFFFFFFFF


#define CS35LXX_AMP_SHORT_ERR		0x1000
#define CS35LXX_BST_SHORT_ERR		0x40000
#define CS35LXX_TEMP_WARN		0x2000000
#define CS35LXX_TEMP_ERR		0x4000000
#define CS35LXX_BST_OVP_ERR		0x10000
#define CS35LXX_BST_DCM_UVP_ERR		0x20000

#define CS35LXX_AMP_SHORT_ERR_RLS	0x02
#define CS35LXX_BST_SHORT_ERR_RLS	0x04
#define CS35LXX_BST_OVP_ERR_RLS		0x08
#define CS35LXX_BST_UVP_ERR_RLS		0x10
#define CS35LXX_TEMP_WARN_ERR_RLS	0x20
#define CS35LXX_TEMP_ERR_RLS		0x40
#define CS35LXX_TEMP_THLD_MASK		0x03

#define CS35LXX_REV_B0			0xb0
#define CS35LXX_REV_A0			0xa0
#define CS35LXX_B0_PAC_PATCH		0x00DD0102

#define CS35LXX_OTP_ECC_EN_MASK		0x400
#define CS35LXX_OTP_ECC_EN_SHIFT	10
#define CS35LXX_OTP_RUN_BOOT_MASK	0x01
#define CS35LXX_OTP_BOOT_DONE		0x2000000
#define CS35LXX_PAC_RESET_MASK		0x04
#define CS35LXX_PAC_RESET_SHIFT		2
#define CS35LXX_PAC_STALL_MASK		0x02
#define CS35LXX_PAC_STALL_SHIFT		1
#define CS35LXX_PAC_ENABLE_MASK		0x00000001
#define CS35LXX_PAC_MEM_ACCESS		0x01
#define CS35LXX_PAC_MEM_ACCESS_CLR	0
#define CS35LXX_SOFT_RESET		0x5AAA
#define CS35LXX_MCU_BOOT_COMPLETE	0x02
#define CS35LXX_MCU_CONFIG_UNMASK	0x00FEFFFF
#define CS35LXX_MCU_CONFIG_CLR		0x00010000
#define CS35LXX_MCU_CONFIG_MASK		0x00FFFFFF
#define CS35LXX_GPIO_INT_SEL_MASK	0x0000003B
#define CS35LXX_GPIO_INT_SEL_UNMASK	0x0000003A
#define CS35LXX_PAC_RESET		0x00000000
#define CS35LXX_OTP_REV_MASK		0x00FF0000
#define CS35LXX_OTP_REV_L37		0x00CC0000
#define CS35LXX_12V_L37			37
#define CS35LXX_10V_L36			36

#define CS35LXX_VPBR_EN_MASK		0x00001000
#define CS35LXX_VPBR_EN_SHIFT		12

#define CS35LXX_VPBR_THLD_MASK		0x0000001F
#define CS35LXX_VPBR_THLD_SHIFT		0
#define CS35LXX_VPBR_MAX_ATTN_MASK	0x00000F00
#define CS35LXX_VPBR_MAX_ATTN_SHIFT	8
#define CS35LXX_VPBR_ATK_VOL_MASK	0x0000F000
#define CS35LXX_VPBR_ATK_VOL_SHIFT	12
#define CS35LXX_VPBR_ATK_RATE_MASK	0x00070000
#define CS35LXX_VPBR_ATK_RATE_SHIFT	16
#define CS35LXX_VPBR_WAIT_MASK		0x00180000
#define CS35LXX_VPBR_WAIT_SHIFT		19
#define CS35LXX_VPBR_REL_RATE_MASK	0x00E00000
#define CS35LXX_VPBR_REL_RATE_SHIFT	21
#define CS35LXX_VPBR_MUTE_EN_MASK	0x01000000
#define CS35LXX_VPBR_MUTE_EN_SHIFT	24

#define CS35LXX_OSC_FREQ_TRIM_MASK	0x070
#define CS35LXX_OSC_TRIM_DONE		0x08

#define CS35LXX_FS1_DEFAULT_VAL		16
#define CS35LXX_FS2_DEFAULT_VAL		36
#define CS35LXX_FS_NOM_6MHZ		6000000

#define CS35LXX_TEST_UNLOCK1		0x00005555
#define CS35LXX_TEST_UNLOCK2		0x0000AAAA
#define CS35LXX_TEST_LOCK1		0x0000CCCC
#define CS35LXX_TEST_LOCK2		0x00003333

#define CS35LXX_PAC_PROG_MEM		512

#define CS35LXX_RX_FORMATS (SNDRV_PCM_FMTBIT_S16_LE | SNDRV_PCM_FMTBIT_S24_LE)
#define CS35LXX_TX_FORMATS (SNDRV_PCM_FMTBIT_S16_LE | SNDRV_PCM_FMTBIT_S24_LE \
				| SNDRV_PCM_FMTBIT_S32_LE)

extern const int cs35lxx_a0_pac_patch[CS35LXX_PAC_PROG_MEM];

#define CS35LXX_MAGIC_NUMBER	0x32353536

#define CS35LXX_SPK_DAC_VOLUME			_IOWR(CS35LXX_MAGIC_NUMBER, 1, void *)
#define CS35LXX_SPK_POWER_ON			_IOWR(CS35LXX_MAGIC_NUMBER, 2, void *)
#define CS35LXX_SPK_POWER_OFF			_IOWR(CS35LXX_MAGIC_NUMBER, 3, void *)
#define CS35LXX_SPK_DSP_BYPASS			_IOWR(CS35LXX_MAGIC_NUMBER, 4, void *)
#define CS35LXX_SPK_SWITCH_CONFIGURATION	_IOWR(CS35LXX_MAGIC_NUMBER, 5, void *)
#define CS35LXX_SPK_SWITCH_CALIBRATION	_IOWR(CS35LXX_MAGIC_NUMBER, 6, void *)
#define CS35LXX_SPK_GET_R0				_IOWR(CS35LXX_MAGIC_NUMBER, 7, void *)
#define CS35LXX_SPK_GET_F0				_IOWR(CS35LXX_MAGIC_NUMBER, 8, void *)
#define CS35LXX_SPK_GET_CAL_STRUCT		_IOWR(CS35LXX_MAGIC_NUMBER, 9, void *)
#define CS35LXX_SPK_SET_CAL_STRUCT		_IOWR(CS35LXX_MAGIC_NUMBER, 10, void *)
#define CS35LXX_SPK_SET_AMBIENT			_IOWR(CS35LXX_MAGIC_NUMBER, 11, void *)
#define CS35LXX_SPK_SET_R0				_IOWR(CS35LXX_MAGIC_NUMBER, 12, void *)
#define CS35LXX_SPK_SWITCH_FIRMWARE		_IOWR(CS35LXX_MAGIC_NUMBER, 13, void *)
#define CS35LXX_SPK_GET_R0_REALTIME		_IOWR(CS35LXX_MAGIC_NUMBER, 14, void *)
#define CS35LXX_SPK_SET_DEFAULT_CALIB	_IOWR(CS35LXX_MAGIC_NUMBER, 15, void *)
#define CS35LXX_SPK_GET_CALIB_STATE		_IOWR(CS35LXX_MAGIC_NUMBER, 16, void *)
#define CS35LXX_SPK_START_CALIBRATION	_IOWR(CS35LXX_MAGIC_NUMBER, 17, void *)
#define CS35LXX_SPK_STOP_CALIBRATION	_IOWR(CS35LXX_MAGIC_NUMBER, 18, void *)
#define CS35LXX_SPK_START_DIAGNOSTICS	_IOWR(CS35LXX_MAGIC_NUMBER, 19, void *)
#define CS35LXX_SPK_STOP_DIAGNOSTICS	_IOWR(CS35LXX_MAGIC_NUMBER, 20, void *)

#ifdef CONFIG_COMPAT
#define CS35LXX_SPK_DAC_VOLUME_COMPAT	\
								_IOWR(CS35LXX_MAGIC_NUMBER, 1, compat_uptr_t)
#define CS35LXX_SPK_POWER_ON_COMPAT		\
								_IOWR(CS35LXX_MAGIC_NUMBER, 2, compat_uptr_t)
#define CS35LXX_SPK_POWER_OFF_COMPAT	\
								_IOWR(CS35LXX_MAGIC_NUMBER, 3, compat_uptr_t)
#define CS35LXX_SPK_DSP_BYPASS_COMPAT	\
								_IOWR(CS35LXX_MAGIC_NUMBER, 4, compat_uptr_t)
#define CS35LXX_SPK_SWITCH_CONFIGURATION_COMPAT	\
								_IOWR(CS35LXX_MAGIC_NUMBER, 5, compat_uptr_t)
#define CS35LXX_SPK_SWITCH_CALIBRATION_COMPAT	\
								_IOWR(CS35LXX_MAGIC_NUMBER, 6, compat_uptr_t)
#define CS35LXX_SPK_GET_R0_COMPAT	\
								_IOWR(CS35LXX_MAGIC_NUMBER, 7, compat_uptr_t)
#define CS35LXX_SPK_GET_F0_COMPAT	\
								_IOWR(CS35LXX_MAGIC_NUMBER, 8, compat_uptr_t)
#define CS35LXX_SPK_GET_CAL_STRUCT_COMPAT	\
								_IOWR(CS35LXX_MAGIC_NUMBER, 9, compat_uptr_t)
#define CS35LXX_SPK_SET_CAL_STRUCT_COMPAT	\
								_IOWR(CS35LXX_MAGIC_NUMBER, 10, compat_uptr_t)
#define CS35LXX_SPK_SET_AMBIENT_COMPAT	\
								_IOWR(CS35LXX_MAGIC_NUMBER, 11, compat_uptr_t)
#define CS35LXX_SPK_SET_R0_COMPAT	\
								_IOWR(CS35LXX_MAGIC_NUMBER, 12, compat_uptr_t)
#define CS35LXX_SPK_SWITCH_FIRMWARE_COMPAT	\
								_IOWR(CS35LXX_MAGIC_NUMBER, 13, compat_uptr_t)
#define CS35LXX_SPK_GET_R0_REALTIME_COMPAT	\
								_IOWR(CS35LXX_MAGIC_NUMBER, 14, compat_uptr_t)
#define CS35LXX_SPK_SET_DEFAULT_CALIB_COMPAT	\
								_IOWR(CS35LXX_MAGIC_NUMBER, 15, compat_uptr_t)
#define CS35LXX_SPK_GET_CALIB_STATE_COMPAT	\
								_IOWR(CS35LXX_MAGIC_NUMBER, 16, compat_uptr_t)
#define CS35LXX_SPK_START_CALIBRATION_COMPAT	\
								_IOWR(CS35LXX_MAGIC_NUMBER, 17, compat_uptr_t)
#define CS35LXX_SPK_STOP_CALIBRATION_COMPAT	\
								_IOWR(CS35LXX_MAGIC_NUMBER, 18, compat_uptr_t)
#define CS35LXX_SPK_START_DIAGNOSTICS_COMPAT	\
								_IOWR(CS35LXX_MAGIC_NUMBER, 19, compat_uptr_t)
#define CS35LXX_SPK_STOP_DIAGNOSTICS_COMPAT	\
								_IOWR(CS35LXX_MAGIC_NUMBER, 20, compat_uptr_t)
#endif

// Structs for Aurisys API
struct cs35lxx_calib_data {
	int32_t temperature;
	int32_t rdc;
	int32_t status;
	int32_t checksum;
};

struct cs35lxx_calib_cmd {
	int32_t command;
	struct cs35lxx_calib_data data;
};

struct cs35lxx_r0_data {
	int32_t empty1;
	int32_t r0;
	int32_t empty2;
	int32_t empty3;
	int32_t empty4;
};

struct cs35lxx_r0_cmd {
	uint32_t command;
	struct cs35lxx_r0_data data;
};

struct cs35lxx_diagnostics_param {
	int32_t temperature;
	int32_t f0;
	int32_t status;
	int32_t empty2;
	int32_t empty3;
};

struct cs35lxx_diagnostics_cmd {
	uint32_t command;
	struct cs35lxx_diagnostics_param data;
};

enum cs35lxx_cspl_cmd_type {
	CSPL_CMD_CALIBRATION	= 1,
	CSPL_CMD_DIAGNOSTICS	= 2,
	CSPL_CMD_R0				= 3
};


enum cs35lxx_cspl_arsi_command {
	CSPL_CMD_START_CALIBRATION		= 2020,
	CSPL_CMD_STOP_CALIBRATION		= 2021,
	CSPL_CMD_START_DIAGNOSTICS		= 2022,
	CSPL_CMD_STOP_DIAGNOSTICS		= 2023,
	CSPL_CMD_SET_CALIBRATION_PARAM	= 2024,
	CSPL_CMD_GET_CALIBRATION_PARAM	= 2025,
	CSPL_CMD_LIBARAY_READY			= 2026,
	CSPL_CMD_ENABLE_DSPBYPASS		= 2027,
	CSPL_CMD_DISABLE_DSPBYPASS		= 2028,
	CSPL_CMD_GET_R0					= 2029,
	CSPL_CMD_GET_F0					= 2030
};
#endif /* __CS35LXX_H */
