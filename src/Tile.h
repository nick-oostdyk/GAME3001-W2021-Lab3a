#pragma once
#ifndef __TILE__
#define __TILE__

#include "DisplayObject.h"

class Tile : public DisplayObject {

	private:
	
	public:

	private:

	public:

	// Constructor
	Tile();

	// Destructor
	~Tile();

	// Life-cycle functions
	void draw() override;
	void update() override;
	void clean() override;

};

#endif /* defined (__TILE__) */