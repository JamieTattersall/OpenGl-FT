#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

//source for vertex 
GLfloat vertices[] =
{
	-0.5f, -0.5f * float(sqrt(3)) / 3,0.0f,
	0.5f, -0.5f * float(sqrt(3)) / 3,0.0f,
	0.0f, 0.5f * float(sqrt(3)) / 3,0.0f,

};



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

	//making vertx shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);



	GLuint VAO, VBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	





	// Declaring the color
	glClearColor(0.17f, 0.20f, 0.27f, 1.0f);

	//Sets the color as the back buffer
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Swaps the back biffer to front render
	glfwSwapBuffers(window);

	//  While window isnt closed run window -- Just makes it that the window constantly runs -- Other wise would just flash for a frame 
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.17f, 0.20f, 0.27f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);




		glfwPollEvents();
	}

	// Destroy the window and terminate glfw

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}