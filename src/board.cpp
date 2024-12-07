/**
 * @brief board related functions and variables
 * @todo change maps to const
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>
#include <SFML/graphics.hpp>

#include "board.h"
#include "util.h"

std::map<std::pair<char, char>, sf::Vector2f> chessBoardCoordMap = {};
std::map<std::pair<char, char>, int> chessBoardOccupationMap = {};
std::pair<char, char> chessBoardPositionArr[BOARD_ROWS][BOARD_ROWS] = {};

std::vector<char> columnNames = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
std::vector<char> rowNames = {'1', '2', '3', '4', '5', '6', '7', '8'};

void drawChessBoard(sf::RenderWindow &window)
{
    sf::RectangleShape squareYellow(sf::Vector2f(SQUARE_LENGTH, SQUARE_LENGTH));
    sf::RectangleShape squareBrown(sf::Vector2f(SQUARE_LENGTH, SQUARE_LENGTH));

    // Set colors
    squareYellow.setFillColor(sf::Color(242,202,92));
    squareBrown.setFillColor(sf::Color(102,0,0));

    // Draw squares alternate fashion
    // Looping: Not sure if this is the right way
    // Because not sure if need shape object for each square in the board
    float squareYellowPosX = 0;
    float squareYellowPosY = 0;
    float squareBrownPosX = 0;
    float squareBrownPosY = 0;
    for (int colIdx = 0; colIdx < BOARD_ROWS; colIdx++)
    {
        for (int rowIdx = 0; rowIdx < 4; rowIdx++)
        {
            // Set positions
            squareYellowPosY = colIdx * SQUARE_LENGTH;
            squareBrownPosY = colIdx * SQUARE_LENGTH;
            if (colIdx % 2)
            {
                squareYellowPosX = 2 * rowIdx * SQUARE_LENGTH;
                squareBrownPosX = (2 * rowIdx + 1) * SQUARE_LENGTH;
            }
            // Else alternate colors
            else 
            {
                squareBrownPosX = 2 * rowIdx * SQUARE_LENGTH;
                squareYellowPosX = (2 * rowIdx + 1) * SQUARE_LENGTH;
            }
            
            squareYellow.setPosition(sf::Vector2f(squareYellowPosX, squareYellowPosY));
            squareBrown.setPosition(sf::Vector2f(squareBrownPosX, squareBrownPosY));

            // Draw
            window.draw(squareYellow);
            window.draw(squareBrown);
        }
    }
}

void initializeBoardPositionsCoords()
{
    for (int rowIdx = 0; rowIdx < BOARD_ROWS; rowIdx++)
    {
        for (int colIdx = 0; colIdx < BOARD_ROWS; colIdx++)
        {
            chessBoardCoordMap[std::make_pair(columnNames.at(colIdx), rowNames.at(rowIdx))] = 
                sf::Vector2f(
                            HALF_SQUARE_LENGTH_INT + (colIdx * SQUARE_LENGTH), 
                            HALF_SQUARE_LENGTH_INT + (rowIdx *  SQUARE_LENGTH));
            chessBoardPositionArr[rowIdx][colIdx] = std::make_pair(columnNames.at(colIdx), rowNames.at(rowIdx));
        }
    }
}

std::pair<char, char> getSquarePosFromCoord(sf::Vector2f squareCoord)
{
    // std::cout << "Input coord: " << squareCoord.x << ", " << squareCoord.y << "\n";
    uint8_t rowIdx = (squareCoord.y - HALF_SQUARE_LENGTH_INT) / SQUARE_LENGTH;
    uint8_t colIdx = (squareCoord.x - HALF_SQUARE_LENGTH_INT) / SQUARE_LENGTH;
    std::pair<char, char> squarePos;

    if (rowIdx > BOARD_ROWS || colIdx > BOARD_ROWS)
    {
        return std::make_pair('L', 'L');
    }

    squarePos = chessBoardPositionArr[rowIdx][colIdx];
    DEBUG_PRINT("square pos: " << squarePos.first << ", " << squarePos.second);
    return squarePos;
}

sf::Vector2f getSquareCoordFromPos(std::pair<char, char> pos)
{
    return chessBoardCoordMap[pos];
}

int getPieceIdAtSquare(std::pair<char, char> squarePos)
{
    // TODO: Add invalid checks
    
    return chessBoardOccupationMap[squarePos];
}

int setPieceIdAtSquare(std::pair<char, char> squarePos, int id)
{
    chessBoardOccupationMap[squarePos] = id;
    return 0;
}

void handle_outside_board(sf::Vector2f *squareCoord)
{
    float x = squareCoord->x;
    float y = squareCoord->y;
    if (x > BOARD_X_COORD_MAX)
    {
        squareCoord->x = BOARD_X_COORD_MAX - HALF_SQUARE_LENGTH_INT;
    }
    else if(x < BOARD_X_COORD_MIN)
    {
        squareCoord->x = BOARD_X_COORD_MIN + HALF_SQUARE_LENGTH_INT;
    }

    if (y > BOARD_Y_COORD_MAX)
    {
        squareCoord->y = BOARD_Y_COORD_MAX - HALF_SQUARE_LENGTH_INT;
    }
    else if(y < BOARD_Y_COORD_MIN)
    {
        squareCoord->y = BOARD_Y_COORD_MIN + HALF_SQUARE_LENGTH_INT;
    }
}