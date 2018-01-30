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

void Image::imgThresholding() {
    for(int i = 0; i < number_cols; ++i) {
        for(int j = 0; j < number_rows; ++j){
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

