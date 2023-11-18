#include "gnss.h"

namespace {
#define DIM 11
#define EDIM 11
#define MEDIM 11
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_6 = 3.8414588206941227;
const static double MAHA_THRESH_20 = 3.8414588206941227;
const static double MAHA_THRESH_7 = 3.8414588206941227;
const static double MAHA_THRESH_21 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_3974798752012907017) {
   out_3974798752012907017[0] = delta_x[0] + nom_x[0];
   out_3974798752012907017[1] = delta_x[1] + nom_x[1];
   out_3974798752012907017[2] = delta_x[2] + nom_x[2];
   out_3974798752012907017[3] = delta_x[3] + nom_x[3];
   out_3974798752012907017[4] = delta_x[4] + nom_x[4];
   out_3974798752012907017[5] = delta_x[5] + nom_x[5];
   out_3974798752012907017[6] = delta_x[6] + nom_x[6];
   out_3974798752012907017[7] = delta_x[7] + nom_x[7];
   out_3974798752012907017[8] = delta_x[8] + nom_x[8];
   out_3974798752012907017[9] = delta_x[9] + nom_x[9];
   out_3974798752012907017[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3775286048623570569) {
   out_3775286048623570569[0] = -nom_x[0] + true_x[0];
   out_3775286048623570569[1] = -nom_x[1] + true_x[1];
   out_3775286048623570569[2] = -nom_x[2] + true_x[2];
   out_3775286048623570569[3] = -nom_x[3] + true_x[3];
   out_3775286048623570569[4] = -nom_x[4] + true_x[4];
   out_3775286048623570569[5] = -nom_x[5] + true_x[5];
   out_3775286048623570569[6] = -nom_x[6] + true_x[6];
   out_3775286048623570569[7] = -nom_x[7] + true_x[7];
   out_3775286048623570569[8] = -nom_x[8] + true_x[8];
   out_3775286048623570569[9] = -nom_x[9] + true_x[9];
   out_3775286048623570569[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_2767523228344983263) {
   out_2767523228344983263[0] = 1.0;
   out_2767523228344983263[1] = 0;
   out_2767523228344983263[2] = 0;
   out_2767523228344983263[3] = 0;
   out_2767523228344983263[4] = 0;
   out_2767523228344983263[5] = 0;
   out_2767523228344983263[6] = 0;
   out_2767523228344983263[7] = 0;
   out_2767523228344983263[8] = 0;
   out_2767523228344983263[9] = 0;
   out_2767523228344983263[10] = 0;
   out_2767523228344983263[11] = 0;
   out_2767523228344983263[12] = 1.0;
   out_2767523228344983263[13] = 0;
   out_2767523228344983263[14] = 0;
   out_2767523228344983263[15] = 0;
   out_2767523228344983263[16] = 0;
   out_2767523228344983263[17] = 0;
   out_2767523228344983263[18] = 0;
   out_2767523228344983263[19] = 0;
   out_2767523228344983263[20] = 0;
   out_2767523228344983263[21] = 0;
   out_2767523228344983263[22] = 0;
   out_2767523228344983263[23] = 0;
   out_2767523228344983263[24] = 1.0;
   out_2767523228344983263[25] = 0;
   out_2767523228344983263[26] = 0;
   out_2767523228344983263[27] = 0;
   out_2767523228344983263[28] = 0;
   out_2767523228344983263[29] = 0;
   out_2767523228344983263[30] = 0;
   out_2767523228344983263[31] = 0;
   out_2767523228344983263[32] = 0;
   out_2767523228344983263[33] = 0;
   out_2767523228344983263[34] = 0;
   out_2767523228344983263[35] = 0;
   out_2767523228344983263[36] = 1.0;
   out_2767523228344983263[37] = 0;
   out_2767523228344983263[38] = 0;
   out_2767523228344983263[39] = 0;
   out_2767523228344983263[40] = 0;
   out_2767523228344983263[41] = 0;
   out_2767523228344983263[42] = 0;
   out_2767523228344983263[43] = 0;
   out_2767523228344983263[44] = 0;
   out_2767523228344983263[45] = 0;
   out_2767523228344983263[46] = 0;
   out_2767523228344983263[47] = 0;
   out_2767523228344983263[48] = 1.0;
   out_2767523228344983263[49] = 0;
   out_2767523228344983263[50] = 0;
   out_2767523228344983263[51] = 0;
   out_2767523228344983263[52] = 0;
   out_2767523228344983263[53] = 0;
   out_2767523228344983263[54] = 0;
   out_2767523228344983263[55] = 0;
   out_2767523228344983263[56] = 0;
   out_2767523228344983263[57] = 0;
   out_2767523228344983263[58] = 0;
   out_2767523228344983263[59] = 0;
   out_2767523228344983263[60] = 1.0;
   out_2767523228344983263[61] = 0;
   out_2767523228344983263[62] = 0;
   out_2767523228344983263[63] = 0;
   out_2767523228344983263[64] = 0;
   out_2767523228344983263[65] = 0;
   out_2767523228344983263[66] = 0;
   out_2767523228344983263[67] = 0;
   out_2767523228344983263[68] = 0;
   out_2767523228344983263[69] = 0;
   out_2767523228344983263[70] = 0;
   out_2767523228344983263[71] = 0;
   out_2767523228344983263[72] = 1.0;
   out_2767523228344983263[73] = 0;
   out_2767523228344983263[74] = 0;
   out_2767523228344983263[75] = 0;
   out_2767523228344983263[76] = 0;
   out_2767523228344983263[77] = 0;
   out_2767523228344983263[78] = 0;
   out_2767523228344983263[79] = 0;
   out_2767523228344983263[80] = 0;
   out_2767523228344983263[81] = 0;
   out_2767523228344983263[82] = 0;
   out_2767523228344983263[83] = 0;
   out_2767523228344983263[84] = 1.0;
   out_2767523228344983263[85] = 0;
   out_2767523228344983263[86] = 0;
   out_2767523228344983263[87] = 0;
   out_2767523228344983263[88] = 0;
   out_2767523228344983263[89] = 0;
   out_2767523228344983263[90] = 0;
   out_2767523228344983263[91] = 0;
   out_2767523228344983263[92] = 0;
   out_2767523228344983263[93] = 0;
   out_2767523228344983263[94] = 0;
   out_2767523228344983263[95] = 0;
   out_2767523228344983263[96] = 1.0;
   out_2767523228344983263[97] = 0;
   out_2767523228344983263[98] = 0;
   out_2767523228344983263[99] = 0;
   out_2767523228344983263[100] = 0;
   out_2767523228344983263[101] = 0;
   out_2767523228344983263[102] = 0;
   out_2767523228344983263[103] = 0;
   out_2767523228344983263[104] = 0;
   out_2767523228344983263[105] = 0;
   out_2767523228344983263[106] = 0;
   out_2767523228344983263[107] = 0;
   out_2767523228344983263[108] = 1.0;
   out_2767523228344983263[109] = 0;
   out_2767523228344983263[110] = 0;
   out_2767523228344983263[111] = 0;
   out_2767523228344983263[112] = 0;
   out_2767523228344983263[113] = 0;
   out_2767523228344983263[114] = 0;
   out_2767523228344983263[115] = 0;
   out_2767523228344983263[116] = 0;
   out_2767523228344983263[117] = 0;
   out_2767523228344983263[118] = 0;
   out_2767523228344983263[119] = 0;
   out_2767523228344983263[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_7917251045724789548) {
   out_7917251045724789548[0] = dt*state[3] + state[0];
   out_7917251045724789548[1] = dt*state[4] + state[1];
   out_7917251045724789548[2] = dt*state[5] + state[2];
   out_7917251045724789548[3] = state[3];
   out_7917251045724789548[4] = state[4];
   out_7917251045724789548[5] = state[5];
   out_7917251045724789548[6] = dt*state[7] + state[6];
   out_7917251045724789548[7] = dt*state[8] + state[7];
   out_7917251045724789548[8] = state[8];
   out_7917251045724789548[9] = state[9];
   out_7917251045724789548[10] = state[10];
}
void F_fun(double *state, double dt, double *out_8573431280396982104) {
   out_8573431280396982104[0] = 1;
   out_8573431280396982104[1] = 0;
   out_8573431280396982104[2] = 0;
   out_8573431280396982104[3] = dt;
   out_8573431280396982104[4] = 0;
   out_8573431280396982104[5] = 0;
   out_8573431280396982104[6] = 0;
   out_8573431280396982104[7] = 0;
   out_8573431280396982104[8] = 0;
   out_8573431280396982104[9] = 0;
   out_8573431280396982104[10] = 0;
   out_8573431280396982104[11] = 0;
   out_8573431280396982104[12] = 1;
   out_8573431280396982104[13] = 0;
   out_8573431280396982104[14] = 0;
   out_8573431280396982104[15] = dt;
   out_8573431280396982104[16] = 0;
   out_8573431280396982104[17] = 0;
   out_8573431280396982104[18] = 0;
   out_8573431280396982104[19] = 0;
   out_8573431280396982104[20] = 0;
   out_8573431280396982104[21] = 0;
   out_8573431280396982104[22] = 0;
   out_8573431280396982104[23] = 0;
   out_8573431280396982104[24] = 1;
   out_8573431280396982104[25] = 0;
   out_8573431280396982104[26] = 0;
   out_8573431280396982104[27] = dt;
   out_8573431280396982104[28] = 0;
   out_8573431280396982104[29] = 0;
   out_8573431280396982104[30] = 0;
   out_8573431280396982104[31] = 0;
   out_8573431280396982104[32] = 0;
   out_8573431280396982104[33] = 0;
   out_8573431280396982104[34] = 0;
   out_8573431280396982104[35] = 0;
   out_8573431280396982104[36] = 1;
   out_8573431280396982104[37] = 0;
   out_8573431280396982104[38] = 0;
   out_8573431280396982104[39] = 0;
   out_8573431280396982104[40] = 0;
   out_8573431280396982104[41] = 0;
   out_8573431280396982104[42] = 0;
   out_8573431280396982104[43] = 0;
   out_8573431280396982104[44] = 0;
   out_8573431280396982104[45] = 0;
   out_8573431280396982104[46] = 0;
   out_8573431280396982104[47] = 0;
   out_8573431280396982104[48] = 1;
   out_8573431280396982104[49] = 0;
   out_8573431280396982104[50] = 0;
   out_8573431280396982104[51] = 0;
   out_8573431280396982104[52] = 0;
   out_8573431280396982104[53] = 0;
   out_8573431280396982104[54] = 0;
   out_8573431280396982104[55] = 0;
   out_8573431280396982104[56] = 0;
   out_8573431280396982104[57] = 0;
   out_8573431280396982104[58] = 0;
   out_8573431280396982104[59] = 0;
   out_8573431280396982104[60] = 1;
   out_8573431280396982104[61] = 0;
   out_8573431280396982104[62] = 0;
   out_8573431280396982104[63] = 0;
   out_8573431280396982104[64] = 0;
   out_8573431280396982104[65] = 0;
   out_8573431280396982104[66] = 0;
   out_8573431280396982104[67] = 0;
   out_8573431280396982104[68] = 0;
   out_8573431280396982104[69] = 0;
   out_8573431280396982104[70] = 0;
   out_8573431280396982104[71] = 0;
   out_8573431280396982104[72] = 1;
   out_8573431280396982104[73] = dt;
   out_8573431280396982104[74] = 0;
   out_8573431280396982104[75] = 0;
   out_8573431280396982104[76] = 0;
   out_8573431280396982104[77] = 0;
   out_8573431280396982104[78] = 0;
   out_8573431280396982104[79] = 0;
   out_8573431280396982104[80] = 0;
   out_8573431280396982104[81] = 0;
   out_8573431280396982104[82] = 0;
   out_8573431280396982104[83] = 0;
   out_8573431280396982104[84] = 1;
   out_8573431280396982104[85] = dt;
   out_8573431280396982104[86] = 0;
   out_8573431280396982104[87] = 0;
   out_8573431280396982104[88] = 0;
   out_8573431280396982104[89] = 0;
   out_8573431280396982104[90] = 0;
   out_8573431280396982104[91] = 0;
   out_8573431280396982104[92] = 0;
   out_8573431280396982104[93] = 0;
   out_8573431280396982104[94] = 0;
   out_8573431280396982104[95] = 0;
   out_8573431280396982104[96] = 1;
   out_8573431280396982104[97] = 0;
   out_8573431280396982104[98] = 0;
   out_8573431280396982104[99] = 0;
   out_8573431280396982104[100] = 0;
   out_8573431280396982104[101] = 0;
   out_8573431280396982104[102] = 0;
   out_8573431280396982104[103] = 0;
   out_8573431280396982104[104] = 0;
   out_8573431280396982104[105] = 0;
   out_8573431280396982104[106] = 0;
   out_8573431280396982104[107] = 0;
   out_8573431280396982104[108] = 1;
   out_8573431280396982104[109] = 0;
   out_8573431280396982104[110] = 0;
   out_8573431280396982104[111] = 0;
   out_8573431280396982104[112] = 0;
   out_8573431280396982104[113] = 0;
   out_8573431280396982104[114] = 0;
   out_8573431280396982104[115] = 0;
   out_8573431280396982104[116] = 0;
   out_8573431280396982104[117] = 0;
   out_8573431280396982104[118] = 0;
   out_8573431280396982104[119] = 0;
   out_8573431280396982104[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_3071191641789059419) {
   out_3071191641789059419[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_1159916964347353646) {
   out_1159916964347353646[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1159916964347353646[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1159916964347353646[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1159916964347353646[3] = 0;
   out_1159916964347353646[4] = 0;
   out_1159916964347353646[5] = 0;
   out_1159916964347353646[6] = 1;
   out_1159916964347353646[7] = 0;
   out_1159916964347353646[8] = 0;
   out_1159916964347353646[9] = 0;
   out_1159916964347353646[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_3534085142260227199) {
   out_3534085142260227199[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_5150692590141527809) {
   out_5150692590141527809[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5150692590141527809[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5150692590141527809[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5150692590141527809[3] = 0;
   out_5150692590141527809[4] = 0;
   out_5150692590141527809[5] = 0;
   out_5150692590141527809[6] = 1;
   out_5150692590141527809[7] = 0;
   out_5150692590141527809[8] = 0;
   out_5150692590141527809[9] = 1;
   out_5150692590141527809[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_27490942570545395) {
   out_27490942570545395[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_3838869535775368150) {
   out_3838869535775368150[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3838869535775368150[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3838869535775368150[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3838869535775368150[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3838869535775368150[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3838869535775368150[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3838869535775368150[6] = 0;
   out_3838869535775368150[7] = 1;
   out_3838869535775368150[8] = 0;
   out_3838869535775368150[9] = 0;
   out_3838869535775368150[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_27490942570545395) {
   out_27490942570545395[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_3838869535775368150) {
   out_3838869535775368150[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3838869535775368150[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3838869535775368150[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3838869535775368150[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3838869535775368150[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3838869535775368150[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_3838869535775368150[6] = 0;
   out_3838869535775368150[7] = 1;
   out_3838869535775368150[8] = 0;
   out_3838869535775368150[9] = 0;
   out_3838869535775368150[10] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_6, H_6, NULL, in_z, in_R, in_ea, MAHA_THRESH_6);
}
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_20, H_20, NULL, in_z, in_R, in_ea, MAHA_THRESH_20);
}
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_7, H_7, NULL, in_z, in_R, in_ea, MAHA_THRESH_7);
}
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_21, H_21, NULL, in_z, in_R, in_ea, MAHA_THRESH_21);
}
void gnss_err_fun(double *nom_x, double *delta_x, double *out_3974798752012907017) {
  err_fun(nom_x, delta_x, out_3974798752012907017);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_3775286048623570569) {
  inv_err_fun(nom_x, true_x, out_3775286048623570569);
}
void gnss_H_mod_fun(double *state, double *out_2767523228344983263) {
  H_mod_fun(state, out_2767523228344983263);
}
void gnss_f_fun(double *state, double dt, double *out_7917251045724789548) {
  f_fun(state,  dt, out_7917251045724789548);
}
void gnss_F_fun(double *state, double dt, double *out_8573431280396982104) {
  F_fun(state,  dt, out_8573431280396982104);
}
void gnss_h_6(double *state, double *sat_pos, double *out_3071191641789059419) {
  h_6(state, sat_pos, out_3071191641789059419);
}
void gnss_H_6(double *state, double *sat_pos, double *out_1159916964347353646) {
  H_6(state, sat_pos, out_1159916964347353646);
}
void gnss_h_20(double *state, double *sat_pos, double *out_3534085142260227199) {
  h_20(state, sat_pos, out_3534085142260227199);
}
void gnss_H_20(double *state, double *sat_pos, double *out_5150692590141527809) {
  H_20(state, sat_pos, out_5150692590141527809);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_27490942570545395) {
  h_7(state, sat_pos_vel, out_27490942570545395);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_3838869535775368150) {
  H_7(state, sat_pos_vel, out_3838869535775368150);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_27490942570545395) {
  h_21(state, sat_pos_vel, out_27490942570545395);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_3838869535775368150) {
  H_21(state, sat_pos_vel, out_3838869535775368150);
}
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF gnss = {
  .name = "gnss",
  .kinds = { 6, 20, 7, 21 },
  .feature_kinds = {  },
  .f_fun = gnss_f_fun,
  .F_fun = gnss_F_fun,
  .err_fun = gnss_err_fun,
  .inv_err_fun = gnss_inv_err_fun,
  .H_mod_fun = gnss_H_mod_fun,
  .predict = gnss_predict,
  .hs = {
    { 6, gnss_h_6 },
    { 20, gnss_h_20 },
    { 7, gnss_h_7 },
    { 21, gnss_h_21 },
  },
  .Hs = {
    { 6, gnss_H_6 },
    { 20, gnss_H_20 },
    { 7, gnss_H_7 },
    { 21, gnss_H_21 },
  },
  .updates = {
    { 6, gnss_update_6 },
    { 20, gnss_update_20 },
    { 7, gnss_update_7 },
    { 21, gnss_update_21 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_init(gnss);
