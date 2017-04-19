// This is the .h file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#ifndef _tilestack_h
#define _tilestack_h

#include <iostream>
#include <string>
#include "gobjects.h"
#include "gwindow.h"
#include "TileNode.h"
#include "stack.h"
using namespace std;

class TileStack {
public:
    string name;
    string pos;
    string team;
    int score;
    int bye;
    TileStack();
    TileStack(string name0, string pos0, string team0, int score0);
    void setBye();
    ~TileStack();

private:
};

#endif
