/*
 * Copyright (C) 2013 Samsung Electronics
 *
 * License terms: GNU General Public License (GPL) version 2
 */

#include <asm/hardware/gic.h>

#include <mach/pxa988.h>
#include <mach/mfp-pxa986-lt02.h>
#include "board-lt02.h"
#include "common.h"

static unsigned long lt02_r0_0_pins[] __initdata = {
	GPIO000_GPIO_0 | MFP_LPM_INPUT,		/* VOL_UP */
	GPIO001_GPIO_1 | MFP_LPM_INPUT,		/* VOL_DN */
	GPIO013_GPIO_13 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* HOME KEY */
#ifdef CONFIG_SEC_IRLED
	GPIO002_GPIO_2 | MFP_LPM_DRIVE_LOW,	/* IRDA_LED_EN */
	GPIO004_GPIO_4 | MFP_LPM_DRIVE_LOW,	/* IRDA_WAKE */
#endif

#define GPIO005_CHG_INT	                GPIO005_GPIO_5
	GPIO005_CHG_INT | MFP_LPM_INPUT,	/* VSYS_OK */
	GPIO006_GPIO_6,	/* AP_AGPS_RESETn */
	GPIO007_GPIO_7,	/* AP_AGPS_ONOFF */
	GPIO008_GPIO_8 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* FET_EN */
#define GPIO09_LCD_BL_CTRL		GPIO009_GPIO_9 | MFP_LPM_DRIVE_LOW

	//GPIO09_LCD_BL_CTRL,
	GPIO009_GPIO_9 | MFP_PULL_HIGH,
	GPIO010_GPIO_10 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* ACC_INT */
	GPIO011_GPIO_11 | MFP_LPM_INPUT | MFP_PULL_LOW,	/* 3G_DCDC_EN */
	GPIO012_GPIO_12 | MFP_PULL_HIGH | MFP_LPM_INPUT,	/* COM_DET */
	//GPIO013_KP_DKIN4,
	GPIO014_GPIO_14 | MFP_LPM_DRIVE_LOW,	/* 5M_CAM_STBY */
	GPIO015_GPIO_15 | MFP_LPM_DRIVE_LOW,	/* 5M_CAM_RST */
	GPIO016_GPIO_16 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* GPIO SCL */
	GPIO017_GPIO_17 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* GPIO SDA */
	GPIO018_GPIO_18 | MFP_LPM_DRIVE_LOW | MFP_PULL_LOW,	/* LVDS_RST */
	GPIO019_GPIO_19 | MFP_LPM_DRIVE_LOW,	/* LCD_EN */
	GPIO020_GPIO_20 | MFP_LPM_DRIVE_LOW,	/* TSP_LDO_ON */

	/*
	 * configure to be GPIO input to avoid leakage in production
	 * mode. would configure it to I2S MFP in sound start up
	 * function.
	 */
	GPIO021_GPIO_INPUT,
	GPIO022_GPIO_INPUT,
	GPIO023_GPIO_INPUT,
	GPIO024_GPIO_INPUT,

	GPIO025_GSSP_SCLK,	/* PCM_CLK */
	GPIO026_GSSP_SFRM,	/* PCM_SYNC */
	GPIO027_GSSP_TXD,	/* PCM_TXD */
	GPIO028_GSSP_RXD,	/* PCM_RXD */

	GPIO029_GPS_CTS,
	GPIO030_GPS_RTS,

	GPIO031_GPIO_31 | MFP_LPM_DRIVE_LOW,	/* HP_MUTE */
	GPIO032_GPIO_32 | MFP_PULL_FLOAT,	/* HW_REV_MOD_2 */

	GPIO033_GPIO_33 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* CHG_STAT */
	GPIO034_GPIO_34 | MFP_PULL_FLOAT,		/* WLAN_BT_RESET */
	GPIO035_GPIO_35 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* SNSR_I2C_SCL */
	GPIO036_GPIO_36 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* SNSR_I2C_SDA */

	/* MMC2 WIB */
	GPIO037_MMC2_DATA3,	/* WLAN_DAT3 */
	GPIO038_MMC2_DATA2,	/* WLAN_DAT2 */
	GPIO039_MMC2_DATA1,	/* WLAN_DAT1 */
	GPIO040_MMC2_DATA0,	/* WLAN_DAT0 */
	GPIO041_MMC2_CMD,	/* WLAN_CMD */
	GPIO042_MMC2_CLK,	/* WLAN_CLK */

#define GPIO043_GPIO_DVC1	(GPIO043_GPIO_43)
#define GPIO044_GPIO_DVC2	(GPIO044_GPIO_44)
	GPIO043_GPIO_DVC1,
	GPIO044_GPIO_DVC2,

	GPIO045_UART2_RXD,	/* GPS_UART_RXD */
	GPIO046_UART2_TXD,	/* GPS_UART_TXD */

	GPIO047_UART1_RXD,	/* AP_RXD */
	GPIO048_UART1_TXD,	/* AP_TXD */

#define GPIO049_GPIO_BARA_INT2	GPIO049_GPIO_49
#define GPIO050_GPIO_BARA_INT1	GPIO050_GPIO_50
	GPIO049_GPIO_BARA_INT2 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	GPIO050_GPIO_BARA_INT1 | MFP_LPM_INPUT | MFP_PULL_HIGH,

	//GPIO051_FUEL_SCL,
	//GPIO052_FUEL_SDA,
	GPIO051_GPIO_51,
	GPIO052_GPIO_52,

//	GPIO053_CI2C_SCL | MFP_LPM_FLOAT,	/* Main CAM I2C_SCL */
//	GPIO054_CI2C_SDA | MFP_LPM_FLOAT,	/* Main CAM I2C_SDA */
	GPIO053_GPIO_53,	/* GRIP_I2C_SCL */
	GPIO054_GPIO_54,	/* GRIP_I2C_SDA */
	GPIO067_CCIC_IN7,
	GPIO068_CCIC_IN6,
	GPIO069_CCIC_IN5,
	GPIO070_CCIC_IN4,
	GPIO071_CCIC_IN3,
	GPIO072_CCIC_IN2,
	GPIO073_CCIC_IN1,
	GPIO074_CCIC_IN0,
	GPIO075_CAM_HSYNC,
	GPIO076_CAM_VSYNC,
	GPIO077_CAM_MCLK,
	GPIO078_CAM_PCLK,

	GPIO079_CAM_SCL,	/* Sub CAM I2C_SCL */
	GPIO080_CAM_SDA,	/* Sub CAM I2C_SDA */
	//GPIO079_GPIO_79 | MFP_PULL_FLOAT,
	//GPIO080_GPIO_80 | MFP_PULL_FLOAT,

	GPIO081_GPIO_81 | MFP_LPM_INPUT,	/* CAM_VGA_nSTBY */
	GPIO082_GPIO_82 | MFP_LPM_INPUT,	/* CAM_VGA_nRST */	

	GPIO083_GPIO_83 | MFP_LPM_INPUT,	/* HOST_WU_WLAN */
	GPIO084_GPIO_84 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* WLAN_WU_HOST */

	GPIO085_GPIO_85 | MFP_LPM_INPUT,	/* HW_REV_MOD1 */
	GPIO086_GPIO_86 | MFP_LPM_INPUT,	/* HW_REV_MOD0 */

	GPIO087_CI2C_SCL_2,	/* I2C4_CLK_LVDS */
	GPIO088_CI2C_SDA_2,	/* I2C4_DATA_LVDS */

	GPIO089_GPIO_89,	/* GPS_ECLK: GPIO by default */
	GPIO090_GPIO_90 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* TFLASH_DETECT */

	GPIO091_GPIO_91 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* GPIO91 */
	GPIO092_GPIO_92 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* PROXI INT */
	GPIO093_GPIO_93 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* MUIC INT */
	GPIO094_GPIO_94 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* TSP INT */
	GPIO095_GPIO_95 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* FEUL ALERT */

#ifdef CONFIG_SEC_IRLED
	GPIO096_GPIO_96 | MFP_LPM_INPUT,	/* IRDA INT */
#endif
	GPIO097_GPIO_97 | MFP_LPM_INPUT | MFP_PULL_LOW,	/* LCD BL EN */
	GPIO098_GPIO_98 | MFP_LPM_INPUT | MFP_PULL_LOW,	/* CHG_EN */
	CLK_REQ_GPIO_123 | MFP_PULL_FLOAT,	/* WLAN PD */
	GPIO124_GPIO_124 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* CODEC_INTN */

	/* MMC1 Micro SD */
	MMC1_DAT7_MMC1_DAT7 | MFP_PULL_LOW | MFP_LPM_FLOAT,
	MMC1_DAT6_MMC1_DAT6 | MFP_PULL_LOW | MFP_LPM_FLOAT,
	MMC1_DAT5_MMC1_DAT5 | MFP_PULL_LOW | MFP_LPM_FLOAT,
	MMC1_DAT4_MMC1_DAT4 | MFP_PULL_LOW | MFP_LPM_FLOAT,
	MMC1_DAT3_MMC1_DAT3,
	MMC1_DAT2_MMC1_DAT2,
	MMC1_DAT1_MMC1_DAT1,
	MMC1_DAT0_MMC1_DAT0,
	MMC1_CMD_MMC1_CMD,
	MMC1_CLK_MMC1_CLK | MFP_LPM_DRIVE_HIGH | MFP_DS01X,
	MMC1_CD_MMC1_CD | MFP_PULL_HIGH,
	MMC1_WP_MMC1_WP | MFP_PULL_HIGH | MFP_LPM_FLOAT,

	/* MMC3 16GB EMMC */
	ND_IO7_MMC3_DAT7,
	ND_IO6_MMC3_DAT6,
	ND_IO5_MMC3_DAT5,
	ND_IO4_MMC3_DAT4,
	ND_IO3_MMC3_DAT3,
	ND_IO2_MMC3_DAT2,
	ND_IO1_MMC3_DAT1,
	ND_IO0_MMC3_DAT0,
	ND_CLE_SM_OEN_MMC3_CMD,
	SM_SCLK_MMC3_CLK | MFP_LPM_DRIVE_HIGH,
	SM_BEN0_MMC3_RSTN | MFP_LPM_DRIVE_LOW,

#define GPIO_GPS_TIMER_SYNC	ANT_SW4_GPIO_28
//#define GPIO_LCD_RESET_N	ND_RDY1_GPIO_1
#define GPIO_LED_B_CTRL		SM_ADVMUX_GPIO_2
#define GPIO_LED_R_CTRL		SM_BEN1_GPIO_127
#define GPIO_LED_G_CTRL		SM_CSN0_GPIO_103
#define GPIO_VT_2_8_EN		(SM_CSN0_GPIO_103 | MFP_LPM_DRIVE_LOW)
#define GPIO_GPS_LDO_EN		(SM_CSN1_GPIO_104 | MFP_PULL_FLOAT)
#define GPIO_VT_1_8_EN		(SM_CSN1_GPIO_104 | MFP_LPM_DRIVE_LOW)
#define GPIO_VCM_PWDN		ND_CS1N3_GPIO_102
	GPIO_GPS_TIMER_SYNC,						/* Not used rev0.2 */
//	GPIO_LCD_RESET_N | MFP_PULL_FLOAT,				/* Not used rev0.2 */
	//GPIO_LED_B_CTRL | MFP_PULL_FLOAT | MFP_LPM_FLOAT,		/* GPIO2 already used */
	GPIO_LED_R_CTRL | MFP_LPM_DRIVE_LOW,		/* Not used rev0.2 */
	GPIO_VT_2_8_EN,
	GPIO_VT_1_8_EN,
	GPIO_VCM_PWDN,							/* Not used rev0.2 */
	/* SM_RDY pin Low for download mode, High for normal boot */
	SM_RDY_GPIO_3 | MFP_PULL_HIGH,

	ND_IO15_ND_DAT15 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO14_ND_DAT14 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO13_ND_DAT13 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO12_ND_DAT12 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO11_ND_DAT11 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO10_ND_DAT10 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO9_ND_DAT9 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO8_ND_DAT8 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	//ND_nCS0_SM_nCS2 | MFP_PULL_LOW | MFP_LPM_FLOAT,
#ifdef CONFIG_WIFIONLY_BOARD
  	ND_CS0N2_GPIO_101 | MFP_LPM_DRIVE_LOW,			/* USIM1_DET */
#else
	ND_CS0N2_GPIO_101 | MFP_LPM_INPUT,				/* USIM1_DET */
#endif
	ND_CS1N3_GPIO_102 | MFP_PULL_HIGH,
	DF_ALE_SM_WEn_ND_ALE | MFP_LPM_FLOAT,				/* Not used rev0.2 */
	//DF_WEn_DF_WEn | MFP_LPM_FLOAT,
	GPIO_RF_TOUCH_INT2 | MFP_PULL_HIGH | MFP_LPM_INPUT,		/* RF_TOUCH_INT2 */ /* GPIO105 */
	GPIO_RF_TOUCH_EN | MFP_PULL_HIGH | MFP_LPM_INPUT,				/* RF_TOUCH_EN */ /* GPIO106 */
	GPIO_RF_TOUCH_INT | MFP_LPM_INPUT ,				/* RF_TOUCH_INT */ /* GPIO108 */
#define PWM4_LCD_VCXO_OUT              VCXO_OUT_PWM_4
	PWM4_LCD_VCXO_OUT,						/* Not used rev0.2 */
};

