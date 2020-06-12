#pragma once

#define PAD_LEFT (1 << 7)
#define PAD_DOWN (1 << 6)
#define PAD_RIGHT (1 << 5)
#define PAD_UP (1 << 4)
#define PAD_START (1 << 3)
#define PAD_R3 (1 << 2)
#define PAD_L3 (1 << 1)
#define PAD_SELECT (1 << 0)
#define PAD_SQUARE (1 << 15)
#define PAD_CROSS (1 << 14)
#define PAD_CIRCLE (1 << 13)
#define PAD_TRIANGLE (1 << 12)
#define PAD_R1 (1 << 11)
#define PAD_L1 (1 << 10)
#define PAD_R2 (1 << 9)
#define PAD_L2 (1 << 8)

uint32_t GetKey(void);
