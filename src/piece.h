#ifndef PIECE_H_
#define PIECE_H_

#include <SFML/Graphics.hpp>

/* MACROS */
#define PAWN_PIECE_B_1_ID 69
#define PAWN_PIECE_B_2_ID 70
#define PAWN_PIECE_B_3_ID 71
#define PAWN_PIECE_B_4_ID 72
#define PAWN_PIECE_B_5_ID 73
#define PAWN_PIECE_B_6_ID 74
#define PAWN_PIECE_B_7_ID 75
#define PAWN_PIECE_B_8_ID 76
#define PAWN_PIECE_W_1_ID 77
#define PAWN_PIECE_W_2_ID 78
#define PAWN_PIECE_W_3_ID 79
#define PAWN_PIECE_W_4_ID 80
#define PAWN_PIECE_W_5_ID 81
#define PAWN_PIECE_W_6_ID 82
#define PAWN_PIECE_W_7_ID 83
#define PAWN_PIECE_W_8_ID 84 

/* ENUMS */
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

/* PIECE SHAPE CLASS */
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

/* PAWN PIECE SHAPE CLASS */
class PawnPieceShape : public ChessPieceShape
{
    private:
        sf::CircleShape m_circle;
        sf::ConvexShape m_trapezium;
        sf::ConvexShape m_rectangle;
        sf::Color       m_Color;
    public:
        PawnPieceShape(sf::Vector2f vec, sf::Color color);
        ~PawnPieceShape();
        std::size_t getPointCount() const override;
        sf::Vector2f getPoint(std::size_t index) const override;
        void setShapePos(sf::Vector2f vecPos) override;
        void drawShape(sf::RenderWindow &window) override;

};

/* PIECE CLASS*/
class ChessPiece
{
    private:
        // Not sure if private variable required
        // ChessPieceShape m_pieceShape;
        int m_pieceID;
        std::pair<char, char> m_piecePos;
        pieceStatus_e m_currPieceStatus;
        pieceType_e m_pieceType;
    public:
        ChessPiece(int id, std::pair<char, char> piecePos, pieceType_e type);
        ~ChessPiece() = default;
        int getPieceID();
        std::pair<char, char> getPiecePos();
        int setPiecePos(std::pair<char, char> pos);
        pieceStatus_e getCurrPieceStatus();
        int setCurrPieceStatus(pieceStatus_e status);
        pieceType_e getPieceType();

        virtual void draw(sf::RenderWindow &window) = 0;
        virtual void setCoord(sf::Vector2f vecCoord) = 0;
        virtual void movePiece(std::pair<char, char> pos) = 0;

};

/* PAWN PIECE CLASS*/
class PawnPiece : public ChessPiece
{
    private:
        PawnPieceShape pawnShape;
    public:
        PawnPiece(  sf::Vector2f vec, 
                    int id, 
                    std::pair<char, char> piecePos,
                    sf::Color color = sf::Color::Black
                );
        void draw(sf::RenderWindow &window) override;
        void setCoord(sf::Vector2f vecCoord) override;
        void movePiece(std::pair<char, char> pos);
        

};

// Shapes
void createPawnShape(sf::RenderWindow &window);

#endif // PIECE_H_