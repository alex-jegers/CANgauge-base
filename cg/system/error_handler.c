/**********     INCLUDES        **********/
#include "error_handler.h"
#include "drivers/drivers.h"
/**********     TYPEDEFS         **********/

/**********		DEFINES		**********/

/**********		EXTERNAL VARIABLE DEFINITIONS		**********/

/**********		STATIC VARIABLES		**********/

/**********		STATIC FUNCTION DECLRATIONS		**********/

/**********		STATIC FUNCTION DEFINITIONS		**********/

/**********		GLOBAL FUNCTION DEFINITIONS		**********/
void error_show_msgbox(char* msg)
{
	assert( lv_port_take_lvgl_mutex(500) );
	lv_obj_t* msg_box = ui_helpers_show_msgbox(msg, NULL, NULL);
	ui_helpers_add_msgbox_close_btn(msg_box, NULL);
	lv_port_give_lvgl_mutex();
}

void error_show_msgbox_from_lvgl_task(char* msg)
{
	lv_obj_t* msg_box = ui_helpers_show_msgbox(msg, NULL, NULL);
	ui_helpers_add_msgbox_close_btn(msg_box, NULL);
}
