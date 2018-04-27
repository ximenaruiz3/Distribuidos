/* 
 * File:   SendFiles.cpp
 * Author: david
 * 
 * Created on 14 de abril de 2017, 02:16 PM
 */

#include "SendFiles.hpp"

SendFiles::SendFiles() {
}

SendFiles::SendFiles(const SendFiles& orig) {
}

SendFiles::~SendFiles() {
}

void SendFiles::enviarArchivo(int socketFD, char* path) {
    archivo = fopen(path, "rb");
    this->SocketFD = socketFD;

    /*Se verifica la integridad del archivo*/
    if (!archivo) {
        perror("Error al abrir el archivo:");
        exit(EXIT_FAILURE);
    }
    /*Se verifica la integridad del socket*/
    if (SocketFD == ERROR) {
        perror("cannot create socket");
        exit(EXIT_FAILURE);
    }
    /*Se configura la dirección del socket del cliente*/
   // memset(&stSockAddr, 0, sizeof stSockAddr);
    /*Se envia el archivo*/
    while (!feof(archivo)) {
        fread(buffer, sizeof (char), BUFFSIZE, archivo);
        if (send(SocketFD, buffer, BUFFSIZE, 0) == ERROR)
            perror("Error al enviar el arvhivo:");
    }
    read(SocketFD, mensaje, sizeof (mensaje));
    printf("\nConfirmación recibida:\n%s\n", mensaje);

    read(SocketFD, mensaje, sizeof (mensaje));
    printf("\nMD5SUM:\n%s\n", mensaje);

    fclose(archivo);
    close(SocketFD);
}

char* SendFiles::saveName(string aux){
    while (aux.find("/")!=aux.npos) {
        aux = aux.substr(aux.find("/")+1, aux.length());
    }
    char* conv = (char*)aux.c_str();
    return conv;
}

//Set - Get
void SendFiles::setStSockAddr(sockaddr_in stSockAddr) {
    this->stSockAddr = stSockAddr;
}