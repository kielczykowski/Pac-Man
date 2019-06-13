#include "stdafx.h"
#include "GameMaster.h"


void GameMaster::updateScore(int&& value){
	if (value < 0) {
		if (score_ - value < 0)
			score_ = 0;
		else
			score_ += value;
	}
	else
		score_ += value;
}

void GameMaster::updateLifes(int&& value){
	if (value < 0) {
		if (lifes_ - value < 0)
			lifes_ = 0;
		else
			lifes_ += value;
	}
	else
		lifes_ += value;
}

bool GameMaster::isDead() const{
	if (lifes_ <= 0) {
		return true;
	}
	else
		return false;
}
void GameMaster::init(){
	score_ = 0;
	lifes_ = 3;

}

bool GameMaster::getPause() const{
	return pause;
}
bool GameMaster::getExit() const{
	return exit;
}

//to refactor
void GameMaster::drawUpdates(sf::RenderWindow& window) {
	sf::Text score,lifes;
	sf::RectangleShape frame;
	std::stringstream buffer,bufferxd;
	buffer << "Score: " << score_;
	score.setString(buffer.str());
	buffer.clear();
	bufferxd << "Lifes: " << lifes_;
	lifes.setString(bufferxd.str());
	
	score.setFont(font_);
	lifes.setFont(font_);
	score.setFillColor(sf::Color::Yellow);
	lifes.setFillColor(sf::Color::Yellow);
	score.setCharacterSize(MAP_PIXELS_SIZE);
	lifes.setCharacterSize(MAP_PIXELS_SIZE);
	score.setPosition(sf::Vector2f(MAP_OFFSET_X + 20 * MAP_PIXELS_SIZE, MAP_OFFSET_Y));
	lifes.setPosition(sf::Vector2f(MAP_OFFSET_X + 20 * MAP_PIXELS_SIZE, MAP_OFFSET_Y + 2* MAP_PIXELS_SIZE));

	//frame.setColor(sf::Color::Yellow);
	frame.setSize(sf::Vector2f(MAP_PIXELS_SIZE * 6, MAP_PIXELS_SIZE * 3.4f));
	frame.setPosition(sf::Vector2f(MAP_OFFSET_X + 20 * MAP_PIXELS_SIZE, MAP_OFFSET_Y));
	frame.setOutlineColor(sf::Color::Yellow);
	frame.setFillColor(sf::Color::Transparent);
	frame.setOutlineThickness(static_cast<float>(MAP_PIXELS_SIZE / 5));

	window.draw(frame);
	window.draw(lifes);
	window.draw(score);

}


GameMaster::GameMaster()
{
	init();
	assert(font_.loadFromFile("./Arialn.ttf"));
}


GameMaster::~GameMaster()
{
}

