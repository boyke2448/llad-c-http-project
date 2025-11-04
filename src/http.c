#include "http.h"
#include <string.h>
#include <unistd.h>

int read_http_request(int socket_fd, http_request *request) {
    char buffer[8192] = {0};
    ssize_t bytes_read = read(socket_fd, buffer, sizeof(buffer) - 1);
    if (bytes_read <= 0) {
        return -1; // Error or connection closed
    }
    buffer[bytes_read] = '\0';

    // Simple parsing of the HTTP request line
    sscanf(buffer, "%7s %2047s %15s", request->method, request->path, request->protocol);
    return 0; // Success
}