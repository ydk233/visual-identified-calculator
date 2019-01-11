/**
  ******************************************************************************
  * @file    palette.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   ��������Ӧ�ú���
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ��  i.MXRT1052������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */

#include "./touch/palette.h"
#include "./touch/gt9xx.h"
#include "./lcd/bsp_lcd.h"
 
/*��ť�ṹ������*/
Touch_Button button[BUTTON_NUM];

/*���ʲ���*/
Brush_Style brush;

static void Draw_Color_Button(void *btn);
static void Draw_Clear_Button(void *btn);
static void Draw_Shape_Button(void *btn);

static void Command_Select_Color(void *btn);
static void Command_Select_Brush(void *btn);
static void Command_Clear_Palette(void *btn);

static void LCD_DrawUniLineCircle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,uint8_t thick );



/**
* @brief  Palette_Init �����ʼ��
* @param  ��
* @retval ��
*/
void Palette_Init(void)
{
  
  uint8_t i;

  /* ������Ϊ��ɫ */
  LCD_Clear(CL_WHITE);	/* ��������ʾȫ�� */

  
  /* ��ʼ����ť */
  Touch_Button_Init();
  
  /* ��水ť */
  for(i=0;i<BUTTON_NUM;i++)
  {
    button[i].draw_btn(&button[i]);
  }
  
	
//  /* ��ʼ������ */
//  brush.color = CL_BLACK;
//  brush.shape = LINE_SINGLE_PIXCEL;
//	
//	LCD_SetTextColor(brush.color);


}




/**
* @brief  Touch_Button_Init ��ʼ����ť����
* @param  ��
* @retval ��
*/

