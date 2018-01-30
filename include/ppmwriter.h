#include <fstream>
using std::ofstream;

#include <string>
using std::string;

#ifndef PPMWRITER_H
#define PPMWRITER_H

#include "../include/image.h"

class PPMWriter {
protected:
    Image new_image;
    ofstream image_file;
    string filename;
public:
    PPMWriter(string f_name, Image image);
    void writeFile(matrix pixels);
};

#endif