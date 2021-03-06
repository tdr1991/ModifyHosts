#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

static int find_directory (const char *dirname, const char *fileName);


int test(int argc, char *argv[]) 
{
    int i;
    int ok;

    /* For each directory in command line */
    /*i = 1;
    while (i < argc) {
        ok = find_directory (argv[i]);
        if (!ok) {
            exit (EXIT_FAILURE);
        }
        i++;
    }*/

    /* List current working directory if no arguments on command line */
    /*if (argc == 1) {
        find_directory (".");
    }*/

	find_directory ("E:\\20161229040152801", "hosts");
    return EXIT_SUCCESS;
}

/* Find files and subdirectories recursively */
static int find_directory(const char *dirname, const char *fileName)
{
    DIR *dir;
    char buffer[PATH_MAX + 2];
    char *p = buffer;
    const char *src;
    char *end = &buffer[PATH_MAX];
    int ok;

    /* Copy directory name to buffer */
    src = dirname;
    while (p < end  &&  *src != '\0') 
	{
        *p++ = *src++;
    }
    *p = '\0';

    /* Open directory stream */
    dir = opendir (dirname);
    if (dir != NULL) {
        struct dirent *ent;

        /* Print all files and directories within the directory */
        while ((ent = readdir (dir)) != NULL) {
            char *q = p;
            char c;

            /* Get final character of directory name */
            if (buffer < q) {
                c = q[-1];
            } else {
                c = ':';
            }

            /* Append directory separator if not already there */
            if (c != ':'  &&  c != '/'  &&  c != '\\') {
                *q++ = '/';
            }

            /* Append file name */
            src = ent->d_name;
            while (q < end  &&  *src != '\0') {
                *q++ = *src++;
            }
            *q = '\0';

            /* Decide what to do with the directory entry */
            switch (ent->d_type) {
            case DT_LNK:
            case DT_REG:
                /* Output file name with directory */
				if(strcmp(ent->d_name, fileName) == 0)
			   {
				   printf ("%s\n", buffer);
				   break;
			   }				
                break;

            case DT_DIR:
                /* Scan sub-directory recursively */
                if (strcmp (ent->d_name, ".") != 0  
                        &&  strcmp (ent->d_name, "..") != 0) {
							find_directory (buffer, fileName);
                }
                break;

            default:
                /* Ignore device entries */
                /*NOP*/;
            }
        }
        closedir (dir);
        ok = 1;

    }
	else {
        /* Could not open directory */
        printf ("Cannot open directory %s\n", dirname);
        ok = 0;
    }

    return ok;
}