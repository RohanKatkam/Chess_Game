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
#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>

#include "board.h"
#include "piece.h"
#include "util.h"

/* MACROS */

sf::Vector2f getSquarePosFromCursor(sf::Vector2f cursorVec)
{
    int x = cursorVec.x;
    int y = cursorVec.y;

    int squareX = (int) (std::floor(x / SQUARE_LENGTH) * SQUARE_LENGTH) + HALF_SQUARE_LENGTH_INT;
    int squareY = (int) (std::floor(y / SQUARE_LENGTH) * SQUARE_LENGTH) + HALF_SQUARE_LENGTH_INT;

    DEBUG_PRINT("square position: " << squareX << "," << squareY );

    return sf::Vector2f(squareX, squareY);
}

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");

    PawnPiece *pawnPiece_1 = new PawnPiece(sf::Vector2f(SQUARE_LENGTH / 2, SQUARE_LENGTH / 2), PAWN_PIECE_1_ID, std::make_pair('A', '1'));
    PawnPiece *pawnPiece_2 = new PawnPiece(sf::Vector2f(SQUARE_LENGTH * 1.5, SQUARE_LENGTH / 2), PAWN_PIECE_2_ID, std::make_pair('B', '1'));
    PawnPiece *pawnPiece_3 = new PawnPiece(sf::Vector2f(SQUARE_LENGTH * 2.5, SQUARE_LENGTH / 2), PAWN_PIECE_3_ID, std::make_pair('C', '1'));
    PawnPiece *pawnPiece_4 = new PawnPiece(sf::Vector2f(SQUARE_LENGTH * 3.5, SQUARE_LENGTH / 2), PAWN_PIECE_4_ID, std::make_pair('D', '1'));
    
    // TODO function place piece on the board, and use pawnPiece_1.getCurrPos
    
    chessBoardOccupationMap[std::pair('A', '1')] = pawnPiece_1->getPieceID();
    chessBoardOccupationMap[std::pair('B', '1')] = pawnPiece_2->getPieceID();
    chessBoardOccupationMap[std::pair('C', '1')] = pawnPiece_3->getPieceID();
    chessBoardOccupationMap[std::pair('D', '1')] = pawnPiece_4->getPieceID();

    // TODO
    pieceType_e currentPieceSelected = pieceType_e::INVALID;
    int currentPieceSelected_ID = 0;

    std::vector<ChessPiece*> chessPiece_vec = {pawnPiece_1, pawnPiece_2, pawnPiece_3, pawnPiece_4};

    drawChessBoard(window);
    setBoardPositions();

#ifdef DEBUG_MODE
    for (const auto &[key, value] : chessBoardPositionMap)
    {
        std::cout << "position:" << (char) key.second << " " << (char) key.first << "," \
        << "(" << value.x << "," << value.y << ")" << std::endl;
    }
#endif

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
                    DEBUG_PRINT("left click pressed");

                    sf::Vector2f localMousePosition = (sf::Vector2f) sf::Mouse::getPosition(window);
                
                    // find the square id based on cursor's position
                    sf::Vector2f squareCoord = getSquarePosFromCursor(localMousePosition);
                    std::pair<char, char> squarePos = getSquarePosFromCoord(squareCoord);
        
                    DEBUG_PRINT("sq POS: " << squarePos.second << "," << squarePos.first);
                    
                    // TODO: Change this
                    squarePos = std::make_pair(squarePos.second, squarePos.first);

                    // See what piece in occupied in that square id
                    int pieceIdAtSqure = getPieceIdAtSquare(squarePos);
                    DEBUG_PRINT("FOUND piece ID at sq: " << pieceIdAtSqure);

                    for (auto &chessPieceEle : chessPiece_vec)
                    {
                        if ((*chessPieceEle).getPieceID() == pieceIdAtSqure)
                        {
                            // current selected piece is that piece
                            currentPieceSelected_ID = pieceIdAtSqure;
                            (*chessPieceEle).setCoord(squareCoord);

                            setPieceIdAtSquare(squarePos, 0);
                        }
                    }
                }
            }
            
            if (event.type == sf::Event::MouseMoved)
            {
                if (isMousePressed)
                {
                    sf::Vector2f localMousePosition = (sf::Vector2f) sf::Mouse::getPosition(window);

                    for (auto &chessPieceEle : chessPiece_vec)
                    {
                        if ((*chessPieceEle).getPieceID() == currentPieceSelected_ID)
                        {
                            (*chessPieceEle).setCoord(localMousePosition);
                        }
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                isMousePressed = false;
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "Left button released!" << std::endl;
                    
                    sf::Vector2f localMousePosition = (sf::Vector2f) sf::Mouse::getPosition(window);              
                    
                    // @todo requirement: sort of a state machine
                    // where status of mouse click is moving the piece
                    // once released set the position of that piece to that location

                    sf::Vector2f squareCoord = getSquarePosFromCursor(localMousePosition);
                    std::pair<char, char> squarePos = getSquarePosFromCoord(squareCoord);
                    // Square Pos is same as ID
                    // TODO: Change this
                    squarePos = std::make_pair(squarePos.second, squarePos.first);
                    
                    for (auto &chessPieceEle : chessPiece_vec)
                    {
                        int eleId = (*chessPieceEle).getPieceID();
                        if (eleId == currentPieceSelected_ID)
                        {
                            (*chessPieceEle).setCoord(squareCoord);

                            // Now this square is occupied with a piece of some id
                            setPieceIdAtSquare(squarePos, eleId);

                            // piece is released from the cursor
                            currentPieceSelected_ID = 0;
                        }
                    }
                }
            }
        }

        // clear the window with black color
        window.clear(sf::Color::White);

        // Draw Chess Board
        drawChessBoard(window);
        
        pawnPiece_1->draw(window);
        pawnPiece_2->draw(window);
        pawnPiece_3->draw(window);
        pawnPiece_4->draw(window);

        // end the current frame
        window.display();
    }

    return 0;
}