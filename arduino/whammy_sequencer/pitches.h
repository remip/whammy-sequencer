typedef struct s_pitch
{
    const char *name;
    byte        prog;
    byte        cc;
} pitch;

const char P_2OCT_name[] PROGMEM    = "2OCT";
const char P_OCT_MA7_name[] PROGMEM = "OCTM7";
const char P_OCT_FL7_name[] PROGMEM = "OCTF7";
const char P_OCT_6TH_name[] PROGMEM = "OCT6";
const char P_OCT_FL6_name[] PROGMEM = "OCTF6";
const char P_OCT_5TH_name[] PROGMEM = "OCT5";
const char P_OCT_FL5_name[] PROGMEM = "OCTF5";
const char P_OCT_4TH_name[] PROGMEM = "OCT4";
const char P_OCT_3RD_name[] PROGMEM = "OCT3";
const char P_OCT_FL3_name[] PROGMEM = "OCTF3";
const char P_OCT_2ND_name[] PROGMEM = "OCT2";
const char P_OCT_FL2_name[] PROGMEM = "OCTF2";

const char P_OCT_name[] PROGMEM   = "OCT";
const char P_MAJ7_name[] PROGMEM  = "MAJ7";
const char P_FLAT7_name[] PROGMEM = "FLAT7";
const char P_6TH_name[] PROGMEM   = "6TH";
const char P_FLAT6_name[] PROGMEM = "FLAT6";
const char P_5TH_name[] PROGMEM   = "5TH";
const char P_FLAT5_name[] PROGMEM = "FLAT5";
const char P_4TH_name[] PROGMEM   = "4TH";
const char P_3RD_name[] PROGMEM   = "3RD";
const char P_FLAT3_name[] PROGMEM = "FLAT3";
const char P_2ND_name[] PROGMEM   = "2ND";
const char P_FLAT2_name[] PROGMEM = "FLAT2";

const char P_UNISON_name[] PROGMEM = "UNISON";

const char P_M_FLAT2_name[] PROGMEM = "-FLAT2";
const char P_M_2ND_name[] PROGMEM   = "-2ND";
const char P_M_FLAT3_name[] PROGMEM = "-FLAT3";
const char P_M_3RD_name[] PROGMEM   = "-3RD";
const char P_M_4TH_name[] PROGMEM   = "-4TH";
const char P_M_FLAT5_name[] PROGMEM = "-FLAT5";
const char P_M_5TH_name[] PROGMEM   = "-5TH";
const char P_M_FLAT6_name[] PROGMEM = "-FLAT6";
const char P_M_6TH_name[] PROGMEM   = "-6TH";
const char P_M_FLAT7_name[] PROGMEM = "-FLAT7";
const char P_M_MAJ7_name[] PROGMEM  = "-MAJ7";

const char P_M_OCT_name[] PROGMEM     = "-OCT";
const char P_M_OCT_FL2_name[] PROGMEM = "-OCTF2";
const char P_M_OCT_2ND_name[] PROGMEM = "-OCT2";
const char P_M_OCT_FL3_name[] PROGMEM = "-OCTF3";
const char P_M_OCT_3RD_name[] PROGMEM = "-OCT3";
const char P_M_OCT_4TH_name[] PROGMEM = "-OCT4";
const char P_M_OCT_FL5_name[] PROGMEM = "-OCTF5";
const char P_M_OCT_5TH_name[] PROGMEM = "-OCT5";
const char P_M_OCT_FL6_name[] PROGMEM = "-OCTF";
const char P_M_OCT_6TH_name[] PROGMEM = "-OCT6";
const char P_M_OCT_FL7_name[] PROGMEM = "-OCTF";
const char P_M_OCT_MA7_name[] PROGMEM = "-OCTM7";
const char P_M_2OCT_name[] PROGMEM    = "-2OCT";

const char DT_SHAL_name[] PROGMEM = "SHALOW";
const char DT_DEEP_name[] PROGMEM = "DEEP";

