#include "Network.h"

Network::Network()
{
	
}

//Initialize
void Network::InitPort()
{
	if (this->Listener.listen(7895) == Socket::Status::Done)
	{
		this->isRun = true;
		cout << "Server is started at port: " << this->Listener.getLocalPort() << "\n" << endl;
	}

	else
		cout << "Error while binding port." << endl;
}

//Handle new client connection
void Network::NewConnection()
{
	if (this->Listener.accept(this->cSocket) == Socket::Status::Done)
		cout << "New connection from " << this->cSocket.getRemoteAddress() << ":" << this->cSocket.getRemotePort() << endl;
}

//Handle client disconnection : Not working for now
void Network::LogOut()
{
	// TODO
	//if(this->cSocket.Disconnected)
		//cout << "Logout from " << this->cSocket.getRemoteAddress() << ":" << this->cSocket.getRemotePort() << endl;
}

void Network::Run()
{
	NewConnection();
	LogOut();
}