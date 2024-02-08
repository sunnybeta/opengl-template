// https://gen.glad.sh/#generator=c&api=gl%3D4.6&profile=gl%3Dcore%2Cgles1%3Dcommon
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
 
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define SQUARE_SIZE   100
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 800

#define TRY(_k, ...) if(!_k) {fprintf(stderr, __VA_ARGS__); exit(EXIT_FAILURE);}


void error_callback(int error, const char* description) {
	fprintf(stderr, "Error %d: %s\n", error, description);
}
 
void process_input(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}
 
int main(void) {
	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);
	TRY(glfwInit(), "Init Failed\n");
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Chester", NULL, NULL);
	if (!window) { glfwTerminate(); exit(EXIT_FAILURE); }
	glfwMakeContextCurrent(window);
	TRY(gladLoadGL(glfwGetProcAddress), "I am not glad");
	while (!glfwWindowShouldClose(window)) {
		process_input(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
