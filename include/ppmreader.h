#include <sstream>
using std::ifstream;

#include <string>
using std::string;

#include "../include/image.h"

#ifndef PPMREADER_H
#define PPMREADER_H

class PPMreader {
protected:
    ifstream image_file;
    string filename;
public:
    PPMreader(string f_name);
    Image readFile();
};

#endif