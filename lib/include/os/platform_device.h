

#ifndef _PLATFORM_DEVICE_H_
#define _PLATFORM_DEVICE_H_

#include <stdint.h>
#include <stddef.h>
#include "device.h"


struct platform_device {
	const char	*name;
	int		id;
	bool		id_auto;
	struct device	dev;
	uint32_t    num_resources;
	struct resource	*resource;

	const struct platform_device_id	*id_entry;
	char *driver_override; /* Driver name to force a match */

	/* MFD cell pointer */
	struct mfd_cell *mfd_cell;

	/* arch specific additions */
	struct pdev_archdata	archdata;
};


#endif