void Touch_Button_Init(void)
{
  /*С����*/
   button[0].start_x = 0;
  button[0].start_y = 0;
  button[0].end_x = 120 ;
  button[0].end_y = 120;
  button[0].para = CL_BUTTON_GREY;
  button[0].touch_flag = 0; 
	button[0].sym=(uint8_t*)".";
  button[0].draw_btn = Draw_Clear_Button ;
  

  
	
	
  /*0*/
  button[1].start_x = 0;
  button[1].start_y = 120;
  button[1].end_x = 120;
  button[1].end_y = 240;
  button[1].para = CL_RED;
  button[1].touch_flag = 0;
	button[1].sym=(uint8_t*)"0";
  button[1].draw_btn = Draw_Clear_Button ;  
  
  
	
  /*=*/
  button[2].start_x = 0;
  button[2].start_y = 240;
  button[2].end_x = 120 ;
  button[2].end_y = 360;
  button[2].para = CL_BLUE;
  button[2].touch_flag = 0;
	button[2].sym=(uint8_t*)"=";
  button[2].draw_btn = Draw_Clear_Button ;  
 
  
	
  /*+*/
 button[3].start_x = 0;
  button[3].start_y = 360;
  button[3].end_x = 120 ;
  button[3].end_y = 480;
  button[3].para = CL_BUTTON_GREY;
  button[3].touch_flag = 0; 
	button[3].sym=(uint8_t*)"+";
  button[3].draw_btn = Draw_Clear_Button ;	
  
  
  
	/*1*/
 button[4].start_x = 120;
  button[4].start_y = 0;
  button[4].end_x = 240 ;
  button[4].end_y =120;
  button[4].para = CL_BLUE;
  button[4].touch_flag = 0; 
	button[4].sym=(uint8_t*)"1";
  button[4].draw_btn = Draw_Clear_Button ;	
  
 
  
	/*2*/
 button[5].start_x = 120;
  button[5].start_y = 120;
  button[5].end_x = 240 ;
  button[5].end_y = 240;
  button[5].para = CL_BUTTON_GREY;
  button[5].touch_flag = 0; 
	button[5].sym=(uint8_t*)"2";
  button[5].draw_btn = Draw_Clear_Button ;	
 
  
  
	/*3*/
  button[6].start_x = 120;
  button[6].start_y = 240;
  button[6].end_x = 240 ;
  button[6].end_y = 360;
  button[6].para = CL_BLUE;
  button[6].touch_flag = 0;
	button[6].sym=(uint8_t*)"3";
  button[6].draw_btn = Draw_Clear_Button ;  
  
 
  
	/*-*/
  button[7].start_x = 120;
  button[7].start_y = 360;
  button[7].end_x = 240 ;
  button[7].end_y = 480;
  button[7].para = CL_BUTTON_GREY;
  button[7].touch_flag = 0; 
	button[7].sym=(uint8_t*)"-";
  button[7].draw_btn = Draw_Clear_Button ;	
 
  
  
	/*4*/
  button[8].start_x = 240;
  button[8].start_y = 0;
  button[8].end_x = 360 ;
  button[8].end_y = 120;
  button[8].para = CL_BLUE;
  button[8].touch_flag = 0;
	button[8].sym=(uint8_t*)"4";
  button[8].draw_btn = Draw_Clear_Button ;  
  
 
  
  
  
  /*5*/
  button[9].start_x = 240;
  button[9].start_y = 120;
  button[9].end_x = 360 ;
  button[9].end_y = 240;
  button[9].para = CL_BUTTON_GREY;
  button[9].touch_flag = 0;
	button[9].sym=(uint8_t*)"5";
  button[9].draw_btn = Draw_Clear_Button ;  
  
  
 
  /*6*/ 
  button[10].start_x = 240;
  button[10].start_y = 240;
  button[10].end_x = 360 ;
  button[10].end_y = 360;
  button[10].para = CL_BLUE;
  button[10].touch_flag = 0;
	button[10].sym=(uint8_t*)"6";
  button[10].draw_btn = Draw_Clear_Button ;  
  
  
  
	/*x*/
  button[11].start_x = 240;
  button[11].start_y = 360;
  button[11].end_x = 360 ;
  button[11].end_y = 480;
  button[11].para = CL_BUTTON_GREY;
  button[11].touch_flag = 0;
	button[11].sym=(uint8_t*)"x";
  button[11].draw_btn = Draw_Clear_Button ;  
  
  
  
	/*7*/
  button[12].start_x = 360;
  button[12].start_y = 0;
  button[12].end_x = 480 ;
  button[12].end_y = 120;
  button[12].para = CL_BLUE;
  button[12].touch_flag = 0;  
	button[12].sym=(uint8_t*)"7";
  button[12].draw_btn = Draw_Clear_Button ;
 
  
	/*8*/
  button[13].start_x = 360;
  button[13].start_y = 120;
  button[13].end_x = 480 ;
  button[13].end_y = 240;
  button[13].para = CL_BUTTON_GREY;
  button[13].touch_flag = 0;  
	button[13].sym=(uint8_t*)"8";
  button[13].draw_btn = Draw_Clear_Button ;
  
  
	/*9*/
  button[14].start_x = 360;
  button[14].start_y = 240;
  button[14].end_x = 480 ;
  button[14].end_y = 360;
  button[14].para = CL_BLUE;
  button[14].touch_flag = 0; 
 button[14].sym=(uint8_t*)"9";	
  button[14].draw_btn = Draw_Clear_Button ;
  
  
	/*��*/
  button[15].start_x = 360;
  button[15].start_y = 360;
  button[15].end_x = 480 ;
  button[15].end_y = 480;
  button[15].para = CL_BUTTON_GREY;
  button[15].touch_flag = 0;  
	button[15].sym=(uint8_t*)"/";
  button[15].draw_btn = Draw_Clear_Button ;
 
  
	/*clear*/
  button[16].start_x = 480;
  button[16].start_y = 0;
  button[16].end_x = 600 ;
  button[16].end_y = 120;
  button[16].para = CL_BLUE;
  button[16].touch_flag = 0;
  button[16].sym=(uint8_t*)"CLR";  
  button[16].draw_btn = Draw_Clear_Button ;
 
  


}

