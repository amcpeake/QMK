#include QMK_KEYBOARD_H
#include "config.h"
#include <print.h>

// SPECIAL KEY MAPPINGS:
enum ctrl_keycodes {
	L_BRI = SAFE_RANGE, //LED Brightness Increase
	L_BRD,              //LED Brightness Decrease
	L_PTN,              //LED Pattern Select Next
	L_PTP,              //LED Pattern Select Previous
	L_PSI,              //LED Pattern Speed Increase
	L_PSD,              //LED Pattern Speed Decrease
	L_T_MD,             //LED Toggle Mode
	L_T_ONF,            //LED Toggle On / Off
	L_ON,               //LED On
	L_OFF,              //LED Off
	L_T_BR,             //LED Toggle Breath Effect
	L_T_PTD,            //LED Toggle Scrolling Pattern Direction
	U_T_AUTO,           //USB Extra Port Toggle Auto Detect / Always Active
	U_T_AGCR,           //USB Toggle Automatic GCR control
	DBG_TOG,            //DEBUG Toggle On / Off
	DBG_MTRX,           //DEBUG Toggle Matrix Prints
	DBG_KBD,            //DEBUG Toggle Keyboard Prints
	DBG_MOU,            //DEBUG Toggle Mouse Prints
	MD_BOOT,            //Restart into bootloader after hold timeout
	DYNAMIC_MACRO_RANGE,//Allows dynamic macros
};

#include "dynamic_macro.h"


// RENAMING
#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode
#define DM_STRT DYN_REC_START1
#define DM_STOP DYN_REC_STOP
#define DM_PLAY DYN_MACRO_PLAY1
#define QWR 0
#define CMK 1
#define MSE 4
#define EMJ 5

// EMOJI MAPPINGS:
enum unicode_names {
	NUM0,
	NUM1,
	NUM2,
	NUM3,
	NUM4,
	NUM5,
	NUM6,
	NUM7,
	NUM8,
	NUM9,
	QSTN,
	WINK,
	EYES,
	RLTY,
	TRMK,
	YHRT,
	UNAM,
	INFO,
	OKAY,
	PRAY,
	ANGR,
	SNEK,
	DEVL,
	FIRE,
	GRIN,
	HOGF,
	JKOL,
	KISS,
	LOCK,
	ZZZZ,
	XMRK,
	COOL,
	VCTR,
	BABY,
	NOSE,
	MOTH,
};

const uint32_t PROGMEM unicode_map[] = {
	[NUM0] = 0x00030,       // 0 0⃣
        [NUM1] = 0x00031,       // 1 1⃣
        [NUM2] = 0x00032,       // 2 2⃣
        [NUM3] = 0x00033,       // 3 3⃣
        [NUM4] = 0x00034,       // 4 4⃣
        [NUM5] = 0x00035,       // 5 5⃣
        [NUM6] = 0x00036,       // 6 6⃣
        [NUM7] = 0x00037,       // 7 7⃣
        [NUM8] = 0x00038,       // 8 8⃣
        [NUM9] = 0x00039,       // 9 9⃣
	[QSTN] = 0x02753,	// Q ❓
	[WINK] = 0x1F609,	// W 😉
	[EYES] = 0x1F440,	// E 👀
	[RLTY] = 0x000AE,	// R ®
	[TRMK] = 0x02122,	// T ™
	[YHRT] = 0x1F49B,	// Y 💛
	[UNAM] = 0x1F612,	// U 😒
	[INFO] = 0x02139,	// I ℹ
	[OKAY] = 0x1F197,	// O 🆗
	[PRAY] = 0x1F64F,	// P 🙏
	[ANGR] = 0x1F621,	// A 😠
	[SNEK] = 0x1F40D,	// S 🐍
	[DEVL] = 0x1F608,	// D 😈
	[FIRE] = 0x1F525,	// F 🔥
	[GRIN] = 0x1F601,	// G 😁
        [HOGF] = 0x1F437,       // H 🐷
	[JKOL] = 0x1F383,	// J 🎃
	[KISS] = 0x1F618,	// K 😘
	[LOCK] = 0x1F512,	// L 🔒
	[ZZZZ] = 0x1F4A4,	// Z 💤
	[XMRK] = 0x0274C,	// X ❌
        [COOL] = 0x1F60E,       // C 😎
	[VCTR] = 0x0270C,	// V ✌
	[BABY] = 0x1F476,	// B 👶
	[NOSE] = 0x1F443, 	// N 👃
	[MOTH] = 0x1F445,	// M 👅
};

