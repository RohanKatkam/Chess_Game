#ifndef CHESS_BOARD_H_
#define CHESS_BOARD_H_

#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>
#include <SFML/graphics.hpp>

#define BOARD_ROWS 8
#define BOARD_COLUMNS 8
#define SQUARE_LENGTH 100.f
#define HALF_SQUARE_LENGTH_INT 50
#define UNOCCUPIED 0
#define BOARD_X_COORD_MAX 800
#define BOARD_X_COORD_MIN 0
#define BOARD_Y_COORD_MIN 0
#define BOARD_Y_COORD_MAX 800

extern std::map<std::pair<char, char>, sf::Vector2f> chessBoardCoordMap;
extern std::map<std::pair<char, char>, int> chessBoardOccupationMap;
extern std::pair<char, char> chessBoardPositionArr[BOARD_ROWS][BOARD_ROWS];
// extern std::array<

void drawChessBoard(sf::RenderWindow &window);

void initializeBoardPositionsCoords();

std::pair<char, char> getSquarePosFromCoord(sf::Vector2f squareCoord);
sf::Vector2f getSquareCoordFromPos(std::pair<char, char> pos);
int getPieceIdAtSquare(std::pair<char, char> squarePos);
int setPieceIdAtSquare(std::pair<char, char> squarePos, int id);

/* Function to handle the cursor coordinates outside the board*/
void handle_outside_board(sf::Vector2f *squareCoord);

#endif // CHESS_BOARD_H_