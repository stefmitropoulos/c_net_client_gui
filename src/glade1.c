#include <gtk/gtk.h>

// cc `pkg-config --cflags gtk+-3.0` glade1.c -o hello `pkg-config --libs gtk+-3.0` -rdynamic

void button_clicked(GtkWidget* mac_entry, GtkWidget* wakey_wakey_button){

      const char *input1 = (const char *)malloc(20);

}


int main (int    argc,char **argv)
{
    /* Init GTK+ */
    gtk_init( &argc, &argv );

    /* Create new GtkBuilder object */
    GtkBuilder *builder = gtk_builder_new();

    /* Load UI from file.
     * Replace "sum.glade" with your saved project. */
    gtk_builder_add_from_file( builder, "glade1.glade", NULL);

    /* Get main window pointer from UI */
    GtkWidget* window = GTK_WIDGET( gtk_builder_get_object( builder, "window1" ) );

    /* Connect signals */
    gtk_builder_connect_signals( builder, NULL );

    /* Destroy builder, since we don't need it anymore */
    g_object_unref( G_OBJECT( builder ) );

    /* Show window. All other widgets are automatically shown by GtkBuilder */
    gtk_widget_show( window );


            //Connects GCallback function gtk_main_quit to "destroy" signal for "window"
    g_signal_connect(G_OBJECT(window), "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);

    /* Start main loop */
    gtk_main();

    return( 0 );
  return 0;
}
