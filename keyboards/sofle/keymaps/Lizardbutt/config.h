// Layer states for OLEDs
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_WPM_ENABLE

// OLED Screens
#define MINUTE_TO_MS              10000  // 10 seconds
#define OLED_SCREENSAVER_TIMEOUT  1 * MINUTE_TO_MS  // 10 Seconds of no activity, turn on the screensaver
#define OLED_TIMEOUT              10 * MINUTE_TO_MS  // 100 Seconds of no activity, turn off the OLED
#define OLED_BRIGHTNESS           120

// Left Side Encoder
#define ENCODERS_PAD_A      { F5 }
#define ENCODERS_PAD_B      { F4 }
#define ENCODER_RESOLUTIONS { 4 }

// Right Side Encoder
#define ENCODERS_PAD_A_RIGHT      { F4 }
#define ENCODERS_PAD_B_RIGHT      { F5 }
#define ENCODER_RESOLUTIONS_RIGHT { 4 }