/*
 * File:   Client.cpp
 * Author: david
 *
 * Created on 1 de abril de 2017, 06:41 PM
 */

#include <dirent.h>
#include "Client.hpp"
#include "ClientInfo.hpp"

SendFiles *sendFiles;
ReciveFiles *reciveFiles;

Client::Client() {
    this->ip = "localhost";
    this->port = 1025;
    this->state = true;
    sendFiles = new SendFiles();
    reciveFiles = new ReciveFiles();
}

Client::Client(string ip, int port) {
    this->ip = ip;
    this->port = port;
    this->state = true;
    sendFiles = new SendFiles();
    reciveFiles = new ReciveFiles();
}

Client::~Client() {
}

void * Client::listenServer(void* cli){
    Client* cliente = (Client *) cli;
    char mensajeDeServidor[60];

    while(1){
        recv(cliente->getDescriptorClient(),(void *)&mensajeDeServidor ,60,0);
        cout<<mensajeDeServidor<<endl;
    }
}

void Client::confirmacionAlmacenamiento(Client * cliente){

    char msg[128];
    if(cliente->getAlmacenamiento()){
        strcpy(msg,"1");
    }else strcpy(msg,"0");

    int i=send(cliente->getDescriptorClient(),(void *)msg,sizeof(msg),0);
    sleep(1);

    if(i==-1){
        cout<<"se desconecto del servidor"<<endl;
        close(cliente->getDescriptorClient());
        exit(EXIT_SUCCESS);
    }

}


int recibirEnteroCliente(int buffer, int clientInfo){
    char* msg;
    read(clientInfo, msg, buffer);
    int entero = atoi(msg);
    return entero;
}
char* recibirStringCliente(int buffer, int clientInfo){
    char* msg;
    read(clientInfo, msg, buffer);
    return (msg);
}

void recibirArchivoCliente(int interface){

}

void enviarArchivoCliente(int socketFD, char* path){

}

int imagenOVideo(){
    if(0==1){
        return 0;
    }else if(0==2){
        return 1;
    }else{
        return 2;
    }
}

char* saveName(string aux){
    while (aux.find("/")!=aux.npos) {
        aux = aux.substr(aux.find("/")+1, aux.length());
    }
    char* conv = (char*)aux.c_str();
    return conv;
}


void enviarStringCliente(string msg, int buffer, int clientInfo){
    char peticion [buffer];
    //sprintf(peticion,"%s", msg);
    write(clientInfo, peticion, buffer);
}

void enviarEnteroCliente(int msg, int buffer, int clientInfo){
    char peticion [buffer];
    //sprintf(peticion,"%d", msg);
    write(clientInfo, peticion, buffer);
}

