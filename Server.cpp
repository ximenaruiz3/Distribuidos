/* 
 * File:   Server.cpp
 * Author: david
 * 
 * Created on 1 de abril de 2017, 05:45 PM
 */

#include "Server.hpp"
#include "ClientInfo.hpp"
int cont;

Server::Server() {
    this->puerto = 9000;
}

Server::Server(int puerto) {
    this->puerto = puerto;
    
}

Server::~Server() {
}

void Server::inicializarServidor(){
    descriptorSer = socket(AF_INET, SOCK_STREAM, 0);
    servidorInfo.sin_family = AF_INET;
    servidorInfo.sin_addr.s_addr = htonl(INADDR_ANY);
    servidorInfo.sin_port = htons(puerto);
    idBind = bind(descriptorSer,(struct sockaddr *) & servidorInfo, sizeof(servidorInfo));
    
    listen(descriptorSer, maxClientes);
    
    if (descriptorSer==-1 && idBind==-1) {
        cout <<"Error iniciando servidor"<<endl;
    }
}

int recibirEnteroServer(int buffer, int clientInfo){
    char *msg;
    read(clientInfo, msg, buffer);
    int entero = atoi(msg);
    return entero;
}
char* recibirStringServer(int buffer, int clientInfo){
    char *msg;
    read(clientInfo, msg, buffer);
    return msg;
}

void recibirArchivoServer(int interface){

}

void enviarArchivoServer(int socketFD, char* path){

}
void enviarString(string msg, int buffer, int clientInfo){
    char peticion [buffer];
    //sprintf(peticion,"%s", msg);
    write(clientInfo, peticion, buffer);
}

void enviarEntero(int msg, int buffer, int clientInfo){
    char peticion [buffer];
    //sprintf(peticion,"%d", msg);
    write(clientInfo, peticion, buffer);
}

void Server::cerrarServer(){
    exit(EXIT_SUCCESS);
}

void* crearArchivo(char* name, int sock){
    ReciveFiles * reciver = new ReciveFiles();
    reciver->recibirArchivo(sock, new FILE, name);
}

