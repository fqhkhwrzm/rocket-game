#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct Backsound1
{
    sf::Music gameMusic;

    Backsound1()
    {
        if (!gameMusic.openFromFile("music/playgame2.wav"))
        {
            std::cout << "ERROR" << std::endl;
        }
    }

    void playGameMusic()
    {
        gameMusic.play();
        gameMusic.setLoop(true);
    }

    void stopGameMusic()
    {
        gameMusic.stop();
    }
};

struct Backsound2
{
    sf::Music menuMusic;
    Backsound2()
    {
        if (!menuMusic.openFromFile("music/menu.wav"))
        {
            std::cout << "ERROR" << std::endl;
        }
    }

    void playMenuMusic()
    {
        menuMusic.play();
        menuMusic.setLoop(true);
    }

    void stopMenuMusic()
    {
        menuMusic.stop();
    }
};
Backsound2 musicMenu;
Backsound2 musicMenuu;

struct Soundhit
{
    sf::SoundBuffer buffer;
    sf::Sound sound;
    Soundhit()
    {
        if (!buffer.loadFromFile("music/fall.wav"))
            cout << "Error" << endl;
        sound.setBuffer(buffer);
    }
    void playSoundhit()
    {
        sound.play();
    }
};

struct rocketBlock
{
    sf::Sprite rocket;
    sf::Texture texture;
    float x = 216, y = 540, timefall = 0.0001;
    float scale_ratio = 0.1367f;
    sf::Vector2f scale;
    float width = 272 * scale_ratio, height = 432 * scale_ratio;
    rocketBlock()
    {
        if (!texture.loadFromFile("img/roket.png"))
            cout << "Error";
        rocket.setTexture(texture);
        rocket.setOrigin(sf::Vector2f(136.f, 216.f));
        rocket.setScale(sf::Vector2f(scale_ratio, scale_ratio));
        scale = rocket.getScale();
        rocket.setPosition(x, y);
    }
    void update(float window_width, float window_height)
    {
        rocket.setPosition(sf::Vector2f(x, y));
    }
    void draw(sf::RenderWindow& window)
    {
        window.draw(rocket);
    }
    void moveleft(float window_width, float window_height)
    {
        rocket.setScale(scale.x * -1, scale.y * 1);
        if (rocket.getRotation() != 325)
            rocket.setRotation(rocket.getRotation() + 325);
        x += -0.07;
        y += -0.07;
        timefall = 0.001;
        if (x - width / 2 <= 0)
            x = 0 + width / 2;
    }
    void moveright(float window_width, float window_height)
    {
        rocket.setScale(scale.x * 1, scale.y * 1);
        if (rocket.getRotation() != 35)
            rocket.setRotation(rocket.getRotation() + 35);
        x += 0.07;
        y += -0.07;
        timefall = 0.001;
        if (x + width / 2 >= window_width)
            x = window_width - width / 2;
    }
    void moveup(float window_width, float window_height)
    {
        rocket.setScale(scale.x * 1, scale.y * 1);
        if (rocket.getRotation() != 0)
            rocket.setRotation(rocket.getRotation() + 0);
        x += 0.0;
        y += -0.07;
        timefall = -0.01;
        if (x + width / 2 >= window_width)
            x = window_width - width / 2;
    }

    void brake(float window_width, float window_height)
    {
        rocket.setScale(scale.x * 1, scale.y * 1);
        if (rocket.getRotation() != 0)
            rocket.setRotation(rocket.getRotation() + 0);
        x += 0.0;
        y += 0.037;
        timefall = 0.0000975;
        if (x + width / 2 >= window_width)
            x = window_width - width / 2;
    }

    void fall(float window_width, float window_height)
    {
        if (rocket.getRotation() <= 45 && rocket.getRotation() > 0)
        {
            rocket.setRotation(rocket.getRotation() - 5);
        }
        if (rocket.getRotation() >= 315 && rocket.getRotation() < 360)
        {
            rocket.setRotation(rocket.getRotation() + 5);
        }
        y += timefall;
        timefall += 0.0001;

        if (x + width / 2 == window_width)
        {
            rocket.setScale(scale.x * -1, scale.y * 1);
            x += -10;
            y += -10;
        }
        if (x - width / 2 == 0)
        {
            rocket.setScale(scale.x * 1, scale.y * 1);
            x += 10;
            y += -10;
        }
    }
    void falldown(float window_width, float window_height)
    {
        y += timefall;
        timefall += 0.008;
        rocket.setRotation(rocket.getRotation() + 1);
    }
};

