#pragma once
#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using String = std::string;
using Bool = bool;
#define null nullptr

int _InputValue(String pMsg);
#define InputValue(pMsg)    _InputValue((String)pMsg)
void _DisplayMsg(String pMsg);
#define DisplayMsg(pMsg)    _DisplayMsg((String)pMsg)
