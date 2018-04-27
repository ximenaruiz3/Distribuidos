/* 
 * File:   Client.hpp
 * Author: david
 *
 * Created on 1 de abril de 2017, 06:41 PM
 */

#ifndef CLIENT_HPP
#define CLIENT_HPP
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
#include "ReciveFiles.hpp"
#include "SendFiles.hpp"

using namespace std;
class Client {

private:
    //atributos
    int descriptorClient;
    struct sockaddr_in servidorInfo;
    int port;
    string ip;
    bool state;
    bool esAlmacenamiento;
    bool esImagen;
    bool esVideo;

    static SendFiles* sender;
    static ReciveFiles* reciver;

public:
    //metodos
    Client(void);
    Client(string,int);
    ~Client();

    void connectServer(void);
    static void * listenServer(void*);
    static void confirmacionAlmacenamiento(Client*);
    static void * menuCliente(void*);
    static void * atenderPetAlma(void*);

    int getDescriptorClient(void);
    void setDescriptorClient(int);

    bool getAlmacenamiento(void);
    void setAlmacenamiento(bool);

    bool getImagen(void);
    void setImagen(bool);

    bool getVideo(void);
    void setVideo(bool);

};

#endif /* CLIENT_HPP */

