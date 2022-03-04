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
      light->current_state = (TrafficLightState *)&light->red_light_state;
    } break;
    case ENUM_LIGHT_COLOR_GREEN: {
      light->current_state = (TrafficLightState *)&light->green_light_state;
    } break;
    case ENUM_LIGHT_COLOR_YELLOW: {
      light->current_state = (TrafficLightState *)&light->yellow_light_state;
    } break;
  }
}

void init_red_light_state(RedLightState *state) {
  strncpy(state->s.color, "red", sizeof(state->s.color) - 1);
  state->s.turn_light = red_light_state_turn_light;
}

void init_green_light_state(GreenLightState *state) {
  strncpy(state->s.color, "green", sizeof(state->s.color) - 1);
  state->s.turn_light = green_light_state_turn_light;
}
void init_yellow_light_state(YellowLightState *state) {
  strncpy(state->s.color, "yellow", sizeof(state->s.color) - 1);
  state->s.turn_light = yellow_light_state_turn_light;
}

void red_light_state_turn_light(TrafficLightPtr light) {
  light->set_state(light, (TrafficLightState *)&light->green_light_state);
}

void green_light_state_turn_light(TrafficLightPtr light) {
  light->set_state(light, (TrafficLightState *)&light->yellow_light_state);
}

void yellow_light_state_turn_light(TrafficLightPtr light) {
  light->set_state(light, (TrafficLightState *)&light->red_light_state);
}

void traffic_light_set_state(TrafficLightPtr light, TrafficLightState *state) {
  light->current_state = state;
}

char *traffic_light_get_color(TrafficLightPtr light) {
  return light->current_state->color;
}

void traffic_light_turn_light(TrafficLightPtr light) {
  light->current_state->turn_light(light);
}
