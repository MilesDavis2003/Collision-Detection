// Collision of Two Object
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <optional>

bool checkCircleCollision(const sf::CircleShape& a, const sf::CircleShape& b) {
    sf::Vector2f posA = a.getPosition();
    sf::Vector2f posB = b.getPosition();

    float dx = posA.x - posB.x;
    float dy = posA.y - posB.y;
    float distance = std::sqrt(dx * dx + dy * dy);

    float radiusSum = a.getRadius() + b.getRadius();

    return distance < radiusSum;
}

int main()
{
    unsigned int height = 500.f;
    unsigned int width = 800.f;
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(width, height)), "SFML works!");
    window.setFramerateLimit(120);
    float radius = 80.0f;

    sf::CircleShape ball1(radius);
    ball1.setFillColor(sf::Color::Green);
    ball1.setOrigin(sf::Vector2f(radius,radius));
    sf::Vector2f pos1(width/4.f, height/2.f);
    ball1.setPosition(pos1);

    sf::CircleShape ball2(radius);
    ball2.setFillColor(sf::Color::Blue);
    ball2.setOrigin({radius, radius});
    sf::Vector2f pos2((3.f * width) / 4.f, height/2.f);
    ball2.setPosition(pos2);

    float speed = 400.f;
    float dt = 1.f / 60.f;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
            pos2.y += -speed * dt;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
            pos2.y += speed * dt;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
            pos2.x += -speed * dt;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
            pos2.x += speed * dt;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
            pos1.y += -speed * dt;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
            pos1.y += speed * dt;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
            pos1.x += -speed * dt;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
            pos1.x += speed * dt;
        }

        if(pos1.y >= height - radius){
            pos1.y = height - radius;
            
        }else if(pos1.y <= radius){
            pos1.y = radius;
        }
        if(pos1.x >= width - radius){
            pos1.x = width - radius;
        }else if(pos1.x <= radius){
            pos1.x = radius;
        }
        if(pos2.y >= height - radius){
            pos2.y = height - radius;
        }else if(pos2.y <= radius){
            pos2.y = radius;
        }
        if(pos2.x >= width - radius){
            pos2.x = width - radius;
        }else if(pos2.x <= radius){
            pos2.x = radius;
        }

        if (checkCircleCollision(ball1, ball2)) {
            ball1.setFillColor(sf::Color::Red);
            ball2.setFillColor(sf::Color::Red);
        }else {
            ball1.setFillColor(sf::Color::Green);
            ball2.setFillColor(sf::Color::Blue);
        }

        ball1.setPosition(pos1);
        ball2.setPosition(pos2);

        window.clear();
        window.draw(ball1);
        window.draw(ball2);
        window.display();
    }
}
