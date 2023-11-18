#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_53504007028147359) {
   out_53504007028147359[0] = delta_x[0] + nom_x[0];
   out_53504007028147359[1] = delta_x[1] + nom_x[1];
   out_53504007028147359[2] = delta_x[2] + nom_x[2];
   out_53504007028147359[3] = delta_x[3] + nom_x[3];
   out_53504007028147359[4] = delta_x[4] + nom_x[4];
   out_53504007028147359[5] = delta_x[5] + nom_x[5];
   out_53504007028147359[6] = delta_x[6] + nom_x[6];
   out_53504007028147359[7] = delta_x[7] + nom_x[7];
   out_53504007028147359[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7516036170442418237) {
   out_7516036170442418237[0] = -nom_x[0] + true_x[0];
   out_7516036170442418237[1] = -nom_x[1] + true_x[1];
   out_7516036170442418237[2] = -nom_x[2] + true_x[2];
   out_7516036170442418237[3] = -nom_x[3] + true_x[3];
   out_7516036170442418237[4] = -nom_x[4] + true_x[4];
   out_7516036170442418237[5] = -nom_x[5] + true_x[5];
   out_7516036170442418237[6] = -nom_x[6] + true_x[6];
   out_7516036170442418237[7] = -nom_x[7] + true_x[7];
   out_7516036170442418237[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_2877146867695156852) {
   out_2877146867695156852[0] = 1.0;
   out_2877146867695156852[1] = 0;
   out_2877146867695156852[2] = 0;
   out_2877146867695156852[3] = 0;
   out_2877146867695156852[4] = 0;
   out_2877146867695156852[5] = 0;
   out_2877146867695156852[6] = 0;
   out_2877146867695156852[7] = 0;
   out_2877146867695156852[8] = 0;
   out_2877146867695156852[9] = 0;
   out_2877146867695156852[10] = 1.0;
   out_2877146867695156852[11] = 0;
   out_2877146867695156852[12] = 0;
   out_2877146867695156852[13] = 0;
   out_2877146867695156852[14] = 0;
   out_2877146867695156852[15] = 0;
   out_2877146867695156852[16] = 0;
   out_2877146867695156852[17] = 0;
   out_2877146867695156852[18] = 0;
   out_2877146867695156852[19] = 0;
   out_2877146867695156852[20] = 1.0;
   out_2877146867695156852[21] = 0;
   out_2877146867695156852[22] = 0;
   out_2877146867695156852[23] = 0;
   out_2877146867695156852[24] = 0;
   out_2877146867695156852[25] = 0;
   out_2877146867695156852[26] = 0;
   out_2877146867695156852[27] = 0;
   out_2877146867695156852[28] = 0;
   out_2877146867695156852[29] = 0;
   out_2877146867695156852[30] = 1.0;
   out_2877146867695156852[31] = 0;
   out_2877146867695156852[32] = 0;
   out_2877146867695156852[33] = 0;
   out_2877146867695156852[34] = 0;
   out_2877146867695156852[35] = 0;
   out_2877146867695156852[36] = 0;
   out_2877146867695156852[37] = 0;
   out_2877146867695156852[38] = 0;
   out_2877146867695156852[39] = 0;
   out_2877146867695156852[40] = 1.0;
   out_2877146867695156852[41] = 0;
   out_2877146867695156852[42] = 0;
   out_2877146867695156852[43] = 0;
   out_2877146867695156852[44] = 0;
   out_2877146867695156852[45] = 0;
   out_2877146867695156852[46] = 0;
   out_2877146867695156852[47] = 0;
   out_2877146867695156852[48] = 0;
   out_2877146867695156852[49] = 0;
   out_2877146867695156852[50] = 1.0;
   out_2877146867695156852[51] = 0;
   out_2877146867695156852[52] = 0;
   out_2877146867695156852[53] = 0;
   out_2877146867695156852[54] = 0;
   out_2877146867695156852[55] = 0;
   out_2877146867695156852[56] = 0;
   out_2877146867695156852[57] = 0;
   out_2877146867695156852[58] = 0;
   out_2877146867695156852[59] = 0;
   out_2877146867695156852[60] = 1.0;
   out_2877146867695156852[61] = 0;
   out_2877146867695156852[62] = 0;
   out_2877146867695156852[63] = 0;
   out_2877146867695156852[64] = 0;
   out_2877146867695156852[65] = 0;
   out_2877146867695156852[66] = 0;
   out_2877146867695156852[67] = 0;
   out_2877146867695156852[68] = 0;
   out_2877146867695156852[69] = 0;
   out_2877146867695156852[70] = 1.0;
   out_2877146867695156852[71] = 0;
   out_2877146867695156852[72] = 0;
   out_2877146867695156852[73] = 0;
   out_2877146867695156852[74] = 0;
   out_2877146867695156852[75] = 0;
   out_2877146867695156852[76] = 0;
   out_2877146867695156852[77] = 0;
   out_2877146867695156852[78] = 0;
   out_2877146867695156852[79] = 0;
   out_2877146867695156852[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1046664394760190799) {
   out_1046664394760190799[0] = state[0];
   out_1046664394760190799[1] = state[1];
   out_1046664394760190799[2] = state[2];
   out_1046664394760190799[3] = state[3];
   out_1046664394760190799[4] = state[4];
   out_1046664394760190799[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1046664394760190799[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1046664394760190799[7] = state[7];
   out_1046664394760190799[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7146767317469864605) {
   out_7146767317469864605[0] = 1;
   out_7146767317469864605[1] = 0;
   out_7146767317469864605[2] = 0;
   out_7146767317469864605[3] = 0;
   out_7146767317469864605[4] = 0;
   out_7146767317469864605[5] = 0;
   out_7146767317469864605[6] = 0;
   out_7146767317469864605[7] = 0;
   out_7146767317469864605[8] = 0;
   out_7146767317469864605[9] = 0;
   out_7146767317469864605[10] = 1;
   out_7146767317469864605[11] = 0;
   out_7146767317469864605[12] = 0;
   out_7146767317469864605[13] = 0;
   out_7146767317469864605[14] = 0;
   out_7146767317469864605[15] = 0;
   out_7146767317469864605[16] = 0;
   out_7146767317469864605[17] = 0;
   out_7146767317469864605[18] = 0;
   out_7146767317469864605[19] = 0;
   out_7146767317469864605[20] = 1;
   out_7146767317469864605[21] = 0;
   out_7146767317469864605[22] = 0;
   out_7146767317469864605[23] = 0;
   out_7146767317469864605[24] = 0;
   out_7146767317469864605[25] = 0;
   out_7146767317469864605[26] = 0;
   out_7146767317469864605[27] = 0;
   out_7146767317469864605[28] = 0;
   out_7146767317469864605[29] = 0;
   out_7146767317469864605[30] = 1;
   out_7146767317469864605[31] = 0;
   out_7146767317469864605[32] = 0;
   out_7146767317469864605[33] = 0;
   out_7146767317469864605[34] = 0;
   out_7146767317469864605[35] = 0;
   out_7146767317469864605[36] = 0;
   out_7146767317469864605[37] = 0;
   out_7146767317469864605[38] = 0;
   out_7146767317469864605[39] = 0;
   out_7146767317469864605[40] = 1;
   out_7146767317469864605[41] = 0;
   out_7146767317469864605[42] = 0;
   out_7146767317469864605[43] = 0;
   out_7146767317469864605[44] = 0;
   out_7146767317469864605[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7146767317469864605[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7146767317469864605[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7146767317469864605[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7146767317469864605[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7146767317469864605[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7146767317469864605[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7146767317469864605[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7146767317469864605[53] = -9.8000000000000007*dt;
   out_7146767317469864605[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7146767317469864605[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7146767317469864605[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7146767317469864605[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7146767317469864605[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7146767317469864605[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7146767317469864605[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7146767317469864605[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7146767317469864605[62] = 0;
   out_7146767317469864605[63] = 0;
   out_7146767317469864605[64] = 0;
   out_7146767317469864605[65] = 0;
   out_7146767317469864605[66] = 0;
   out_7146767317469864605[67] = 0;
   out_7146767317469864605[68] = 0;
   out_7146767317469864605[69] = 0;
   out_7146767317469864605[70] = 1;
   out_7146767317469864605[71] = 0;
   out_7146767317469864605[72] = 0;
   out_7146767317469864605[73] = 0;
   out_7146767317469864605[74] = 0;
   out_7146767317469864605[75] = 0;
   out_7146767317469864605[76] = 0;
   out_7146767317469864605[77] = 0;
   out_7146767317469864605[78] = 0;
   out_7146767317469864605[79] = 0;
   out_7146767317469864605[80] = 1;
}
void h_25(double *state, double *unused, double *out_2260312613686352744) {
   out_2260312613686352744[0] = state[6];
}
void H_25(double *state, double *unused, double *out_4428509306206893012) {
   out_4428509306206893012[0] = 0;
   out_4428509306206893012[1] = 0;
   out_4428509306206893012[2] = 0;
   out_4428509306206893012[3] = 0;
   out_4428509306206893012[4] = 0;
   out_4428509306206893012[5] = 0;
   out_4428509306206893012[6] = 1;
   out_4428509306206893012[7] = 0;
   out_4428509306206893012[8] = 0;
}
void h_24(double *state, double *unused, double *out_2900175126686715536) {
   out_2900175126686715536[0] = state[4];
   out_2900175126686715536[1] = state[5];
}
void H_24(double *state, double *unused, double *out_6654217090185761574) {
   out_6654217090185761574[0] = 0;
   out_6654217090185761574[1] = 0;
   out_6654217090185761574[2] = 0;
   out_6654217090185761574[3] = 0;
   out_6654217090185761574[4] = 1;
   out_6654217090185761574[5] = 0;
   out_6654217090185761574[6] = 0;
   out_6654217090185761574[7] = 0;
   out_6654217090185761574[8] = 0;
   out_6654217090185761574[9] = 0;
   out_6654217090185761574[10] = 0;
   out_6654217090185761574[11] = 0;
   out_6654217090185761574[12] = 0;
   out_6654217090185761574[13] = 0;
   out_6654217090185761574[14] = 1;
   out_6654217090185761574[15] = 0;
   out_6654217090185761574[16] = 0;
   out_6654217090185761574[17] = 0;
}
void h_30(double *state, double *unused, double *out_8725872695774310547) {
   out_8725872695774310547[0] = state[4];
}
void H_30(double *state, double *unused, double *out_7101544426011041849) {
   out_7101544426011041849[0] = 0;
   out_7101544426011041849[1] = 0;
   out_7101544426011041849[2] = 0;
   out_7101544426011041849[3] = 0;
   out_7101544426011041849[4] = 1;
   out_7101544426011041849[5] = 0;
   out_7101544426011041849[6] = 0;
   out_7101544426011041849[7] = 0;
   out_7101544426011041849[8] = 0;
}
void h_26(double *state, double *unused, double *out_3724199428113464902) {
   out_3724199428113464902[0] = state[7];
}
void H_26(double *state, double *unused, double *out_687005987332836788) {
   out_687005987332836788[0] = 0;
   out_687005987332836788[1] = 0;
   out_687005987332836788[2] = 0;
   out_687005987332836788[3] = 0;
   out_687005987332836788[4] = 0;
   out_687005987332836788[5] = 0;
   out_687005987332836788[6] = 0;
   out_687005987332836788[7] = 1;
   out_687005987332836788[8] = 0;
}
void h_27(double *state, double *unused, double *out_8659354131100201890) {
   out_8659354131100201890[0] = state[3];
}
void H_27(double *state, double *unused, double *out_2124407047263228031) {
   out_2124407047263228031[0] = 0;
   out_2124407047263228031[1] = 0;
   out_2124407047263228031[2] = 0;
   out_2124407047263228031[3] = 1;
   out_2124407047263228031[4] = 0;
   out_2124407047263228031[5] = 0;
   out_2124407047263228031[6] = 0;
   out_2124407047263228031[7] = 0;
   out_2124407047263228031[8] = 0;
}
void h_29(double *state, double *unused, double *out_4797670654671700238) {
   out_4797670654671700238[0] = state[1];
}
void H_29(double *state, double *unused, double *out_4809401703378045126) {
   out_4809401703378045126[0] = 0;
   out_4809401703378045126[1] = 1;
   out_4809401703378045126[2] = 0;
   out_4809401703378045126[3] = 0;
   out_4809401703378045126[4] = 0;
   out_4809401703378045126[5] = 0;
   out_4809401703378045126[6] = 0;
   out_4809401703378045126[7] = 0;
   out_4809401703378045126[8] = 0;
}
void h_28(double *state, double *unused, double *out_8843880089707687291) {
   out_8843880089707687291[0] = state[0];
}
void H_28(double *state, double *unused, double *out_6773031974943371377) {
   out_6773031974943371377[0] = 1;
   out_6773031974943371377[1] = 0;
   out_6773031974943371377[2] = 0;
   out_6773031974943371377[3] = 0;
   out_6773031974943371377[4] = 0;
   out_6773031974943371377[5] = 0;
   out_6773031974943371377[6] = 0;
   out_6773031974943371377[7] = 0;
   out_6773031974943371377[8] = 0;
}
void h_31(double *state, double *unused, double *out_5897762141940375094) {
   out_5897762141940375094[0] = state[8];
}
void H_31(double *state, double *unused, double *out_4459155268083853440) {
   out_4459155268083853440[0] = 0;
   out_4459155268083853440[1] = 0;
   out_4459155268083853440[2] = 0;
   out_4459155268083853440[3] = 0;
   out_4459155268083853440[4] = 0;
   out_4459155268083853440[5] = 0;
   out_4459155268083853440[6] = 0;
   out_4459155268083853440[7] = 0;
   out_4459155268083853440[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_53504007028147359) {
  err_fun(nom_x, delta_x, out_53504007028147359);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7516036170442418237) {
  inv_err_fun(nom_x, true_x, out_7516036170442418237);
}
void car_H_mod_fun(double *state, double *out_2877146867695156852) {
  H_mod_fun(state, out_2877146867695156852);
}
void car_f_fun(double *state, double dt, double *out_1046664394760190799) {
  f_fun(state,  dt, out_1046664394760190799);
}
void car_F_fun(double *state, double dt, double *out_7146767317469864605) {
  F_fun(state,  dt, out_7146767317469864605);
}
void car_h_25(double *state, double *unused, double *out_2260312613686352744) {
  h_25(state, unused, out_2260312613686352744);
}
void car_H_25(double *state, double *unused, double *out_4428509306206893012) {
  H_25(state, unused, out_4428509306206893012);
}
void car_h_24(double *state, double *unused, double *out_2900175126686715536) {
  h_24(state, unused, out_2900175126686715536);
}
void car_H_24(double *state, double *unused, double *out_6654217090185761574) {
  H_24(state, unused, out_6654217090185761574);
}
void car_h_30(double *state, double *unused, double *out_8725872695774310547) {
  h_30(state, unused, out_8725872695774310547);
}
void car_H_30(double *state, double *unused, double *out_7101544426011041849) {
  H_30(state, unused, out_7101544426011041849);
}
void car_h_26(double *state, double *unused, double *out_3724199428113464902) {
  h_26(state, unused, out_3724199428113464902);
}
void car_H_26(double *state, double *unused, double *out_687005987332836788) {
  H_26(state, unused, out_687005987332836788);
}
void car_h_27(double *state, double *unused, double *out_8659354131100201890) {
  h_27(state, unused, out_8659354131100201890);
}
void car_H_27(double *state, double *unused, double *out_2124407047263228031) {
  H_27(state, unused, out_2124407047263228031);
}
void car_h_29(double *state, double *unused, double *out_4797670654671700238) {
  h_29(state, unused, out_4797670654671700238);
}
void car_H_29(double *state, double *unused, double *out_4809401703378045126) {
  H_29(state, unused, out_4809401703378045126);
}
void car_h_28(double *state, double *unused, double *out_8843880089707687291) {
  h_28(state, unused, out_8843880089707687291);
}
void car_H_28(double *state, double *unused, double *out_6773031974943371377) {
  H_28(state, unused, out_6773031974943371377);
}
void car_h_31(double *state, double *unused, double *out_5897762141940375094) {
  h_31(state, unused, out_5897762141940375094);
}
void car_H_31(double *state, double *unused, double *out_4459155268083853440) {
  H_31(state, unused, out_4459155268083853440);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_init(car);
