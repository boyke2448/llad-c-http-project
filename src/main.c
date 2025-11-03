#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include "tcp.h"

#define PORT 8080

int main() {
        tcp_server server = {0};
        server_status_e status = bind_tcp_port(&server, PORT);
        if(status != SERVER_OK) {
            printf("Server intialization failed.\n");
            exit(EXIT_FAILURE);
        }

        int client_fd = accept_client(server.socket_fd);
        if(client_fd == -1) {
            printf("Faile to accept client connection.\n");
            close(server.socket_fd);
            exit(EXIT_FAILURE);
        };

        printf("Client connected.\n");

        close(client_fd);
        close(server.socket_fd);
        return 0;
}