#include "board.h"
#include "bitboard.h"
#include <iostream>

u64 generate_moves(u64 player_disks, u64 enemy_disks) {
	u64 no_disks = ~(player_disks | enemy_disks);
	u64 moves = 0;

	u64 x = player_disks;
	for (int i = 0; i < 6; i++) {
		x |= shift_right(x) & enemy_disks;
	}
	moves |= shift_right(x) & no_disks;

	x = player_disks;
	for (int i = 0; i < 6; i++) {
		x |= shift_down_right(x) & enemy_disks;
	}
	moves |= shift_down_right(x) & no_disks;

	x = player_disks;
	for (int i = 0; i < 6; i++) {
		x |= shift_down(x) & enemy_disks;
	}
	moves |= shift_down(x) & no_disks;

	x = player_disks;
	for (int i = 0; i < 6; i++) {
		x |= shift_down_left(x) & enemy_disks;
	}
	moves |= shift_down_left(x) & no_disks;

	x = player_disks;
	for (int i = 0; i < 6; i++) {
		x |= shift_left(x) & enemy_disks;
	}
	moves |= shift_left(x) & no_disks;

	x = player_disks;
	for (int i = 0; i < 6; i++) {
		x |= shift_up_left(x) & enemy_disks;
	}
	moves |= shift_up_left(x) & no_disks;

	x = player_disks;
	for (int i = 0; i < 6; i++) {
		x |= shift_up(x) & enemy_disks;
	}
	moves |= shift_up(x) & no_disks;

	x = player_disks;
	for (int i = 0; i < 6; i++) {
		x |= shift_up_right(x) & enemy_disks;
	}
	moves |= shift_up_right(x) & no_disks;

	return moves;
}

void make_move(u64& player_disks, u64& enemy_disks, i32 square) {
	u64 no_disks = ~(player_disks | enemy_disks);
	u64 flipped_disks = 0;

	u64 placed_disk = 1ULL << square;

	u64 x = player_disks;
	for (int i = 0; i < 6; i++) {
		x |= shift_right(x) & enemy_disks;
	}
	flipped_disks |= shift_right(x) & player_disks;

	x = player_disks;
	for (int i = 0; i < 6; i++) {
		x |= shift_down_right(x) & enemy_disks;
	}
	flipped_disks |= shift_down_right(x) & player_disks;

	x = player_disks;
	for (int i = 0; i < 6; i++) {
		x |= shift_down(x) & enemy_disks;
	}
	flipped_disks |= shift_down(x) & player_disks;

	x = player_disks;
	for (int i = 0; i < 6; i++) {
		x |= shift_down_left(x) & enemy_disks;
	}
	flipped_disks |= shift_down_left(x) & player_disks;

	x = player_disks;
	for (int i = 0; i < 6; i++) {
		x |= shift_left(x) & enemy_disks;
	}
	flipped_disks |= shift_left(x) & player_disks;

	x = player_disks;
	for (int i = 0; i < 6; i++) {
		x |= shift_up_left(x) & enemy_disks;
	}
	flipped_disks |= shift_up_left(x) & player_disks;

	x = player_disks;
	for (int i = 0; i < 6; i++) {
		x |= shift_up(x) & enemy_disks;
	}
	flipped_disks |= shift_up(x) & player_disks;

	x = player_disks;
	for (int i = 0; i < 6; i++) {
		x |= shift_up_right(x) & enemy_disks;
	}
	flipped_disks |= shift_up_right(x) & player_disks;

	player_disks ^= flipped_disks;
	enemy_disks ^= flipped_disks;
}

void print_board(Position pos) {
	for (i32 row = 0; row < 8; row++) {
		for (i32 col = 0; col < 8; col++) {
			i32 square = row * 8 + col;

			if (pos.white_disks & (1ULL << square)) {
				std::cout << "W ";
			}
			else if (pos.black_disks & (1ULL << square)) {
				std::cout << "B ";
			}
			else {
				std::cout << ". ";
			}
		}
		std::cout << std::endl;
	}
}