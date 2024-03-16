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
	Point leftP;
	Point rightP;

	Block()
	{
		leftP = Point();
		rightP = Point();
	}

	Block(Point startPoint)
	{
		leftP = Point(startPoint.x, startPoint.y);
		rightP = Point(startPoint.x + 1, startPoint.y);
	}

	Point GetLeftPoint()
	{
		return this->leftP;
	}

	Point GetRightPoint()
	{
		return this->rightP;
	}
};

enum class EMinoType
{
	None,
	IMino,
	OMino,
	TMino,
	JMino,
	LMino,
	SMino,
	ZMino
};

class Mino abstract
{
protected:
	EMinoType minoType;
	bool isFix;
	std::vector<Block> blocks;

public:
	virtual const std::vector<Block>& GetBlocks() const = 0;
};

class IMino : public Mino
{
private:
	bool isFix;
	std::vector<Block> blocks;

public:
	IMino(Point startPoint) : isFix(false), blocks(4)
	{
		minoType = EMinoType::IMino;
		Point p1 = Point(startPoint.x + 0, startPoint.y + 0);
		Point p2 = Point(startPoint.x + 2, startPoint.y + 0);
		Point p3 = Point(startPoint.x + 4, startPoint.y + 0);
		Point p4 = Point(startPoint.x + 6, startPoint.y + 0);

		blocks.push_back(Block(p1));
		blocks.push_back(Block(p2));
		blocks.push_back(Block(p3));
		blocks.push_back(Block(p4));
	}

	const std::vector<Block>& GetBlocks() const override
	{
		return blocks;
	}
};

class OMino : public Mino
{
private:
	bool isFix;
	std::vector<Block> blocks;

public:
	OMino(Point startPoint) : isFix(false), blocks(4)
	{
		minoType = EMinoType::OMino;
		Point p1 = Point(startPoint.x + 0, startPoint.y + 0);
		Point p2 = Point(startPoint.x + 2, startPoint.y + 0);
		Point p3 = Point(startPoint.x + 0, startPoint.y + 1);
		Point p4 = Point(startPoint.x + 2, startPoint.y + 1);

		blocks.push_back(Block(p1));
		blocks.push_back(Block(p2));
		blocks.push_back(Block(p3));
		blocks.push_back(Block(p4));
	}

	const std::vector<Block>& GetBlocks() const override
	{
		return blocks;
	}
};

class TMino : public Mino
{
private:
	bool isFix;
	std::vector<Block> blocks;

public:
	TMino(Point startPoint) : isFix(false), blocks(4)
	{
		minoType = EMinoType::TMino;
		Point p1 = Point(startPoint.x + 0, startPoint.y + 0);
		Point p2 = Point(startPoint.x + 2, startPoint.y + 0);
		Point p3 = Point(startPoint.x + 4, startPoint.y + 0);
		Point p4 = Point(startPoint.x + 2, startPoint.y + 1);

		blocks.push_back(Block(p1));
		blocks.push_back(Block(p2));
		blocks.push_back(Block(p3));
		blocks.push_back(Block(p4));
	}

	const std::vector<Block>& GetBlocks() const override
	{
		return blocks;
	}
};

class JMino : public Mino
{
private:
	bool isFix;
	std::vector<Block> blocks;

public:
	JMino(Point startPoint) : isFix(false), blocks(4)
	{
		minoType = EMinoType::JMino;
		Point p1 = Point(startPoint.x + 0, startPoint.y + 0);
		Point p2 = Point(startPoint.x + 2, startPoint.y + 0);
		Point p3 = Point(startPoint.x + 4, startPoint.y + 0);
		Point p4 = Point(startPoint.x + 4, startPoint.y + 1);

		blocks.push_back(Block(p1));
		blocks.push_back(Block(p2));
		blocks.push_back(Block(p3));
		blocks.push_back(Block(p4));
	}

	const std::vector<Block>& GetBlocks() const override
	{
		return blocks;
	}
};

