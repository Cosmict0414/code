typedef struct _iobuf {
    int cnt;  // 剩余的字符，如果是输入缓冲区，那么就表示缓冲区中还有多少个字符未被读取
    char *ptr;  // 下一次读取时，要被读取的字符的地址
    char *base;  // 缓冲区基地址
    int flag;  // 读写状态标志位
    int fd;  // 文件描述符
    // 其他成员
} FILE;