#pragma once
#include "ECS.h"
class PositionComponets : public Component
{
private:
	int xpos;
	int ypos;
public:
	int x() { return xpos; }
	int y() { return ypos; }

	void setPos(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void update() override {
		xpos++;
		ypos++;
	}
	void init() override {
		xpos = 0;
		xpos = 0;
	}

};

