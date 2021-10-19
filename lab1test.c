#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"
int main(int argc, char *argv[]){
  
  int pid1, pid2, pid3;    
  if ((pid1 = fork()) == 0) {
    settickets(30);
    struct pstat info = {0};
    getpinfo(&info);
  }
  else if ((pid2 = fork()) == 0) {
    settickets(20);
    struct pstat info = {0};
    getpinfo(&info);
  }
  else if ((pid3 = fork()) == 0) {
    settickets(10);
    struct pstat info = {0};
    getpinfo(&info);
  }
  wait();
  wait();
  wait();
  exit();
}
