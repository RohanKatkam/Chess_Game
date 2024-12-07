/**
 * Generic Project Top comment
 * Some Author
 * Some date
 * Some version
 * Copyright my ass, just take it!
 * @author
 * @brief Main loop of the game!
 * Quicc TODO: 
 * 
 */

/* INCLUDES */
#include <iostream>
#include <SFML/graphics.hpp>
#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>
#include <memory>

#include "board.h"
#include "piece.h"
#include "util.h"

/* MACROS */

// Black pawn
std::shared_ptr<PawnPiece> pawnPiece_b_1;
std::shared_ptr<PawnPiece> pawnPiece_b_2;
std::shared_ptr<PawnPiece> pawnPiece_b_3;
std::shared_ptr<PawnPiece> pawnPiece_b_4;
std::shared_ptr<PawnPiece> pawnPiece_b_5;
std::shared_ptr<PawnPiece> pawnPiece_b_6;
std::shared_ptr<PawnPiece> pawnPiece_b_7;
std::shared_ptr<PawnPiece> pawnPiece_b_8;

// White pawn
std::shared_ptr<PawnPiece> pawnPiece_w_1;
std::shared_ptr<PawnPiece> pawnPiece_w_2;
std::shared_ptr<PawnPiece> pawnPiece_w_3;
std::shared_ptr<PawnPiece> pawnPiece_w_4;
std::shared_ptr<PawnPiece> pawnPiece_w_5;
std::shared_ptr<PawnPiece> pawnPiece_w_6;
std::shared_ptr<PawnPiece> pawnPiece_w_7;
std::shared_ptr<PawnPiece> pawnPiece_w_8;
    
sf::Vector2f getSquareCoordFromCursor(sf::Vector2f cursorVec)
{
    int x = cursorVec.x;
    int y = cursorVec.y;

    int squareX = (int) (std::floor(x / SQUARE_LENGTH) * SQUARE_LENGTH) + HALF_SQUARE_LENGTH_INT;
    int squareY = (int) (std::floor(y / SQUARE_LENGTH) * SQUARE_LENGTH) + HALF_SQUARE_LENGTH_INT;

    DEBUG_PRINT("square position: " << squareX << "," << squareY );

    return sf::Vector2f(squareX, squareY);
}

std::pair<char, char> getSquarePosFromCursor(sf::Vector2f localMousePosition)
{
    // find the square id based on cursor's position
    sf::Vector2f squareCoord = getSquareCoordFromCursor(localMousePosition);
    DEBUG_PRINT("sq POS: " << squareCoord.x << "," << squareCoord.y);
    std::pair<char, char> squarePos = getSquarePosFromCoord(squareCoord);

    return squarePos;
}

void initializeBlackPawns()
{
    sf::Color color = sf::Color::Black;

    pawnPiece_b_1 = std::make_shared<PawnPiece>(
                                            getSquareCoordFromPos(std::make_pair('A', '2')), 
                                            PAWN_PIECE_B_1_ID, 
                                            std::make_pair('A', '2'), 
                                            color);
    pawnPiece_b_2 = std::make_shared<PawnPiece>(
                                            getSquareCoordFromPos(std::make_pair('B', '2')), 
                                            PAWN_PIECE_B_2_ID, 
                                            std::make_pair('B', '2'), 
                                            color);
    pawnPiece_b_3 = std::make_shared<PawnPiece>(
                                            getSquareCoordFromPos(std::make_pair('C', '2')), 
                                            PAWN_PIECE_B_3_ID, 
                                            std::make_pair('C', '2'), 
                                            color);
    pawnPiece_b_4 = std::make_shared<PawnPiece>(
                                            getSquareCoordFromPos(std::make_pair('D', '2')), 
                                            PAWN_PIECE_B_4_ID, 
                                            std::make_pair('D', '2'), 
                                            color);
    pawnPiece_b_5 = std::make_shared<PawnPiece>(
                                            getSquareCoordFromPos(std::make_pair('E', '2')), 
                                            PAWN_PIECE_B_5_ID, 
                                            std::make_pair('E', '2'), 
                                            color);
    pawnPiece_b_6 = std::make_shared<PawnPiece>(
                                            getSquareCoordFromPos(std::make_pair('F', '2')), 
                                            PAWN_PIECE_B_6_ID, 
                                            std::make_pair('F', '2'), 
                                            color);
    pawnPiece_b_7 = std::make_shared<PawnPiece>(
                                            getSquareCoordFromPos(std::make_pair('G', '2')), 
                                            PAWN_PIECE_B_7_ID, 
                                            std::make_pair('G', '2'), 
                                            color);
    pawnPiece_b_8 = std::make_shared<PawnPiece>(
                                            getSquareCoordFromPos(std::make_pair('H', '2')), 
                                            PAWN_PIECE_B_8_ID, 
                                            std::make_pair('H', '2'), 
                                            color);
}

