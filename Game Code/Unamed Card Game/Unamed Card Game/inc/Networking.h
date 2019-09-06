#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"

#include <iostream>

class Networking
{
	// Constructor 

public:

	Networking();

	// Deconstructor 

	~Networking();

	// Data Members 

private:

	std::unique_ptr<sf::TcpListener> m_Listener; 

	std::unique_ptr<sf::TcpSocket> m_Socket; 
	
	std::unique_ptr<sf::Packet> m_Packet; 

	// Member Functions 

public:

	int m_OpenServer();

	int m_ConnectToServer(); 

	void m_SendMessage(); 
};