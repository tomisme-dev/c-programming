# 1. 函数与程序结构
## 1.1. 作用域
函数需要使用到其他文件的函数/变量时，需要使用```extern```关键字声明一下外部函数/变量，否则编译报错
```c
extern void f(int);
extern int sum;
int main(int argc, char const *argv[])
{
    f(3);
    int x = sum + 1;
    return 0;
}
```

## 1.2. 头文件
- .h格式的文件
- 是一些函数/变量声明的集合
```c
#define NUMBER '0'

void push(double);
double pop(void);
```

## 1.3. 静态变量
- static 修饰
- 只能在源文件中使用
- 初始化一次
- 存放在process 私有线程空间data片段中
- static 也可修饰函数，被修饰后的函数外部方法无法访问
- 也可修饰方法内部的局部变量

```c
static char buf[BUFSIZE];  /* buffer for ungetch */

void f() {
    static int count = 0; // 由于static 修饰的变量不是存储在stack中，因而不会随着方法调用的结束而回收
    count++;
}
```
## 1.4. 寄存器变量
1. 告诉编译器，这种变量使用频率高。但编译器也可以忽略它

```c
register int x;
register char c;
```

## 1.5. c预处理器
1. 预处理是编译的第一步
2. 常见的预处理指令
   - #include: 编译期将指定的文件内容包含进当前文件
   - #define: 用任意字符序列替换某一个标记
### 1.5.1. 文件包含
1. 包含格式
   1. #include "文件名"
   2. #include <文件名>
2. 大程序中，#include指令是将所有声明捆绑在一起的好方法，保证了所有源文件具有相同的函数/变量声明和定义

### 1.5.2. 宏替换
1. 书写格式
    ```c
    #define 名字 替换文本
    ```
2. 不需要已分号结尾，多行书写时，需要在行尾加上\
3. 不会替换引号内部匹配到的字符串
4. 替换文本可以是任意的，比如
   ```c
    #define forever for(;;)
   ```
5. 宏定义也可带参数, 注意需要加上括号保证执行顺序
   ```c
    #define max(A, B) ((A) > (B) ? (A) : (B))
   ```
6. ```#undef MAX```取消宏的定义，取消后，此处后面的代码不可以再使用```MAX```这个宏
7. 通过在宏参数前加上#号，可以让其变成字符串
```c
#define  dprint(expr)   printf(#expr " = %g\n", expr)
//使用dprint(x/y)时，等价于
printf("x/y" " = &g\n", x/y);

#define cat(x,y) x##y
cat(tom,12); // 等价于tom12
 
```


### 1.5.3. 条件包含
1. 在编译过程中，根据计算所得的条件值选择性得包含不同代码
2. 常用语法，满足条件后，才会将符合条件后的内容纳入编译范畴
```c
// #if 后面跟的是常量表达式
#if SYSTEM == SYSV
    #define HDR "sysv.h"
#elif SYSTEM == BSD
    #define HDR "bsd.h"
#elif SYSTEM == MSDOS
    #define HDR "msdos.h"
#else
    #define HDR "default.h"
#endif
#include HDR
```
3. 判断某个宏是否被定义
   1. 使用defined函数
    ```c
    #if !defined(HDR) //判断是否已经定义了HDR
        #define HDR
        /* */
    #endif
    ```
    2. 使用```#ifdef```和```#ifndef```预处理语句
    ```c
    #ifndef HDR
        #define HDR
        /*  */
    #endif
    ```
# 2. 指针与数组
> ANSI C使用```void *```代替```char *```作为通用指针的类型

## 2.1. 指针与地址
1. 取地址运算符```&a```,只能应用与内存中的对象，不能作用于表达式，常量，register类型的变量
```
    register int x = 1;
    int *p = &x; // 编译报错，不能取register变量的地址
```

### 2.1.1. 指针与数组

1. 指针可以完成所有数组下标下的操作

