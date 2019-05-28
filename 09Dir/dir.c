#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <math.h>

void dir_size() {
	//opens directory
	DIR * f;
	struct dirent * d;
	f = opendir(".");
	
	//goes through each file to and adds to size
	struct stat storage;
	int truesize;
	while ((d = readdir(f)) != NULL) {
		stat(d->d_name, &storage);
		truesize += storage.st_size;
	}
	
	closedir(f);
	
	//into human readable size
    int i = 0;
	while ((truesize % (int)pow(1024, i)) > 0){ //raises the power of 1024 to i
    	i++;
  	}
	float human_read = (truesize / (pow(1024, i)));
	char * size = malloc(2);
	if (i == 0){size = "B";};
	if (i == 1){size = "KB";};
	if (i == 2){size = "MB";};
	if (i == 3){size = "GB";};
	printf("Total Directory Size: %f%sB\n", human_read,size);
}

void dir_files() {
	//opens directory
	DIR * f;
	struct dirent *d;
	f = opendir(".");
	
	printf("Directories:\n");
	while ((d = readdir(f)) != NULL) {
		if (d->d_type == DT_DIR) {
			printf("        \t%s\n", d->d_name);
		}
	}
	
	rewinddir(f);
	printf("Regular files:\n");
	while ((d = readdir(f)) != NULL) {
		if (d->d_type != DT_DIR) {
			printf("        \t%s\n", d->d_name);
		}
	}
	closedir(f);
	
}

int main() {
	printf("Statistics for directory: .\n");
	dir_size();
	dir_files();
	return 0;
}