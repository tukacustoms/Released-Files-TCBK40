#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT( 
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSPC, 
        KC_TAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,  
        KC_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,  KC_SLASH,  KC_LGUI, KC_RALT, 
        KC_LCTL, MO(1), KC_LSFT, KC_SPC,   MO(2),   KC_RCTL  
    ),

    [1] = LAYOUT(  
        KC_ESC,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,  KC_DEL, 
        KC_PSCR, KC_LPRN, KC_RPRN, _______, _______, _______, _______, KC_MINS, KC_LBRC, KC_RBRC, KC_EQUAL, 
        _______, KC_RGUI, _______, KC_SLCT, KC_PAUS, KC_INS,  KC_HOME, KC_DOT,  KC_COMM, KC_UNDS, _______, 
        _______, _______, _______, _______, _______, _______   
    ),

    [2] = LAYOUT(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,  
        RGB_MOD, KC_MPRV, KC_MNXT, RGB_MODE_RGBTEST, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_PGDN, QK_BOOT, 
        RGB_TOG, RGB_M_R, RGB_M_P, RGB_M_SW, RGB_M_TW, RGB_SAD, RGB_HUI,RGB_HUD, _______, RGB_VAI, RGB_VAD, 
        _______, _______, _______, _______, _______, _______  
    ),

};


