sudo g++ -std=c++11 main.cpp src/Icosahedron.cpp src/IndexBuffer.cpp src/VertexArray.cpp src/Buffer.cpp src/BatchRenderer2D.cpp src/sprite.cpp src/Shader.cpp src/Window.cpp src/vec2.cpp src/vec3.cpp src/vec4.cpp src/mat4.cpp -o main -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor -lGL -lGLEW 

sudo ./main
