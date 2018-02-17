/*
 * Copyright (C) 2012 Texas Instruments
 *
 * License Terms: GNU General Public License v2
 *
 * Simple driver for Texas Instruments LM3554 LED driver chip
 *
 * Author: G.Shark Jeong <a0414807@ti.com>
 */
 

#ifndef _LINUX_LED_FLASH_LM3554_H__
#define _LINUX_LED_FLASH_LM3554_H__

#define LM3554_NAME "leds-lm3554"

enum lm3554_indic_i_select{
	LM3554_INDIC_I_2P3_MA = 0,
	LM3554_INDIC_I_4P6_MA ,
	LM3554_INDIC_I_6P9_MA ,
	LM3554_INDIC_I_8P2_MA ,
};

enum lm3554_torch_i_select{
	LM3554_TORCH_I_17_MA = 0,
	LM3554_TORCH_I_35P5_MA ,
	LM3554_TORCH_I_54_MA ,
	LM3554_TORCH_I_73_MA ,
	LM3554_TORCH_I_90_MA ,
	LM3554_TORCH_I_109_MA ,
	LM3554_TORCH_I_128_MA ,
	LM3554_TORCH_I_147P5_MA ,
};

enum lm3554_mode{
	LM3554_MODE_SHDN = 0,
	LM3554_MODE_INDIC ,
	LM3554_MODE_TORCH ,
	LM3554_MODE_FLASH ,
	LM3554_MODE_VOUT ,
	LM3554_MODE_VOUT_INDIC ,
	LM3554_MODE_VOUT_TORCH ,
	LM3554_MODE_VOUT_FLASH ,
};

enum lm3554_strobe{
	LM3554_STROBE_LVL_SENSE = 0,
	LM3554_STROBE_EDGE_SENSE ,
};

enum lm3554_flash_i_select{
	LM3554_FLASH_I_35P5_MA = 0,
	LM3554_FLASH_I_73_MA,
	LM3554_FLASH_I_109_MA,
	LM3554_FLASH_I_147P5_MA,
	LM3554_FLASH_I_182P5_MA,
	LM3554_FLASH_I_220P5_MA,
	LM3554_FLASH_I_259_MA,
	LM3554_FLASH_I_298_MA,
	LM3554_FLASH_I_326_MA,
	LM3554_FLASH_I_364P5_MA,
	LM3554_FLASH_I_402P5_MA,
	LM3554_FLASH_I_440P5_MA,
	LM3554_FLASH_I_480_MA,
	LM3554_FLASH_I_518P5_MA,
	LM3554_FLASH_I_556P5_MA,
	LM3554_FLASH_I_595P5_MA,
};

enum lm3554_i_limit_select{
	LM3554_I_LIMIT_1_A = 0,
	LM3554_I_LIMIT_1P5_A ,
	LM3554_I_LIMIT_2_A ,
	LM3554_I_LIMIT_2P5_A ,
};

enum lm3554_flash_timeout{
	LM3554_FLASH_T_32_MS = 0,
	LM3554_FLASH_T_64_MS,
	LM3554_FLASH_T_96_MS,
	LM3554_FLASH_T_128_MS, 
	LM3554_FLASH_T_160_MS, 
	LM3554_FLASH_T_192_MS, 
	LM3554_FLASH_T_224_MS, 
	LM3554_FLASH_T_256_MS, 
	LM3554_FLASH_T_288_MS, 
	LM3554_FLASH_T_320_MS, 
	LM3554_FLASH_T_352_MS, 
	LM3554_FLASH_T_384_MS, 
	LM3554_FLASH_T_416_MS, 
	LM3554_FLASH_T_448_MS, 
	LM3554_FLASH_T_480_MS, 
	LM3554_FLASH_T_512_MS, 
	LM3554_FLASH_T_544_MS, 
	LM3554_FLASH_T_576_MS, 
	LM3554_FLASH_T_608_MS, 
	LM3554_FLASH_T_640_MS, 
	LM3554_FLASH_T_672_MS, 
	LM3554_FLASH_T_704_MS, 
	LM3554_FLASH_T_736_MS, 
	LM3554_FLASH_T_768_MS, 
	LM3554_FLASH_T_800_MS, 
	LM3554_FLASH_T_832_MS, 
	LM3554_FLASH_T_864_MS, 
	LM3554_FLASH_T_896_MS, 
	LM3554_FLASH_T_928_MS, 
	LM3554_FLASH_T_960_MS, 
	LM3554_FLASH_T_992_MS, 
	LM3554_FLASH_T_1024_MS,	
};