void * Client::atenderPetAlma(void * cli){
    //Recibe cliente
    ClientInfo * cliente=(ClientInfo *) cli;
    while(true){
        //Opcion de cliente
        char opcion [128];
        //Esperando servidor
        cout << "Esperando solicitud de servidor..." <<endl;
        read(cliente->getDescriptorClient(), opcion, 128);
        //Recibe la peticion
        int pet1 = atoi(opcion);
        cout <<"recibe --------"<<pet1<<endl;
        //Solicitud para enviar archivos
        if(pet1 == 0){
            //Buffer de lectura
            char opcion2 [128];
            //Lee la acción que le envía el servidor
            read(cliente->getDescriptorClient(), opcion2, 128);
            //Sabe si evia o recibe archivo
            cout <<"para saber si envia tamano o recibe--------"<<opcion2<<endl;
            //Convierte en entero el tamaño
            int pet2 = atoi(opcion2);
            //Depende de la opcion
            if(pet2==1){
                //Recive archivos
                //Crea el archivo que va a enviar
                FILE *fpg;
                //Crea el buffer de la interfz
                char recvBuff[256];
                //Creando archivo con el nombre
                char fname[256];
                //Recive el nombre del archivo
                read(cliente->getDescriptorClient(), fname, 256);
                //Crea la ruta para recibir archivo
                char path[256];
                //Copia el nombre de la carpeta en path
                strcpy(path, "filesCloud/");
                //Concatena el directorio con el nombre del archivo
                strcat(path,fname);
                //abre el archivo para escritura "ab" (append binary)
                fpg = fopen(path, "ab");
                //Imprime el directorio y el nombre del archivo
                //Obteniendo el tamanio del archivo
                char sizeChar[256];
                //Lee el buffer del tamanio del archivo del cliente
                read(cliente->getDescriptorClient(), sizeChar, sizeof(sizeChar));
                //Covierte en tamanio del archivo
                int size = atoi(sizeChar);
                //Imprime el tamaño
                //Bytes que recibe
                int rcBytes = 0;
                //Empieza a transferir el archivo hasta que se complete el tamao del archivo
                while (rcBytes < size){
                    //Sobreescribe los bytes recibidos según lo que envió el cliente
                    rcBytes = rcBytes + read(cliente->getDescriptorClient(), recvBuff, 256);
                    //Escribe el archivo con el buffer que se le envia
                    fwrite(recvBuff, 1,sizeof(recvBuff),fpg);
                }
                //Cierra el archivo
                fclose(fpg);
                //Termina la transferencia
            }else {
                //Solicitud para saber numero de archivos
                int counter = 0;
                //Crea un DIR (dirección de directorio para la lista de archivos)
                DIR *dir;
                //Estructura de directorio
                struct dirent *ent;
                //Abre el directorio si existe
                if ((dir = opendir("filesCloud/")) != NULL) {
                    /* Imprime todos los archivos y carpetas del directorio */
                    while ((ent = readdir(dir)) != NULL) {
                        //Compara los directorios padre con los hijos para no repetir
                        if (!(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0))
                            //Aumenta el contador de archivos
                            counter++;
                    }
                    //Cierra el directorio
                    closedir(dir);
                } else {
                    //Si no se puede abrir o no existe el directorio
                    cout << "No se pudo abrir el directorio" << endl;
                }
                //Crea el contador de tamaño
                char counterChar[128];
                //Imprime formateado el contador de tamaño
                sprintf(counterChar, "%d", counter);
                //Escribe en el servidor el contador de tamaño
                write(cliente->getDescriptorClient(), counterChar, 128);
                //Imprime el tamaño que envía
            }
        }
        //Para solicitar archivos
        if(pet1 == 1){
            // Solicitud para listado de archivos
            int counter = 0;
            //Crea la variable del directorio donde estarán los archivos
            DIR *dir;
            //Estructura de directorios
            struct dirent *ent;
            if ((dir = opendir ("filesCloud/")) != NULL) {
                /* Imprime todos los archivos y carpetas del directorio */
                while ((ent = readdir (dir)) != NULL) {
                    //Compara los directorios padre con los hijos para no repetir
                    if(!(strcmp(ent->d_name,".")==0 || strcmp(ent->d_name,"..")==0))
                        //Aumenta el contador de archivos
                        counter++;
                }
                //Cierra el directorio de archivos
                closedir (dir);
            } else {
                //No se pudo abrir o no existe el directorio
                cout << "No se pudo abrir el directorio" << endl;
            }
            //Contador de archivos
            char counterChar[128];
            //Imprimete formateado el contador de archivos
            sprintf(counterChar,"%d",counter);
            //Escribe en el cliente el contador de archivos
            write(cliente->getDescriptorClient(),counterChar,128);
            //Si abre el directorio
            if ((dir = opendir ("filesCloud/")) != NULL) {
                /* Imprime todos los archivos y carpetas del directorios*/
                while ((ent = readdir (dir)) != NULL) {
                    //Compara los directorios padre con los hijos para no repetir
                    if(!(strcmp(ent->d_name,".")==0 || strcmp(ent->d_name,"..")==0))
                        //Aumenta el contador de archivos
                        write(cliente->getDescriptorClient(),ent->d_name,256);
                }
                //Cierra el directorio
                closedir (dir);
            } else {
                cout << "No se pudo abrir el directorio" << endl;
            }


        }
        //Petición de eliminar archivos
        if(pet1 == 2){
            //Archivo a eliminar
            char petElim[128];
            //Leer la peticion que va a eliminar
            read(cliente->getDescriptorClient(), petElim,128);
            cout<<petElim<<endl;
            //Ruta donde buscar archivo a eliminar
            string ruta = "filesCloud/";
            //directorio completo del archivo que va a eliminar
            ruta += petElim;
            //Archivo a eliminar
            const char *C = ruta.c_str();
            //Elimina archivo
            remove(C);
            //Mensaje de confirmación
            //Vuelve a mostrar los archivos del directorio
            int counte = 0;
            //Variable de directorio de archivo
            DIR *dirr;
            //Estructura de directorio
            struct dirent *entt;
            if ((dirr = opendir ("filesCloud/")) != NULL) {
                /* print all the files and directories within directory */
                while ((entt = readdir (dirr)) != NULL) {
                    if(!(strcmp(entt->d_name,".")==0 || strcmp(entt->d_name,"..")==0))
                        counte++;
                }
                closedir (dirr);
            } else {
                cout << "No se pudo abrir el directorio" << endl;
            }
            char counteChar[128];
            sprintf(counteChar,"%d",counte);
            //Envía al cliente la lista de archivos sin el que removio
            write(cliente->getDescriptorClient(),counteChar,128);

        }
        if(pet1 == 3){
            char op[128];
            DIR *direca;
            struct dirent *enta;
            read(cliente->getDescriptorClient(), op,128);
            int pet1q = atoi(op);
            if(pet1q==0){

                if ((direca = opendir ("filesCloud/")) != NULL) {
                    /* print all the files and directories within directory */
                    while ((enta = readdir (direca)) != NULL) {
                        if(!(strcmp(enta->d_name,".")==0 || strcmp(enta->d_name,"..")==0)){
                            cout<<"el archivo a enviar "<<enta->d_name<<endl;
                            write(cliente->getDescriptorClient(),enta->d_name,256);
                            char opa[256];
                            read(cliente->getDescriptorClient(), opa,256);
                            int xv = atoi(opa);
                            if(xv == 0){
                                int siza = -1;
                                char pathhh[256];
                                strcpy(pathhh, "filesCloud/");
                                strcat(pathhh,enta->d_name);
                                FILE *fppa = fopen(pathhh,"rb");
                                int fdda = fileno(fppa);
                                fseek(fppa,0L, SEEK_END);
                                siza = ftell(fppa);
                                rewind(fppa);
                                char sizeaCharr [256];
                                sprintf(sizeaCharr,"%d",siza);
                                write(cliente->getDescriptorClient(),sizeaCharr, sizeof(sizeaCharr));
                                if(fppa== NULL){
                                    printf("Error abriendo archivo");
                                }else{

                                    while(1)
                                    {
                                        /* First read file in chunks of 256 bytes */
                                        unsigned char buffa[256]={0};
                                        int nreada = fread(buffa,1,256,fppa);
                                        //cout << buff<< endl;
                                        /* If read was success, send data. */
                                        if(nreada > 0)
                                        {
                                            //printf("Sending \n");
                                            write(cliente->getDescriptorClient(), buffa, nreada);
                                        }
                                        if (nreada < 256)
                                        {
                                            if (feof(fppa))
                                            {
                                                printf("La transferencia ha terminado correctamente.\n");
                                                fclose(fppa);
                                                string rutax = "filesCloud/";
                                                rutax += enta->d_name;
                                                const char *Cb = rutax.c_str();
                                                remove(Cb);

                                            }
                                            if (ferror(fppa))
                                                printf("Error reading\n");
                                            break;
                                        }
                                    }


                                }
                                break;
                            }else if(xv == 2){
                                break;
                            }
                        }

                    }

                } else {
                    cout << "No se pudo abrir el directorio" << endl;
                }
            }else if(pet1q==1){
                FILE *fps;
                char recvBufff[256];
                //Creando archivo
                bool cat =true;
                bool open = true;
                char fnamee[256];
                char* named;
                while(cat){
                    read(cliente->getDescriptorClient(), fnamee, 256);
                    DIR *dirra;
                    struct dirent *enttx;
                    if ((dirra = opendir ("filesCloud/")) != NULL) {
                        /* print all the files and directories within directory */
                        while ((enttx = readdir (dirra)) != NULL) {
                            if(!(strcmp(enttx->d_name,".")==0 || strcmp(enttx->d_name,"..")==0)){
                                named = enttx->d_name;
                                if(strcmp(named,fnamee)==0){
                                    char cop[256];
                                    sprintf(cop,"%d",1);
                                    write(cliente->getDescriptorClient(),cop,256);
                                    open = false;
                                    break;
                                }


                            }

                        }
                        if(open){
                            char copp[256];
                            sprintf(copp,"%d",0);
                            write(cliente->getDescriptorClient(),copp,256);
                            cat = false;
                        }
                        closedir (dirra);
                    } else {
                    }
                }
                char path1z[256];
                strcpy(path1z, "filesCloud/");
                strcat(path1z,fnamee);
                fps = fopen(path1z, "ab");
                cout<< "Archivo: "<< path1z <<endl;
                //Obteniendo el tamanio del archivo
                char sizeChaara[256];
                read(cliente->getDescriptorClient(), sizeChaara, sizeof(sizeChaara));
                int sizeaz = atoi(sizeChaara);
                int rcBytesaa = 0;
                while (rcBytesaa < sizeaz){
                    rcBytesaa = rcBytesaa + read(cliente->getDescriptorClient(), recvBufff, 256);
                    fwrite(recvBufff, 1,sizeof(recvBufff),fps);
                }
                fclose(fps);
                cout<< "Se ha terminado la transferencia."<<endl;
            }
        }
    }
}

