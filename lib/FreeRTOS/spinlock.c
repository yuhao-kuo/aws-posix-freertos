

#include "FreeRTOS.h"
#include "port.h"

#define spin_irq_disable    portDISABLE_INTERRUPTS
#define spin_irq_enable     portENABLE_INTERRUPTS

void spin_lock(spinlock_t *lock)
{
    unsigned char *p = &lock->lock;
    while(*p == SPIN_LOCK_UNLOCKED) {
        *p = SPIN_LOCK_LOCKED;
    }
}

void spin_lock_irqsave(spinlock_t *lock, unsigned long flag);
void spin_lock_irq(spinlock_t *lock);

void spin_lock_bh(spinlock_t *lock)
{
    unsigned char *p = &lock->lock;
    while(*p == SPIN_LOCK_UNLOCKED) {
        *p = SPIN_LOCK_LOCKED;
        spin_irq_enable();
    }
}

void spin_unlock(spinlock_t *lock)
{
    lock->lock = SPIN_LOCK_UNLOCKED;
}

void spin_unlock_irqsave(spinlock_t *lock, unsigned long flag);
void spin_unlock_irq(spinlock_t *lock);

void spin_unlock_bh(spinlock_t *lock)
{
    lock->lock = SPIN_LOCK_UNLOCKED;
    spin_irq_disable();
}

int spin_trylock(spinlock_t *lock)
{
    unsigned char *p = &lock->lock;
    if(*p == SPIN_LOCK_UNLOCKED) {
        *p = SPIN_LOCK_LOCKED;
        return 0;
    }
    
    return 1;
}

int spin_trylock_bh(spinlock_t *lock)
{
    unsigned char *p = &lock->lock;
    if(*p == SPIN_LOCK_UNLOCKED) {
        *p = SPIN_LOCK_LOCKED;
        spin_irq_enable();
        return 0;
    }
    
    return 1;
}