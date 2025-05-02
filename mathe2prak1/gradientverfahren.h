#pragma once
#include "CMyVektor.h"
#include "gradient.h"

CMyVektor maximierung(CMyVektor x0, double lambda, double(*funktion)(CMyVektor x));