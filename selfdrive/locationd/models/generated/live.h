#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_8092633923285395540);
void live_err_fun(double *nom_x, double *delta_x, double *out_3620341017897320880);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_2868810410129887903);
void live_H_mod_fun(double *state, double *out_375769480066233426);
void live_f_fun(double *state, double dt, double *out_2886570514762972352);
void live_F_fun(double *state, double dt, double *out_599726182636572751);
void live_h_4(double *state, double *unused, double *out_5447955873756908119);
void live_H_4(double *state, double *unused, double *out_7583561376319400239);
void live_h_9(double *state, double *unused, double *out_3558382028159031217);
void live_H_9(double *state, double *unused, double *out_3575963762125703907);
void live_h_10(double *state, double *unused, double *out_4774111250308639731);
void live_H_10(double *state, double *unused, double *out_6603987483218829838);
void live_h_12(double *state, double *unused, double *out_3015068259565433242);
void live_H_12(double *state, double *unused, double *out_5843726289358189582);
void live_h_35(double *state, double *unused, double *out_8712759432416130386);
void live_H_35(double *state, double *unused, double *out_3098163257033175873);
void live_h_32(double *state, double *unused, double *out_31822123257556908);
void live_H_32(double *state, double *unused, double *out_5984644679881630369);
void live_h_13(double *state, double *unused, double *out_292658993205325816);
void live_H_13(double *state, double *unused, double *out_2424786986171971443);
void live_h_14(double *state, double *unused, double *out_3558382028159031217);
void live_H_14(double *state, double *unused, double *out_3575963762125703907);
void live_h_33(double *state, double *unused, double *out_1458641141303595655);
void live_H_33(double *state, double *unused, double *out_52393747605681731);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}