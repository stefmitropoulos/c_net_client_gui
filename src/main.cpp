#include <gtk/gtk.h>

static void
entry_activate (GtkEntry *entry, GtkLabel *label)
{
    const char *entry_in = gtk_entry_get_text (entry);
    gtk_label_set_text (label, entry_in);
}

int main( int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *label,*label2;
    GtkWidget *entry;
    GtkWidget *button;


    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 250);
    gtk_window_set_title(GTK_WINDOW(window), "Linux-buddy.blogspot.com");

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 7);

    //Create label
    label = gtk_label_new("PENIS");
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 3);

    //Create entryBox
    entry = gtk_entry_new ();
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 3);
    g_signal_connect (GTK_ENTRY(entry), "activate",
                      G_CALLBACK(entry_activate), label);


    //Create Button
    button = gtk_toggle_button_new_with_label ("Button");
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 3);
    g_signal_connect (GTK_TOGGLE_BUTTON (button), "toggled",
                      G_CALLBACK (entry_activate), label);


        //Connects GCallback function gtk_main_quit to "destroy" signal for "window"
    g_signal_connect(G_OBJECT(window), "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);

    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}