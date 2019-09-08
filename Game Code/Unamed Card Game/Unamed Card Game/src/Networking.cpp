#include "Networking.h"

Networking::Networking()
{

}

Networking::~Networking()
{
}

/*! \fn OpenServer : Used to open a server for a client to be connected. */
int Networking::m_OpenServer()
{
	m_Listener.reset(new sf::TcpListener());

	if (m_Listener->listen(53000) != sf::Socket::Done)
	{
		// Exit

		return 2; 
	}

	m_Socket.reset(new sf::TcpSocket());

	if (m_Listener->accept(*m_Socket) != sf::Socket::Done)
	{
		// Exit 

		return 2;
	}

	std::cout << "Connected to client." << std::endl;

	return 0;
}

/*! \fn ConnectToServer : Used to form a connection to a server. */
int Networking::m_ConnectToServer()
{
	m_Socket.reset(new sf::TcpSocket());

	sf::Socket::Status l_Status = m_Socket->connect(sf::IpAddress::getLocalAddress(), 53000);

	if (l_Status != sf::Socket::Done)
	{
		// Exit

		return 2;
	}

	std::cout << "Connected to Server." << std::endl;

	return 0;
}

/*! \fn Used to send a message to the other connected person. */
void Networking::m_SendMessage()
{
}
