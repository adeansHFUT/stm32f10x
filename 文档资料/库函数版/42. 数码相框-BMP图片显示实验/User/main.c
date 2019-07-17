

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "tftlcd.h"
#include "key.h"
#include "malloc.h" 
#include "sd.h"
#include "flash.h"
#include "ff.h" 
#include "fatfs_app.h"
#include "key.h"
#include "font_show.h"
#include "bmp.h"


FileNameTypeDef filename[30];

int main()
{
	u8 i=0,t;
	u8 key;
    u8 j, k;
    u8 dat[7] = {"0:/ͼƬ"};  //Ҫ��ʾ��ͼƬ���ļ���ַ
    u8 picFile[30];
	u8 num[6];
    u32 sdCapacity, free;
	
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�ж����ȼ����� ��2��
	LED_Init();
	USART1_Init(9600);
	TFTLCD_Init();			//LCD��ʼ��
	KEY_Init();
	EN25QXX_Init();				//��ʼ��EN25QXX
	
	my_mem_init(SRAMIN);		//��ʼ���ڲ��ڴ��
	
	FRONT_COLOR=RED;//��������Ϊ��ɫ 
	LCD_ShowFont16Char(10,10,"ͼƬ��ʾʵ��");
	
	while(SD_Init()!=0)
	{	
		LCD_ShowFont12Char(10,30,"SD Card Error!");
		
	}
	LCD_ShowFont12Char(10,30,"SD Card OK!    ");
	
	FATFS_Init();							//Ϊfatfs��ر��������ڴ�				 
  	f_mount(fs[0],"0:",1); 					//����SD�� 
 	f_mount(fs[1],"1:",1); 				//����FLASH.
	
	while(FATFS_GetFree("0", &sdCapacity, &free) != 0)
	{
		LCD_ShowFont12Char(10, 50, "SD Card FAT ERROR!");
	}
	
	sdCapacity >>= 10;                         //��KBת��ΪMB
	num[0] = (sdCapacity /10000 % 10) + '0';
	num[1] = (sdCapacity /1000 % 10) + '0';
	num[2] = (sdCapacity /100 % 10) + '0';
	num[3] = (sdCapacity /10 % 10) + '0';
	num[4] = (sdCapacity % 10) + '0';
	
	LCD_ShowFont12Char(10, 50, "SD Card FAT OK!  ");
    LCD_ShowFont12Char(10, 70, "SD card total memory:     MB");
	LCD_ShowFont12Char(178, 70, num);
	
	/* ��ʾSD������ռ� */
	free >>= 10;         //����λת��ΪMB
	num[0] = (free /10000 % 10) + '0';
	num[1] = (free /1000 % 10) + '0';
	num[2] = (free /100 % 10) + '0';
	num[3] = (free /10 % 10) + '0';
	num[4] = (free % 10) + '0';

    LCD_ShowFont12Char(10, 100, "SD card free memory:     MB");
	LCD_ShowFont12Char(170, 100, num);
    LCD_ShowFont12Char(10, 120, "KEY_DOWN����һ��ͼƬ��");
	
	/*  ɨ���ļ���ַ�������е��ļ� */
    FATFS_ScanFiles(dat, filename);

	while(1)
	{
		while(1)
		{
			key=KEY_Scan(0);
			if(key==KEY_DOWN)
			{
				break;
			}
			t++;
			if(t%20==0)
			{
				led1=!led1;
			}
			delay_ms(10);
		}
		while(1)
		{
			/* ����ˢ������FAT32�ļ����BMPͼƬ�Ǵ����ʼ�� */
		#ifdef TFTLCD_HX8357D
            LCD_WriteCmd(0x26); //01
        	LCD_WriteData(0x01);
            LCD_WriteCmd(0x36);
    		LCD_WriteData(0x8c);
		#endif
			
		#ifdef TFTLCD_HX8352C
            LCD_WriteCmd(0x36);   //���ò�����ʾ����ļĴ���
			LCD_WriteData(0x06);
		#endif
			
		#ifdef TFTLCD_ILI9341
            LCD_WriteCmd(0x26); //01
        	LCD_WriteData(0x01);
            LCD_WriteCmd(0x36);
    		LCD_WriteData(0x8c);
		#endif
				
		#ifdef TFTLCD_R61509V
			LCD_WriteCmd(0x0400);
			LCD_WriteData(0xe200);
		#endif
		
		#ifdef TFTLCD_R61509V3
			LCD_WriteCmd(0x0400);
			LCD_WriteData(0xe200);
		#endif
		
		#ifdef TFTLCD_NT5510
            
		#endif
			
			/* �ж��Ƿ���BMPͼƬ�ļ� */
			if((filename[i].type[1] == 'b') && (filename[i].type[2] == 'm') &&
               (filename[i].type[3] == 'p')) 
			{
				/* �����ļ�·��,������ļ�·�� */
				k = 0;
				while(*(dat + k) != '\0')
				{
					*(picFile + k) = *(dat + k);
					k++;
				}

                /* ·��֮�����һб�� */
				*(picFile + k) = '/';
				k++;

                /* ����ļ��������� */
				j = 0;
				while(filename[i].name[j] != '\0')
				{
					*(picFile + k) = filename[i].name[j];
					k++;
					j++;	
				}

                /* ����ļ���׺ */
				j = 0;
				while(filename[i].type[j] != '\0')
				{
					*(picFile + k) = filename[i].type[j];
					k++;
					j++;	
				}

                /* �ļ�������һ���������� */
                *(picFile + k) = '\0';

				/* ��ʾͼƬ */
			 	BMP_ShowPicture(picFile);
                i++;
				break;
			}
			i++;
            if(i > 30)
            {
                i = 0;
				
            }		
		}
		
	}
}
