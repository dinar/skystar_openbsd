/*
 * OpenBSD 4.8 driver for Skystar1 DVB card rev. 1.3 and 1.5
 * Copyright (c) 2010 Dinar Talypov & Edward Garipov
 * based on code by:
 * Copyright (c) 2002 Alexander Romanov ported to OpenBSD 3.3 for Alloyant Technologies
 * based on code by:
 * FreeBSD driver for SkyStar1 DVB card (Siemens Fujitsu DVB PCI)
 * Copyright (c) 2000 Stanislav "Stephen" Golovin
 *
 * Based on linux driver code by:
 *
 * Copyright (C) 1999,2000 Ralph  Metzler & Marcus Metzler for convergence integrated media GmbH
 *
 * originally based on code by:
 *
 * Copyright (C) 1998,1999 Christian Theiss <mistert@rz.fh-augsburg.de>
 * 
 * 
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 * Or, point your browser to http://www.gnu.org/copyleft/gpl.html
 * 
 * The author can be reached at stas@everest.kaluga.ru
 *
 */

struct skystar_softc;

#include "dvb_bsru6.h"
#include "dvb_bsrv2.h"

#define DVB_NONE	0
#define BSRV2		1
#define BSRU6		2

union DVB {
	struct DVB_BSRV2 bsrv2;
	struct DVB_BSRU6 bsru6;
};

/*
 * network subsystem functions
 */

int	dvb_detect(struct skystar_softc *);
int	dvb_command(struct skystar_softc *, unsigned int, void *);
void	dvb_init(void *);
void	dvb_done(void *);
void	dvb_ipmpe(struct skystar_softc *, u_char *, int);
void	dvb_watchdog(struct ifnet *);
int	dvb_output(struct ifnet *, struct mbuf *, struct sockaddr *, struct rtentry *);
void	dvb_start(struct ifnet *);
int	dvb_ioctl(struct ifnet *, u_long, caddr_t);
