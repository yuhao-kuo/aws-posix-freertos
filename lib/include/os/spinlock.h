
#ifndef _SPINLOCK_H_
#define _SPINLOCK_H_

/**
 * spinlock
 * 上時必須保證不會有任何中斷導致鎖上的行程被暫停
 */

typedef struct {
    volatile unsigned int lock;
} spinlock_t;


#define SPIN_LOCK_UNLOCKED  0
#define SPIN_LOCK_LOCKED    1

void spin_lock_init(spinlock_t *lock);

void spin_lock(spinlock_t *lock);
void spin_lock_irqsave(spinlock_t *lock, unsigned long flag);
void spin_lock_irq(spinlock_t *lock);
void spin_lock_bh(spinlock_t *lock);

void spin_unlock(spinlock_t *lock);
void spin_unlock_irqsave(spinlock_t *lock, unsigned long flag);
void spin_unlock_irq(spinlock_t *lock);
void spin_unlock_bh(spinlock_t *lock);

int spin_trylock(spinlock_t *lock);
int spin_trylock_bh(spinlock_t *lock);

#endif