2. 指针编写的程序效率比数组下标效率高，但可读性差一些

   ```c
   // 这两种方式等价
   pa[i];
   *(pa+1);
   ```

3. 指针是变量，可以赋值；数组名不是变量，不允许赋值，但作为方法形参可以赋值

   ```c
   void f1(char a[]) {
       a++; // 此处a可以++
       char b[] = "abc";
     	// b++; // 编译报错，此处b不可以++
       printf("%d\n", *(a));
   }
   ```

   

### 2.2.2. 地址算术运算

1. 指针可以与算术值+/-，但会考虑到指针类型所指向的值大小，按对象长度进行比例缩放

   ```c
   int arr[12];
   int *p = arr + 3； //由于一个int是4字节，此处相当于p = arr + 3 * 4
   ```

2. 算術值中，只有0可以賦值給指針

## 2.2. 字符指针与函数

1. 字符串两种定义方式

   ```c
   /** 方式1: 采用指针接受
   	s1字符串存储在.rodata部分，字符串值不允许修改
   */
   char *s1 = "hello";
   /** 方式1: 采用数组接受
   	s2字符串已char数组的形式存储在stack中，允许修改
   */
   char s2[] = "world";
   ```

## 2.3 指针数组以及指针的指针

```c
char *lines[100]; // 指针数组
char **p; // 指针的指针
```

## 2.4 多维数组

```c
static char daytab[2][13] = {
       {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
   };
```

1. 多维数组是一种特殊的一维数组

2. 二维数组重要的是列数，所以其作为形参传递时，必须要指定列数

   ```c
   // 这三种声明方式都是可以的
   f(int daytab[2][13]) { ... }
   f(int daytab[][13]) { ... }
   f(int (*daytab)[13]) { ... }
   ```

## 2.5 指向函数的指针

```c
// comp作为一个函数指针
void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *)) {
    // 使用comp
    int result = (*comp)('a', 'b');
}

int numcmp(char *c1, char *c2) {
    return *c1 - * c2;
}
int main() {
    // 将函数传递过去
    qsort(lineptr, left, right, numcmp);
}
```

## 2.6 复杂声明

```c
int *f(); // 一个函数声明，f函数返回一个int类型
int (*pf)(); // 函数指针，pf指向一个函数，该函数返回int类型
```



# 3. 结构

## 3.1 基本知识

```c
// 1.声明方式
struct point {
    int x;
    int y;
};

// 2.声明的同时创建变量
struct {
    int x;
    int y;
} p1, p2;

// 3.声明后再定义变量
struct point p1, p2;

// 4.声明变量的同时初始化
struct point p1 = {100, 200}
```

## 3.2 结构与函数

函数传递结构的两种方式

1. 值传递，会复制整个结构

   ```c
   struct point f(struct point p1) {
       // 会将调用者的数据复制到p1
       p1.x = 12;
       p2.y = 13;
       return p1;
   }
   ```

   

2. 指针传递，不会复制结构，效率较高

   ```c
   struct point *f(struct point *ptr1) {
       ptr1->x = 12; // 等价于 (*ptr1).x = 12;
       ptr1->y = 13;
       return ptr1;
   }
   ```

3. 以下四种运算符优先级最高

   - .
   - ->
   - ()
   - []

## 3.3 结构数组

```c
struct key {
    char *word;
    int count;
} keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0}
};

// 由于keytab的size在编译期已经确定，可以通过下列方法获得
#define KEYTSIZE (sizeof(keytab) / sizeof(keytab[0]))
```

## 3.4 类型定义-typedef

1. 使用方法

   ```c
   // typedef 类型 自定义别名;
   typedef int Length;
   typedef char* String;
   typedef struct tnode* Treeptr; //定义Treeptr为指向tnode的一个指针
   typedef int (*PFI)(char *, char *); //定义PFI为一个指向一个方法的指针
   ```

   