/**
* @brief  Touch_Button_Down ����������ʱ���õĺ������ɴ���������
* @param  x ����λ�õ�x����
* @param  y ����λ�õ�y����
* @retval ��
*/
void Touch_Button_Down(uint16_t x,uint16_t y)
{
  uint8_t i;
  for(i=0;i<BUTTON_NUM;i++)
  {
    /* �������˰�ť */
    if(x<=button[i].end_x && y<=button[i].end_y && y>=button[i].start_y && x>=button[i].start_x )
    {
      if(button[i].touch_flag == 0)     /*ԭ����״̬Ϊû�а��£������״̬*/
      {
      button[i].touch_flag = 1;         /* ��¼���±�־ */
      
      button[i].draw_btn(&button[i]);  /*�ػ水ť*/
      }        
      
    }
    else if(button[i].touch_flag == 1) /* �����Ƴ��˰����ķ�Χ��֮ǰ�а��°�ť */
    {
      button[i].touch_flag = 0;         /* ������±�־���ж�Ϊ�����*/
      
      button[i].draw_btn(&button[i]);   /*�ػ水ť*/
    }

  }

}

/**
* @brief  Touch_Button_Up �������ͷ�ʱ���õĺ������ɴ���������
* @param  x ��������ͷ�ʱ��x����
* @param  y ��������ͷ�ʱ��y����
* @retval ��
*/
void Touch_Button_Up(uint16_t x,uint16_t y)
{
   uint8_t i; 
   for(i=0;i<BUTTON_NUM;i++)
   {
     /* �����ڰ�ť�����ͷ� */
      if((x<button[i].end_x && x>button[i].start_x && y<button[i].end_y && y>button[i].start_y))
      {        
        button[i].touch_flag = 0;       /*�ͷŴ�����־*/
        
        button[i].draw_btn(&button[i]); /*�ػ水ť*/        
      
        //button[i].btn_command(&button[i]);  /*ִ�а����Ĺ�������*/
        
        break;
      }
    }  

}

/**
* @brief  Draw_Trail �ڻ���������津���켣
* @param  pre_x ��һ���x����
* @param  pre_y ��һ���y����
* @param  x     ����һ���x����
* @param  y     ����һ���y����
* @param  brush ��ˢ����
* @retval ��
*/
void Draw_Trail(int16_t pre_x,int16_t pre_y,int16_t x,int16_t y,Brush_Style* brush)
{
  /*���û�������Ϊ�����,bsp_lcd.c������û�������ĺ������������ƻ滭����*/
//  RA8875_SetActiveWindow(PALETTE_START_X,PALETTE_START_Y,PALETTE_END_X,PALETTE_END_Y);
  
	
  /*����λ���ڻ�������*/
  if(x>PALETTE_START_X && pre_x>PALETTE_START_X )
  {
    switch(brush->shape)  /*���ݻ�ˢ������治ͬ�Ĺ켣*/
    {
      /* ���1���ؿ�ȵĹ켣�� */
      case LINE_SINGLE_PIXCEL:
				
			
            if(pre_x< 0 || pre_y < 0) //�µıʼ�
            {      
              PutPixel(x,y);              
            }
            else //������һ�εıʼ�
            {      
              LCD_DrawUniLine(pre_x,pre_y,x,y);
            } 
        
        break;
            
      case LINE_2_PIXCEL:
        
				if(x-1<PALETTE_START_X||pre_x-1<PALETTE_START_X)	//������߽�
					break;

        /* ���2���ؿ�ȵĹ켣�� */
        LCD_DrawUniLineCircle(pre_x,pre_y,x,y,1);
        
        break;
      
      case LINE_4_PIXCEL:
				
				if(x-2<PALETTE_START_X||pre_x-2<PALETTE_START_X)	//������߽�
					break;
        
            LCD_DrawUniLineCircle(pre_x,pre_y,x,y,2);

        break;
      
      case LINE_6_PIXCEL:
        
				if(x-3<PALETTE_START_X||pre_x-3<PALETTE_START_X)	//������߽�
					break;
      
        LCD_DrawUniLineCircle(pre_x,pre_y,x,y,3);
        
        break;
      
      case LINE_8_PIXCEL:
				
				if(x-4<PALETTE_START_X||pre_x-4<PALETTE_START_X)	//������߽�
					break;
        
            LCD_DrawUniLineCircle(pre_x,pre_y,x,y,4);

        break;
      
     case LINE_16_PIXCEL:
			 
		 		if(x-8<PALETTE_START_X||pre_x-8<PALETTE_START_X)	//������߽�
					break;
        
            LCD_DrawUniLineCircle(pre_x,pre_y,x,y,8);

        break;
            
      case LINE_20_PIXCEL:
				
				if(x-10<PALETTE_START_X ||pre_x-10<PALETTE_START_X)	//������߽�
					break;
        
            LCD_DrawUniLineCircle(pre_x,pre_y,x,y,10);

        break;
      
      /*�������ӵĵ�������*/
      case LINE_WITH_CIRCLE:  

		 		if(x-3<PALETTE_START_X||pre_x-3<PALETTE_START_X)	//������߽�
					break;			
           
            if(pre_x< 0 || pre_y< 0)//�µıʼ�
            {      
              PutPixel(x,y); 
            }
            else //������һ�εıʼ�
            {      
              LCD_DrawUniLine(pre_x,pre_y,x,y);
              LCD_DrawFullCircle(x,y,3);
            } 
        
        break;
           
      /*��Ƥ����*/            
      case RUBBER:
				
				if(x-20<PALETTE_START_X ||						//������߽�
					  x+20>LCD_PIXEL_WIDTH || x-20<0 || //Һ�����ұ߽�
						y+20>LCD_PIXEL_HEIGHT || y-20<0)	 //Һ�����±߽�				
					break;	
			
//        if(x>PALETTE_START_X+20)
        {
						LCD_SetColors(CL_WHITE,CL_WHITE);
            
						LCD_DrawFullRect( x-40/2,
                                y-40/2,
                                40,
                                40);   
      
        }
      break;

    }
  }
  
  /*�˳����޻���Ļ�ͼ���ڣ�bsp_lcd.c������û�������ĺ������������ƻ滭����*/
//  RA8875_SetActiveWindow(0,0,LCD_PIXEL_WIDTH,LCD_PIXEL_HEIGHT);


}


