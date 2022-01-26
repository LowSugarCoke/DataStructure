#include "bloom_filter.h"

int h1(char* s, int arr_size){
  int hash = 0;
  int s_len = strlen(s);
    for (int i = 0; i < s_len; i++) 
    {
        hash = (hash + ((int)s[i]));
        hash = hash % arr_size;
    }
    return hash;
}
int h2(char* s, int arr_size){
    int hash = 1;
    int s_len = strlen(s);
    for (int i = 0; i < s_len; i++) 
    {
        hash = hash + pow(6, i) * s[i];
        hash = hash % arr_size;
    }
    return hash % arr_size;
}
int h3(char* s, int arr_size){
    int hash = 7;
    int s_len = strlen(s);
    for (int i = 0; i < s_len; i++) 
    {
        hash = (hash * 31 + s[i]) % arr_size;
    }
    return hash % arr_size;
}
int h4(char* s, int arr_size){
    int hash = 3;
    int p = 5;
    int s_len = strlen(s);
    for (int i = 0; i < s_len; i++) {
        hash += hash * 7 + s[0] * pow(p, i);
        hash = hash % arr_size;
    }
    return hash;
}


int lookup(int* bitarray, int arr_size, char* s)
{
    int a = h1(s, arr_size);
    int b = h2(s, arr_size);
    int c = h3(s, arr_size);
    int d = h4(s, arr_size);
  
    if (bitarray[a] 
     && bitarray[b] 
    && bitarray[c]
   && bitarray[d]
  )
        {
          return 1;}
    else
    {
        return 0;
        }
}
void insert(int* bitarray, int arr_size, char* s){
  // check if the element in already present or not
    if (lookup(bitarray, arr_size, s))
    {
        //printf("%s is Probably already present\n",s);
    }
    else 
    {
        int a = h1(s, arr_size);
        int b = h2(s, arr_size);
        int c = h3(s, arr_size);
        int d = h4(s, arr_size);
  
        bitarray[a] = 1;
        bitarray[b] = 1;
        bitarray[c] = 1;
        bitarray[d] = 1;
  
        //printf("%s inserted\n",s);
    }
}