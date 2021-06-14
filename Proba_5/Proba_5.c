/*
 * Proba_4.c
 *
 *  Created on: Jun 7, 2021
 *      Author: osboxes
 */


#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>





#define MPin    2
#define MPin1   4
#define LDR	      0
#define LDR1	  1




int main(void)
{



        printf("Mikel wwProgram is starting ... \n");

        wiringPiSetup();        //Initialize wiringPi.
        softPwmCreate(MPin,  0, 100);//Create SoftPWM pin
        softPwmCreate(MPin1,  0, 100);//Create SoftPWM pin


        	while(1)
        	{



				while(digitalRead(LDR1) == 1 && digitalRead(LDR) == 1 )
				{


					printf("Detecta recto \n");
					softPwmWrite(MPin, 70);
					softPwmWrite(MPin1, 70);


				}


				//Create SoftPWM pin

        		while(digitalRead(LDR) == 1 && digitalRead(LDR1) == 0 )
        		{


        			softPwmWrite(MPin1, 0);
        			printf("Detecta derecha \n");
        			softPwmWrite(MPin, 70);




        		}



        		while(digitalRead(LDR) == 0 && digitalRead(LDR1) == 1 )
        		{
        			softPwmWrite(MPin, 0);

        		printf("Detecta izquierda \n");
        		softPwmWrite(MPin1, 70);


        		}


        		while(digitalRead(LDR1) == 0 && digitalRead(LDR) == 0 )
        		{

        			softPwmWrite(MPin, 0);
        			softPwmWrite(MPin1, 0);
        			//delay(700);
        			printf("Delay \n");

        		}




        	}



                        printf("Itzali naiz");
        				return 0;

}



