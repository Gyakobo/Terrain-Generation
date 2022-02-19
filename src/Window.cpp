#include "../headers/Window.h"

void WindowAdjust(GLFWwindow *window, int m_width, int m_height);
void key_callback(GLFWwindow *w_window, int key, int scancode, int action, int mods);
void key_mouse_button_callback(GLFWwindow *w_window, int button, int action, int mods); 
void cursor_position_callback(GLFWwindow *w_window, double xpos, double ypos);

Window::Window(const char *name, int width, int height) {
	this->name 	= name;
	this->width 	= width;
	this->height 	= height;
	if (!init()) glfwTerminate();
	
	for (int i=0; i<MAX_NUMB_OF_KEYS; i++) {
		Keys[i] = false;
	}
	for (int i=0; i<MAX_NUMB_OF_BUTTONS; i++) {
		MouseButtons[i] = false;
	}
}


Window::~Window() {
	glfwTerminate();
}

void WindowAdjust(GLFWwindow *window, int m_width, int m_height) {
	glViewport(0, 0, m_width, m_height);	
}

bool Window::init() {
	if(!glfwInit()) { 
		cout << "Error has occured, Cannot Initialize GLFW" << endl;
		return false;
	}

	window = glfwCreateWindow(width, height, name, NULL, NULL);
	if (!window) {
		cout << "Failed to Open Window" << endl;
		return false;
	}
	glfwMakeContextCurrent(window);
	glfwSetWindowUserPointer(window, this);	
	glfwSetWindowSizeCallback(window, WindowAdjust);
	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, key_mouse_button_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);

	if (glewInit() != GLEW_OK) {
		cout << "Glew Failed" << endl;
		return false;
	}

	return true;
}








bool Window::isKeyPressed(unsigned int keycode) const {
	if (keycode >= MAX_NUMB_OF_KEYS)
		return false;
	return Keys[keycode];
} 
bool Window::isMouseButtonPressed(unsigned int button) const {
	if (button >= MAX_NUMB_OF_BUTTONS)
		return false;
	return MouseButtons[button];
} 
void Window::getMousePosition(float &x, float &y) const {
	x = x_mouse_pos;	
	y = y_mouse_pos;	
}








void Window::clear() const {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Change me if needed
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}


void Window::update() {
	glfwPollEvents();
	glfwSwapBuffers(window);
}


bool Window::closed() const {
	if (glfwWindowShouldClose(window)) return true;
	else false;
}


void key_callback(GLFWwindow *w_window, int key, int scancode, int action, int mods) {
	Window* win = (Window*) glfwGetWindowUserPointer(w_window);
	win->Keys[key] = (action != GLFW_RELEASE);
}

void key_mouse_button_callback(GLFWwindow *w_window, int button, int action, int mods) {
	Window* win = (Window*) glfwGetWindowUserPointer(w_window);
	win->MouseButtons[button] = (action != GLFW_RELEASE);
}

void cursor_position_callback(GLFWwindow *w_window, double xpos, double ypos) {
	Window* win = (Window*) glfwGetWindowUserPointer(w_window);
	win->x_mouse_pos = xpos;	
	win->y_mouse_pos = ypos;	
}
