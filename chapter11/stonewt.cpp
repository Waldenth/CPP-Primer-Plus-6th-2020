#include <iostream>
using std::cout;
#include "stonewt.h"

Stonewt::Stonewt(double lbs) {
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
}