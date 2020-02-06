Scene tutorial

We want the entire scene to be built and edited from outside 
Demo.cpp, so that people dont need to scroll through Vulkan
code to build a game.

Inside Scene.cpp, all Meshes, Textures, and Entities,
can be added, removed, drawn, and updated.

To do this, we need an abstraction layer that lets 
Demo handle anything that the Scene can do.

Demo is now a singleton, so it can be accessed
from anywhere. That means we dont need to pass 
a pointer of Demo to Scene, Mesh, Entity, or Texture

We initialize Scene in Demo.cpp, after initCmd 
starts recording commands, and before it ends.
After Scene is created, the initCmd buffer ends,
executes, and then deletes CPU buffers after they
are copied to GPU (convered in previous tutorial)

While the secondary command buffer is being built,
it calls Scene->Draw to add the Scene's entities to
the command buffer. When Scene->Draw ends, the
secondary command buffer is finalized

Scene::Draw calls new functions in Demo:
	4 functions to apply different pipelines
	1 function to draw each entity

In Demo::draw, all entities are updated by calling
Scene->Update

When Demo::~Demo is called, at the end of the demo,
Scene::~Scene is called, to destroy all entities, textures,
and meshes