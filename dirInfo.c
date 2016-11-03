#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  DIR *dirr = opendir(".");
  struct dirent *entry = readdir(dirr);
  if (entry == NULL){
    printf("error: %d - %s\n", errno, strerror(errno));
    return -1;
  }
  int dirSize = 0;
  struct stat data;
  char *dirList = malloc(sizeof(*dirList));
  char *fileList = malloc(sizeof(*fileList));
  while (entry != NULL){
    stat(entry -> d_name, &data);
    if (S_ISREG(data.st_mode)){
      dirSize += data.st_size;
      strcat(fileList, "\t");
      strcat(fileList, entry -> d_name);
      strcat(fileList, "\n");
    }
    else {
      strcat(dirList, "\t");
      strcat(dirList, entry -> d_name);
      strcat(dirList, "\n");
    }
    entry = readdir(dirr);
  }
  closedir(dirr);
  printf("Printing directory statistics...\n\n");
  printf("Total directory size: %d bytes\n", dirSize);
  printf("Directories:\n%s", dirList);
  printf("Files:\n%s", fileList);
  //free(dirList);
  //free(fileList);
  return 0;
}
