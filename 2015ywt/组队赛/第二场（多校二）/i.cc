#include<cstdio>
#include<cstring>
using namespace std;

int n;
int main()
{
	while(scanf("%d", &n) != EOF){
		if (n < 4) puts("-1");
		else if (n == 21){
			puts("1 / 2");
			puts("3 / 4");
			puts("5 / 6");
			puts("7 - 8");
			for (int i = 9; i < 21; i++)
				printf("%d * %d\n", i, 25+i-9);
			puts("22 + 37");
			puts("23 + 38");
			puts("24 + 39");
			puts("21 + 40");
		}
		else if (n >= 20){
			if (n & 1){
				for (int i = 1; i <= 10; i++)
					printf("%d / %d\n", i, i+10);
				printf("%d + %d\n", n+1, n+2);
				printf("%d + %d\n", n+1+10, n+3);
				printf("%d + %d\n", n+1+11, n+4);
				printf("%d + %d\n", n+5, n+6);
				printf("%d + %d\n", n+1+13, n+7);
				printf("%d + %d\n", n+1+14, n+8);
				printf("%d + %d\n", n+1+15, n+9);
				printf("%d + %d\n", n+1+16, n+10);
				puts("21 - 22");
				for (int i = 23, j = 0; i <= n; i++, j++)
					printf("%d * %d\n", n+1+18+j, i);
				printf("%d + %d\n", n*2-3, n+1+12);
				printf("%d * %d\n", n*2-2, n+1+17);
			}
			else{
				for (int i = 1; i <= 10; i++)
					printf("%d / %d\n", i, i+10);
				printf("%d + %d\n", n+1, n+2);
				printf("%d + %d\n", n+1+10, n+3);
				printf("%d + %d\n", n+1+11, n+4);
				printf("%d + %d\n", n+5, n+6);
				printf("%d + %d\n", n+1+13, n+7);
				printf("%d + %d\n", n+1+14, n+8);
				printf("%d + %d\n", n+1+15, n+9);
				printf("%d + %d\n", n+1+16, n+10);
				if (n >= 22){
					puts("21 - 22");
					for (int i = 23, j = 0; i <= n; i++, j++)
						printf("%d * %d\n", n+1+18+j, i);
					printf("%d + %d\n", n*2-3, n+1+12);
					printf("%d * %d\n", n*2-2, n+1+17);
				}
				else{
					printf("%d * %d\n", n+1+12, n+1+17);
				}
			}
		}
		if (n == 4){
			puts("1 * 2");
			puts("5 + 3");
			puts("6 + 4");

		}
		else if (n == 5){
puts("1 / 2");
puts("6 / 3");
puts("4 - 7");
puts("8 * 5");


		}
		else if (n == 6){
puts("1 + 2");
puts("7 + 3");
puts("8 + 4");
puts("9 + 5");
puts("10 - 6");

		}
		else if (n == 7){
puts("1 + 2");
puts("8 + 3");
puts("9 / 4");
puts("10 + 5");
puts("11 + 6");
puts("12 + 7");


		}
		else if (n == 8){

puts("1 + 2");
puts("9 + 3");
puts("4 - 5");
puts("11 * 6");
puts("12 * 7");
puts("13 * 8");
puts("10 + 14");


		}
		else if (n == 9){
puts("1 / 2");
puts("3 / 4");
puts("5 / 6");
puts("10 + 11");
puts("12 + 13");
puts("7 - 14");
puts("15 + 8");
puts("16 + 9");


		}
		else if (n == 10){

puts("1 / 2");
puts("3 / 4");
puts("5 / 6");
puts("7 / 8");
puts("9 + 10");
puts("11 + 12");
puts("13 + 14");
puts("15 + 16");
puts("17 + 18");

		}
		else if (n == 11){
puts("1 / 2");
puts("3 / 4");
puts("5 + 6");
puts("7 - 8");
puts("15 * 9");
puts("16 * 10");
puts("17 * 11");
puts("18 + 12");
puts("19 + 13");
puts("20 + 14");

		}
		else if (n == 12){
puts("1 + 2");
puts("3 - 4");
puts("14 * 5");
puts("15 * 6");
puts("16 * 7");
puts("17 * 8");
puts("18 * 9");
puts("19 * 10");
puts("20 * 11");
puts("21 * 12");
puts("22 + 13");


		}
		else if (n == 13){
puts("1 + 2");
puts("3 / 4");
puts("5 / 6");
puts("7 - 8");
puts("17 * 9");
puts("18 * 10");
puts("19 * 11");
puts("20 * 12");
puts("21 * 13");
puts("22 + 14");
puts("23 - 15");
puts("24 - 16");


		}
		else if (n == 14){
puts("1 + 2");
puts("3 / 4");
puts("5 / 6");
puts("7 / 8");
puts("9 / 10");
puts("11 - 12");
puts("20 * 13");
puts("21 * 14");
puts("22 + 15");
puts("23 - 16");
puts("24 - 17");
puts("25 - 18");
puts("26 - 19");


		}
		else if (n == 15){
puts("1 / 2");
puts("3 / 4");
puts("5 / 6");
puts("7 / 8");
puts("9 / 10");
puts("11 / 12");
puts("16 + 17");
puts("22 + 18");
puts("19 + 20");
puts("24 + 21");
puts("23 * 25");
puts("26 + 13");
puts("27 + 14");
puts("28 - 15");


		}
		else if (n == 16){
puts("1 / 2");
puts("3 / 4");
puts("5 / 6");
puts("7 / 8");
puts("9 / 10");
puts("11 / 12");
puts("17 + 18");
puts("19 + 20");
puts("24 + 21");
puts("25 + 22");
puts("23 * 26");
puts("27 + 13");
puts("14 - 15");
puts("29 * 16");
puts("30 + 28");


		}
		else if (n == 17){
puts("1 / 2");
puts("3 / 4");
puts("5 / 6");
puts("7 / 8");
puts("9 / 10");
puts("11 / 12");
puts("13 / 14");
puts("15 + 18");
puts("25 + 19");
puts("26 + 20");
puts("27 + 21");
puts("28 + 22");
puts("29 + 23");
puts("30 + 24");
puts("31 + 16");
puts("32 - 17");


		}
		else if (n == 18){
puts("1 / 2");
puts("3 / 4");
puts("5 / 6");
puts("7 / 8");
puts("9 / 10");
puts("11 / 12");
puts("13 + 19");
puts("25 + 20");
puts("26 + 21");
puts("27 + 22");
puts("28 + 23");
puts("29 + 24");
puts("14 - 15");
puts("31 * 16");
puts("32 * 17");
puts("33 * 18");
puts("34 + 30");

		}
		else if (n == 19){
puts("1 / 2");
puts("3 / 4");
puts("5 / 6");
puts("7 / 8");
puts("9 / 10");
puts("11 + 20");
puts("25 + 21");
puts("26 + 22");
puts("27 + 23");
puts("28 + 24");
puts("13 - 12");
puts("30 * 14");
puts("31 * 15");
puts("32 * 16");
puts("33 * 17");
puts("34 * 18");
puts("35 * 19");
puts("36 + 29");

		}
	}
	return 0;
}
