/* 
 * File:   Server.hpp
 * Author: david
 *
 * Created on 1 de abril de 2017, 05:45 PM
 */

#ifndef SERVER_HPP
#define SERVER_HPP
#include "Client.hpp"
#include "ClientInfo.hpp"
#include "ReciveFiles.hpp"
#define maxClientes 100


class Server {
public:
private:
    int descriptorSer;
    int idBind;
    int puerto;
    struct sockaddr_in servidorInfo;
    vector<ClientInfo *> clientesDescriptor;
    vector<ClientInfo *> maquinasImagen;
    vector<ClientInfo *> maquinasVideo;
    bool estado;
    static ReciveFiles * reciver;
    static SendFiles* sender;
public:

    //constructores
    Server(void);
    Server(int);
    ~Server();

    // metodos

    void inicializarServidor(void);
    void* aceptarClientes(void);
    void cerrarServer(void);
    static void * comenzarServidor(void *);
    void ejecutarServidor(void);
    void confirmacionCliente(ClientInfo*);
    static void * atenderPetCli(void *);

    //set

    void setDescriptorServer(int);
    void setIdBind(int);
    void setPuerto(int);
    void setServidorInfo(struct sockaddr_in);

    //get

    int getDescriptorServer(void);
    int getIdBind(void);
    int getPuerto(void);
    struct sockaddr_in getServidorInfo(void);
    vector<ClientInfo *> getClientes(void);
    vector<ClientInfo *> getMaquinas(void);


};

#endif /* SERVER_HPP */

