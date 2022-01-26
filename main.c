#include <stdio.h>
#include <string.h>
#include "bloom_filter.h"

int arrSize = 6650;
int bitarray[6650] = { 0 };
char* sarray[1000];

int main(void) {

  //read data
  char * line = NULL;
  size_t len =0;
  FILE * fp;
  fp = fopen("data.txt","r"); 
  if(fp==NULL)
  {
    exit(EXIT_FAILURE);
  }
  for(int i=0;i<1000;++i)
  {
    getline(&line,&len,fp);
    sarray[i] = (char*)malloc(sizeof(char)*11);
    strcpy(sarray[i],line);
  }


  for (int i = 0; i < 500; i++) {
        insert(bitarray, arrSize, sarray[i]);
    }

  int wrong_ans=0;
  for (int i = 0; i < 1000; i++) {
      int a =lookup(bitarray, arrSize, sarray[i]);
      if(a && i<500)
        {
          //printf("%s is probabliy in bloom filter\n",sarray[i]);
        }
        else if(a&& i>=500)
        {
          wrong_ans++;
          //printf("it's wrong\n");
        }
        else
        {
          //printf("%s is not in bloom filter\n",sarray[i]);
        }
    }
    double wrong_per = wrong_ans/1000.0;
    
    printf("wrong ans percent = %lf",wrong_per);
  
  return 0;
}