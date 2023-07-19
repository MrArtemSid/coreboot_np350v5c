/* SPDX-License-Identifier: GPL-2.0-only */

#include <mainboard/samsung/np350v5c/onboard.h>

/* FIXME: Recheck everything  */

Scope (\_SB) {
	Device (LID0)
	{
		Name(_HID, EisaId("PNP0C0D"))
		Method(_LID, 0)
		{
			\LIDS = GP15
			Return (\LIDS)
		}
	}

	Device (MB) {
		Name(_HID, EisaId("PNP0C01")) // System Board

		/* Lid open */
		Method (LIDO) { /* Not needed on this board */ }
		/* Lid closed */
		Method (LIDC) { /* Not needed on this board */ }
		/* Increase brightness */
		Method (BRTU) { /* Not needed on this board */ }
		/* Decrease brightness */
		Method (BRTD) { /* Not needed on this board */ }
		/* Switch display */
		Method (DSPS) { /* Not needed on this board */ }
		/* Toggle wireless */
		Method (WLTG) { /* Not needed on this board */ }
		/* Return lid state */
		Method (LIDS)
		{
			Return (GP15)
		}
	}

}
