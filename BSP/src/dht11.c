#include "stm32f10x.h"
#include "dht11.h"
#include "sw_delay.h"
#include "sys.h"

#define DHT11_Mode_Out_PP()
#define DHT11_Mode_IPU()

static uint8_t dht11_index = 0;

 /**************************************************************************************
 * 描  述 : 初始化DHT11信号引脚为输出
 * 入  参 : 无
 * 返回值 : 无
 **************************************************************************************/
void DHT11_GPIO_Config(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(DHT11_CLK, ENABLE); 
													   
	GPIO_InitStructure.GPIO_Pin = DHT11_PIN1|DHT11_PIN2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;   //开漏输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(DHT11_PORT, &GPIO_InitStructure);		  

	GPIO_SetBits(DHT11_PORT, DHT11_PIN1|DHT11_PIN2);	 
}

static uint8_t DHT11_DATA_IN()
{
	if(dht11_index == 1)
	{
		return GPIO_ReadInputDataBit(DHT11_PORT,DHT11_PIN1);
	}
	else 
	{
		return GPIO_ReadInputDataBit(DHT11_PORT,DHT11_PIN2);		
	}
}
void DHT11_DATA_OUT(uint8_t dat)
{
	if(dht11_index == 1)
	{
//		PBout(DHT11_PIN1) = dat;
		if(dat)
			GPIO_SetBits(DHT11_PORT,DHT11_PIN1);
		else
			GPIO_ResetBits(DHT11_PORT,DHT11_PIN1);	
	}
	else 
	{
//		PBout(DHT11_PIN2) = dat;
		if(dat)
			GPIO_SetBits(DHT11_PORT,DHT11_PIN2);
		else
			GPIO_ResetBits(DHT11_PORT,DHT11_PIN2);	
	}	
}
 /**************************************************************************************
 * 描  述 : 从DHT11读取一个字节，MSB先行
 * 入  参 : 无
 * 返回值 : uint8_t
 **************************************************************************************/
static uint8_t Read_Byte(void) 
{
	uint8_t i, temp=0;

	for(i=0;i<8;i++)    
	{	   
		while(DHT11_DATA_IN()==Bit_RESET);  //每bit以50us低电平标置开始，轮询直到从机发出 的50us 低电平 结束

		/*DHT11 以26~28us的高电平表示“0”，以70us高电平表示“1”  */
		sw_delay_us(40); //延时40us,这个延时需要大于数据0持续的时间即可	   	  

		if(DHT11_DATA_IN() == Bit_SET)  //  40us后仍为高电平表示数据“1”
		{
			while(DHT11_DATA_IN()==Bit_SET);  //等待数据1的高电平结束
			temp|=(uint8_t)(0x01<<(7-i));  //把第7-i位置1，MSB先行 
		}
		else	 // 40us后为低电平表示数据“0”
		{			   
			temp&=(uint8_t)~(0x01<<(7-i)); //把第7-i位置0，MSB先行
		}
	}
	return temp;
}

 /**************************************************************************************
 * 描  述 : 一次完整的数据传输为40bit，高位先出
 * 入  参 : 8bit 湿度整数 + 8bit 湿度小数 + 8bit 温度整数 + 8bit 温度小数 + 8bit 校验和 
 * 返回值 : uint8_t
 **************************************************************************************/
uint8_t Read_DHT11(DHT11_Data_TypeDef *DHT11_Data,uint8_t index)
{
	uint8_t timeout = 80;
	DHT11_Mode_Out_PP();   //输出模式
	dht11_index = index;
	DHT11_DATA_OUT(LOW);   //主机拉低
	sw_delay_ms(18);       //延时18ms
	
	rt_enter_critical();
	DHT11_DATA_OUT(HIGH);  //总线拉高 主机延时30us
	sw_delay_us(30);   	   //延时30us

	DHT11_Mode_IPU();   	//主机设为输入 判断从机响应信号
   
	if(DHT11_DATA_IN()== Bit_RESET)  //判断从机是否有低电平响应信号 如不响应则跳出，响应则向下运行   
	{  
		while(DHT11_DATA_IN() == Bit_RESET)  //轮询直到从机发出 的80us 低电平 响应信号结束
		{
			if(timeout == 0)
			{
				rt_exit_critical();
				return ERROR;
			}
			timeout --;
			sw_delay_us(1);
		}
		timeout = 80;
		while(DHT11_DATA_IN() == Bit_SET)    //轮询直到从机发出的 80us 高电平 标置信号结束
		{
			if(timeout == 0)
			{
				rt_exit_critical();
				return ERROR;
			}
			timeout --;
			sw_delay_us(1);
		}
		/*开始接收数据*/   
		DHT11_Data->humi_int= Read_Byte();
		DHT11_Data->humi_deci= Read_Byte();
		DHT11_Data->temp_int= Read_Byte();
		DHT11_Data->temp_deci= Read_Byte();
		DHT11_Data->check_sum= Read_Byte();
		rt_exit_critical();
		
		DHT11_Mode_Out_PP();   //读取结束，引脚改为输出模式
		DHT11_DATA_OUT(HIGH);   //主机拉高

		/*检查读取的数据是否正确*/
		if(DHT11_Data->check_sum == DHT11_Data->humi_int + DHT11_Data->humi_deci + DHT11_Data->temp_int+ DHT11_Data->temp_deci)
		{	
			return SUCCESS;
		}
		else 
			return ERROR;
	}
	else
	{
		rt_exit_critical();	
		return ERROR;
	}   
}
