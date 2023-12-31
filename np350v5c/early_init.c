/* SPDX-License-Identifier: GPL-2.0-only */


#include <bootblock_common.h>
#include <device/pci_ops.h>
#include <northbridge/intel/sandybridge/raminit_native.h>
#include <southbridge/intel/bd82x6x/pch.h>

const struct southbridge_usb_port mainboard_usb_ports[] = {
	{ 1, 1, 0 },
	{ 1, 1, 0 },
	{ 1, 1, 1 },
	{ 1, 1, 1 },
	{ 0, 0, 2 },
	{ 0, 0, 2 },
	{ 0, 0, 3 },
	{ 0, 0, 3 },
	{ 1, 1, 4 },
	{ 1, 1, 4 },
	{ 0, 0, 5 },
	{ 1, 0, 5 },
	{ 0, 0, 6 },
	{ 0, 0, 6 },
};

void bootblock_mainboard_early_init(void)
{
	pci_write_config16(PCI_DEV(0, 0x1f, 0), 0x82, 0x3c00);
	pci_write_config16(PCI_DEV(0, 0x1f, 0), 0x80, 0x0000);
}

/* FIXME: Recheck second SPD i2c address. */
void mainboard_get_spd(spd_raw_data *spd, bool id_only)
{
	read_spd(&spd[0], 0x50, id_only);
	read_spd(&spd[2], 0x52, id_only);
}
