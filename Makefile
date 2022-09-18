all:
	g++ main.cpp include/*.cpp -IC:/SFML-2.5.1/include -IC:/glm-master -IC:/glfw-3.3.8/include -IC:/Programming/C++/Projects/SFML/openGL_testing/include -o build/app.exe -LC:/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
	clear
	./build/app.exe