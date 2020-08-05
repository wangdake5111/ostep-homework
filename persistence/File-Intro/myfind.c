/*
4．递归查找：编写一个程序，打印指定目录树下所有的文件和目录名。比如，当不带
参数运行程序时，会从当前工作目录开始递归打印目录内容以及其所有子目录的所有内容，
直到打印完以当前工作目录为根的整棵目录树。如果传入了一个目录参数，则以这个目录
为根开始递归打印。可以添加更多的参数来限制程序的递归遍历操作，可以参照 find 命令。
有用的接口：自己想一下。
*/
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<assert.h>
#include<unistd.h>
#include<dirent.h>
#include<stdlib.h>
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
void getDir(char *name){
    DIR *dir;
    struct dirent *dire;
    // printf("here\n");
    dir = opendir(name);
    // printf("there\n");
    if(dir==NULL){
        perror("opendir");
        return;
        // exit(1);
    }
    while((dire = readdir(dir))!=NULL){
        printf("%s\n", dire->d_name);
        char pathname[1024] = "";
        strncpy(pathname, name, strlen(name));
        strncat(pathname, "/", 1);
        strncat(pathname, dire->d_name, strlen(dire->d_name));
        // printf("the path name is: %s\n", pathname);
        
        if (dire->d_type == DT_DIR){
            // printf("the dir is %s\n", dire->d_name);
            if(strcmp(dire->d_name,".")==0||strcmp(dire->d_name,"..")==0){
                // printf("inaaaaaaaaaaaaaaaaaaaa\n");
                continue;
            }
            // printf("1\n");
            getDir(pathname);
            // printf("2\n");

        }
        // printf("3\n");
    }
    closedir(dir);
}
int main(int argc, char *argv[]){
    char *dir = ".";
    if (argc==2){
        dir = argv[1];
    }
    printf("the path is %s\n", argv[1]);
    // DIR *dirp;
    struct stat st;
    int rs = stat(dir, &st);
    assert(rs==0);
    if(!S_ISDIR(st.st_mode)){
        printFile(dir);
        return 0;
    }
    // struct dirent *dire;
    getDir(dir);
}