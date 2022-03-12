#include <pthread.h>
#include <semaphore.h>
#include "simos.h"


int currentPid = 2;    // user pid should start from 2, pid=0/1 are OS/idle
int numUserProcess = 0; 

//============================================
// context switch, switch in or out a process pid
//============================================

void context_in (int pid)
{ CPU.Pid = pid;
  CPU.PC = PCB[pid]->PC;
  CPU.AC = PCB[pid]->AC;
  CPU.PTptr = PCB[pid]->PTptr;
  CPU.exeStatus = PCB[pid]->exeStatus;
}

void context_out (int pid)
{ PCB[pid]->PC = CPU.PC;
  PCB[pid]->AC = CPU.AC;
  PCB[pid]->exeStatus = CPU.exeStatus;
}

//=========================================================================
// ready queue management
// Implemented as a linked list with head and tail pointers
// The ready queue needs to be protected in case insertion comes from
// process submission and removal from process execution
//=========================================================================

#define nullReady 0
   // when get_ready_process encoutered empty queue, nullReady is returned

typedef struct ReadyNodeStruct{ 
  int pid;
  struct ReadyNodeStruct *next;
}ReadyNode;

ReadyNode *readyHead_Q1 = NULL;
ReadyNode *readyTail_Q1 = NULL;

ReadyNode *readyHead_Q2 = NULL;
ReadyNode *readyTail_Q2 = NULL;

ReadyNode *readyHead_Q3 = NULL;
ReadyNode *readyTail_Q3 = NULL;

ReadyNode *readyHead_Q4 = NULL;
ReadyNode *readyTail_Q4 = NULL;

void insert_ready_process_Q1 (int pid){
  ReadyNode *node;

  node = (ReadyNode *) malloc (sizeof (ReadyNode));
  node->pid = pid;
  node->next = NULL;
  if (readyTail_Q1 == NULL) // readyHead would be NULL also
    { readyTail_Q1 = node; readyHead_Q1 = node; }
  else // insert to tail
    { readyTail_Q1->next = node; readyTail_Q1 = node; }
}

int get_ready_process_Q1(){
  ReadyNode *rnode;
  int pid;

  if (readyHead_Q1 == NULL)
  { if (cpuDebug) fprintf (bugF, "No ready process now!!!\n");
    return (nullReady); 
  }
  else
  { pid = readyHead_Q1->pid;
    rnode = readyHead_Q1;
    readyHead_Q1 = rnode->next;
    free (rnode);
    if (readyHead_Q1 == NULL) readyTail_Q1 = NULL;
  }
  return (pid);
}




void insert_ready_process_Q2 (int pid){
  ReadyNode *node;

  node = (ReadyNode *) malloc (sizeof (ReadyNode));
  node->pid = pid;
  node->next = NULL;
  if (readyTail_Q2 == NULL) // readyHead would be NULL also
    { readyTail_Q2 = node; readyHead_Q2 = node; }
  else // insert to tail
    { readyTail_Q2->next = node; readyTail_Q2 = node; }
}

int get_ready_process_Q2(){
  ReadyNode *rnode;
  int pid;

  if (readyHead_Q2 == NULL)
  { if (cpuDebug) fprintf (bugF, "No ready process now!!!\n");
    return (nullReady); 
  }
  else
  { pid = readyHead_Q2->pid;
    rnode = readyHead_Q2;
    readyHead_Q2 = rnode->next;
    free (rnode);
    if (readyHead_Q2 == NULL) readyTail_Q2 = NULL;
  }
  return (pid);
}






void insert_ready_process_Q3 (int pid){
  ReadyNode *node;

  node = (ReadyNode *) malloc (sizeof (ReadyNode));
  node->pid = pid;
  node->next = NULL;
  if (readyTail_Q3 == NULL) // readyHead would be NULL also
    { readyTail_Q3 = node; readyHead_Q3 = node; }
  else // insert to tail
    { readyTail_Q3->next = node; readyTail_Q3 = node; }
}

int get_ready_process_Q3(){
  ReadyNode *rnode;
  int pid;

  if (readyHead_Q3 == NULL)
  { if (cpuDebug) fprintf (bugF, "No ready process now!!!\n");
    return (nullReady); 
  }
  else
  { pid = readyHead_Q3->pid;
    rnode = readyHead_Q3;
    readyHead_Q3 = rnode->next;
    free (rnode);
    if (readyHead_Q3 == NULL) readyTail_Q3 = NULL;
  }
  return (pid);
}





void insert_ready_process_Q4 (int pid){
  ReadyNode *node;

  node = (ReadyNode *) malloc (sizeof (ReadyNode));
  node->pid = pid;
  node->next = NULL;
  if (readyTail_Q4 == NULL) // readyHead would be NULL also
    { readyTail_Q4 = node; readyHead_Q4 = node; }
  else // insert to tail
    { readyTail_Q4->next = node; readyTail_Q4 = node; }
}

