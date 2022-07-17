#ifndef ULTRA64_PFS_H
#define ULTRA64_PFS_H

#include "ultra64.h"

typedef union {
    struct {
        /* 0x00 */ u8 bank;
        /* 0x01 */ u8 page;
    } inode_t;
    /* 0x00 */ u16 ipage;
} __OSInodeUnit; // size = 0x02

typedef struct {
    /* 0x00 */ __OSInodeUnit inodePage[128];
} __OSInode; // size = 0x100

typedef struct {
    /* 0x00 */ u32 repaired;
    /* 0x04 */ u32 random;
    /* 0x08 */ u64 serialMid;
    /* 0x10 */ u64 serialLow;
    /* 0x18 */ u16 deviceid;
    /* 0x1A */ u8 banks;
    /* 0x1B */ u8 version;
    /* 0x1C */ u16 checksum;
    /* 0x1E */ u16 invertedChecksum;
} __OSPackId; // size = 0x20

#endif
