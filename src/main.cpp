#include <iostream>

#include "../include/ppmreader.h"
#include "../include/ppmwriter.h"
#include "../include/pixel.h"

void menu(Image &ppm_image, string &filter){
    if (filter.compare("thresh") == 0) { 
        ppm_image.imgThresholding();
    } else if (filter.compare ("blurr") == 0) {
        ppm_image.imgBlurring();
    } else if (filter.compare ("sharp") == 0) {
        ppm_image.imgSharpening();
    } else if (filter.compare ("rotate") == 0) {
        std::cout << "Enter angle to rotate: ";
        int angle;
        std::cin >> angle;
        filter = filter + std::to_string(angle);
        ppm_image.imgRotate(angle);
    } else if (filter.compare ("border-detect") == 0) {
        ppm_image.borderDetection();
    } else {
        std::cout << "Unidentified filter" << std::endl;
        exit(0);
    }
}


int main(int argc, char const *argv[]) {
    if(argc == 3) {
        string file = argv[1], filter = argv[2];
        PPMReader ppm_reader(file);
        Image ppm_image = ppm_reader.readFile();
        menu(ppm_image, filter);
        PPMWriter ppm_writer(filter + ".ppm", ppm_image);
        ppm_writer.writeFile(ppm_image.getPixels());
    } else {
        std::cout << "Not enough arguments!" << std::endl;
        std::cout << "Input ./bin/ppmprocessor image_name.ppm image_filter" << std::endl;
    }
    return 0;
}
