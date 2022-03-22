/*
 ============================================================================
 Name        : Mini_project1.c
 Author      : Rahma Abdelkader
 Version     :
 Copyright   : Your copyright notice
 Description : vehicle control program
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define OFF 0
#define ON 1
char option,option2,option3,color;
int speed,room_temperature,eng_temperature,engine_state;
int engine_temperatureController ;
int current_temp1;//room
int current_temp2;//engine
int  AC = OFF;

//functions prototypes

void output_screen();
void sensor_menu();
void engine_off();

int main()

{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

  //display main menu

printf("choose one of the following options \n");
printf("a- Turn on vehicle engine \n");
printf("b- Turn off vehicle engine \n");
printf("c- Quit the system \n");
scanf("%c",&option);
 switch (option){
   case 'c' :
   printf("quit the program \n");
   break ;

   case 'b' :
	   engine_off();
   break;

   case 'a' :
       sensor_menu();
  break;

 default :
	printf("invalid input");
}
 return 0;
}

     // functions to display sensor menu which consists of 4 options

void sensor_menu(){

	 printf("sensor set menu \n ");
		 printf("a-Turn off the engine \n ");
		 printf("b-set the traffic light color \n ");
		 printf("c-set the room temperature (temperature sensor) \n ");
		 printf("d-set the engine temperature (engine temperature sensor) \n");
	 scanf(" %c",&option3);

		 switch(option3){
		 case 'a':

			 engine_off();
			 break ;
		 case 'b':
	        printf("enter the color");

			 scanf(" %c", &color);
			 if(color=='G'){
				 speed=100 ;
				 printf("vehicle speed is %d km/hr \n ",speed);

			 }
			  if(color =='O'){
				 speed=30;
				 printf("vehicle speed is %d km/hr \n",speed);

			 }
			  if(color =='R'){
				 speed =0 ;
			 printf("vehicle speed is %d km/hr \n",speed);


			 }

			  output_screen();
			 			 sensor_menu();
			 break;

		 case 'c':

	         printf("enter room temperature \n");
			 scanf("%d",&room_temperature);  //room temrperature sensor
			 if(room_temperature <10)
			 {
				 AC = ON ;
				 room_temperature=20;
			 }
			 else if (room_temperature >30){
				 AC=ON;
				 room_temperature =20;
			 }
			 else{
			 AC=0;
			 }

			 output_screen();
			 sensor_menu();
		  break;

		 case 'd':
		 {
			 printf("enter engine temperature \n");
			 scanf(" %d",&eng_temperature);
			 if(eng_temperature <100){
				 engine_temperatureController=ON;
				 eng_temperature=125;
			 }
			 else if (eng_temperature>150 ){
				 engine_temperatureController=ON;
				 eng_temperature=125;
			 }
			 else{
				 engine_temperatureController=OFF;
		 }
			 output_screen();
						 sensor_menu();
	       break ;}
	 default :{
	printf("invalid input");
	 output_screen();
				 sensor_menu();
	 }

		 }


}

        //function to show the vehicle state

void output_screen(){
	if(speed==30){
		printf("set room tempreture");
		scanf("%d",&current_temp1);
		printf("set engine tempreture");
		scanf("%d",&current_temp2);
	 	 	 room_temperature=current_temp1*(5/4)+1;
	 	 	 AC=ON;
	 	 	 engine_temperatureController=ON;
	 	 	 eng_temperature=current_temp2*(5/4)+1;

	}
	         //printf("vehicle speed is %d Km/hr \n",speed);
	 	 	 printf("Room temperature is %d C \n",room_temperature);
	 	 	 printf("engine temperature is %d C \n ",eng_temperature);

	 	 	 if(engine_state==ON){
	 	 		 printf("engine state is on \n ");
	 	 	 }
	 	 		 else{
	 	 			 printf("engine state is off \n");
	 	 	 }

	 		 if(AC==ON){
	 		 	 		 printf("AC is on \n ");
	 		 	 	 }
	 		 	 		 else{
	 		 	 			 printf("AC is off \n");
	 		 	 	 }



 	 	  if(engine_temperatureController==ON){
 	 	            	printf("engine temperature Controller state is ON \n");
 	 	             }
 	 	            	else{
 	 	            		printf("engine temperature controller state is OFF \n");
 	 	             }


}

     // function to turn engine on or off or quit

  void engine_off(){
	 printf("are you sure you want to turn off? choose an option \n ");
	   printf("choose one of the following options \n");
	   printf("a- Turn on vehicle engine \n");
	   printf("b- Turn off vehicle engine \n");
	   printf("c- Quit the system \n");

	       scanf(" %c",  &option2);
	       switch (option2){
	          case 'a':
	        	  engine_state=ON;
	    	  printf("engine is turned on");
	    	  sensor_menu(option2);

	    	  break;
	          case 'b':
	        	  engine_state=OFF;
	    	  printf("engine is turned off");
	    	  break;
	         case 'c':
	    	  printf("quit the program");
	    	 break;
	      default :
	    	  printf("invalid input");

	       }
}