// TAP DANCE
qk_tap_dance_action_t tap_dance_actions[] = {
};

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// QWERTY:
[0] = LAYOUT(
	KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             	KC_PSCR,  KC_SLCK,  KC_PAUS,  \
	KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,   	KC_INS,   KC_HOME,  KC_PGUP,  \
	LT(2, KC_TAB),KC_Q, KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,   	KC_DEL,   KC_END,   KC_PGDN,  \
	KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,                                     \
	KC_LSPO,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSPC,             	                  KC_UP,              \
	KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,                                 KC_RALT,  MO(3),    DM_PLAY,  KC_RCTL,                KC_LEFT,  KC_DOWN,  KC_RGHT   \
),

// COLEMAK:
[1] = LAYOUT(
	KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             	KC_PSCR,  KC_SLCK,  KC_PAUS,  \
	KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,   	KC_INS,   KC_HOME,  KC_PGUP,  \
	KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_LBRC,  KC_RBRC,  KC_BSLS,   	KC_DEL,   KC_END,   KC_PGDN,  \
	KC_BSPC,  KC_A,     KC_R,     KC_S,     KC_T,     KC_D,     KC_H,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,            KC_ENT,                                     \
	KC_LSPO,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                      KC_RSPC,	 	  KC_UP,              \
	KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,                                 KC_RALT,  MO(3),    DM_PLAY,  KC_RCTL,            	KC_LEFT,  KC_DOWN,  KC_RGHT   \
),
// HOTKEYS, MEDIA CONTROL, ETC
[2] = LAYOUT(
        DF(QWR),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                KC_TRNS,  KC_TRNS,  KC_TRNS,  \
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_MUTE,  KC_VOLU,  KC_MPLY,  \
        KC_TRNS,  KC_BTN1,  KC_TRNS,  KC_BTN2,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_MPRV,  KC_VOLD,  KC_MNXT,  \
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_TRNS,  KC_TRNS,  KC_TRNS,                                              \
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                                    KC_WREF,            \
        KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_ENT,                                 DM_STRT,  DM_STOP,  KC_TRNS,  KC_TRNS,                KC_WBAK,  KC_WSCH,  KC_WFWD   \
),
// KEYBOARD CONTROL
[3] = LAYOUT(
	RESET,    DF(QWR),  DF(CMK),  DF(MSE),  DF(EMJ),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            	KC_TRNS,  KC_TRNS,  KC_TRNS,  \
	KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   	KC_TRNS,  KC_TRNS,  KC_TRNS,  \
	KC_TRNS,  L_PSD,    L_BRI,    L_PSI,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   	KC_TRNS,  KC_TRNS,  KC_TRNS,  \
	KC_TRNS,  L_PTP,    L_BRD,    L_PTN,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                                              \
	KC_ASTG,  L_T_MD,   L_T_BR,   L_T_PTD,  KC_TRNS,  KC_TRNS,  TG_NKRO,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                             	  KC_TRNS,            \
	KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            	KC_TRNS,  KC_TRNS,  KC_TRNS   \
),

// MOUSE EMULATION:
[4] = LAYOUT(
	DF(QWR),    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             	KC_TRNS,  KC_TRNS,  KC_TRNS,  \
	KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   	KC_TRNS,  KC_TRNS,  KC_TRNS,  \
	KC_TRNS,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   	KC_TRNS,  KC_TRNS,  KC_TRNS,  \
	KC_TRNS,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                                              \
	KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                                 	  KC_WH_U,            \
	KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_BTN3,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             	KC_WH_L,  KC_WH_D,  KC_WH_R   \
),

