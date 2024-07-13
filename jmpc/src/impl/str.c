#include <jmp/str.h>
#include <jmp.h>

int jmp_strlen(char* str) {
  int i = 0;
  while (str[i++]) ;
  return i-1;
}

int jmp_streq(char* str1, char* str2) {
  if (jmp_strlen(str1) != jmp_strlen(str2)) return 0;
  
  int l = jmp_strlen(str1);
  for (int i = 0; i < l; ++i)
    if (str1[i] != str2[i]) return 0;
  
  return 1;
}

int jmp_streq2(char* str1, int idx, char* str2) {
  int s = 0;
  while (str1[idx+s++]) ;
  if (s-- != jmp_strlen(str2)) return 0;
  
  int l = jmp_strlen(str2);
  for (int i = 0; i < l; ++i)
    if (str1[idx+i] != str2[i]) return 0;
  
  return 1;
}

void  jmp_strcpy(char* dest, char* str) {
  int i = 0;
  while (str[i]) dest[i] = str[i++];
}

void  jmp_strcat(char* dest, char* str1, char* str2) {
  int i = 0;
  int j = 0;
  
  // Loop through the strings, adding them to the string.
  while (str1[i]) dest[i] = str1[i++];
  while (str2[j]) dest[i+j] = str2[j++];
  
  dest[i] = '\0';
}

char* jmp_strcat2(char* str1, char* str2) {
  char* str = malloc(jmp_strlen(str1) + jmp_strlen(str2) + 1);
  if (!str) exit(-1);
  
  int i = 0;
  int j = 0;
  
  // Loop through the strings, adding them to the string.
  while (str1[i]) str[i] = str1[i++];
  while (str2[j]) str[i+j] = str2[j++];
  str[i] = '\0';
  
  return str;
}
