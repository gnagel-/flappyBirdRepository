#include "pipe.h";

Pipe::Pipe(int x, int y, sf::Sprite spr){
	xPos = x;
	startX = x;
	yPos = y;
	startY = y;
	pipeWidth = 28 * 4.1;
	sprite = spr;
}

void Pipe::setPosition(int x, int y){
	xPos = x;
	yPos = y;
}
sf::Vector2f Pipe::getPosition(){
	return sf::Vector2f(xPos, yPos);
}
float Pipe::getStartX(){
	return startX;
}
float Pipe::getStartY(){
	return startY;
}

sf::Sprite Pipe::getSprite(){
	return sprite;
}

bool Pipe::passScore(float birdX){
	if (birdX > (xPos + pipeWidth)){
		return true;
	}
	else return false;
}

float Pipe::getPipeWidth(){
	return pipeWidth;
}