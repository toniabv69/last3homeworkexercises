#include "processes.h"
#include <string.h>

static int idcount = 0;

static int nextprocessid() {
    idcount++;
    if(idcount > 0) return idcount;
    else return 0;
}

int createnewprocess(char input_name[30]) {
    static Process newprocess;
    if(nextprocessid() != 0) {
        idcount--;
        newprocess.id = nextprocessid();
        strcpy(newprocess.name, input_name);
        if(processescount < MAX_PROCESSES) {
            processes[processescount].id = newprocess.id;
            strcpy(processes[processescount].name, newprocess.name);
            processescount++;
            return newprocess.id;
        } else return 0;
    } else return -1;
}

int stopprocess(int input_id) {
    for(int i = 0; i < MAX_PROCESSES && processes[i].id != 0; i++) {
        if(processes[i].id == input_id) {
            processes[i].id = 0;
            strcpy(processes[i].name, "\0");
            processescount--;
            for(int j = 0; j < MAX_PROCESSES; j++) {
                if(processes[j].id == 0 && j < MAX_PROCESSES - 1) {
                    processes[j].id = processes[j + 1].id;
                    strcpy(processes[j].name, processes[j + 1].name);
                    processes[j + 1].id = 0;
                    strcpy(processes[j + 1].name, "\0");
                }
            } return 1;
        }
    } return 0;
}