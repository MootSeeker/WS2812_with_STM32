/*
 *
 *  Description:
 *  ------------
 *
 *    project name: WS2812(B) Library
 *    File Name: WS2812.h
 *	  Software IDE: System Workbench for STM32
 *
 *
 *    Version:		Date:        Author:         comment:
 *    --------		-----------  --------------  -------------------
 *    1.00			01.06.2017   Kevin Perillo   build.
 *
 *
 *    Copyright (c) Fancy Electronics 2017
 ***********************************************************************************/

/*
	In this Library, you can use the follow LEDs:

		- WS2811 NeoPixel LED
		- WS2812 5050 LED
		- WS2812 3550 LED
		- WS2812 3535 LED
		- WS2812B LED
*/

/* Defines for prevent File issues. -------------------------------------*/
#ifndef __WS2812_H
#define __WS2812_H

/* Includes ------------------------------------------------------------------*/

/* Defines ------------------------------------------------------------------*/
#define WS2812_NUM_LEDS_CH1		8		// Define Number of LEDs.

#define WS2812_TIM_PRESCALE      0      // F_T3  = 72 MHz (13.88ns)
#define WS2812_TIM_PERIODE   	89  	// F_PWM = 800 kHz (1.25us)

#define WS2812_LO_TIME        	29  	// PWM Low Time  29 * 13,9ns = 0.43us
#define WS2812_HI_TIME        	58  	// PWM High Time 58 * 13.9ns = 0.81us

#define WS2812_BUFLEN (WS2812_NUM_LEDS_CH1+2)*24

//--------------------------------------------------------------
// RGB LED Color define (3 x 8bit)
//--------------------------------------------------------------
typedef struct
{
  unsigned char red;    			// 0...255 (as PWM-Value)
  unsigned char green;  			// 0...255 (as PWM-Value)
  unsigned char blue;   			// 0...255 (as PWM-Value)
}WS2812_RGB_t;


//--------------------------------------------------------------
// HSV LED Color define
//--------------------------------------------------------------
typedef struct
{
  unsigned int h;     	// 0...359 (in Grad, 0=R, 120=G, 240=B)
  unsigned char s;      // 0...100 (in Prozent)
  unsigned char v;      // 0...100 (in Prozent)
}WS2812_HSV_t;


WS2812_RGB_t WS2812_LED_BUF_CH1[WS2812_NUM_LEDS_CH1];

/* DMA Callback ------------------------------------------------------------------*/
void DMA_Callback(void);

/* Library Interface ------------------------------------------------------------------*/
void WS2812_Refresh		(void);
void WS2812_Clear		(void);
void WS2812_RGB2HSV		(WS2812_HSV_t hsv_col, WS2812_RGB_t *rgb_col);
void WS2812_One_RGB		(unsigned int nr, WS2812_RGB_t rgb_col, unsigned char refresh);
void WS2812_All_RGB		(WS2812_RGB_t rgb_col, unsigned char refresh);
void WS2812_One_HSV		(unsigned int nr, WS2812_HSV_t hsv_col, unsigned char refresh);
void WS2812_All_HSV		(WS2812_HSV_t hsv_col, unsigned char refresh);
void WS2812_Shift_Left	(unsigned char refresh);
void WS2812_Shift_Right	(unsigned char refresh);
void WS2812_Rotate_Left	(unsigned char refresh);
void WS2812_Rotate_Right(unsigned char refresh);


#endif

/************************ (C) COPYRIGHT Fancy Electronics ***** END OF FILE ****/
