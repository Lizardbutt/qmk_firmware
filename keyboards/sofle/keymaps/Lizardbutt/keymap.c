// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

// REMEMBER THAT YOUR KNOB TURNING KEYCODE DEFINITIONS ARE 
// AT THE END OF THE FILE YOU SILLY GOOSE!

// Animation Variables ------------------------------------
// This is used later in the OLED Screensaver
bool oled_screensaver_active = false;
// Frame split time
#define FRAME_DURATION 75
// Animation timer/frames
uint32_t timer = 0;
uint8_t current_frame = 0;
// --------------------------------------------------------

#include QMK_KEYBOARD_H
#include "ivy.h"
#include "triforce.h"

// Current KB Layers and their names
enum sofle_layers {
    _BASE,
    _NUMPAD,
    _ALTNUM,
    _CHARACTERS
};
// Layer Definitions
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base
 * ,-----------------------------------------.                     ,-----------------------------------------.
 * | ESC    | 1   | 2    | 3    | 4    | 5   |                     | 6    | 7    | 8    | 9    | 0    | - _  |
 * |--------+-----+------+------+------+-----|                     |------+------+------+------+------+------|
 * | Tab    | Q   | W    | E    | R    | T   |                     | Y    | U    | I    | O    | P    | \ |  |
 * |--------+-----+------+------+------+-----|                     |------+------+------+------+------+------|
 * | LShift | A   | S    | D    | F    | G   |--------.    ,-------| H    | J    | K    | L    | ; :  | ' "  |
 * |--------+-----+------+------+------+-----| XXXXX  |    | XXXXX |------+------+------+------+------+------|
 * | LCTRL  | Z   | X    | C    | V    | B   |--------|    |-------| N    | M    | = +  | , <  | . >  | / ?  |
 * `-----------------------------------------/       /      \      \-----------------------------------------'
 *         | LGUI | LAlt | MO 1 | Backspc | / Enter /        \ MO 3 \  | Space | MO 2 | MO 3 |      |
 *         |      |      |      |         |/       /          \      \ |       |      |      |      |
 *         '------------------------------''------'            '------''----------------------------'       */
[_BASE] = LAYOUT(
  KC_ESC,  KC_1, KC_2,    KC_3,    KC_4,        KC_5,                                       KC_6,     KC_7,            KC_8,     KC_9,     KC_0,    KC_MINS,
  KC_TAB,  KC_Q, KC_W,    KC_E,    KC_R,        KC_T,                                       KC_Y,     KC_U,            KC_I,     KC_O,     KC_P,    KC_BSLS,
  KC_LSFT, KC_A, KC_S,    KC_D,    KC_F,        KC_G,                                       KC_H,     KC_J,            KC_K,     KC_L,     KC_SCLN, KC_QUOT,
  KC_LCTL, KC_Z, KC_X,    KC_C,    KC_V,        KC_B,         KC_MUTE,    KC_MPLY,          KC_N,     KC_M,            KC_EQUAL, KC_COMMA, KC_DOT,  KC_SLSH,
                 KC_LGUI, KC_LALT, MO(_NUMPAD), KC_BACKSPACE, KC_ENT,     MO(_CHARACTERS),  KC_SPACE, MO(_CHARACTERS), XXXXXXX,  XXXXXXX
),
/* Numpad
 * ,------------------------------------------.                    ,---------------------------------------------.
 * | BKSP | NLOCK | /    | *    | -    |      |                    | F1   | F2    | F3   | F4   | F5    | F6     |
 * |------+-------+------+------+------+------|                    |------+-------+------+------+-------+--------|
 * | PGUP | 7     | 8    | 9    | +    |      |                    | F7   | F8    | F9   | F10  | F11   | F12    |
 * |------+-------+------+------+------+------|                    |------+-------+------+------+-------+--------|
 * | PGDN | 4     | 5    | 6    |      | DEL  |-------.    ,-------| CAPS | CTRL  | ALT  |      |       |        |
 * |------+---- --+------+------+------+------|       |    |       |------+-------+------+------+-------+--------|
 * | HOME | 1     | 2    | 3    |      |      |-------|    |-------|      |       |      |      |       |        |
 * `------------------------------------------/      /      \      \---------------------------------------------'
 *            |  0    | .    |      | PT   | / PT   /        \      \  |      |      |      |      |
 *            |       |      |      |      |/      /          \      \ |      |      |      |      |
 *            '-----------------------------------'            '------''---------------------------'            */   
[_NUMPAD] = LAYOUT(
  KC_BACKSPACE, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX,                       KC_F1,   KC_F2,       KC_F3,   KC_F4,   KC_F5,   KC_F6,
  KC_PGUP,      KC_P7,  KC_P8,   KC_P9,   KC_PPLS, XXXXXXX,                       KC_F7,   KC_F8,       KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_PGDN,      KC_P4,  KC_P5,   KC_P6,   XXXXXXX, KC_DEL,                        KC_CAPS, KC_LCTL,     KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_HOME,      KC_P1,  KC_P2,   KC_P3,   XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        KC_P0,   KC_PDOT, XXXXXXX, KC_TRNS, KC_TRNS,     XXXXXXX, XXXXXXX, MO(_ALTNUM), XXXXXXX, XXXXXXX
),
/* Template layou
 * ,-----------------------------------------.                     ,------------------------------------------.
 * | PT   | PT   | PT   | PT   | PT   |      |                     |      |      |      |       |      |      |
 * |------+------+------+------+------+------|                     |------+------+------+-------+------+------|
 * | PT   | PT   | PT   | PT   | PT   |      |                     |      |      | Up   |       | PGUP |      |
 * |------+------+------+------+------+------|                     |------+------+------+-------+------+------|
 * | PT   | PT   | PT   | PT   |      | PT   |--------.    ,-------| DEL  | Left | Down | Right | PGDN | |    |
 * |------+------+------+------+------+------|        |    |       |------+------+------+-------+------+------|
 * | PT   | PT   | PT   | PT   |      |      |--------|    |-------|      |      |      |       |      |      |
 * `-----------------------------------------/       /      \      \------------------------------------------'
 *            | PT   | PT   | PT   | PT   | / PT    /        \      \  |      |      |      |      |
 *            |      |      |      |      |/       /          \      \ |      |      |      |      |
 *            '---------------------------''------'            '------''---------------------------'        */