const char H_OCT_name[] PROGMEM   = "H+OCT";
const char H_MAJ7_name[] PROGMEM  = "H+MAJ7";
const char H_FLAT7_name[] PROGMEM = "H+FLT7";
const char H_6TH_name[] PROGMEM   = "H+6TH";
const char H_FLAT6_name[] PROGMEM = "H+FLT6";
const char H_5TH_name[] PROGMEM   = "H+5TH";
const char H_FLAT5_name[] PROGMEM = "H+FLT5";
const char H_4TH_name[] PROGMEM   = "H+4TH";
const char H_3RD_name[] PROGMEM   = "H+3RD";
const char H_FLAT3_name[] PROGMEM = "H+FLT3";
const char H_2ND_name[] PROGMEM   = "H+2ND";
const char H_FLAT2_name[] PROGMEM = "H+FLT2";

const char H_UNI_name[] PROGMEM = "H UNI";

const char H_M_FLAT2_name[] PROGMEM = "H-FLT2";
const char H_M_2ND_name[] PROGMEM   = "H-2ND";
const char H_M_FLAT3_name[] PROGMEM = "H-FLT3";
const char H_M_3RD_name[] PROGMEM   = "H-3RD";
const char H_M_4TH_name[] PROGMEM   = "H-4TH";
const char H_M_FLAT5_name[] PROGMEM = "H-FLT5";
const char H_M_5TH_name[] PROGMEM   = "H-5TH";
const char H_M_FLAT6_name[] PROGMEM = "H-FLT6";
const char H_M_6TH_name[] PROGMEM   = "H-6TH";
const char H_M_FLAT7_name[] PROGMEM = "H-FLT7";
const char H_M_MAJ7_name[] PROGMEM  = "H-MAJ7";
const char H_M_OCT_name[] PROGMEM   = "H-OCT";

const char BYPASS_name[] PROGMEM = "BYPASS";
const char P_DIVE_NAME[] PROGMEM = "DIVEBB";

