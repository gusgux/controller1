/*
 * File:          controller1.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/differential_wheels.h>, etc.
 */
#include  <stdio.h>
#include <webots/robot.h>
#include <webots/led.h>

/*
 * You may want to add macros here.
 */
#define TIME_STEP 1000

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv)
{
  /* necessary to initialize webots stuff */
  wb_robot_init();
 
  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */
   printf("doing some setup! \n");
   int seconds_counter=0;
   int led_state=0;
   
   WbDeviceTag my_led=wb_robot_get_device("led");

  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
  while (wb_robot_step(TIME_STEP) != -1) {
  
   printf("doing some repetitve task! \n");
   printf("Time= %i \n",seconds_counter);
   seconds_counter++;

    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */

 //wb_led_set(my_led,0);


led_state=wb_led_get(my_led);
printf("led value= %i \n",led_state);
  if(led_state==0)
    
    wb_led_set(my_led,1);
    
      else{
        wb_led_set(my_led,0);
      
      }
    /* Process sensor data here */

    /*
     * Enter here functions to send actuator commands, like:
     * wb_differential_wheels_set_speed(100.0,100.0);
     */
     
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
