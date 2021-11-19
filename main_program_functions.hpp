#pragma once

void init_net();
void init_ball();
void init_racket();
void init_env();

void move();

void collide();

void live();

void draw_scene();
void display();

void tick(int null);

void init_glut_window();

void init_glut_functions();

void init_glut(int& argc, char**& argv);