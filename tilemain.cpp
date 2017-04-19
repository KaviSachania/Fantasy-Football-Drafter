

#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "Vector.h"
#include "simpio.h"
#include "strlib.h"
#include "TileStack.h"
using namespace std;

void draftPlayer(Vector<TileStack>& chosen, Vector<Vector<TileStack>>& players, Vector<string>& recentPicks, int& qb, int& rb, int& wr, int& te, int& dst, int& k, int pick);


int main()
{
    ifstream input;
    string word;


    Vector<TileStack> qbV;
    Vector<TileStack> rbV;
    Vector<TileStack> wrV;
    Vector<TileStack> teV;
    Vector<TileStack> dstV;
    Vector<TileStack> kV;

    Vector<Vector<TileStack>> players;
    players.add(qbV);
    players.add(rbV);
    players.add(wrV);
    players.add(teV);
    players.add(dstV);
    players.add(kV);


    input.open("Players1.txt");
    word = "";
    while (input >> word)//rank
    {
        input >> word;//first name
        string first = word;
        word = "";
        input >> word;//name
        string name = first + word;
        word = "";
        input >> word;//team
        string team = word;
        word = "";
        input >> word;//pos
        string pos = word;
        input >> word;//1
        input >> word;//2
        input >> word;//3
        input >> word;//4
        input >> word;//5
        input >> word;//6
        input >> word;//7
        input >> word;//8
        input >> word;//9
        input >> word;//10
        word = "";
        input >> word;//score
        double score = stringToDouble(word);


        TileStack ts;
        ts.name = name;
        ts.pos = pos;
        ts.team = team;
        ts.setBye();
        ts.score = score;
        cout << name << " " << ts.bye << " " << score << endl;

        if (pos == "QB")
        {
            players[0].add(ts);
        }
        if (pos == "RB")
        {
            players[1].add(ts);
        }
        if (pos == "WR")
        {
            players[2].add(ts);
        }
        if (pos == "TE")
        {
            players[3].add(ts);
        }
        if (pos == "DST")
        {
            players[4].add(ts);
        }
        if (pos == "K")
        {
            players[5].add(ts);
        }


    }
    input.close();

//    cout << qbV.size() << endl;
//    cout << rbV.size() << endl;
//    cout << wrV.size() << endl;
//    cout << teV.size() << endl;
//    cout << dstV.size() << endl;
//    cout << kV.size() << endl;

    cout<< "Pick #: ";
    word = "";
    cin >> word;
    int pick = stringToInteger(word);


    Vector<string> recentPicks;
    Vector<TileStack> chosen;
    int qb = 0;
    int rb = 0;
    int wr = 0;
    int te = 0;
    int dst = 0;
    int k = 0;

    int pick1 = (8 - pick) * 2;
    int pick2 = (pick - 1) * 2;
    if (pick1 == 0)
    {
        pick1 = pick2;
    }
    if (pick2 == 0)
    {
        pick2 = pick1;
    }
    bool pickSwitch = true;
    while (true)
    {
        cin >> word;
        if (word == "draft")
        {
            if (pickSwitch)
            {
                pick = pick1;
            }
            else
            {
                pick = pick2;
            }
            pickSwitch = !pickSwitch;
            draftPlayer(chosen, players, recentPicks, qb, rb, wr, te, dst, k, pick);
        }
        if (word == "quit")
        {
            break;
        }

        for (int i1 = 0; i1 < players.size(); i1++)
        {
            for (int i2 = 0; i2 < players[i1].size(); i2++)
            {
                if (toLowerCase(word) == toLowerCase(players[i1][i2].name))
                {
                    cout << players[i1][i2].name << " removed" << endl;
                    recentPicks.add(players[i1][i2].pos);
                    players[i1].remove(i2);
                    i1 = players.size();
                    break;
                }
            }
        }


    }

    return 0;
}

