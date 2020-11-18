#include <stdio.h>

// Piece enconding
enum {e, P, N, B, R, Q, K, p, n, b, r, q, k, o};

// Square encoding
enum square {
	a8 = 0, b8, c8, d8, e8, f8, g8, h8,
	a7 = 16, b7, c7, d7, e7, f7, g7, h7,
	a6 = 32, b6, c6, d6, e6, f6, g6, h6,
	a5 = 48, b5, c5, d5, e5, f5, g5, h5,
	a4 = 64, b4, c4, d4, e4, f4, g4, h4,
	a3 = 80, b3, c3, d3, e3, f3, g3, h3,
	a2 = 96, b2, c2, d2, e2, f2, g2, h2,
	a1 = 112, b1, c1, d1, e1, f1, g1, h1,
};

// ASCII pieces
char ascii_pieces[] = ".PNBRQKpnbrqko";

// Unicode pieces
char *unicode_pieces[] = {".", "&#9817", "U+2658", "U+2657", "U+2656", "U+2655", "U+2654", "U+265F", "U+265E", "U+265D", "U+265C", "U+265B", "U+265A"};

// Encode ASCII pieces
int char_pieces[] = {
	['P'] = P,
	['N'] = N,
	['B'] = B,
	['R'] = R,
	['Q'] = Q,
	['K'] = K,
	['p'] = p,
	['n'] = n,
	['b'] = b,
	['r'] = r,
	['q'] = q,
	['k'] = k,
};

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

// Convert board indexes to coordination points
char *square_to_coor[] = {
	"a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8", "i8", "j8", "k8", "l8", "m8", "n8", "o8", "p8",
	"a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7", "i7", "j7", "k7", "l7", "m7", "n7", "o7", "p7",
	"a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6", "i6", "j6", "k6", "l6", "m6", "n6", "o6", "p6",
	"a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5", "i5", "j5", "k5", "l5", "m5", "n5", "o5", "p5",
	"a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4", "i4", "j4", "k4", "l4", "m4", "n4", "o4", "p4",
	"a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3", "i3", "j3", "k3", "l3", "m3", "n3", "o3", "p3",
	"a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2", "i2", "j2", "k2", "l2", "m2", "n2", "o2", "p2",
	"a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1", "i1", "j1", "k1", "l1", "m1", "n1", "o1", "p1",
};

// Print the board
void print_board()
{
	int lin;
	int col;
	int square;
	int lin_digit = 8;

	printf("\n");
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
				printf(" %d--", lin_digit--);
			//remove the offboard square
			if ((square & 0x88) == 0)
				printf("%c ", ascii_pieces[board[square]]);
				//printf("%s ", unicode_pieces[board[square]]);
			col++;
		}
		printf("\n");
		lin++;
	}
	printf("    | | | | | | | |");
	printf("\n");
	// print column alphas
	printf("    a b c d e f g h");
	printf("\n\n");
}

// main function
int main()
{
	board[e2] = e;
	board[e4] = P;
	print_board();
	return (0);
}
