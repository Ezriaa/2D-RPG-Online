#include "Game.h"
#include "Network.h"
#include <SFML/Network.hpp>

int main()
{
	//Initialisation
	Game Game;
	TcpSocket socket;
	Socket::Status status = socket.connect("127.0.0.1", 7895);

	//Game Loop
	while (Game.Running())
	{
		if (status != sf::Socket::Done)
			std::cout << "Connection error" << std::endl;

		else 
		{
			//Game Update
			Game.Update();

			//Game Render
			Game.Render();
		}
	}

	return 0;
}