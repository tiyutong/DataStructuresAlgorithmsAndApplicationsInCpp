#include "stdafx.h"
#include "xcept.h"

_PNH Old_Handler_ = _set_new_handler(my_new_handler);