#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<assert.h>
/*
：实现一个自己的命令行工具 stat，实现对一个文件或目录调用 stat() 函数即可。
将文件的大小、分配的磁盘块数、引用数等信息打印出来。当目录的内容发生变化时，目
录的引用计数如何变化？有用的接口：stat()。
*/
int main(int argc, char *argv[]){
    if(argc!=2){
        fprintf(stderr,"input one path");
        return 0;
    }
    char *path = argv[1];
    printf("%s\n", path);
    struct stat *buf = (struct stat*)malloc(sizeof(struct stat));
    int rs = stat(path, buf);
    printf("%d\n",rs);
    perror("wrong:");
    assert(rs==0);
    printf("the file information:\n\tsize: %d\n\tblocks: %d\n\treference:%d\n\tinode:%d", 
    buf->st_size, buf->st_blocks, buf->st_nlink, buf->st_ino);
    return 0;
}