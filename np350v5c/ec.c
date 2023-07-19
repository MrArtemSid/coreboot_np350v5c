/* SPDX-License-Identifier: GPL-2.0-only */

#include <types.h>
#include <console/console.h>
#include <device/device.h>
#include <ec/compal/ene932/ec.h>
#include "ec.h"

void ec_init(void)
{
	printk(BIOS_DEBUG, "EC Init\n");

	/* Clean up the buffers. We don't know the initial condition. */
	kbc_cleanup_buffers();

	/* FIXME: Need to recheck if laptop needs that */
	/* US Keyboard */
	//ec_kbc_write_cmd(0x59);
	//ec_kbc_write_ib(0xE5);

	/* Enable IRQ1 */
	//ec_kbc_write_cmd(0x59);
	//ec_kbc_write_ib(0xD1);

	/* TODO - Do device detection and device maintain state (nvs) */
	/* Enable Wireless and Bluetooth */
	//ec_kbc_write_cmd(0x45);
	//ec_kbc_write_ib(0xAD);

	/* Set Wireless and Bluetooth Available */
	//ec_kbc_write_cmd(0x45);
	//ec_kbc_write_ib(0xA8);

	/* Set Wireless and Bluetooth Enable */
	//ec_kbc_write_cmd(0x45);
	//ec_kbc_write_ib(0xA2);
}
