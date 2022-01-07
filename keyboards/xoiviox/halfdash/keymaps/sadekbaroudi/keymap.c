#include "sadekbaroudi.h"

#include QMK_KEYBOARD_H

#define _GAME 0
#define _FUNCTION 1
#define _KICAD 2
#define _FUSION 3
#define _ALPHA 4

enum custom_keycodes {
  GAME = SAFE_RANGE,
  FUNCTION,
  KICAD,
  FUSION,
  ALPHA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_GAME] = LAYOUT_halfdash( \
    KC_F4,   KC_F1,   KC_F2,   KC_C,    KC_V,    KC_G,    KC_N, \
    KC_Z,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_D,    KC_Y, \
    KC_P,    KC_A,    KC_F,    KC_TAB,  KC_L,    KC_H,    KC_F7, \
    KC_LSFT, KC_T,    KC_COMM, KC_K,    KC_SCLN, KC_DOT,  \
    KC_LCTL, KC_ESC,  MO(_FUNCTION),  KC_LALT,          KC_J,  KC_X, KC_B \
  ),

  /**
   *  /---------------v---------------v---------------v---------------v---------------v---------------v---------------\
   *  |               |               |               |               |               |               |               |
   *  |---------------|---------------|---------------|---------------|---------------|---------------|---------------|
   *  |               |               |               |               |               |               |               |
   *  |---------------|---------------|---------------|---------------|---------------|---------------|---------------|
   *  |               |               |               |               |               |               |               |
   *  |---------------|---------------|---------------|---------------|---------------|---------------|---------------/
   *  |               |               |               |               |               |               |
   *  |---------------|---------------|---------------|---------v-----^---------v-----|---------------|---------------|---------------\
   *  |               |               |               |         |               |     |               |               |               |
   *  \---------------|---------------|---------------|         \---------------/     \---------------|---------------|---------------/
   */
  [_FUNCTION] = LAYOUT_halfdash( \
    RESET,   TG(_KICAD), TG(_FUSION),      TG(_ALPHA),        KC_4,     KC_5,       KC_LBRC, \
    KC_TAB,  RGB_TOG,    RGB_MODE_REVERSE, RGB_MODE_FORWARD,  _______,  RGB_SPI,    BL_ON, \
    KC_CAPS, KC_RGB_BLT, RGB_HUI,          RGB_SAI,           RGB_VAI,  RGB_SPI,    BL_OFF, \
    KC_LSFT, KC_RGB_T,   RGB_HUD,          RGB_SAD,           RGB_VAD,  RGB_SPD,    \
    KC_LCTL, KC_LGUI,   _______,    KC_LALT,                                KC_BSPC,   KC_SPC, KC_ENT \
  ),

  /**
   *  /---------------v---------------v---------------v---------------v---------------v---------------v---------------\
   *  |    Escape     |   Zoom Home   |   Add Line    |    Add Arc    |  Add Polygon  |  Add Circle   |   Add Text    |
   *  |---------------|---------------|---------------|---------------|---------------|---------------|---------------|
   *  |  Select Net   |    Measure    |       X       |     Flip      |   Fill Zones  |  Unfill Zones |   3D Viewer   |
   *  |---------------|---------------|---------------|---------------|---------------|---------------|---------------|
   *  |     Copy      |     Undo      |    Rotate     | Edit Property |     Move      |      X        |      X        |
   *  |---------------|---------------|---------------|---------------|---------------|---------------|---------------/
   *  |     Paste     |     Redo      | Create Track  |       X       |    Add Via    | Front<->Back  |
   *  |---------------|---------------|---------------|---------v-----^---------v-----|---------------|---------------|---------------\
   *  |       X       |       X       |  TG(_KICAD)   |         |       X       |     |    Delete     |     Enter     |       X       |
   *  \---------------|---------------|---------------|         \---------------/     \---------------|---------------|---------------/
   */
  [_KICAD] = LAYOUT_halfdash( \
    KC_ESC,     KC_HOME,            LCTL(LSFT(KC_L)),   LCTL(LSFT(KC_A)),  LCTL(LSFT(KC_P)),   LCTL(LSFT(KC_C)),   LCTL(LSFT(KC_T)), \
    KC_GRV,     LCTL(LSFT(KC_M)),   KC_NO,              KC_F,              KC_B,               LCTL(KC_B),         LALT(KC_3), \
    LCTL(KC_C), LCTL(KC_Z),         KC_R,               KC_E,              LSFT(KC_M),         KC_G,               KC_NO, \
    LCTL(KC_V), LCTL(KC_Y),         KC_X,               KC_NO,             LCTL(LSFT(KC_V)),   KC_V, \
    KC_NO,      KC_NO,              TG(_KICAD),                     KC_NO,                KC_DEL,   KC_ENT, KC_NO \
  ),

  /**
   *  /---------------v---------------v---------------v---------------v---------------v---------------v---------------\
   *  |               |               |               |               |               |               |               |
   *  |---------------|---------------|---------------|---------------|---------------|---------------|---------------|
   *  |               |               |               |               |               |               |               |
   *  |---------------|---------------|---------------|---------------|---------------|---------------|---------------|
   *  |               |               |               |               |               |               |               |
   *  |---------------|---------------|---------------|---------------|---------------|---------------|---------------/
   *  |               |               |               |               |               |               |
   *  |---------------|---------------|---------------|---------v-----^---------v-----|---------------|---------------|---------------\
   *  |               |               |               |         |               |     |               |               |               |
   *  \---------------|---------------|---------------|         \---------------/     \---------------|---------------|---------------/
   */
  [_FUSION] = LAYOUT_halfdash( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_DEL , \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    \
    KC_LCTL, KC_LGUI, TG(_FUSION), KC_LALT,             KC_BSPC,  KC_SPC, KC_ENT \
  ),

  [_ALPHA] = LAYOUT_halfdash( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC, \
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_MINS, \
    KC_CAPS, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_DEL , \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    \
    KC_LCTL, KC_LGUI, TG(_ALPHA), KC_LALT,            KC_BSPC,  KC_SPC, KC_ENT \
  ),
};
