#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_3974798752012907017);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_3775286048623570569);
void gnss_H_mod_fun(double *state, double *out_2767523228344983263);
void gnss_f_fun(double *state, double dt, double *out_7917251045724789548);
void gnss_F_fun(double *state, double dt, double *out_8573431280396982104);
void gnss_h_6(double *state, double *sat_pos, double *out_3071191641789059419);
void gnss_H_6(double *state, double *sat_pos, double *out_1159916964347353646);
void gnss_h_20(double *state, double *sat_pos, double *out_3534085142260227199);
void gnss_H_20(double *state, double *sat_pos, double *out_5150692590141527809);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_27490942570545395);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_3838869535775368150);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_27490942570545395);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_3838869535775368150);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}