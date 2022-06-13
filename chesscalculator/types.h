#pragma once
#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

// In order to easy use
struct xyTuple
{
	int x;
	int y;
};

enum color {
	WHITE,
	BLACK
};

enum blockType {
	NONE,
	BLOCK,
	BLOCK_WITH_THREAT
};

#endif // !TYPES_H_INCLUDED
