#include "WaveFuncs.h"
#include "Console.h"
using namespace std;



int main()
{
    Console console("Hello world");

    //BorderDraw(20, 10, BorderSingle);

    

    Cell start, finish;

    Map map = MapReadFile("map.txt", start, finish);
    MapConsole(map);

    bool isFinish{ true };

    Fronts fronts;
    bool frontCurr{ false };
    int frontNumber{ 1 };

    fronts[frontCurr].push_back(start);
    bool isBreak{ false };
   

    while (true)
    {
        fronts[!frontCurr].clear();
        for (int c = 0; c < fronts[frontCurr].size(); c++)
        {
            int crow = fronts[frontCurr][c].row;
            int ccol = fronts[frontCurr][c].col;
            for (int d = 0; d < diff.size(); d++)
            {
                int drow = crow + diff[d].row;
                int dcol = ccol + diff[d].col;
                if ((Field)map[drow][dcol] == Field::Finish ||
                    (Field)map[drow][dcol] == Field::Space)
                {
                    fronts[!frontCurr].push_back({drow, dcol});
                    if ((Field)map[drow][dcol] == Field::Finish)
                    {
                        map[drow][dcol] = frontNumber;
                        isBreak = true; break;
                    }
                    map[drow][dcol] = frontNumber;
                }
            }
            if (isBreak) break;
        }
        if (isBreak) break;
        if (fronts[!frontCurr].size() == 0)
        {
            isFinish = false;
            break;
        }
        frontCurr = !frontCurr;
        frontNumber++;
    }

    MapConsole(map);
    cout << "front number " << frontNumber << "\n";
    if (!isFinish)
    {
        cout << "\nmap is wrong - way to finish not create\n";
        return 0;
    }

    Way way;
    way.push_back(finish);
    while (true)
    {
        int crow = way[way.size() - 1].row;
        int ccol = way[way.size() - 1].col;
        for (int d = 0; d < diff.size(); d++)
        {
            int drow = crow + diff[d].row;
            int dcol = ccol + diff[d].col;
            if (map[drow][dcol] == frontNumber - 1)
            {
                way.push_back({ drow, dcol });
                break;
            }
        }
        if (frontNumber - 1 == 0)
            break;
        frontNumber--;
    }
    
    for_each(way.rbegin(), way.rend(), [](Cell item) 
        { 
            cout << "[" << item.row << "," << item.col << "] "; 
        });

    cout << "\n";
    WayConsole(map, way);



    return 0;
}
