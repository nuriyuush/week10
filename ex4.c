//
//  main.c
//  test
//
//  Created by НУРИЯ on 10/22/20.
//  Copyright © 2020 НУРИЯ. All rights reserved.
// Nuriya Umirbekova exe4.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <libgen.h>

struct i_nodes{
    long i_node, cnt;
    char names[256][256];
};

int main()
{
    struct i_nodes files[256];
    int id=0;
    DIR *dirp=opendir("tmp/");
    struct dirent *dp;
    
    if (dirp==NULL)
    {
        printf(" 'tmp/' does not exist\n");
        return -1;
    }
    while((dp=readdir(dirp))!=NULL) {
        long number_of_i_nodes=dp->d_ino;
        int found=0;

        for (size_t i=0; i<256; i++)
        {
            if (files[i].i_node==number_of_i_nodes){
                
                strcpy(files[i].names[files[i].cnt], dp->d_name);
                files[i].cnt++;
                found=1;
            }
        }
        if (found==0){
            files[id].i_node = dp->d_ino;
            strcpy(files[id].names[files[id].cnt], dp->d_name);
            files[id].cnt++;
            id++;
        }
    }
    for(size_t i=0; i<id; i++) {
        if (files[i].cnt>=2){
            printf("%ld: \n", files[i].i_node);
            for(size_t j=0; j<files[i].cnt; j++){
                
                printf("%s \n", files[i].names[j]);
            }
            printf("\n");
        }
    }
    exit(0);
}
