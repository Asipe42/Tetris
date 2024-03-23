#include <iostream>
#include <vector>
#include <windows.h>
#include <cassert>
#include <chrono>
#include <thread>
#include <random>

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

	void Down()
	{
		this->y = y + 1;
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

	Point GetLeftPoint()
	{
		return this->leftPoint;
	}

	Point GetRightPoint()
	{
		return this->rightPoint;
	}

	void Down()
	{
		leftPoint.Down();
		rightPoint.Down();
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
	ZMino,
	EOE
};

class Mino abstract
{
protected:
	EMinoType minoType;
	bool isFix;
	std::vector<Block> blocks;

public:
	virtual const std::vector<Block>& GetBlocks() const = 0;
	virtual void Down()
	{
		for (auto& block : blocks)
		{
			block.Down();
		}
	}
};

class IMino : public Mino
{
public:
	IMino(Point startPoint)
	{
		minoType = EMinoType::IMino;
		isFix = false;
		blocks = vector<Block>(4);

		Point p1 = Point(startPoint.x + 0, startPoint.y + 0);
		Point p2 = Point(startPoint.x + 2, startPoint.y + 0);
		Point p3 = Point(startPoint.x + 4, startPoint.y + 0);
		Point p4 = Point(startPoint.x + 6, startPoint.y + 0);

		blocks[0] = Block(p1);
		blocks[1] = Block(p2);
		blocks[2] = Block(p3);
		blocks[3] = Block(p4);
	}

	const std::vector<Block>& GetBlocks() const override
	{
		return blocks;
	}
};

class OMino : public Mino
{
public:
	OMino(Point startPoint)
	{
		minoType = EMinoType::OMino;
		isFix = false;
		blocks = vector<Block>(4);

		Point p1 = Point(startPoint.x + 0, startPoint.y + 0);
		Point p2 = Point(startPoint.x + 2, startPoint.y + 0);
		Point p3 = Point(startPoint.x + 0, startPoint.y + 1);
		Point p4 = Point(startPoint.x + 2, startPoint.y + 1);

		blocks[0] = Block(p1);
		blocks[1] = Block(p2);
		blocks[2] = Block(p3);
		blocks[3] = Block(p4);
	}

	const std::vector<Block>& GetBlocks() const override
	{
		return blocks;
	}
};

class TMino : public Mino
{
public:
	TMino(Point startPoint)
	{
		minoType = EMinoType::TMino;
		isFix = false;
		blocks = vector<Block>(4);

		Point p1 = Point(startPoint.x + 0, startPoint.y + 0);
		Point p2 = Point(startPoint.x + 2, startPoint.y + 0);
		Point p3 = Point(startPoint.x + 4, startPoint.y + 0);
		Point p4 = Point(startPoint.x + 2, startPoint.y + 1);

		blocks[0] = Block(p1);
		blocks[1] = Block(p2);
		blocks[2] = Block(p3);
		blocks[3] = Block(p4);
	}

	const std::vector<Block>& GetBlocks() const override
	{
		return blocks;
	}
};

class JMino : public Mino
{
public:
	JMino(Point startPoint)
	{
		minoType = EMinoType::JMino;
		isFix = false;
		blocks = vector<Block>(4);

		Point p1 = Point(startPoint.x + 0, startPoint.y + 0);
		Point p2 = Point(startPoint.x + 2, startPoint.y + 0);
		Point p3 = Point(startPoint.x + 4, startPoint.y + 0);
		Point p4 = Point(startPoint.x + 4, startPoint.y + 1);

		blocks[0] = Block(p1);
		blocks[1] = Block(p2);
		blocks[2] = Block(p3);
		blocks[3] = Block(p4);
	}

	const std::vector<Block>& GetBlocks() const override
	{
		return blocks;
	}
};

class LMino : public Mino
{
public:
	LMino(Point startPoint)
	{
		minoType = EMinoType::LMino;
		isFix = false;
		blocks = vector<Block>(4);

		Point p1 = Point(startPoint.x + 0, startPoint.y + 0);
		Point p2 = Point(startPoint.x + 2, startPoint.y + 0);
		Point p3 = Point(startPoint.x + 4, startPoint.y + 0);
		Point p4 = Point(startPoint.x + 0, startPoint.y + 1);

		blocks[0] = Block(p1);
		blocks[1] = Block(p2);
		blocks[2] = Block(p3);
		blocks[3] = Block(p4);
	}

	const std::vector<Block>& GetBlocks() const override
	{
		return blocks;
	}
};

class SMino : public Mino
{
public:
	SMino(Point startPoint)
	{
		minoType = EMinoType::SMino;
		isFix = false;
		blocks = vector<Block>(4);

		Point p1 = Point(startPoint.x + 2, startPoint.y + 0);
		Point p2 = Point(startPoint.x + 4, startPoint.y + 0);
		Point p3 = Point(startPoint.x + 0, startPoint.y + 1);
		Point p4 = Point(startPoint.x + 2, startPoint.y + 1);

		blocks[0] = Block(p1);
		blocks[1] = Block(p2);
		blocks[2] = Block(p3);
		blocks[3] = Block(p4);
	}

	const std::vector<Block>& GetBlocks() const override
	{
		return blocks;
	}
};

class ZMino : public Mino
{
public:
	ZMino(Point startPoint)
	{
		minoType = EMinoType::ZMino;
		isFix = false;
		blocks = vector<Block>(4);

		Point p1 = Point(startPoint.x + 0, startPoint.y + 0);
		Point p2 = Point(startPoint.x + 2, startPoint.y + 0);
		Point p3 = Point(startPoint.x + 2, startPoint.y + 1);
		Point p4 = Point(startPoint.x + 4, startPoint.y + 1);

		blocks[0] = Block(p1);
		blocks[1] = Block(p2);
		blocks[2] = Block(p3);
		blocks[3] = Block(p4);
	}

	const std::vector<Block>& GetBlocks() const override
	{
		return blocks;
	}
};

void ResetGrid(vector<vector<char>>& grid);

EMinoType PickRandomMinoType();

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

	//TODO 랜덤으로 하나 골라서 생성하기

	vector<Mino*> minos;

	EMinoType ranMinoType = PickRandomMinoType();
	Mino* mino = GenerateMino(ranMinoType, Point(4, 5));
	minos.push_back(mino);

	DrawMino(grid, minos[0]);
	
	auto startTime = std::chrono::high_resolution_clock::now();
	double elapsedTime = 0.0;
	double deltaTime = 0.0;

	while (true)
	{
		auto currentTime = std::chrono::high_resolution_clock::now();
		deltaTime = std::chrono::duration<double, std::milli>(currentTime - startTime).count() / 1000.0;
		startTime = currentTime;
		elapsedTime += deltaTime;

		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COLUMN; j++)
			{
				cout << grid[i][j];
			}

			cout << "\n";
		}

		if (elapsedTime > 1)
		{
			ResetGrid(grid);

			elapsedTime = 0;
			minos[0]->Down();
			DrawMino(grid, minos[0]);
		}

		cout << "\033[H";

		std::this_thread::sleep_for(std::chrono::milliseconds(16));
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

void ResetGrid(vector<vector<char>>& grid)
{
	//TODO 너무 비효율적인 건 아닐까?
	grid = 
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
}

EMinoType PickRandomMinoType()
{
	// 난수 생성의 품질이 더 좋아야 한다면 다른 라이브러리로 대체하자
	std::random_device rd;
	std::mt19937 gen(rd());

	int start = (int)EMinoType::None + 1;
	int end = (int)EMinoType::EOE - 1;

	std::uniform_int_distribution<int> dis(start, end);
	
	int ranNum = dis(gen);
	return (EMinoType)ranNum;
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