struct Background
{
    sf::Sprite background;
    sf::Texture texture;
    float x = 0, y = 0, timefall = 0;
    float scale = 1.f;
    float width = 432 * scale, height = 768 * scale;

    Background()
    {
        if (!texture.loadFromFile("img/bg.png"))
        {
            cout << "Error" << endl;
        }
        background.setTexture(texture);
        background.setScale(sf::Vector2f(scale, scale));
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(background);
    }
};

struct Endgame
{
    sf::Sprite endgame;
    sf::Texture texture;
    float x = 0, y = 0;
    float scale = 1.f;
    float width = 432 * scale, height = 768 * scale;

    Endgame()
    {
        if (!texture.loadFromFile("img/end.png"))
        {
            cout << "Error" << endl;
        }
        endgame.setTexture(texture);
        endgame.setScale(sf::Vector2f(scale, scale));
    }
    void draw(sf::RenderWindow& window)
    {
        window.draw(endgame);
    }
};

struct Startgame
{
    sf::Sprite startgame;
    sf::Texture texture;
    float x = 0, y = 0;
    float scale = 1.f;
    float width = 432 * scale, height = 768 * scale;

    Startgame()
    {
        if (!texture.loadFromFile("img/start.png"))
        {
            cout << "Error" << endl;
        }
        musicMenu.playMenuMusic();
        startgame.setTexture(texture);
        startgame.setScale(sf::Vector2f(scale, scale));
    }
    void draw(sf::RenderWindow& window)
    {
        window.draw(startgame);
    }
};

sf::Texture asteroidTexture;
sf::Font fontscore;
sf::Text textscore;
sf::Color color(250, 250, 250);

struct asteroidBlock
{
    sf::Sprite asteroid;
    float x = 100, y = 0;
    float scale = 0.5f;
    float width = 81 * scale, height = 87 * scale;

    asteroidBlock()
    {
        if (!asteroidTexture.loadFromFile("img/asteroid.png"))
        {
            cout << "Error" << endl;
        }
        asteroid.setTexture(asteroidTexture);
        asteroid.setOrigin(sf::Vector2f(40.5f, 87.f));
        asteroid.setScale(sf::Vector2f(scale, scale));
    }
    void setX(float _x)
    {
        x = _x;
    }
    void draw(sf::RenderWindow& window)
    {
        window.draw(asteroid);
    }
    void update(float window_width, float window_height)
    {
        asteroid.setPosition(sf::Vector2f(x, y));
        y += 0.1;
    }
    bool collide(float blockX, float blockY, float blockWidth, float blockHeight)
    {
        if (y - height <= blockY + blockHeight / 2 && y >= blockY - blockHeight / 2)
        {
            if (x + width / 2 >= blockX - blockWidth / 2 && x - width / 2 <= blockX + blockWidth / 2)
            {
                return true;
            }
        }
        return false;
    }
};

struct rowAsteroid
{
    vector<asteroidBlock> row;
    int asteroid_number;
    float rand_number, xx;
    rowAsteroid()
    {
        rand_number = rand();
        asteroid_number = (int)rand_number % 3 + 1;
        if (asteroid_number == 1)
        {
            rand_number = rand();
            xx = (int)rand() % 432;
            asteroidBlock asteroid;
            asteroid.setX(xx);
            row.push_back(asteroid);
        }
        if (asteroid_number == 2)
        {
            for (int i = 0; i < 2; i++)
            {
                if (i == 0)
                {
                    asteroidBlock asteroid;
                    rand_number = rand();
                    xx = (int)rand_number % 190;
                    asteroid.setX(xx);
                    row.push_back(asteroid);
                }
                if (i == 1)
                {
                    asteroidBlock asteroid;
                    rand_number = rand();
                    xx = (int)rand_number % 190 + 241;
                    asteroid.setX(xx);
                    row.push_back(asteroid);
                }
            }
        }
        if (asteroid_number == 3)
        {
            for (int i = 0; i < 3; i++)
            {
                if (i == 0)
                {
                    asteroidBlock asteroid;
                    rand_number = rand();
                    xx = (int)rand_number % 120;
                    asteroid.setX(xx);
                    row.push_back(asteroid);
                }
                if (i == 1)
                {
                    asteroidBlock asteroid;
                    rand_number = rand();
                    xx = (int)rand_number % 99 + 165;
                    asteroid.setX(xx);
                    row.push_back(asteroid);
                }
                if (i == 2)
                {
                    asteroidBlock asteroid;
                    rand_number = rand();
                    xx = (int)rand_number % 31 + 400;
                    asteroid.setX(xx);
                    row.push_back(asteroid);
                }
            }
        }
    }
    void draw(sf::RenderWindow& window)
    {
        for (int i = 0; i < asteroid_number; i++)
        {
            row[i].draw(window);
        }
    }
    void update(float window_width, float window_height)
    {
        for (int i = 0; i < asteroid_number; i++)
        {
            row[i].update(window_width, window_height);
        }
    }
    bool collide(float blockX, float blockY, float blockWidth, float blockHeight)
    {
        for (int i = 0; i < asteroid_number; i++)
        {
            if (row[i].collide(blockX, blockY, blockWidth, blockHeight) == true)
                return true;
        }
        return false;
    }
};

