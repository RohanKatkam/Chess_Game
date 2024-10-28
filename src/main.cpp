/**
 * Generic Project Top comment
 * Some Author
 * Some date
 * Some version
 * Copyright my ass, just take it!
 * @author
 * @brief Main loop of the game!
 */

#include <iostream>
#include <SFML/graphics.hpp>
#include "piece.h"
#include <unordered_map>
#include <vector>
#include <string>

// Macros
#define BOARD_ROWS 8
#define SQUARE_LENGTH 100.f

std::map<std::pair<char, int>, sf::Vector2f> chessBoardPositionMap;
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

void setBoardPositions()
{
    for (int rowIdx = 0; rowIdx < BOARD_ROWS; rowIdx++)
    {
        for (int colIdx = 0; colIdx < BOARD_ROWS; colIdx++)
        {
            chessBoardPositionMap[std::make_pair(rowNames.at(rowIdx), columnNames.at(colIdx))] = 
                sf::Vector2f(50 + (colIdx * SQUARE_LENGTH / 2), 50 + (rowIdx *  SQUARE_LENGTH / 2));
        }
    }
}
int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");

    pawnPieceShape pawn(sf::Vector2f(SQUARE_LENGTH / 2, SQUARE_LENGTH / 2));
    pawnPieceShape pawn_2(sf::Vector2f(SQUARE_LENGTH * 1.5, SQUARE_LENGTH / 2));

    pieceType_c currentPieceSelected = pieceType_c::INVALID;

    drawChessBoard(window);
    setBoardPositions();
    for (const auto &[key, value] : chessBoardPositionMap)
    {
        std::cout << "position:" << (char) key.second << " " << (char) key.first << "," << "(" << value.x << "," << value.y << ")" << std::endl;
    }
    bool isMousePressed = false;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                isMousePressed = true;
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "left click pressed " << std::endl;

                    sf::Vector2f localMousePosition = (sf::Vector2f) sf::Mouse::getPosition(window);
                    
                    // @todo requirement: for a piece and move otherwise do nothing!
                    // get the square ID or more like the number A2, etc, and check for a piece's existence
                    // if there is a piece, move the piece in that position
                    // else do nothing

                    // find the square id based on cursor's position

                    // See what piece in occupied in that square id

                    // current selected piece is that piece
                }
            }
            
            if (event.type == sf::Event::MouseMoved)
            {
                if (isMousePressed)
                {
                    sf::Vector2f localMousePosition = (sf::Vector2f) sf::Mouse::getPosition(window);
                    pawn.setPosition(localMousePosition);
                }
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                isMousePressed = false;
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "Left button released!" << std::endl;
                    
                    sf::Vector2f localMousePosition = (sf::Vector2f) sf::Mouse::getPosition(window);
                    // If pawn, set that position                
                    pawn.setPosition(localMousePosition);

                    // @todo requirement: sort of a state machine
                    // where status of mouse click is moving the piece
                    // once released set the position of that piece to that location
                }
            }
        }

        // clear the window with black color
        window.clear(sf::Color::White);

        // draw everything here...
        // window.draw(...);

        // Draw Chess Board
        drawChessBoard(window);

        // Pawn
        
        pawn.draw(window);

        // Another one, pawn

        pawn_2.draw(window);

        // end the current frame
        window.display();
    }

    return 0;
}