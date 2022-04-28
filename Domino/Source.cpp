#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

const int GLOBAL_VALUE=28;		//число костей в игре
const int IN_HAND = 7;			//число костей в руке

int d0 = 0,
	d1 = 0,
	d2 = 0,
	d3 = 0,
	d4 = 0,
	d5 = 0,
	d6 = 0;//вышедшие кости

class Domino {
private:
	int number1;	//число кости 1
	int number2;	//число кости 2
	int value;		//количество очков кости
	int id;			//номер кости
	bool dual;		//кость €вл€етс€ дублем?
	bool inGame;	//кость в игре?
	bool inHand;	//кость в руке?

public:
	void setNumber1(int number1) {
		this->number1 = number1;
	}
	int getNumber1()
	{
		return this->number1;
	}

	void setNumber2(int number2) {
		this->number2 = number2;
	}
	int getNumber2()
	{
		return this->number2;
	}

	void setId(int id) {
		this->id = id;
	}
	int getId()
	{
		return this->id;
	}

	int getValue()
	{
		return this->value;
	}

	void setDual(bool dual) {
		this->dual = dual;
	}
	bool getDual()
	{
		return this->dual;
	}

	void setInGame(bool inGame) {
		this->inGame = inGame;
	}
	bool getInGame()
	{
		return this->inGame;
	}

	void setInHand(bool inHand) {
		this->inHand = inHand;
	}
	bool getInHand()
	{
		return this->inHand;
	}

	Domino() {}
	Domino(int number1, int number2, bool dual,int id) {
		this->number1 = number1;
		this->number2 = number2;
		this->dual = dual;
		this->inGame = false;
		this->inHand = false;
		this->value = number1 + number2;
		this->id = id;
	}
};

class Player {
private:
	bool move=false;			//сейчас ход данного игрока?
	
public:
	void setMove(bool move) {
		this->move = move;
	}
	bool getMove()
	{
		return this->move;
	}

	std::vector<Domino> hand;		//"–ука" игрока
};

struct Cells {
	int number1 = -1;
	int number2 = -1;
	bool dual = false;
	bool first = false;
};

