#ifndef SIDEHOPPER_AI_H
#define SIDEHOPPER_AI_H

#include "../types.h"

u8 SidehopperCheckSamusInRange(void);
void SidehopperInit(void);
void SidehopperIdleGFXInit(void);
void SidehopperJumpingGFXInit(void);
void SidehopperLandingGFXInit(void);
void SidehopperAfterIdle(void);
void SidehopperJumpingIntoBlockGFXInit(void);
void SidehopperCheckBeforeJumpingGroundAnimEnded(void);
void SidehopperCheckBeforeJumpingCeilingAnimEnded(void);
void SidehopperJumpingGround(void);
void SidehopperJumpingCeiling(void);
void SidehopperCheckLandingCeilingAnimEnded(void);
void SidehopperJumpingGroundIntoBlock(void);
void SidehopperJumpingCeilingIntoBlock(void);
void SidehopperGroundIdleAnim(void);
void SidehopperCeilingIdleAnim(void);
void SidehopperDeath(void);
void Sidehopper(void);

#endif /* SIDEHOPPER_AI_H */