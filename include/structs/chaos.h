#ifndef CHAOS_STRUCT_H
#define CHAOS_STRUCT_H

#include "types.h"

#define MAX_NUM_CHAOS_EFFECTS 5

struct ChaosEffect {
    u8 exists;
    u8 id;
    u16 timer;
    u16 data;
};

extern u32 gChaosRng;
extern u32 gActiveChaosEffects;
extern struct ChaosEffect gChaosEffects[MAX_NUM_CHAOS_EFFECTS];

#endif /* CHAOS_STRUCT_H */
