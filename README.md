# image-processor
:mount_fuji: image (ppm) processing in c++

## Built With

* [C++](http://en.cppreference.com/w/) - Programming Language

## Author

[![Thais Lins](https://avatars.githubusercontent.com/thaislins?s=100)<br /><sub>Thais Lins</sub>](https://github.com/thaislins) 
| :---: | 

### Running the program

```
make all
./bin/ppmprocessor "image_name.ppm" "filter_name" 
```

### Available Filters

```
thresh         -- Image Thresholding
blurr          -- Image Blurring
sharp          -- Image Sharpening
rotate 	       -- Image Rotation (90°, 180° or 270°)
extra-filter   -- Adds an extra filter to the image
```