void drawDomino(sf::RenderWindow& window,int x,int y,bool player,int n1,int n2){
sf::RectangleShape domino(sf::Vector2f(60, 100));
	domino.setPosition(x, y);
	domino.setOutlineThickness(4);
	if (!player){
		domino.setFillColor(sf::Color(0, 0, 0));
	}
	else {
		domino.setFillColor(sf::Color(255, 255, 255));
	}
	domino.setOutlineColor(sf::Color(0, 0, 0));

	sf::RectangleShape line(sf::Vector2f(60, 3));
	line.setPosition(x, y+48);
	line.setFillColor(sf::Color(0, 0, 0));
	
	window.draw(domino);
	window.draw(line);

	if (player)
	{
		sf::RectangleShape point1(sf::Vector2f(10, 10));
		sf::RectangleShape point2(sf::Vector2f(10, 10));
		sf::RectangleShape point3(sf::Vector2f(10, 10));
		sf::RectangleShape point4(sf::Vector2f(10, 10));
		sf::RectangleShape point5(sf::Vector2f(10, 10));
		sf::RectangleShape point6(sf::Vector2f(10, 10));

		switch (n1)
		{
		case 1:
			point1.setPosition(x + 25, y + 20);
			point1.setFillColor(sf::Color(0, 0, 0));
			window.draw(point1);
			break;
		case 2:
			point1.setPosition(x + 10, y + 10);
			point1.setFillColor(sf::Color(0, 0, 0));
			window.draw(point1);
			point2.setPosition(x + 40, y + 30);
			point2.setFillColor(sf::Color(0, 0, 0));
			window.draw(point2);
			break;
		case 3:
			point1.setPosition(x + 10, y + 10);
			point1.setFillColor(sf::Color(0, 0, 0));
			window.draw(point1);
			point2.setPosition(x + 25, y + 20);
			point2.setFillColor(sf::Color(0, 0, 0));
			window.draw(point2);
			point3.setPosition(x + 40, y + 30);
			point3.setFillColor(sf::Color(0, 0, 0));
			window.draw(point3);
			break;
		case 4:
			point1.setPosition(x + 10, y + 10);
			point1.setFillColor(sf::Color(0, 0, 0));
			window.draw(point1);
			point2.setPosition(x + 40, y + 10);
			point2.setFillColor(sf::Color(0, 0, 0));
			window.draw(point2);
			point3.setPosition(x + 10, y + 30);
			point3.setFillColor(sf::Color(0, 0, 0));
			window.draw(point3);
			point4.setPosition(x + 40, y + 30);
			point4.setFillColor(sf::Color(0, 0, 0));
			window.draw(point4);
			break;
		case 5:
			point1.setPosition(x + 10, y + 10);
			point1.setFillColor(sf::Color(0, 0, 0));
			window.draw(point1);
			point2.setPosition(x + 40, y + 10);
			point2.setFillColor(sf::Color(0, 0, 0));
			window.draw(point2);
			point3.setPosition(x + 10, y + 30);
			point3.setFillColor(sf::Color(0, 0, 0));
			window.draw(point3);
			point4.setPosition(x + 40, y + 30);
			point4.setFillColor(sf::Color(0, 0, 0));
			window.draw(point4);
			point5.setPosition(x + 25, y + 20);
			point5.setFillColor(sf::Color(0, 0, 0));
			window.draw(point5);
			break;
		case 6:
			point1.setPosition(x + 10, y + 5);
			point1.setFillColor(sf::Color(0, 0, 0));
			window.draw(point1);
			point2.setPosition(x + 40, y + 5);
			point2.setFillColor(sf::Color(0, 0, 0));
			window.draw(point2);
			point3.setPosition(x + 10, y + 35);
			point3.setFillColor(sf::Color(0, 0, 0));
			window.draw(point3);
			point4.setPosition(x + 40, y + 35);
			point4.setFillColor(sf::Color(0, 0, 0));
			window.draw(point4);
			point5.setPosition(x + 10, y + 20);
			point5.setFillColor(sf::Color(0, 0, 0));
			window.draw(point5);
			point6.setPosition(x + 40, y + 20);
			point6.setFillColor(sf::Color(0, 0, 0));
			window.draw(point6);
			break;
		default:
			break;
		}

		switch (n2)
		{
		case 1:
			point1.setPosition(x + 25, y + 70);
			point1.setFillColor(sf::Color(0, 0, 0));
			window.draw(point1);
			break;
		case 2:
			point1.setPosition(x + 10, y + 60);
			point1.setFillColor(sf::Color(0, 0, 0));
			window.draw(point1);
			point2.setPosition(x + 40, y + 80);
			point2.setFillColor(sf::Color(0, 0, 0));
			window.draw(point2);
			break;
		case 3:
			point1.setPosition(x + 10, y + 60);
			point1.setFillColor(sf::Color(0, 0, 0));
			window.draw(point1);
			point2.setPosition(x + 25, y + 70);
			point2.setFillColor(sf::Color(0, 0, 0));
			window.draw(point2);
			point3.setPosition(x + 40, y + 80);
			point3.setFillColor(sf::Color(0, 0, 0));
			window.draw(point3);
			break;
		case 4:
			point1.setPosition(x + 10, y + 60);
			point1.setFillColor(sf::Color(0, 0, 0));
			window.draw(point1);
			point2.setPosition(x + 40, y + 60);
			point2.setFillColor(sf::Color(0, 0, 0));
			window.draw(point2);
			point3.setPosition(x + 10, y + 80);
			point3.setFillColor(sf::Color(0, 0, 0));
			window.draw(point3);
			point4.setPosition(x + 40, y + 80);
			point4.setFillColor(sf::Color(0, 0, 0));
			window.draw(point4);
			break;
		case 5:
			point1.setPosition(x + 10, y + 60);
			point1.setFillColor(sf::Color(0, 0, 0));
			window.draw(point1);
			point2.setPosition(x + 40, y + 60);
			point2.setFillColor(sf::Color(0, 0, 0));
			window.draw(point2);
			point3.setPosition(x + 10, y + 80);
			point3.setFillColor(sf::Color(0, 0, 0));
			window.draw(point3);
			point4.setPosition(x + 40, y + 80);
			point4.setFillColor(sf::Color(0, 0, 0));
			window.draw(point4);
			point5.setPosition(x + 25, y + 70);
			point5.setFillColor(sf::Color(0, 0, 0));
			window.draw(point5);
			break;
		case 6:
			point1.setPosition(x + 10, y + 55);
			point1.setFillColor(sf::Color(0, 0, 0));
			window.draw(point1);
			point2.setPosition(x + 40, y + 55);
			point2.setFillColor(sf::Color(0, 0, 0));
			window.draw(point2);
			point3.setPosition(x + 10, y + 85);
			point3.setFillColor(sf::Color(0, 0, 0));
			window.draw(point3);
			point4.setPosition(x + 40, y + 85);
			point4.setFillColor(sf::Color(0, 0, 0));
			window.draw(point4);
			point5.setPosition(x + 10, y + 70);
			point5.setFillColor(sf::Color(0, 0, 0));
			window.draw(point5);
			point6.setPosition(x + 40, y + 70);
			point6.setFillColor(sf::Color(0, 0, 0));
			window.draw(point6);
			break;
		default:
			break;
		}
	}
}