/**
* @brief  Draw_Color_Button ��ɫ��ť����溯��
* @param  btn Touch_Button ���͵İ�������
* @retval ��
*/
static void Draw_Color_Button(void *btn)
{
  Touch_Button *ptr = (Touch_Button *)btn;
  
  /*�ͷŰ���*/
  if(ptr->touch_flag == 0)
  {
		/*����Ϊ���ܼ���Ӧ����ɫ*/
		LCD_SetColors(ptr->para,CL_WHITE);
    LCD_DrawFullRect(ptr->start_x,
                      ptr->start_y,
                      ptr->end_x - ptr->start_x,
											ptr->end_y - ptr->start_y);
  }
  else  /*��������*/
  {
    /*��ɫ����*/
		LCD_SetColors(CL_WHITE,CL_WHITE);
    LCD_DrawFullRect(ptr->start_x,
                      ptr->start_y,
                      ptr->end_x - ptr->start_x,
											ptr->end_y - ptr->start_y);
  } 
    /*��ť�߿�*/
		LCD_SetColors(CL_BLUE4,CL_WHITE);
    LCD_DrawRect(ptr->start_x,
									ptr->start_y,
									ptr->end_x - ptr->start_x,
									ptr->end_y - ptr->start_y);
  
}


/**
* @brief  Draw_Clear_Button ������ť����溯��

* @param  btn Touch_Button ���͵İ�������
* @retval ��
*/
static void Draw_Clear_Button(void *btn)
{
	
	Touch_Button *ptr = (Touch_Button *)btn;
    
  /*�ͷŰ���*/
  if(ptr->touch_flag == 0)
  {
	
		LCD_SetColors(CL_BUTTON_GREY,CL_WHITE);
    LCD_DrawFullRect(ptr->start_x,
                      ptr->start_y,
                      ptr->end_x - ptr->start_x,
											ptr->end_y - ptr->start_y);
    

		
		LCD_SetColors(CL_RED,CL_BUTTON_GREY);
		/*ѡ�����壬ʹ����Ӣ����ʾʱ��������Ӣ��ѡ���16*32�����壬
		*���������С��24*24�ģ���Ҫ��������������������ģ*/
		/*�������ֻ��Ӣ������������*/
		LCD_SetFont(&Font16x32);
    LCD_DispString( ptr->start_x + (ptr->end_x - ptr->start_x - 16*3 )/2,      
										ptr->start_y+25,            
										ptr->sym);
  }
  else  /*��������*/
  {
		
		LCD_SetColors(CL_WHITE,CL_WHITE);
    LCD_DrawFullRect(ptr->start_x,
                      ptr->start_y,
                      ptr->end_x - ptr->start_x,
											ptr->end_y - ptr->start_y);
    
		
		LCD_SetColors(CL_RED,CL_WHITE);
		/*ѡ�����壬ʹ����Ӣ����ʾʱ��������Ӣ��ѡ���16*32�����壬
		*���������С��24*24�ģ���Ҫ��������������������ģ*/
		/*�������ֻ��Ӣ������������*/
		LCD_SetFont(&Font16x32);
    LCD_DispString(	ptr->start_x + (ptr->end_x - ptr->start_x - 16*3 )/2,                     
                          ptr->start_y+25,	
														ptr->sym);
		
  } 
	  
  
     /*��ť�߿�*/
		LCD_SetColors(CL_BLUE4,CL_WHITE);
    LCD_DrawRect(ptr->start_x,
										ptr->start_y,
										ptr->end_x - ptr->start_x,
										ptr->end_y - ptr->start_y);
  
}

