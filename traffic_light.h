/**
 * @file traffic_light.h
 * @author daniel1820kobe@gmail.com
 * @brief A practice of using pure C to implement state pattern.
 * @version 0.2
 * @date 2022-03-05
 * 
 * @copyright Copyright (c) 2022 R-CO. All rights reserved. 
 * This project is released under the GNU Public License.
 */
#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

typedef struct _TrafficLight *TrafficLightPtr;

typedef struct _TrafficLightState {
  void (*turn_light)(TrafficLightPtr light);
} TrafficLightState;

typedef struct _RedLightState {
  TrafficLightState s;
} RedLightState;

typedef struct _GreenLightState {
  TrafficLightState s;
} GreenLightState;

typedef struct _YellowLightState {
  TrafficLightState s;
} YellowLightState;

typedef struct _TrafficLight {
  // private:
  char color[16];

  TrafficLightState *current_state;

  RedLightState red_light_state;
  GreenLightState green_light_state;
  YellowLightState yellow_light_state;

  void (*set_state)(TrafficLightPtr light, TrafficLightState *state);

  // public:
  char *(*get_color)(TrafficLightPtr light);
  void (*turn_light)(TrafficLightPtr light);
} TrafficLight;

// clang-format off
typedef enum _EnumLightColor {
  ENUM_LIGHT_COLOR_RED    = 0,
  ENUM_LIGHT_COLOR_GREEN  = 1,
  ENUM_LIGHT_COLOR_YELLOW = 2
} EnumLightColor;
// clang-format on
void init_traffic_light(TrafficLight *light, EnumLightColor color);

#endif  // end of defin TRAFFIC_LIGHT_H
