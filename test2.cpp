#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// g++ test2.cpp -o test2
int main() {
	// this code simulates an attacker that aims to abuse the /proc/self/mem file
	int fd = open("/proc/self/mem", O_RDWR);
	if (fd < 0) {
		printf("Failed to open /proc/self/mem ... attacker blocked :) !!!\n");
	}
	else {
		printf("Opened /proc/self/mem ... attacker not blocked :( !!!\n");
		/* attackers here can do "bad" stuff with the fd and break the W^X policy */
		close(fd);
	}

	return 0;
}