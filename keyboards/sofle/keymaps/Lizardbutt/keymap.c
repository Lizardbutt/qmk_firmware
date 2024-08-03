// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    _BASE,
    _NUMPAD,
    _CHARACTERS
};

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
  KC_LCTL, KC_Z, KC_X,    KC_C,    KC_V,        KC_B,         XXXXXXX,    XXXXXXX,          KC_N,     KC_M,            KC_EQUAL, KC_COMMA, KC_DOT,  KC_SLSH,
                 KC_LGUI, KC_LALT, MO(_NUMPAD), KC_BACKSPACE, KC_ENT,     MO(_CHARACTERS),  KC_SPACE, MO(_CHARACTERS), XXXXXXX,  XXXXXXX
),
/* NUMPAD / Blender common keys
 * ,------------------------------------------.                    ,---------------------------------------------.
 * | BKSP | NLOCK | /    | *    | -    |      |                    | F1   | F2    | F3   | F4   | F5    | F6     |
 * |------+-------+------+------+------+------|                    |------+-------+------+------+-------+--------|
 * | PGUP | 7     | 8    | 9    | +    |      |                    | F7   | F8    | F9   | F10  | F11   | F12    |
 * |------+-------+------+------+------+------|                    |------+-------+------+------+-------+--------|
 * | PGDN | 4     | 5    | 6    |      |      |-------.    ,-------| CAPS |       |      |      |       |        |
 * |------+---- --+------+------+------+------|       |    |       |------+-------+------+------+-------+--------|
 * | HOME | 1     | 2    | 3    |      |      |-------|    |-------|      |       |      |      |       |        |
 * `------------------------------------------/      /      \      \---------------------------------------------'
 *            |  0    | .    |      | PT   | / PT   /        \      \  |      |      |      |      |
 *            |       |      |      |      |/      /          \      \ |      |      |      |      |
 *            '-----------------------------------'            '------''---------------------------'            */   
[_NUMPAD] = LAYOUT(
  KC_BACKSPACE, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX,                       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
  KC_PGUP,      KC_P7,  KC_P8,   KC_P9,   KC_PPLS, XXXXXXX,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_PGDN,      KC_P4,  KC_P5,   KC_P6,   XXXXXXX, XXXXXXX,                       KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_HOME,      KC_P1,  KC_P2,   KC_P3,   XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        KC_P0,   KC_PDOT, XXXXXXX, KC_TRNS, KC_TRNS,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
/* Function
 * ,-----------------------------------------.                     ,------------------------------------------.
 * |      |      |      | [    | ]    | *    |                     |      |      | PP   | PT    | NT   | Mute |
 * |------+------+------+------+------+------|                     |------+------+------+-------+------+------|
 * | `    | '    | "    | (    | )    | -    |                     |      |      | Up   |       | PGUP | VU   |
 * |------+------+------+------+------+------|                     |------+------+------+-------+------+------|
 * | |    | ~    | $    | {    | }    | +    |--------.    ,-------|      | Left | Down | Right | PGDN | VD   |
 * |------+------+------+------+------+------|        |    |       |------+------+------+-------+------+------|
 * |      | :    | @    | <    | >    | =    |--------|    |-------|      |      |      |       |      |      |
 * `-----------------------------------------/       /      \      \------------------------------------------'
 *            |      |      |      | PT   | / PT    /        \      \  |      |      |      | C+A+D |
 *            |      |      |      |      |/       /          \      \ |      |      |      |       |
 *            '-----------------------------------'            '------''----------------------------'         */
[_CHARACTERS] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_ASTR,                      XXXXXXX, XXXXXXX, KC_MPLY, KC_MPRV,  KC_MNXT, KC_MUTE,
  KC_GRV,  KC_QUOT, KC_DQT,  KC_LPRN, KC_RPRN, KC_MINS,                      XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,  KC_PGUP, KC_VOLU,
  KC_PIPE, KC_TILD, KC_DLR,  KC_LCBR, KC_RCBR, KC_PLUS,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_VOLD,
  XXXXXXX, KC_COLN, KC_AT,   KC_LABK, KC_RABK, KC_EQUAL, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_WSCH,
                    XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,  KC_TRNS,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C(A(KC_DEL))
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
[_FUNCTION] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,d
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
*/  

// Code stuff

// Layer states. Do custom fun shit here
bool oled_task_user() {
    oled_advance_page(true);
    switch (get_highest_layer(layer_state)) {
        case _BASE :
            oled_clear();
            oled_write("Main\nLayer", false);
            break;
        case _NUMPAD : 
            oled_clear();
            oled_write("Num\nLayer", false);
            break;
        case _CHARACTERS :
            oled_clear();
            oled_write("Char\nLayer", false);
            break;
        }
    return false;
}

// This orients the non-master hand to display right-side-up
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        oled_clear();
        return OLED_ROTATION_270;  // flips the display 270 degrees if offhand
    }
    return rotation;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_KB_VOLUME_UP);
        } else {
            tap_code(KC_KB_VOLUME_DOWN);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif