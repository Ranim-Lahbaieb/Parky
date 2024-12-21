#include <gtk/gtk.h>


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RL_BCom_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_radiobutton_RL_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Inactif_RL_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RL_buttonR_clicked                  (GtkWidget        *button,
                                        gpointer         user_data);

void
on_RL_Annuler_clicked                  (GtkWidget        *button,
                                        gpointer         user_data);

void
on_RL_Affecter_clicked                 (GtkWidget        *button,
                                        gpointer         user_data);

void
on_actualiserAffec_RL_clicked          (GtkWidget        *button,
                                        gpointer         user_data);

void
on_treeviewParking_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_chercher_RL_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_RL_buttonMod_clicked                (GtkWidget        *button,
                                        gpointer         user_data);

void
on_Rl_buttonSupp_clicked               (GtkWidget        *button,
                                        gpointer         user_data);

void
on_actualiser1_RL_clicked              (GtkWidget        *button,
                                        gpointer         user_data);

void
on_treeviewParking_RL_realize          (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_treeviewAgent_RL_realize            (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_treeviewParking_RL_map              (GtkTreeView* treeview);

void
on_treeviewAgent_RL_map                (GtkTreeView* treeview);

void
on_comboboxParky_RL_map                (GtkComboBox *combobox);
