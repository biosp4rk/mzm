#include "data/cutscenes/internal_mecha_sees_samus_data.h"
#include "cutscenes/mecha_sees_samus.h"
#include "cutscenes/cutscene_utils.h"
#include "macros.h"

const struct CutsceneSubroutineData sMechaSeesSamusSubroutineData[3] = {
    {
        .pFunction = MechaRidleySeesSamusInit,
        .oamLength = 2
    },
    {
        .pFunction = MechaRidleySeesSamusEyeOpen,
        .oamLength = 2
    },
    {
        .pFunction = (CutsceneFunc_T)0x8061229, //CutsceneEndFunction,
        .oamLength = 2
    }
};

const u8 sTempArray_76002c[0x97708] = INCBIN_U8("data/Blob_76002c_7f7734.bin");
