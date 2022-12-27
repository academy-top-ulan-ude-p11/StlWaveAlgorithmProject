#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <iomanip>
#include <string>

#pragma once

struct Cell
{
    int row;
    int col;
    /*friend ostream& operator<<(ostream& out, Cell& cell)
    {
        out << "[" << cell.row << "," << cell.col << "]";
        return out;
    }*/
};

using namespace std;

typedef vector<vector<int>> Map;
typedef vector<Cell> Way;
typedef array<vector<Cell>, 2> Fronts;


enum class Field
{
    Start = 0,
    Finish = -2,
    Space = -1,
    Wall = -3
};

enum class TableIndex
{
    TopLeft, TopCenter, TopRight,
    MiddleLeft, MiddleCenter, MiddleRight,
    BottomLeft, BottomCenter, BottomRight,
    Horizotal, Vertical
};

const int BorderSingle[]{ 218, 194, 191, 195, 197, 180, 192, 193, 217, 196, 179 };
const int BorderDouble[]{ 201, 203, 187, 204, 206, 185, 200, 202, 188, 205, 186 };
const int BgLight{ 176 };
const int BgNormal{ 177 };
const int BgDark{ 178 };

const vector<Cell> diff{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void BorderDraw(int width, int height, const int* border);

Map MapReadFile(string path, Cell& start, Cell& finish);

void MapConsole(Map map);

void WayConsole(Map map, Way way);