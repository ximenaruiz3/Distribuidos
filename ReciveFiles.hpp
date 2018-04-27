/* 
 * File:   Files.hpp
 * Author: david
 *
 * Created on 12 de abril de 2017, 11:49 PM
 */

#ifndef FILES_HPP
#define FILES_HPP
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <string.h>


/*Definición de constantes*/
#define BUFFSIZE 1
#define PUERTO	9000
#define ERROR -1

using namespace std;

class ReciveFiles {
public:
    ReciveFiles();
    ReciveFiles(int);
    ReciveFiles(const ReciveFiles& orig);
    virtual ~ReciveFiles();
    
    /*Prototipos de función*/
    void recibirArchivo(int , FILE *, string);
    void enviarConfirmacion(int);
    void enviarMD5SUM(int);
    void getIP(int , char *);
    
    void socketConfiguration();
    int getSocketClientFD();
    void setSocketClientFD(int);
    int getSocketServerFD();
    void setSocketServerFD(int);
    struct sockaddr_in getClSockAddr();
    void setClSockAddr(sockaddr_in);
    struct sockaddr_in getStSockAddr();
    void setStSockAddr(sockaddr_in);

private:
    struct sockaddr_in stSockAddr;
    struct sockaddr_in clSockAddr;
    FILE *archivo;
    char *direccIP;
    int SocketServerFD;
    int SocketClientFD;
    int clientLen;
    int serverLen;
    
};

#endif /* FILES_HPP */