void draftPlayer(Vector<TileStack>& chosen, Vector<Vector<TileStack>>& players, Vector<string>& recentPicks, int& qb, int& rb, int& wr, int& te, int& dst, int& k, int pick)
{
    cout << "drafting" << endl;

    int qbNum = 0;
    int rbNum = 0;
    int wrNum = 0;
    int teNum = 0;
    int dstNum = 0;
    int kNum = 0;

    int i;
    for (i = recentPicks.size(); (i > 0) && (i > recentPicks.size() - 14); i--)
    {
        if (recentPicks[i - 1] == "QB")
        {
            qbNum++;
        }
        if (recentPicks[i - 1] == "RB")
        {
            rbNum++;
        }
        if (recentPicks[i - 1] == "WR")
        {
            wrNum++;
        }
        if (recentPicks[i - 1] == "TE")
        {
            teNum++;
        }
        if (recentPicks[i - 1] == "DST")
        {
            dstNum++;
        }
        if (recentPicks[i - 1] == "K")
        {
            kNum++;
        }
    }

    i = recentPicks.size() - i;
    if (i == 0)
    {
        i = 1;
    }

    double largestGap = 0;
    double largestPos;

    //qb
    double qbRatio = (double)qbNum / (double)i;
    qbRatio = qbRatio * pick;
    if ((qbRatio > 0) && (qbRatio < 1))
    {
        qbRatio = 1.0;
    }
    int qbLength = (int)(qbRatio + 0.5);

    double qbGap = players[0][0].score - players[0][qbLength].score;
    if (qbRatio == 0)
    {
        qbGap = (players[0][0].score - players[0][1].score) / 2;
    }
    if (qb >= 1)
    {
        if (chosen.size() < 13)
        {
            qbGap *= 0.1;
        }
    }
    if (qb >= 2)
    {
        qbGap = -1;
    }
    if (qbGap > largestGap)
    {
        largestGap = qbGap;
        largestPos = 0;
    }




    //rb
    double rbRatio = (double)rbNum / (double)i;
    rbRatio = rbRatio * pick;
    if ((rbRatio > 0) && (rbRatio < 1))
    {
        rbRatio = 1.0;
    }
    int rbLength = (int)(rbRatio + 0.5);

    if (rbLength > pick / 2)
    {
        rbLength = pick / 2;
    }

    double rbGap = players[1][0].score - players[1][rbLength].score;
    if (rbRatio == 0)
    {
        rbGap = (players[1][0].score - players[1][1].score) / 2;
    }

    if (rb >= 3)
    {
        if (chosen.size() < 13)
        {
            rbGap *= 0.1;
        }
    }
    if (rb >= 5)
    {
        rbGap = -1;
    }
    if (rbGap > largestGap)
    {
        largestGap = rbGap;
        largestPos = 1;
    }


    //wr
    double wrRatio = (double)wrNum / (double)i;
    wrRatio = wrRatio * pick;
    if ((wrRatio > 0) && (wrRatio < 1))
    {
        wrRatio = 1.0;
    }
    int wrLength = (int)(wrRatio + 0.5);

    if (wrLength > pick / 2)
    {
        wrLength = pick / 2;
    }


    double wrGap = players[2][0].score - players[2][wrLength].score;
    if (wrRatio == 0)
    {
        wrGap = (players[2][0].score - players[2][1].score) / 2;
    }

    if (wr >= 3)
    {
        if (chosen.size() < 13)
        {
            wrGap *= 0.1;
        }
    }
    if (wr >= 5)
    {
        wrGap = -1;
    }
    if (wrGap > largestGap)
    {
        largestGap = wrGap;
        largestPos = 2;
    }


    //te
    double teRatio = (double)teNum / (double)i;
    teRatio = teRatio * pick;
    if ((teRatio > 0) && (teRatio < 1))
    {
        teRatio = 1.0;
    }
    int teLength = (int)(teRatio + 0.5);

    double teGap = players[3][0].score - players[3][teLength].score;
    if (teRatio == 0)
    {
        teGap = (players[3][0].score - players[3][1].score) / 2;
    }
    if (te >= 1)
    {
        if (chosen.size() < 13)
        {
            teGap *= 0.1;
        }
    }
    if (te >= 2)
    {
        teGap = -1;
    }
    if (teGap > largestGap)
    {
        largestGap = teGap;
        largestPos = 3;
    }

    //dst
    double dstRatio = (double)dstNum / (double)i;
    dstRatio = dstRatio * pick;
    if ((dstRatio > 0) && (dstRatio < 1))
    {
        dstRatio = 1.0;
    }
    int dstLength = (int)(dstRatio + 0.5);

    double dstGap = players[4][0].score - players[4][dstLength].score;
    if (dstRatio == 0)
    {
        dstGap = (players[4][0].score - players[4][1].score) / 2;
    }
    if (dst >= 1)
    {
        dstGap = -1;
    }
    if ((dstGap > largestGap) && (chosen.size() >= 13))
    {
        largestGap = dstGap;
        largestPos = 4;
    }


    //k
    double kRatio = (double)kNum / (double)i;
    kRatio = kRatio * pick;
    if ((kRatio > 0) && (kRatio < 1))
    {
        kRatio = 1.0;
    }
    int kLength = (int)(kRatio + 0.5);

    double kGap = players[5][0].score - players[5][kLength].score;
    if (kRatio == 0)
    {
        kGap = (players[5][0].score - players[5][1].score) / 2;
    }
    if (k >= 1)
    {
        kGap = -1;
    }
    if ((kGap > largestGap) && (chosen.size() >= 14))
    {
        largestGap = kGap;
        largestPos = 5;
    }

    int byeFactor = 0;

    if ((qb == 1) && (largestPos == 0))
    {
        int pickedBye;
        for (TileStack ts : chosen)
        {
            if (ts.pos == "QB")
            {
                pickedBye = ts.bye;
            }
        }
        while (players[largestPos][byeFactor].bye == pickedBye)
        {
            byeFactor++;
        }
    }

    if ((te == 1) && (largestPos == 3))
    {
        int pickedBye;
        for (TileStack ts : chosen)
        {
            if (ts.pos == "TE")
            {
                pickedBye = ts.bye;
            }
        }
        while (players[largestPos][byeFactor].bye == pickedBye)
        {
            byeFactor++;
        }
    }

    chosen.add(players[largestPos][byeFactor]);

    cout << players[largestPos][byeFactor].pos << " " << players[largestPos][byeFactor].name << endl;

    players[largestPos].remove(byeFactor);

    if (largestPos == 0)
    {
        qb++;
    }
    if (largestPos == 1)
    {
        rb++;
    }
    if (largestPos == 2)
    {
        wr++;
    }
    if (largestPos == 3)
    {
        te++;
    }
    if (largestPos == 4)
    {
        dst++;
    }
    if (largestPos == 5)
    {
        k++;
    }



}
