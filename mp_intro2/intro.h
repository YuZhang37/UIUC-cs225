#pragma once

#include "cs225/PNG.h"

#include <string>

void rotate(std::string inputFile, std::string outputFile);
cs225::PNG myArt(unsigned int width, unsigned int height);
int get_distance(unsigned x, unsigned y, unsigned center_x, unsigned center_y);
