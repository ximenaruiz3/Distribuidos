/* 
 * File:   main.cpp
 * Author: david
 *
 * Created on 1 de abril de 2017, 05:35 PM
 */

#include <cstdlib>
#include "Server.hpp"
#include "Client.hpp"

using namespace std;

int main(int argc, char** argv) {
    int tipo = 0;
    int port = 0;
    cout <<"1. Servidor, 2. Cliente, 3. Almacenamiento \nSeleccione: ";
    cin>>tipo;
    cin.get();
    cout <<"Puerto: ";
    cin>>port;
    cin.get();
    int val = tipo;
    string host;
    if (val==1) {
        Server *servidor;
        servidor = new Server(port);
        servidor->inicializarServidor();
        servidor->ejecutarServidor();
        while(1);
    }
    if (val == 2) {
        cout << "Nombre del host o ip: "; string host;
        getline(cin, host);
        Client *cliente = new Client(host, port);
        cliente->connectServer();
    }
    if (val == 3) {
        cout << "Nombre del host o ip: "; string host;
        getline(cin, host);
        Client *cliente = new Client(host, port);
        cliente->setAlmacenamiento(true);

        cliente->connectServer();
    }
    return 0;
}

