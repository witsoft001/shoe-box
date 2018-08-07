//#include "stm32f10x.h"
//#include "user_ili9341_lcd.h"
//#include "user_xpt2046.h"
//#include "delay.h"

//volatile uint8_t touch_flag;

///* ������У��ϵ�� */
//#if 1
//long double aa1=0,bb1=0,cc1=0,aa2=0,bb2=0,cc2=0;
//#elif 0
//long double aa1=0.088370,\
//            bb1=-0.000468,\
//            cc1=-24.042172,\
//            aa2=0.0001891,\
//            bb2=0.062395,\
//            cc2=-10.223455;
//#endif

///* ��ֵ���� */
//#define THRESHOLD 2 

///*--------------------------------------------------------------------*/
//// �ĸ���Ҫ�Ľṹ�����

///* ��������ADֵ����ṹ�� */
//Coordinate ScreenSample[4];

//Coordinate DisplaySample[4] =   
//{
//    { 45,  35 },
//    { 10,  200},
//    { 290, 200},
//    { 200, 35}
//};
///* ���ڱ���У��ϵ�� */
//Parameter   touch_para ;

///* Һ���������꣬�������������ʱ���� */
//Coordinate  display ;
///*------------------------------------------------------------------*/

///**************************************************************************************
// * ��  �� : ��ʼ��xpt2046��SPI���õ���IO��
// * ��  �� : ��
// * ����ֵ : ��
// **************************************************************************************/
//void SPI_GPIO_Init(void)
//{
//  GPIO_InitTypeDef  GPIO_InitStructure;

//  //������GPIO��ʱ��
//  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOG , ENABLE);  
//  
//  //���õ�IO��PG13 PG14��SPI�� MOSI CLK
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;                
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;           //�������
//	GPIO_Init(GPIOG, &GPIO_InitStructure);
//  //���õ�IO��PD12��SPI�� CS
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;                
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;           //�������
//	GPIO_Init(GPIOD, &GPIO_InitStructure);
//  //���õ�IO��PG15��SPI��MISO
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;              //��������
//	GPIO_Init(GPIOG, &GPIO_InitStructure);
//}

///*******************************************************************************
// * ��  �� : ��ʼ��xpt2046��PD6Ϊ�ⲿ�ж�6
// * ��  �� : ��
// * ����ֵ : ��
// ******************************************************************************/
//void EXTI_PD6_Init(void)
//{
//	GPIO_InitTypeDef GPIO_InitStructure;
//	EXTI_InitTypeDef EXTI_InitStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;
//	
//	/* Enable the EXTI_PD6 Clock */
//	RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOD , ENABLE); 
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;                 //��������   
//	GPIO_Init(GPIOD, &GPIO_InitStructure);
//	
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSource6);   //����PD6�ܽ�Ϊ�ⲿ�ж���·��
//	  
//	EXTI_InitStructure.EXTI_Line = EXTI_Line6;                    //����Ϊ�ⲿ�ж���6
//	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;           //����Ϊ�ж�����
//	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;       //������·�½���Ϊ�ж�����
//	EXTI_InitStructure.EXTI_LineCmd = ENABLE;	                    //ʹ���ж�
//  EXTI_Init(&EXTI_InitStructure);
//	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);               //NVIC_Group:��ռ���ȼ�2λ�������ȼ�2λ  
//  NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;            //����Ϊ�ⲿ�ж�6�ж�
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;     //��ռ���ȼ�Ϊ1
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;            //�����ȼ�Ϊ2
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;               //ʹ���ж�ͨ��
//  NVIC_Init(&NVIC_InitStructure); 
//}

///**************************************************************************************
// * ��  �� : �ⲿ�жϷ������
// * ��  �� : ��
// * ����ֵ : ��
// **************************************************************************************/
//void EXTI9_5_IRQHandler(void)
//{
//  if(EXTI_GetITStatus(EXTI_Line6) != RESET)
//  {	
//    touch_flag=1;
//    EXTI_ClearITPendingBit(EXTI_Line6);  //���EXTI�ж���·����λ
//  }
//}


///*******************************************************************************
// * ��  �� : ��ʼ��xpt2046��IO�ڣ�ģ��SPI���ж�IO��
// * ��  �� : ��
// * ����ֵ : ��
// ******************************************************************************/
//void xpt2046_Init(void)
//{
//   SPI_GPIO_Init();
//   EXTI_PD6_Init();  
//}