void drawDominoOnTable(sf::RenderWindow& window, int x, int y, int num, bool dual) {
	sf::RectangleShape domino(sf::Vector2f(56, 56));
	
	domino.setPosition(x, y);
	domino.setOutlineThickness(4);
	
	if(dual)
		domino.setFillColor(sf::Color(250, 212, 0));
	else
	domino.setFillColor(sf::Color(255, 255, 255));
	domino.setOutlineColor(sf::Color(0, 0, 0));

	window.draw(domino);

	sf::RectangleShape point1(sf::Vector2f(10, 10));
	sf::RectangleShape point2(sf::Vector2f(10, 10));
	sf::RectangleShape point3(sf::Vector2f(10, 10));
	sf::RectangleShape point4(sf::Vector2f(10, 10));
	sf::RectangleShape point5(sf::Vector2f(10, 10));
	sf::RectangleShape point6(sf::Vector2f(10, 10));

	switch (num)
	{
	case 1:
		point1.setPosition(x + 25, y + 20);
		point1.setFillColor(sf::Color(0, 0, 0));
		window.draw(point1);
		break;
	case 2:
		point1.setPosition(x + 10, y + 10);
		point1.setFillColor(sf::Color(0, 0, 0));
		window.draw(point1);
		point2.setPosition(x + 40, y + 30);
		point2.setFillColor(sf::Color(0, 0, 0));
		window.draw(point2);
		break;
	case 3:
		point1.setPosition(x + 10, y + 10);
		point1.setFillColor(sf::Color(0, 0, 0));
		window.draw(point1);
		point2.setPosition(x + 25, y + 20);
		point2.setFillColor(sf::Color(0, 0, 0));
		window.draw(point2);
		point3.setPosition(x + 40, y + 30);
		point3.setFillColor(sf::Color(0, 0, 0));
		window.draw(point3);
		break;
	case 4:
		point1.setPosition(x + 10, y + 10);
		point1.setFillColor(sf::Color(0, 0, 0));
		window.draw(point1);
		point2.setPosition(x + 40, y + 10);
		point2.setFillColor(sf::Color(0, 0, 0));
		window.draw(point2);
		point3.setPosition(x + 10, y + 30);
		point3.setFillColor(sf::Color(0, 0, 0));
		window.draw(point3);
		point4.setPosition(x + 40, y + 30);
		point4.setFillColor(sf::Color(0, 0, 0));
		window.draw(point4);
		break;
	case 5:
		point1.setPosition(x + 10, y + 10);
		point1.setFillColor(sf::Color(0, 0, 0));
		window.draw(point1);
		point2.setPosition(x + 40, y + 10);
		point2.setFillColor(sf::Color(0, 0, 0));
		window.draw(point2);
		point3.setPosition(x + 10, y + 30);
		point3.setFillColor(sf::Color(0, 0, 0));
		window.draw(point3);
		point4.setPosition(x + 40, y + 30);
		point4.setFillColor(sf::Color(0, 0, 0));
		window.draw(point4);
		point5.setPosition(x + 25, y + 20);
		point5.setFillColor(sf::Color(0, 0, 0));
		window.draw(point5);
		break;
	case 6:
		point1.setPosition(x + 10, y + 5);
		point1.setFillColor(sf::Color(0, 0, 0));
		window.draw(point1);
		point2.setPosition(x + 40, y + 5);
		point2.setFillColor(sf::Color(0, 0, 0));
		window.draw(point2);
		point3.setPosition(x + 10, y + 35);
		point3.setFillColor(sf::Color(0, 0, 0));
		window.draw(point3);
		point4.setPosition(x + 40, y + 35);
		point4.setFillColor(sf::Color(0, 0, 0));
		window.draw(point4);
		point5.setPosition(x + 10, y + 20);
		point5.setFillColor(sf::Color(0, 0, 0));
		window.draw(point5);
		point6.setPosition(x + 40, y + 20);
		point6.setFillColor(sf::Color(0, 0, 0));
		window.draw(point6);
		break;
	default:
		break;
	}

}

