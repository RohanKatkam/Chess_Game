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

// Macros
#define BOARD_ROWS 8
#define SQUARE_LENGTH 100.f

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

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");

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
        }

        // clear the window with black color
        window.clear(sf::Color::White);

        // draw everything here...
        // window.draw(...);

        // Draw Chess Board
        drawChessBoard(window);

        // Pawn
        pawnPieceShape pawn(sf::Vector2f(SQUARE_LENGTH / 2, SQUARE_LENGTH / 2));
        pawn.draw(window);

        // Another one, pawn
        pawnPieceShape pawn_2(sf::Vector2f(SQUARE_LENGTH * 1.5, SQUARE_LENGTH / 2));
        pawn_2.draw(window);

        // end the current frame
        window.display();
    }

    return 0;
}