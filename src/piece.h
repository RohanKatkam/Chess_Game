#ifndef PIECE_H_
#define PIECE_H_

#include <SFML/Graphics.hpp>

enum class pieceType_c 
{
    PAWN,
    ROOK,
    BISHOP,
    INVALID
};

enum class pieceColor_c
{
    BLACK,
    WHITE
};

class pawnPieceShape : public sf::Shape
{
    private:
        sf::CircleShape m_circle;
        sf::ConvexShape m_trapezium;
        sf::ConvexShape m_rectangle;

    public:
        pawnPieceShape(sf::Vector2f vec);
        ~pawnPieceShape();
        virtual std::size_t getPointCount() const;
        virtual sf::Vector2f getPoint(std::size_t index) const;
        void draw(sf::RenderWindow &window);
        void setPosition(sf::Vector2f vecPos);
};

// Shapes
void createPawnShape(sf::RenderWindow &window);
void createBishopShape();
void createRookShape();
void createDefaultShape();
#endif // PIECE_H_