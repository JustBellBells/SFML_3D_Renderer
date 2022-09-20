all:
	mkdir build -p
	g++ main.cpp include/*.cpp -Iinclude/SFML-2.5.1/include -Iinclude/glm-master -Iinclude/glfw-3.3.8/include -o build/app.exe -Linclude/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
	clear
	./build/app.exe
run:
	./build/app.exe