#include <stdio.h>
#include <math.h>
#include<stdlib.h>

      
void printPWMGammaTable(double PWMgamma, int maxValue){
	//double PWMgamma   = 1.8; // Correction factor
	int max_in  = 100, // Top end of INPUT range
		max_out = 100; // Top end of OUTPUT range
	printf("\n[C code]\n//Gamma = %f\nconst uint8_t gamma1_8PWM[] = {",PWMgamma);
	for(int i=0; i<=max_in; i++) {
		if(i > 0) printf(",");
		if((i & 15) == 0) printf("\n  ");

		printf("%3d",(int)(pow((double)i / (double)max_in, PWMgamma) * max_out + 0.5));
	}
	printf("\n };\n[/C code]\n\n");
}

void printRGBGammaTable(double RGBgamma, int maxValue){
	//double gamma   = 2.2; // Correction factor
	int max_in  = 255, // Top end of INPUT range
		max_out = 255; // Top end of OUTPUT range
	printf("\n[C code]\n//Gamma = %f\nconst uint8_t gamma2_2[] = {",RGBgamma);
	for(int i=0; i<=max_in; i++) {
		if(i > 0) printf(",");
		if((i & 15) == 0) printf("\n  ");

		printf("%3d",(int)(pow((double)i / (double)max_in, RGBgamma) * max_out + 0.5));
	}
	printf("\n };\n[/C code]\n\n");
}

int main(int argc, char **argv) {
	double factor;
	int maxVal;
	
	if(argc<3){
		printf("Usage: /gamma factor maxValue\nWhere,\n\tfactor is a double between 0 and 3\n\t maxValue is the largest input/output value\n\n");
		return 0;
	}
	
	factor = atof(argv[1]);
	maxVal = atoi(argv[2]);
	if(maxVal==100){
		printPWMGammaTable(factor, maxVal);
	}else{
		printRGBGammaTable(factor, maxVal);
	}
	return 0;
}
