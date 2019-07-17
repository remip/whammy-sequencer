
#define TYPE_SETTINGS 0
#define STR_SETTINGS "SETTINGS"
#define TYPE_1_SHOT 1
#define STR_1_SHOT "1 SHOT"
#define TYPE_1_STEP 2
#define STR_1_STEP "1 STEP"
#define TYPE_2_STEP 3
#define STR_2_STEP "2 STEP"
#define TYPE_TAP 4
#define STR_TAP "TAP"
#define TYPE_CLOCK 5
#define STR_CLOCK "CLOCK"
const char *type_names[6] = { STR_SETTINGS, STR_1_SHOT, STR_1_STEP,
                              STR_2_STEP,   STR_TAP,    STR_CLOCK };

#define MAX_STEP 16

typedef struct s_preset
{
    const char *name;
    byte        steps[MAX_STEP];
    byte        type;
    byte        step_number;
    byte        note_value;
} preset;

/* duration in 1/quarter */
#define NONE 0
#define QUARTER 1
#define EIGHTH 2
#define SIXTEENTH 4
#define THIRTYSECOND 8
#define SIXTYFOURTH 16

#define PRESET_COUNT 19
const preset presets[PRESET_COUNT] = {
    {.name  = "ONTHERUN",
     .steps = { P_UNISON, P_FLAT3, P_FLAT6, P_FLAT3, P_OCT_2ND, P_OCT,
                P_OCT_2ND, P_OCT_3RD },
     // P_M_OCT, P_M_6TH, P_M_3RD, P_M_6TH, P_2ND, P_UNISON, P_2ND, P_3RD
     .type        = TYPE_TAP,
     .step_number = 8,
     .note_value  = SIXTEENTH },
    {.name  = "DOTTED",
     .steps = { P_UNISON, P_UNISON, P_DIVE, P_UNISON, P_M_4TH, P_M_4TH, P_M_OCT,
                P_M_OCT },
     .type        = TYPE_TAP,
     .step_number = 8,
     .note_value  = SIXTEENTH },
    {.name        = "HARMONY",
     .steps       = { H_3RD, H_4TH, H_5TH, H_MAJ7, H_4TH, H_5TH },
     .type        = TYPE_TAP,
     .step_number = 6,
     .note_value  = SIXTEENTH },
    {.name  = "ROLLOVER",
     .steps = { P_M_2OCT, P_M_OCT, P_UNISON, P_OCT, P_2OCT, P_OCT, P_UNISON,
                P_M_OCT },
     .type        = TYPE_TAP,
     .step_number = 8,
     .note_value  = SIXTEENTH },
    {.name        = "SAMU",
     .steps       = { P_5TH, P_UNISON },
     .type        = TYPE_TAP,
     .step_number = 2,
     .note_value  = SIXTEENTH },
    {.name        = "APERIODIC",
     .steps       = { P_2OCT, P_UNISON, P_2OCT, P_2OCT, P_UNISON, P_UNISON },
     .type        = TYPE_TAP,
     .step_number = 6,
     .note_value  = THIRTYSECOND },
    {.name        = "SWING",
     .steps       = { P_UNISON, P_UNISON, P_5TH, P_OCT, P_OCT, P_5TH },
     .type        = TYPE_TAP,
     .step_number = 6,
     .note_value  = SIXTEENTH },
    {.name        = "SLICER",
     .steps       = { H_UNI, H_OCT },
     .type        = TYPE_TAP,
     .step_number = 2,
     .note_value  = SIXTEENTH },
    {.name        = "BEE",
     .steps       = { P_UNISON, P_FLAT2, P_UNISON, P_M_FLAT2 },
     .type        = TYPE_TAP,
     .step_number = 4,
     .note_value  = SIXTEENTH },
    {.name  = "GLASS-1", // https://musescore.com/user/162972/scores/875671
     .steps = { P_UNISON, P_FLAT3, P_5TH, P_OCT, P_5TH, P_FLAT3 },
     .type  = TYPE_TAP,
     .step_number = 6,
     .note_value  = SIXTEENTH },
    {.name        = "ARPEGGIO",
     .steps       = { P_UNISON, P_3RD, P_5TH, P_OCT },
     .type        = TYPE_TAP,
     .step_number = 4,
     .note_value  = SIXTEENTH },
    {.name  = "PROBLMTQ", // Muse map of the problematique
     .steps = { H_M_OCT, H_UNI, H_OCT, H_UNI, H_OCT, H_UNI, H_M_OCT, H_UNI,
                H_OCT, H_UNI, H_OCT, H_UNI, H_M_OCT, H_UNI, H_OCT, H_UNI },
     .type        = TYPE_TAP,
     .step_number = 16,
     .note_value  = SIXTEENTH },
    {.name        = "BLACKSUN", // Easy to riff along with
     .steps       = { P_M_OCT, P_FLAT7, P_M_2ND, P_UNISON },
     .type        = TYPE_2_STEP,
     .step_number = 4,
     .note_value  = NONE },
    {.name  = "SMOKEW", // deep...
     .steps = { P_UNISON, P_FLAT3, P_4TH, P_UNISON, P_FLAT3, P_FLAT5, P_4TH,
                P_UNISON, P_FLAT3, P_4TH, P_FLAT3, P_UNISON },
     .type        = TYPE_1_STEP,
     .step_number = 12,
     .note_value  = NONE },
    {.name =
         "SOLO MOD", // Steps up through pitch intervals for modulating a solo
     .steps = { P_UNISON, P_4TH, P_5TH, P_FLAT7, P_OCT, P_OCT_4TH, P_OCT_5TH,
                P_OCT_FL7, P_2OCT },
     .type        = TYPE_1_STEP,
     .step_number = 9,
     .note_value  = NONE },
    {.name  = "BOMBDROP", // Quick sweeping Dive Bomb down an octave
     .steps = { P_M_FLAT2, P_M_2ND, P_M_FLAT3, P_M_3RD, P_M_4TH, P_M_FLAT5,
                P_M_5TH, P_M_FLAT6, P_M_6TH, P_M_FLAT7, P_M_MAJ7, P_M_OCT },
     .type        = TYPE_1_SHOT,
     .step_number = 12,
     .note_value  = SIXTYFOURTH },
    {.name  = "-LASER-", // Fast 2 Octave Up to Octave Up sweep
     .steps = { P_2OCT, P_OCT_MA7, P_OCT_FL7, P_OCT_6TH, P_OCT_FL6, P_OCT_5TH,
                P_OCT_FL5, P_OCT_4TH, P_OCT_3RD, P_OCT_FL3, P_OCT_2ND,
                P_OCT_FL2, P_OCT },
     .type        = TYPE_1_SHOT,
     .step_number = 13,
     .note_value  = SIXTYFOURTH },
    {.name        = "BACKSLAP", // Funky enchancer riff
     .steps       = { P_2OCT, P_OCT_5TH, P_OCT, P_OCT_FL7 },
     .type        = TYPE_1_SHOT,
     .step_number = 4,
     .note_value  = SIXTEENTH },
    {.name  = "CHORUS", // Toggles the deep detune on and off for chorus effect
     .steps = { DT_SHAL, DT_DEEP },
     .type  = TYPE_SETTINGS,
     .step_number = 2,
     .note_value  = NONE }
};
