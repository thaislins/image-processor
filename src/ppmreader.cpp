#include <iostream>
#include <fstream>
#include <vector>

#include "../include/ppmreader.h"
#include "../include/pixel.h"

PPMreader::PPMreader(string f_name) {
    filename = f_name;
}

Image PPMreader::readFile() {
    int number_cols, number_rows, max_color;
    std::string header;
    int R, G, B;
    Pixel p;

    image_file.open(filename, std::ios::binary);

    if (!image_file) {
        std::cout << "Can't read ppm_image: " << filename << std::endl;
        exit(1);
    }

    image_file >> header >> number_cols >> number_rows >> max_color;
    Image ppm_image(number_cols,number_rows,max_color);
    matrix pixels(number_cols,vector<Pixel>(number_rows, p));

    for(int i = 0; i < number_cols; i++) {
        for(int j = 0; j < number_rows; j++){
            image_file >> R >> G >> B;
            pixels[i][j].setR(R);
            pixels[i][j].setG(G);
            pixels[i][j].setB(B);
        }
    }

    ppm_image.setPixels(pixels);
    image_file.close();

    return ppm_image;
}


int main() {

    PPMreader ppm_reader("lena.ppm");
    Image ppm_image = ppm_reader.readFile();

    return 0;
}