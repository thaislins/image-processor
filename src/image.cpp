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

/*Image::Image(const Image& oldImage) {

}

void Image::operator=(const Image&) {

}*/

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

