#pragma once
#include "BufferCPU.h"
#include "BufferGPU.h"
#include "Demo.h"

// forward declaration
class Demo;

class Mesh
{
public:
	// Mesh data
	BufferCPU* vertexDataCPU;
	BufferGPU* vertexDataGPU;
	BufferCPU* indexDataCPU;
	BufferGPU* indexDataGPU;

	Mesh(char* file, bool tangents);
	~Mesh();

	int numIndices;
	void LoadBasic(char* file);
	void LoadTangents(char* file);
};

