#pragma once
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class Network
{
private:
	TcpListener Listener;
	TcpSocket cSocket;
	bool isRun = false;
public:
	Network();
	void InitPort();
	void NewConnection();
	void LogOut();
	void Run();
};

