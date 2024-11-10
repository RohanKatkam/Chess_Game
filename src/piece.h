#ifndef PIECE_H_
#define PIECE_H_

#include <SFML/Graphics.hpp>

/* DEFINES */
#define PAWN_PIECE_1_ID 69
#define PAWN_PIECE_2_ID 70
#define PAWN_PIECE_3_ID 71
#define PAWN_PIECE_4_ID 72


enum class pieceType_e 
{
    PAWN = 1,
    ROOK = 2,
    BISHOP = 3,
    INVALID = -1
};

enum class pieceColor_e
{
    BLACK,
    WHITE
};

enum class pieceStatus_e
{
    ON_BOARD = 0,
    ELIMINATED = 1
};

class ChessPieceShape : public sf::Shape
{
    public:
        // ChessPieceShape(sf::Vector2f vec);
        // ~ChessPieceShape();
        virtual std::size_t getPointCount() const;
        virtual sf::Vector2f getPoint(std::size_t index) const = 0;
        virtual void setShapePos(sf::Vector2f vecPos) = 0;
        virtual void drawShape(sf::RenderWindow &window) = 0;
};

class PawnPieceShape : public ChessPieceShape
{
    private:
        sf::CircleShape m_circle;
        sf::ConvexShape m_trapezium;
        sf::ConvexShape m_rectangle;

    public:
        PawnPieceShape(sf::Vector2f vec);
        ~PawnPieceShape();
        std::size_t getPointCount() const override;
        sf::Vector2f getPoint(std::size_t index) const override;
        void setShapePos(sf::Vector2f vecPos) override;
        void drawShape(sf::RenderWindow &window) override;

};

class ChessPiece
{
    private:
    // Not sure if private variable required
        // ChessPieceShape m_pieceShape;
        int m_pieceID;
        std::pair<char, char> m_piecePos;
        pieceStatus_e m_currPieceStatus;
    public:
        ChessPiece(int id, std::pair<char, char> piecePos);
        int getPieceID();
        std::pair<char, char> getPiecePos();
        int setPiecePos(std::pair<char, char> pos);
        pieceStatus_e getCurrPieceStatus();
        int setCurrPieceStatus(pieceStatus_e status);

        virtual void draw(sf::RenderWindow &window) = 0;
        virtual void setCoord(sf::Vector2f vecCoord) = 0;
        virtual void movePiece(std::pair<char, char> pos) = 0;

};

class PawnPiece : public ChessPiece
{
    private:
        PawnPieceShape pawnShape;
    public:
        PawnPiece(sf::Vector2f vec, int id, std::pair<char, char> piecePos);
        // ~PawnPiece();
        void draw(sf::RenderWindow &window) override;
        void setCoord(sf::Vector2f vecCoord) override;
        void movePiece(std::pair<char, char> pos);
        

};

// Shapes
void createPawnShape(sf::RenderWindow &window);
// void createBishopShape();
// void createRookShape();
// void createDefaultShape();

sf::Vector2f getChessSquareCoord(std::pair<char, char> pos);
#endif // PIECE_H_