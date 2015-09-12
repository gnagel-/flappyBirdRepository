#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>

#include "pipe.h";

int main(){
	//
	int gameWidth = 600;
	int gameHeight = 800;
	sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "SFML Application");
	//view
	sf::View view1(sf::FloatRect(0, 0, gameWidth, gameHeight));
	window.setView(view1);
	

	//sprite sheet
	sf::Texture spriteSheet;
	spriteSheet.loadFromFile("fbirdsprites.png");

	//background
	sf::Sprite background;
	background.setTexture(spriteSheet);
	background.setTextureRect(sf::IntRect(0, 0, 143, 256));
	background.scale(sf::Vector2f(4.2f, 3.2f));

	//title
	sf::Sprite title;
	title.setTexture(spriteSheet);
	title.setTextureRect(sf::IntRect(349, 90, 91, 26));
	title.setPosition(100, 150);
	title.scale(sf::Vector2f(4.2f, 4.2f));
	//play button
	sf::Sprite playButton;
	playButton.setTexture(spriteSheet);
	playButton.setTextureRect(sf::IntRect(352, 118, 55, 29));
	playButton.setPosition(200, 400);
	playButton.scale(sf::Vector2f(3.2f, 3.2f));
	sf::FloatRect buttonBox = playButton.getGlobalBounds();


	//get ready
	sf::Sprite ready;
	ready.setTexture(spriteSheet);
	ready.setTextureRect(sf::IntRect(293, 58, 95, 26));
	ready.setPosition(100, 150);
	ready.scale(sf::Vector2f(4.2f, 3.2f));
	//instructions
	sf::Sprite instruct;
	instruct.setTexture(spriteSheet);
	instruct.setTextureRect(sf::IntRect(290, 89, 59, 51));
	instruct.setPosition(190, 300);
	instruct.scale(sf::Vector2f(3.7f, 3.7f));

	//game over
	sf::Sprite gameOver;
	gameOver.setTexture(spriteSheet);
	gameOver.setTextureRect(sf::IntRect(394, 58, 97, 26));
	gameOver.setPosition(100, 150);
	gameOver.scale(sf::Vector2f(4.2f, 3.2f));

	//bird sprite
	sf::Sprite bird;
	bird.setTexture(spriteSheet);
	bird.setTextureRect(sf::IntRect(2, 490, 18, 13));
	bird.scale(sf::Vector2f(3.1f, 3.1f));
	bird.setPosition(140, 340);
	sf::FloatRect birdBox = bird.getGlobalBounds();

	//pipe1, top
	sf::Sprite pipe1;
	pipe1.setTexture(spriteSheet);
	pipe1.setTextureRect(sf::IntRect(55, 320, 28, 164));
	pipe1.scale(sf::Vector2f(4.1f, 4.1f));
	pipe1.setPosition(500, -390);
	sf::FloatRect pipe1Box = pipe1.getGlobalBounds();

	//pipe2, bottom
	sf::Sprite pipe2;
	pipe2.setTexture(spriteSheet);
	pipe2.setTextureRect(sf::IntRect(83, 320, 28, 162));
	pipe2.scale(sf::Vector2f(4.1f, 4.1f));
	pipe2.setPosition(pipe1.getPosition().x, pipe1.getPosition().y +900);
	sf::FloatRect pipe2Box = pipe2.getGlobalBounds();

	//pipe1_2
	sf::Sprite pipe1_2;
	pipe1_2.setTexture(spriteSheet);
	pipe1_2.setTextureRect(sf::IntRect(55, 320, 28, 164));
	pipe1_2.scale(sf::Vector2f(4.1f, 4.1f));
	pipe1_2.setPosition(900, -390);
	sf::FloatRect pipe1_2Box = pipe1_2.getGlobalBounds();
	//pipe2_2
	sf::Sprite pipe2_2;
	pipe2_2.setTexture(spriteSheet);
	pipe2_2.setTextureRect(sf::IntRect(83, 320, 28, 162));
	pipe2_2.scale(sf::Vector2f(4.1f, 4.1f));
	pipe2_2.setPosition(pipe1_2.getPosition().x, pipe1_2.getPosition().y + 900);
	sf::FloatRect pipe2_2Box = pipe2_2.getGlobalBounds();

	//pipe1_3
	sf::Sprite pipe1_3;
	pipe1_3.setTexture(spriteSheet);
	pipe1_3.setTextureRect(sf::IntRect(55, 320, 28, 164));
	pipe1_3.scale(sf::Vector2f(4.1f, 4.1f));
	pipe1_3.setPosition(1300, -390);
	sf::FloatRect pipe1_3Box = pipe1_3.getGlobalBounds();
	//pipe2_3
	sf::Sprite pipe2_3;
	pipe2_3.setTexture(spriteSheet);
	pipe2_3.setTextureRect(sf::IntRect(83, 320, 28, 162));
	pipe2_3.scale(sf::Vector2f(4.1f, 4.1f));
	pipe2_3.setPosition(pipe1_3.getPosition().x, pipe1_3.getPosition().y + 900);
	sf::FloatRect pipe2_3Box = pipe2_3.getGlobalBounds();

	Pipe firstPipeT = Pipe(pipe1.getPosition().x, pipe1.getPosition().y, pipe1);
	Pipe firstPipeB = Pipe(pipe2.getPosition().x, pipe2.getPosition().y, pipe2);
	Pipe secondPipeT = Pipe(pipe1_2.getPosition().x, pipe1_2.getPosition().y, pipe1_2);
	Pipe secondPipeB = Pipe(pipe2_2.getPosition().x, pipe2_2.getPosition().y, pipe2_2);
	Pipe thirdPipeT = Pipe(pipe1_3.getPosition().x, pipe1_3.getPosition().y, pipe1_3);
	Pipe thirdPipeB = Pipe(pipe2_3.getPosition().x, pipe2_3.getPosition().y, pipe2_3);
	Pipe pipeArray[6] = { firstPipeT,firstPipeB, secondPipeT,secondPipeB, thirdPipeT,thirdPipeB };
	int pipeArrayLength = 6;	

	//ground
	sf::Sprite ground1;
	ground1.setTexture(spriteSheet);
	ground1.setTextureRect(sf::IntRect(291, 0, 166, 55));
	ground1.scale(sf::Vector2f(4.1f, 2.1f));
	ground1.setPosition(0, gameHeight-55);
	sf::FloatRect g1Box = ground1.getGlobalBounds();
	float groundLength = (166 * 3.9);

	sf::Sprite ground2;
	ground2.setTexture(spriteSheet);
	ground2.setTextureRect(sf::IntRect(291, 0, 166, 55));
	ground2.scale(sf::Vector2f(4.1f, 2.1f));
	ground2.setPosition(groundLength, gameHeight - 55);
	sf::FloatRect g2Box = ground2.getGlobalBounds();

	bool g1moved = false; //keep ground moving correctly
	

	//variables
	float scrollSpeed = 0.2; //0.09;
	int screen = 0; //0 title, 1 instructions, 2 game over
	bool playing = false;
	int score = 0;
	float groundCount= 0;
	float gravity = 0.4;
	float flap = 70.0;
	bool flapped = false;

	bool checkScore = true;
	int pipeCount = 0;

	int pipeChangeCount = 0;
	int pipeMovements[4] = {700,100, 1000,650};
	int pipePosLength = 4;
	

	//text
	sf::Font font;
	if (!font.loadFromFile("fbirdfont.ttf")) printf("unable to load font");

	sf::Text scoreDisplay;
	scoreDisplay.setFont(font);
	scoreDisplay.setCharacterSize(70);
	scoreDisplay.setPosition(gameWidth / 2, 70);
	scoreDisplay.setColor(sf::Color::White);
	//scoreDisplay.setString("Score: " + (std::to_string(score)));
	scoreDisplay.setString(std::to_string(score));


	while (window.isOpen()){

		sf::Event event;
		while (window.pollEvent(event)){

			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed){
				if (!playing){
					if (screen == 0){//move from title to instructions
						//screen += 1;
						buttonBox = playButton.getGlobalBounds();
						float mouseX = sf::Mouse::getPosition(window).x;
						float mouseY = sf::Mouse::getPosition(window).y;
						//printf("mouseX: %f, mouseY: %f \n", mouseX, mouseY);
						if (buttonBox.contains(sf::Vector2f(mouseX, mouseY))){
							screen += 1;
						}
					}
					else if (screen == 1){//move from instructions to game
						playing = true;
					}
					else if (screen == 2){ //restart game
						//replay is an absolute mess

						//having issues with collision detection
						/*
						buttonBox = playButton.getGlobalBounds();
						float mouseX = sf::Mouse::getPosition(window).x;
						float mouseY = sf::Mouse::getPosition(window).y;
						printf("mouseX: %f, mouseY: %f \n", mouseX, mouseY);
						if (buttonBox.contains(sf::Vector2f(mouseX, mouseY))){
						*/
						score = 0;
						groundCount = 0;
						pipeCount = 0;
						view1.reset(sf::FloatRect(0, 0, gameWidth, gameHeight));
						playing = true;
						checkScore = true;

						// should be a seperate function/functions
						background.setPosition(0, 0);
						title.setPosition(100, 150);
						playButton.setPosition(200, 400);
						ready.setPosition(100, 150);
						instruct.setPosition(190, 300);
						gameOver.setPosition(100, 150);
						bird.setPosition(140, 340);
						ground1.setPosition(0, gameHeight - 55); //on replay, one ground seems to be wrongly positioned
						ground2.setPosition(groundLength, gameHeight - 55);
						scoreDisplay.setPosition(gameWidth / 2, 70);

						pipe1.setPosition(firstPipeT.getStartX(), firstPipeT.getStartY());
						firstPipeT.setPosition(firstPipeT.getStartX(), firstPipeT.getStartY());
						pipe2.setPosition(firstPipeB.getStartX(), firstPipeB.getStartY());
						firstPipeB.setPosition(firstPipeB.getStartX(), firstPipeB.getStartY());

					}
					
				}//end if !playing
				else if (playing){
					bird.move(scrollSpeed, gravity-flap);
					//printf("mouse pressed \n");
				}
			}

		}//end pollEvent loop

		
		if (playing){
			//check for collisions
			birdBox = bird.getGlobalBounds();
			g1Box = ground1.getGlobalBounds();
			g2Box = ground2.getGlobalBounds();
			pipe1Box = pipe1.getGlobalBounds();
			pipe2Box = pipe2.getGlobalBounds();
			pipe1_2Box = pipe1_2.getGlobalBounds();
			pipe2_2Box = pipe2_2.getGlobalBounds();
			pipe1_3Box = pipe1_3.getGlobalBounds();
			pipe2_3Box = pipe2_3.getGlobalBounds();
			if (birdBox.intersects(g1Box) || birdBox.intersects(g2Box) ||
				birdBox.intersects(pipe1Box) || birdBox.intersects(pipe2Box) ||
				birdBox.intersects(pipe1_2Box) || birdBox.intersects(pipe2_2Box) ||
				birdBox.intersects(pipe1_3Box) || birdBox.intersects(pipe2_3Box)){
				screen = 2; //game over
				pipeCount = 0;
				playing = false;
			}

			//update score
			//printf("\npipeCount: %d\n", pipeCount);
			Pipe currPipe = pipeArray[pipeCount];
			if (pipeCount >= 8) currPipe = firstPipeB;
			else if (pipeCount >= 6) currPipe = firstPipeT;

			float birdX = bird.getPosition().x;
			printf("birdX: %f, currPipeX: %f \n", birdX, currPipe.getPosition().x);
			if (checkScore && currPipe.passScore(birdX)){
				score++;
				pipeCount +=2;
				pipeChangeCount++;
				checkScore = false;
			}
			else if (birdX > currPipe.getPosition().x &&
				birdX < currPipe.getPosition().x + currPipe.getPipeWidth()){
				checkScore = true;
			}
			if (pipeCount > pipeArrayLength){
				pipeCount = 0;

			}
			//}//

			//move pipes, this is awful
			if (pipeChangeCount == 2){
				pipe1.setPosition(bird.getPosition().x + pipeMovements[0], pipe1.getPosition().y + pipeMovements[1]);
				firstPipeT.setPosition(pipe1.getPosition().x, pipe1.getPosition().y);
				pipeChangeCount++;
			}
			else if (pipeChangeCount == 3){
				pipe2.setPosition(bird.getPosition().x + pipeMovements[2], pipe1.getPosition().y + pipeMovements[3]);
				firstPipeB.setPosition(pipe2.getPosition().x, pipe2.getPosition().y);
				pipeChangeCount++;
			}
			
		}//end if playing 
		

