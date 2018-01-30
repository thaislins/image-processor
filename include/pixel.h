#include <vector>

#ifndef PIXEL_H
#define PIXEL_H

class Pixel {
protected:                       
    int R, G, B;
public:
    Pixel();
    ~Pixel();

    int getR();
    void setR(int r);
    int getG();
    void setG(int g);
    int getB();
    void setB(int b);
};

#endif