class LMino : public Mino
{
private:
	bool isFix;
	std::vector<Block> blocks;

public:
	LMino(Point startPoint) : isFix(false), blocks(4)
	{
		minoType = EMinoType::LMino;
		Point p1 = Point(startPoint.x + 0, startPoint.y + 0);
		Point p2 = Point(startPoint.x + 2, startPoint.y + 0);
		Point p3 = Point(startPoint.x + 4, startPoint.y + 0);
		Point p4 = Point(startPoint.x + 0, startPoint.y + 1);

		blocks.push_back(Block(p1));
		blocks.push_back(Block(p2));
		blocks.push_back(Block(p3));
		blocks.push_back(Block(p4));
	}

	const std::vector<Block>& GetBlocks() const override
	{
		return blocks;
	}
};

class SMino : public Mino
{
private:
	bool isFix;
	std::vector<Block> blocks;

public:
	SMino(Point startPoint) : isFix(false), blocks(4)
	{
		minoType = EMinoType::SMino;
		Point p1 = Point(startPoint.x + 2, startPoint.y + 0);
		Point p2 = Point(startPoint.x + 4, startPoint.y + 0);
		Point p3 = Point(startPoint.x + 0, startPoint.y + 1);
		Point p4 = Point(startPoint.x + 2, startPoint.y + 1);

		blocks.push_back(Block(p1));
		blocks.push_back(Block(p2));
		blocks.push_back(Block(p3));
		blocks.push_back(Block(p4));
	}

	const std::vector<Block>& GetBlocks() const override
	{
		return blocks;
	}
};

class ZMino : public Mino
{
private:
	bool isFix;
	std::vector<Block> blocks;

public:
	ZMino(Point startPoint) : isFix(false), blocks(4)
	{
		minoType = EMinoType::ZMino;
		Point p1 = Point(startPoint.x + 0, startPoint.y + 0);
		Point p2 = Point(startPoint.x + 2, startPoint.y + 0);
		Point p3 = Point(startPoint.x + 2, startPoint.y + 1);
		Point p4 = Point(startPoint.x + 4, startPoint.y + 1);

		blocks.push_back(Block(p1));
		blocks.push_back(Block(p2));
		blocks.push_back(Block(p3));
		blocks.push_back(Block(p4));
	}

	const std::vector<Block>& GetBlocks() const override
	{
		return blocks;
	}
};

Mino* GenerateMino(EMinoType minoType, Point startPoint);

void DrawMino(vector<vector<char>>& grid, const Mino* mino);

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

	Mino* mino = GenerateMino(EMinoType::IMino, Point(4, 5));
	DrawMino(grid, mino);

	// DrawMino(grid, Point(4, 1));
	// DrawMino(grid, Point(9, 4));
	// DrawMino(grid, Point(3, 9));

	// Mino에 대한 배열을 만들고 이것들이 N초마다 아래로 내려가도록 해야 한다. (단 mino에도 상태가 있겠군)

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


Mino* GenerateMino(EMinoType minoType, Point startPoint)
{
	switch (minoType)
	{
	case EMinoType::None:
		break;
	case EMinoType::IMino:
		return new IMino(startPoint);
	case EMinoType::OMino:
		return new OMino(startPoint);
	case EMinoType::TMino:
		return new TMino(startPoint);
	case EMinoType::JMino:
		return new JMino(startPoint);
	case EMinoType::LMino:
		return new LMino(startPoint);
	case EMinoType::SMino:
		return new SMino(startPoint);
	case EMinoType::ZMino:
		return new ZMino(startPoint);
	default:
		break;
	}

	return nullptr;
}


void DrawMino(vector<vector<char>>& grid, const Mino* mino)
{
	const vector<Block>& blocks = mino->GetBlocks();

	for (auto block : blocks)
	{
		const Point& lp = block.GetLeftPoint();
		const Point& rp = block.GetRightPoint();

		grid[lp.y][lp.x] = '[';
		grid[rp.y][rp.x] = ']';
	}
}