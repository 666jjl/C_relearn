#include <stdio.h>
#include <stdlib.h>
#include <limits.h>         //极限值
#include <string.h>
#include <stdint.h>
#define ZERO 0
//#define ISBIGGER(x,y) (int)((##x)>(##y)?(##x):(##y))
#define MAX(a,b) ((a>b)?a:b)
#define jj_str "123547"
#define wh_str "1235478"
#define CHOOSE_STR(_strname) (_strname##_str)
#define CONNECT(x,y) x##y   //##用于把参数独立出来让编译器可识别
//#define TOCHAR(a) #@a  //#@用于把参数传化成字符，似乎不管用
#define TOSTRING(p) #p  //#用于把参数转化成字符串//
#define ISLITTLER(x,y) ISBIGGER(y,x)//
#define MAX(x,y) ISBIGGER(x,y)?x:y//
#define MIN(x,y) ISBIGGER(x,y)?y:x
int main(){    
  int a=-1,b=0;      
  float c=3.2235f;      
  int eight0=010;      
  int sixteen0=0x1f;     
  char chr='c';     
  //char jj_str[]="0123";     
  char str[]="this is a string";     
  uint64_t catchline = 23581647;     
  enum week{sun,mon,tue,wed,thu,fri,sat}; //枚举类型    
           printf("输入两个参数a,b:");     
  scanf("%d %d",&a,&b);       //输入 
  printf("scanf后会有回车键在缓冲区导致后续的输入会错误读取回车而没法正常输入,需要fflush(stdin)删除缓存.\n");
  fflush(stdin);
           printf("Define MAX(a,b)=%d\n",MAX(a,b));      
           printf("%%0.2f表示保留小数点后两位：%0.2f\n",c);        //保留小数点几位      
           printf("输出define的值：%d\n",ZERO);        //define     
           printf("8进制（010）改十进制输出：%d\n",eight0);      //八进制     
           printf("16进制（0x1f）改十进制输出：%d\n",sixteen0);    //十六进制      
           printf("sizeof(int) == %d\n",sizeof(int));//int大小为4Bytes      
           printf("INT_MIN == %d\n",INT_MIN);     //极限值,需要limits.h      
           printf("输出字符串：%s ，字符串size：%d\n",str,sizeof(str));//详情看string一节     
           switch (a){         
             case 1:               
               printf("switch case1，a=%d\n",a);              
               break;         
             case 2:              
               printf("switch case2，a==%d\n",a); //不加break会继续往下执行          
             default:               
               printf("switch default，a!=1\n");      
           }      
           printf("putchar(char)输出字符char\n");     
           putchar(*str);          //*str=str[0]      
           putchar('\n');      
           printf("putchar('\\n')就是换行\n");      
           putchar('\n');          //换行           
           chr=getchar();//中间似乎不能输入？     
           putchar(chr);    
  putchar('\n');    
           printf("%%o代表8进制，%%x代表16进制，字母前加数字代表指定显示位数：\n%%o %%9o %%x\n%o %9o %x\n",a,a,a); //八进制,指定位数,十六进制     
           printf("字母前的小数表示保留几个字符,整数表示显示字符长度(正负表示右、左对齐)：\              
                  \n%%7s %%7.2s %%-5.3s %%.4s\n%7s %7.2s %-5.3s %.4s\n","CHINA","CHINA","CHINA","CHINA"); //小数点表示保留几个字符,整数表示显示字符长度(正负表示往哪个方向补空格)     
                  printf("0x%x\n",catchline);     
                  printf("0x%11x\n",catchline);     
                  printf("宏定义函数 CHOOSE_STR(jj)=%s\n",CHOOSE_STR(jj));      
                  printf("宏定义函数 TOSTRING(jjlee)=%s\n",TOSTRING(jjlee));    
                  return 0;  
                  }

           
           
