//NOLINT
#ifndef _TFractal
#define _TFractal


#include "Triangle.hpp"

#include <vector>
#include <iostream>

using namespace std;

class TFractal{
    public:
        //size / depth
        TFractal(int, int, bool);
        //size / depth / x / y
        void AddTriangle(int, int, int, int);

    private:
        //point to base triangle.
        //Triangle *tPtr [0];
        vector<Triangle> triVec;
        int depth;

        //screen size
        int W = 1024;
        int H = 612;
};

#endif