int choosen = 0;

void sleep() {
	clock_t time_end;
	time_end = clock() + 100 * CLOCKS_PER_SEC / 1000;
	while (clock() < time_end)
	{
	}
}

int main() {
	std::vector<Domino> pool;	//общий массив костей и "базар"

	for (int i = 0, j = 0, k = 0; i < GLOBAL_VALUE; i++) {
		bool dual = false;
		if (j == k)
			dual = true;
		pool.push_back(Domino(j, k, dual, i));

		j++;
		if (j == 7) {
			k++;
			j = k;
		}
	}//—оздание костей

	srand(time(0));
	for (int i = 0; i < GLOBAL_VALUE; i++)
		std::swap(pool[i], pool[std::rand() % GLOBAL_VALUE]);//перемешивание костей

	Player player;
	Player computer;

	for (int i = 0; i < IN_HAND; i++) {
		player.hand.push_back(pool[i]);
		computer.hand.push_back(pool[i + IN_HAND]);
	}//раздача костей игрокам
	for (int i = 0; i < IN_HAND * 2; i++) {
		pool.erase(pool.begin());
	}

	int max1 = -1, max2 = -1, maxId = -1;
	bool gamer = false;		//ходит игрок?
	bool start = false;		//игра началась?

	int numberOfTransitions = 0;

	for (int i = 0; i < IN_HAND; i++) {
		if (player.hand[i].getDual()) {
			if ((player.hand[i].getNumber1() + player.hand[i].getNumber2()) > (max1 + max2)) {
				max1 = player.hand[i].getNumber1();
				max2 = player.hand[i].getNumber2();
				maxId = player.hand[i].getId();
				gamer = true;
				start = true;
			}
		}
		if (computer.hand[i].getDual()) {
			if ((computer.hand[i].getNumber1() + computer.hand[i].getNumber2()) > (max1 + max2)) {
				max1 = computer.hand[i].getNumber1();
				max2 = computer.hand[i].getNumber2();
				maxId = computer.hand[i].getId();
				gamer = false;
				start = true;
			}
		}
	}//проверка наличи€ дубл€ у игроков
	if (!start) {
		int maxId1 = 0, maxId2 = 0;
		for (int i = 0; i < IN_HAND; i++) {
			if (player.hand[i].getValue() > max1) {
				max1 = player.hand[i].getValue();
				maxId1 = player.hand[i].getId();
			}
			if (computer.hand[i].getValue() > max2) {
				max2 = computer.hand[i].getValue();
				maxId2 = computer.hand[i].getId();
			}
		}
		if (max1 >= max2) {
			start = true;
			gamer = true;
			maxId = maxId1;
		}
		else {
			start = true;
			gamer = false;
			maxId = maxId2;
		}
	}//если нет дубл€ поиск кости с наибольшим значением (если значени€ одинаковые, то ходит игрок)


	if (gamer) {
		player.setMove(true);
	}
	else {
		computer.setMove(true);
	}

	sf::RenderWindow window(sf::VideoMode(1360, 720), "Domino");

	sf::Font font;
	font.loadFromFile("CyrilicOld.ttf");

	sf::Text text("", font, 40);
	text.setFillColor(sf::Color(0, 0, 0));
	text.setPosition(30, 10);

	sf::Image icon;
	icon.loadFromFile("icon.png");
	window.setIcon(344, 344, icon.getPixelsPtr());

	bool firstMove = true;
	bool fish = false;
	bool endOfGame = false;

	std::vector<Cells> field;

	int freeNumberLeft = -1;
	int freeNumberRight = -1;

	bool iterator=false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (endOfGame)
			{
				sf::Font font;
				font.loadFromFile("CyrilicOld.ttf");
				sf::Text text("", font, 80);
				text.setFillColor(sf::Color(0, 0, 0));
				text.setPosition(500, 100);

				if (!fish) {
					if (player.hand.size() == 0) {
						sleep();
						sleep();
						sleep();
						sleep();
						window.clear(sf::Color(0, 255, 0));
						text.setString("ѕобеда!!!");
						window.draw(text);
					}
					else if (computer.hand.size() == 0) {
						sleep();
						sleep();
						sleep();
						sleep();
						window.clear(sf::Color(232, 32, 32));
						text.setString("ѕоражение!!!");
						window.draw(text);
					}
				}
				else {
					int pl = 0, cmp = 0;

					for (int i = 0; i < player.hand.size(); i++) {
						if (player.hand[i].getNumber1() == 0 && player.hand[i].getDual())
							pl += 10;
						else
							pl += player.hand[i].getValue();
					}
					for (int i = 0; i < computer.hand.size(); i++) {
						if (computer.hand[i].getNumber1() == 0 && computer.hand[i].getDual())
							cmp += 10;
						else
							cmp += computer.hand[i].getValue();
					}

					if (cmp < pl) {
						sleep();
						sleep();
						sleep();
						sleep();
						window.clear(sf::Color(232, 32, 32));
						text.setString("–ыба!!!\nѕоражение\nвам не хвтило очков(");
						window.draw(text);
					}
					else {
						sleep();
						sleep();
						sleep();
						sleep();
						window.clear(sf::Color(0, 255, 0));
						text.setString("–ыба!!!\nѕобеда!!!");
						window.draw(text);
					}
				}
				window.display();
			}
			else {
				window.clear(sf::Color(255, 0, 0));

				for (int i = 0; i < player.hand.size(); i++) {
					drawDomino(window, 10 + (70 * i), 610, true, player.hand[i].getNumber1(), player.hand[i].getNumber2());
				}
				for (int i = 0; i < computer.hand.size(); i++) {
					drawDomino(window, 1260 - (70 * i), 10, false, computer.hand[i].getNumber1(), computer.hand[i].getNumber2());
				}

				int frst;
				for (int i = 0; i < field.size(); i++) {
					if (field[i].first) {
						frst = i;
					}
				}

				for (int i = 0; i < field.size(); i++) {
					if(i<=frst)
					drawDominoOnTable(window, 100+(i * 60), 300, field[i].number1, field[i].dual);
					else
						drawDominoOnTable(window, 100 + (i * 60), 300, field[i].number2, field[i].dual);
				}

				text.setString(" остей на базаре: " + std::to_string(pool.size()));
				if (computer.hand.size() > 12) {
					text.setFillColor(sf::Color(255, 255, 255));
				}
				window.draw(text);

				if (player.getMove()) {
					sf::RectangleShape point(sf::Vector2f(60, 10));
					point.setFillColor(sf::Color(255, 77, 0));

					if (firstMove) {
						bool dual;
						for (int i = 0; i < player.hand.size(); i++)
						{
							if (player.hand[i].getDual()) {
								dual = true;
								break;
							}
						}

						if (dual) {
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
								choosen--;
								sleep();
								if (choosen < 0) {
									choosen = player.hand.size() - 1;
								}
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
								choosen++;
								sleep();
								if (choosen >= player.hand.size()) {
									choosen = 0;
								}
							}

							point.setPosition(10 + (70 * choosen), 710);
							window.draw(point);

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && player.hand[choosen].getDual()) {
								player.setMove(false);
								computer.setMove(true);

								Cells cell;
								cell.first = true;
								cell.dual = true;
								cell.number1 = player.hand[choosen].getNumber1();
								cell.number2 = player.hand[choosen].getNumber1();
								freeNumberLeft = cell.number1;
								freeNumberRight = cell.number2;
								field.push_back(cell);

								player.hand.erase(player.hand.begin() + choosen);
								choosen = 0;

								firstMove = false;

								sleep();
							}
						}
						else {
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
								choosen--;
								sleep();
								if (choosen < 0) {
									choosen = player.hand.size() - 1;
								}
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
								choosen++;
								sleep();
								if (choosen >= player.hand.size()) {
									choosen = 0;
								}
							}

							point.setPosition(10 + (70 * choosen), 710);
							window.draw(point);

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
								player.setMove(false);
								computer.setMove(true);
								
								Cells cell;
								cell.first = true;
								cell.dual = false;
								cell.number1 = player.hand[choosen].getNumber1();
								cell.number2 = player.hand[choosen].getNumber1();
								freeNumberLeft = cell.number1;
								freeNumberRight = cell.number2;
								field.push_back(cell);

								player.hand.erase(player.hand.begin() + choosen);
								choosen = 0;

								firstMove = false;

								sleep();
							}
						}
					}
					else {
						bool move = false;
						while (!move) {
							for (int i = 0; i < player.hand.size(); i++)
							{
								if (player.hand[i].getNumber1() == freeNumberLeft || 
									player.hand[i].getNumber1() == freeNumberRight || 
									player.hand[i].getNumber2() == freeNumberLeft ||
									player.hand[i].getNumber2() == freeNumberRight) {
									move = true;
									numberOfTransitions = 0;
									break;
								}
							}
							if (!move) {
								if (pool.size() > 0) {
									player.hand.push_back(pool[0]);
									pool.erase(pool.begin());
								}
								else{
									player.setMove(false);
									computer.setMove(true);
									if (numberOfTransitions == 0)
										numberOfTransitions++;
									else {
										endOfGame = true;
										fish = true;
										break;
									}
								}
							}
						}

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
							choosen--;
							sleep();
							if (choosen < 0) {
								choosen = player.hand.size() - 1;
							}
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
							choosen++;
							sleep();
							if (choosen >= player.hand.size()) {
								choosen = 0;
							}
						}
						point.setPosition(10 + (70 * choosen), 710);

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
							iterator = false;
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
							iterator = true;
						}

						if (!iterator) {
							if (player.hand[choosen].getNumber1() != freeNumberLeft && player.hand[choosen].getNumber2() != freeNumberLeft ) {
								point.setFillColor(sf::Color(120, 29, 39));
								window.draw(point);
							}
							else if(player.hand[choosen].getNumber1() == freeNumberLeft || player.hand[choosen].getNumber2() == freeNumberLeft) {
								Cells cell;
								point.setFillColor(sf::Color(255, 77, 0));
								window.draw(point);

								if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
									player.setMove(false);
									computer.setMove(true);

									if (player.hand[choosen].getNumber1() == freeNumberLeft)
									{
										cell.number1 = player.hand[choosen].getNumber2();
										cell.number2 = player.hand[choosen].getNumber1();
										cell.dual = player.hand[choosen].getDual();
										freeNumberLeft = cell.number1;
									}
									else if (player.hand[choosen].getNumber2() == freeNumberLeft)
									{
										cell.number1 = player.hand[choosen].getNumber1();
										cell.number2 = player.hand[choosen].getNumber2();
										cell.dual = player.hand[choosen].getDual();
										freeNumberLeft = cell.number1;
									}
									player.hand.erase(player.hand.begin() + choosen);
									choosen = 0;

									field.emplace(field.begin(), cell);

									if (player.hand.size() == 0)
										endOfGame = true;
									else
										sleep();
								}
							}
						}
						else {
							if (player.hand[choosen].getNumber1() != freeNumberRight &&player.hand[choosen].getNumber2() != freeNumberRight) {
								point.setFillColor(sf::Color(120, 29, 39));
								window.draw(point);
							}
							else if (player.hand[choosen].getNumber1() == freeNumberRight || player.hand[choosen].getNumber2() == freeNumberRight) {
								Cells cell;

								point.setFillColor(sf::Color(255, 77, 0));
								window.draw(point);

								if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
									player.setMove(false);
									computer.setMove(true);

									if (player.hand[choosen].getNumber1() == freeNumberRight)
									{
										cell.number1 = player.hand[choosen].getNumber1();
										cell.number2 = player.hand[choosen].getNumber2();
										cell.dual = player.hand[choosen].getDual();
										freeNumberRight = cell.number2;
									}
									else if (player.hand[choosen].getNumber2() == freeNumberRight)
									{
										cell.number1 = player.hand[choosen].getNumber2();
										cell.number2 = player.hand[choosen].getNumber1();
										cell.dual = player.hand[choosen].getDual();
										freeNumberRight = cell.number2;
									}

									player.hand.erase(player.hand.begin() + choosen);
									choosen = 0;

									field.push_back(cell);

									if (player.hand.size() == 0)
										endOfGame = true;
									else
										sleep();
								}
							}
						}
					}
				}
				else {
					player.setMove(true);
					computer.setMove(false);

					int tmp = std::rand() % computer.hand.size();

					if (firstMove) {
						firstMove = false;
						bool duals = false;
						for (int i = 0; i < computer.hand.size(); i++) {
							if (computer.hand[i].getDual()) {
								duals = true;
								break;
							}
						}

						Cells cell;
						cell.first = true;

						if (duals) {
							while (!computer.hand[tmp].getDual())
								tmp = std::rand() % computer.hand.size();
							cell.dual = true;
							cell.number1 = computer.hand[tmp].getNumber1();
							cell.number2 = computer.hand[tmp].getNumber2();

							freeNumberLeft = cell.number1;
							freeNumberRight = cell.number2;

							computer.hand.erase(computer.hand.begin() + tmp);

						}
						else {
							cell.number2 = computer.hand[tmp].getNumber2();
							cell.number1 = computer.hand[tmp].getNumber1();

							freeNumberLeft = cell.number1;
							freeNumberRight = cell.number2;

							computer.hand.erase(computer.hand.begin() + tmp);
						}
						field.push_back(cell);
					}
					else {
						Cells cell;

						bool move = false;
						while (!move) {
							for (int i = 0; i < computer.hand.size(); i++) {
								if (computer.hand[i].getNumber1() == freeNumberLeft || computer.hand[i].getNumber2() == freeNumberLeft) {
									move = true;
									numberOfTransitions = 0;
									if (move) {
										if (computer.hand[i].getNumber1() == freeNumberLeft) {
											cell.number1 = computer.hand[i].getNumber2();
											cell.number2 = computer.hand[i].getNumber1();
											freeNumberLeft = cell.number1;
										}
										else {
											cell.number1 = computer.hand[i].getNumber1();
											cell.number2 = computer.hand[i].getNumber2();
											freeNumberLeft = cell.number1;
										}
										cell.dual = computer.hand[i].getDual();
										field.emplace(field.begin(), cell);
										computer.hand.erase(computer.hand.begin() + i);
										break;
									}
								}
								else if (computer.hand[i].getNumber1() == freeNumberRight || computer.hand[i].getNumber2() == freeNumberRight) {
									move = true;
									numberOfTransitions = 0;
									if (move) {
										if (computer.hand[i].getNumber1() == freeNumberRight) {
											cell.number1 = computer.hand[i].getNumber1();
											cell.number2 = computer.hand[i].getNumber2();
											freeNumberRight = cell.number2;
										}
										else {
											cell.number1 = computer.hand[i].getNumber2();
											cell.number2 = computer.hand[i].getNumber1();
											freeNumberRight = cell.number2;
										}
										cell.dual = computer.hand[i].getDual();
										field.push_back(cell);
										computer.hand.erase(computer.hand.begin() + i);
										break;
									}
								}
							}
							if (!move) {
								if (pool.size() > 0) {
									computer.hand.push_back(pool[0]);
									pool.erase(pool.begin());
								}
								else {
									move = true;
									computer.setMove(false);
									player.setMove(true);
									if (numberOfTransitions == 0)
										numberOfTransitions++;
									else {
										endOfGame = true;
										fish = true;
									}
								}
							}
						}

						if (computer.hand.size() == 0)
							endOfGame = true;
					}

				}

				window.display();
			}
		}
	}

	return 0;
}