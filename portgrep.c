#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fts.h>

#define PROG_NAME "portgrep"
#define PORTS_DIR "/usr/ports"
#define MAX_LEN	127

int main(int argc, char *argv[])
{
	FTS *fts;
	FTSENT *ftsent;
	
	FILE *fp;
	char str_buf[MAX_LEN + 1];
	
	char *fts_path[2] = { (char *)PORTS_DIR, NULL };
		
	if (argc != 3) {
		printf("Usage: %s <filename> <string>\n", PROG_NAME);
		return 1;
	}
	
	fts = fts_open(fts_path, FTS_PHYSICAL, NULL);
	if (fts == NULL) {
		printf("Couldn't read %s directory\n", PORTS_DIR);
		return 1;
	}
	
	while ((ftsent = fts_read(fts))) {
		switch (ftsent->fts_info) {
			case FTS_F:
				
				if (strcmp(ftsent->fts_name, argv[1]) == 0) {
					fp = fopen(ftsent->fts_path, "r");
					if (fp == NULL) {
						continue;
					}
					
					while (fgets(str_buf, MAX_LEN + 1, fp) != NULL) {
						if (strstr(str_buf, argv[2])) {
							printf("Found in: %s\n", ftsent->fts_path);
							printf("%s\n", str_buf);
						}
					}
					
					(void) fclose(fp);
				}
				break;
		}
	}
	
	(void) fts_close(fts);
	
	return 0;
}