void Client::connectServer(){
    descriptorClient = socket(AF_INET,SOCK_STREAM,0);
    servidorInfo.sin_family=AF_INET;

    inet_pton(AF_INET,ip.c_str(),&servidorInfo.sin_addr);

    servidorInfo.sin_port=htons(port);

    int conn=connect(descriptorClient,(struct sockaddr *)&servidorInfo,sizeof(servidorInfo));

    if(conn!=-1){

        confirmacionAlmacenamiento(this);
        if(this->getAlmacenamiento()){

            pthread_t hiloRecibeArchivoMaquina;
            pthread_create(&hiloRecibeArchivoMaquina,NULL,atenderPetAlma,(void *)this);


        }
        else{
            pthread_t hiloEnviarArchivo;
            pthread_create(&hiloEnviarArchivo,NULL,menuCliente,(void *)this);
        }

        while(1);
    }else{

        cout<<"No se pudo conectar con el servidor"<<endl;
    }
}

void * Client::menuCliente(void * cli){
    Client* cliente = (Client *) cli;
    while(true){
        int option;
        cout<< "Seleccione: 0 para enviar archivo; 1 para ver listado de "
            <<  "archivos de una maquina; 2 para borrar archivo "<<endl;
        cin >> option;
        //Petición de cliente 01
        if(option == 0){
            //Solicitud para enviar archivo ---- 1
            char peticion [128];
            sprintf(peticion,"%d",0);
            write(cliente->getDescriptorClient(),peticion,128);
            //---------------
            char fnamev [100];
            cout<< "Ingrese el archivo que va a enviar"<< endl;
            cin >> fnamev;
            cout<<"nombre de archivo: "<<fnamev<<endl;
            sleep(4);
            write(cliente->getDescriptorClient(),fnamev, 256);
            int sizek = -1;
            FILE *fpv = fopen(fnamev,"rb");
            int fdnm = fileno(fpv);
            fseek(fpv,0L, SEEK_END);
            sizek = ftell(fpv);
            rewind(fpv);
            char sizeCharx [256];
            sprintf(sizeCharx,"%d",sizek);
            cout<<sizeCharx<<endl;
            write(cliente->getDescriptorClient(),sizeCharx, sizeof(sizeCharx));

            if(fdnm == -1){
                printf("Error abriendo archivo");
            }else{

                while(1)
                {
                    /// First read file in chunks of 256 bytes
                    unsigned char buffon[256]={0};
                    int nreader = fread(buffon,1,256,fpv);
                    cout << buffon<< endl;
                    // If read was success, send data.
                    if(nreader > 0)
                    {
                        printf("Sending \n");
                        write(cliente->getDescriptorClient(), buffon, nreader);
                    }
                    if (nreader < 256)
                    {
                        if (feof(fpv))
                        {
                            printf("La transferencia ha terminado correctamente.\n");
                            fclose(fpv);
                        }
                        if (ferror(fpv))
                            printf("Error reading\n");
                        break;
                    }
                }
            }

        }
        else if(option == 1){
            //------------------
            //Solicitud para enviar archivo ---- 0
            char peticion [128];
            sprintf(peticion,"%d",option);
            write(cliente->getDescriptorClient(),peticion,128);
            //-------------
            char tamMaquinasChar [128];
            read(cliente->getDescriptorClient(), tamMaquinasChar, 128);
            int tamMaquinas = atoi(tamMaquinasChar);
            cout <<"Seleccione la maquina:";
            for(int i =0; i < tamMaquinas; i++){
                cout << " "<< i;
            }
            cout<<endl;
            int maqSelec;
            cin >> maqSelec;
            char maqSelecChar [128];
            sprintf(maqSelecChar, "%d", maqSelec);
            write(cliente->getDescriptorClient(),maqSelecChar,128);


            // leyendo de servidor lista de archivos de maquina seleccionada
            char sizeListChar[128];
            read(cliente->getDescriptorClient(), sizeListChar, 128);
            int sizeList = atoi(sizeListChar);
            cout << "Lista de archivos:"<<endl;
            cout << "Tamanio: "<< sizeList<<endl;
            for (int i = 0; i < sizeList; ++i) {
                char contList[256];
                read(cliente->getDescriptorClient(), contList, 256);
                cout<<contList<<endl;
            }
        }else if(option == 2){
            char peticionElimin [128];
            cout <<"Escriba el nombre del archivo a eliminar:";
            cin>>peticionElimin;
            write(cliente->getDescriptorClient(),peticionElimin,128);
            cout << "El archivo se elimino correctamente" << endl;
            char balan[256];
            read(cliente->getDescriptorClient(), balan, 256);
            cout<<balan<<endl;
        }else{
            cout<< "Opcion ingresada no es valida" << endl;
        }
    }

}

//Set - Get
int Client::getDescriptorClient(){
    return this->descriptorClient;
}

void Client::setDescriptorClient(int descriptor){
    this->descriptorClient = descriptor;
}

bool Client::getAlmacenamiento(){
    return this->esAlmacenamiento;
}

void Client::setAlmacenamiento(bool almacenamiento){
    this->esAlmacenamiento = almacenamiento;
}