#include <stdio.h>

// Piece enconding
enum {e, P, N, B, R, Q, K, p, n, b, r, q, k, o};

// ASCII pieces
char ascii_pieces[] = ".PNBRQKpnbrqko";

// Unicode pieces
char *unicode_pieces[] = {".", "&#9817", "U+2658", "U+2657", "U+2656", "U+2655", "U+2654", "U+265F", "U+265E", "U+265D", "U+265C", "U+265B", "U+265A"};

// Chessboard representation (and offboard square)
int board[128] = {
	r, n, b, q, k, b, n, r,		o, o, o, o, o, o, o, o,
	p, p, p, p, p, p, p, p,		o, o, o, o, o, o, o, o,
	e, e, e, e, e, e, e, e,		o, o, o, o, o, o, o, o,
	e, e, e, e, e, e, e, e,		o, o, o, o, o, o, o, o,
	e, e, e, e, e, e, e, e,		o, o, o, o, o, o, o, o,
	e, e, e, e, e, e, e, e,		o, o, o, o, o, o, o, o,
	P, P, P, P, P, P, P, P,		o, o, o, o, o, o, o, o,
	R, N, B, Q, k, B, N, R,		o, o, o, o, o, o, o, o,
};

// Print the board
void print_board()
{
	int lin;
	int col;
	int square;
	int lin_digit = 8;

	lin = 0;
	while (lin < 8)
	{
		col = 0;
		while (col < 16)
		{
			//init big square
			square = lin * 16 + col;
			//print line digits
			if (col == 0)
				printf("%d  ", lin_digit--);
			//remove the offboard square
			if ((square & 0x88) == 0)
				printf("%c ", ascii_pieces[board[square]]);
				//printf("%s ", unicode_pieces[board[square]]);
			col++;
		}
		printf("\n");
		lin++;
	}
	printf("\n");
	// print column alphas
	printf("   A B C D E F G H");
	printf("\n\n");
}

// main function
int main()
{
	print_board();
	return (0);
}
