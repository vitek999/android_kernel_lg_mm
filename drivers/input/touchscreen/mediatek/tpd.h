#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/input.h>
#include <linux/interrupt.h>
#include <linux/time.h>
#include <linux/types.h>
#include <linux/seq_file.h>
#include <linux/list.h>
#include <linux/proc_fs.h>

#include <linux/slab.h>
#if defined(CONFIG_MTK_LEGACY)
#include <mach/mt_gpio.h>
#endif
#ifndef CONFIG_ARM64 /* MT6795 */
#include <mach/mt_reg_base.h>
#include <mach/irqs.h>
#endif

#include <mach/mt_typedefs.h>
#include <mach/board.h>
#include <mach/eint.h>

#include <linux/io.h>
#include <linux/platform_device.h>
#include <generated/autoconf.h>
#include <linux/kobject.h>
#include <linux/earlysuspend.h>
#include <linux/regulator/consumer.h>
/* #include "tpd_custom.h" */
#include <vibrator_hal.h>

/* debug macros */
/* #define TPD_DEBUG */
#define TPD_DEBUG_CODE
/* #define TPD_DEBUG_TRACK */
#define TPD_DMESG(a, arg...) printk(TPD_DEVICE ": " a, ##arg)
#if defined(TPD_DEBUG)
#undef TPD_DEBUG
#define TPD_DEBUG(a, arg...) printk(TPD_DEVICE ": " a, ##arg)
#else
#define TPD_DEBUG(arg...)
#endif

/* register, address, configurations */
#define TPD_DEVICE            "mtk-tpd"
#define TPD_X                  0
#define TPD_Y                  1
#define TPD_Z1                 2
#define TPD_Z2                 3
#define TP_DELAY              (2*HZ/100)
#define TP_DRV_MAX_COUNT          (20)
#define TPD_WARP_CNT          (4)
#define TPD_VIRTUAL_KEY_MAX   (10)

/* various mode */
#define TPD_MODE_NORMAL        0
#define TPD_MODE_KEYPAD        1
#define TPD_MODE_SW 2
#define TPD_MODE_FAV_SW 3
#define TPD_MODE_FAV_HW 4
#define TPD_MODE_RAW_DATA 5
#undef TPD_RES_X
#undef TPD_RES_Y
extern int TPD_RES_X;
extern int TPD_RES_Y;
extern int tpd_load_status;	/* 0: failed, 1: sucess */
extern int tpd_mode;
extern int tpd_mode_axis;
extern int tpd_mode_min;
extern int tpd_mode_max;
extern int tpd_mode_keypad_tolerance;
extern int tpd_em_debounce_time;
extern int tpd_em_debounce_time0;
extern int tpd_em_debounce_time1;
extern int tpd_em_asamp;
extern int tpd_em_auto_time_interval;
extern int tpd_em_sample_cnt;
extern int tpd_calmat[];
extern int tpd_def_calmat[];
extern int tpd_calmat[];
extern int tpd_def_calmat[];
extern int TPD_DO_WARP;
extern int tpd_wb_start[];
extern int tpd_wb_end[];

struct tpd_device {
	struct device *tpd_dev;
	struct regulator *reg;
	struct input_dev *dev;
	struct input_dev *kpd;
	struct timer_list timer;
	struct tasklet_struct tasklet;
	int btn_state;
};
#if !defined(CONFIG_MTK_LEGACY)
struct tpd_key_dim_local {
	int key_x;
	int key_y;
	int key_width;
	int key_height;
};
struct tpd_dts_info {
	int tpd_resolution[2];
	int use_tpd_button;
	int tpd_key_num;
	int tpd_key_local[4];
	struct tpd_key_dim_local tpd_key_dim_local[4];
};
extern struct tpd_dts_info tpd_dts_data;
#endif
struct tpd_attrs {
	struct device_attribute **attr;
	int num;
};
struct tpd_driver_t {
	char *tpd_device_name;
	int (*tpd_local_init) (void);
	void (*suspend) (struct early_suspend *h);
	void (*resume) (struct early_suspend *h);
	int tpd_have_button;
	struct tpd_attrs attrs;
};

struct tpd_filter_t {
	int enable; /* 0: disable, 1: enable */
	int pixel_density; /* XXX pixel/cm */
	int W_W[3][4]; /* filter custom setting prameters */
	unsigned int VECLOCITY_THRESHOLD[3]; /* filter speed custom settings */
};

#if 1	/* #ifdef TPD_HAVE_BUTTON */
void tpd_button(unsigned int x, unsigned int y, unsigned int down);
void tpd_button_init(void);
ssize_t tpd_virtual_key(char *buf);
/* #ifndef TPD_BUTTON_HEIGHT */
/* #define TPD_BUTTON_HEIGHT TPD_RES_Y */
/* #endif */
#endif

#if 0
void tpd_adc_init(void);
void tpd_set_debounce_time(int debounce_time);
void tpd_set_spl_number(int spl_num);
u16 tpd_read(int position);
u16 tpd_read_adc(u16 pos);
u16 tpd_read_status(void);
#endif

extern int tpd_driver_add(struct tpd_driver_t *tpd_drv);
extern int tpd_driver_remove(struct tpd_driver_t *tpd_drv);
void tpd_button_setting(int keycnt, void *keys, void *keys_dim);
extern int tpd_em_spl_num;
extern int tpd_em_pressure_threshold;
extern int tpd_v_magnify_x;
extern int tpd_v_magnify_y;


#if !defined(CONFIG_MTK_LEGACY)
#define GTP_RST_PORT    0
#define GTP_INT_PORT    1
extern void tpd_get_dts_info(void);
extern void tpd_gpio_as_int(int pin);
extern void tpd_gpio_output(int pin, int level);
#endif
extern UINT32 DISP_GetScreenHeight(void);
extern UINT32 DISP_GetScreenWidth(void);
#if defined(CONFIG_MTK_S3320) || defined(CONFIG_MTK_S3320_47) || defined(CONFIG_MTK_S3320_50)
extern void synaptics_init_sysfs(void);
#endif
extern void tpd_button_init(void);

#ifdef TPD_DEBUG_CODE
#include "tpd_debug.h"
#endif

#ifdef TPD_HAVE_CALIBRATION
#include "tpd_calibrate.h"
#endif

#include "tpd_default.h"

/* switch touch panel into different mode */
void _tpd_switch_single_mode(void);
void _tpd_switch_multiple_mode(void);
void _tpd_switch_sleep_mode(void);
void _tpd_switch_normal_mode(void);