enum lm3554_tx1_pin{
	LM3554_TX1_PIN_FLASH_INT =0,
	LM3554_TX1_PIN_HW_TORCH,
};

enum lm3554_tx2_pin{
	LM3554_TX2_PIN_VOLTAGE_MODE =0,
	LM3554_TX2_PIN_PAM_SYNCH,
};

enum lm3554_tx2_polarity{
	LM3554_TX2_PIN_ACTIVE_LOW =0,
	LM3554_TX2_PIN_ACTIVE_HIGH,
};

enum lm3554_ledi_ntc_pin{
	LM3554_LEDI_NTC_PIN_INDIC_MODE = 0,
	LM3554_LEDI_NTC_PIN_TERMAL_MODE,
};

enum lm3554_strobe_pin{
	LM3554_STROBE_PIN_ENABLE = 0,
	LM3554_STROBE_PIN_DISABLE,
};

enum lm3554_voltage_mode_out{
	LM3554_VOLTAGE_MODE_4500_MV = 0,
	LM3554_VOLTAGE_MODE_5000_MV,

};

enum lm3554_light_load_comp{
	LM3554_LIGHT_LOAD_COMP_ENABLE = 0,
	LM3554_LIGHT_LOAD_COMP_DISABLE,
};

enum lm3554_vin_monitor_shutdown{
	LM3554_VIN_MONNITOR_SHDN_DISABLE = 0,
	LM3554_VIN_MONNITOR_SHDN_ENABLE,
};

enum lm3554_aet_mode{
	LM3554_AET_MODE_DISABLE = 0,
	LM3554_AET_MODE_ENABLE,
};

enum lm3554_ntc_shutdown{
	LM3554_NTC_SHDN_DISABLE = 0,
	LM3554_NTC_SHDN_ENABLE,
};

enum lm3554_tx2_shutdown{
	LM3554_TX2_SHDN_DISABLE = 0,
	LM3554_TX2_SHDN_ENABLE,
};

enum lm3554_ntc_external_flag{
	LM3554_NTC_EXTERNAL_FLAG_DISABLE = 0,
	LM3554_NTC_EXTERNAL_FLAG_ENABLE,
};

enum lm3554_gpio2_direction{
	LM3554_GPIO2_INPUT = 0,
	LM3554_GPIO2_OUTPUT,
};

enum lm3554_gpio2_usage{
	LM3554_GPIO2_USE_ENVM_TX2 = 0,
	LM3554_GPIO2_USE_GPIO,
};
enum lm3554_gpio1_direction{
	LM3554_GPIO1_INPUT = 0,
	LM3554_GPIO1_OUTPUT,
};

enum lm3554_gpio1_usage{
	LM3554_GPIO1_USE_ENVM_TX2 = 0,
	LM3554_GPIO1_USE_GPIO,
};

enum lm3554_vin_threshold{
	LM3554_VIN_TH_3100_MV = 0,
	LM3554_VIN_TH_3200_MV,
	LM3554_VIN_TH_3300_MV,
	LM3554_VIN_TH_3400_MV,
};

enum lm3554_vin_monitor{
	LM3554_VIN_MONNITOR_DISABLE = 0,
	LM3554_VIN_MONNITOR_ENABLE,
};

struct lm3554_platform_data {
	u8 torch_pin_enable;    // 1:  TX1/TORCH pin isa hardware TORCH enable
	u8 pam_sync_pin_enable; // 1:  TX2 Mode The ENVM/TX2 is a PAM Sync. on input
	u8 thermal_comp_mode_enable;// 1: LEDI/NTC pin in Thermal Comparator Mode
	u8 strobe_pin_disable;  // 1 : STROBE Input disabled
	u8 vout_mode_enable;  // 1 : Voltage Out Mode enable
};

#endif	/* _LINUX_LED_FLASH_LM3554_H__ */

