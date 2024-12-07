/**
 * @brief Piece Class and methods
 * @todo Make piece.h for holding macros and enums
 */

#include <iostream>
#include <vector>
#include <utility>
#include <SFML/graphics.hpp>

#include "piece.h"
#include "board.h"
#include "util.h"

/* CHESS PIECE METHOD DEFINITIONS*/

// CHESS PIECE SHAPE
std::size_t ChessPieceShape::getPointCount() const
{
    return 0;
}

// PAWN PIECE SHAPE

// Ideally a param should be starting point for the shape
PawnPieceShape::PawnPieceShape(sf::Vector2f vec, sf::Color color=sf::Color::Black)
{
    m_Color = color;
    // Circle Head
    // change these literals to BOARD_SQUARE_HALF
    m_circle.setRadius(10.f);
    m_circle.setPosition(vec.x-10, vec.y-10);
    // m_circle.setOrigin(sf::Vector2f(vec.x-10, vec.y-10));
    m_circle.setPosition(vec.x-10, vec.y-10);
    m_circle.setFillColor(m_Color);

    // Trapezium
    m_trapezium.setPointCount(4);
    m_trapezium.setPoint(0, sf::Vector2f(vec.x-5, vec.y));
    m_trapezium.setPoint(1, sf::Vector2f(vec.x+5, vec.y));
    m_trapezium.setPoint(2, sf::Vector2f(vec.x+15, vec.y+25));
    m_trapezium.setPoint(3, sf::Vector2f(vec.x-15, vec.y+25));
    m_trapezium.setOrigin(sf::Vector2f(vec.x-5, vec.y));
    m_trapezium.setPosition(vec.x-5, vec.y);
    m_trapezium.setFillColor(m_Color);

    // Rectangle
    m_rectangle.setPointCount(4);
    m_rectangle.setPoint(0, sf::Vector2f(vec.x-20, vec.y+25));
    m_rectangle.setPoint(1, sf::Vector2f(vec.x+20, vec.y+25));
    m_rectangle.setPoint(2, sf::Vector2f(vec.x+20, vec.y+30));
    m_rectangle.setPoint(3, sf::Vector2f(vec.x-20, vec.y+30));
    m_rectangle.setOrigin(sf::Vector2f(vec.x-20, vec.y+25));
    m_rectangle.setPosition(vec.x-20, vec.y+25);
    m_rectangle.setFillColor(m_Color);
}

PawnPieceShape::~PawnPieceShape()
{
    DEBUG_PRINT("Destruction !!");
}

std::size_t PawnPieceShape::getPointCount() const
{
    // Using random ass values for overriding exising methods from shape
     return 30;
}

// Using random ass values for overriding exising methods from shape
sf::Vector2f PawnPieceShape::getPoint(std::size_t index) const
{
    return m_circle.getOrigin();
}

void PawnPieceShape::setShapePos(sf::Vector2f vecPos)
{
    m_trapezium.setPosition(vecPos.x-5, vecPos.y);
    m_rectangle.setPosition(vecPos.x-20, vecPos.y+25);
    m_circle.setPosition(vecPos.x-10, vecPos.y-10);
}

void PawnPieceShape::drawShape(sf::RenderWindow &window)
{
    window.draw(m_trapezium);
    window.draw(m_rectangle);
    window.draw(m_circle);
}

/* CHESS PIECES METHOD DEFINITIONS*/

ChessPiece::ChessPiece(int id, std::pair<char, char> piecePos, pieceType_e type)
{
    m_pieceID = id;
    m_piecePos = piecePos;
    m_currPieceStatus = pieceStatus_e::ON_BOARD;
    m_pieceType = type;
}

int ChessPiece::getPieceID()
{
    return m_pieceID;
}

std::pair<char, char> ChessPiece::getPiecePos()
{
    // like A2, etc
    return m_piecePos;
}

int ChessPiece::setPiecePos(std::pair<char, char> pos)
{
    m_piecePos = pos;
    // return 0 if success
    return 0;
}

int ChessPiece::setCurrPieceStatus(pieceStatus_e status)
{
    m_currPieceStatus = status;
    // return 0 if success
    return 0;
}

pieceType_e ChessPiece::getPieceType()
{
    return m_pieceType;
}

/* PAWN PIECE METHOD DEFINITIONS */

PawnPiece::PawnPiece(sf::Vector2f vec, int id, std::pair<char, char> piecePos, sf::Color color) 
    : pawnShape(vec, color), ChessPiece(id, piecePos, pieceType_e::PAWN)
{
    // other code?
}

void PawnPiece::setCoord(sf::Vector2f vecCoord)
{
    // std::cout << "Set coord: " << vecCoord.x << ", " << vecCoord.y << std::endl;
    pawnShape.setShapePos(vecCoord);
}

// Use this function all the time while rendering!
void PawnPiece::draw(sf::RenderWindow &window)
{
    pawnShape.drawShape(window);
}

void PawnPiece::movePiece(std::pair<char, char> pos)
{
    // TODO: INCORRECT FORMAT!
    sf::Vector2f coord = getSquareCoordFromPos(pos);
    setCoord(coord);
}