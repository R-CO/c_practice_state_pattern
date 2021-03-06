/**
 * @file main.c
 * @author daniel1820kobe@gmail.com
 * @brief Demo of using traffic_light.h
 * @version 0.1
 * @date 2022-03-05
 * 
 * @copyright Copyright (c) 2022 R-CO. All rights reserved. 
 * This project is released under the GNU Public License.
 */
#include <stdio.h>
#include <stdlib.h>

#include "traffic_light.h"

int main(int argc, char *argv[]) {
  TrafficLight traffic_light;
  init_traffic_light(&traffic_light, ENUM_LIGHT_COLOR_RED);

  printf("current light color is : %s\n",
         traffic_light.get_color(&traffic_light));

  traffic_light.turn_light(&traffic_light);
  printf("light turn\ncurrent light color is : %s\n",
         traffic_light.get_color(&traffic_light));

  traffic_light.turn_light(&traffic_light);
  printf("light turn\ncurrent light color is : %s\n",
         traffic_light.get_color(&traffic_light));

  traffic_light.turn_light(&traffic_light);
  printf("light turn\ncurrent light color is : %s\n",
         traffic_light.get_color(&traffic_light));

  traffic_light.turn_light(&traffic_light);
  printf("light turn\ncurrent light color is : %s\n",
         traffic_light.get_color(&traffic_light));

  traffic_light.turn_light(&traffic_light);
  printf("light turn\ncurrent light color is : %s\n",
         traffic_light.get_color(&traffic_light));

  return EXIT_SUCCESS;
}