2. typedef并没有创建一个新类型，而是为已有结构增加一个新名称
3. typedef类似与#define语句（由预处器处理），但typedef由编译器解释，因此文本替换功能超过预处理器的能力

## 3. 5 联合

1. 使用方法

   ```c
   // 声明
   union u_tag {
          int ival;
          float fval;
          char *sval;
   } u, *uptr;
   // 使用
   int x = u.ival;
   float f = u.fval;
   int x2 = uptr->ival;
   ```

2. 只在占用一份内存，只是采用不同类型的解析方式

## 3.6 位字段

1. 判断某个bit位的值，常采用“屏蔽码”的方式，必须是2的幂

   ```c
   // 方式1，通过#define
   #define KEYWORD  01
   #define EXTRENAL 02
   #define STATIC   04
   
   // 方式2，通过枚举
   enum { KEYWORD = 01, EXTERNAL = 02, STATIC = 04 };
   ```

   

2. 通过c语言定义的位字段实现

   ```c
   struct
   {
       unsigned int is_keyword : 1; // 定义is_keyword占用的位长
       unsigned int is_extern : 1;
       unsigned int is_static : 1;
   } flags;
   // char : 0 0 0 0 0 0(=>is_static) 0(=>is_extern) 0(=>is_keyword)
   ```

# 4. 输入与输出

## 4.1 标准输入输出

1. ```getchar```函数

   > 可以从控制台输入，可以重定向```prog < infile```

2. ```int putchar(int)```将某个字符送到标准输出

## 4.2 格式化输出

1. 输出到标准输出

   ```c
   int printf(char *format, arg1, arg2, ...);
   ```

   

2. 输出到字符串

   ```c
   int sprintf(char *string, char *format, arg1, arg2, ...);
   ```

## 4.3 可变长参数表

1. 声明形式

   ```c
   void minprintf(char *fmt, ...); // ...一定出现在最后
   ```

2. 使用案例

   ```c
   /**
   	@param arg_num 可变参数的个数
   */
   int sum(int arg_num, ...) {
       int total = 0;
       va_list ap; /* points to each unnamed arg in turn */
       va_start(ap, arg_num); /* make ap point to 1st unnamed arg */
   
       int ival = 0;
       for(int i = 0; i < arg_num; i++) {
           int ival = va_arg(ap, int); // 运行完后，指向下一个参数
           total += ival;
       }
   
       va_end(ap); /* clean up when done */
       return total;
   }
   ```

   

## 4.4 格式化输入-scanf

1. 从标准输入扫描

   ```c
   /**
   1. 可变参数均必须是指针
   2. scanf扫描完格式串，或某些输入与格式不匹配时，该函数将终止
   3. 返回值为成功匹配项的数量
   */
   int scanf(char *format, ...);
   
   // 使用案例
   int year, month, day;
   scanf("%d/%d/%d", &year, &month, &day);
   printf("%d年-%d月-%d日\n", year, month, day);
   ```

2. 从本文扫描

   ```c
   int sscanf(char *string, char *format, arg1, arg2, ...)
   ```

3. scanf和其他输入函数共用时，下一个输入函数的调用将从scanf没读取的第一个字符处开始读

   

## 4.5 文件访问

1. 打开/关闭文件

   ```c
   // 打开一个文件
   FILE *fp;
   /**
   	mode: "r", "w", "a" 或者他们的组合
   */
   FILE *fopen(char *name, char *mode);
   
   // 关闭文件, 释放资源，同时将putc的内容刷新到文件中
   int fclose(FILE *fp);
   ```

2. 读取/写入文件

   ```c
   // 读取文件
   int getc(FILE *fp);
   
   // 写入文件
   int putc(FILE *fp);
   ```

3. 已经定义的一些标准流

   1. stdin, 标准输入流
   2. stdout, 标准输出流
   3. stderr, 标准错误流

4. 文件相关的标准输入输出流

   ```c
   int fscanf(FILE *fp, char *format, ...)
   int fprintf(FILE *fp, char *format, ...)
   ```

