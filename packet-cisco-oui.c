/* packet-cisco-oui.c
 * Register an LLC dissector table for Cisco's OUI 00:00:0c
 *
 * $Id: packet-cisco-oui.c,v 1.1 2003/09/03 06:27:03 guy Exp $
 *
 * Ethereal - Network traffic analyzer
 * By Gerald Combs <gerald@ethereal.com>
 * Copyright 1998 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#include "config.h"

#include <epan/packet.h>
#include "packet-llc.h"
#include "oui.h"

static int hf_llc_cisco_pid = -1;

static const value_string cisco_pid_vals[] = {
	{ 0x0102,	"DRIP" },
	{ 0x2000,	"CDP" },
	{ 0x2001,	"CGMP" },
	{ 0x2003,	"VTP" },
	{ 0,		NULL }
};

/*
 * NOTE: there's no dissector here, just registration routines to set
 * up the dissector table for the Cisco OUI.
 */
void
proto_register_cisco_oui(void)
{
	static hf_register_info hf = {
	    &hf_llc_cisco_pid,
		{ "PID",	"llc.cisco_pid",  FT_UINT16, BASE_HEX,
		  VALS(cisco_pid_vals), 0x0, "", HFILL },
	};

	llc_add_oui(OUI_CISCO, "llc.cisco_pid", "Cisco OUI PID", &hf);
}