/**
* @brief  Draw_Shape_Button ��ˢ��ť����溯��
* @param  btn Touch_Button ���͵İ�������
* @retval ��
*/
static void Draw_Shape_Button(void *btn)
{
  Touch_Button *ptr = (Touch_Button *)btn;
  
   uint16_t i;
  
    /* ������ɫ û����ʱΪ��ɫ������ʱΪ��ɫ*/                  
    if(ptr->touch_flag ==0 )
    {
			
			LCD_SetColors(CL_BUTTON_GREY,CL_WHITE);
			LCD_DrawFullRect(ptr->start_x,
                      ptr->start_y,
                      ptr->end_x - ptr->start_x,
											ptr->end_y - ptr->start_y);
      

			 /*��ʾ����ʱ�ı�����ɫ*/     
			LCD_SetColors(CL_BLUE4,CL_BUTTON_GREY);
			LCD_DrawRect(ptr->start_x,
										ptr->start_y,
										ptr->end_x - ptr->start_x,
										ptr->end_y - ptr->start_y);

    }
    else
    {

			LCD_SetColors(CL_WHITE,CL_WHITE);
			LCD_DrawFullRect(ptr->start_x,
                      ptr->start_y,
                      ptr->end_x - ptr->start_x,
											ptr->end_y - ptr->start_y);
      

			 /*��ʾ����ʱ�ı�����ɫ*/     
			LCD_SetColors(CL_BLUE4,CL_WHITE);
			LCD_DrawRect(ptr->start_x,
										ptr->start_y,
										ptr->end_x - ptr->start_x,
										ptr->end_y - ptr->start_y);
    }
  
	LCD_SetColors(CL_BLACK,CL_WHITE);	
  /*���ݻ�ˢ��״��水ťͼ��*/
 switch(ptr->para)
  {
    		
    case LINE_SINGLE_PIXCEL:      
     		
				LCD_SetColors(CL_BLACK,CL_WHITE);
        LCD_DrawUniLine(ptr->start_x+20,
                          ptr->start_y+(ptr->end_y-ptr->start_y)/2,
                          ptr->end_x-20,
                          ptr->start_y+(ptr->end_y-ptr->start_y)/2);
      
      break;   

      
    case LINE_2_PIXCEL:
        
        LCD_DrawUniLineCircle(ptr->start_x+20,
                          ptr->start_y+(ptr->end_y-ptr->start_y)/2,ptr->end_x-20,
                          ptr->start_y+(ptr->end_y-ptr->start_y)/2,
                          1);
 
    
      break;
        
    case LINE_4_PIXCEL:
   
            LCD_DrawUniLineCircle(ptr->start_x+20,
                          ptr->start_y+(ptr->end_y-ptr->start_y)/2,ptr->end_x-20,
                          ptr->start_y+(ptr->end_y-ptr->start_y)/2,
                          2);
 
    
      break;
    
        case LINE_6_PIXCEL:
        
        LCD_DrawUniLineCircle(ptr->start_x+20,
                          ptr->start_y+(ptr->end_y-ptr->start_y)/2,ptr->end_x-20,
                          ptr->start_y+(ptr->end_y-ptr->start_y)/2,
                          3);
 
    
      break;
        
     case LINE_8_PIXCEL:
   
            LCD_DrawUniLineCircle(ptr->start_x+20,
                          ptr->start_y+(ptr->end_y-ptr->start_y)/2,ptr->end_x-20,
                          ptr->start_y+(ptr->end_y-ptr->start_y)/2,
                          4);
 
    
      break;
    
       case LINE_16_PIXCEL:
   
            LCD_DrawUniLineCircle(ptr->start_x+20,
                          ptr->start_y+(ptr->end_y-ptr->start_y)/2,ptr->end_x-20,
                          ptr->start_y+(ptr->end_y-ptr->start_y)/2,
                          8 );
 
    
      break;
        
       case LINE_20_PIXCEL:
   
            LCD_DrawUniLineCircle(ptr->start_x+20,
                          ptr->start_y+(ptr->end_y-ptr->start_y)/2,ptr->end_x-20,
                          ptr->start_y+(ptr->end_y-ptr->start_y)/2,
                          10);
 
    
      break;
            
            
    
     case LINE_WITH_CIRCLE: 
        LCD_SetColors(CL_BLACK,CL_WHITE);      
        LCD_DrawUniLine(ptr->start_x+5,
                          ptr->start_y+(ptr->end_y-ptr->start_y)/2,
                          ptr->end_x-5,
                          ptr->start_y+(ptr->end_y-ptr->start_y)/2);
		 
        
        for(i=0;i<((ptr->end_x - ptr->start_x-10)/10);i++)
        {
        
        LCD_DrawFullCircle(ptr->start_x+5+i*10,
                            ptr->start_y+(ptr->end_y-ptr->start_y)/2,
                            3);
        

        }

      
    break;
      
      
    case RUBBER:
			LCD_SetColors(CL_WHITE,CL_BLACK);
       LCD_DrawFullRect( ptr->start_x+((ptr->end_x - ptr->start_x -40)/2),
                          ptr->start_y+ ((ptr->end_y - ptr->start_y-40 -30)/2),
                          40,
                          40 );   
      
  
			LCD_SetColors(CL_RED,CL_BUTTON_GREY);    

		/*ѡ�����壬ʹ����Ӣ����ʾʱ��������Ӣ��ѡ���16*2�����壬
		*���������С��24*24�ģ���Ҫ��������������������ģ*/
		/*�������ֻ��Ӣ������������*/
		LCD_SetFont(&Font16x32);
    LCD_DispString( ptr->start_x+(ptr->end_x - ptr->start_x -16*3)/2,
                          ptr->end_y -40,
														(uint8_t*)"RUB");
		

    break;

  }
  
}

