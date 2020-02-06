#pragma once
#include "BufferCPU.h"

// The structure of each Vertex
// Each vertex has a position
// and a UV texture coordinate
struct VertexBasic
{
	// X, Y, and Z axis for 3D position
	float position[3];

	// X and Y, for 2D Texture coordinate
	float uv[2];

	// X, Y, and Z directions for normal
	float normal[3];

	// get the state
	static VkPipelineVertexInputStateCreateInfo GetState();
};

