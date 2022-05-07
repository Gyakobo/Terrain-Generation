#include "../headers/camera.h"

mat4 lookAt(vec3& eye, vec3& center, vec3& up) {
    mat4 returnMatrix;

    vec3 x, y, z;
    z = eye - center;
    z.normalize();
    y = up;
    x = vec3::CrossProduct(y, z);
    y = vec3::CrossProduct(z, x);
    x.normalize();
    y.normalize();

    returnMatrix.elements[0] =      x.x;
    returnMatrix.elements[1] =      x.y;
    returnMatrix.elements[2] =      x.z;
    returnMatrix.elements[3] =      vec3::DotProduct(vec3(-x.x, -x.y, -x.z), eye);

    returnMatrix.elements[4] =      y.x;
    returnMatrix.elements[5] =      y.y;
    returnMatrix.elements[6] =      y.z;
    returnMatrix.elements[7] =      vec3::DotProduct(vec3(-y.x, -y.y, -y.z), eye);

    returnMatrix.elements[8] =      z.x;
    returnMatrix.elements[9] =      z.y;
    returnMatrix.elements[10] =     z.z;
    returnMatrix.elements[11] =     vec3::DotProduct(vec3(-z.x, -z.y, -z.z), eye);

    returnMatrix.elements[12] =     0.0f;
    returnMatrix.elements[13] =     0.0f;
    returnMatrix.elements[14] =     0.0f;
    returnMatrix.elements[15] =     1.0f;

    return returnMatrix;
}

Camera::Camera(int width, int height, vec3 position) {
    this->width     = width;
    this->height    = height;
    this->position  = position;
}

void Camera::Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform) {
    mat4 view       = mat4(1.0f);
    mat4 projection = mat4(1.0f);

    view =          lookAt(position, position + Orientation, Up);
    //projection =    mat4::perspective(FOVdeg, (float)(width/height), nearPlane, farPlane); //We already have a projection matrix

    shader.setUniformMat4(uniform, (projection * view));

}

void Camera::Inputs(GLFWwindow* window) {

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        position += vec3::product(speed, Orientation);
    }
    
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        position += vec3::product(-speed, Orientation);
    }

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        vec3 subvector = vec3::normalize(vec3::CrossProduct(Orientation, Up));
        position += vec3::product(-speed, subvector);
    }

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        vec3 subvector = vec3::normalize(vec3::CrossProduct(Orientation, Up));
        position += vec3::product(speed, subvector);
    }

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        position += vec3::product(speed, Up);
    }

    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
        position += vec3::product(-speed, Up);
    }

    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        speed = 0.4f;
    }

    else if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_RELEASE) {
        speed = 0.1f;
    }
}





