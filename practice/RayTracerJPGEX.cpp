#include <iostream>
#include <fstream>
#include "./lib/color.h"
#include "./lib/vec3.h"

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb/stb_image.h"
#include "stb/stb_image_resize.h"
#include "stb/stb_image_write.h"

using namespace std;

int main() {
    int width = 256, height = 256, channels = 3;
    // stbi_load returns a pointer to an unsigned char* buffer. The size of this buffer is width * height * channels
    // image data is stored in the buffer in row order, width * channels bytes belong to the first row image
    unsigned char* img = (unsigned char *) malloc(sizeof(char) * width * height * channels);

    unsigned char* p = img;
    for (int i=height-1;i>=0;--i) {
        for (int j=0;j<width;j++) {
            auto r = double(j) / (width-1);
            auto g = double(i) / (height-1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);
            *p = (uint8_t) ir;
            *(p+1) = (uint8_t) ig;
            *(p+2) = (uint8_t) ib;
            p += 3;
        }
    }

    cout << "Loading iamge\n";
    cout << "\twidth = " << width << "\n";
    cout <<"\theight = " << height << "\n";
    cout << "\tchannels = " << channels << "\n";

    stbi_write_jpg("FirstExample.jpg", width, height, channels, img, 100 /* Quality = 100 */);

    stbi_image_free(img);
    return 0;
}