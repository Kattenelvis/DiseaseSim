#include "Rectangle.h"

Rectangle::Rectangle(float x, float y, float width, float height, sf::Color c)
{
    this->color = c;
    this->x = x;
    this->y = y;
    this->width=width;
    this->height=height;
}

Rectangle::Rectangle()
{

}

sf::RectangleShape Rectangle::getRect()
{
    sf::RectangleShape rect(sf::Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(sf::Vector2f(x, y));
    return rect;
}

void Rectangle::Move(float dx, float dy)
{
    this->x += velVector[0];
    this->y += velVector[1];
}

void Rectangle::randomRotation(int tenthPercentileOdds, float rotation)
{
    int X = rand()%(9);
    if (X < tenthPercentileOdds)
    {
        rotateRect(rotation);
    }
}

void Rectangle::setVelocity(float x, float y)
{
    this->velVector[0] = x;
    this->velVector[1] = y;
}

#include <math.h>
float Rectangle::getSpeed()
{
    //Pythagorean theorem
    return sqrt(pow(velVector[0],2) + pow(velVector[1],2));
}

void Rectangle::rotateRect(float radians)
{
    //Linear transformation
    float velVector0 = velVector[0];
    this->velVector[0] = velVector[0]*cos(radians) + velVector[1]*sin(radians);
    this->velVector[1] = -velVector0*sin(radians) + velVector[1]*cos(radians);
}

#include "SFML/Window.hpp"
void Rectangle::avoidEdge()
{
    if(x + width > 1000 || x - width < 0)
    {
        velVector[0] *= -1;
    }

    if(y + height > 1000 || y - height < 0)
    {
        velVector[1] *= -1;
    }
}


