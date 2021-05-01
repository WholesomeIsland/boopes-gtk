#include "../boopes.h"
#include <gtk/gtk.h>

class(BGtkWindow)
method_proto(BGtkWindow, void, SetTitle, char*);
method_proto(BGtkWindow, void, Close);
GtkWidget* window;
method_proto(BGtkWindow, void, SignalConnect, char*, GCallback)
class_end(BGtkWindow)

BGtkWindow* BGtkWindow_init(int x, int y, char* title){
BGtkWindow* retval = new(BGtkWindow);
call_method(retval, SetTitle, title);
gtk_window_set_default_size(GTK_WINDOW(retval->window), x, y);

}