///*******************************************************************************
// * ��  �� : д����
// * ��  �� : ����������
// * ����ֵ : ��
// ******************************************************************************/
//static void XPT2046_WriteCMD(uint8_t cmd) 
//{
//  uint8_t temp,i;
//  xpt2046_SPI_MOSI_0;
//  xpt2046_SPI_SCK_0;
//  for (i = 0; i < 8; i++) 
//	{
//     temp = (cmd>>(7-i))&0x1; 
//     if(temp)
//     { xpt2046_SPI_MOSI_1; }
//     else 
//     { xpt2046_SPI_MOSI_0; }
//     sw_delay_us(5);
//     xpt2046_SPI_SCK_1 ;
//     sw_delay_us(5);
//     xpt2046_SPI_SCK_0;
//   }
//}

///*******************************************************************************
// * ��  �� : ������
// * ��  �� : ��
// * ����ֵ : ���ض���������
// ******************************************************************************/
//static unsigned short XPT2046_ReadCMD(void) 
//{
//    unsigned short buf=0,temp;
//    unsigned char i,SDI;
//    xpt2046_SPI_MOSI_0;
//    xpt2046_SPI_SCK_1 ;
//    for(i=0;i<12;i++) 
//    {
//        xpt2046_SPI_SCK_0; 
//        SDI = GPIO_ReadInputDataBit(GPIOG, GPIO_Pin_15);   //MISO��������
//        temp= (SDI) ? 1:0;
//        buf|=(temp<<(11-i));
//        xpt2046_SPI_SCK_1 ;
//    }
//    buf&=0x0fff;

//    return(buf);
//}

///*******************************************************************************
// * ��  �� : ѡ��һ��ģ��ͨ��������ADC��������ADC�������
// * ��  �� : _ucCh = 0x90 ��ʾYͨ���� 0xd0 ��ʾXͨ��
// * ����ֵ : 12λADCֵ
// ******************************************************************************/
//uint16_t XPT2046_ReadAdc(uint8_t _ucCh)
//{
//  XPT2046_WriteCMD(_ucCh);
//	return 	XPT2046_ReadCMD();
//}


///*
// * У������ʱ��ʮ��ר�� 
// * x:0~300
// * y:0~230
// */
//void DrawCross(uint16_t x,uint16_t y)
//{
//   LCD_Clear(x, y, 20, 1, RED);
//   LCD_Clear(x+10, y-10, 1, 20, RED);
//}

///*
// * ��ȡTP x y ��ADֵ(12bit�������4096)
// */
//void Touch_GetAdXY(int *x,int *y)  
//{ 
//    int adx,ady; 
//    //adx=Read_X();
//    adx = XPT2046_ReadAdc(CHX);
//  
//    sw_delay_us(1); 
//    //ady=Read_Y();
//    ady = XPT2046_ReadAdc(CHY);  
//    *x=adx; 
//    *y=ady; 
//}

///******************************************************
//* ��������Read_2046
//* ����  ���õ��˲�֮���X Y
//* ����  : ��
//* ���  ��Coordinate�ṹ���ַ
//* ����  ����
//* ע��  ���ٶ���ԱȽ���
//*********************************************************/    
//Coordinate *Read_2046(void)
//{
//    static Coordinate  screen;
//    int m0,m1,m2,TP_X[1],TP_Y[1],temp[3];
//    uint8_t count=0;
//		
//		/* ����X��Y����9�β���*/
//    int buffer[2][9]={{0},{0}};  	
//    do
//    {		   
//        Touch_GetAdXY(TP_X,TP_Y);  
//        buffer[0][count]=TP_X[0];  
//        buffer[1][count]=TP_Y[0];
//        count++; 
//				 
//    }	/*�û����������ʱ��TP_INT_IN�ź�Ϊ�� ���� count<9*/
//    while(!INT_IN_2046&& count<9);  
//    
//		
//		/*������ʵ���*/
//		if(INT_IN_2046 ==1)
//    {
//        /*�жϱ�־��λ*/
//				touch_flag =0;						
//    }