5. 标准输入输出也可关闭，关闭后可通过```freopen```重新打开

   

## 4.6 错误处理--stderr和eixt

1. stderr, 标准错误流

   ```c
   if (ferror(stdout)) { // ferror用于判断某个流中是否发生异常的函数
       fprintf(stderr, "%s: error writing stdout\n", prog);
       exit(2);
   }
   ```

2. ```int feof(FILE *fp)```用于判断某个流是否结束

3. 使用```exit(int num)```函数可以退出程序，调时exit时，会自动为每一个打开的输出流调用fclose, 并将缓存中的数据写入对应文件

   

## 4.7 行输入和行输出

1. 读取一行数据, 结尾的换行符会被删掉

   ```c
   // 最多可以读取maxline-1个字符，因为最后一个要放置'\0'，line中不会包含'\n'
   char *fgets(char *line, int maxline, FILE *fp);
   ```

2. 写入一行，```fputs```会额外追加写入一个换行符\n

   ```c
   // 发生错误时返回EOF，否则返回一个非负值
   int fputs(char *line, FILE *fp);
   ```



## 4.8 其他字符串函数

1. ```strcat(s, t)``` 字符串s与t拼接
2. ```strncat(s, t, n) ```将字符串s与t的前n个字符串拼接
3. ```strcmp(s, t)``` 比较字符串大小
4. ```strncmp(s, t, n)``` 在前n个字符串中比较s与t的大小
5. ```strcpy(s, t)``` 将t复制到s中
6. ```strncpy(s, t, n)``` 将t中的前n个复制到s中
7. ```strlen(s)``` 字符串长度
8. ```strchr(s, c)``` 在字符串s查找字符c第一次出现的位置
9. ```strrchr(s, c) ```在字符串s查找字符c最后一次出现的位置



## 4.9 字符类别测试和转换函数

```c
// 字符类别测试
isalpha(c);
isupper(c);
islower(c);
isdigit(c);
isalnum(c);
isspace(c);
// 大小写转换
toupper(c);
tolower(c);
```



##  4.10 其他函数

1. ungetc函数

   ```c
   // 多读了一个字符时，使用这个函数返还多读的字符
   // 可以和任何一个输入函数一起使用，比如：fscan, getc, getchar
   int ungetc(int c, FILE *fp);
   ```

2. 命令执行函数--sysetem

   ```c
   #include <stdlib.h>
   // 执行系统的某个命令，比如 system("date");等价于在控制台输入date命令
   // 返回值时exit函数的参数值
   int system(char *command);
   ```

3. 内存管理函数

   ```c
   // 返回一个未初始化的内存块
   void *malloc(size_t n);
   // 返回一个所有值初始化为0了的内存块
   void *calloc(size_t n, size_t size);
   /**
   1. 禁止释放一个不是由malloc或者calloc获得的内存
   2. 释放内存后，p的值应该再被使用
   */
   void free(void *p);
   ```

4. 数学函数

   ```
   sin(x);
   cos(x);
   atan2(y,x);
   exp(x);
   log(x);
   log10(x);
   pow(x,y);
   sqrt(x);
   fabs(x);
   ```

5. 随机数函数

   ```c
   // 1. 设置一个种子
   srand(unsigned seed);
   // 2. 调用随机函数，返回一个0~RAND_MAX (inclusive)
   rand();
   
   //使用案例
   #include <stdio.h>
   #include <stdlib.h>
   #include <sys/time.h>
   #include <unistd.h>
   
   unsigned int current_ms() {
       struct timeval tv;
       gettimeofday(&tv, NULL);
       return tv.tv_sec * 1000000 + tv.tv_usec;
   }
   
   
   int main(int argc, char const *argv[])
   {
       int r = 5;
       srand(current_ms()); // 设置一个种子
       for(int i =0; i < 10; i++) {
   
           printf("%d\n", rand());
           // printf("%d\n");
       }
       return 0;
   }
   ```



