#ifndef LAB_INTRO_H
#define LAB_INTRO_H

#include "cs225/PNG.h"
using namespace cs225;

PNG grayscale(PNG image);
double calc_distance(unsigned x, unsigned y, int centerX, int centerY);
PNG createSpotlight(PNG image, int centerX, int centerY);

bool is_closer_to_orange(double h);
double get_min_distance_in_circle(double loc1, double loc2);
PNG illinify(PNG image);
PNG watermark(PNG firstImage, PNG secondImage);

// for illiny
const double illini_orange = 11, illini_blue = 216, max_range = 360;

// for spotlight
const double decr_ratio = 0.005;

// for watermark
const double incr_lumi = 0.2;
const double max_lumi = 1.0;
#endif