#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
using namespace std;
#include <memory>

int main() {
    // Image

    const int image_width = 256;
    const int image_height = 256;

    // image_width = x, image_height = y
    int n =3;
    // unsigned char* data = stbi_load("apple.jpg", &image_width, &image_height, &n, 3);

    // Render

    cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j=image_height-1;j >= 0; --j) {
        cerr << "\rScanlines remaining: " << j << ' ' << flush;
        for (int i=0; i< image_width; ++i) {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    cerr << "\nDone.\n";
}

if (dot(ray_direction, outward_normal) > 0.0) {
    // ray is inside the sphere
} else {
    // ray is outside the sphere
}

// remembering the side of the surface
// have the normal always point against the array
bool front_face;
if (dot(ray_direction, outward_normal) > 0.0) {
    // ray is inside the sphere
    normal = -outward_normal;
    front_face = false;
} else {
    // ray is outside the sphere
    normal = outward_normal;
    front_face = true;
}

// set things up so that normals always poitn "outward" from the surface, or always point against the incident ray

// decision is determined by whether you want to determine the side of the surface at the time of geometry intersection
// or at the time of coloring.
// in this book we have more material types than we have geometry types, less work and put the determination at geometry time

// example allocation with a shared pointer
shared_ptr<double> double_ptr = make_shared<double>(0.37);
shared_ptr<vec3> vec3_ptr = make_shared<vec3>(1.41,2.71,1.62);
shared_ptr<sphere> sphere_ptr = make_shared<sphere>(point3(0,0,0), 1.0);

// An example allocation using shared_ptr with auto type
auto double_ptr = make_shared<double>(0.37);
auto vec3_ptr = make_shared<vec3>(1.41, 2.82, 1.62);
auto sphere_ptr = make_shared<sphere>(point3(0,0,0), 1.0);

// use shared pointers, allows multiple geometries to share a common isntance