static unsigned long lt02_r0_1_pins[] __initdata = {
	GPIO000_GPIO_0 | MFP_LPM_INPUT,		/* VOL_UP */
	GPIO001_GPIO_1 | MFP_LPM_INPUT,		/* VOL_DN */
	GPIO013_GPIO_13 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* HOME KEY */
#ifdef CONFIG_SEC_IRLED
	GPIO002_GPIO_2 | MFP_LPM_DRIVE_LOW,	/* IRDA_LED_EN */
	GPIO004_GPIO_4 | MFP_LPM_DRIVE_LOW,	/* IRDA_WAKE */
#endif
#define GPIO005_CHG_INT	                GPIO005_GPIO_5
	GPIO005_CHG_INT | MFP_LPM_INPUT,	/* VSYS_OK */
	GPIO006_GPIO_6,	/* AP_AGPS_RESETn */
	GPIO007_GPIO_7,	/* AP_AGPS_ONOFF */
	GPIO008_GPIO_8 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* FET_EN */

	GPIO009_GPIO_9 | MFP_PULL_HIGH,						/* Not Connected */
	GPIO010_GPIO_10 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* ACC_INT */
	GPIO011_GPIO_11 | MFP_LPM_INPUT | MFP_PULL_LOW,	/* 3G_DCDC_EN */
	GPIO012_GPIO_12 | MFP_PULL_HIGH | MFP_LPM_INPUT,	/* COM_DET */
	//GPIO013_KP_DKIN4,
	GPIO014_GPIO_14 | MFP_LPM_DRIVE_LOW,	/* 5M_CAM_STBY */
	GPIO015_GPIO_15 | MFP_LPM_DRIVE_LOW,	/* 5M_CAM_RST */
	GPIO016_GPIO_16 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* GPIO SCL */
	GPIO017_GPIO_17 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* GPIO SDA */
	GPIO018_GPIO_18 | MFP_LPM_DRIVE_LOW | MFP_PULL_LOW,	/* LVDS_RST */
	GPIO019_GPIO_19 | MFP_LPM_DRIVE_LOW,	/* LCD_EN */
	GPIO020_GPIO_20 | MFP_LPM_DRIVE_LOW,	/* TSP_LDO_ON */

	/*
	 * configure to be GPIO input to avoid leakage in production
	 * mode. would configure it to I2S MFP in sound start up
	 * function.
	 */
	GPIO021_GPIO_INPUT,
	GPIO022_GPIO_INPUT,
	GPIO023_GPIO_INPUT,
	GPIO024_GPIO_INPUT,

	GPIO025_GSSP_SCLK,	/* PCM_CLK */
	GPIO026_GSSP_SFRM,	/* PCM_SYNC */
	GPIO027_GSSP_TXD,	/* PCM_TXD */
	GPIO028_GSSP_RXD,	/* PCM_RXD */

	GPIO029_GPS_CTS,
	GPIO030_GPS_RTS,

	GPIO031_GPIO_31 | MFP_LPM_INPUT | MFP_PULL_LOW,		/* NC */
	GPIO032_GPIO_32 | MFP_PULL_FLOAT,	/* HW_REV_MOD_2 */

	GPIO033_GPIO_33 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* CHG_STAT */
	GPIO034_GPIO_34 | MFP_PULL_FLOAT,		/* WLAN_BT_RESET */
	GPIO035_GPIO_35 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* SNSR_I2C_SCL */
	GPIO036_GPIO_36 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* SNSR_I2C_SDA */

	/* MMC2 WIB */
	GPIO037_MMC2_DATA3,	/* WLAN_DAT3 */
	GPIO038_MMC2_DATA2,	/* WLAN_DAT2 */
	GPIO039_MMC2_DATA1,	/* WLAN_DAT1 */
	GPIO040_MMC2_DATA0,	/* WLAN_DAT0 */
	GPIO041_MMC2_CMD,	/* WLAN_CMD */
	GPIO042_MMC2_CLK,	/* WLAN_CLK */

#define GPIO043_GPIO_DVC1	(GPIO043_GPIO_43 | MFP_PULL_FLOAT)
#define GPIO044_GPIO_DVC2	(GPIO044_GPIO_44 | MFP_PULL_FLOAT)
	GPIO043_GPIO_DVC1,
	GPIO044_GPIO_DVC2,

	GPIO045_UART2_RXD,	/* GPS_UART_RXD */
	GPIO046_UART2_TXD,	/* GPS_UART_TXD */

	GPIO047_UART1_RXD,	/* AP_RXD */
	GPIO048_UART1_TXD,	/* AP_TXD */

#define GPIO049_GPIO_BARA_INT2	GPIO049_GPIO_49
#define GPIO050_GPIO_BARA_INT1	GPIO050_GPIO_50
	GPIO049_GPIO_BARA_INT2 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	GPIO050_GPIO_BARA_INT1 | MFP_LPM_INPUT | MFP_PULL_HIGH,

	//GPIO051_FUEL_SCL | MFP_PULL_FLOAT,
	//GPIO052_FUEL_SDA | MFP_PULL_FLOAT,
	GPIO051_GPIO_51,
	GPIO052_GPIO_52,

	GPIO053_GPIO_53,	/* GRIP_I2C_SCL */
	GPIO054_GPIO_54,	/* GRIP_I2C_SDA */
	GPIO067_CCIC_IN7,
	GPIO068_CCIC_IN6,
	GPIO069_CCIC_IN5,
	GPIO070_CCIC_IN4,
	GPIO071_CCIC_IN3,
	GPIO072_CCIC_IN2,
	GPIO073_CCIC_IN1,
	GPIO074_CCIC_IN0,
	GPIO075_CAM_HSYNC,
	GPIO076_CAM_VSYNC,
	GPIO077_CAM_MCLK,
	GPIO078_CAM_PCLK,

	GPIO079_CAM_SCL,	/* Sub CAM I2C_SCL */
	GPIO080_CAM_SDA,	/* Sub CAM I2C_SDA */

	GPIO081_GPIO_81 | MFP_LPM_DRIVE_LOW | MFP_PULL_LOW, /* CAM_VGA_nSTBY */
	GPIO082_GPIO_82 | MFP_LPM_DRIVE_LOW | MFP_PULL_LOW, /* CAM_VGA_nRST */

	GPIO083_GPIO_83 | MFP_LPM_INPUT,	/* HOST_WU_WLAN */
	GPIO084_GPIO_84 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* WLAN_WU_HOST */

	GPIO085_GPIO_85 | MFP_LPM_INPUT,	/* HW_REV_MOD1 */
	GPIO086_GPIO_86 | MFP_LPM_INPUT,	/* HW_REV_MOD0 */

	GPIO087_CI2C_SCL_2 | MFP_LPM_FLOAT, /* I2C4_CLK_LVDS */
	GPIO088_CI2C_SDA_2 | MFP_LPM_FLOAT, /* I2C4_DATA_LVDS */

	GPIO089_GPIO_89,	/* GPS_ECLK: GPIO by default */
	GPIO090_GPIO_90 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* TFLASH_DETECT */

#ifdef CONFIG_SEC_IRLED
	GPIO091_GPIO_91 | MFP_LPM_INPUT,	/* IRDA_IRQ */
#endif
	GPIO092_GPIO_92 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* PROXI INT */
	GPIO093_GPIO_93 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* MUIC INT */
	GPIO094_GPIO_94 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* TSP INT */
	GPIO095_GPIO_95 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* FEUL ALERT */

	GPIO096_GPIO_96 | MFP_LPM_DRIVE_LOW | MFP_PULL_FLOAT,	/* TSP_LDO_ON */
	GPIO097_GPIO_97 | MFP_LPM_DRIVE_LOW | MFP_PULL_FLOAT,	/* LCD BL EN */
	GPIO098_GPIO_98 | MFP_LPM_INPUT | MFP_PULL_LOW,	/* Not used LT02 rev0.1 */
	CLK_REQ_GPIO_123 | MFP_PULL_FLOAT,	/* WLAN PD */
	GPIO124_GPIO_124 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* CODEC_INTN */

	/* MMC1 Micro SD */
	MMC1_DAT7_MMC1_DAT7 | MFP_PULL_LOW | MFP_LPM_FLOAT,
	MMC1_DAT6_MMC1_DAT6 | MFP_PULL_LOW | MFP_LPM_FLOAT,
	MMC1_DAT5_MMC1_DAT5 | MFP_PULL_LOW | MFP_LPM_FLOAT,
	MMC1_DAT4_MMC1_DAT4 | MFP_PULL_LOW | MFP_LPM_FLOAT,
	MMC1_DAT3_MMC1_DAT3,
	MMC1_DAT2_MMC1_DAT2,
	MMC1_DAT1_MMC1_DAT1,
	MMC1_DAT0_MMC1_DAT0,
	MMC1_CMD_MMC1_CMD,
	MMC1_CLK_MMC1_CLK | MFP_LPM_DRIVE_HIGH | MFP_DS01X,
	MMC1_CD_MMC1_CD | MFP_PULL_HIGH,
	MMC1_WP_MMC1_WP | MFP_PULL_HIGH | MFP_LPM_FLOAT,

	/* MMC3 16GB EMMC */
	ND_IO7_MMC3_DAT7,
	ND_IO6_MMC3_DAT6,
	ND_IO5_MMC3_DAT5,
	ND_IO4_MMC3_DAT4,
	ND_IO3_MMC3_DAT3,
	ND_IO2_MMC3_DAT2,
	ND_IO1_MMC3_DAT1,
	ND_IO0_MMC3_DAT0,
	ND_CLE_SM_OEN_MMC3_CMD,
	SM_SCLK_MMC3_CLK | MFP_LPM_DRIVE_HIGH,
	SM_BEN0_MMC3_RSTN | MFP_LPM_DRIVE_LOW,

#define GPIO_GPS_TIMER_SYNC	ANT_SW4_GPIO_28
//#define GPIO_LCD_RESET_N	ND_RDY1_GPIO_1
#define GPIO_LED_B_CTRL		SM_ADVMUX_GPIO_2
#define GPIO_LED_R_CTRL		SM_BEN1_GPIO_127
#define GPIO_LED_G_CTRL		SM_CSN0_GPIO_103
#define GPIO_VT_2_8_EN		(SM_CSN0_GPIO_103 | MFP_LPM_DRIVE_LOW)
#define GPIO_GPS_LDO_EN		(SM_CSN1_GPIO_104 | MFP_PULL_FLOAT)
#define GPIO_VT_1_8_EN		(SM_CSN1_GPIO_104 | MFP_LPM_DRIVE_LOW)
#define GPIO_VCM_PWDN		ND_CS1N3_GPIO_102
	GPIO_GPS_TIMER_SYNC,						/* Not used rev0.2 */
//	GPIO_LCD_RESET_N | MFP_PULL_FLOAT,				/* Not used rev0.2 */
	//GPIO_LED_B_CTRL | MFP_PULL_FLOAT | MFP_LPM_FLOAT,		/* GPIO2 already used */
	//GPIO_LED_R_CTRL | MFP_PULL_FLOAT | MFP_LPM_FLOAT,		/* Not used rev0.2 */
#ifdef CONFIG_SEC_IRLED
	SM_BEN0_GPIO_126,		/* IRDA_SCL */
	SM_BEN1_GPIO_127,		/* IRDA_SDA */
#endif
	GPIO_VT_2_8_EN,
	GPIO_VT_1_8_EN,
	GPIO_VCM_PWDN,							/* Not used rev0.2 */
	/* SM_RDY pin Low for download mode, High for normal boot */
	SM_RDY_GPIO_3 | MFP_PULL_HIGH,

	ND_IO15_ND_DAT15 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO14_ND_DAT14 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO13_ND_DAT13 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO12_ND_DAT12 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO11_ND_DAT11 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO10_ND_DAT10 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO9_ND_DAT9 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO8_ND_DAT8 | MFP_LPM_INPUT | MFP_PULL_HIGH,			/* NC */
	//ND_nCS0_SM_nCS2 | MFP_PULL_LOW | MFP_LPM_FLOAT,
#ifdef CONFIG_WIFIONLY_BOARD
  	ND_CS0N2_GPIO_101 | MFP_LPM_DRIVE_LOW,			/* USIM1_DET */
#else
	ND_CS0N2_GPIO_101 | MFP_LPM_INPUT,				/* USIM1_DET */
#endif
	ND_CS1N3_GPIO_102 | MFP_PULL_HIGH,
	DF_ALE_SM_WEn_ND_ALE | MFP_LPM_INPUT | MFP_PULL_LOW,			/* NC */
	//DF_WEn_DF_WEn | MFP_LPM_FLOAT,
	GPIO_RF_TOUCH_INT2 | MFP_PULL_HIGH | MFP_LPM_INPUT,		/* RF_TOUCH_INT2 */ /* GPIO105 */
	GPIO_RF_TOUCH_EN | MFP_PULL_HIGH | MFP_LPM_INPUT,				/* RF_TOUCH_EN */ /* GPIO106 */
	GPIO_RF_TOUCH_INT | MFP_LPM_INPUT,				/* RF_TOUCH_INT */ /* GPIO108 */
#define PWM4_LCD_VCXO_OUT              VCXO_OUT_PWM_4
	PWM4_LCD_VCXO_OUT,
};


