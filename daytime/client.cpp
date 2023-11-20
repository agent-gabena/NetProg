#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string>
#include <errno.h>
#include <unistd.h>
using namespace std;
#define BUFSIZE 1024

int main(){
    int s;
    char buffer[BUFSIZE];
    int n;

    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s<0) {
        cout<<"ERROR socket"<<endl;
        exit(EXIT_FAILURE);
    }
    sockaddr_in* sa = new sockaddr_in;
    sa->sin_family = AF_INET;
    sa->sin_addr.s_addr = INADDR_ANY;
    sa->sin_port = htons(0);
    if( bind(s, (const sockaddr*)sa, (socklen_t)sizeof(sockaddr_in)) < 0) {
        cout << "Error <bind>" << endl;
        exit(EXIT_FAILURE);
    }
    sockaddr_in* server = new sockaddr_in;
    server->sin_family = AF_INET;
    server->sin_port = htons(7);
    server->sin_addr.s_addr = inet_addr("172.16.40.1");

    socklen_t clen = sizeof(sockaddr_in);

    n = sendto(s,buffer,BUFSIZE,0, (const sockaddr*)server, clen);
    if (n<0) {
        cout<<"ERROR sendto"<<endl;
        exit(EXIT_FAILURE);
    }
    
    
    n = recvfrom(s,buffer,BUFSIZE,0, (sockaddr*)server, &clen);
    if (n<0) {
        cout<<"ERROR recvfrom"<<endl;
        exit(EXIT_FAILURE);
    }
    string msg(buffer, n);
    cout << msg << endl;
    delete sa;
    delete server;
    close(s);
    return 0;
} 