/**
* @brief  Command_Select_Color �л���ˢ��ɫ����ɫ�����Ĺ���ִ�к���
* @param  btn Touch_Button ���͵İ�������
* @retval ��
*/
static void Command_Select_Color(void *btn)
{
  Touch_Button *ptr = (Touch_Button *)btn;
  
  brush.color = ptr->para;	
	LCD_SetColors(brush.color,CL_WHITE);
  
  if(brush.shape == RUBBER)
  {
    brush.shape = LINE_SINGLE_PIXCEL;
  }

}

/**
* @brief  Command_Select_Brush �л���ˢ��ɫ����ˢ�����Ĺ���ִ�к���
* @param  btn Touch_Button ���͵İ�������
* @retval ��
*/
static void Command_Select_Brush(void *btn)
{
  Touch_Button *ptr = (Touch_Button *)btn;
  brush.shape =(SHAPE) ptr->para;
	LCD_SetColors(brush.color,CL_WHITE);
}

/**
* @brief  Command_Select_Brush �л���ˢ��ɫ�����������Ĺ���ִ�к���
* @param  btn Touch_Button ���͵İ�������
* @retval ��
*/
static void Command_Clear_Palette(void *btn)
{
		LCD_SetColors(CL_WHITE,CL_WHITE);
   /* LCD_DrawFullRect(PALETTE_START_X,
                      PALETTE_START_Y,                    
                      PALETTE_END_X-(PALETTE_START_X+1), 
											PALETTE_END_Y-PALETTE_START_Y );
*/
}



