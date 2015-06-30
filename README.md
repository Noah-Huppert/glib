#Glib
An OpenGl library.  
*Note: The code currently on this branch does not reflect the design below, currently refactoring*

#TODO
- Move everything to namespaces

#Design Strategy
I am determining how to break up Glib based on a recent [OpenGl endeavor](https://github.com/Noah-Huppert/HelloGl/). 
I will be taking the parts that I think I can split up and making them into modules for Glib.

At least initially the lifetime of an app will not be directly managed by Glib. Instead a series of helpers modules will
be made. 

#Structure
Everything is in the `Glib` namespace

##Window
**Jobs**  
- Manages OpenGl context binding
- Creates window with GLFW
- Handles window events from GLFW

**Members**
- shared_ptr<GLFWwindow> mGLFWWindow
- WindowEventHandler mWindowEventHandler

**Methods**
- Constructor
 - Sets basic window properties like width and height, along with the window title
- InitWindow
 - Initializes GLFW
 - Creates a window with GLFW
 - Binds the current Gl context to the window
- BindEventHandler
 - Sets the window event handler
  - This handler handles key presses and other window events

##WindowEventHandler
**Jobs**
- Handles key presses
- Handles GLFW errors

**Methods**
- GLFWErrorCallback
 - Handles GLFW errors
- KeyCallback
 - Handles key press events