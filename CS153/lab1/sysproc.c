#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  if(argint(0, &myproc()->exitStatus) < 0)
    return -1;
  exit(myproc()->exitStatus);
  return -1;  // not reached
}

// returns output of wait 
// calls wait function 
int
sys_wait(void)
{
  int* status_ptr;
  argptr(0, (char**) &status_ptr, 4);
  return wait(status_ptr);
}

int
sys_waitpid(void)
{

  int* status_ptr;
  int pid;
  int options;
  
  if(argint(0, &pid) < 0)
    return -1;
  argptr(1, (char**) &status_ptr, 4);
  if(argint(2, &options) < 0)
    return -1;
  return waitpid(pid, status_ptr, options); // maybe change arguments later
}

int
sys_lab1_test(void)
{
  lab1_test();
  return 0;
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

/* added */
int sys_getparents(void) {
  getparents();
  return 0;
}

int sys_test(void) {
  test();
  return 0;
}