// EMOJI KEYBOARD:
[5] = LAYOUT(
        DF(0),    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                KC_TRNS,  KC_TRNS,  KC_TRNS,  \
        KC_TRNS,  X(NUM1),  X(NUM2),  X(NUM3),  X(NUM4),  X(NUM5),  X(NUM6),  X(NUM7),  X(NUM8),  X(NUM9),  X(NUM0),  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  \
        KC_TRNS,  X(QSTN),  X(WINK),  X(EYES),  X(RLTY),  X(TRMK),  X(YHRT),  X(UNAM),  X(INFO),  X(OKAY),  X(PRAY),  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  \
        KC_TRNS,  X(ANGR),  X(SNEK),  X(DEVL),  X(FIRE),  X(GRIN),  X(HOGF),  X(JKOL),  X(KISS),  X(LOCK),  KC_TRNS,  KC_TRNS,  KC_TRNS,                                              \
        KC_TRNS,  X(ZZZZ),  X(XMRK),  X(COOL),  X(VCTR),  X(BABY),  X(NOSE),  X(MOTH),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                                    KC_TRNS,            \
        UC_M_WI,  KC_TRNS,  KC_TRNS,                      KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  UC_M_LN,                KC_TRNS,  KC_TRNS,  KC_TRNS   \
),

/* TEMPLATE:
[X] = LAYOUT(
	KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             	KC_TRNS,  KC_TRNS,  KC_TRNS,  \
	KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   	KC_TRNS,  KC_TRNS,  KC_TRNS,  \
	KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   	KC_TRNS,  KC_TRNS,  KC_TRNS,  \
	KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                                              \
	KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                                 	  KC_TRNS,            \
	KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             	KC_TRNS,  KC_TRNS,  KC_TRNS   \
),
*/
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

void eeconfig_init_user(void) {
  set_unicode_input_mode(UC_LNX);
}

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }

    if (keycode >= 20992 && keycode <= 21247){ // Set lighting on layer change
	led_animation_id = keycode - 20992;
    }

    switch (keycode) {
        case L_BRI:
            if (record->event.pressed) {
                if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) gcr_desired = LED_GCR_MAX;
                else gcr_desired += LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_BRD:
            if (record->event.pressed) {
                if (LED_GCR_STEP > gcr_desired) gcr_desired = 0;
                else gcr_desired -= LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_PTN:
            if (record->event.pressed) {
                if (led_animation_id == led_setups_count - 1) led_animation_id = 0;
                else led_animation_id++;
            }
            return false;
        case L_PTP:
            if (record->event.pressed) {
                if (led_animation_id == 0) led_animation_id = led_setups_count - 1;
                else led_animation_id--;
            }
            return false;
        case L_PSI:
            if (record->event.pressed) {
                led_animation_speed += ANIMATION_SPEED_STEP;
            }
            return false;
        case L_PSD:
            if (record->event.pressed) {
                led_animation_speed -= ANIMATION_SPEED_STEP;
                if (led_animation_speed < 0) led_animation_speed = 0;
            }
            return false;
        case L_T_MD:
            if (record->event.pressed) {
                led_lighting_mode++;
                if (led_lighting_mode > LED_MODE_MAX_INDEX) led_lighting_mode = LED_MODE_NORMAL;
            }
            return false;
        case L_T_ONF:
            if (record->event.pressed) {
                led_enabled = !led_enabled;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_ON:
            if (record->event.pressed) {
                led_enabled = 1;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_OFF:
            if (record->event.pressed) {
                led_enabled = 0;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_T_BR:
            if (record->event.pressed) {
                led_animation_breathing = !led_animation_breathing;
                if (led_animation_breathing) {
                    gcr_breathe = gcr_desired;
                    led_animation_breathe_cur = BREATHE_MIN_STEP;
                    breathe_dir = 1;
                }
            }
            return false;
        case L_T_PTD:
            if (record->event.pressed) {
                led_animation_direction = !led_animation_direction;
            }
            return false;
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
