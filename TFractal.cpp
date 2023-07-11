
#include "TFractal.hpp"

using namespace std;

TFractal::TFractal(int d, int l, bool rot)
{
    int size = l;
    depth = d;
    int i = 0;
    bool isRotate = rot;
    sf::RenderWindow window(sf::VideoMode(1680, 1050), "Triangles");
    W = window.getSize().x;
    H = window.getSize().y;
    AddTriangle(i, size, W / 2, (H / 2) - (H / 8));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        if (isRotate)
        {
            for (auto &t : triVec)
            {
                t.getTriangle().rotate(2.5f);
            }
        }
        for (auto &t : triVec)
        {
            window.draw(t.getTriangle());
        }
        window.display();
    }
}

void TFractal::AddTriangle(int o, int l, int x, int y)
{
    Triangle t(l, x, y);
    int d = o;
    triVec.push_back(t);
    if (d >= depth)
    {
        return;
    }

    AddTriangle(d + 1, l / 2, x + (l - ((l / 2) - ((l / 8) + (l / 16)))), y - (l / 2 + (l / 4))); //T
    AddTriangle(d + 1, l / 2, x + (l + (l / 8)), y + (l + (l / 2)));                              //BR
    AddTriangle(d + 1, l / 2, x - (l + (l / 16)), y + (l - (l / 4)));                             //BL
}

int main(int argc, char *argv[])
{
    int dep, base;
    bool r = false;
    
    if (argc > 2)
    {
        dep = atoi(argv[1]);
        base = atoi(argv[2]);
        if (argc > 3)
        {
            if (*argv[3] == 'r')
            {
                cout << "here" << endl;
                r = true;
            }
        }
    }
    else
    {
        dep = 8;
        base = 120;
    }
    TFractal(dep, base, r);
    return -1;
}
