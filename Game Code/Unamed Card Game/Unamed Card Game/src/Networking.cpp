#include "Networking.h"

Networking::Networking()
{

}

Networking::~Networking()
{
}

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
