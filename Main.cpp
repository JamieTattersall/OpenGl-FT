#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
	glfwInit();

	// Saying we are using the core profile + VERSIONS
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
	
	// Declaring window size and GLFWwindow variable
	GLFWwindow* window = glfwCreateWindow(800, 800, "New window", nullptr, nullptr);

	// If window doesnt load function
	if (window == NULL)
	{
		std::cout << "Failed to create window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	//  Loads glad into open GL
	gladLoadGL();

	//  Specifying the viewport of OpenGL in the window
	glViewport(0, 0, 800, 800);

	// Declaring the color
	glClearColor(0.17f, 0.20f, 0.27f, 1.0f);

	//Sets the color as the back buffer
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Swaps the back biffer to front render
	glfwSwapBuffers(window);

	//  While window isnt closed run window -- Just makes it that the window constantly runs -- Other wise would just flash for a frame 
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	// Destroy the window and terminate glfw
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}