#include <gtk/gtk.h>

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *button;

    window = gtk_application_window_new(app);

    gtk_window_set_title(GTK_WINDOW(window),"Doctor Doom!");

    gtk_window_set_default_size(GTK_WINDOW(window), 1920, 1080);

    button = gtk_button_new_with_label("Let There be Doom!");

    gtk_window_set_child(GTK_WINDOW(window), button);

    gtk_window_present(GTK_WINDOW(window));

}
int main(int argc, char** argv)
{
    GtkApplication *app;
    int status;
    
    app = gtk_application_new("app.gtk.hello", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK ( activate ), NULL );
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;

}