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

std::map<std::pair<char, char>, sf::Vector2f> chessBoardPositionMap = {};
std::map<std::pair<char, char>, int> chessBoardOccupationMap = {};
std::pair<char, char> chessBoardPositionArr[BOARD_ROWS][BOARD_ROWS] = {};

std::vector<char> columnNames = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
std::vector<char> rowNames = {'1', '2', '3', '4', '5', '6', '7', '8'};

// void initializeBoardOccupation()
// {

// }

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

void setBoardPositions()
{
    for (int rowIdx = 0; rowIdx < BOARD_ROWS; rowIdx++)
    {
        for (int colIdx = 0; colIdx < BOARD_ROWS; colIdx++)
        {
            chessBoardPositionMap[std::make_pair(rowNames.at(rowIdx), columnNames.at(colIdx))] = 
                sf::Vector2f(50 + (colIdx * SQUARE_LENGTH / 2), 50 + (rowIdx *  SQUARE_LENGTH / 2));
            chessBoardPositionArr[rowIdx][colIdx] = std::make_pair(rowNames.at(rowIdx), columnNames.at(colIdx));
        }
    }
}

std::pair<char, char> getSquarePosFromCoord(sf::Vector2f squareCoord)
{
    // std::cout << "Input coord: " << squareCoord.x << ", " << squareCoord.y << "\n";
    uint8_t rowIdx = (squareCoord.y - 50) / 100;
    uint8_t colIdx = (squareCoord.x - 50) / 100;
    std::pair<char, char> squarePos;

    if (rowIdx > BOARD_ROWS || colIdx > BOARD_ROWS)
    {
        return std::make_pair('L', 'L');
    }

    squarePos = chessBoardPositionArr[rowIdx][colIdx];
    std::cout << "square pos: " << squarePos.second << ", " << squarePos.first << std::endl;
    return squarePos;
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