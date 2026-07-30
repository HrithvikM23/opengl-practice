#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

int main() {
	glfwInit();// Initialize GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);// Set the OpenGL version to 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);// Set the OpenGL profile to core
	GLFWwindow* window = glfwCreateWindow(1920, 1080, "Voxy", NULL, NULL);// Create a window with the specified width, height, and title, fullscreen or windowed as NULL, and no shared context
	// Check if the window was created successfully
	if (window == NULL) {
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}
	// Make the window's context current
	glfwMakeContextCurrent(window);
	// Load OpenGL function pointers using GLAD
	gladLoadGL();
	// Set the viewport to the size of the window
	glViewport(0, 0, 1920, 1080);
	// Set the clear color to a dark blue color
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);// Clear the color buffer
	glfwSwapBuffers(window);// Swap the front and back buffers
	// Main loop
	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);// Destroy the window
	glfwTerminate();// Terminate GLFW
	return 0;
}