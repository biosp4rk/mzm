#ifndef CHAOS_H
#define CHAOS_H

#include "types.h"

s32 ChaosIsEffectActive(u8 id);
u8 ChaosEmptyEffectIndex(void);
void ChaosUpdate(void);
void ChaosUpdateEffects(void);
void ChaosCreateEffect(void);
void ChaosUpdateRng(void);
u32 ChaosRandUint(u32 min, u32 max);

void ChaosEffectFreezeEnemies(void);
void ChaosEffectRandSound(void);

#endif /* CHAOS_H */
