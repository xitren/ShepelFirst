#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include <unistd.h> 
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <termios.h>
#include <unistd.h>

int main(void)
{
    int fin;
    fin = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY);
    
    struct termios SerialPortSettings;
    tcgetattr(fin, &SerialPortSettings);
    //скорость на чтение запись
    cfsetispeed(&SerialPortSettings,B9600); 
    cfsetospeed(&SerialPortSettings,B9600);
    //стандарнтные натройки
    SerialPortSettings.c_cflag &= ~PARENB;
    SerialPortSettings.c_cflag &= ~CSTOPB;
    SerialPortSettings.c_cflag &= ~CSIZE;
    SerialPortSettings.c_cflag |=  CS8;
    SerialPortSettings.c_cflag &= ~CRTSCTS;
    SerialPortSettings.c_cflag |= CREAD | CLOCAL;
    SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);
    SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    SerialPortSettings.c_oflag &= ~OPOST;
    
    
    //устанавливает атрибуты струк термос
    if((tcsetattr(fin,TCSANOW,&SerialPortSettings)) != 0)
        printf("\n  ERROR ! in Setting attributes");
    else
        printf("\n  BaudRate = 9600 \n  StopBits = 1 \n  Parity   = none");
    
    char text[20];
    read (fin, text, 20); 
    text[19] = 0;
    printf("%s\n\r", text);
    
    
}
