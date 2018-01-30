#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include "../include/image.h"

#ifndef PPMREADER_H
#define PPMREADER_H

class PPMReader {
protected:
    ifstream image_file;
    string filename;
public:
    PPMReader(string f_name);
    Image readFile();
};

#endif