#ifndef __HOUSEMENT_H
#define __HOUSEMENT_H

#define H_DEBUG

#ifdef H_DEBUG
# define debug_print(s) (Serial.print(s))
# define debug_println(s) (Serial.println(s))
//~ #else
//~ # define debug_print(s) ;
//~ # define debug_println(s) ;
#endif

#define buzzer 5

#endif // __HOUSEMENT_H
