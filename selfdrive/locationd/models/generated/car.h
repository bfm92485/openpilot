#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_53504007028147359);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7516036170442418237);
void car_H_mod_fun(double *state, double *out_2877146867695156852);
void car_f_fun(double *state, double dt, double *out_1046664394760190799);
void car_F_fun(double *state, double dt, double *out_7146767317469864605);
void car_h_25(double *state, double *unused, double *out_2260312613686352744);
void car_H_25(double *state, double *unused, double *out_4428509306206893012);
void car_h_24(double *state, double *unused, double *out_2900175126686715536);
void car_H_24(double *state, double *unused, double *out_6654217090185761574);
void car_h_30(double *state, double *unused, double *out_8725872695774310547);
void car_H_30(double *state, double *unused, double *out_7101544426011041849);
void car_h_26(double *state, double *unused, double *out_3724199428113464902);
void car_H_26(double *state, double *unused, double *out_687005987332836788);
void car_h_27(double *state, double *unused, double *out_8659354131100201890);
void car_H_27(double *state, double *unused, double *out_2124407047263228031);
void car_h_29(double *state, double *unused, double *out_4797670654671700238);
void car_H_29(double *state, double *unused, double *out_4809401703378045126);
void car_h_28(double *state, double *unused, double *out_8843880089707687291);
void car_H_28(double *state, double *unused, double *out_6773031974943371377);
void car_h_31(double *state, double *unused, double *out_5897762141940375094);
void car_H_31(double *state, double *unused, double *out_4459155268083853440);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}