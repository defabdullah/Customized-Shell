#include "main.h"

using namespace std;

int main(int argc,char *argv[]){
    char* userName = getenv("USER");
    char* defaultEditor = getenv("EDITOR");
    string command;

    while(true){

        printf("%s >>> ",userName);
        cin >> command;
        
        if(!command.compare(listdirCmd)){
            DIR *currentDirectory = opendir(".");
            dirent *directoryPt;
            while ((directoryPt = readdir(currentDirectory)) != NULL){
                printf("%s\n",directoryPt->d_name);
            }
        }
        
        else if(!command.compare(mycomputernameCmd)){
            char hostName[HOST_NAME_MAX];
            gethostname(hostName, HOST_NAME_MAX);
            printf("%s\n",hostName);
        }

        else if(!command.compare(whatsmyipCmd)){
            system("hostname -i");
        }

        else if(!command.compare(hellotextCmd)){
            system(defaultEditor);
        }

        else if(!command.compare(exitCmd)){
            break;
        }
    }
    
    return 0;
}