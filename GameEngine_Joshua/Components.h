#pragma once
#include "Engine.h"

#include <fstream>
#include "Tile.h"
#include "Interface/States.h"

struct Transform
{
public:
	ECS_DECLARE_TYPE;
	float xPos, yPos, rotationAngle, xSpeed, ySpeed, xSpeedMod, ySpeedMod, rotationSpeed;
	bool bColliding = false;

	Transform(float newX, float newY, float xSpeed = 0.0f, float ySpeed = 0.0f, float rotationAngle = 0.0f, float rotationSpeed = 0.0f) : xPos(newX), yPos(newY)
	{
		this->xSpeed = newX;
		this->ySpeed = newY;
		this->xSpeedMod = xSpeed;
		this->ySpeedMod = ySpeed;
		this->rotationAngle = rotationAngle;
		this->rotationSpeed = rotationSpeed;
	}
	void Move()
	{
		if (bColliding == false)
		{
			this->xPos += xSpeed;
			this->yPos += ySpeed;
		}
	}
};
ECS_DEFINE_TYPE(Transform);

struct Sprite2D
{
public:
	ECS_DECLARE_TYPE;
	sf::Sprite picture;
	std::string texture;
	int width, height;

	Sprite2D(std::string filepath)
	{
		this->texture = filepath;
	}
};
ECS_DEFINE_TYPE(Sprite2D);

struct Animator
{
	ECS_DECLARE_TYPE;
public:
	int spriteWidth;
	int spriteHeight;
	int currentColumn;
	int currentRow;
	int totalColumns;
	int totalRows;
	float currentTime, nextFrameTime;
	bool bFacingRight;

	Animator(int newWidth, int newHeight, float timeBetweenFrames, int columns, int rows)
	{
		this->spriteWidth = newWidth;
		this->spriteHeight = newHeight;
		this->currentColumn = 0;
		this->currentRow = 0;
		this->totalColumns = columns;
		this->totalRows = rows;
		this->nextFrameTime = timeBetweenFrames;
		this->currentTime = 0;
		this->bFacingRight = true;

	}
};
ECS_DEFINE_TYPE(Animator);



struct InputController
{
public:
	ECS_DECLARE_TYPE;
	bool bInputActive;
	bool w, a, s, d, left, right, up, down, space;
	InputController()
	{
		std::memset(this, false, sizeof(InputController));
		bInputActive = true;
	}
};
ECS_DEFINE_TYPE(InputController);

struct BoxCollider
{
public:
	ECS_DECLARE_TYPE;
	int leftEdge;
	int rightEdge;
	int bottomEdge;
	int topEdge;

	BoxCollider()
	{
		std::memset(this, 0, sizeof(BoxCollider));

	}
	void Update(int x, int y, int width, int height)
	{
		this->leftEdge = x;
		this->rightEdge = x + width;
		this->bottomEdge = y + height;
		this->topEdge = y;
	}
};
ECS_DEFINE_TYPE(BoxCollider);

struct TileMap
{
public:
	ECS_DECLARE_TYPE;
	float gridSizeF;
	uint32_t gridSizeU;
	uint32_t layers;
	sf::Vector2u maxSize;
	sf::RectangleShape collisionBox;
	std::vector < std::vector < std::vector <Tile*>>> map;

	TileMap()
	{
		this->gridSizeF = 50.0f;
		this->gridSizeU = static_cast<unsigned int> (this->gridSizeF);
		this->maxSize.x = 20;
		this->maxSize.y = 20;
		this->layers = 1;
		this->map.resize(this->maxSize.x);

		for (size_t x = 0; x < this->maxSize.x; x++)
		{
			this->map.push_back(std::vector<std::vector<Tile*>>());

			for (size_t y = 0; y < this->maxSize.y; y++)
			{
				this->map[x].resize(this->maxSize.y);
				this->map[x].push_back(std::vector<Tile*>());

				for (size_t z = 0; z < this->layers; z++)
				{
					this->map[x][y].resize(this->layers);
					this->map[x][y].push_back(nullptr);
				}
			}
		}
		this->collisionBox.setSize(sf::Vector2f(this->gridSizeF, this->gridSizeF));
		this->collisionBox.setFillColor(sf::Color::Red);
		this->collisionBox.setOutlineColor(sf::Color::Green);
		this->collisionBox.setOutlineThickness(-1.0f);
	}

	~TileMap()
	{
		this->Clear();
	}

	void AddTile(const uint32_t x, const uint32_t y, const uint32_t z, bool bHasCollision)
	{
		if (States::getPausedState() == false)
		{
			printf("%d, %d, %d \n", maxSize.x, maxSize.y, layers);
			if (x < this->maxSize.x && x >= 0 &&
				y < this->maxSize.y && y >= 0 &&
				z < this->layers && z >= 0)
			{
				if (this->map[x][y][z] == nullptr)
				{
					this->map[x][y][z] = new Tile(x, y, this->gridSizeF, bHasCollision);
					std::cout << "Tile added." << std::endl;

				}
			}
		}
	}

	void Clear()
	{
		for (size_t x = 0; x < this->maxSize.x; x++)
		{


			for (size_t y = 0; y < this->maxSize.y; y++)
			{


				for (size_t z = 0; z < this->layers; z++)
				{
					delete this->map[x][y][z];
					this->map[x][y][z] = NULL;
				}
				this->map[x][y].clear();
			}
			this->map[x].clear();
		}
		this->map.clear();

	}

	void SaveTileMap(std::string fileName)
	{
		std::ofstream saveFile;
		saveFile.open(fileName);
		if (saveFile.is_open() == true)
		{
			saveFile << maxSize.x << " " << maxSize.y << "\n" << gridSizeF << "\n" << layers << "\n";

			for (size_t x = 0; x < this->maxSize.x; x++)
			{


				for (size_t y = 0; y < this->maxSize.y; y++)
				{


					for (size_t z = 0; z < this->layers; z++)
					{
						if (this->map[x][y][z] != nullptr)
						{
							saveFile << x << " " << y << " " << z << " " << this->map[x][y][z]->ToString() << " " << "\n";
						}
					}

				}

			}
		}
		else
		{
			std::cerr << "Error.. Tile Map could not save to file " << fileName << std::endl;
		}
		saveFile.close();
	}

	void LoadTileMap(std::string fileName)
	{
		std::printf("Loading Tile Map.. \n");
		std::ifstream loadFile;
		loadFile.open(fileName);
		if (loadFile.is_open() == true)
		{
			loadFile >> maxSize.x >> maxSize.y >> gridSizeF >> layers;
			gridSizeU = static_cast<uint32_t>(gridSizeF);
			Clear();
			map.resize(maxSize.x, std::vector<std::vector<Tile*>>());

			for (size_t x = 0; x < this->maxSize.x; x++)
			{


				for (size_t y = 0; y < this->maxSize.y; y++)
				{
					map.at(x).resize(maxSize.y, std::vector<Tile*>());

					for (size_t z = 0; z < this->layers; z++)
					{
						this->map.at(x).at(y).resize(layers, nullptr);
					}
				}
			}
			int tx, ty, tz;
			bool bColliding = false;
			while (loadFile >> tx >> ty >> tz >> bColliding)
			{
				std::printf("Reading %d, %d, %d\n", tx, ty, tz);
				map.at(tx).at(ty).at(tz) = new Tile(tx, ty, this->gridSizeF, bColliding);
			}

		}
		else
		{
			std::cerr << "Error Tile Map could not load from file " << fileName << std::endl;
		}
		loadFile.close();
	}
};
ECS_DEFINE_TYPE(TileMap);
