#ifndef PLAYER_H
#define PLAYER_H

#include <set>
#include "Board.h"
#include "Protocol.h"

class Player
{
    public:
        Player();
        virtual ~Player();

        void setColor(PROTO_CLR);
        void generateMove(char *);
        void makeMove(char *);
    protected:

    private:
        bool color;
        Board *board;
};

#endif // PLAYER_H