[_ALTNUM] = LAYOUT(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX,                       XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,  KC_PGUP, XXXXXXX,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, KC_TRNS,                       KC_DEL,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_PIPE,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
/* Characters
 * ,-----------------------------------------.                     ,------------------------------------------.  
 * |      |      |      | [    | ]    | *    |                     |      |      |      |       |      |      |
 * |------+------+------+------+------+------|                     |------+------+------+-------+------+------|
 * | `    | '    | "    | (    | )    | -    |                     |      |      | Up   |       | PGUP |      |
 * |------+------+------+------+------+------|                     |------+------+------+-------+------+------|
 * | PT   | ~    | $    | {    | }    | +    |--------.    ,-------| DEL  | Left | Down | Right | PGDN | |    |
 * |------+------+------+------+------+------|        |    |       |------+------+------+-------+------+------|
 * | PT   | :    | @    | <    | >    | =    |--------|    |-------|      |      |      |       |      |      |
 * `-----------------------------------------/       /      \      \------------------------------------------'
 *            | PT   | PT   |      | PT   | / PT    /        \      \  |      |      |      | C+A+D |
 *            |      |      |      |      |/       /          \      \ |      |      |      |       |
 *            '-----------------------------------'            '------''----------------------------'         */
[_CHARACTERS] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_ASTR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
  KC_GRV,  KC_QUOT, KC_DQT,  KC_LPRN, KC_RPRN, KC_MINS,                      XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,  KC_PGUP, XXXXXXX,
  KC_TRNS, KC_TILD, KC_DLR,  KC_LCBR, KC_RCBR, KC_PLUS,                      KC_DEL,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_PIPE,
  KC_TRNS, KC_COLN, KC_AT,   KC_LABK, KC_RABK, KC_EQUAL, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
                    KC_TRNS, KC_TRNS, XXXXXXX, KC_TRNS,  KC_TRNS,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C(A(KC_DEL))
)
};
/* Template layout
 * ,-----------------------------------------.                     ,-----------------------------------------.
 * |      |      |      |      |      |      |                     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |--------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|        |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |--------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /      \      \-----------------------------------------'
 *            |      |      |      |      | /       /        \      \  |      |      |      |      |
 *            |      |      |      |      |/       /          \      \ |      |      |      |      |
 *            '---------------------------''------'            '------''---------------------------'        */
/*
[_TEMPLATE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,d
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
*/

// This works, if I want more frames I need to add more, then add them to the array for display
// This orients the non-master hand to display right-side-up
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;  // flips the display 270 degrees if mainhand
    } else {
        oled_clear();
        return OLED_ROTATION_270;  // flips the display 270 degrees if offhand
    }
    return rotation;
}


// This works now, just need a better animation.
bool oled_task_user(void) {
    // If the keyboard is active and screensaver is on, turn the OLED on and clear it once
    if(last_input_activity_elapsed() < OLED_SCREENSAVER_TIMEOUT && oled_screensaver_active == true) {
        oled_screensaver_active = false;
        oled_on();
        oled_clear();
    }
    if(last_input_activity_elapsed() < OLED_SCREENSAVER_TIMEOUT && oled_screensaver_active == false) {
        switch (get_highest_layer(layer_state)) {
            case _BASE :
                oled_write_P("----\nMain\nLayer\n----\n", false);
                break;
            case _NUMPAD :
                oled_write_P("----\nNum\nLayer\n----\n", false);
                break;
            case _ALTNUM :
                oled_write_P("----\nAltNmLayer\n----\n", false);
                break;
            case _CHARACTERS :
                oled_write_P("----\nChar\nLayer\n----\n", false);
                break;
        }
        render_triforce_animation();
    }
    // If the oled is on, but has been idle for longer than the screensaver time, turn the OLED off
    if(is_oled_on() && last_input_activity_elapsed() > OLED_TIMEOUT) {
        oled_clear();
        oled_off();
        oled_screensaver_active = false;
    // If the OLED is on, but has been idle for a while, turn the screensaver on
    } else if(is_oled_on() && last_input_activity_elapsed() > OLED_SCREENSAVER_TIMEOUT) {
        oled_screensaver_active = true;
    }
    // If idle, render the animation.
    if (oled_screensaver_active) {
        // Use some render animation
        render_ivy_animation();
        return false;
    }
    return false;
}

// This is squared away and working correctly.
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    // This is so ass backwards, it's fucking stupid.
    // clockwise is technically counter clockwise, I'm too lazy to inverse it.
    switch (get_highest_layer(layer_state)) {
        case _BASE :
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_VOLD);
                } else {
                    tap_code(KC_VOLU);
                }
            } else if (index == 1) {
                if (clockwise) {
                    tap_code(KC_MPRV);
                } else {
                    tap_code(KC_MNXT);
                }
            }
            break;
        case _NUMPAD :
            break;
        case _ALTNUM :
            break;
        case _CHARACTERS :
            break;
    }
    return true;
}
