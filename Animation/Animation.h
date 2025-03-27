#pragma once
#include<SFML\Graphics.hpp>
class Animation
{
public:
	Animation(sf::Texture* texture,sf::Vector2u imageCount, float switchTime);
	~Animation();

	void Update(int row, float deltaTime);

public://declaring public again because I want to keep my variables different from my functions
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

