/* SPDX-License-Identifier: GPL-2.0-only */

Method(_WAK,1)
{
	/* FIXME: Recheck */
	/* Update in case state changed while asleep */
	/* Update AC status */
	Local0 = \_SB.PCI0.LPCB.EC0.ADPT
	if (Local0 != \PWRS) {
		\PWRS = Local0
		Notify (\_SB.PCI0.LPCB.EC0.AC, 0x80)
	}

	/* Update LID status */
	Local0 = GP15
	if (Local0 != \LIDS) {
		\LIDS = Local0
		Notify (\_SB.LID0, 0x80)
	}

	Return(Package(){0,0})
}

Method(_PTS,1)
{
	/* FIXME: EC support  */
}
