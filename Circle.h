#pragma once
#include "IShape.h"
#include <stdio.h>
#include <stdlib.h>

class Circle : IShape {
	float r = 0;
	float size = 0;
public:
	void Size() override;
	void Draw() override;
};