//		/* ����ɹ�����9��,�����˲� */ 
//    if(count==9)   								
//    {  
//        /* Ϊ����������,�ֱ��3��ȡƽ��ֵ */
//        temp[0]=(buffer[0][0]+buffer[0][1]+buffer[0][2])/3;
//        temp[1]=(buffer[0][3]+buffer[0][4]+buffer[0][5])/3;
//        temp[2]=(buffer[0][6]+buffer[0][7]+buffer[0][8])/3;
//        
//        /* ����3�����ݵĲ�ֵ */
//        m0=temp[0]-temp[1];
//        m1=temp[1]-temp[2];
//        m2=temp[2]-temp[0];
//        
//        /* ��������ֵȡ����ֵ */
//        m0=m0>0?m0:(-m0);
//        m1=m1>0?m1:(-m1);
//        m2=m2>0?m2:(-m2);
//        
//        /* �жϾ��Բ�ֵ�Ƿ񶼳�����ֵ���ޣ������3�����Բ�ֵ����������ֵ�����ж���β�����ΪҰ��,���������㣬��ֵ����ȡΪ2 */
//        if( m0>THRESHOLD  &&  m1>THRESHOLD  &&  m2>THRESHOLD ) 
//            return 0;
//        
//        /* �������ǵ�ƽ��ֵ��ͬʱ��ֵ��screen */ 
//        if(m0<m1)
//        {
//            if(m2<m0) 
//                screen.x=(temp[0]+temp[2])/2;
//            else 
//                screen.x=(temp[0]+temp[1])/2;	
//        }
//        else if(m2<m1) 
//            screen.x=(temp[0]+temp[2])/2;
//        else 
//            screen.x=(temp[1]+temp[2])/2;
//        
//        /* ͬ�� ����Y��ƽ��ֵ */
//        temp[0]=(buffer[1][0]+buffer[1][1]+buffer[1][2])/3;
//        temp[1]=(buffer[1][3]+buffer[1][4]+buffer[1][5])/3;
//        temp[2]=(buffer[1][6]+buffer[1][7]+buffer[1][8])/3;
//        m0=temp[0]-temp[1];
//        m1=temp[1]-temp[2];
//        m2=temp[2]-temp[0];
//        m0=m0>0?m0:(-m0);
//        m1=m1>0?m1:(-m1);
//        m2=m2>0?m2:(-m2);
//        if(m0>THRESHOLD&&m1>THRESHOLD&&m2>THRESHOLD) 
//            return 0;
//        
//        if(m0<m1)
//        {
//            if(m2<m0) 
//                screen.y=(temp[0]+temp[2])/2;
//            else 
//                screen.y=(temp[0]+temp[1])/2;	
//        }
//        else if(m2<m1) 
//            screen.y=(temp[0]+temp[2])/2;
//        else
//            screen.y=(temp[1]+temp[2])/2;
//        
//        return &screen;
//    }
//    
//    else if(count>1)
//    {
//        screen.x=buffer[0][0];
//        screen.y=buffer[1][0];
//        return &screen;
//    }  
//    return 0; 
//}

///******************************************************
//* ��������Read_2046
//* ����  ���õ����˲�֮���X Y
//* ����  : ��
//* ���  ��Coordinate�ṹ���ַ
//* ����  ����
//* ע��  ��������Ӧ��ʵ��"ר��,���Ǻܾ�׼�������ٶȱȽϿ�
//*********************************************************/    
//Coordinate *Read_2046_2(void)
//{
//    static Coordinate  screen2;
//    int TP_X[1],TP_Y[1];
//    uint8_t count=0;
//    int buffer[2][10]={{0},{0}};  /*����X��Y���ж�β���*/
//    int min_x,max_x;
//    int min_y,max_y;
//    int	i=0;
//    
//    do					       				
//    {		/* ѭ������10�� */   
//        Touch_GetAdXY(TP_X,TP_Y);  
//        buffer[0][count]=TP_X[0];  
//        buffer[1][count]=TP_Y[0];
//        count++;  
//    }	/*�û����������ʱ��TP_INT_IN�ź�Ϊ�� ���� count<10*/
//    while(!INT_IN_2046&& count<10);
//    
//		/*������ʵ���*/
//    if(INT_IN_2046)						
//    {
//				/*�жϱ�־��λ*/
//        touch_flag = 0;					 
//    }
//		
//		/*����ɹ�����10������*/
//    if(count ==10)		 					
//    {
//        max_x=min_x=buffer[0][0];
//        max_y=min_y=buffer[1][0];       
//        for(i=1; i<10; i++)
//        {
//            if(buffer[0][i]<min_x)
//            {
//                min_x=buffer[0][i];
//            }
//            else
//            if(buffer[0][i]>max_x)
//            {
//                max_x = buffer[0][i];
//            }
//        }
//        
//        for(i=1; i<10; i++)
//        {
//            if(buffer[1][i]<min_y)
//            {
//                min_y=buffer[1][i];
//            }
//            else
//            if(buffer[1][i]>max_y)
//            {
//                max_y = buffer[1][i];
//            }
//        }
//				/*ȥ����Сֵ�����ֵ֮����ƽ��ֵ*/
//        screen2.x=(buffer[0][0]+buffer[0][1]+buffer[0][2]+buffer[0][3]+buffer[0][4]+buffer[0][5]+buffer[0][6]+buffer[0][7]+buffer[0][8]+buffer[0][9]-min_x-max_x)>>3;
//        screen2.y=(buffer[1][0]+buffer[1][1]+buffer[1][2]+buffer[1][3]+buffer[1][4]+buffer[1][5]+buffer[1][6]+buffer[1][7]+buffer[1][8]+buffer[1][9]-min_y-max_y)>>3; 
//        
//        return &screen2;
//    }    
//    return 0;    
//}

