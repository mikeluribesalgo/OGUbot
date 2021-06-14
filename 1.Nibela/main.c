#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>

#define MOTORIZQUIERDA    2
#define MOTORDERECHA    4

void hasieratu();
void automatic();
int fitxategiaIrakurri(int instruct[]);
int fitxCond(FILE* fp, int instruct[]);
void bukatu();
int main(void) {
	//TODO DE JOSEBA
	printf("fitxategia wwProgram is starting ... \n");

	hasieratu();
	automatic();
	bukatu();
}

void hasieratu(){


	wiringPiSetup();
	softPwmCreate(MOTORIZQUIERDA, 0, 100);        //Create SoftPWM pin
	softPwmCreate(MOTORDERECHA, 0, 100);        //Create SoftPWM pin
	softPwmWrite(MOTORIZQUIERDA,100);
	softPwmWrite(MOTORDERECHA,100);

}

void automatic(){

	int i = 0,instruct[20],kop=0;

    kop = fitxategiaIrakurri(instruct);

	while (i < kop) {
		if (instruct[i] == 1) {        //aurrera
			softPwmWrite(MOTORIZQUIERDA,100);
			softPwmWrite(MOTORDERECHA,100);
			delay(1000);
			softPwmWrite(MOTORIZQUIERDA,0);
			softPwmWrite(MOTORDERECHA,0);
			delay(300);
		}
		if (instruct[i] == 2) {//eskumara biratu
			softPwmWrite(MOTORIZQUIERDA,100);
			delay(1000);
			softPwmWrite(MOTORIZQUIERDA,0);
			delay(300);
		}
		if (instruct[i] == 3) {//ezkerra biratu
			softPwmWrite(MOTORDERECHA,100);
			delay(1000);
			softPwmWrite(MOTORDERECHA,0);
			delay(300);
		}

		i++;
	}



}

int fitxategiaIrakurri(int instruct[]) {
    FILE* fp;
    int i = 0;

    fp = fopen("instrukzioak.txt", "r");
    if (fp != EOF)
    {
        i = fitxCond(fp, instruct);
    }
    fclose(fp);
    return i;
}

int fitxCond(FILE* fp, int instruct[]) {
    int i = 0;
    char str[128];
    int irakurritako = 1;
    while (irakurritako != 0) {
        irakurritako = fgets(str, 128, fp);
        str[strlen(str) - 1] = '\0';
        if (irakurritako != 0) {
            if (strcmp(str, "aurrera") == 0) {
                instruct[i] = 1;
            }
            if (strcmp(str, "eskuma") == 0) {
                instruct[i] = 2;
            }
            if (strcmp(str, "ezkerra") == 0) {
                instruct[i] = 3;
            }
            i++;
        }
    }
    return i;
}

void bukatu(){
	softPwmStop(MOTORIZQUIERDA);
	softPwmStop(MOTORDERECHA);
}
