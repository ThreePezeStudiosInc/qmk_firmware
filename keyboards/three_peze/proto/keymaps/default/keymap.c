// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ Q │ W │ E │
     * ├───┼───┼───┤
     * │ A │ S │ D │
     * └───┴───┴───┘
     */
    [0] = LAYOUT_ortho_2x3(
        KC_Q,    KC_W,    KC_E,
        KC_A,    KC_S,    KC_D
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
    return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise)
{
    if (!encoder_update_user(index, clockwise))
    {
        return false;
    }

    if (index == 0)
    { /* First encoder */
        if (clockwise)
        {
            tap_code(KC_VOLU);
        }
        else
        {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1)
    { /* Second encoder */
        if (clockwise)
        {
            tap_code(KC_MNXT);
        }
        else
        {
            tap_code(KC_MPRV);
        }
    }
    return true;
}
#endif
