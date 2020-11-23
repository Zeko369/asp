#include "Point.h"

void Point::mirrorX(double xVal) { x = xVal - (x - xVal); }
void Point::mirrorY(double yVal) { y = yVal - (y - yVal); }
