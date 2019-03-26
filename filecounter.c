//
//  main.cpp
//  Assignment2
//
//  Created by Ahmed Jallad on 3/4/19.
//  Copyright © 2019 AJProductions. All rights reserved.
//
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/param.h>
#include <stdint.h>

using namespace std;

static int numByte = 0; // holds the number of bytes
static int numDirectory = 0; // holds the number of directories
static int numFiles = 0; // holds the number of files

static int showContent(const char *path, const struct stat *s, int t, struct FTW *buff) {
    if(t == 0) {
        numFiles++; // if the flag is 0, then increment the number of files
        numByte = numByte + (intmax_t)s->st_size;
    }
    if(t == 1) {
        numDirectory++; // if the flag is 1 then you will increment the number of directories
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    char pathName[100];
    cout << "Please enter the path:  " << endl;
    cin.getline(pathName, 100);
    string path (pathName);
    string directory = " /Users/AhmedJ";
    string changeDirectory = path;
    
    chdir(directory.c_str());
    
    const char *call = changeDirectory.c_str();
    system("ls -lR | grep \"^d\" | wc -l");
    //system(call);
    system("ls");
    //string command = "ls -lR | grep \"^d\" | wc -l";
    //const char *call2 = command.c_str();
    //system(call2);
    
    return 0;
}
