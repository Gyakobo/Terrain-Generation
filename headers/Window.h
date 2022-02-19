#ifndef WINDOW_H                                                                                     
#define WINDOW_H

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define MAX_NUMB_OF_KEYS        1024
#define MAX_NUMB_OF_BUTTONS     32

using namespace std;

class Window {
private:
        const char *name;
        int width, height;
        GLFWwindow *window;
        bool window_Closed;

        bool init();

        bool Keys[MAX_NUMB_OF_KEYS];
        bool MouseButtons[MAX_NUMB_OF_BUTTONS];
        double x_mouse_pos, y_mouse_pos;

        // Declare as a friend
        friend void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
        friend void key_mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
        friend void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);

public:
        Window(const char *name, int width, int height);
        ~Window();

        bool closed()   const;
        void update();
        void clear()    const;

        int getWidth() const    { return width; }
        int getHeight() const   { return height; }

        static Window *INSTANCE;
    
        bool isKeyPressed(unsigned int keycode) const;
        bool isMouseButtonPressed(unsigned int button) const;
        void getMousePosition(float &x, float &y) const;
};

#endif
