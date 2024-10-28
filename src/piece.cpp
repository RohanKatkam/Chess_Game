/**
 * @brief Piece Class and methods
 * @todo Make piece.h for holding macros and enums
 */

#include <iostream>
#include <vector>
#include <utility>
#include <SFML/graphics.hpp>
#include "piece.h"


// Ideally a param should be starting point for the shape
pawnPieceShape::pawnPieceShape(sf::Vector2f vec)
{
    // Circle Head
    // change these literals to BOARD_SQUARE_HALF
    m_circle.setRadius(10.f);
    m_circle.setPosition(vec.x-10, vec.y-15);
    // m_circle.setPosition(40.f, 35.f);
    m_circle.setFillColor(sf::Color::Black);

    // Trapezium
    m_trapezium.setPointCount(4);
    // m_trapezium.setPoint(0, sf::Vector2f(45.f, 50.f));
    // m_trapezium.setPoint(1, sf::Vector2f(55.f, 50.f));
    // m_trapezium.setPoint(2, sf::Vector2f(65.f, 75.f));
    // m_trapezium.setPoint(3, sf::Vector2f(35.f, 75.f));
    m_trapezium.setPoint(0, sf::Vector2f(vec.x-5, vec.y));
    m_trapezium.setPoint(1, sf::Vector2f(vec.x+5, vec.y));
    m_trapezium.setPoint(2, sf::Vector2f(vec.x+15, vec.y+25));
    m_trapezium.setPoint(3, sf::Vector2f(vec.x-15, vec.y+25));
    m_trapezium.setOrigin(sf::Vector2f(vec.x-5, vec.y));
    m_trapezium.setPosition(vec.x-5, vec.y);
    m_trapezium.setFillColor(sf::Color::Black);

    // Rectangle
    m_rectangle.setPointCount(4);
    // m_rectangle.setPoint(0, sf::Vector2f(30.f, 75.f));
    // m_rectangle.setPoint(1, sf::Vector2f(70.f, 75.f));
    // m_rectangle.setPoint(2, sf::Vector2f(70.f, 80.f));
    // m_rectangle.setPoint(3, sf::Vector2f(30.f, 80.f));
    m_rectangle.setPoint(0, sf::Vector2f(vec.x-20, vec.y+25));
    m_rectangle.setPoint(1, sf::Vector2f(vec.x+20, vec.y+25));
    m_rectangle.setPoint(2, sf::Vector2f(vec.x+20, vec.y+30));
    m_rectangle.setPoint(3, sf::Vector2f(vec.x-20, vec.y+30));
    m_rectangle.setOrigin(sf::Vector2f(vec.x-20, vec.y+25));
    m_rectangle.setPosition(vec.x-20, vec.y+25);
    m_rectangle.setFillColor(sf::Color::Black);
}

pawnPieceShape::~pawnPieceShape()
{

}

// Using random ass values for overriding exising methods from shape
std::size_t pawnPieceShape::getPointCount() const
{
     return 30;
}

// Using random ass values for overriding exising methods from shape
sf::Vector2f pawnPieceShape::getPoint(std::size_t index) const
{
    return sf::Vector2f(100,100);
}

void pawnPieceShape::draw(sf::RenderWindow &window) 
{
    // Ideally return these elements instead of window drawing
    window.draw(m_trapezium);
    window.draw(m_rectangle);
    window.draw(m_circle);
}

void pawnPieceShape::setPosition(sf::Vector2f vecPos)
{
    m_trapezium.setPosition(vecPos.x-5, vecPos.y);
    m_rectangle.setPosition(vecPos.x-20, vecPos.y+25);
    m_circle.setPosition(vecPos.x-10, vecPos.y-10);
}

void createBishopShape()
{

}

void createRookShape()
{

}

void createDefaultShape()
{

}

void createPawnShape(sf::RenderWindow &window)
{   
    
}

class chessPiece
{
    private:
        /* data */

    public:
        chessPiece(pieceType_c piece);
        ~chessPiece();

        void movePiece();
        sf::Vector2f getPosition();
        void resetPosition();
};

chessPiece::chessPiece(pieceType_c piece)
{
    // Draw the piece diagram based on the macro

    // Set the position, with reset position
}

chessPiece::~chessPiece()
{
}

void chessPiece::movePiece()
{

}