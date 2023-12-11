#pragma once
#include "types.h"

inline u64 shift_right(u64 disks) {
	return (disks >> 1) & 0x7F7F7F7F7F7F7F7FULL;
}

inline u64 shift_down_right(u64 disks) {
	return (disks >>  9 ) & 0x007F7F7F7F7F7F7FULL;
}

inline u64 shift_down(u64 disks) {
	return (disks >> 8) & 0xFFFFFFFFFFFFFFFFULL;
}

inline u64 shift_down_left(u64 disks) {
	return (disks >> 7) & 0x00FEFEFEFEFEFEFEULL;
}

inline u64 shift_left(u64 disks) {
	return (disks << 1) & 0xFEFEFEFEFEFEFEFEULL;
}

inline u64 shift_up_left(u64 disks) {
	return (disks << 9) & 0xFEFEFEFEFEFEFE00ULL;
}

inline u64 shift_up(u64 disks) {
	return (disks << 8) & 0xFFFFFFFFFFFFFFFFULL;
}

inline u64 shift_up_right(u64 disks) {
	return (disks << 7) & 0x7F7F7F7F7F7F7F00ULL;
}