
#include <stdio.h>

/**
 * 實作項目, 依據linux架構來實作這些功能, 這些功能主要為系統呼叫
 * os_open
 * os_close
 * os_read
 * os_write
 * os_about
 * os_printk
 */

// 這裡要實作一個標準函數庫的啟動方法, 實作各個驅動程式裝置的inode
int os_syscall_init(void)
{

}

// open不實作包含mode的功能, 僅實做成一個標準的開關介面
int os_open(const void *path, const int flag)
{
    
}

// freertos中此函數沒有太多意義 可以直接malloc成一個空值
void os_close(int fd)
{
    // 不做任何事
}

// 依照標準實作來完成這2個功能, 不同的地方為 return value 的 type 是 size_t 而不是標準的 ssize_t
size_t os_read(int fd, void *buff, size_t size)
{
    // 讀取值, 這裡實作呼叫一個fops驅動的功能
}

size_t os_wirte(int fd, const void *buff, size_t size)
{
    // 寫入值
}

// os_ioctl 屬於具有不定引數的函數, 此函數必須討論是否需要實作不定引數
int os_ioctl(int fd, unsigned long request, void *value)
{
    // ioctl操作
}
