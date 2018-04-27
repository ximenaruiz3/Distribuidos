/* 
 * File:   Files.cpp
 * Author: david
 * 
 * Created on 12 de abril de 2017, 11:49 PM
 */

#include "ReciveFiles.hpp"

ReciveFiles::ReciveFiles() {
    this->direccIP = (char*) malloc(20);
    getIP(0, direccIP);
}

/*Recibe la clave de la interfaz que va a manejar:
 * lo : 0
 * wlan: 1
 * eth0: 2
*/
ReciveFiles::ReciveFiles(int interface) {
    this->direccIP = (char*) malloc(20);
    getIP(interface, direccIP);
}

ReciveFiles::ReciveFiles(const ReciveFiles& orig) {
}

ReciveFiles::~ReciveFiles() {
}

/*Se recibe el archivo del cliente*/
void ReciveFiles::recibirArchivo(int SocketFD, FILE *file, string pathFile) {
    char buffer[BUFFSIZE];
    int recibido = -1;
    pathFile = "recived/"+pathFile;
    /*Se abre el archivo para escritura*/
    file = fopen((char*)pathFile.c_str(), "wb");
    enviarConfirmacion(SocketFD);
    enviarMD5SUM(SocketFD);
    while ((recibido = recv(SocketFD, buffer, BUFFSIZE, 0)) > 0) {
        //printf("%s", buffer);
        fwrite(buffer, sizeof (char), 1, file);
    }//Termina la recepción del archivo
    fclose(file);
}//End recibirArchivo procedure

void ReciveFiles::enviarConfirmacion(int SocketFD) {
    char mensaje[80] = "Paquete Recibido";
    int lenMensaje = strlen(mensaje);
    printf("\nConfirmación enviada\n");
    if (write(SocketFD, mensaje, sizeof (mensaje)) == ERROR)
        perror("Error al enviar la confirmación:");


}//End enviarConfirmacion

void ReciveFiles::enviarMD5SUM(int SocketFD) {
    FILE *tmp; //Apuntador al archivo temporal que guarda el MD5SUM del archivo.
    char *fileName = "verificacion";
    char md5sum[80];
    system("md5sum archivoRecibido >> verificacion");

    tmp = fopen(fileName, "r");
    fscanf(tmp, "%s", md5sum);
    printf("\nMD5SUM:%s\n", md5sum);
    write(SocketFD, md5sum, sizeof (md5sum));
    fclose(tmp);

}//End enviarMD5DUM

void ReciveFiles::getIP(int tipo, char * IP) {
    FILE *tmpIP;
    char dIP[20];
    char dIP2[20];
    int i, j;
    switch (tipo) {
        case 0:
            system("ifconfig lo | grep inet > tmp");
            break;
        case 1:
            system("ifconfig wlan | grep inet > tmp");
            break;
        case 2:
            system("ifconfig eth | grep inet > tmp");
            break;
    }//End switch
    j = 0;
    tmpIP = fopen("tmp", "r");
    fscanf(tmpIP, "%s %s", dIP, dIP);
    for (i = 5; i < 20; i++) {
        IP[j] = dIP[i];
        j++;
    }
}//End getIP

//Set - Get

void ReciveFiles::socketConfiguration() {
    memset(&stSockAddr, 0, sizeof stSockAddr);
}

void ReciveFiles::setSocketClientFD(int socketClientFD) {
    this->SocketClientFD = socketClientFD;
}

int ReciveFiles::getSocketClientFD() {
    return this->SocketClientFD;
}

void ReciveFiles::setSocketServerFD(int socketServerFD) {
    this->SocketServerFD = socketServerFD;
}

int ReciveFiles::getSocketServerFD() {
    return this->SocketServerFD;
}

sockaddr_in ReciveFiles::getClSockAddr() {
    return clSockAddr;
}

void ReciveFiles::setClSockAddr(sockaddr_in clSockAddr) {
    this->clSockAddr = clSockAddr;
}

sockaddr_in ReciveFiles::getStSockAddr() {
    return stSockAddr;
}

void ReciveFiles::setStSockAddr(sockaddr_in stSockAddr) {
    this->stSockAddr = stSockAddr;
}
