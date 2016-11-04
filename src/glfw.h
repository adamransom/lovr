#ifdef EMSCRIPTEN
#define GLFW_INCLUDE_ES2
#elif __APPLE__
#define GLFW_INCLUDE_GLCOREARB
#elif _WIN32
#include <GL/glew.h>
#endif

#include <GLFW/glfw3.h>

GLFWwindow* window;

void initGlfw();
