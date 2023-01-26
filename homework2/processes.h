#ifndef PROCESSES_H
#define PROCESSES_H

#define NAME_SIZE 30
#define MAX_PROCESSES 5

typedef struct {
    int id;
    char name[NAME_SIZE];
} Process;

#ifndef VARIABLES
#define VARIABLES
Process processes[MAX_PROCESSES];
int processescount;
#endif

static int nextprocessid();
int createnewprocess(char input_name[30]);
int stopprocess(int input_id);

#endif