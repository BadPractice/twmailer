#include "connection.h"

#include <string.h>
using namespace std;

connection::connection()
{
    create_socket = socket (AF_INET, SOCK_STREAM, 0);

    memset(&address,0,sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons (PORT);

    if (bind ( create_socket, (struct sockaddr *) &address, sizeof (address)) != 0)
    {
        cout<<"bind error"<<endl;
      //  return EXIT_FAILURE;
    }
    listen (create_socket, 5);

    addrlen = sizeof (struct sockaddr_in);
}

string connection::connect()
{
    new_socket = accept ( create_socket, (struct sockaddr *) &cliaddress, &addrlen );
    if (new_socket > 0)
        {
         //   cout<<"client connected.....  " << inet_ntoa (cliaddress.sin_addr),ntohs(cliaddress.sin_port)<<endl;
         buffer = "Welcome to my server! I hat you so much";
           // strcpy(buffer,"Welcome to my Server! I hate you so much!\n");
            send(new_socket, buffer.c_str(), buffer.size(),0);
        }
           do
        {
            size = recv (new_socket,
                          (void *) buffer.c_str(),
                          buffer.size()
                         ,NULL);
            if( size > 0)
            {
                buffer[size] = '\0';
                return buffer;

            }
            else if (size == 0)
            {
//                printf("Client closed remote socket\n");
                break;
            }
            else
            {
//                perror("recv error");
              //  return EXIT_FAILURE;
            }
        }while(buffer.find("quit",4));
    //    while (strncmp (buffer, "quit", 4)  != 0);
    //    close (new_socket);
        return buffer;
}
connection::~connection()
{
    close (create_socket);
}
