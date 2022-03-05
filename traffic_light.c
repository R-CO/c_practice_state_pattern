/**
 * @file traffic_light.c
 * @author daniel1820kobe@gmail.com
 * @brief A practice of using pure C to implement state pattern.
 * @version 0.2
 * @date 2022-03-05
 * 
 * @copyright Copyright (c) 2022 R-CO. All rights reserved. 
 * This project is released under the GNU Public License.
 */
#include "traffic_light.h"

#include <string.h>

static void init_red_light_state(RedLightState *state);
static void init_green_light_state(GreenLightState *state);
static void init_yellow_light_state(YellowLightState *state);

static void red_light_state_turn_light(TrafficLightPtr light);
static void green_light_state_turn_light(TrafficLightPtr light);
static void yellow_light_state_turn_light(TrafficLightPtr light);

static void traffic_light_set_state(TrafficLightPtr light,
                                    TrafficLightState *state);
static char *traffic_light_get_color(TrafficLightPtr light);
static void traffic_light_turn_light(TrafficLightPtr light);

void init_traffic_light(TrafficLight *light, EnumLightColor color) {
  light->set_state = traffic_light_set_state;
  light->get_color = traffic_light_get_color;
  light->turn_light = traffic_light_turn_light;

  init_red_light_state(&light->red_light_state);
  init_green_light_state(&light->green_light_state);
  init_yellow_light_state(&light->yellow_light_state);

  switch (color) {
    case ENUM_LIGHT_COLOR_RED: {
      strncpy(light->color, "red", sizeof(light->color) - 1);
      light->current_state = (TrafficLightState *)&light->red_light_state;
    } break;
    case ENUM_LIGHT_COLOR_GREEN: {
      strncpy(light->color, "green", sizeof(light->color) - 1);
      light->current_state = (TrafficLightState *)&light->green_light_state;
    } break;
    case ENUM_LIGHT_COLOR_YELLOW: {
      strncpy(light->color, "yellow", sizeof(light->color) - 1);
      light->current_state = (TrafficLightState *)&light->yellow_light_state;
    } break;
  }
}

void init_red_light_state(RedLightState *state) {
  state->s.turn_light = red_light_state_turn_light;
}

void init_green_light_state(GreenLightState *state) {
  state->s.turn_light = green_light_state_turn_light;
}
void init_yellow_light_state(YellowLightState *state) {
  state->s.turn_light = yellow_light_state_turn_light;
}

void red_light_state_turn_light(TrafficLightPtr light) {
  strncpy(light->color, "green", sizeof(light->color) - 1);
  light->set_state(light, (TrafficLightState *)&light->green_light_state);
}

void green_light_state_turn_light(TrafficLightPtr light) {
  strncpy(light->color, "yellow", sizeof(light->color) - 1);
  light->set_state(light, (TrafficLightState *)&light->yellow_light_state);
}

void yellow_light_state_turn_light(TrafficLightPtr light) {
  strncpy(light->color, "red", sizeof(light->color) - 1);
  light->set_state(light, (TrafficLightState *)&light->red_light_state);
}

void traffic_light_set_state(TrafficLightPtr light, TrafficLightState *state) {
  light->current_state = state;
}

char *traffic_light_get_color(TrafficLightPtr light) {
  return light->color;
}

void traffic_light_turn_light(TrafficLightPtr light) {
  light->current_state->turn_light(light);
}
