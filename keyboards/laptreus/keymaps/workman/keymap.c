#include QMK_KEYBOARD_H
#include "laptreus.h"

enum layer_names {
  _WORKMAN = 0,
  _QWERTY,
  _RAISE,
  _ARR,
};

// Fillers to make layering more clear
#define _LAYER_ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_WORKMAN] = LAYOUT(
    KC_TAB  , KC_Q    , KC_D    , KC_R    , KC_W    , KC_B    , KC_J       , KC_F    , KC_U    , KC_P    , KC_SCLN , KC_BSPC ,
    KC_LCTL , KC_A    , KC_S    , KC_H    , KC_T    , KC_G    , KC_Y       , KC_N    , KC_E    , KC_O    , KC_I    , KC_QUOT ,
    KC_LGUI , KC_Z    , KC_X    , KC_M    , KC_C    , KC_V    , KC_K       , KC_L    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
    KC_LALT , MO(_ARR), XXXXXXX , XXXXXXX , KC_SPC  , KC_LSFT , MO(_RAISE) , KC_ENT  , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
  ),
  [_QWERTY] = LAYOUT(
    _______ , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , _______ ,
    _______ , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , _______ ,
    _______ , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
  ),
  [_RAISE] = LAYOUT(
    S(KC_SLASH) , KC_EXLM     , KC_AT        , KC_LCBR , KC_RCBR     , KC_PIPE , KC_PLUS  , KC_7    , KC_8    , KC_9    , KC_ASTR  , KC_BSPC ,
    KC_AMPR     , KC_HASH     , KC_DLR       , KC_LPRN , KC_RPRN     , KC_GRV  , KC_COLON , KC_4    , KC_5    , KC_6    , KC_EQUAL , S(KC_QUOTE),
    KC_TRNS     , KC_PERC     , KC_CIRC      , KC_LBRC , KC_RBRC     , KC_TILD , KC_MINUS , KC_1    , KC_2    , KC_3    , KC_BSLASH, KC_TRNS ,
    RESET       , TO(_QWERTY) , TO(_WORKMAN) , _______ , S(KC_MINUS) , KC_ESC  , _LAYER_  , KC_CAPS , KC_0    , KC_DOT  , _______  , _______
  ),
  [_ARR] = LAYOUT(
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KCXLEFT , KCXDOWN , KCXUP   , KCXRIGHT , XXXXXXX , XXXXXXX ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KCXPGDN , KCXPGUP , XXXXXXX  , XXXXXXX , XXXXXXX ,
    XXXXXXX , _LAYER_ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX ,
  ),
};
