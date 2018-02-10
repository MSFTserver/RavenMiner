#ifndef ALGOS_H
#define ALGOS_H

#include <string.h>
#include "compat.h"

enum sha_algos {
	ALGO_X16R = 0,
	ALGO_AUTO,
	ALGO_COUNT
};

extern volatile enum sha_algos opt_algo;

static const char *algo_names[] = {
	"x16r",
	"auto", /* reserved for multi algo */
	""
};

// string to int/enum
static inline int algo_to_int(char* arg)
{
	int i;

	for (i = 0; i < ALGO_COUNT; i++) {
		if (algo_names[i] && !strcasecmp(arg, algo_names[i])) {
			return i;
		}
	}

	if (i == ALGO_COUNT) {
		// some aliases...
		if (!strcasecmp("all", arg))
			i = ALGO_AUTO;
		else
			i = -1;
	}

	return i;
}

#endif
