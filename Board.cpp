#include "Board.h"

Board::Board(char*& current_position)
{
    map_Char = std::map<std::string, char>();
    for(int i=0; i<32; i++)
    {
        map_Char[std::string{char('a'+i%4),char('8'-i/4)}] = current_position[i];
        std::map<Path, std::string> temp;

		if(i/4>0)
			temp[Path::Up] = std::string{char('a'+i%4),char('8'-i/4+1)}; //
		if(i/4<7)
			temp[Path::Down] = std::string{char('a'+i%4),char('8'-i/4-1)}; //
		if(i%4>0)
			temp[Path::Left] = std::string{char('a'+i%4-1),char('8'-i/4)};
		if(i%4<3)
			temp[Path::Right] = std::string{char('a'+i%4+1),char('8'-i/4)};

        this->pathTo[std::string{char('a'+i%4),char('8'-i/4)}] = temp;
    }
}

Board::~Board()
{
    //dtor
}

void Board::makeMove(char *move)
{
    std::string src, dst;

    src = std::string{move[0],move[1]};
    if(move[2]=='-')
    {
        dst = std::string{move[3],move[4]};
        map_Char[dst] = map_Char[src];
        map_Char[src] = '-';
    }
    else
        map_Char[src] = move[3] ;
}

std::string Board::jumpTo(std::string src, Path path)
{
    while(this->pathTo[src].count(path)&&this->map_Char[this->pathTo[src][path]]=='-')
        src = this->pathTo[src][path];
    if(this->pathTo[src].count(path))
    {
        src = this->pathTo[src][path];
        while(this->pathTo[src].count(path)&&this->map_Char[this->pathTo[src][path]]=='-')
            src = this->pathTo[src][path];
        if(this->pathTo[src].count(path))
        {
            src = this->pathTo[src][path];
            return src ;
        }
        else
            return "outer" ;
    }
    else
        return "outer" ;
}

bool Board::momentum(char hig, char low)
{
	return (hig=='X'||low=='X'||islower(hig)==islower(low))
        ? false : low=='-'||hig=='c'||hig=='C'||
	    (hig=='k'&&low!='P')||
	    (hig=='g'&&low!='K')||
	    (hig=='m'&&(low!='G'&&low!='K'))||
	    (hig=='r'&&(low!='M'&&low!='G'&&low!='K'))||
	    (hig=='n'&&(low=='N'||low=='C'||low=='P'))||
		(hig=='p'&&(low=='K'||low=='P'))||
	    (hig=='K'&&low!='p')||
	    (hig=='G'&&low!='k')||
	    (hig=='M'&&(low!='g'&&low!='k'))||
	    (hig=='R'&&(low!='m'&&low!='g'&&low!='k'))||
	    (hig=='N'&&(low=='n'||low=='c'||low=='p'))||
	    (hig=='P'&&(low=='k'||low=='p'));
}

std::map<std::string, char> Board::getMapChar()
{
    return this->map_Char ;
}

std::map<std::string, std::map<Path, std::string>>  Board::getPathTo()
{
    return this->pathTo ;
}
