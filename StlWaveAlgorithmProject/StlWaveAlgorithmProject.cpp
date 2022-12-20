#include <iostream>

using namespace std;

enum TableIndex
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

void BorderDraw(int width, int height, const int* border)
{
    cout << (char)border[TopLeft];
    for (int i = 0; i < width - 2; i++)
        cout << (char)border[Horizotal];
    cout << (char)border[TopRight] << "\n";

    for (int i = 0; i < height - 2; i++)
    {
        cout << (char)border[Vertical];
        for (int j = 0; j < width - 2; j++)
            cout << " ";
        cout << (char)border[Vertical] << "\n";
    }

    cout << (char)border[BottomLeft];
    for (int i = 0; i < width - 2; i++)
        cout << (char)border[Horizotal];
    cout << (char)border[BottomRight] << "\n";
}


int main()
{
    BorderDraw(10, 6, BorderDouble);
    cout << (char)BgLight << " " << (char)BgNormal << " " << (char)BgDark << "\n";
}
