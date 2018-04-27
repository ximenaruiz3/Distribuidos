/* 
 * File:   ClientInfo.cpp
 * Author: david
 * 
 * Created on 1 de abril de 2017, 10:46 PM
 */

#include "ClientInfo.hpp"

ClientInfo::ClientInfo(int desc, struct sockaddr_in information) {
    this->descriptorClient = desc;
    this->clientInfo = information;
    this->state = true;
}

ClientInfo::~ClientInfo() {
    
}


int ClientInfo::getId(){
    return this->id;
}

void ClientInfo::setId(int id){
    this->id=id;
}


int ClientInfo::getDescriptorClient(void){
    return this->descriptorClient;
}
struct sockaddr_in ClientInfo::getClientInfo(){
    return this->clientInfo;
}

bool ClientInfo::getState(){
    return this->state;
}

void ClientInfo::setState(bool estado){
    this->state=state;
}

vector<ClientInfo *>* ClientInfo::getMaquinasImagen(){
    return this->maquinasImagen;
}

void ClientInfo::setMaquinasImagen(vector<ClientInfo *> *maquinas){
    this->maquinasImagen = maquinas;
}
vector<ClientInfo *>* ClientInfo::getMaquinasVideo(){
    return this->maquinasVideo;
}

void ClientInfo::setMaquinasVideo(vector<ClientInfo *> *maquinas){
    this->maquinasVideo = maquinas;
}