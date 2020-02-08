all:
	g++ main.cpp BlinkyGhost.cpp Data.cpp Engine.cpp Event.cpp Ghost.cpp PacMan.cpp PinkyGhost.cpp RandomGhost.cpp View.cpp -o PacMan.exe -DSFML_STATIC -I C:\Users\konra\CLionProjects\PACMAN_WINDOWS_SFML\SFML\include -L C:\Users\konra\CLionProjects\PACMAN_WINDOWS_SFML\SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype
