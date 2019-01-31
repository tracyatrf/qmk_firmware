#include QMK_KEYBOARD_H
#include "laptreus.h"

enum layer_names {
  _WORKMAN = 0,
  _RAISE,
};

// Fillers to make layering more clear
#define _LAYER_ KC_TRNS

// Adding macros to make the keymaps below much easier to read.
#define CTL_ESC CTL_T(KC_ESC)
#define CTL_GRV CTL_T(KC_GRV)
#define ALT_TAB ALT_T(KC_TAB)
#define SFT_SPC SFT_T(KC_SPC)

// Extended alpha key layers
#define RSE_J  LT(_RAISE, KC_J)
#define LWR_F  LT(_LOWER, KC_F)
#define RSE_H  LT(_RAISE, KC_H)
#define LWR_U  LT(_LOWER, KC_U)
#define LFT_BK  LT(_LIFT, KC_BSPC)
#define LFT_ENT LT(_LIFT, KC_ENT)

// Macro keys for some apps
#define SLACKUP LALT(LSFT(KC_UP))
#define SLACKDN LALT(LSFT(KC_DOWN))
#define TAB_LFT LGUI(LSFT(KC_LBRC))
#define TAB_RGT LGUI(LSFT(KC_RBRC))
#define BWSR_BK LGUI(KC_LBRC)
#define BWSR_FW LGUI(KC_RBRC)
#define SCR_LFT HYPR(KC_LEFT)
#define SCR_RGT HYPR(KC_RGHT)
#define SCR_FUL HYPR(KC_F)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_WORKMAN] = LAYOUT(
    KC_TAB  , KC_Q    , KC_D    , KC_R    , KC_W    , KC_B    , KC_J    , KC_F    , KC_U    , KC_P    , KC_SCLN , KC_BSPC ,
    KC_LCTL , KC_A    , KC_S    , KC_H    , KC_T    , KC_G    , KC_Y    , KC_N    , KC_E    , KC_O    , KC_I    , KC_QUOT ,
    KC_LGUI , KC_Z    , KC_X    , KC_M    , KC_C    , KC_V    , KC_K    , KC_L    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
    KC_LALT , KC_HYPR , ALT_TAB , XXXXXXX , KC_SPC  , KC_LSFT , MO(_RAISE)  , KC_ENT  , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
  ),
  [_RAISE] = LAYOUT(
    S(KC_SLASH) , KC_EXLM , KC_AT   , KC_LCBR , KC_RCBR     , KC_PIPE , KC_PLUS  , KC_7    , KC_8    , KC_9    , KC_ASTR  , KC_BSPC ,
    KC_AMPR     , KC_HASH , KC_DLR  , KC_LPRN , KC_RPRN     , KC_GRV  , KC_COLON , KC_4    , KC_5    , KC_6    , KC_EQUAL , S(KC_QUOTE),
    KC_TRNS     , KC_PERC , KC_CIRC , KC_LBRC , KC_RBRC     , KC_TILD , KC_MINUS , KC_1    , KC_2    , KC_3    , KC_BSLASH, KC_TRNS ,
    RESET       , OUT_USB , OUT_BT , _______ , S(KC_MINUS) , KC_ESC  , KC_TRNS , KC_CAPS , KC_0    , KC_DOT  , _______  , _______
  ),
};