const pitch pitches[78] PROGMEM = {
#define P_2OCT 0
    { P_2OCT_name, 0, 127 }, // +2.OCTAVE  two octaves up  +24 half steps
#define P_OCT_MA7 1
    { P_OCT_MA7_name, 0, 122 }, // +OCT+MA7 one octave plus major 7th up  +23 half steps
#define P_OCT_FL7 2
    { P_OCT_FL7_name, 0, 116 }, // +OCT+FL7  one octave plus flat 7th up +22 half steps
#define P_OCT_6TH 3
    { P_OCT_6TH_name, 0, 111 }, // +OCT+6TH  one octave plus 6th up  +21 half steps
#define P_OCT_FL6 4
    { P_OCT_FL6_name, 0, 106 }, // +OCT+FL6  one octave plus flat 6th up +20 half steps
#define P_OCT_5TH 5
    { P_OCT_5TH_name, 0, 101 }, // +OCT+5TH  one octave plus 5th up  +19 half steps
#define P_OCT_FL5 6
    { P_OCT_FL5_name, 0, 95 }, // +OCT+FL5  one octave plus flat 5th up +18 half steps
#define P_OCT_4TH 7
    { P_OCT_4TH_name, 0, 90 }, // +OCT+4TH  one octave plus 4th up  +17 half steps
#define P_OCT_3RD 8
    { P_OCT_3RD_name, 0, 85 }, // +OCT+3RD  one octave plus 3rd up  +16 half steps
#define P_OCT_FL3 9
    { P_OCT_FL3_name, 0, 79 }, // +OCT+FL3  one octave plus flat 3rd up +15 half steps
#define P_OCT_2ND 10
    { P_OCT_2ND_name, 0, 74 }, // +OCT+2ND  one octave plus 2nd up  +14 half steps
#define P_OCT_FL2 11
    { P_OCT_FL2_name, 0, 69 }, // +OCT+FL2  one octave plus flat 2nd up +13 half steps
#define P_OCT 12
    { P_OCT_name, 1, 127 }, // +OCTAVE one octave up +12 half steps
#define P_MAJ7 13
    { P_MAJ7_name, 1, 116 }, // +MAJ 7  major 7th up  +11 half steps
#define P_FLAT7 14
    { P_FLAT7_name, 1, 106 }, // +FLAT 7 flat 7th up +10 half steps
#define P_6TH 15
    { P_6TH_name, 1, 95 }, // +6TH  6th up  +9 half steps
#define P_FLAT6 16
    { P_FLAT6_name, 1, 85 }, // +FLAT 6 flat 6th up +8 half steps
#define P_5TH 17
    { P_5TH_name, 2, 127 }, // +5TH  5th up  +7 half steps
#define P_FLAT5 18
    { P_FLAT5_name, 2, 109 }, // +FLAT 5 flat 5th up +6 half steps
#define P_4TH 19
    { P_4TH_name, 3, 127 }, // +4TH  4th up  +5 half steps
#define P_3RD 20
    { P_3RD_name, 3, 102 }, // +3RD  3rd up  +4 half steps
#define P_FLAT3 21
    { P_FLAT3_name, 3, 76 }, // +FLAT 3 flat 3rd up +3 half steps
#define P_2ND 22
    { P_2ND_name, 3, 51 }, // +2ND  2nd up  +2 half steps
#define P_FLAT2 23
    { P_2ND_name, 3, 25 }, // +FLAT 2 flatted 2nd up  +1 half step
#define P_UNISON 24
    { P_UNISON_name, 3, 0 }, // UNISON  pitch unchanged
#define P_M_FLAT2 25
    { P_M_FLAT2_name, 4, 64 }, // -FLAT 2 flatted 2nd down  -1 half step
#define P_M_2ND 26
    { P_M_2ND_name, 5, 127 }, // -2ND  2nd down  -2 half steps
#define P_M_FLAT3 27
    { P_M_FLAT3_name, 5, 76 }, // -FLAT 3 flat 3rd down -3 half steps
#define P_M_3RD 28
    { P_M_3RD_name, 5, 102 }, // -3RD  3rd down  -4 half steps
#define P_M_4TH 29
    { P_M_4TH_name, 5, 127 }, // -4TH  4th down  -5 half steps
#define P_M_FLAT5 30
    { P_M_FLAT5_name, 6, 109 }, // -FLAT 5 flat 5th down -6 half steps
#define P_M_5TH 31
    { P_M_5TH_name, 6, 127 }, // -5TH  5th down  -7 half steps
#define P_M_FLAT6 32
    { P_M_FLAT6_name, 7, 85 }, // -FLAT 6 flat 6th down -8 half steps
#define P_M_6TH 33
    { P_M_6TH_name, 7, 95 }, // -6TH  6th down  -9 half steps
#define P_M_FLAT7 34
    { P_M_FLAT7_name, 7, 106 }, // -FLAT 7 flat 7th down -10 half steps
#define P_M_MAJ7 35
    { P_M_MAJ7_name, 7, 116 }, // -MAJ 7  major 7th down  -11 half steps
#define P_M_OCT 36
    { P_M_OCT_name, 7, 127 }, // -OCTAVE octave down -12 half steps
#define P_M_OCT_FL2 37
    { P_M_OCT_FL2_name, 8, 69 }, // -OCT-FL2  one octave plus flat 2nd down -13 half steps
#define P_M_OCT_2ND 38
    { P_M_OCT_2ND_name, 8, 74 }, // -OCT-2ND  one octave plus 2nd down  -14 half steps
#define P_M_OCT_FL3 39
    { P_M_OCT_FL3_name, 8, 79 }, // -OCT-FL3  one octave plus flat 3rd down -15 half steps
#define P_M_OCT_3RD 40
    { P_M_OCT_3RD_name, 8, 85 }, // -OCT-3RD  one octave plus 3rd down  -16 half steps
#define P_M_OCT_4TH 41
    { P_M_OCT_4TH_name, 8, 90 }, // -OCT-4TH  one octave plus 4th down  -17 half steps
#define P_M_OCT_FL5 42
    { P_M_OCT_FL5_name, 8, 95 }, // OCT-FL5 one octave plus flat 5th down -18 half steps
#define P_M_OCT_5TH 43
    { P_M_OCT_5TH_name, 8, 101 }, // -OCT-5TH  one octave plus 5th down  -19 half steps
#define P_M_OCT_FL6 44
    { P_M_OCT_FL6_name, 8, 106 }, // -OCT-FL6  one octave plus flat 6th down -20 half steps
#define P_M_OCT_6TH 45
    { P_M_OCT_6TH_name, 8, 111 }, // -OCT-6TH  one octave plus 6th down  -21 half steps
#define P_M_OCT_FL7 46
    { P_M_OCT_FL7_name, 8, 116 }, // -OCT-FL7  one octave plus flat 7th dowm -22 half steps
#define P_M_OCT_MA7 47
    { P_M_OCT_MA7_name, 8, 122 }, // -OCT-MA7  one octave plus major 7th down  -23 half steps
#define P_M_2OCT 48
    { P_M_2OCT_name, 8, 127 }, // -2.OCTAVE two octaves down  -24 half steps

#define DT_SHAL 49
    { DT_SHAL_name, 11, 127 },
#define DT_DEEP 50
    { DT_DEEP_name, 10, 127 },

#define H_OCT 51
    { H_OCT_name, 20, 127 }, // Harmony -OCT + OCT -> +12
#define H_MAJ7 52
    { H_MAJ7_name, 20, 121 }, // Harmony -OCT + OCT -> +11
#define H_FLAT7 53
    { H_FLAT7_name, 20, 116 }, // Harmony -OCT + OCT -> +10
#define H_6TH 54
    { H_6TH_name, 20, 111 }, // Harmony -OCT + OCT -> +9
#define H_FLAT6 55
    { H_FLAT6_name, 20, 105 }, // Harmony -OCT + OCT -> +8
#define H_5TH 56
    { H_5TH_name, 20, 100 }, // Harmony -OCT + OCT -> +7
#define H_FLAT5 57
    { H_FLAT5_name, 20, 95 }, // Harmony -OCT + OCT -> +6
#define H_4TH 58
    { H_4TH_name, 20, 89 }, // Harmony -OCT + OCT -> +5
#define H_3RD 59
    { H_3RD_name, 20, 84 }, // Harmony -OCT + OCT -> +4
#define H_FLAT3 60
    { H_FLAT3_name, 20, 79 }, // Harmony -OCT + OCT -> +3
#define H_2ND 61
    { H_2ND_name, 20, 74 }, // Harmony -OCT + OCT -> +2
#define H_FLAT2 62
    { H_FLAT2_name, 20, 68 }, // Harmony -OCT + OCT -> +1

#define H_UNI 63
    { H_UNI_name, 20, 64 }, // Harmony -OCT + OCT -> 0

#define H_M_FLAT2 64
    { H_M_FLAT2_name, 20, 58 }, // Harmony -OCT + OCT -> -1
#define H_M_2ND 65
    { H_M_2ND_name, 20, 52 }, // Harmony -OCT + OCT -> -2
#define H_M_FLAT3 66
    { H_M_FLAT3_name, 20, 47 }, // Harmony -OCT + OCT -> -3
#define H_M_3RD 67
    { H_M_3RD_name, 20, 42 }, // Harmony -OCT + OCT -> -4
#define H_M_4TH 68
    { H_M_4TH_name, 20, 37 }, // Harmony -OCT + OCT -> -5
#define H_M_FLAT5 69
    { H_M_FLAT5_name, 20, 31 }, // Harmony -OCT + OCT -> -6
#define H_M_5TH 70
    { H_M_5TH_name, 20, 26 }, // Harmony -OCT + OCT -> -7
#define H_M_FLAT6 71
    { H_M_FLAT6_name, 20, 21 }, // Harmony -OCT + OCT -> -8
#define H_M_6TH 72
    { H_M_6TH_name, 20, 15 }, // Harmony -OCT + OCT -> -9
#define H_M_FLAT7 73
    { H_M_FLAT7_name, 20, 10 }, // Harmony -OCT + OCT -> -10
#define H_M_MAJ7 74
    { H_M_MAJ7_name, 20, 5 }, // Harmony -OCT + OCT -> -11
#define H_M_OCT 75
    { H_M_OCT_name, 20, 0 }, // Harmony -OCT + OCT -> -12

#define BYPASS 76
    { BYPASS_name, 22, 0 }, // bypass

#define P_DIVE 77
    { P_DIVE_NAME, 10, 0 } // dive bomn -36
};
