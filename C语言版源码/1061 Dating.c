#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	char s1[65],s2[65],s3[65],s4[65];
	gets(s1);
	gets(s2);
	gets(s3);
	gets(s4);
	int i,j ;char data,time;
	for(i=0;s1[i]!='\0'&&s2[i]!='\0';i++){
		if(s1[i]>='A'&&s1[i]<='G'&&s2[i]>='A'&&s2[i]<='G'){
			if(s1[i]==s2[i]){
				data=s2[i];break;
			}
		}
	}
	for(j=i+1;s2[j]!='\0'&&s1[j]!='\0';j++){
		if(s2[j]>='A'&&s2[j]<='N'&&s1[j]>='A'&&s1[j]<='N'){
			if(s1[j]==s2[j]){
				time=s2[j];break;
			}
		}
		if(isdigit(s2[j])&&isdigit(s1[j])){
			if(s2[j]==s1[j]){
				time=s2[j];break;
			}
		}
	}
	
	for(i=0;s3[i]!='\0'&&s4[i]!='\0';i++){
		if(isalpha(s3[i])&&isalpha(s4[i])){
		
			if(s3[i]==s4[i]){
				
				break;
			}
	}
		
	}
	char data1[4],time1[3];
	switch(data){
		case 'A':strcpy(data1,"MON");break;
		case 'B':strcpy(data1,"TUE");break;
		case 'C':strcpy(data1,"WED");break;
		case 'D':strcpy(data1,"THU");break;
		case 'E':strcpy(data1,"FRI");break;
		case 'F':strcpy(data1,"SAT");break;
		case 'G':strcpy(data1,"SUN");break;
	}
	switch(time){
		case'A':strcpy(time1,"10");break;
		case'B':strcpy(time1,"11");break;
		case'C':strcpy(time1,"12");break;
		case'D':strcpy(time1,"13");break;
		case'E':strcpy(time1,"14");break;
		case'F':strcpy(time1,"15");break;
		case'G':strcpy(time1,"16");break;
		case'H':strcpy(time1,"17");break;
		case'I':strcpy(time1,"18");break;
		case'J':strcpy(time1,"19");break;
		case'K':strcpy(time1,"20");break;
		case'L':strcpy(time1,"21");break;
		case'M':strcpy(time1,"22");break;
		case'N':strcpy(time1,"23");break;
		case'0':strcpy(time1,"00");break;
		case'1':strcpy(time1,"01");break;
		case'2':strcpy(time1,"02");break;
		case'3':strcpy(time1,"03");break;
		case'4':strcpy(time1,"04");break;
		case'5':strcpy(time1,"05");break;
		case'6':strcpy(time1,"06");break;
		case'7':strcpy(time1,"07");break;
		case'8':strcpy(time1,"08");break;
		case'9':strcpy(time1,"09");break;
	}
	
	printf("%s %s:%02d",data1,time1,i);
	return 0;
}