int get_ready_process_Q4(){
  ReadyNode *rnode;
  int pid;

  if (readyHead_Q4 == NULL)
  { if (cpuDebug) fprintf (bugF, "No ready process now!!!\n");
    return (nullReady); 
  }
  else
  { pid = readyHead_Q4->pid;
    rnode = readyHead_Q4;
    readyHead_Q4 = rnode->next;
    free (rnode);
    if (readyHead_Q4 == NULL) readyTail_Q4 = NULL;
  }
  return (pid);
}


void dump_ready_queue_Q1 (FILE *outf)
{ ReadyNode *node;

  fprintf (outf, "******************** Ready Queue1 Dump\n");
  node = readyHead_Q1;
  while (node != NULL)
    { fprintf (outf, "%d, ", node->pid); node = node->next; }
  fprintf (outf, "\n");
}

void dump_ready_queue_Q2 (FILE *outf)
{ ReadyNode *node;

  fprintf (outf, "******************** Ready Queue2 Dump\n");
  node = readyHead_Q2;
  while (node != NULL)
    { fprintf (outf, "%d, ", node->pid); node = node->next; }
  fprintf (outf, "\n");
}

void dump_ready_queue_Q3 (FILE *outf)
{ ReadyNode *node;

  fprintf (outf, "******************** Ready Queue3 Dump\n");
  node = readyHead_Q3;
  while (node != NULL)
    { fprintf (outf, "%d, ", node->pid); node = node->next; }
  fprintf (outf, "\n");
}

void dump_ready_queue_Q4 (FILE *outf)
{ ReadyNode *node;

  fprintf (outf, "******************** Ready Queue4 Dump\n");
  node = readyHead_Q4;
  while (node != NULL)
    { fprintf (outf, "%d, ", node->pid); node = node->next; }
  fprintf (outf, "\n");
}

//=========================================================================
// endIO list management
// processes that has finished waiting can be inserted into endIO list
//   -- when adding process to endIO list, should set endIO interrupt,
//      interrupt handler will move processes in endIO list to ready queue
// The list needs to be protected because multiple threads may insert
// to endIO list and a thread will remove nodes in the list concurrently
//=========================================================================

sem_t pmutex;

typedef struct EndIOnodeStruct
{ int pid;
  struct EndIOnodeStruct *next;
} EndIOnode;

EndIOnode *endIOhead = NULL;
EndIOnode *endIOtail = NULL;

void insert_endIO_list (int pid)
{ EndIOnode *node;

  sem_wait (&pmutex);
  node = (EndIOnode *) malloc (sizeof (EndIOnode));
  node->pid = pid;
  node->next = NULL;
  if (endIOtail == NULL) // endIOhead would be NULL also
    { endIOtail = node; endIOhead = node; }
  else // insert to tail
    { endIOtail->next = node; endIOtail = node; }
  sem_post (&pmutex);
}

// move all processes in endIO list to ready queue, empty the list
// need to set exeStatus from eWait to eReady

void endIO_moveto_ready ()
{ EndIOnode *node;

  sem_wait (&pmutex);
  while (endIOhead != NULL)
  { node = endIOhead;
    insert_ready_process_Q1 (node->pid);
    PCB[node->pid]->exeStatus = eReady;
    endIOhead = node->next;
    free (node);
  }
  endIOtail = NULL;
  sem_post (&pmutex);
}

void dump_endIO_list (FILE *outf)
{ EndIOnode *node;

  node = endIOhead;
  fprintf (outf, "endIO List = ");
  while (node != NULL)
    { fprintf (outf, "%d, ", node->pid); node = node->next; }
  fprintf (outf, "\n");
}

//=========================================================================
// Some support functions for PCB 
// PCB related definitions are in simos.h
//=========================================================================

void init_PCB_ptrarry ()
{ PCB = (typePCB **) malloc (maxProcess*addrSize); }

int new_PCB ()
{ int pid;

  pid = currentPid;
  currentPid++;
  if (pid >= maxProcess)
  { fprintf (infF, "\aExceeding maximum number of processes: %d\n", pid);
    // because we do not reuse pid, pid may run out, use max to
    // protect against potential integer overflow (though very unlikely)
    return (-1);
  }
  PCB[pid] = (typePCB *) malloc ( sizeof(typePCB) );
  PCB[pid]->Pid = pid;
  PCB[pid]->timeUsed = 0;
  PCB[pid]->numPF = 0;
  return (pid);
}

