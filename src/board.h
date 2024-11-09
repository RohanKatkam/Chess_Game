#ifndef CHESS_BOARD_H_
#define CHESS_BOARD_H_

#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>
#include <SFML/graphics.hpp>

#define BOARD_ROWS 8
#define SQUARE_LENGTH 100.f
#define HALF_SQUARE_LENGTH_INT 50
#define UNOCCUPIED 0

#define PAWN_PIECE_1_ID 69
#define PAWN_PIECE_2_ID 70

extern std::map<std::pair<char, char>, sf::Vector2f> chessBoardPositionMap;
extern std::map<std::pair<char, char>, int> chessBoardOccupationMap;
extern std::pair<char, char> chessBoardPositionArr[BOARD_ROWS][BOARD_ROWS];
// extern std::array<

void drawChessBoard(sf::RenderWindow &window);

void setBoardPositions();

std::pair<char, char> getSquarePosFromCoord(sf::Vector2f squareCoord);
int getPieceIdAtSquare(std::pair<char, char> squarePos);
int setPieceIdAtSquare(std::pair<char, char> squarePos, int id);

#endif // CHESS_BOARD_H_