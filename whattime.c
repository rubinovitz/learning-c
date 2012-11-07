#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 

int main (int argc, char **argv)
{
 


  int i;
  int time_fun();
  int daemon_fun();
  int k;

  for (i=0;i<argc;++i)
  {


// if the commandline argument is "-f" or blank call time_fun() every two seconds for 60 seconds
    if (strcmp(argv[i], "-f") == 0 || argc < 2)
    { 
             for (k = 1; k < 31; k++){
      
      time_fun();
      sleep(2);
}

 }
// if commandline argument is "-d" call daemon_fun()
    if (strcmp(argv[i], "-d") == 0)
    { 
      daemon_fun();}

  }
  exit(0);
}


// A function that returns the seconds since January 1, 1970 
int time_fun()
{
  time_t seconds;
  char * pPath;
  char * user;
  // get user path
  pPath = getenv ("HOME");
  // get user
  user = getenv("USER");
  // get time since Jan 1 1970 in seconds
  seconds = time (NULL);
  printf ("%ld - %s, %s \n", seconds, user, pPath);
  
  return 0;

}

  int daemon_fun(){
  pid_t childpid; /* variable to store the child's pid */
  int retval;     /* child process: user-provided return code */
  int status;     /* parent process: child's exit status */
      

  /* now create new process */
  childpid = fork();
    
  if (childpid >= 0) /* fork succeeded */
  {
    if (childpid == 0) /* fork() returns 0 to the child process */
    {
      /* **** WE ARE IN FIRST CHILD **** */
      childpid = fork();
      if (childpid >= 0) /* fork succeeded */
      {
        if (childpid == 0) /* fork() returns 0 to the child process */
        {
          /* **** WE ARE IN SECOND CHILD **** */
          /* GOOD: We are writing to a file instead of stdout */
          
            time_t seconds;
             // get User path
            char * pPath;
            char * user;
            FILE *file;
            file = fopen("mydaemon.log","w");
       
            int j;
            // every two seconds for 60 seconds write the time, user, and path to mydaemon.log file
            for (j = 1; j < 31; j++){
                file = fopen("mydaemon.log","a");
                pPath = getenv ("HOME");
                user = getenv("USER");
                seconds = time (NULL);
                fprintf (file, "%ld - %s, %s \n", seconds, user, pPath);
                fclose(file);
                sleep(2);

          
            }

          exit(0); /* child exits */

        }
      }
      else 
      {
        perror("fork"); 
        exit(0); 
      }
    }
else{
wait();
}
  }

}