void free_PCB (int pid)
{
  free (PCB[pid]);
  if (cpuDebug) fprintf (bugF, "Free PCB: %d\n", PCB[pid]);
  PCB[pid] = NULL;
}

void dump_PCB (FILE *outf, int pid)
{
  fprintf (outf, "******************** PCB Dump for Process %d\n", pid);
  fprintf (outf, "Pid = %d\n", PCB[pid]->Pid);
  fprintf (outf, "PC = %d\n", PCB[pid]->PC);
  fprintf (outf, "AC = "mdOutFormat"\n", PCB[pid]->AC);
  fprintf (outf, "PTptr = %x\n", PCB[pid]->PTptr);
  fprintf (outf, "exeStatus = %d\n", PCB[pid]->exeStatus);
}

void dump_PCB_list (FILE *outf)
{ int pid;

  fprintf (outf, "Dump all PCB: From 0 to %d\n", currentPid);
  for (pid=idlePid; pid<currentPid; pid++)
    if (PCB[pid] != NULL) dump_PCB (outf, pid);
}

void dump_PCB_memory (FILE *outf)
{ int pid;

  fprintf (outf,
           "Dump memory/swap of all processes: From 1 to %d\n", currentPid-1);
  // dump_process_memory (outf, idlePid);
  for (pid=idlePid+1; pid<currentPid; pid++)
    if (PCB[pid] != NULL) dump_process_memory (outf, pid);
}


//=========================================================================
// process management
//=========================================================================

//#include "idle.c"

void clean_process (int pid)
{
  free_process_memory (pid);
  free_PCB (pid);  // PCB has to be freed last, other frees use PCB info
} 

void exiting_process (int pid)
{ PCB[pid]->exeStatus = CPU.exeStatus;
    // PCB[pid] is not updated, no point to do a full context switch

  // send exiting process printout to term.c, str will be freed by term.c
  char *str = (char *) malloc (80);
  if (CPU.exeStatus == eError)
  { fprintf (infF, "\aProcess %d has an error, dumping its states\n", pid);
    dump_PCB (infF, pid);
    dump_process_memory (infF, pid); 
    sprintf (str, "Process %d had encountered error in execution!!!\n", pid);
  }
  else  // was eEnd
  { fprintf (infF, "Process %d had completed successfully: Time=%d, PF=%d\n",
             pid, PCB[pid]->timeUsed, PCB[pid]->numPF);
    sprintf (str, "Process %d had completed successfully: Time=%d, PF=%d\n",
             pid, PCB[pid]->timeUsed, PCB[pid]->numPF);
  }
  insert_termIO (pid, str, exitProgIO);

  // invoke io to print str, process has terminated, so no wait state

  numUserProcess--;
  clean_process (pid); 
    // cpu will clean up process pid without waiting for printing to finish
    // so, io should not access PCB[pid] for end process printing
}

void initialize_process_manager ()
{
  init_PCB_ptrarry ();

  currentPid = 2;  // the next pid value to be used
  numUserProcess = 0;  // the actual number of processes in the system

  init_idle_process ();
  sem_init (&pmutex, 0, 1);
}

//================================================================
// submit_process always works on a new pid and the new pid will not be 
// used by anyone else till submit_process finishes working on it
// currentPid is not used by anyone else but the dump functions
// So, no conflict for PCB and Pid related data
// -----------------
// During insert_ready_process, there is potential of conflict accesses
//================================================================

int submit_process (char *fname)
{ int pid, ret, i;

  // if there are too many processes s.t. each cannot get sufficient memory
  // then reject the process
  if ( ((numFrames-OSpages)/(numUserProcess+1)) < 2 )
    fprintf (infF, 
  "\aToo many processes => they may not execute properly due to page faults\n");
  else
  { pid = new_PCB ();
    if (pid > idlePid)
    { ret = load_process (pid, fname);   // return #pages loaded
      if (ret > 0)  // loaded successfully
      { PCB[pid]->PC = 0;
        PCB[pid]->AC = 0;
        PCB[pid]->exeStatus = eReady;
        // swap manager will put the process to endIO list and then
        // process.c will eventually move it to ready queue
        // at this point, the process may not be loaded yet, but no problem
        numUserProcess++;
        return (pid);  // the only case of successful process creation
      }
      // else new_PCB returned -1, PCB has not been created
  } }
  // failed, PCB has not been created, exitProg
  char *str = (char *) malloc (80);
  fprintf (infF, "\aProgram %s has loading problem!!!\n", fname);
  sprintf (str, "Program %s has loading problem!!!\n", fname);
  insert_termIO (pid, str, exitProgIO);
  return (-1);
}

//================================================================
// execute_process: prepare; execute instruction; subsequent processing
// -----------------
// During insert_ready_process, there is potential of conflict accesses
//================================================================

