#ifndef SERVER_CONNECTION_H
#define SERVER_CONNECTION_H

#include <string>//
#include <GameState.h>
#include <SDL_net.h>
#include <OgreVector3.h>

class Game;

class ServerConnection {
public:
	ServerConnection(Game& game);
	~ServerConnection();
	
	void initialize();
	void destroy();
	
	void update();
	
	const GameState& getGameState() { return latest; }
	
	void move(const Ogre::Vector3& pos);
	
private:
	void sendText(std::string str);
	bool receivePacket();
	
	Game& game;
	
	UDPsocket socket;
	UDPpacket* packet;
	GameState latest;
	
	int myID;
	
};

#endif

    


