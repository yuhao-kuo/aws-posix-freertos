
#ifndef _DEVICE_H_
#define _DEVICE_H_

#include <stdint.h>
#include <stddef.h>


#define PROMREG_MAX 10

typedef struct {
    volatile int counter;
} atomic_t;

struct device {

};

struct resource {

};

struct pdev_archdata {
    uint64_t dma_mask;
    struct resource resource[PROMREG_MAX];
    unsigned int irq[PROMREG_MAX];
    int num_irqs;
};

struct mfd_cell {
	const char		*name;
	int			id;

	/* refcounting for multiple drivers to use a single cell */
	atomic_t		*usage_count;
	int			(*enable)(struct platform_device *dev);
	int			(*disable)(struct platform_device *dev);

	int			(*suspend)(struct platform_device *dev);
	int			(*resume)(struct platform_device *dev);

	/* platform data passed to the sub devices drivers */
	void			*platform_data;
	size_t			pdata_size;
	/*
	 * Device Tree compatible string
	 * See: Documentation/devicetree/usage-model.txt Chapter 2.2 for details
	 */
	const char		*of_compatible;

	/*
	 * These resources can be specified relative to the parent device.
	 * For accessing hardware you should use resources from the platform dev
	 */
	int			num_resources;
	const struct resource	*resources;

	/* don't check for resource conflicts */
	bool			ignore_resource_conflicts;

	/*
	 * Disable runtime PM callbacks for this subdevice - see
	 * pm_runtime_no_callbacks().
	 */
	bool			pm_runtime_no_callbacks;

	/* A list of regulator supplies that should be mapped to the MFD
	 * device rather than the child device when requested
	 */
	const char * const	*parent_supplies;
	int			num_parent_supplies;
};

#endif
