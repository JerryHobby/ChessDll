#pragma once

#include <vector>
#include <string>
#include <cmath>
#include <ctype.h>		// case detection

#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Command.h"

#define BLACK 'B'
#define WHITE 'W'
#define EMPTY '_'
#define ROOK 'R'
#define PAWN 'P'
#define KNIGHT 'N'
#define BISHOP 'B'
#define QUEEN 'Q'
#define KING 'K'
#define MOVE 'M'
#define CAPTURE 'X'
#define KINGCASTLING 'K'
#define QUEENCASTLING 'Q'
#define CHECK '+'
#define CHECKMATE '#'