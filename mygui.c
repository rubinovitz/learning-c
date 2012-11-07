#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>

    char *buttonfiles[5];
// on click callback
static void callback (GtkWidget *widget,
                      gpointer   data)
{
// send system call to run program corresponding with button
   system((gchar *) data);

}

static gboolean delete_event (GtkWidget *widget,
                              GdkEvent  *event,
                              gpointer   data)
{
    gtk_main_quit ();
    return FALSE;
}

int main (int   argc,
          char *argv[])
{
    GtkWidget *window;

    GtkWidget *box1;

    char *buttonnames[5];

    GtkWidget *buttons[5];

// list of button names for buttons
    buttonnames[0] = "Run shellscript";
    buttonnames[1]= "Run getlines";
    buttonnames[2]= "Run timecalc";
    buttonnames[3]= "Run linkedlist";
    buttonnames[4]= "Run whattime";

// list of commands each button should run    
    buttonfiles[0] = "./shellscript.d";
    buttonfiles[1]= "./getlines";
    buttonfiles[2]= "./timecalc";
    buttonfiles[3]= "./linkedlist";
    buttonfiles[4]= "./whattime";
   

int i;

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

// open window called "My Assignments
    gtk_window_set_title (GTK_WINDOW (window), "My Assignments");

     * exits GTK. */
    g_signal_connect (window, "delete-event",
		      G_CALLBACK (delete_event), NULL);

    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    gtk_container_set_border_width (GTK_CONTAINER (window), 100);

    box1 = gtk_vbox_new (FALSE, 0);

    gtk_container_add (GTK_CONTAINER (window), box1);

// loop through array of buttons and put them into the window with their respective titles and commands
    for (i = 0; i < 5; i++)
{
    // make a new button for the index
    buttons[i] = gtk_button_new_with_label (buttonnames[i]);
    // set a callback for the button that will call its file
    g_signal_connect (buttons[i], "clicked",
		      G_CALLBACK (callback), buttonfiles[i]);
    // pack the button into box1
    gtk_box_pack_start (GTK_BOX (box1), buttons[i], TRUE, TRUE, 0);
    // show the button
    gtk_widget_show (buttons[i]);
}


 

    gtk_widget_show (box1);

    gtk_widget_show (window);

    gtk_main ();

    return 0;
}
