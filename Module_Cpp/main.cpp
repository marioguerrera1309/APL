#include <iostream>
#include <string>
#include <cstring>      
#include <sys/socket.h> 
#include <arpa/inet.h>  
#include <unistd.h>     
#define SERVER_IP   "127.0.0.1"
#define PORT        50000
#define BUFFER_SIZE 1024
int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    const char *message = "Pingcpp";
    char buffer[BUFFER_SIZE] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Errore: creazione socket fallita" << std::endl;
        return -1;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr) <= 0) {
        std::cerr << "Errore: Indirizzo IP non valido/non supportato" << std::endl;
        close(sock);
        return -1;
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Errore: Connessione fallita. Assicurati che il server Go sia in esecuzione sulla porta " << PORT << std::endl;
        close(sock);
        return -1;
    }
    //std::cout << "Connesso al server Go. Invio messaggio..." << std::endl;
    while (true) {
        send(sock, message, strlen(message), 0);
        //std::cout << "Messaggio inviato: " << message << std::endl;
        //sleep(1);
        //std::cout << "Messaggio inviato: " << message << std::endl;
        int valread;
        valread = read(sock, buffer, BUFFER_SIZE - 1);
        if (valread > 0) {
            buffer[valread] = '\0';
            //std::cout << "Risposta ricevuta dal server Go: " << buffer << std::endl;
            if(std::string(buffer) == std::string("Pong")) {
                //std::cout << "Comunicazione avvenuta con successo!" << std::endl;
                std::cout << std::string(buffer) << std::endl;
                sleep(1);
            } else {
                std::cerr << "Errore: Risposta inaspettata dal server Go: " << buffer << std::endl;
            }
        }
    }
    close(sock);
    return 0;
}
