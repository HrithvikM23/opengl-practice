#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

// Vertex shader source code
const char* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x,aPos.y,aPos.z, 1.0);\n"
	"}\0";

// Fragment shader source code
const char* fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
	"}\n\0";

// Called whenever the window is resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    // Initialize GLFW
    if (!glfwInit())
    {
        cout << "Failed to initialize GLFW" << endl;
        return -1;
    }

    // Configure GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLfloat vertices[] = {
        -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
         0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		 0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f  // Upper corner
	};

    // Create window
    GLFWwindow* window = glfwCreateWindow(800, 800, "Voxy", nullptr, nullptr);

    if (window == nullptr)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }

    // Make the OpenGL context current
    glfwMakeContextCurrent(window);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    // Set initial viewport
    glViewport(0, 0, 800, 800);

	// Create and compile shaders
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); 
	glCompileShader(vertexShader);
    
	// Check for shader compilation errors
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	// Check for shader compilation errors
	GLuint shaderProgram = glCreateProgram();

	// Attach shaders to the program
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	// Link the shader program
	glLinkProgram(shaderProgram);

	// Delete the shaders as they are no longer needed after linking
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// Create a Vertex Array Object (VAO) and a Vertex Buffer Object (VBO)
    GLuint VAO,VBO;
    
	// Generate 
	glGenVertexArrays(1, &VAO);

	// Generate and bind the VBO
	glGenBuffers(1, &VBO);

	// Bind the VAO first, then bind and set VBOs, and then configure vertex attributes.
    glBindVertexArray(VAO);

	// Bind the VBO to the GL_ARRAY_BUFFER target
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// Upload vertex data to the VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Define the vertex attribute pointer for position (location = 0)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	// Enable the vertex attribute array for position
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbind the VBO
	glBindVertexArray(0); // Unbind the VAO

    // Register resize callback
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Enable V-Sync (optional, prevents screen tearing)
    glfwSwapInterval(1);

    // Main render loop
    while (!glfwWindowShouldClose(window))
    {
        // Clear the screen
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
		// Use the shader program
		glUseProgram(shaderProgram);
		//  Bind the VAO
		glBindVertexArray(VAO);
		// Draw the triangle
		glDrawArrays(GL_TRIANGLES, 0, 3);
       
        // Present the frame
        glfwSwapBuffers(window);

        // Process window events
        glfwPollEvents();
    }

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}