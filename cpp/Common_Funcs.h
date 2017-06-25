#ifndef _COMMON_FUNCS_
#define _COMMON_FUNCS_

#include <assert.h>
#include <iostream>
#include <string>

#include "TypeDefs.h"
#include "Consts.h"

Bool v_assert(Bool val, const std::string& mesg);

inline double sqr(double x){
  return x * x;
}

#endif

