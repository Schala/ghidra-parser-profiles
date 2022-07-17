#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "pfs.h"
#include "printf.h"
#include "stdlib.h"

s32 __osCheckId(OSPfs* pfs);
s32 __osCheckPackId(OSPfs* pfs, __OSPackId* check);
void __osCleanupThread(void);
u8 __osContAddressCrc(u16 addr);
u8 __osContDataCrc(u8* data);
void __osContGetInitData(u8* ctlBitfield, OSContStatus* status);
s32 __osContRamRead(OSMesgQueue* ctrlrqueue, s32 channel, u16 addr, u8* data);
s32 __osContRamWrite(OSMesgQueue* mq, s32 channel, u16 address, u8* buffer, s32 force);
void __osDequeueThread(OSThread** queue, OSThread* thread);
void __osDevMgrMain(void* arg);
s32 __osDisableInt(void);
void __osDispatchThread(void);
void __osEnqueueAndYield(OSThread**);
void __osEnqueueThread(OSThread**, OSThread*);
OSThread* __osGetActiveQueue(void);
s32 __osGetId(OSPfs* pfs);
u32 __osGetSR(void);
s32 __osIdCheckSum(u16* ptr, u16* checkSum, u16* idSum);
OSTime __osInsertTimer(OSTimer* timer);
void __osPackRequestData(u8 poll);
s32 __osPfsDeclearPage(OSPfs* pfs, __OSInode* inode, s32 fileSizeInPages, s32* startPage, u8 bank, s32* decleared, s32* finalPage);
void __osPfsGetInitData(u8* pattern, OSContStatus* contData);
void __osPfsGetOneChannelData(s32 channel, OSContStatus* contData);
s32 __osPfsGetStatus(OSMesgQueue* queue, s32 channel);
s32 __osPfsReleasePages(OSPfs* pfs, __OSInode* inode, u8 initialPage, u8 bank, __OSInodeUnit* finalPage);
void __osPfsRequestData(u8 poll);
void __osPfsRequestOneChannel(s32 channel, u8 poll);
s32 __osPfsRWInode(OSPfs* pfs, __OSInode* inode, u8 flag, u8 bank);
s32 __osPfsSelectBank(OSPfs* pfs, u8 bank);
void __osPiCreateAccessQueue(void);
void __osPiGetAccess(void);
void __osPiRelAccess(void);
OSThread* __osPopThread(OSThread**);
u32 __osProbeTLB(void*);
s32 __osRepairPackId(OSPfs* pfs, __OSPackId* badid, __OSPackId* newid);
void __osRestoreInt(s32);
void __osSetCompare(u32);
void __osSetFpcCsr(u32);
void __osSetSR(u32);
void __osSetTimerIntr(OSTime time);
void __osSiCreateAccessQueue(void);
s32 __osSiDeviceBusy(void);
void __osSiGetAccess(void);
s32 __osSiRawReadIo(void* devAddr, u32* dst);
s32 __osSiRawStartDma(s32 dir, void* addr);
s32 __osSiRawWriteIo(void* devAddr, u32 val);
void __osSiRelAccess(void);
u32 __osSpDeviceBusy(void);
u32 __osSpGetStatus(void);
s32 __osSpRawStartDma(s32 direction, void* devAddr, void* dramAddr, u32 size);
s32 __osSpSetPc(void* pc);
void __osSpSetStatus(u32 status);
u16 __osSumcalc(u8* ptr, s32 length);
void __osTimerInterrupt(void);
void __osTimerServicesInit(void);
void __osViInit(void);
void __osViSwapContext(void);
void _Ldtob(_Pft* args, u8 type);
void _Litob(_Pft* args, u8 type);
lldiv_t lldiv(s64 num, s64 denom);

#endif
