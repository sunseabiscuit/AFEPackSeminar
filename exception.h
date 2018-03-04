#ifndef __EXCEPTION_H_
#define __EXCEPTION_H_

#include <cassert>

#ifdef DEBUG
#define Assert(cond, state) \
{ \
  if(!(cond)){\
  std::cerr << state << std::endl; \
  assert(cond);\
}}
#else
#define Assert(cond, state) {}
#endif


#endif
