#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"

#include <iostream>

/*! \class This will be used to connect two systems together, a single server and one client. */
class Networking
{
	// Constructor 

public:

	Networking();

	// Deconstructor 

	~Networking();

	// Data Members 

private:
	/*! \var The server side listener which will host the connection for the client. */
	std::unique_ptr<sf::TcpListener> m_Listener; 

	/*! \var The socket which will allow for the conection between the client and the server. */
	std::unique_ptr<sf::TcpSocket> m_Socket; 
	
	/*! \var The data which will be use to send messages between the client and the server. */
	std::unique_ptr<sf::Packet> m_Packet; 

	// Member Functions 

public:

	/*! \fn OpenServer : Used to open a server for a client to be connected. */
	int m_OpenServer();

	/*! \fn ConnectToServer : Used to form a connection to a server. */
	int m_ConnectToServer(); 

	/*! \fn Used to send a message to the other connected person. */
	void m_SendMessage(); 
};