///******************************************************
//* ��������Cal_touch_para
//* ����  ���������������Һ��������任��ת�������� K A B C D E Fϵ��
//* ����  : ��
//* ���  ������1��ʾ�ɹ� 0ʧ��
//* ����  ����
//* ע��  ��ֻ����LCD�ʹ�����������Ƕȷǳ�Сʱ,�����������湫ʽ
//*********************************************************/    
//FunctionalState Cal_touch_para( Coordinate * displayPtr,
//                                Coordinate * screenPtr,
//                                Parameter * para)
//{
//    
//    FunctionalState retTHRESHOLD = ENABLE ;

//    /* K��(X0��X2) (Y1��Y2)��(X1��X2) (Y0��Y2) */
//    para->Divider = ((screenPtr[0].x - screenPtr[2].x) * (screenPtr[1].y - screenPtr[2].y)) - 
//                    ((screenPtr[1].x - screenPtr[2].x) * (screenPtr[0].y - screenPtr[2].y)) ;
//    
//		if( para->Divider == 0 )
//    {
//        retTHRESHOLD = DISABLE;
//    }
//    else
//    {
//        /* A��((XD0��XD2) (Y1��Y2)��(XD1��XD2) (Y0��Y2))��K	*/
//        para->An = ((displayPtr[0].x - displayPtr[2].x) * (screenPtr[1].y - screenPtr[2].y)) - 
//                   ((displayPtr[1].x - displayPtr[2].x) * (screenPtr[0].y - screenPtr[2].y));
//        
//        /* B��((X0��X2) (XD1��XD2)��(XD0��XD2) (X1��X2))��K	*/
//        para->Bn = ((screenPtr[0].x - screenPtr[2].x) * (displayPtr[1].x - displayPtr[2].x)) - 
//                   ((displayPtr[0].x - displayPtr[2].x) * (screenPtr[1].x - screenPtr[2].x));
//        
//        /* C��(Y0(X2XD1��X1XD2)+Y1(X0XD2��X2XD0)+Y2(X1XD0��X0XD1))��K */
//        para->Cn = (screenPtr[2].x * displayPtr[1].x - screenPtr[1].x * displayPtr[2].x) * screenPtr[0].y +
//                   (screenPtr[0].x * displayPtr[2].x - screenPtr[2].x * displayPtr[0].x) * screenPtr[1].y +
//                   (screenPtr[1].x * displayPtr[0].x - screenPtr[0].x * displayPtr[1].x) * screenPtr[2].y ;
//        
//        /* D��((YD0��YD2) (Y1��Y2)��(YD1��YD2) (Y0��Y2))��K	*/
//        para->Dn = ((displayPtr[0].y - displayPtr[2].y) * (screenPtr[1].y - screenPtr[2].y)) - 
//                   ((displayPtr[1].y - displayPtr[2].y) * (screenPtr[0].y - screenPtr[2].y)) ;
//        
//        /* E��((X0��X2) (YD1��YD2)��(YD0��YD2) (X1��X2))��K	*/
//        para->En = ((screenPtr[0].x - screenPtr[2].x) * (displayPtr[1].y - displayPtr[2].y)) - 
//                   ((displayPtr[0].y - displayPtr[2].y) * (screenPtr[1].x - screenPtr[2].x)) ;
//        
//        
//        /* F��(Y0(X2YD1��X1YD2)+Y1(X0YD2��X2YD0)+Y2(X1YD0��X0YD1))��K */
//        para->Fn = (screenPtr[2].x * displayPtr[1].y - screenPtr[1].x * displayPtr[2].y) * screenPtr[0].y +
//                   (screenPtr[0].x * displayPtr[2].y - screenPtr[2].x * displayPtr[0].y) * screenPtr[1].y +
//                   (screenPtr[1].x * displayPtr[0].y - screenPtr[0].x * displayPtr[1].y) * screenPtr[2].y;
//        
//    }
//    return( retTHRESHOLD ) ;
//}

