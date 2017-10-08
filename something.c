#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>
#include <arpa/inet.h>
 
void *read_image(char *path) {
        int fd = open(path, O_RDONLY);
        if (fd < 0) {
            return NULL;
        }
        size_t size = 1000;
        size_t offset = 0;
        size_t res;
        char *buff = malloc(size);
 
        while((res = read(fd, buff + offset, 100)) != 0) {
                offset += res;
                if (offset + 100 > size) {
                        size *= 2;
                        buff = realloc(buff, size);
                }
        }
        close(fd);
        return buff;
}
int main(int argc,char* argv[]){
    uint8_t* f = read_image(argv[1]);
    uint32_t width = 0, height = 0;
    for(uint8_t i =0;i<1000000;i++){
        uint8_t*current= f+i;
        printf("%x  ",*current);
        if(*(f+i)==73)
            if(*(f+i+1)==72)
                if(*(f+i+2)==68)
                    if(*(f+i+3)==82)
                    {
                        printf("ima go");
                width =*(uint32_t*)(f+i+4);
                width = ntohl(width);
                printf("%d",width);
                        break;
                    }
    }
 
    return 0;
}
