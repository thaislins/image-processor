#include "../include/ppmreader.h"
#include "../include/ppmwriter.h"
#include "../include/pixel.h"

int main() {

    PPMReader ppm_reader("lena.ppm");
    Image ppm_image = ppm_reader.readFile();
    ppm_image.imgBlurring();
    PPMWriter ppm_writer("blurr.ppm", ppm_image);
    ppm_writer.writeFile(ppm_image.getPixels());
    return 0;
}