void initializeWhitePawns()
{
    sf::Color color = sf::Color::White;

    pawnPiece_w_1 = std::make_shared<PawnPiece>(
                                            getSquareCoordFromPos(std::make_pair('A', '7')), 
                                            PAWN_PIECE_W_1_ID, 
                                            std::make_pair('A', '7'), 
                                            color);
    pawnPiece_w_2 = std::make_shared<PawnPiece>(
                                            getSquareCoordFromPos(std::make_pair('B', '7')), 
                                            PAWN_PIECE_W_2_ID, 
                                            std::make_pair('B', '7'), 
                                            color);
    pawnPiece_w_3 = std::make_shared<PawnPiece>(
                                            getSquareCoordFromPos(std::make_pair('C', '7')), 
                                            PAWN_PIECE_W_3_ID, 
                                            std::make_pair('C', '7'), 
                                            color);
    pawnPiece_w_4 = std::make_shared<PawnPiece>(
                                            getSquareCoordFromPos(std::make_pair('D', '7')), 
                                            PAWN_PIECE_W_4_ID, 
                                            std::make_pair('D', '7'), 
                                            color);
    pawnPiece_w_5 = std::make_shared<PawnPiece>(
                                            getSquareCoordFromPos(std::make_pair('E', '7')), 
                                            PAWN_PIECE_W_5_ID, 
                                            std::make_pair('E', '7'), 
                                            color);
    pawnPiece_w_6 = std::make_shared<PawnPiece>(
                                            getSquareCoordFromPos(std::make_pair('F', '7')), 
                                            PAWN_PIECE_W_6_ID, 
                                            std::make_pair('F', '7'), 
                                            color);
    pawnPiece_w_7 = std::make_shared<PawnPiece>(
                                            getSquareCoordFromPos(std::make_pair('G', '7')), 
                                            PAWN_PIECE_W_7_ID, 
                                            std::make_pair('G', '7'), 
                                            color);
    pawnPiece_w_8 = std::make_shared<PawnPiece>(
                                            getSquareCoordFromPos(std::make_pair('H', '7')), 
                                            PAWN_PIECE_W_8_ID, 
                                            std::make_pair('H', '7'), 
                                            color);
}

