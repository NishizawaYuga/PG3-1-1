#pragma once
#include "IShape.h"
#include <stdio.h>
#include <stdlib.h>

class Rectangle : IShape {
	float x = 0;
	float y = 0;
	float size = 0;
public:
	void Size() override;
	void Draw() override;
};
