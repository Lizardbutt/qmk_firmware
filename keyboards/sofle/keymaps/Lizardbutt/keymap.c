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
  KC_LCTL, KC_Z, KC_X,    KC_C,    KC_V,        KC_B,         KC_MUTE,    KC_MPLY,          KC_N,     KC_M,            KC_EQUAL, KC_COMMA, KC_DOT,  KC_SLSH,
                 KC_LGUI, KC_LALT, MO(_NUMPAD), KC_BACKSPACE, KC_ENT,     MO(_CHARACTERS),  KC_SPACE, MO(_CHARACTERS), XXXXXXX,  XXXXXXX
),
/* NUMPAD / Blender common keys
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
  KC_BACKSPACE, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX,                       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
  KC_PGUP,      KC_P7,  KC_P8,   KC_P9,   KC_PPLS, XXXXXXX,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_PGDN,      KC_P4,  KC_P5,   KC_P6,   XXXXXXX, KC_DEL,                        KC_CAPS, KC_LCTL, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_HOME,      KC_P1,  KC_P2,   KC_P3,   XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        KC_P0,   KC_PDOT, XXXXXXX, KC_TRNS, KC_TRNS,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
/* Function
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
[_FUNCTION] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,d
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
*/  

// Code stuff

// How long each frame lasts in milliseconds
#define FRAME_DURATION 333 
// Animation timer/frames
uint32_t timer = 0;
uint8_t current_frame = 0;
// Screen saver must always be inactive
bool oled_screensaver_active = false;

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

static void render_animation(void) {
    // Frame 1
    static const char PROGMEM epd_bitmap_frame_0_delay_0[] = {
        0x00, 0x00, 0x00, 0xc1, 0x02, 0x00, 0xfe, 0x02, 0xfe, 0x02, 0x02, 0x0a, 0x02, 0x62, 0x62, 0x02, 
        0x0a, 0x02, 0x02, 0xfe, 0x00, 0x02, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xff, 0x02, 0xff, 0x03, 0x13, 0x3b, 0x13, 0x03, 0x07, 0x57, 
        0x07, 0x23, 0x03, 0xff, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x0b, 0x05, 0x01, 0x01, 0x01, 
        0x0b, 0x05, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    };
    // Frame 2
    static const char PROGMEM epd_bitmap_frame_1_delay_0[] = {
        0x00, 0x00, 0x00, 0x80, 0x05, 0x00, 0xfd, 0x04, 0xfc, 0x04, 0x04, 0x14, 0x04, 0xc4, 0xc4, 0x04, 
        0x14, 0x04, 0x04, 0xfc, 0x01, 0x00, 0x85, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0xff, 0x04, 0xff, 0x06, 0x26, 0x76, 0x26, 0x06, 0x0e, 0xae, 
        0x0e, 0x46, 0x06, 0xff, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x03, 0x02, 0x02, 0x16, 0x0a, 0x02, 0x02, 0x02, 
        0x16, 0x0a, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    // Animation Frames Array
    const char* epd_bitmap_allArray[2] = {
        epd_bitmap_frame_0_delay_0,
        epd_bitmap_frame_1_delay_0
    };
    uint16_t frame_sizes[2] = {
        sizeof(epd_bitmap_frame_0_delay_0),
        sizeof(epd_bitmap_frame_1_delay_0)
    };
    if (timer_elapsed(timer) > FRAME_DURATION) {
        // Set timer to updated time
        timer = timer_read();

        // Increment frame
        current_frame = (current_frame + 1) % (sizeof(epd_bitmap_allArray) / sizeof(epd_bitmap_allArray[0]));

        // Draw to OLED
        oled_write_raw_P(epd_bitmap_allArray[current_frame], frame_sizes[current_frame]);
    }
}

// This works now, just need a better animation.
bool oled_task_user(void) {
    if(last_input_activity_elapsed() < OLED_SCREENSAVER_TIMEOUT) {
        oled_on();
        oled_screensaver_active = false;
    }
    if(is_oled_on() && last_input_activity_elapsed() > OLED_SCREENSAVER_TIMEOUT) {
        oled_screensaver_active = true;
    }
    if(is_oled_on() && last_input_activity_elapsed() > OLED_TIMEOUT) {
        oled_clear();
        oled_off();
        oled_screensaver_active = false;
    }
    // If idle, render the animation.
    if (oled_screensaver_active) {
        // Call the Rendering function from above this bool function
        render_animation();
        return false;
    }
    // This works correctly when selecting layers
    // Layer states should be added here as more layers are added
    switch (get_highest_layer(layer_state)) {
        case _BASE :
            // Clearing the OLED to omit anything previously
            oled_clear();
            // Writing the PAGE, oled_write() should write below this.
            oled_write_P("----\nMain\nLayer\n----", false);
            break;
        case _NUMPAD : 
            oled_clear();
            oled_write_P("----\nNum\nLayer\n----", false);
            break;
        case _CHARACTERS :
            oled_clear();
            oled_write_P("----\nChar\nLayer\n----", false);
            break;
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
    return true;
}
