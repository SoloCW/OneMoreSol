
#ifndef INCLUDE_HUNTER_H_
#define INCLUDE_HUNTER_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "KoratEmpire.h"
#include "TextureLoader.h"

class Hunter: public KoratEmpire {
public:
	sf::Sprite hunter;

	Hunter(int, TextureLoader*);
	virtual ~Hunter();

	int getLane();

    std::string getName();

	void setLane(int givenLane);

	void wasShot(int damage);

	bool checkDeath();

	void moveCurrentKorat(float timePassed);

	void drawCurrentKorat(sf::RenderWindow& window);

	sf::Sprite getKorat();

	float getPositionX();

	bool checkSurvive();

	int getHealth();

	int getSpeed();

	void shootWeapon();

private:

	int lane;
	int speed = 100;
	int health = 100;
	bool survive = false;

    int lane1 = 335;
    int lane2 = 422;
    int lane3 = 508;
    int lane4 = 594;
    int lane5 = 680;

    bool koratDeathSoundPlayed = false;
	bool koratLeftSoundPlayed = false;
    float postDeathTime;
	sf::Clock postDeathClock;
	sf::Clock postLeftClock;
	float postLeftTime;

	sf::SoundBuffer gruntHitSound;
    sf::Sound gruntWasHit;
    sf::SoundBuffer koratDeathSound;
    sf::Sound koratDied;
    sf::SoundBuffer koratLeftSound;
	sf::Sound koratLeft;
};

#endif