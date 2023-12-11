#pragma once
#include "types.h"

struct Position {
	Color side_to_move;
	u64 white_disks;
	u64 black_disks;
};