static unsigned long lt02_r0_3_pins[] __initdata = {
	GPIO000_GPIO_0 | MFP_LPM_INPUT,		/* VOL_UP */
	GPIO001_GPIO_1 | MFP_LPM_INPUT,		/* VOL_DN */
	GPIO013_GPIO_13 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* HOME KEY */
#ifdef CONFIG_SEC_IRLED
	GPIO002_GPIO_2 | MFP_LPM_DRIVE_LOW,	/* IRDA_LED_EN */
	GPIO004_GPIO_4 | MFP_LPM_DRIVE_LOW,	/* IRDA_WAKE */
#endif
#define GPIO005_CHG_INT	                GPIO005_GPIO_5
	GPIO005_CHG_INT | MFP_LPM_INPUT,	/* VSYS_OK */
	GPIO006_GPIO_6,	/* AP_AGPS_RESETn */
	GPIO007_GPIO_7,	/* AP_AGPS_ONOFF */
	GPIO008_GPIO_8 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* FET_EN */

	GPIO009_GPIO_9 | MFP_PULL_HIGH,						/* Not Connected */
	GPIO010_GPIO_10 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* ACC_INT */
	GPIO011_GPIO_11 | MFP_LPM_INPUT | MFP_PULL_LOW,	/* 3G_DCDC_EN */
	GPIO012_GPIO_12 | MFP_PULL_HIGH | MFP_LPM_INPUT,	/* COM_DET */
	//GPIO013_KP_DKIN4,
	GPIO014_GPIO_14 | MFP_LPM_DRIVE_LOW,	/* 5M_CAM_STBY */
	GPIO015_GPIO_15 | MFP_LPM_DRIVE_LOW,	/* 5M_CAM_RST */
	GPIO016_GPIO_16 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* GPIO SCL */
	GPIO017_GPIO_17 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* GPIO SDA */
	GPIO018_GPIO_18 | MFP_LPM_DRIVE_LOW | MFP_PULL_LOW,	/* LVDS_RST */
	GPIO019_GPIO_19 | MFP_LPM_DRIVE_LOW,	/* LCD_EN */
	GPIO020_GPIO_20 | MFP_LPM_DRIVE_LOW,	/* TSP_LDO_ON */

	/*
	 * configure to be GPIO input to avoid leakage in production
	 * mode. would configure it to I2S MFP in sound start up
	 * function.
	 */
	GPIO021_GPIO_INPUT,
	GPIO022_GPIO_INPUT,
	GPIO023_GPIO_INPUT,
	GPIO024_GPIO_INPUT,

	GPIO025_GSSP_SCLK,	/* PCM_CLK */
	GPIO026_GSSP_SFRM,	/* PCM_SYNC */
	GPIO027_GSSP_TXD,	/* PCM_TXD */
	GPIO028_GSSP_RXD,	/* PCM_RXD */

	GPIO029_GPS_CTS,
	GPIO030_GPS_RTS,

	GPIO032_GPIO_32 | MFP_PULL_FLOAT,	/* HW_REV_MOD_2 */

	GPIO033_GPIO_33 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* CHG_STAT */
	GPIO034_GPIO_34 | MFP_PULL_FLOAT,		/* WLAN_BT_RESET */
	GPIO035_GPIO_35 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* SNSR_I2C_SCL */
	GPIO036_GPIO_36 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* SNSR_I2C_SDA */

	/* MMC2 WIB */
	GPIO037_MMC2_DATA3,	/* WLAN_DAT3 */
	GPIO038_MMC2_DATA2,	/* WLAN_DAT2 */
	GPIO039_MMC2_DATA1,	/* WLAN_DAT1 */
	GPIO040_MMC2_DATA0,	/* WLAN_DAT0 */
	GPIO041_MMC2_CMD,	/* WLAN_CMD */
	GPIO042_MMC2_CLK,	/* WLAN_CLK */

#define GPIO043_GPIO_DVC1	(GPIO043_GPIO_43 | MFP_PULL_FLOAT)
#define GPIO044_GPIO_DVC2	(GPIO044_GPIO_44 | MFP_PULL_FLOAT)
	GPIO043_GPIO_DVC1,
	GPIO044_GPIO_DVC2,

	GPIO045_UART2_RXD,	/* GPS_UART_RXD */
	GPIO046_UART2_TXD,	/* GPS_UART_TXD */

	GPIO047_UART1_RXD,	/* AP_RXD */
	GPIO048_UART1_TXD,	/* AP_TXD */

#define GPIO049_GPIO_BARA_INT2	GPIO049_GPIO_49
#define GPIO050_GPIO_BARA_INT1	GPIO050_GPIO_50
	GPIO049_GPIO_BARA_INT2 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	GPIO050_GPIO_BARA_INT1 | MFP_LPM_INPUT | MFP_PULL_HIGH,

	//GPIO051_FUEL_SCL | MFP_PULL_FLOAT,
	//GPIO052_FUEL_SDA | MFP_PULL_FLOAT,
	GPIO051_GPIO_51,
	GPIO052_GPIO_52,

	GPIO053_GPIO_53,	/* GRIP_I2C_SCL */
	GPIO054_GPIO_54,	/* GRIP_I2C_SDA */
	GPIO067_CCIC_IN7,
	GPIO068_CCIC_IN6,
	GPIO069_CCIC_IN5,
	GPIO070_CCIC_IN4,
	GPIO071_CCIC_IN3,
	GPIO072_CCIC_IN2,
	GPIO073_CCIC_IN1,
	GPIO074_CCIC_IN0,
	GPIO075_CAM_HSYNC,
	GPIO076_CAM_VSYNC,
	GPIO077_CAM_MCLK,
	GPIO078_CAM_PCLK,

	GPIO079_CAM_SCL,	/* Sub CAM I2C_SCL */
	GPIO080_CAM_SDA,	/* Sub CAM I2C_SDA */

	GPIO081_GPIO_81 | MFP_LPM_DRIVE_LOW | MFP_PULL_LOW, /* CAM_VGA_nSTBY */
	GPIO082_GPIO_82 | MFP_LPM_DRIVE_LOW | MFP_PULL_LOW, /* CAM_VGA_nRST */

	GPIO083_GPIO_83 | MFP_LPM_INPUT,	/* HOST_WU_WLAN */
	GPIO084_GPIO_84 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* WLAN_WU_HOST */

	GPIO085_GPIO_85 | MFP_LPM_INPUT,	/* HW_REV_MOD1 */
	GPIO086_GPIO_86 | MFP_LPM_INPUT,	/* HW_REV_MOD0 */

	GPIO087_CI2C_SCL_2 | MFP_LPM_FLOAT, /* I2C4_CLK_LVDS */
	GPIO088_CI2C_SDA_2 | MFP_LPM_FLOAT, /* I2C4_DATA_LVDS */

	GPIO089_GPIO_89,	/* GPS_ECLK: GPIO by default */
	GPIO090_GPIO_90 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* TFLASH_DETECT */

#ifdef CONFIG_SEC_IRLED
	GPIO091_GPIO_91 | MFP_LPM_INPUT,	/* IRDA_IRQ */
#endif
	GPIO092_GPIO_92 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* PROXI INT */
	GPIO093_GPIO_93 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* MUIC INT */
	GPIO094_GPIO_94 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* TSP INT */
	GPIO095_GPIO_95 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* FEUL ALERT */

	GPIO096_GPIO_96 | MFP_LPM_DRIVE_LOW | MFP_PULL_FLOAT,	/* TSP_LDO_ON */
	GPIO097_GPIO_97 | MFP_LPM_DRIVE_LOW | MFP_PULL_FLOAT,	/* LCD BL EN */
	GPIO098_GPIO_98 | MFP_LPM_INPUT | MFP_PULL_LOW,	/* Not used LT02 rev0.1 */
	CLK_REQ_GPIO_123 | MFP_PULL_FLOAT,	/* WLAN PD */
	GPIO124_GPIO_124 | MFP_LPM_INPUT | MFP_PULL_HIGH,	/* CODEC_INTN */

	/* MMC1 Micro SD */
	MMC1_DAT7_MMC1_DAT7 | MFP_PULL_LOW | MFP_LPM_FLOAT,
	MMC1_DAT6_MMC1_DAT6 | MFP_PULL_LOW | MFP_LPM_FLOAT,
	MMC1_DAT5_MMC1_DAT5 | MFP_PULL_LOW | MFP_LPM_FLOAT,
	MMC1_DAT4_MMC1_DAT4 | MFP_PULL_LOW | MFP_LPM_FLOAT,
	MMC1_DAT3_MMC1_DAT3,
	MMC1_DAT2_MMC1_DAT2,
	MMC1_DAT1_MMC1_DAT1,
	MMC1_DAT0_MMC1_DAT0,
	MMC1_CMD_MMC1_CMD,
	MMC1_CLK_MMC1_CLK | MFP_LPM_DRIVE_HIGH | MFP_DS01X,
	MMC1_CD_MMC1_CD | MFP_PULL_HIGH,
	MMC1_WP_MMC1_WP | MFP_PULL_HIGH | MFP_LPM_FLOAT,

	/* MMC3 16GB EMMC */
	ND_IO7_MMC3_DAT7,
	ND_IO6_MMC3_DAT6,
	ND_IO5_MMC3_DAT5,
	ND_IO4_MMC3_DAT4,
	ND_IO3_MMC3_DAT3,
	ND_IO2_MMC3_DAT2,
	ND_IO1_MMC3_DAT1,
	ND_IO0_MMC3_DAT0,
	ND_CLE_SM_OEN_MMC3_CMD,
	SM_SCLK_MMC3_CLK | MFP_LPM_DRIVE_HIGH,
	SM_BEN0_MMC3_RSTN | MFP_LPM_DRIVE_LOW,

#define GPIO_GPS_TIMER_SYNC	ANT_SW4_GPIO_28
//#define GPIO_LCD_RESET_N	ND_RDY1_GPIO_1
#define GPIO_LED_B_CTRL		SM_ADVMUX_GPIO_2
#define GPIO_LED_R_CTRL		SM_BEN1_GPIO_127
#define GPIO_LED_G_CTRL		SM_CSN0_GPIO_103
#define GPIO_VT_2_8_EN		(SM_CSN0_GPIO_103 | MFP_LPM_DRIVE_LOW)
#define GPIO_GPS_LDO_EN		(SM_CSN1_GPIO_104 | MFP_PULL_FLOAT)
#define GPIO_VT_1_8_EN		(SM_CSN1_GPIO_104 | MFP_LPM_DRIVE_LOW)
#define GPIO_VCM_PWDN		ND_CS1N3_GPIO_102
	GPIO_GPS_TIMER_SYNC,						/* Not used rev0.2 */
//	GPIO_LCD_RESET_N | MFP_PULL_FLOAT,				/* Not used rev0.2 */
	//GPIO_LED_B_CTRL | MFP_PULL_FLOAT | MFP_LPM_FLOAT,		/* GPIO2 already used */
	//GPIO_LED_R_CTRL | MFP_PULL_FLOAT | MFP_LPM_FLOAT,		/* Not used rev0.2 */
#ifdef CONFIG_SEC_IRLED
	SM_BEN0_GPIO_126,		/* IRDA_SCL */
	SM_BEN1_GPIO_127,		/* IRDA_SDA */
#endif
	GPIO_VT_2_8_EN,
	GPIO_VT_1_8_EN,
	GPIO_VCM_PWDN,							/* Not used rev0.2 */
	/* SM_RDY pin Low for download mode, High for normal boot */
	SM_RDY_GPIO_3 | MFP_PULL_HIGH,

	ND_IO15_ND_DAT15 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO14_ND_DAT14 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO13_ND_DAT13 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO12_ND_DAT12 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO11_ND_DAT11 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO10_ND_DAT10 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO9_ND_DAT9 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	ND_IO8_ND_DAT8 | MFP_LPM_INPUT | MFP_PULL_HIGH,
	//ND_nCS0_SM_nCS2 | MFP_PULL_LOW | MFP_LPM_FLOAT,
#ifdef CONFIG_WIFIONLY_BOARD
  	ND_CS0N2_GPIO_101 | MFP_LPM_DRIVE_LOW,			/* USIM1_DET */
#else
	ND_CS0N2_GPIO_101 | MFP_LPM_INPUT,				/* USIM1_DET */
#endif
	ND_CS1N3_GPIO_102 | MFP_PULL_HIGH,
	//DF_WEn_DF_WEn | MFP_LPM_FLOAT,
	GPIO_RF_TOUCH_INT2 | MFP_PULL_HIGH | MFP_LPM_INPUT,		/* RF_TOUCH_INT2 */ /* GPIO105 */
	GPIO_RF_TOUCH_EN | MFP_PULL_HIGH | MFP_LPM_INPUT,				/* RF_TOUCH_EN */ /* GPIO106 */
	GPIO_RF_TOUCH_INT | MFP_LPM_INPUT,				/* RF_TOUCH_INT */ /* GPIO108 */
	VCXO_REQ,
	VCXO_OUT_CLK,

};

void mmp_pins_init(void)
{
	if (system_rev <= LT02_R0_0)
		mfp_config(ARRAY_AND_SIZE(lt02_r0_0_pins));
	else if (system_rev <= LT02_R0_2)
		mfp_config(ARRAY_AND_SIZE(lt02_r0_1_pins));
	else
		mfp_config(ARRAY_AND_SIZE(lt02_r0_3_pins));
}

