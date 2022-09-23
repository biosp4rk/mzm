#ifndef SPRITE_DEBRIS_H
#define SPRITE_DEBRIS_H

#include "types.h"
#include "clipdata.h"
#include "oam.h"

#define MAX_AMOUNT_OF_SPRITE_DEBRIS 8

extern struct SpriteDebris gSpriteDebris[MAX_AMOUNT_OF_SPRITE_DEBRIS];

struct SpriteDebris {
    const struct FrameData* pOam;
    u16 currentAnimationFrame;
    u16 yPosition;
    u16 xPosition;
    u8 animationDurationCounter;
    u8 exists;
    u8 debrisType;
    u8 frameCounter;
    u8 arrayOffset;
};

void SpriteDebrisSetSplash(u16 oldY, u16 yPosition, u16 xPosition);
void SpriteDebrisProcess(struct SpriteDebris* pDebris);
void SpriteDebrisProcessAll(void);
void SpriteDebrisDraw(struct SpriteDebris* pDebris);
void SpriteDebrisDrawAll(void);
void SpriteDebrisInit(u8 cloudType, u8 debrisType, u16 yPosition, u16 xPosition);

#endif /* SPRITE_DEBRIS_H */