void * comunicacionCliente(void * cli){
    //Crea cliente
    ClientInfo * cliente = (ClientInfo *) cli;
    while(true){
        char peticionCli [128];
        read(cliente->getDescriptorClient(),peticionCli,128);
        int option = atoi(peticionCli);
        if(option == 0){
            sleep(10);
            char peticion1 [128];
            strcpy(peticion1,"0");//Peticion de archivos de la maquina;
            vector<int> contadorArchivosMaq;
            for(int i = 0; i < cliente->getMaquinasVideo()->size();i++){
                char tamanioArchivo[128];
                write(cliente->getMaquinasVideo()->at(i)->getDescriptorClient(),peticion1,128);
                write(cliente->getMaquinasVideo()->at(i)->getDescriptorClient(),peticion1,128);
            }
            for(int i = 0; i < cliente->getMaquinasVideo()->size();i++){
                char tamanioArchivoa[128];
                read(cliente->getMaquinasVideo()->at(i)->getDescriptorClient(),tamanioArchivoa,128);
                contadorArchivosMaq.push_back(atoi(tamanioArchivoa));
            }
            vector<int> posMenor;
            int posPrimerMenor = 0;
            int posSegundoMenor = 1;
            posMenor.push_back(posPrimerMenor);
            posMenor.push_back(posSegundoMenor);


            char peticion2 [128];
            strcpy(peticion2,"0"); //Peticion para enviar archivo
            write(cliente->getMaquinasVideo()->at(posMenor.at(0))->getDescriptorClient(),peticion2,128);
            write(cliente->getMaquinasVideo()->at(posMenor.at(1))->getDescriptorClient(),peticion2,128);
            char peticion3 [128];
            strcpy(peticion3,"1"); //Peticion para enviar archivo
            write(cliente->getMaquinasVideo()->at(posMenor.at(0))->getDescriptorClient(),peticion3,128);
            write(cliente->getMaquinasVideo()->at(posMenor.at(1))->getDescriptorClient(),peticion3,128);


            char recvBuff[256];
            //datos archivo
            char fname[256];
            read(cliente->getDescriptorClient(), fname, 256);
            write(cliente->getMaquinasVideo()->at(posMenor.at(0))->getDescriptorClient(),fname,256);
            write(cliente->getMaquinasVideo()->at(posMenor.at(1))->getDescriptorClient(),fname,256);
            //Determinando tamanio del archivo
            char sizeChar[256];
            read(cliente->getDescriptorClient(), sizeChar, sizeof(sizeChar));
            write(cliente->getMaquinasVideo()->at(posMenor.at(0))->getDescriptorClient(), sizeChar, sizeof(sizeChar));
            write(cliente->getMaquinasVideo()->at(posMenor.at(1))->getDescriptorClient(), sizeChar, sizeof(sizeChar));
            int size = atoi(sizeChar);
            int rcBytes = 0;
            while (rcBytes < size){
                rcBytes += read(cliente->getDescriptorClient(), recvBuff, 256);
                write(cliente->getMaquinasVideo()->at(posMenor.at(0))->getDescriptorClient(), recvBuff,256);
                write(cliente->getMaquinasVideo()->at(posMenor.at(1))->getDescriptorClient(), recvBuff,256);
                cout<<recvBuff<<endl;
            }

        }
        if(option == 1){
            char tamMaquinas[128];
            int sizeMaq = cliente->getMaquinasVideo()->size();
            sprintf(tamMaquinas,"%d", sizeMaq);
            write(cliente->getDescriptorClient(), tamMaquinas,128);
            char selecMaqChar[128];
            read(cliente->getDescriptorClient(), selecMaqChar,128);
            int selecMaq = atoi(selecMaqChar);

            //Enviando peticion para recibir listado
            ClientInfo* maquina = cliente->getMaquinasVideo()->at(selecMaq);
            char peticionMaquina[128];
            sprintf(peticionMaquina, "%d", 1);
            write(maquina->getDescriptorClient(),peticionMaquina , 128);



            //leyendo de maquina y enviando al cliente
            char sizeListChar[128];
            read(maquina->getDescriptorClient(), sizeListChar,128);
            write(cliente->getDescriptorClient(),sizeListChar , 128);
            int size = atoi(sizeListChar);
            for (int i = 0; i < size; ++i) {
                char contList[256];
                read(maquina->getDescriptorClient(), contList,256);
                write(cliente->getDescriptorClient(),contList , 256);
            }
        }
        if(option == 2){
            char peticionMaquina[128];
            sprintf(peticionMaquina, "%d", 2);
            for (int i = 0; i < cliente->getMaquinasVideo()->size(); ++i) {
                write(cliente->getMaquinasVideo()->at(i)->getDescriptorClient(),peticionMaquina, 128);
            }
            char petEliminado[128];
            read(cliente->getDescriptorClient(), petEliminado,128);
            for (int i = 0; i < cliente->getMaquinasVideo()->size(); ++i) {
                cout<<petEliminado<<endl;
                write(cliente->getMaquinasVideo()->at(i)->getDescriptorClient(),petEliminado, 128);
            }
            char taman[128];
            vector<int> sizes;
            char selec[128];
            int may;
            int posi;
            int men;
            int posii;
            char fnname[256];
            for (int i = 0; i < cliente->getMaquinasVideo()->size(); ++i) {
                read(cliente->getMaquinasVideo()->at(i)->getDescriptorClient(),taman,128);
                int temp = atoi( taman );
                sizes.push_back(temp);
            }
            bool bal = true;
            while(bal){
                may = sizes.at(0);
                men = sizes.at(0);
                posi=0;
                posii=0;
                for (int i = 1; i < sizes.size(); ++i) {
                    if(may >= sizes.at(i)){

                    }else{
                        may = sizes.at(i);
                        posi = i;
                    }
                    if(men <= sizes.at(i) ){

                    }else{
                        men = sizes.at(i);
                        posii = i;
                    }
                }
                if((may-men)<2){
                    string lol = "ya esta balanceado";
                    const char *cx = lol.c_str();
                    write(cliente->getDescriptorClient(),cx , 256);
                    bal = false;
                    sprintf(fnname, "%d", 2);
                    write(cliente->getMaquinasVideo()->at(posi)->getDescriptorClient(),fnname,256);
                }else{
                    sprintf(selec, "%d", 3);
                    write(cliente->getMaquinasVideo()->at(posi)->getDescriptorClient(),selec, 128);
                    write(cliente->getMaquinasVideo()->at(posii)->getDescriptorClient(),selec, 128);
                    sprintf(selec, "%d", 0);
                    write(cliente->getMaquinasVideo()->at(posi)->getDescriptorClient(),selec, 128);

                    sizes[posi] = sizes.at(posi)-1;

                    sprintf(selec, "%d", 1);
                    write(cliente->getMaquinasVideo()->at(posii)->getDescriptorClient(),selec, 128);

                    sizes[posii] = sizes.at(posii)+1;

                    char recvBuuff[256];
                    //datos archivo
                    bool cd = true;


                    read(cliente->getMaquinasVideo()->at(posi)->getDescriptorClient(), fnname, 256);
                    write(cliente->getMaquinasVideo()->at(posii)->getDescriptorClient(),fnname,256);
                    while(cd){
                        read(cliente->getMaquinasVideo()->at(posii)->getDescriptorClient(), fnname, 256);
                        int cxz = atoi(fnname);
                        if(cxz== 1){
                            sprintf(fnname, "%d", 1);
                            write(cliente->getMaquinasVideo()->at(posi)->getDescriptorClient(),fnname,256);
                        }else{
                            sprintf(fnname, "%d", 0);
                            write(cliente->getMaquinasVideo()->at(posi)->getDescriptorClient(),fnname,256);
                            break;
                        }
                        read(cliente->getMaquinasVideo()->at(posi)->getDescriptorClient(), fnname, 256);
                        write(cliente->getMaquinasVideo()->at(posii)->getDescriptorClient(),fnname,256);
                    }
                    //Determinando tamanio del archivo
                    char sizzeChar[256];
                    read(cliente->getMaquinasVideo()->at(posi)->getDescriptorClient(), sizzeChar, sizeof(sizzeChar));
                    write(cliente->getMaquinasVideo()->at(posii)->getDescriptorClient(), sizzeChar, sizeof(sizzeChar));
                    int siize = atoi(sizzeChar);
                    int rccBytes = 0;
                    while (rccBytes < siize){
                        rccBytes += read(cliente->getMaquinasVideo()->at(posi)->getDescriptorClient(), recvBuuff, 256);
                        write(cliente->getMaquinasVideo()->at(posii)->getDescriptorClient(), recvBuuff,256);

                    }

                }
            }
        }
    }
}

