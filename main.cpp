#include "main.h"

using namespace std;

int main(int argc,char *argv[]){
    char *userName = getenv("USER");
    char *defaultEditor = getenv("EDITOR");
    commandNumber = 0;

    //allocate memory for commands
    allCommands = (char**) calloc(MAX_COMMAND_NUMBER,sizeof(char*));
    for(int i=0;i<MAX_COMMAND_NUMBER;i++){
        allCommands[i] = (char*) calloc(MAX_COMMAND_LENGTH,sizeof(char));
    }
    command = (char*) calloc(MAX_COMMAND_LENGTH,sizeof(char));

    while(true){
        printf("%s >>> ",userName);
        fgets(command,MAX_COMMAND_LENGTH,stdin);
        command[strcspn(command, "\n")] = 0;
        strcpy(allCommands[commandNumber],command);
        commandNumber++;
        command = strtok(command," ");
        
        if(!strcmp(command,listdirCmd)){
            DIR *currentDirectory = opendir(".");
            dirent *directoryPt;
            while ((directoryPt = readdir(currentDirectory)) != NULL){
                printf("%s\n",directoryPt->d_name);
            }
        }
        
        else if(!strcmp(command,mycomputernameCmd)){
            char hostName[HOST_NAME_MAX];
            gethostname(hostName, HOST_NAME_MAX);
            printf("%s\n",hostName);
        }

        else if(!strcmp(command,whatsmyipCmd)){
            system("hostname -i");
        }

        else if(!strcmp(command,hellotextCmd)){
            system(defaultEditor);
        }

        else if(!strcmp(command,printfileCmd)){
            fileName = strtok(NULL," ");
            FILE *InputFile = fopen(fileName, "r"), *outFile;
            
            //if file couldn't open
            if(InputFile == NULL) {
                printf("Cannot open %s\n",fileName);
                continue;
            }

            char *redirectionSymbol = strtok(NULL," ");
            if(redirectionSymbol!=NULL && !strcmp(">", redirectionSymbol)){
                char *outFileName = strtok(NULL," ");
                ofstream outFile(outFileName);
                while(fgets(line,MAX_LINE_LENGTH,InputFile) != NULL){
                    outFile<<line;
                }
            }
            
            else{
                char *executedCommand;
                executedCommand = (char*) calloc(MAX_COMMAND_LENGTH,sizeof(char));
                sprintf(executedCommand,"less %s",fileName);
                system(executedCommand);
                free(executedCommand);
            }
        }
        
        else if(!strcmp(command,dididothatCmd)){
            char *searchCommand = strtok(NULL,"/0");
            bool isFound = false;
            for(int i = commandNumber-1; i > commandNumber - 16 && i>=0; i--){
                if(!strcmp(searchCommand,allCommands[i])){
                    isFound = true;
                    break;
                }
            }
            if(isFound){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }

        else if(!strcmp(command,exitCmd)){
            break;
        }

        //invalid commands
        else{
            printf("No command found as %s\n",command);
        }

    }

    //free memory for commands
    free(command);
    for(int i=0;i<MAX_COMMAND_NUMBER;i++){
        free(allCommands[i]);
    }
    free(allCommands);
    
    return 0;
}