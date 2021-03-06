#ifndef PCH_H
#define PCH_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include "Vector.h"

#define PI 3.1415926535

enum Color {
	Black, DarkBlue, DarkGreen, Cyan, DarkRed, Purple, DarkYellow, LightGray, Gray, Blue, Green, LightBlue, Red, Pink, Yellow, White
};

enum KeyState {
	None, Enter, Exit, Stay
};

#endif