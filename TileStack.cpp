// Kavi Sachania

#include "TileStack.h"
#include "strlib.h"
#include "stack.h"
using namespace std;



string name;
string pos;
string team;
int score;
int bye;

TileStack::TileStack()
{

}

TileStack::TileStack(string name0, string pos0, string team0, int score0)
{
    name = name0;
    pos = pos0;
    team = team0;
    score = score0;
}

void TileStack::setBye()
{
    if ((team == "GB") || (team == "Phi"))
    {
        bye = 4;
    }
    if ((team == "Jax") || (team == "KC") || (team == "NO") || (team == "Sea"))
    {
        bye = 5;
    }
    if ((team == "Min") || (team == "TB"))
    {
        bye = 6;
    }
    if ((team == "Car") || (team == "Dal"))
    {
        bye = 7;
    }
    if ((team == "Bal") || (team == "LA") || (team == "Mia") || (team == "NYG") || (team == "Pit") || (team == "SF"))
    {
        bye = 8;
    }
    if ((team == "Ari") || (team == "Chi") || (team == "Cin") || (team == "Hou") || (team == "NE") || (team == "Wsh"))
    {
        bye = 9;
    }
    if ((team == "Buf") || (team == "Det") || (team == "Ind") || (team == "Oak"))
    {
        bye = 10;
    }
    if ((team == "Atl") || (team == "Den") || (team == "NYJ") || (team == "SD"))
    {
        bye = 11;
    }
    if ((team == "Cle") || (team == "Ten"))
    {
        bye = 13;
    }
}

TileStack::~TileStack()
{

}
