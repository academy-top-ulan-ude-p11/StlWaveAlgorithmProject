#include "WaveFuncs.h"

using namespace std;




void BorderDraw(int width, int height, const int* border)
{
    cout << (char)border[(int)TableIndex::TopLeft];
    cout << (char)border[(int)TableIndex::Horizotal];
    for (int i = 0; i < width - 2; i++)
        cout << (char)border[(int)TableIndex::Horizotal]
        << (char)border[(int)TableIndex::Horizotal];
    cout << (char)border[(int)TableIndex::Horizotal];
    cout << (char)border[(int)TableIndex::TopRight] << "\n";

    for (int i = 0; i < height - 2; i++)
    {
        cout << (char)border[(int)TableIndex::Vertical] << " ";
        for (int j = 0; j < width - 2; j++)
            cout << "  ";
        cout << " " << (char)border[(int)TableIndex::Vertical] << "\n";
    }

    cout << (char)border[(int)TableIndex::BottomLeft];
    cout << (char)border[(int)TableIndex::Horizotal];
    for (int i = 0; i < width - 2; i++)
        cout << (char)border[(int)TableIndex::Horizotal]
        << (char)border[(int)TableIndex::Horizotal];
    cout << (char)border[(int)TableIndex::Horizotal];
    cout << (char)border[(int)TableIndex::BottomRight] << "\n";
}



Map MapReadFile(string path, Cell& start, Cell& finish)
{
    Map map;

    fstream fileMap;
    fileMap.open(path, ios::in);

    int sizeStr = 1024;
    char* str = new char[sizeStr] {};

    int row{};
    while (!fileMap.eof())
    {
        map.push_back(vector<int>());
        fileMap.getline(str, sizeStr);

        //cout << strlen(str) << "\n";
        for (int col = 0; col < strlen(str); col++)
        {
            Field value = Field::Space;
            switch (str[col])
            {
            case '#': value = Field::Wall; break;
            case 's':
            case 'S': value = Field::Start; 
                      start = Cell{ row, col };
                      break;
            case 'f':
            case 'F': value = Field::Finish; 
                      finish = Cell{ row, col }; 
                      break;
            case ' ': value = Field::Space; break;
            default:
                break;
            }
            map[row].push_back((int)value);
        }
        row++;
    }
    fileMap.close();

    return map;
}

void MapConsole(Map map)
{
    string symbol;
    for (int row = 0; row < map.size(); row++)
    {
        for (int col = 0; col < map[0].size(); col++)
        {
            symbol = "";
            switch ((Field)map[row][col])
            {
            case Field::Start: symbol = "S";
                break;
            case Field::Finish: symbol = "F";
                break;
            case Field::Space: symbol = " ";
                break;
            case Field::Wall: symbol.append(string(2, BgNormal));
                break;
            default:
                symbol = to_string(map[row][col]);
                break;
            }
            cout << setw(2) << symbol;
        }
        cout << "\n";
    }
}

void WayConsole(Map map, Way way)
{

}
