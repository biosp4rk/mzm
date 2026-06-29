#ifndef CHAOS_H
#define CHAOS_H

#include "types.h"
#include "structs/chaos.h"

#define CHAOS_RAND_BOOL() (ChaosRandU16(0, 1))

typedef bools32 (*ChaosFunc_T)(void);

void ChaosReset(void);
bools32 ChaosIsEffectActive(u32 id);
u16 ChaosRandU16(u16 min, u16 max);
void ChaosEndEquipmentEffects(void);
void ChaosUpdate(void);

#endif /* CHAOS_H */
