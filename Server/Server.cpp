#include "Network.h"

int main()
{
	Network Server;
	Server.InitPort();

	while (1)
	{
		Server.Run();
	}
}