///******************************************************
//* ��������Touchl_Calibrate
//* ����  ��������У������
//* ����  : ��
//* ���  ��0	---	У���ɹ�
//					1	---	У��ʧ��
//* ����  ����
//* ע��  ����
//*********************************************************/ 
//int Touch_Calibrate(void)
//{
//    #if 1
//    uint8_t i;
//    u16 test_x=0, test_y=0;
//    u16 gap_x=0, gap_y=0;
//    Coordinate * Ptr;   
//    
//    for(i=0; i<4; i++)
//    {        
//        LCD_Clear(0, 0, 320, 240, BACKGROUND);        
//        LCD_DispStr(110, 110, (uint8_t *)"Touch Calibrate......", RED);	         
//        LCD_DisNum(160, 90, i+1, RED);
//      
//        /* �ʵ�����ʱ���б�Ҫ */        
//        sw_delay_ms(500);     
//        DrawCross(DisplaySample[i].x,DisplaySample[i].y);  //��ʾУ���õġ�ʮ����
//        do
//        {
//            Ptr=Read_2046_2();        //��ȡXPT2046���ݵ�����ptr            
//        }
//        while( Ptr == (void*)0 );     //��ptrΪ��ʱ��ʾû�д��㱻����
//        ScreenSample[i].x= Ptr->x; 	  //�Ѷ�ȡ��ԭʼ���ݴ�ŵ�ȫ�ֱ���ScreenSample�ṹ��
//        ScreenSample[i].y= Ptr->y;

//    }
//		/* ��ԭʼ��������� ԭʼ�����������ת��ϵ���� */
//    Cal_touch_para( &DisplaySample[0],&ScreenSample[0],&touch_para ) ;  	   
//    
//		/*ȡһ�������Xֵ*/
//    test_x = ( (touch_para.An * ScreenSample[3].x) + 
//               (touch_para.Bn * ScreenSample[3].y) + 
//                touch_para.Cn 
//             ) / touch_para.Divider ;			 
//    
//		/*ȡһ�������Yֵ*/
//    test_y = ( (touch_para.Dn * ScreenSample[3].x) + 
//               (touch_para.En * ScreenSample[3].y) + 
//               touch_para.Fn 
//             ) / touch_para.Divider ;
//    
//    /* ʵ���������������Ĳ� */
//    gap_x = (test_x > DisplaySample[3].x)?(test_x - DisplaySample[3].x):(DisplaySample[3].x - test_x);
//    gap_y = (test_y > DisplaySample[3].y)?(test_y - DisplaySample[3].y):(DisplaySample[3].y - test_y);
//    

//    //LCD_Rectangle(0,0,320,240,CAL_BACKGROUND_COLOR);
//    LCD_Clear(0, 0, 320, 240, BACKGROUND);
//    
//    /* ����ͨ���޸�������ֵ�Ĵ�С���������� */
//    if((gap_x>10)||(gap_y>10))
//    {
//      LCD_DispStr(100, 100, (uint8_t *)"Calibrate fail", RED);
//      LCD_DispStr(100, 120, (uint8_t *)"try again", RED);     
//      sw_delay_ms(2000);
//      return 1;
//    }    
//    
//    /* У��ϵ��Ϊȫ�ֱ��� */
//    aa1 = (touch_para.An*1.0)/touch_para.Divider;
//    bb1 = (touch_para.Bn*1.0)/touch_para.Divider;
//    cc1 = (touch_para.Cn*1.0)/touch_para.Divider;
//    
//    aa2 = (touch_para.Dn*1.0)/touch_para.Divider;
//    bb2 = (touch_para.En*1.0)/touch_para.Divider;
//    cc2 = (touch_para.Fn*1.0)/touch_para.Divider;
//    
//    #elif 0
//    aa1=0.088370;
//    bb1=-0.000468;
//    cc1=-24.042172;
//    aa2=0.0001891;
//    bb2=0.062395;
//    cc2=-10.223455;
//    
//    #endif
//    
//    LCD_DispStr(58, 100, (uint8_t *)"The touch calibration is OK!!!", RED);  
//    sw_delay_ms(1000);
//    
//    
//    return 0;    
//}

