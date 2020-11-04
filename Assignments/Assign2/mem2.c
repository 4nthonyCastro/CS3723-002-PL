{\rtf1\ansi\ansicpg1252\cocoartf1671\cocoasubrtf200
{\fonttbl\f0\fmodern\fcharset0 Courier;}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;}
{\*\expandedcolortbl;;\cssrgb\c0\c0\c0;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\partightenfactor0

\f0\fs26 \cf0 \expnd0\expndtw0\kerning0
#include <stdio.h>\
#include <stdlib.h>\
\pard\pardeftab720\partightenfactor0
\cf0 #include <stdio.h>\
#include <stdlib.h>\
\
#define PRECHECK 0xAEAEAEAEAEAEAEAEL\
#define POSTCHECK 0xEAEAEAEAEAEAEAEAL\
\
//   +------------------------------------------+\
//   +      Pointer to next memory block        +\
//   +------------------------------------------+\
//   +       Size of User Data, in bytes        +\
//   +------------------------------------------+\
//   +             PRECHECK sentinel            +\
//   +------------------------------------------+\
//   +                                          +\
//   +                                          +\
//   +                User Data                 +\
//   +                                          +\
//   +                                          +\
//   +------------------------------------------+\
//   +            POSTCHECK sentinel            +\
//   +------------------------------------------+\
\
unsigned long *firstMemoryBlock = NULL;\
\
// Grab some memory\
void *getMem(int numBytes) \{\
  // TODO: Implement\
\}\
\
\
// Check one memory block for integrity\
void checkMem(unsigned long *longPtr) \{\
  // TODO: Implement\
\}\
\
\
// Free memory allocated by getMem\
void freeMem(void *userPtr) \{\
  // TODO: Implement\
\}\
\
\
// Check all the un-freed memory\
void finalMemoryCheck() \{\
  // TODO: Implement\
\}\
\
\
int main(int argc, char *argv[]) \{\
  char *userPtr;\
  \
  printf("===== Test 1\\n");\
  userPtr = getMem(1);\
  userPtr[0] = 'x';\
  userPtr[1] = 'y';\
  \
  printf("===== Test 2\\n");\
  userPtr = getMem(100);\
  userPtr[-30] = 'a';\
  userPtr[230] = 'b';\
  \
  printf("===== Test 3\\n");\
  userPtr = getMem(10);\
  userPtr[0] = 'x';\
  userPtr[9] = 'y';\
  freeMem(userPtr);\
  \
  printf("===== Test 4\\n");\
  userPtr = getMem(1000);\
  userPtr[-1] = 'a';\
  userPtr[1000] = 'b';\
\
  finalMemoryCheck();  \
  return 0;\
\}}