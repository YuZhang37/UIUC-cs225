#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>
#include <cmath>

int get_distance(unsigned int i, unsigned int j, unsigned int x, unsigned int y);

using namespace cs225;

void rotate(std::string inputFile, std::string outputFile) {
    PNG png1{};
    png1.readFromFile(inputFile);
    for (unsigned i = 0; i < (png1.width() + 1) >> 1; i++) {
        for (unsigned j = 0; j < png1.height(); j++) {
            HSLAPixel &cur_p = png1.getPixel(i, j);
            HSLAPixel temp_p = cur_p;
            HSLAPixel &mirror_p = png1.getPixel(png1.width() - i - 1, png1.height() - j - 1);
            cur_p = mirror_p;
            mirror_p = temp_p;
        }
    }
    png1.writeToFile(outputFile);
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
    cs225::PNG png(width, height);
    HSLAPixel pixels[] {
        HSLAPixel(201, 1.0, 50, 1),
        HSLAPixel(115, 1.0, 50, 1),
        HSLAPixel(8, 1.0, 50, 1)
    };
    int num_of_pixels = 3;
    unsigned center_x = png.width() >> 1;
    unsigned center_y = png.height() >> 1;
    int region_width = 50;
    for (unsigned i = 0; i < png.width(); i++) {
        for (unsigned j = 0; j < png.height(); j++) {
            int distance = get_distance(i, j, center_x, center_y);
            int region_index = distance / region_width;
            if (distance % region_width != 0) {
                region_index++;
            }
            HSLAPixel &cur_p = png.getPixel(i, j);
            cur_p = pixels[region_index % num_of_pixels];
        }
    }
    return png;
}

int get_distance(unsigned i, unsigned j, unsigned x, unsigned y) {
    int dist_x = i > x ? (int) (i - x) : (int) (x - i);
    int dist_y = j > y ? (int) (j - y) : (int) (y - j);
    double distance = std::sqrt(dist_x * dist_x + dist_y * dist_y);
    return std::ceil(distance);
}

