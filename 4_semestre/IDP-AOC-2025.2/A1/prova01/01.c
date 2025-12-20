#include <stdio.h>
#include <stdbool.h>

int f(const int *p, int acc){
	while(true) {
		int x = *p;
		if(x == 0){
			break;
		}

		acc += x;
		p++;
	}

	return acc;
}