void execute_process ()
{ int pid, intime;
  genericPtr event;


  pid = get_ready_process_Q1();
  if (pid != nullReady)
    // execute the ready process (with pid# = pid)
    //   before and after the execution, need to do:
    //   (1) context switch,
    //   (2) set execution status + check status to do subsequent actions
    //   (3) set timer to stop execution at the time quantum
    //   (4) accounting: add execution time to PCB[?]->timeUsed,
  { context_in (pid);   // === (1) 
    CPU.exeStatus = eRun;   // === (2) 
    intime = CPU.numCycles;   // ===(4) 
    event = add_timer (cpuQuantum, CPU.Pid,  // == (3) 
                       actTQinterrupt, oneTimeTimer);

      cpu_execution ();
      context_out (pid);  // === (1)
      PCB[pid]->timeUsed += (CPU.numCycles - intime);  // ===(4)

      if (CPU.exeStatus == eReady && (CPU.interruptV==CPU.interruptV | tqInterrupt)){
          insert_ready_process_Q2 (pid);  // === (2)
      }

      else if (CPU.exeStatus == ePFault || CPU.exeStatus == eWait) 
        // eWait: should have been handled by instruction execution
        // ePFault: calculate_memory_address should have set pFaultException,
        //   which is subsequently handled by page_fault_handler
        deactivate_timer (event);
      else // CPU.exeStatus == eError or eEnd, exiting
        { exiting_process (pid); deactivate_timer (event); }
      // Why deactivate_timer?
      //   If exeStatus != eReady ==> process is not stopped by time quantum
      //   but timer is still there ==> should be deactivated
      //   To deactivate: need the returned ptr from set timer: "event"
      //   If not: it will impact the execution of the next process
      // But if time quantum just expires and exeStatus != eReady
      //   No problem! eReady is only set upon tqInterrupt (in cpu.c)
      //    if the process had ePFault/eWait, it will not be set to eReady
  }else{

      // insert_ready_process_Q2(pid);
          pid = get_ready_process_Q2();
          
          if (pid != nullReady)
          {
            context_in (pid);
            CPU.exeStatus = eRun;   
            intime = CPU.numCycles;  
            event = add_timer (2*cpuQuantum, CPU.Pid, actTQinterrupt, oneTimeTimer);

              cpu_execution();
              context_out (pid); 
              PCB[pid]->timeUsed += (CPU.numCycles - intime); 

              if (CPU.exeStatus == eReady && (CPU.interruptV==CPU.interruptV | tqInterrupt)){
                insert_ready_process_Q3 (pid);  // === (2)
              }else if (CPU.exeStatus == ePFault || CPU.exeStatus == eWait) 
              deactivate_timer (event);
              else // CPU.exeStatus == eError or eEnd, exiting
              { exiting_process (pid); deactivate_timer (event); }
          }else{

                pid = get_ready_process_Q3();
                if (pid != nullReady)
                {
                    context_in (pid);
                    CPU.exeStatus = eRun;   
                    intime = CPU.numCycles;  
                    event = add_timer (3*cpuQuantum, CPU.Pid, actTQinterrupt, oneTimeTimer);

                    cpu_execution();
                    context_out (pid); 
                    PCB[pid]->timeUsed += (CPU.numCycles - intime); 
                    
                    if (CPU.exeStatus == eReady && (CPU.interruptV==CPU.interruptV | tqInterrupt)){
                        insert_ready_process_Q4 (pid);  // === (2)
                    }else if (CPU.exeStatus == ePFault || CPU.exeStatus == eWait){ 
                        deactivate_timer (event);
                    }else // CPU.exeStatus == eError or eEnd, exiting
                    { exiting_process (pid); deactivate_timer (event); }
              
                }else{


                  pid = get_ready_process_Q4 ();
                  if (pid != nullReady)
                    { context_in (pid);   
                      CPU.exeStatus = eRun;   
                      intime = CPU.numCycles;   
                      event = add_timer (4*cpuQuantum, CPU.Pid,  
                                        actTQinterrupt, oneTimeTimer);
                      cpu_execution ();
                      context_out (pid);  
                      PCB[pid]->timeUsed += (CPU.numCycles - intime);  
                      if (CPU.exeStatus == eReady) insert_ready_process_Q4 (pid); 
                      else if (CPU.exeStatus == ePFault || CPU.exeStatus == eWait) 
                        deactivate_timer (event);
                      else
                        { exiting_process (pid); deactivate_timer (event); }
                    }else execute_idle_process ();
                    // no ready process in the system, so execute idle process
                    // ===== see https://en.wikipedia.org/wiki/System_Idle_Process

                }
              }
  }
}