# 8. UNIX系统接口

## 8.1 文件描述符

1. unix为每一个打开的文件分配一个小的唯一的正整数作为文件描述符

2. 0, 1, 2 分别是标准输入，标准输出，错误输出的文件描述符

3. io重定向

   ```shell
   > prog < 输入文件名
   > prog > 输出文件名
   ```



## 8.2 低级io

1. 输入函数

   ```c
   int n_read = read(int fd, char *buf, int n);
   ```

2. 输出函数

   ```c
   int n_written = write(int fd, char *buf, int n);
   ```



##  8.3 open, create , close, unlink函数

1. 打开文件

   ```c
   #include <fcntl.h>
   /**
   
   @param name 文件路径
   @param flags 打开方式，可选值：O_RDONLY， O_WRONLY， O_RDWR
   @param perms 权限
   @return 返回文件描述符，错误时返回-1
   */
   int open(char *name, int flags, int perms);
   ```

2. 创建文件

   ```c
   // #define PERMS 0666, perm用一个三位的八进制数表示权限
   int creat(char *name, int perms);
   ```

3. 关闭文件

   ```c
   // 如果打开的文件忘记关闭，在进程退出时(exit)，会自动关闭
   close(int fd);
   ```

4. 删除文件

   ```c
   unlink(char *name);
   ```

   

## 8.4 随机访问-lseek

1. 输入输出通常时顺序执行的，系统通过调用lseek可以在文件中任意移动位值而不写入数据

    ```c
    #include <sys/types.h>
    #include <unistd.h>

    /**
        @param whence 代表从那里开始计算，可选值有：
            SEEK_SET(将文件位值设置到offset处)
            SEEK_CUR(将文件位值设置到当前位值+offset)
            SEEK_END(将文件位值设置到文件size+offset)
        @return error时返回-1，否则返回最终的offset
    */
    off_t lseek(int fd, off_t offset, int whence);
    ```

2. 在write, read前使用lseek



## 8.5 目录列表

1. 获取文件相关信息函数

   ```c
   #include <sys/types.h>
   #include <sys/stat.h>
   #include <unistd.h>
   
   int stat(const char *pathname, struct stat *statbuf);
   int fstat(int fd, struct stat *statbuf);
   ```

2. stat数据结构

   ```c
   struct stat {
       dev_t     st_dev;         /* ID of device containing file */
       ino_t     st_ino;         /* Inode number */
       mode_t    st_mode;        /* File type and mode */
       nlink_t   st_nlink;       /* Number of hard links */
       uid_t     st_uid;         /* User ID of owner */
       gid_t     st_gid;         /* Group ID of owner */
       dev_t     st_rdev;        /* Device ID (if special file) */
       off_t     st_size;        /* Total size, in bytes */
       blksize_t st_blksize;     /* Block size for filesystem I/O */
       blkcnt_t  st_blocks;      /* Number of 512B blocks allocated */
   
       /* Since Linux 2.6, the kernel supports nanosecond
                     precision for the following timestamp fields.
                     For the details before Linux 2.6, see NOTES. */
   
       struct timespec st_atim;  /* Time of last access */
       struct timespec st_mtim;  /* Time of last modification */
       struct timespec st_ctim;  /* Time of last status change */
   
   };
   ```

3. 相关函数

   ```c
   // 1. 打开目录
   #include <sys/types.h>
   #include <dirent.h>
   DIR *opendir(const char *name);
   DIR *fdopendir(int fd);
   
   // 2. 读取目录，每次读取该文件夹下的一个文件，需要循环使用
   struct dirent *readdir(DIR *dirp);
   // 使用
   while((dir_e =  readdir(dir)) != NULL) {
       printf("d_name=%s\n", dir_e->d_name);
   }
   
   // 3. 关闭文件夹
   int closedir(DIR *dirp);//成功返回0;出错返回-1
   ```

   