/* MAIN */
int main()
{
    // create the window
    sf::RenderWindow window(
                        sf::VideoMode(SQUARE_LENGTH * BOARD_ROWS, SQUARE_LENGTH * BOARD_COLUMNS), 
                        "My window");

    drawChessBoard(window);
    initializeBoardPositionsCoords();
    
    // Initialize pawns
    initializeBlackPawns();
    initializeWhitePawns();

    // Ensure occupation map knows the pawns initial location
    chessBoardOccupationMap[pawnPiece_b_1->getPiecePos()] = pawnPiece_b_1->getPieceID();
    chessBoardOccupationMap[pawnPiece_b_2->getPiecePos()] = pawnPiece_b_2->getPieceID();
    chessBoardOccupationMap[pawnPiece_b_3->getPiecePos()] = pawnPiece_b_3->getPieceID();
    chessBoardOccupationMap[pawnPiece_b_4->getPiecePos()] = pawnPiece_b_4->getPieceID();
    chessBoardOccupationMap[pawnPiece_b_5->getPiecePos()] = pawnPiece_b_5->getPieceID();
    chessBoardOccupationMap[pawnPiece_b_6->getPiecePos()] = pawnPiece_b_6->getPieceID();
    chessBoardOccupationMap[pawnPiece_b_7->getPiecePos()] = pawnPiece_b_7->getPieceID();
    chessBoardOccupationMap[pawnPiece_b_8->getPiecePos()] = pawnPiece_b_8->getPieceID();

    chessBoardOccupationMap[pawnPiece_w_1->getPiecePos()] = pawnPiece_w_1->getPieceID();
    chessBoardOccupationMap[pawnPiece_w_2->getPiecePos()] = pawnPiece_w_2->getPieceID();
    chessBoardOccupationMap[pawnPiece_w_3->getPiecePos()] = pawnPiece_w_3->getPieceID();
    chessBoardOccupationMap[pawnPiece_w_4->getPiecePos()] = pawnPiece_w_4->getPieceID();
    chessBoardOccupationMap[pawnPiece_w_5->getPiecePos()] = pawnPiece_w_5->getPieceID();
    chessBoardOccupationMap[pawnPiece_w_6->getPiecePos()] = pawnPiece_w_6->getPieceID();
    chessBoardOccupationMap[pawnPiece_w_7->getPiecePos()] = pawnPiece_w_7->getPieceID();
    chessBoardOccupationMap[pawnPiece_w_8->getPiecePos()] = pawnPiece_w_8->getPieceID();

    // TODO, for state machine lolz
    pieceType_e currentPieceSelected = pieceType_e::INVALID;
    int currentPieceSelected_ID = 0;

    // Vector of chess pieces
    std::vector<std::shared_ptr<ChessPiece>> chessPiece_vec;
    chessPiece_vec.push_back(pawnPiece_b_1);
    chessPiece_vec.push_back(pawnPiece_b_2);
    chessPiece_vec.push_back(pawnPiece_b_3);
    chessPiece_vec.push_back(pawnPiece_b_4);
    chessPiece_vec.push_back(pawnPiece_b_5);
    chessPiece_vec.push_back(pawnPiece_b_6);
    chessPiece_vec.push_back(pawnPiece_b_7);
    chessPiece_vec.push_back(pawnPiece_b_8);

    chessPiece_vec.push_back(pawnPiece_w_1);
    chessPiece_vec.push_back(pawnPiece_w_2);
    chessPiece_vec.push_back(pawnPiece_w_3);
    chessPiece_vec.push_back(pawnPiece_w_4);
    chessPiece_vec.push_back(pawnPiece_w_5);
    chessPiece_vec.push_back(pawnPiece_w_6);
    chessPiece_vec.push_back(pawnPiece_w_7);
    chessPiece_vec.push_back(pawnPiece_w_8);

#if DEBUG_MODE
    for (const auto &[key, value] : chessBoardCoordMap)
    {
        std::cout << "position:" << (char) key.first << " " << (char) key.second << "," \
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

                    std::pair<char, char> squarePos = getSquarePosFromCursor((sf::Vector2f) sf::Mouse::getPosition(window));
        
                    DEBUG_PRINT("sq POS: " << squarePos.first << "," << squarePos.second);
                    
                    // TODO: Change this
                    // squarePos = std::make_pair(squarePos.second, squarePos.first);

                    // See what piece in occupied in that square id
                    int pieceIdAtSqure = getPieceIdAtSquare(squarePos);
                    DEBUG_PRINT("FOUND piece ID at sq: " << pieceIdAtSqure);

                    for (auto &chessPieceEle : chessPiece_vec)
                    {
                        if ((*chessPieceEle).getPieceID() == pieceIdAtSqure)
                        {
                            // current selected piece is that piece
                            currentPieceSelected_ID = pieceIdAtSqure;
                            // (*chessPieceEle).setCoord(squareCoord);
                            (*chessPieceEle).movePiece(squarePos);

                            setPieceIdAtSquare(squarePos, 0);
                            break;
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
                            // (*chessPieceEle).movePiece(pos);
                            break;
                        }
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                isMousePressed = false;
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    DEBUG_PRINT("Left button released!");
                    
                    sf::Vector2f localMousePosition = (sf::Vector2f) sf::Mouse::getPosition(window);              
                    
                    // @todo requirement: sort of a state machine
                    // where status of mouse click is moving the piece
                    // once released set the position of that piece to that location

                    sf::Vector2f squareCoord = getSquareCoordFromCursor(localMousePosition);
                    handle_outside_board(&squareCoord);
                    std::pair<char, char> squarePos = getSquarePosFromCoord(squareCoord);
                    // Square Pos is same as ID
                    // TODO: Change this
                    // squarePos = std::make_pair(squarePos.second, squarePos.first);
                    
                    for (auto &chessPieceEle : chessPiece_vec)
                    {
                        int eleId = (*chessPieceEle).getPieceID();
                        if (eleId == currentPieceSelected_ID)
                        {
                            int pieceIdAtSquare = getPieceIdAtSquare(squarePos);
                            // If already a piece at that square
                            if (pieceIdAtSquare != 0)
                            {
                                std::pair<char, char> backToSqaurePos = chessPieceEle->getPiecePos();
                                // Takes A 2
                                DEBUG_PRINT("Going back to: " << backToSqaurePos.first << ",," << backToSqaurePos.second);
                                sf::Vector2f coord = getSquareCoordFromPos(backToSqaurePos);

                                std::cout << coord.x << ",  " << coord.y << "\n";
                                chessPieceEle->setCoord(coord);
                                
                                // A 2
                                // chessPieceEle->setPiecePos(backToSqaurePos);
                                setPieceIdAtSquare(backToSqaurePos, eleId);
                            }
                            else
                            {
                                // If square empty
                                (*chessPieceEle).setCoord(squareCoord);
                                chessPieceEle->setPiecePos(squarePos);
                                // Now this square is occupied with a piece of some id
                                setPieceIdAtSquare(squarePos, eleId);
                            }

                            // piece is released from the cursor
                            currentPieceSelected_ID = 0;
                            break;
                        }
                    }
                }
            }
        }

        // clear the window with default color
        window.clear(sf::Color::White);

        // Draw Chess Board
        drawChessBoard(window);

        // TODO: Can use when window is resized
        window.getPosition();
        
        // Draw All the Pieces
        pawnPiece_b_1->draw(window);
        pawnPiece_b_2->draw(window);
        pawnPiece_b_3->draw(window);
        pawnPiece_b_4->draw(window);
        pawnPiece_b_5->draw(window);
        pawnPiece_b_6->draw(window);
        pawnPiece_b_7->draw(window);
        pawnPiece_b_8->draw(window);

        pawnPiece_w_1->draw(window);
        pawnPiece_w_2->draw(window);
        pawnPiece_w_3->draw(window);
        pawnPiece_w_4->draw(window);
        pawnPiece_w_5->draw(window);
        pawnPiece_w_6->draw(window);
        pawnPiece_w_7->draw(window);
        pawnPiece_w_8->draw(window);

        // end the current frame
        window.display();
    }

    return 0;
}