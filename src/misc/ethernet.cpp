/*
 *  Copyright (C) 2020  The DOSBox Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "ethernet_slirp.h"
#include <cstring>
#include "dosbox.h"

EthernetConnection::~EthernetConnection()
{}

EthernetConnection *OpenEthernetConnection(const char *backend)
{
	if (!strcmp(backend, "slirp")) {
		auto conn = new SlirpEthernetConnection;
		return conn->Initialize() ? conn : nullptr;
	}
	LOG_MSG("ETHERNET: unknown backend: %s", backend);
	return nullptr;
}
