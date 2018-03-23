#include <iostream>

#include <vector>
using std::vector;

#include "../include/image.h"

Image::Image() {

}     

Image::Image(int height, int width, int maxColor) {
    this->height = height;
    this->width = width;
    max_color = maxColor;  
}     

Image::~Image() {

}    

int Image::getHeight() {
    return height;
}

void Image::setHeight(int height) {
    this->height = height;
}

int Image::getWidth() {
    return width;
}

void Image::setWidth(int width) {
    this->width = width;
}

int Image::getMaxColor() {
    return max_color;
}

void Image::setMaxColor(int maxColor) {
    max_color = maxColor;
}

matrix Image::getPixels() {
    return pixels;
}

void Image::setPixels(matrix pix) {
    pixels = pix;
}

void Image::copy_pixels(matrix &temp, matrix &old) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            temp[i][j].setR(old[i][j].getR());
            temp[i][j].setG(old[i][j].getG());
            temp[i][j].setB(old[i][j].getB());
        }
    }
}

void Image::imgThresholding() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j){
            int rgb_value = 0;
            if (((pixels[i][j].getR() + pixels[i][j].getG() + pixels[i][j].getB())/3) > 127) {
                rgb_value = max_color;
            } 

            pixels[i][j].setR(rgb_value);
            pixels[i][j].setG(rgb_value);
            pixels[i][j].setB(rgb_value);  
        }
    }
}

void Image::imgBlurring() {
    Pixel p;
    matrix temp(height,vector<Pixel>(width, p));

    copy_pixels(temp, pixels);

    for (int i = 1; i < height - 1; ++i) {
        for (int j = 1; j < width - 1; ++j) { 
            pixels[i][j].setR((temp[i][j].getR() + temp[i-1][j-1].getR() + temp[i-1][j].getR() + 
             temp[i-1][j+1].getR() + temp[i][j-1].getR() + temp[i][j+1].getR() +
             temp[i+1][j-1].getR() + temp[i+1][j].getR() + temp[i+1][j+1].getR())/9);

            pixels[i][j].setG((temp[i][j].getG() + temp[i-1][j-1].getG() + temp[i-1][j].getG() + 
             temp[i-1][j+1].getG() + temp[i][j-1].getG() + temp[i][j+1].getG() +
             temp[i+1][j-1].getG() + temp[i+1][j].getG() + temp[i+1][j+1].getG())/9);

            pixels[i][j].setB((temp[i][j].getB() + temp[i-1][j-1].getB() + temp[i-1][j].getB() + 
             temp[i-1][j+1].getB() + temp[i][j-1].getB() + temp[i][j+1].getB() +
             temp[i+1][j-1].getB() + temp[i+1][j].getB() + temp[i+1][j+1].getB())/9);
        }
    }
}

void Image::imgSharpening() {
    Pixel p;
    matrix temp(height,vector<Pixel>(width, p));

    copy_pixels(temp, pixels);

    for (int i = 1; i < height - 1; ++i) {
        for (int j = 1; j < width - 1; ++j) { 
            pixels[i][j].setR(5*temp[i][j].getR() - temp[i-1][j-1].getR()  
             - temp[i-1][j+1].getR() - temp[i+1][j-1].getR() - temp[i+1][j+1].getR());
            pixels[i][j].setR(pixels[i][j].getR() < 0 ? 0 : pixels[i][j].getR()); 
            pixels[i][j].setR(pixels[i][j].getR() > max_color ? max_color : pixels[i][j].getR());

            pixels[i][j].setG(5*temp[i][j].getG() - temp[i-1][j-1].getG()  
             - temp[i-1][j+1].getG() - temp[i+1][j-1].getG() - temp[i+1][j+1].getG());
            pixels[i][j].setG(pixels[i][j].getG() < 0 ? 0 : pixels[i][j].getG()); 
            pixels[i][j].setG(pixels[i][j].getG() > max_color ? max_color : pixels[i][j].getG());


            pixels[i][j].setB(5*temp[i][j].getB() - temp[i-1][j-1].getB()  
               - temp[i-1][j+1].getB() - temp[i+1][j-1].getB() - temp[i+1][j+1].getB());
            pixels[i][j].setB(pixels[i][j].getB() < 0 ? 0 : pixels[i][j].getB()); 
            pixels[i][j].setB(pixels[i][j].getB() > max_color ? max_color : pixels[i][j].getB());
        }
    }
}

void Image::imgRotate(int angle) {
    Pixel p;
    matrix temp(height,vector<Pixel>(width, p));

    copy_pixels(temp, pixels);

    if (angle == 90) {
        pixels = rotate90(temp);
    } else if (angle == 180) {
        temp = rotate90(temp);
        pixels = rotate90(temp);
    } else if (angle == 270) {
        temp = rotate90(temp);
        pixels = rotate90(temp);
        temp = rotate90(pixels);
        pixels = temp;
    } else {
        std:: cout << "Invalid" << std::endl;
        exit(0);
    }
}

matrix Image::rotate90(matrix temp) {
    for (int i = 1; i < height - 1; ++i) {
        for (int j = 1; j < width - 1; ++j) { 
            pixels[i][j] = temp[height-j-1][i];
        }
    }

    return pixels;
}

void Image::extraFilter() {
    Pixel p;
    matrix temp(height,vector<Pixel>(width, p));

    copy_pixels(temp, pixels);

    for (int i = 1; i < width - 1; ++i) {
        for (int j = 1; j < height - 1; ++j) { 
            pixels[i][j].setR(8*temp[i][j].getR() - temp[i-1][j-1].getR()  
             - temp[i-1][j+1].getR() - temp[i+1][j-1].getR() - temp[i+1][j+1].getR());
            pixels[i][j].setR(pixels[i][j].getR() < 0 ? 0 : pixels[i][j].getR()); 
            pixels[i][j].setR(pixels[i][j].getR() > max_color ? max_color : pixels[i][j].getR());

            pixels[i][j].setG(8*temp[i][j].getG() - temp[i-1][j-1].getG()  
             - temp[i-1][j+1].getG() - temp[i+1][j-1].getG() - temp[i+1][j+1].getG());
            pixels[i][j].setG(pixels[i][j].getG() < 0 ? 0 : pixels[i][j].getG()); 
            pixels[i][j].setG(pixels[i][j].getG() > max_color ? max_color : pixels[i][j].getG());


            pixels[i][j].setB(8*temp[i][j].getB() - temp[i-1][j-1].getB()  
               - temp[i-1][j+1].getB() - temp[i+1][j-1].getB() - temp[i+1][j+1].getB());
            pixels[i][j].setB(pixels[i][j].getB() < 0 ? 0 : pixels[i][j].getB()); 
            pixels[i][j].setB(pixels[i][j].getB() > max_color ? max_color : pixels[i][j].getB());
        }
    }
}