#include "AI.cpp"
#include "includes/Audio.h"
#include "includes/Home_Page.h"
#include "includes/game.h"

using namespace std;
class Text : public sf::Drawable
{
	sf::Font font;
	sf::Text text;
	sf::RectangleShape cover;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(text, states);
	}

public:
	Text(string s, string f, sf::Color color, int height, sf::Vector2f pos)
	{
		font.loadFromFile(f);
		text.setFont(font);
		text.setOutlineThickness(2.5);
		text.setOutlineColor(sf::Color(254, 255, 102));
		sf::Rect rect = text.getGlobalBounds();
		text.setOrigin(rect.width / 2, rect.height / 2);

		text.setCharacterSize(height);
		text.setFillColor(color);

		text.setString(s);
		text.setPosition(pos);
	}
	void hover(sf::Vector2i pos)
	{
		if (text.getGlobalBounds().contains(pos.x, pos.y))
		{
			text.setFillColor(sf::Color::Red);
		}
		else
		{
			text.setFillColor(sf::Color(85, 99, 7));
		}
	}
	bool mouse_clicked(sf::Vector2i pos)
	{
		return text.getGlobalBounds().contains(pos.x, pos.y);
	}
};

class Baghchal
{
	sf::RenderWindow window;
	Game game;
	sf::Event event;
	AI ai;

public:
	Baghchal();
	void run_home();
	void run_game(bool);
};