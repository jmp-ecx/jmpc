#ifndef __JMPC_STR_H
#define __JMPC_STR_H

int   jmp_strlen(char* str);
int   jmp_streq(char* str1, char* str2);
void  jmp_strcpy(char* dest, char* str);
void  jmp_strcat(char* dest, char* str1, char* str2);
char* jmp_strcat2(char* str1, char* str2);

#endif // __JMPC_STR_H
