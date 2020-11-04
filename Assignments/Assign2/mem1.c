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
\
#define PRECHECK 0xAEAEAEAEAEAEAEAEL\
#define POSTCHECK 0xEAEAEAEAEAEAEAEAL\
\
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
// Grab some memory\
void *getMem(int numBytes) \{\
  // TODO: Allocation memory, fill in the two blocks at the top, and the block at the bottom\
  // Return a pointer to the User Data\
\} // End of getMem\
\
\
// Free memory allocated by getMem\
void freeMem(void *ptr) \{\
  // TODO: Check the two sentinels. If there are any problems, print an error message to stderr.\
  // Release (free) the memory\
\} // End of freeMem\
\
int main(int argc, char *argv[]) \{\
  char *ptr;\
  \
  printf("===== Test 1\\n");\
  ptr = getMem(10);\
  ptr[0] = 'x';\
  ptr[9] = 'y';\
  freeMem(ptr);\
  \
  printf("===== Test 2\\n");\
  ptr = getMem(1);\
  ptr[0] = 'x';\
  ptr[1] = 'y';\
  freeMem(ptr);\
  \
  printf("===== Test 3\\n");\
  ptr = getMem(100);\
  ptr[-100] = 'a';\
  ptr[200] = 'b';\
  freeMem(ptr);\
  \
  printf("===== Test 4\\n");\
  ptr = getMem(1000);\
  ptr[-1] = 'a';\
  ptr[1000] = 'b';\
  freeMem(ptr);\
  \
  return 0;\
\}}