#define ABS(X)  ((X) > 0 ? (X) : -(X))

/**
  * @brief  ������֮�����켣
  * @param  x1: specifies the point 1 x position.
  * @param  y1: specifies the point 1 y position.
  * @param  x2: specifies the point 2 x position.
  * @param  y2: specifies the point 2 y position.
  * @retval None
  */
static void LCD_DrawUniLineCircle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,uint8_t thick )
{
  int16_t deltax = 0, deltay = 0, x = 0, y = 0, xinc1 = 0, xinc2 = 0, 
  yinc1 = 0, yinc2 = 0, den = 0, num = 0, numadd = 0, numpixels = 0, 
  curpixel = 0;
  
  deltax = ABS(x2 - x1);        /* The difference between the x's */
  deltay = ABS(y2 - y1);        /* The difference between the y's */
  x = x1;                       /* Start x off at the first pixel */
  y = y1;                       /* Start y off at the first pixel */
  
	
  if (x2 >= x1)                 /* The x-values are increasing */
  {
    xinc1 = 1;
    xinc2 = 1;
  }
  else                          /* The x-values are decreasing */
  {
    xinc1 = -1;
    xinc2 = -1;
  }
  
  if (y2 >= y1)                 /* The y-values are increasing */
  {
    yinc1 = 1;
    yinc2 = 1;
  }
  else                          /* The y-values are decreasing */
  {
    yinc1 = -1;
    yinc2 = -1;
  }
  
  if (deltax >= deltay)         /* There is at least one x-value for every y-value */
  {
    xinc1 = 0;                  /* Don't change the x when numerator >= denominator */
    yinc2 = 0;                  /* Don't change the y for every iteration */
    den = deltax;
    num = deltax / 2;
    numadd = deltay;
    numpixels = deltax;         /* There are more x-values than y-values */
  }
  else                          /* There is at least one y-value for every x-value */
  {
    xinc2 = 0;                  /* Don't change the x for every iteration */
    yinc1 = 0;                  /* Don't change the y when numerator >= denominator */
    den = deltay;
    num = deltay / 2;
    numadd = deltax;
    numpixels = deltay;         /* There are more y-values than x-values */
  }
  
  for (curpixel = 0; curpixel <= numpixels; curpixel++)
  {
		
		//�жϱ߽�
		if(x+thick >= LCD_PIXEL_WIDTH || x-thick <= 0 || //Һ�����ұ߽�
			y+thick >= LCD_PIXEL_HEIGHT || y-thick <= 0  ) //Һ�����±߽�
			continue;

    LCD_DrawFullCircle(x,y,thick);             /* Draw the current pixel */
    num += numadd;              /* Increase the numerator by the top of the fraction */
    if (num >= den)             /* Check if numerator >= denominator */
    {
      num -= den;               /* Calculate the new numerator value */
      x += xinc1;               /* Change the x as appropriate */
      y += yinc1;               /* Change the y as appropriate */
    }
    x += xinc2;                 /* Change the x as appropriate */
    y += yinc2;                 /* Change the y as appropriate */
  }
}




/* ------------------------------------------end of file---------------------------------------- */



