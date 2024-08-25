#include <gtk/gtk.h>

void make_window(GtkWidget* toggle, char* data)
{
    GtkWidget *window, *button;

    window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(window), "Message 1");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    button = gtk_button_new_with_label(data);

    g_signal_connect_swapped (toggle, "toggled", G_CALLBACK (gtk_window_destroy), window);
    gtk_window_set_child(GTK_WINDOW(window), button);
    gtk_window_present(GTK_WINDOW(window));
}

void make_toggles(GtkApplication *app, gpointer user_data) // if NULL does not work use --> gpointer user_data
{
    GtkWidget *window, *toggle1, *toggle2, *box;

    char *text1, *text2;

    text1 = "rishabh!";

    text2 = "riddhi!";

    window = gtk_application_window_new(app);

    gtk_window_set_title(GTK_WINDOW(window), "Toggle Message" );
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    toggle1 = gtk_toggle_button_new_with_label("Message 1");
    g_signal_connect(toggle1, "toggled", G_CALLBACK(make_window), text1);
    gtk_box_append(GTK_BOX(box), toggle1);

    toggle2 = gtk_toggle_button_new_with_label("Message 2");
    g_signal_connect(toggle2, "toggled", G_CALLBACK(make_window), text2);
    gtk_box_append(GTK_BOX(box), toggle2);

    gtk_window_set_child(GTK_WINDOW(window), box);

    gtk_window_present(GTK_WINDOW(window));

}

int main(int argc, char** argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("toggle.message.demo", G_APPLICATION_DEFAULT_FLAGS);

    g_signal_connect(app, "activate", G_CALLBACK(make_toggles), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}