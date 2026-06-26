#ifndef CHAOS_H
#define CHAOS_H

#include "types.h"
#include "structs/chaos.h"

typedef bools32 (*ChaosFunc_T)(void);

void ChaosReset(void);
bools32 ChaosIsEffectActive(u32 id);
void ChaosEndEquipmentEffects(void);
void ChaosUpdate(void);

#endif /* CHAOS_H */
