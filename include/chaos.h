#ifndef CHAOS_H
#define CHAOS_H

#include "types.h"
#include "structs/chaos.h"

#define CHAOS_RAND_BOOL (ChaosRandU16(0, 1))

u32 ChaosIsEffectActive(u32 flags);
u8 ChaosEmptyEffectIndex(void);
void ChaosUpdate(void);
void ChaosUpdateEffects(void);
void ChaosEffectEnded(struct ChaosEffectData* pEffect);
void ChaosEndEquipmentEffects(void);
void ChaosCreateEffect(void);
void ChaosUpdateRng(void);
u16 ChaosRandU16(u16 min, u16 max);
u16 ChaosPositionNearSamus(u16 samusPos, u16 max);
u16 ChaosPositionNearSamusX(void);
u16 ChaosPositionNearSamusY(void);

// Duration effects
s32 ChaosEffectDeactivateAbility(struct ChaosEffectData* pEffect);
s32 ChaosEffectGiveAbility(struct ChaosEffectData* pEffect);
s32 ChaosEffectSuitless(struct ChaosEffectData* pEffect);
void ChaosEffectMoveHud(void);
void ChaosEffectExplosions(void);

// One time effects
s32 ChaosEffectSpawnEnemy(void);
s32 ChaosEffectSpawnPB(void);
void ChaosEffectShotBlock(void);
void ChaosEffectReplaceSolidBlocks(u16 value);
s32 ChaosEffectFreezeEnemies(void);
s32 ChaosEffectKnockback(void);
void ChaosEffectScreenShake(void);
void ChaosEffectChangeEnergyAmmo(void);
void ChaosEffectRandSound(void);
void ChaosEffectColorEffect(void);

#endif /* CHAOS_H */
