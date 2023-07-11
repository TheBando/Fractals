
#include "Triangle.hpp"

Triangle::Triangle(int b,int x, int y){
    baseSize = b; xPos = x; yPos = y;
    triangle.setFillColor(sf::Color::Transparent);
    int r = (b+x)*2;
    int g = (y^b)*3;
    int bl = (x^y)*4;
    sf::Color c(r,g,bl);
    triangle.setOutlineColor(c);
    triangle.setOutlineThickness(1);
    triangle.setRadius(baseSize);
    //triangle.setRotation(60);
    //triangle.setPosition(xPos,yPos);
    triangle.setPointCount(3);
    triangle.setPosition(xPos,yPos);
    triangle.setOrigin(baseSize/2,0);
}