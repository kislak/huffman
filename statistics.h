/* 
 * File:   statistics.h
 * Author: serge
 *
 * Created on March 28, 2015, 9:46 PM
 */
#include <unistd.h>

#ifndef STATISTICS_H
#define	STATISTICS_H

#ifdef	__cplusplus
extern "C" {
#endif

    int check_arguments(int argc, char **argv) {
        if (argc != 4) {
            printf("Error: Wrong format.\n");
            printf("Usage: %s ifile [-c|-x] ofile\n", argv[0]);
            return (EXIT_FAILURE);
        }

        if (strcmp(argv[2], "-c") && strcmp(argv[2], "-x")) {
            printf("Error: Wrong format.\n");
            printf("Usage: %s ifile [-c|-x] ofile\n", argv[0]);
            return (EXIT_FAILURE);
        }

        if (access(argv[1], F_OK) == -1) {
            printf("File %s doesn't exist.\n", argv[1]);
            return (EXIT_FAILURE);
        }

        return EXIT_SUCCESS;
    }

    void get_statistics(int result[], char *fname) {
        FILE *pFile = fopen(fname, "rb");
        int c;
        if (pFile == NULL) perror("Error opening file");
        else {
            while ((c = fgetc(pFile)) != EOF) {
                result[c]++;
            };
            fclose(pFile);
        }
    }


#ifdef	__cplusplus
}
#endif

#endif	/* STATISTICS_H */

