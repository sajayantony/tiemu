/* Hey EMACS -*- linux-c -*- */
/* $Id: main.c 245 2004-05-23 20:45:43Z roms $ */

/*  TiEmu - an TI emulator
 *
 *  Copyright (c) 2000, Thomas Corvazier, Romain Lievin
 *  Copyright (c) 2001-2002, Romain Lievin, Julien Blache
 *  Copyright (c) 2003-2004, Romain Li�vin
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
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef __TI68K_MEMORY__
#define __TI68K_MEMORY__

#include "stdint.h"

/* Functions */

int hw_mem_init(void);
int hw_mem_reset(void);
int hw_mem_exit(void);

// defs similar to UAE's memory.h (interface)
extern uint8_t  hw_get_byte(uint32_t addr);
extern uint16_t hw_get_word(uint32_t addr);
extern uint32_t hw_get_long(uint32_t addr);

extern void hw_put_long(uint32_t addr, uint32_t arg);
extern void hw_put_word(uint32_t addr, uint16_t arg);
extern void hw_put_byte(uint32_t addr, uint8_t  arg);

extern uint8_t* hw_get_real_address(uint32_t addr);

/* Variables */

extern uint8_t  *mem_tab[];
extern uint32_t mem_mask[];

/* Defines */

#define rom_at_0() { mem_tab[0] = tihw.rom; mem_mask[0] = tihw.rom_size-1; }
#define ram_at_0() { mem_tab[0] = tihw.ram; mem_mask[0] = tihw.ram_size-1; }

#endif
