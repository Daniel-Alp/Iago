#pragma once
#include "types.h"

struct Position {
	Color side_to_move;
	u64 white_disks = 0x0000001008000000ULL;
	u64 black_disks = 0x0000000810000000ULL;
};

u64 generate_moves(u64 player_disks, u64 enemy_disks);

void make_move(u64& player_disks, u64& enemy_disks, i32 square);

void print_board(Position pos);