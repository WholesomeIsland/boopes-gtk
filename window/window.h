#include "../boopes.h"
#include <gtk/gtk.h>

class(BGtkWindow)
method_proto(BGtkWindow, void, SetTitle, char*);
method_proto(BGtkWindow, void, Show);
method_proto(BGtkWindow, void, Close);
GtkWidget* window;
method_proto(BGtkWindow, void, SignalConnect, char*, GCallback);
class_end(BGtkWindow)

BGtkWindow* BGtkWindow_init(int x, int y, char* title, GtkApplication* app){
BGtkWindow* retval = new(BGtkWindow);
retval->window = gtk_application_window_new(app);
call_method(retval, SetTitle, title);
gtk_window_set_default_size(GTK_WINDOW(retval->window), x, y);
return retval;
}
method_def(BGtkWindow, void, SetTitle, char* title){
      gtk_window_set_title(GTK_WINDOW(this->window), title);
}
method_def(BGtkWindow, void, Show){
    gtk_widget_show_all(this->window);
}
method_def(BGtkWindow, void, Close){
    gtk_widget_destroy(this->window);
}