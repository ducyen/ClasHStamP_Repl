#pragma once
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#if defined(_MSC_VER)
#include <Windows.h>
#endif

using String = std::string;
using Bool = bool;
#if !defined(_MSC_VER)
using boolean = bool;
#endif
#define null nullptr

int InputValue(char* pMsg);
void DisplayMsg(char* pMsg);