struct allAsteroid
{
    vector<rowAsteroid> all;
    string yourscore;

    void draw(sf::RenderWindow& window)
    {
        for (unsigned int i = 0; i < all.size(); i++)
        {
            all[i].draw(window);
        }
    }
    void update(long timeloop, float window_width, float window_height)
    {
        if (timeloop % 2000 == 0)
        {
            rowAsteroid row;
            all.push_back(row);
            yourscore = to_string(all.size());
            // cout<<"time loop"<<" "<<timeloop<<endl;
            // cout<<"all.size"<<" "<<all.size()<<endl;
        }
        for (unsigned int i = 0; i < all.size(); i++)
        {
            all[i].update(window_width, window_height);
        }
    }
    bool collide(float blockX, float blockY, float blockWidth, float blockHeight)
    {
        for (unsigned int i = 0; i < all.size(); i++)
        {
            if (all[i].collide(blockX, blockY, blockWidth, blockHeight) == true)
                return true;
        }
        return false;
    }
};

struct Status
{
    float window_width = 432, window_height = 768;
    Startgame startgame;
    Background background;
    Endgame endgame;
    rocketBlock rocket;
    allAsteroid all;
    Backsound1 gameMusic;
    Soundhit soundhit;
    string score;
    long timeloop = 0; // 225
    bool start = true;
    bool gameover = false;
    void displayStatus(sf::RenderWindow& window)
    {
        if (start == true)
        {
            window.clear(sf::Color::Green);
            gameMusic.playGameMusic();
            startgame.draw(window);
        }
        else
        {
            window.clear(sf::Color::Black);
            background.draw(window);
            all.draw(window);
            rocket.draw(window);

            // draw score
            score = all.yourscore;
            textscore.setFont(fontscore);
            textscore.setString(score);
            textscore.setCharacterSize(40);
            textscore.setFillColor(color);
            textscore.setPosition(sf::Vector2f(10, 5));
            window.draw(textscore);

            if (rocket.y >= window_height)
            {
                window.clear(sf::Color::Black);
                endgame.draw(window);
                textscore.setCharacterSize(60);
                textscore.setFillColor(sf::Color::White);
                textscore.setStyle(sf::Text::Bold);
                textscore.setPosition(sf::Vector2f(200, 364));
                window.draw(textscore);
            }
        }
        window.display();
    }

    void updateStatus()
    {
        if (start == true)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                start = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                start = false;
        }
        else
        {
            if (gameover == false)
            {
                musicMenu.stopMenuMusic();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    rocket.moveleft(window_width, window_height);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    rocket.moveright(window_width, window_height);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    rocket.moveup(window_width, window_height);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    rocket.brake(window_width, window_height);
                else
                    rocket.fall(window_width, window_height);
            }
            else
            {
                rocket.y += -0.5;
                rocket.falldown(window_width, window_height);
            }
            if (gameover == false)
            {
                all.update(timeloop, window_width, window_height);
            }
            rocket.update(window_width, window_height);

            if (all.collide(rocket.x, rocket.y, rocket.width, rocket.height) == true || rocket.y >= window_height)
            {
                soundhit.playSoundhit();
                gameMusic.stopGameMusic();
                gameover = true;
            }
            timeloop++;
        }
    }
};

int main()
{
REPLAY:
    srand(time(0));
    Status status;

    sf::RenderWindow window(sf::VideoMode(status.window_width, status.window_height), "Rocket Launch");
    if (!asteroidTexture.loadFromFile("img/asteroid.png"))
    {
        cout << "Error" << endl;
    }
    if (!fontscore.loadFromFile("font/NexaText-Trial-Bold.ttf"))
    {
        cout << "Error loading NexaText-Trial-Bold.ttf" << endl;
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        status.updateStatus();
        status.displayStatus(window);
        if (status.gameover == true)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                goto REPLAY;
            }
        }
    }
    return 0;
}