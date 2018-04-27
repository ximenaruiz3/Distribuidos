/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SendFiles.hpp
 * Author: david
 *
 * Created on 14 de abril de 2017, 02:16 PM
 */

#ifndef SENDFILES_HPP
#define SENDFILES_HPP
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string>

#define BUFFSIZE 1
#define	ERROR	-1
#define	PUERTO	9000


using namespace std;

class SendFiles {
public:
    SendFiles();
    SendFiles(const SendFiles& orig);
    virtual ~SendFiles();
    void enviarArchivo(int, char*);
    char* saveName(string);
    void setStSockAddr(sockaddr_in stSockAddr);
private:
    struct sockaddr_in stSockAddr;
    int sockLen;
    int Res;
    int SocketFD;
    int recibido;
    char buffer[BUFFSIZE];
    char mensaje[80];
    int totalBytesRcvd;
    int bytesRcvd;
    FILE *archivo;

};

#endif /* SENDFILES_HPP */