///*
// * �����ʼ��������ȡɫ��
// */
//void Palette_Init(void)
//{
//  /* ������Ϊ��ɫ */
//  LCD_Clear(0, 0, 320, 240, GREY);
//  
//  /* ������ֱ�� */
//  LCD_Clear(39, 0, 1, 30, BLACK);
//  LCD_Clear(0, 29, 40, 1, BLACK);
//  LCD_DispStr(7, 10, (uint8_t *)"CLR", RED);
//  
//  LCD_Clear(0, 30, 40, 30, GREEN);
//  LCD_Clear(0, 60, 40, 30, BLUE);
//  LCD_Clear(0, 90, 40, 30, BRED);
//  LCD_Clear(0, 120, 40, 30, GRED);
//  LCD_Clear(0, 150, 40, 30, GBLUE);
//  LCD_Clear(0, 180, 40, 30, BLACK);
//  LCD_Clear(0, 210, 40, 30, RED);  
//  
//  sw_delay_ms(500);
//}

///******************************************************
//* ��������Get_touch_point
//* ����  ��ͨ�� K A B C D E F ��ͨ��X Y��ֵת��ΪҺ��������
//* ����  : ��
//* ���  ������1��ʾ�ɹ� 0ʧ��
//* ����  ����
//* ע��  �������ȡ�Ĵ�����Ϣ���󣬽�����DISABLE
//*********************************************************/    
////long double linear=0 ;
////long double aa1=0,bb1=0,cc1=0,aa2=0,bb2=0,cc2=0;
//FunctionalState Get_touch_point(Coordinate * displayPtr,
//                                Coordinate * screenPtr,
//                                Parameter * para )
//{
//  FunctionalState retTHRESHOLD =ENABLE ;

//  if(screenPtr==0)
//  {
//    /*�����ȡ�Ĵ�����Ϣ�����򷵻�DISABLE*/
//    retTHRESHOLD = DISABLE;			
//  }
//  else
//  {    
//    if( para->Divider != 0 )
//    {        
//      displayPtr->x = ( (aa1 * screenPtr->x) + (bb1 * screenPtr->y) + cc1);        
//      displayPtr->y = ((aa2 * screenPtr->x) + (bb2 * screenPtr->y) + cc2 );
//    }
//    else
//    {
//      retTHRESHOLD = DISABLE;
//    }
//  }
//  return(retTHRESHOLD);
//} 

///******************************************************
//* ��������Palette_draw_point
//* ����  ����LCDָ��λ�û�һ�����(�����ĸ�С��)
//* ����  : Xpos		--X����λ��
//*         Ypos		--Y����λ��
//* ���  ����
//* ����  ��Palette_draw_point(100,100);
//* ע��  ���ú����� "��������Ӧ��ʵ��" ר�ú���
//*********************************************************/    
//void Palette_draw_point(uint16_t x, uint16_t y)
//{
//  /* ����Ĭ��Ϊ��ɫ */
//  static u16 Pen_color=0; 
//  u16 y_pos = y;

//  /* �ڻ�����ȡɫ */
//  if( x<40 )
//  {
//    if( y>30 )
//    Pen_color = (y_pos<60)?GREEN:\
//                (y_pos<90)?BLUE:\
//                (y_pos<120)?BRED:\
//                (y_pos<150)?GRED:\
//                (y_pos<180)?GBLUE:\
//                (y_pos<210)?BLACK:\
//                (y_pos<240)?RED:BLUE;
//    else
//    {/* ���� */      
//      #if 1
//      LCD_Clear(40, 0, 280, 240, BLACK);
//      #elif 0
//      LCD_Clear(40, 0, 280, 240, WHITE);
//      #endif
//      return;
//    }
//  }
//  else
//  {
//    #if 0
//    LCD_SetPoint(x , y , Pen_color);
//    LCD_SetPoint(x+1 , y , Pen_color);
//    LCD_SetPoint(x , y+1 , Pen_color);
//    LCD_SetPoint(x+1 , y+1 , Pen_color);
//    #elif 1
//    LCD_SetPoint(x , y , Pen_color);
//    LCD_SetPoint(x-1 , y , Pen_color);
//    LCD_SetPoint(x , y-1 , Pen_color);
//    LCD_SetPoint(x+1 , y , Pen_color);
//    LCD_SetPoint(x , y+1 , Pen_color);
//    #endif
//  }	
//}


