/* SPDX-License-Identifier: GPL-2.0-only */

#include <cpu/x86/smm.h>
#include <device/device.h>
#include <drivers/intel/gma/int15.h>
#include <southbridge/intel/bd82x6x/pch.h>
#include <ec/acpi/ec.h>
#include <console/console.h>
#include <pc80/keyboard.h>
#include "ec.h"
#include <ec/compal/ene932/ec.h>

void mainboard_suspend_resume(void)
{
	/* Enable ACPI mode before OS resume */
	apm_control(APM_CNT_ACPI_ENABLE);
}

static void mainboard_init(struct device *dev)
{
	/* Initialize the Embedded Controller */
	ec_init();
}

static void mainboard_enable(struct device *dev)
{
	dev->ops->init = mainboard_init;

	/* FIXME: fix these values. */
	install_intel_vga_int15_handler(GMA_INT15_ACTIVE_LFP_INT_LVDS,
					GMA_INT15_PANEL_FIT_DEFAULT,
					GMA_INT15_BOOT_DISPLAY_DEFAULT, 0);
}

struct chip_operations mainboard_ops = {
	.enable_dev = mainboard_enable,
};
