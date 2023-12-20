/*
 * Copyright 2006,2011,2012,2014 Free Software Foundation, Inc.
 * Author: Tom Rondeau, 2011
 *
 * Converted to C by Steve Sampson
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <complex.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define TAU (2.0 * M_PI)

void create_control_loop(float, float, float);
float phase_detector(complex float);
void update_gains(void);
void advance_loop(float);
void phase_wrap(void);
void frequency_limit(void);

// Setters

void set_loop_bandwidth(float);
void set_damping_factor(float);
void set_alpha(float);
void set_beta(float);
void set_frequency(float);
void set_phase(float);
void set_max_freq(float);
void set_min_freq(float);

void set_costas_enable(bool);

// Getters

float get_loop_bandwidth(void);
float get_damping_factor(void);
float get_alpha(void);
float get_beta(void);
float get_frequency(void);
float get_phase(void);
float get_max_freq(void);
float get_min_freq(void);

bool get_costas_enable(void);

#ifdef __cplusplus
}
#endif

