#include <stdio.h>
#include <sys/mman.h>

// g++ test1.cpp -o test1
int main() {
	void* region = mmap(0, 4096, PROT_READ, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if (region == MAP_FAILED) {
		printf("Should never go here\n");
	}
	else {
		// here we simulate an attacker that abuses system calls to bypass the W^X policy
		int err = mprotect(region, 4096, PROT_EXEC | PROT_WRITE);
		if (err == 0) {
			printf("Attacker managed to bypass the W^X policy\n");
		}
		else {
			printf("Succeeded to mitigate the attacker\n");
		}
	}

	return 0;
}