//draw things
		window.clear();
		window.draw(background);

		if (playing){
			//move background and view
			view1.move(sf::Vector2f(scrollSpeed, 0));
			window.setView(view1);
			background.move(sf::Vector2f(scrollSpeed, 0));

			//move score
			scoreDisplay.move(sf::Vector2f(scrollSpeed, 0));
			//move gameOver
			gameOver.move(sf::Vector2f(scrollSpeed, 0));
			//move playButton
			playButton.move(sf::Vector2f(scrollSpeed, 0));

			//move ground
			groundCount = groundCount + scrollSpeed;
			//printf("%f \n", groundCount);
			if (groundCount > groundLength){
				if (groundCount >= 2 * groundLength) {
					ground2.move(groundLength * 2, 0);
					groundCount = 0;
					g1moved = false;
				}
				else if (!g1moved){
					ground1.move(groundLength * 2, 0);
					g1moved = true;
				}
			}

			//move bird
			bird.move(scrollSpeed, gravity);

		}//end if playing

		window.draw(pipe1);
		window.draw(pipe2);
		window.draw(pipe1_2);
		window.draw(pipe2_2);
		window.draw(pipe1_3);
		window.draw(pipe2_3);
		window.draw(ground1);
		window.draw(ground2);

		scoreDisplay.setString(std::to_string(score));
		window.draw(scoreDisplay);
		window.draw(bird);

		if (!playing){
			if (screen == 0){
				window.draw(title);
				window.draw(playButton);
			}
			else if (screen == 1){
				window.draw(ready);
				window.draw(instruct);
			}
			else if (screen == 2){
				window.draw(gameOver);
				window.draw(playButton);
			}
		}//end if !playing

		window.display();
	}//end window loop

}//end main

