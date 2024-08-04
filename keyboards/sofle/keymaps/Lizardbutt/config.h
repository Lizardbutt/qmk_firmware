// Layer states for OLEDs
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_WPM_ENABLE

// OLED Screens
#define MINUTE_TO_MS              6000  // 6 seconds * 1000 milliseconds
#define OLED_SCREENSAVER_TIMEOUT  1 * MINUTE_TO_MS  // 1 minute of no activity to turn on OLED screensaver
#define OLED_TIMEOUT              10 * MINUTE_TO_MS  // 10 minutes of no activity to turn OLED off
#define OLED_BRIGHTNESS           120

// // Flips Encoder CW > CCW ; CCW > CW
// #define ENCODER_DIRECTION_FLIP

// Left Side Encoder
#define ENCODERS_PAD_A      { F5 }
#define ENCODERS_PAD_B      { F4 }
#define ENCODER_RESOLUTIONS { 4 }

// Right Side Encoder
#define ENCODERS_PAD_A_RIGHT      { F4 }
#define ENCODERS_PAD_B_RIGHT      { F5 }
#define ENCODER_RESOLUTIONS_RIGHT { 4 }