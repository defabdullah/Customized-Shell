#include "main.h"

using namespace std;

int main(int argc,char *argv[]){
    //get enviorenment variables
    char *userName = getenv("USER");
    char *defaultEditor = getenv("EDITOR");
    commandNumber = 0;

    //allocate memory for commands
    allCommands = (char**) calloc(MAX_COMMAND_NUMBER,sizeof(char*));
    for(int i=0;i<MAX_COMMAND_NUMBER;i++){
        allCommands[i] = (char*) calloc(MAX_COMMAND_LENGTH,sizeof(char));
    }
    command = (char*) calloc(MAX_COMMAND_LENGTH,sizeof(char));

    //main loop
    while(true){
        //user signature and get command
        printf("%s >>> ",userName);
        fgets(command,MAX_COMMAND_LENGTH,stdin);
        command[strcspn(command, "\n")] = 0;
        //save command to list and increment command number
        strcpy(allCommands[commandNumber],command);
        commandNumber++;
        command = strtok(command," ");
        
        //listdir command
        if(!strcmp(command,listdirCmd)){
            //open directory and prints all filenames.
            DIR *currentDirectory = opendir(".");
            dirent *directoryPt;
            while ((directoryPt = readdir(currentDirectory)) != NULL){
                printf("%s\n",directoryPt->d_name);
            }
        }
        
        //mycomputername command
        else if(!strcmp(command,mycomputernameCmd)){
            //get and prints hostname
            char hostName[HOST_NAME_MAX];
            gethostname(hostName, HOST_NAME_MAX);
            printf("%s\n",hostName);
        }

        //whatsmyipcommmand
        else if(!strcmp(command,whatsmyipCmd)){
            system("hostname -i");
        }

        //hellotext command
        else if(!strcmp(command,hellotextCmd)){
            system(defaultEditor);
        }

        //printfile commands
        else if(!strcmp(command,printfileCmd)){
            //get file name
            fileName = strtok(NULL," ");
            char *redirectionSymbol = strtok(NULL," ");
            
            //control redirection symbol and if it is found execute cp command
            if(redirectionSymbol!=NULL && !strcmp(redirectionSymbol, ">")){
                char *outFileName = strtok(NULL," ");
                char *executedCommand = (char*) calloc(MAX_COMMAND_LENGTH,sizeof(char));
                sprintf(executedCommand,"cp %s > %s",fileName,outFileName);
                system(executedCommand);
                free(executedCommand);
            }
            
            //if this is just print a file command open file and print it line by line with enter
            else{
                FILE *InputFile = fopen(fileName, "r"), *outFile;
            
                //if file couldn't open
                if(InputFile == NULL) {
                    printf("Cannot open %s\n",fileName);
                    continue;
                }

                while (fgets(line,MAX_LINE_LENGTH,InputFile)) {
                    line[strcspn(line, "\n")] = 0;
                    printf("%s", line);
                    cin.get();
                }

                fclose(InputFile);
            }
        }
        
        //dididothat command: read command to be searched and try to find it in last 15 command.
        else if(!strcmp(command,dididothatCmd)){
            char *searchCommand = strtok(NULL,"/0");
            searchCommand++;
            searchCommand[strcspn(searchCommand, "\"")] = 0;
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

        //exit command.
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