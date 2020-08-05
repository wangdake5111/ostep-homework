/*
列出文件：编写一个程序，列出指定目录内容。如果没有传参数，则程序仅输出文
件名。当传入-l 参数时，程序需要打印出文件的所有者，所属组权限以及 stat() 函数获得的
一些其他信息。另外还要支持传入要读取的目录作为参数，比如 myls -l directory。如果没有
传入目录参数，则用当前目录作为默认参数。有用的接口：stat()、opendir()、readdir()和 getcwd()
*/
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<assert.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
void printFile(char *name){
    struct stat buf;
    int rs = stat(name, &buf);
    assert(rs==0);
    printf("the file name is : %s\n\t \
    its information:\n\t \
    size: %d\n\t \
    blocks: %d\n\t \
    reference:%d\n\t \
    inode:%d\n", \
    name, buf.st_size, buf.st_blocks, buf.st_nlink, buf.st_ino);
}
int main(int argc, char *argv[]){
    int ch;
    char *dir = ".";
    int have_l = 0;
    struct stat st;
    DIR *dirp;
    opterr = 0;
    while((ch=getopt(argc, argv, "l:"))!=-1){
        printf("haha\n");
        switch(ch)
        {
            case 'l':
                  dir = optarg;
                  have_l = 1;
                  break;
            case '?':
                    if(optopt=='l')
                        have_l = 1;
                    break;
        }
    }
    if(!have_l&&argc>1){
        dir = argv[1];
    }
    printf("dir:%s\n", dir);
    int rs = stat(dir, &st);
    assert(rs==0);
    struct dirent * dire;
    if(S_ISDIR(st.st_mode)){
        
        dirp=opendir(dir);
        if(dirp==NULL){
            perror("opendir");
            return -1;
        }
        if(strcmp(dir, ".")!=0){
            while((dire = readdir(dirp))!=NULL){
                if(have_l){
                    // printf("the dir is %s\n\n", dir);
                    // printf("the name is %s\n\n\n", dire->d_name);
                    char path[1024] = "";
                    // printf("the path is %s\n\n", path);
                    strncpy(path, dir, strlen(dir));
                    // printf("the path is %s\n\n", path);
                    strncat(path, "/", 1);
                    strncat(path, dire->d_name, strlen(dire->d_name));
                    // printf("the path is %s\n\n", path);
                    printFile(path);
                }
                printf("%s\n", dire->d_name);
        }        

        }else{
            while((dire = readdir(dirp))!=NULL){
                if(have_l){
                    printFile(dire->d_name);
                }
                printf("%s\n", dire->d_name);
            }

        }
        
    }

}