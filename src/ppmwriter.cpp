#include "../include/ppmwriter.h"

PPMWriter::PPMWriter(string f_name, Image image) {
    filename = f_name;
    new_image = image;
}

void PPMWriter::writeFile(matrix pixels) {

    image_file.open(filename, std::ios::binary);

    image_file << "P3" << "\n";
    image_file << new_image.getNumberCols() << "\n";
    image_file << new_image.getNumberRows() << "\n"; 
    image_file << new_image.getMaxColor() << "\n";

    for(int i = 0; i < new_image.getNumberRows(); ++i) {
        for(int j = 0; j < new_image.getNumberCols(); ++j){
            image_file << pixels[i][j].getR() << " ";
            image_file << pixels[i][j].getG() << " ";
            image_file << pixels[i][j].getB() << " ";
        }
    } 

    image_file.close(); 
}