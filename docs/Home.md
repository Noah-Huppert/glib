##The Idea behind GLIB
GLIB is not meant to be a "Do it all" engine like Unity 3D. Instead I will be writing GLIB to directly mirror my needs as a developer. 

##Modules
- [Core](#core)
- [2D](#2d)
- [3D](#3d)
- [Helpers](#helpers)

##Core
**Namespace**: *glib::core*  
**Description**: *This GLIB Core will provide basic functionality such as basic rendering and input handling. The GLIB Core will only handle the basic render process to the point where users can input a array of vertices and they will be rendered. The GLIB Core will handle window input with a basic callback*

##2D
**Namespace**: *glib::2d*  
**Description**: *The GLIB 2D module will handle 2D rendering functions. These include Keyframe animation(?), Texture Mapping, and Obscuring z layer.*

##3D
**Namespace**: *glib::3d*  
**Description**: *The GLIB 3D module will handle 3D rendering functions. These include Animations, and Texture Mapping.*

##Helpers
**Namespace**: *glib::helpers*  
**Descriptions**: *The GLIB Helper Module will have many helper functions. These functions include 2D and 3D transformations and other helpers I will create during the creating of the engine.*