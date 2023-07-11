//NOLINT
#ifndef _Triangle
#define _Triangle


//C headers
#include <math.h>


//SFML headers
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

class Triangle : sf::Drawable
{
    public:
        //size / xPos / yPos
        Triangle(int,int,int);

        //special gets
        sf::CircleShape& getTriangle(){return triangle;}


        //reg gets n sets

        int getXPosition(){return xPos;}
        void setXPosition(int i){xPos = i;}

        int getYPosition(){return yPos;}
        void setYPosition(int i){yPos = i;}

        //dont think i need these ones...
        int getBaseSize(){return baseSize;}
        void setBaseSize(int i){baseSize = i;}

    private:
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const{
            //states.texture = &tex;
            target.draw(triangle, states);
        }
        int xPos, yPos;
        int baseSize;
        sf::CircleShape triangle;
};


#endif