#include <iostream>

#include <vector>
using std::vector;

#include "../include/image.h"

Image::Image() {

}     

Image::Image(int numRows, int numCols, int maxColor) {
    number_rows = numRows;
    number_cols = numCols;
    max_color = maxColor;  
}     

Image::~Image() {

}    

int Image::getNumberRows() {
    return number_rows;
}

void Image::setNumberRows(int numRows) {
    number_rows = numRows;
}

int Image::getNumberCols() {
    return number_cols;
}

void Image::setNumberCols(int numCols) {
    number_cols = numCols;
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
    for (int i = 0; i < number_rows; ++i) {
        for (int j = 0; j < number_cols; ++j) {
            temp[i][j].setR(old[i][j].getR());
            temp[i][j].setG(old[i][j].getG());
            temp[i][j].setB(old[i][j].getB());
        }
    }
}

void Image::imgThresholding() {
    for (int i = 0; i < number_rows; ++i) {
        for (int j = 0; j < number_cols; ++j){
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
    matrix temp(number_rows,vector<Pixel>(number_cols, p));

    copy_pixels(temp, pixels);

    for (int i = 1; i < number_rows - 1; ++i) {
        for (int j = 1; j < number_cols - 1; ++j) { 
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
    matrix temp(number_rows,vector<Pixel>(number_cols, p));

    copy_pixels(temp, pixels);

    for (int i = 1; i < number_rows - 1; ++i) {
        for (int j = 1; j < number_cols - 1; ++j) { 
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
    matrix temp(number_rows,vector<Pixel>(number_cols, p));

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
    }
}

matrix Image::rotate90(matrix temp) {
    for (int i = 1; i < number_rows - 1; ++i) {
        for (int j = 1; j < number_cols - 1; ++j) { 
            pixels[i][j] = temp[number_rows-j-1][i];
        }
    }

    return pixels;
}

void Image::borderDetection() {
    Pixel p;
    matrix temp(number_rows,vector<Pixel>(number_cols, p));

    copy_pixels(temp, pixels);

    for (int i = 1; i < number_cols - 1; ++i) {
        for (int j = 1; j < number_rows - 1; ++j) { 
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