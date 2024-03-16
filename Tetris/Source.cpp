#include <iostream>
#include <vector>
#include <windows.h>
#include <cassert>

using namespace std;

const int ROW = 22;
const int COLUMN = 24;

struct Point
{
public:
	int x;
	int y;

	Point()
	{
		this->x = 0;
		this->y = 0;
	}

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

struct Block
{
public:
	Point leftPoint;
	Point rightPoint;

	Block()
	{
		leftPoint = Point();
		rightPoint = Point();
	}

	Block(Point startPoint)
	{
		leftPoint = Point(startPoint.x, startPoint.y);
		rightPoint = Point(startPoint.x + 1, startPoint.y);
	}
};

class OMino
{
private:
	Block blocks[4];

public:
	OMino(Point startPoint)
	{
		Point p1 = Point(startPoint.x + 0, startPoint.y + 0);
		Point p2 = Point(startPoint.x + 2, startPoint.y + 0);
		Point p3 = Point(startPoint.x + 0, startPoint.y + 1);
		Point p4 = Point(startPoint.x + 2, startPoint.y + 1);

		blocks[0] = Block(p1);
		blocks[1] = Block(p2);
		blocks[2] = Block(p3);
		blocks[3] = Block(p4);
	}

	const Block* GetBlocks()
	{
		return blocks;
	}
};


int main()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);

	vector<vector<char>> grid
	{
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> { '<', '!', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '!', '>' },
		vector<char> {' ', ' ', '\\', '/', '\\', '/', '\\', '/', '\\', '/', '\\', '/', '\\', '/', '\\', '/', '\\', '/', '\\', '/', '\\', '/', ' ', ' ' }
	};

	Point startPoint = Point(4, 1);
	OMino oMino = OMino(startPoint);

	const Block* blocks = oMino.GetBlocks();

	for (int i = 0; i < 4; i++)
	{
		grid[blocks[i].leftPoint.y][blocks[i].leftPoint.x] = '[';
		grid[blocks[i].rightPoint.y][blocks[i].rightPoint.x] = ']';
	}


	while (true)
	{
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COLUMN; j++)
			{
				cout << grid[i][j];
			}

			cout << "\n";
		}

		cout << "\033[H";
	}
}
