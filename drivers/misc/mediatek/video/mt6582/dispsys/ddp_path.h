#ifndef __DDP_PATH_H__
#define __DDP_PATH_H__

#include "ddp_ovl.h"
#include "ddp_rdma.h"
#include "ddp_wdma.h"
#include "ddp_bls.h"
#include "ddp_drv.h"

#define DDP_USE_CLOCK_API
#define DDP_OVL_LAYER_MUN 4
#define DDP_BACKUP_REG_NUM 0x1000
#define DDP_UNBACKED_REG_MEM 0xdeadbeef

extern unsigned int decouple_addr;
#ifdef DDP_USE_CLOCK_API
extern unsigned int *pRegBackup;
#endif

#if defined(CONFIG_MTK_HDMI_SUPPORT)
extern bool is_hdmi_active(void);
#endif

#endif
