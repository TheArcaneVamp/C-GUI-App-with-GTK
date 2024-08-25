#include <gtk/gtk.h>

static void
output_state (GtkToggleButton *source,
              gpointer         user_data)
{
  g_print ("Toggle button %s is active: %s",
           gtk_button_get_label (GTK_BUTTON (source)),
           gtk_toggle_button_get_active (source) ? "Yes" : "No");
}

static void
make_toggles (GtkApplication *app, gpointer user_data)
{
  GtkWidget *window, *toggle1, *toggle2;
  GtkWidget *box;
  const char *text;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Hello Rishabh!");
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 400);

  box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 12);

  text = "1";
  toggle1 = gtk_toggle_button_new_with_label (text);

  g_signal_connect (toggle1, "toggled",
                    G_CALLBACK (output_state),
                    NULL);
  gtk_box_append (GTK_BOX (box), toggle1);

  text = "2";
  toggle2 = gtk_toggle_button_new_with_label (text);
  g_signal_connect (toggle2, "toggled",
                    G_CALLBACK (output_state),
                    NULL);
  gtk_box_append (GTK_BOX (box), toggle2);

  gtk_window_set_child (GTK_WINDOW (window), box);
  gtk_window_present (GTK_WINDOW (window));
}

int main(int argc, char** argv)
{
    int status;
    GtkApplication *app;

    app = gtk_application_new("toggle.example.demo", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(make_toggles), NULL);
    status = g_application_run(G_APPLICATION(app),argc, argv);
    g_object_unref(app);
    return status;
}