#ifndef CHAOS_H
#define CHAOS_H

#include "types.h"
#include "structs/chaos.h"

#define CHAOS_RAND_BOOL (ChaosRandU16(0, 1))

u32 ChaosIsEffectActive(u32 flags);
u8 ChaosEmptyEffectIndex(void);
void ChaosUpdate(void);
void ChaosUpdateEffects(void);
void ChaosEffectEnded(struct ChaosEffect* pEffect);
void ChaosCreateEffect(void);
void ChaosUpdateRng(void);
u16 ChaosRandU16(u16 min, u16 max);
u16 ChaosPositionNearSamus(u16 samusPos, u16 max);
u16 ChaosPositionNearSamusX(void);
u16 ChaosPositionNearSamusY(void);

s32 ChaosEffectSpawnEnemy(void);
s32 ChaosEffectSpawnPB(void);
void ChaosEffectFreezeEnemies(void);
void ChaosEffectScreenShake(void);
void ChaosEffectChangeEnergyAmmo(void);
void ChaosEffectRandSound(void);

#endif /* CHAOS_H */
