// fork-sleep program for ANU's CDS fork/pipe Lab 
#include <stdio.h>
#include <unistd.h>   //fork(), sleep()
#include <sys/time.h> //gettimeofday()
#include <sys/wait.h>
#define SLEEP_TIME 5
double get_elapsed_time();
int main(void) {
  pid_t fork_pid;
  double elp_time;

  // added
  int status; int wpid;

  elp_time = get_elapsed_time();
  printf("Hello from main   %14.6lf\n",elp_time);

  fork_pid = fork();
  if (fork_pid == 0) {
    elp_time = get_elapsed_time();
    printf("1st Hello from Child  %14.6lf\n", elp_time);
    sleep(SLEEP_TIME);
    elp_time = get_elapsed_time();
    printf("2nd Hello from Child  %14.6lf\n", elp_time);
  } else {
    elp_time = get_elapsed_time();
    printf("1st Hello from Parent %14.6lf\n", elp_time);

    /**
    elp_time = get_elapsed_time();
    printf("2nd Hello from Parent %14.6lf\n", elp_time);
    **/

    wpid = wait(&status);
    elp_time = get_elapsed_time();
    printf("2nd Hello from Parent wpid = %d exited = %d %14.6lf\n",
      wpid, WIFEXITED(status), elp_time);
  }

  elp_time = get_elapsed_time();
  printf("Good bye from %s %14.6lf\n", fork_pid==0? "Child": "Parent", 
         elp_time);
  return 0;
}

// function to get wall clock time since first call
double get_elapsed_time(void) {
  struct timeval mytime;
  static double start_time=0.0e0;
  double new_time;
  /* this function gets seconds and microseconds since the epoch */
  gettimeofday(&mytime, NULL);
  new_time = (double)mytime.tv_sec + mytime.tv_usec*1.0e-06;
  if (start_time <= 0.0e0) start_time = new_time; 
  return new_time-start_time; 
} 
