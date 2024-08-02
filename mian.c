#include <STC89C5xRC.H>
#define SW1 P42

//需求：独立按键SW1控制P00LED灯的亮灭
//手册信息：按键按下去时，对应引脚会直接接地，引脚电平为0
//松开后，引脚电平为1
//注意点：按键抖动，由于按键的物理特性，存在一个10ms左右的“抖动”

//延时函数
void Delay10ms()                //@11.0592MHz
{
        unsigned char i, j;

        i = 108;
        j = 145;
        do
        {
                while (--j);
        } while (--i);
}

void main()
{
        while(1)
        {
                if(SW1 == 0)                         //按下按键
                {
                        Delay10ms();                 //消除抖动
                        while(SW1 == 0);        		 //按下按键并保持
                        Delay10ms();                 //松开前消除抖动
                        P00 = ~P00;                  //0000 0001 -> 1111 1110
                }
        }
}