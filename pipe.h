#include <SFML/Graphics.hpp>

class Pipe{
private:
	int xPos;
	int yPos;
	float startX;
	float startY;
	float pipeWidth;
	sf::Sprite sprite;

public:
	Pipe(int x, int y, sf::Sprite spr);
	void setPosition(int x, int y);
	sf::Vector2f getPosition();
	float Pipe::getStartX();
	float Pipe::getStartY();
	sf::Sprite getSprite();
	bool Pipe::passScore(float birdX);
	float Pipe::getPipeWidth();
};