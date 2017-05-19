/*
** Structures.hpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/interfaces/Structures.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Fri Mar 17 15:55:42 2017 Vincent DUSAUTOIR
** Last update Fri Mar 17 15:55:42 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_ARCADE_STRUCTURES_HPP
#define CPP_ARCADE_STRUCTURES_HPP

#include <string>

namespace arcade
{
  enum				eventType
  {
    ET_KEYBOARD_CLICK,
    ET_KEYBOARD_RELEASE,
    ET_WINDOW_CLOSED,
    ET_NONE
  };

  enum                      eventValue
  {
    EV_SPACE,
    EV_ESCAPE,
    EV_A,
    EV_B,
    EV_C,
    EV_D,
    EV_E,
    EV_F,
    EV_G,
    EV_H,
    EV_I,
    EV_J,
    EV_K,
    EV_L,
    EV_M,
    EV_N,
    EV_O,
    EV_P,
    EV_Q,
    EV_R,
    EV_S,
    EV_T,
    EV_U,
    EV_V,
    EV_W,
    EV_X,
    EV_Y,
    EV_Z,
    EV_ENTER,
    EV_BACKSPACE,
    EV_UP, // 30 and 2 in protocol
    EV_DOWN,
    EV_RIGHT,
    EV_LEFT,
    EV_0,
    EV_1,
    EV_2,
    EV_3,
    EV_4,
    EV_5,
    EV_6,
    EV_7,
    EV_8,
    EV_9,
    EV_UNKNOWN
  };

  typedef struct s_rectangle	rectangle;
  typedef struct s_pos 		pos;
  typedef union u_rgb		rgb;
  typedef struct s_text		text;
  typedef struct s_circle	circle;

  struct			s_pos
  {
    s_pos(uint64_t x = 0, uint64_t y = 0) : x(x), y(y){};
    uint64_t			x;
    uint64_t			y;
  };

  union				u_rgb
  {
    u_rgb(unsigned int full) : full(full){};
    u_rgb(unsigned char a, unsigned char r, unsigned char g, unsigned char b) {
      argb[0] = a;
      argb[1] = r;
      argb[2] = g;
      argb[3] = b;
    };
    unsigned char		argb[4];
    unsigned int		full;
  };

  struct			s_rectangle
  {
    s_rectangle(pos s = pos(0, 0), rgb c = rgb(255, 0, 0, 0), float r = 0, bool f = true, uint64_t t = 0) : size(s), color(c), rotate(r), full(f), thickness(t) {}
    pos				size;
    rgb				color;
    float			rotate;
    bool			full;
    uint64_t			thickness;
  };

  struct			s_text
  {
    s_text(rgb c = rgb(255, 0, 0, 0), uint64_t fS = 18, float r = 0.0, bool b = false, bool u = false, bool i = false) :
      color(c), fontSize(fS), rotate(r), bold(b), underline(u), italic(i) {}
    rgb				color;
    uint64_t			fontSize;
    float			rotate;
    bool			bold;
    bool			underline;
    bool			italic;
  };

  struct			s_circle
  {
    s_circle(rgb c = rgb(255, 0, 0, 0), uint64_t r = 1, bool f = true, uint64_t t = 0) :
      color(c), radius(r), full(f), thickness(t) {}
    rgb				color;
    uint64_t			radius;
    bool			full;
    uint64_t			thickness;
  };
}

#endif //CPP_ARCADE_STRUCTURES_HPP
