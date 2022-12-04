#include <stdio.h>
#include "B05_hotel.h"

int main(void)
{
	int nights;
	double hotel_rate;
	int code;

	while ((code = menu() != QUIT))
	{
		switch(code)
		{
		case 1 :
			hotel_rate = HOTEL1;
			break;
		case 2:
			hotel_rate = HOTEL2;
			break;
		case 3:
			hotel_rate = HOTEL3;
			break;
		case 4:
			hotel_rate = HOTEL4;
			break;
		default:
			hotel_rate = 0.0;
			printf("으악!\n");
			break;
		}
		nights = getnights();
		showprice(hotel_rate, nights);
	}
	printf("감사합니다. 안녕히 가십시오.\n");

	return 0;
}
