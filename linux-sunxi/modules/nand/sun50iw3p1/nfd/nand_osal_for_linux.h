/*
******************************************************************************
*								        eBIOS
*			            the Easy Portable/Player Develop Kits
*						           dma sub system
*
*		        (c) Copyright 2006-2008, David China
*				 All	Rights Reserved
*
* File    : clk_for_nand.c
* By      : Richard
* Version : V1.00
*****************************************************************************/
#ifndef _NAND_OSAL_FOR_LINUX_H_
#define _NAND_OSAL_FOR_LINUX_H_
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/fs.h>
#include <linux/blkdev.h>
#include <linux/blkpg.h>
#include <linux/spinlock.h>
#include <linux/hdreg.h>
#include <linux/init.h>
#include <linux/semaphore.h>
#include <linux/platform_device.h>
#include <linux/clk.h>
#include <linux/interrupt.h>
#include <asm/uaccess.h>
#include <linux/timer.h>
#include <linux/delay.h>
#include <linux/mutex.h>
#include <linux/sys_config.h>
#include <linux/dma-mapping.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <asm/cacheflush.h>
#include <linux/pinctrl/pinconf.h>
#include <linux/pinctrl/consumer.h>
#include <linux/gpio.h>
#include "nand_blk.h"
#include <linux/regulator/consumer.h>
#include <linux/of.h>
#include <linux/sunxi-sid.h>

#ifdef CONFIG_DMA_ENGINE
#include <linux/dmaengine.h>
#include <linux/dma-mapping.h>
#include <linux/dma/sunxi-dma.h>
#endif

#define  NAND_DRV_VERSION_0		0x03
#define  NAND_DRV_VERSION_1		0x5003
#define  NAND_DRV_DATE			0x20161020
#define  NAND_DRV_TIME			0x1726

#define GPIO_BASE_ADDR			0x01c20800
#define CCMU_BASE_ADDR			0x01c20000



#define DMA_CONFIG_SIZE (4096)



struct clk *pll6;
struct clk *nand0_dclk, *nand0_cclk;
struct clk *ahb_nand0;
struct regulator *regu1;
struct regulator *regu2;

int seq;
int nand_handle;

static __u32 PRINT_LEVEL;

extern void *NDFC0_BASE_ADDR;
extern void *NDFC1_BASE_ADDR;
extern struct device *ndfc_dev;

struct dma_chan *dma_hdl;
__u32 NAND_Print_level(void);
__u32 nand_dma_callback(void *para);
#endif

