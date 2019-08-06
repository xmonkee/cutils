#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
	int pid = fork();
	if(pid == -1) {
		perror("fork"); return 1;
	}
	if(!pid) { //child
		int ret;
		ret = execlp("ls", "ls", NULL);
		if (ret == -1) {
			perror("exec"); return 1;
		}
	} else {
		printf("Parent\n");
	}

}