void GameMaster::main(sf::RenderWindow& window, sf::Event& event, Highscore& hgh, const sf::Sprite& background){
	sf::Font font;
	assert(font.loadFromFile("./Walk-Around-the-Block.ttf"));

	sf::Text pause, pause_contiunation;
	pause.setString("Pause!");
	pause.setFont(font);
	pause.setFillColor(sf::Color::Yellow);
	pause.setCharacterSize(MAP_PIXELS_SIZE * 2);
	pause.setPosition(sf::Vector2f(MAP_OFFSET_X + 7 * MAP_PIXELS_SIZE, MAP_OFFSET_Y + 3 * MAP_PIXELS_SIZE));

	pause_contiunation.setString("Press Enter to continue, Escape to quit game");
	pause_contiunation.setFont(font);
	pause_contiunation.setFillColor(sf::Color::Yellow);
	pause_contiunation.setCharacterSize(MAP_PIXELS_SIZE * 0.5f);
	pause_contiunation.setPosition(sf::Vector2f(MAP_OFFSET_X + 5.4f * MAP_PIXELS_SIZE, MAP_OFFSET_Y + 6* MAP_PIXELS_SIZE));



	std::random_device rd{};
	std::mt19937 engine{ rd() };
	std::uniform_real_distribution<> dist(0.0, 1.0);

	srand(std::time(NULL));

	bool enemyMove = false;
	int xd = 0;

	//hgh.addHighscores("KIEMON", 696969696);
	//hgh.saveHighscores();


	//Creating components of game/map -----------------------------

	//Map
	std::vector<Map> map = Map::stage1(window);
	std::vector<Point> points = Point::stage1();

	//mask for teleport
	std::vector<Map> mask{ Map(window, sf::Vector2f(17, 9), sf::Vector2f(2, 1), sf::Color::Black),
		Map(window, sf::Vector2f(0, 9), sf::Vector2f(2, 1), sf::Color::Black) };

	//teleport 
	std::vector<Map> teleport{ Map(window, sf::Vector2f(-1, 9), sf::Vector2f(1, 1), sf::Color::Black),
		Map(window, sf::Vector2f(19, 9), sf::Vector2f(1, 1), sf::Color::White) };

	//creating player sprite
	Player pl(window, "./sprites/player.png", sf::Vector2f(9 ,14),1.f);

	//creating Enemies
	std::vector<Enemy> enemies{ Enemy(window, "./sprites/special.jpg", sf::Vector2f(8,9)),
		Enemy(window, "./sprites/special.jpg", sf::Vector2f(9, 9)),
		Enemy(window, "./sprites/special.jpg", sf::Vector2f(10, 9)) };

	//TODO

	//initialise game with starting values
	init();
	GameLogic logic;

	//loop for framerate-independent gameplay - TODO
	//float delta = 0.0015f;
	//float nextTime = clock.getElapsedTime().asSeconds();

	//mainloop
	while (!logic.getExit()) {
		xd++;
		window.clear();

		if (!logic.getPause()) {
			window.clear();
			window.draw(background);

			//map drawing
			drawMap(map, window, pl, enemies);

			//teleport handling
			//for (auto enemy : enemies) {
			//	if (enemy.doesCollide(teleport[0].getShape())){
			//		enemy.setPosition(18.f, 9.f);
			//		enemy.setmoveLeft();
			//	}
			//	else if (pl.doesCollide(teleport[1].getShape())) {
			//		enemy.setPosition(0.f, 9.f);
			//		enemy.setmoveRight();
			//	}
			//}

			//points drawing + handling
			for (auto it = points.begin(); it < points.end();) {

				if (pl.doesCollide(it->getShape()) && it->getPower() == SpecialPower::SLOW_EAT_ENEMY) {
					pl.setPower(SpecialPower::SLOW_EAT_ENEMY);
					logic.setValidPower(true);
					logic.startClock();
					for (auto& obj : enemies){
						obj.changeColor(sf::Color::Red);
					}
					it = points.erase(it);
					updateScore(200);
				}
				else if (pl.doesCollide(it->getShape()) && it->getPower() == SpecialPower::NONE){
					it = points.erase(it);
					updateScore();
				}else{
					it->draw(window);
					++it;
				}
			}

			//logic.pointsLogic(window, &points, &pl, &enemies);


			//enemies collision
			logic.enemyCollision(enemies, pl, lifes_, score_);

			//player actions + drawing
			logic.playerLogic(window, pl, event, map);


			//enemy actions
			logic.enemyLogic(window, pl, enemies, map, xd);
			if (xd >= 75){
				xd = 0;
			}

			//teleport logic
			logic.teleportLogic(teleport, pl, enemies);

			pl.draw(window);
			drawUpdates(window);

			// drawing mask for teleport
			//mask[0].draw(window);
			//mask[1].draw(window);

			teleport[0].draw(window);
			teleport[1].draw(window);
			//winning game situation
			if (points.empty()) {
				logic.setExit(true);
				logic.setPause(true);
			}
		}
		else {
			window.clear();
			window.draw(pause);
			window.draw(pause_contiunation);
			logic.pausedGameLogic(window, event);
		}
		window.display();
	}
	if (score_ == 0) {
		return;
	}
	else{
		//lost game
		if (lifes_ <= 0) {
			endSign("YOU LOST!",window,font,logic);
		}
		//won game
		else  if(points.empty()){
			endSign("YOU WON!",window,font,logic);
		}
		else{}
		endResult(window, event, &font, logic, hgh);
	}
}

void GameMaster::endSign(const std::string& str, sf::RenderWindow& window,sf::Font& font,GameLogic& logic){
	sf::Text lost;

	lost.setString(str);
	lost.setFillColor(sf::Color::Yellow);
	lost.setCharacterSize(150);
	lost.setFont(font);
	lost.setPosition(sf::Vector2f(MAP_OFFSET_X, MAP_OFFSET_Y + 4 * MAP_PIXELS_SIZE));

	logic.startClock();
	while (logic.getElapsedTime() <= 2.f){
		window.clear();
		window.draw(lost);
		window.display();
	}
}

void GameMaster::endResult(sf::RenderWindow& window,sf::Event event, sf::Font* font, GameLogic& logic, Highscore& hgh){
	sf::Text ending, input;
	sf::String nick;
	ending.setString("Enter Your Nickname: ");
	ending.setFillColor(sf::Color::Yellow);
	ending.setCharacterSize(50);
	ending.setFont(*font);
	ending.setPosition(sf::Vector2f(MAP_OFFSET_X, MAP_OFFSET_Y + 2 * MAP_PIXELS_SIZE));

	input.setFillColor(sf::Color::Yellow);
	input.setCharacterSize(25);
	input.setFont(*font);
	input.setPosition(sf::Vector2f(MAP_OFFSET_X, MAP_OFFSET_Y + 5 * MAP_PIXELS_SIZE));

	while (!logic.getSaveScore()){
		window.clear();
		logic.afterGameLogic(window, event, nick);
		input.setString(nick);
		window.draw(ending);
		window.draw(input);
		window.display();
	}
	////EMPTY STRING PROBLEM
	//std::string s = nick.toAnsiString();
	//std::cout << s;
	//if (s != "\n" || s!="") {
	hgh.addHighscores(nick, score_);
	hgh.saveHighscores();
	//}
}

void GameMaster::drawMap(std::vector<Map>& map,sf::RenderWindow& window,Player& pl,std::vector<Enemy>& enemies){
	for (auto& obj : map) {
		obj.draw(window);
		if (pl.doesCollide(obj.getShape()))
			pl.stop();

		for (int i = 0; i < 3; i++) {
			if (enemies[i].doesCollide(obj.getShape()))
			{
				enemies[i].stop();
			}
		}
	}

}
