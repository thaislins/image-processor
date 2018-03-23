#include <iostream>
#include <fstream>
#include <vector>

#include "../include/ppmreader.h"
#include "../include/ppmwriter.h"
#include "../include/pixel.h"

PPMReader::PPMReader(string f_name) {
    filename = f_name;
}

Image PPMReader::readFile() {
    int width;    //width
    int height;    //height
    int max_color;
    std::string header;
    int R, G, B;
    Pixel p;

    image_file.open(filename, std::ios::binary);

    if (!image_file) {
        std::cout << "Can't read image: " << filename << std::endl;
        exit(1);
    }

    image_file >> header >> width >> height >> max_color;
    Image ppm_image(height,width,max_color);
    matrix pixels(height,vector<Pixel>(width, p));

    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j){
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