void Server::confirmacionCliente(ClientInfo * cliente){
    int almacenamiento = recibirEnteroServer(128, cliente->getDescriptorClient());
    if(almacenamiento){
       /* if(maquinasImagen.size() <= maquinasVideo.size()){
            maquinasImagen.push_back(cliente);
            cout<<"Se ha conectado una maquina de almacenamiento de imagen."<<endl;
        }else{*/
            maquinasVideo.push_back(cliente);
            cout<<"Se ha conectado una maquina de almacenamiento de video."<<endl;
        //}


    }
    else{
        cout<<"Se ha conectado un cliente."<<endl;
        cliente->setMaquinasImagen(&maquinasImagen);
        cliente->setMaquinasVideo(&maquinasVideo);
        sleep(10);
        pthread_t clientesHilos;
        pthread_create(&clientesHilos,NULL,&comunicacionCliente,(void *) cliente);
    }

}

void * Server::aceptarClientes(){
    int descriptorCliente;

    cont=0;

    while(cont<maxClientes){
        struct sockaddr_in clienteInfor;
        int tamano= sizeof(struct sockaddr_in);
        cout<<"Aceptando cliente..."<<endl;
        descriptorCliente=accept(this->descriptorSer,(struct sockaddr *)&clienteInfor,(socklen_t*) &tamano);

        //recibiendo clientes

        if(descriptorCliente!=-1){
            clientesDescriptor.push_back(new ClientInfo(descriptorCliente,clienteInfor));
            confirmacionCliente(clientesDescriptor[cont]);
            cont++;
        }
    }
}
void * Server::comenzarServidor(void* serv){
    Server * server = (Server *)  serv;
    server->aceptarClientes();
}


///Set- get
void Server::ejecutarServidor(){
    pthread_t thread;
    pthread_create(&thread, NULL, &comenzarServidor, (void *) this);
}

void Server::setDescriptorServer(int descriptor){
    this->descriptorSer = descriptor;
}

void Server::setIdBind(int idBind){
    this->idBind = idBind;
}

void Server::setPuerto(int port){
    this->puerto = port;
}

void Server::setServidorInfo(struct sockaddr_in info){
    this->servidorInfo = info;
}

vector <ClientInfo *> Server::getClientes(){
    return this->clientesDescriptor;
}

int Server::getDescriptorServer(){
    return this->descriptorSer;
}

int Server::getIdBind(){
    return this->idBind;
}

int Server::getPuerto(){
    return this->puerto;
}
