#include <iostream>
#include <fstream>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb/stb_image.h"
#include "stb/stb_image_resize.h"
#include "stb/stb_image_write.h"

using namespace std;

int main() {
    int width, height, channels;
    unsigned char* img = stbi_load("apple.jpg", &width, &height, &channels, 0);
    if (img == 0) {
        cout << "Error loading image file" << endl;
        return -1;
    }
    // stbi_load returns a pointer to an unsigned char* buffer. The size of this buffer is width * height * channels
    // image data is stored in the buffer in row order, width * channels bytes belong to the first row image

    // Lets set the first 10 rows to black
    for (unsigned char* p = img; p != img + 1000*width*channels; p += channels) {
        *p = (uint8_t) 0;
        *(p+1) = (uint8_t) 0;
        *(p+2) = (uint8_t) 0;
    }

    cout << "Loading iamge\n";
    cout << "\twidth = " << width << "\n";
    cout <<"\theight = " << height << "\n";
    cout << "\tchannels = " << channels << "\n";

    stbi_write_jpg("apple-copy.jpg", width, height, channels, img, 100 /* Quality = 100 */);

    stbi_image_free(img);
    return 0;
}