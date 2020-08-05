/*
3．Tail：编写一个程序，输出一个文件的最后几行。这个程序运行后要能跳到文件末
尾附近，然后一直读取指定的数据行数，并全部打印出来。运行程序的命令是 mytail -n file，
其中参数 n 是指从文件末尾数起要打印的行数。有用的接口：stat()、lseek()、open()、read()
和 close()。
*/
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/uio.h>
#include<assert.h>
int main(int argc, char *argv[]){
    // char buf[1024];
    int fd = open(argv[2], O_RDONLY);
    struct stat st;
    int lines = atoi(argv[1]);
    lines *= -1;
    int rs = stat(argv[2], &st);
    assert(rs==0);
    char buf[st.st_size];
    int off = lseek(fd, -1, SEEK_END);
    assert(off!=-1);
    while(lines>0){
        if(read(fd, buf, 1) == -1){
            perror("read");
            return 1;
        }
        if(buf[0]=='\n'){
            lines--;
        }
        // read will move the CUR
        off = lseek(fd, -2, SEEK_CUR);
        if(off==-1)
            break;
    }
    if(off>0||lines==0){
        lseek(fd, 2, SEEK_CUR);
    }else{
        lseek(fd, 0 , SEEK_SET);
    }
    memset(buf, 0, st.st_size);
    if (read(fd, buf, st.st_size) == -1){
        perror("read");
        return 1;
    }
        
    printf("buf is\n %s\n", buf);
    close(fd);
    return 0;
}