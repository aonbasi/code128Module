#ifndef _TYPES_H_
#define _TYPES_H_

#define ARCH_X86

#define NULL 0

#ifdef ARCH_X86
#define ZB_U8 unsigned char
#define ZB_U16 unsigned short
#define ZB_U32 unsigned int
#define ZB_S8 char
#endif 

#ifdef ARCH_AVR
#define ZB_U8 unsigned char
#define ZB_U16 unsigned int
#define ZB_U32 unsigned long int
#define ZB_S8 char
#endif 

#endif
