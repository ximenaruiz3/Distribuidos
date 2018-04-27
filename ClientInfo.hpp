/* 
 * File:   ClientInfo.hpp
 * Author: david
 *
 * Created on 1 de abril de 2017, 10:46 PM
 */

#ifndef CLIENTINFO_HPP
#define CLIENTINFO_HPP
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <time.h>
#include <cstdio>
#include <stdlib.h>
#include <pthread.h>
#include <sstream>
#include <vector>

using namespace std;
class ClientInfo {
private:
    int descriptorClient;
    struct sockaddr_in clientInfo;
    bool state;
    int id;
    vector<ClientInfo *> *maquinasImagen;
    vector<ClientInfo *> *maquinasVideo;
public:

    ClientInfo(int ,struct sockaddr_in);
    ~ClientInfo();

    int getId(void);
    void setId(int);

    int getDescriptorClient(void);
    struct sockaddr_in getClientInfo();

    bool getState(void);
    void setState(bool);

    vector<ClientInfo *> *getMaquinasImagen();
    vector<ClientInfo *> *getMaquinasVideo();
    void setMaquinasImagen(vector<ClientInfo *>*);
    void setMaquinasVideo(vector<ClientInfo *>*);

};
#endif /* CLIENTINFO_HPP */