/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <allegro5/allegro.h>  
#include <allegro5/allegro_color.h> 
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_ttf.h> 
#include <allegro5/allegro_audio.h> 
#include <allegro5/allegro_acodec.h> 
#include "config.h"
#include "main_menu.h"
uint16_t menu_display(ALLEGRO_SAMPLE *sample[],ALLEGRO_EVENT_QUEUE ** event_queue,ALLEGRO_FONT *font[]){
    uint8_t do_exit=false, aux=0 ;
    float mouse_x = 0 ;
    float mouse_y =0 ;
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_play_sample(sample[0], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
    create_button(font[0]);
    al_flip_display();
    while(!do_exit){ 
        ALLEGRO_EVENT ev;
        if (al_get_next_event(*event_queue, &ev)) //Toma un evento de la cola, VER RETURN EN DOCUMENT.
        {
             if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE )
                do_exit = true;

            else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                mouse_x = ev.mouse.x;
                mouse_y = ev.mouse.y;
            }
        }
        if(mouse_x>=SCREEN_W / 4.0 && mouse_x<= 3*SCREEN_W / 4.0)
            if(mouse_y>=7*SCREEN_H/16 && mouse_y<= 9*SCREEN_H/16){
                do_exit=true;
                aux=1;
            }
            else if(mouse_y>=5*SCREEN_H/8 && mouse_y<= 3*SCREEN_H/4){
                do_exit=true;
                aux=2;
            }
            else if (mouse_y>=13*SCREEN_H/16 && mouse_y<= 15*SCREEN_H/16){
                do_exit=true;
                aux=3;
            }
        
    }
    return aux;
}
void create_button(ALLEGRO_FONT*font){
    al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, (SCREEN_H / 4), ALLEGRO_ALIGN_CENTER, "SPACE INVADERS");
    al_draw_rectangle(SCREEN_W/4, 7*SCREEN_H/16, 3*SCREEN_W/4, 9*SCREEN_H/16, al_color_name("white"), 2.0);
    al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, (SCREEN_H /2), ALLEGRO_ALIGN_CENTER, "PLAY");
    al_draw_rectangle(SCREEN_W/4, 5*SCREEN_H/8, 3*SCREEN_W/4, 3*SCREEN_H/4, al_color_name("white"), 2.0);
    al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, (11*SCREEN_H / 16), ALLEGRO_ALIGN_CENTER, "DIFFICULTY");
    al_draw_rectangle(SCREEN_W/4, 13*SCREEN_H/16, 3*SCREEN_W/4, 15*SCREEN_H/16, al_color_name("white"), 2.0);
    al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, (7*SCREEN_H / 8), ALLEGRO_ALIGN_CENTER, "TOP SCORE");
    
}