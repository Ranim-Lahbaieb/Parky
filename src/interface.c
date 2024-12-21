/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_RL_Admin (void)
{
  GtkWidget *RL_Admin;
  GtkWidget *alignment12;
  GtkWidget *notebook2;
  GtkWidget *fixed9;
  GtkWidget *nom_RL;
  GtkWidget *add_RL;
  GtkObject *cap_RL_adj;
  GtkWidget *cap_RL;
  GtkWidget *horaire_RL;
  GtkObject *nb_RL_adj;
  GtkWidget *nb_RL;
  GtkWidget *tarif_RL;
  GtkWidget *id_Rl;
  GtkWidget *label91;
  GtkWidget *label92;
  GtkWidget *label93;
  GtkWidget *label94;
  GtkWidget *label101;
  GtkWidget *image34;
  GtkWidget *label103;
  GtkWidget *label90;
  GtkWidget *label95;
  GtkWidget *label99;
  GtkWidget *label96;
  GtkWidget *label97;
  GtkWidget *_Statut_RL;
  GtkWidget *Actif_RL;
  GSList *Actif_RL_group = NULL;
  GtkWidget *Inactif_RL;
  GtkWidget *button16;
  GtkWidget *alignment19;
  GtkWidget *hbox17;
  GtkWidget *image28;
  GtkWidget *label100;
  GtkWidget *type_RL;
  GtkWidget *checkbutton1;
  GtkWidget *checkbutton3;
  GtkWidget *checkbutton4;
  GtkWidget *checkbutton2;
  GtkWidget *confirmer_RL;
  GtkWidget *alignment18;
  GtkWidget *hbox16;
  GtkWidget *image27;
  GtkWidget *label89;
  GtkWidget *fixed13;
  GtkWidget *cellview7;
  GtkWidget *idRecherche_RL;
  GtkWidget *treeviewParking_RL;
  GtkWidget *actualiser1_RL;
  GtkWidget *image42;
  GtkWidget *hbuttonbox7;
  GtkWidget *button23;
  GtkWidget *alignment23;
  GtkWidget *hbox21;
  GtkWidget *image38;
  GtkWidget *label122;
  GtkWidget *button24;
  GtkWidget *alignment24;
  GtkWidget *hbox22;
  GtkWidget *image39;
  GtkWidget *label123;
  GtkWidget *chercher_RL;
  GtkWidget *image41;
  GtkWidget *label125;
  GtkWidget *fixed14;
  GtkWidget *treeviewAgent_RL;
  GtkWidget *button33;
  GtkWidget *alignment29;
  GtkWidget *hbox27;
  GtkWidget *image48;
  GtkWidget *label140;
  GtkWidget *comboboxParky_RL;
  GtkWidget *label137;
  GtkWidget *label136;
  GtkWidget *label138;
  GtkWidget *label141;

  RL_Admin = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (RL_Admin), _("RL_Admin"));

  alignment12 = gtk_alignment_new (0.5, 0.5, 1, 1);
  gtk_widget_show (alignment12);
  gtk_container_add (GTK_CONTAINER (RL_Admin), alignment12);

  notebook2 = gtk_notebook_new ();
  gtk_widget_show (notebook2);
  gtk_container_add (GTK_CONTAINER (alignment12), notebook2);

  fixed9 = gtk_fixed_new ();
  gtk_widget_show (fixed9);
  gtk_container_add (GTK_CONTAINER (notebook2), fixed9);

  nom_RL = gtk_entry_new ();
  gtk_widget_show (nom_RL);
  gtk_fixed_put (GTK_FIXED (fixed9), nom_RL, 232, 160);
  gtk_widget_set_size_request (nom_RL, 164, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (nom_RL), 8226);

  add_RL = gtk_entry_new ();
  gtk_widget_show (add_RL);
  gtk_fixed_put (GTK_FIXED (fixed9), add_RL, 232, 200);
  gtk_widget_set_size_request (add_RL, 164, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (add_RL), 8226);

  cap_RL_adj = gtk_adjustment_new (1, 0, 100, 1, 10, 10);
  cap_RL = gtk_spin_button_new (GTK_ADJUSTMENT (cap_RL_adj), 1, 0);
  gtk_widget_show (cap_RL);
  gtk_fixed_put (GTK_FIXED (fixed9), cap_RL, 232, 240);
  gtk_widget_set_size_request (cap_RL, 164, 27);

  horaire_RL = gtk_entry_new ();
  gtk_widget_show (horaire_RL);
  gtk_fixed_put (GTK_FIXED (fixed9), horaire_RL, 232, 448);
  gtk_widget_set_size_request (horaire_RL, 164, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (horaire_RL), 8226);

  nb_RL_adj = gtk_adjustment_new (1, 0, 100, 1, 10, 10);
  nb_RL = gtk_spin_button_new (GTK_ADJUSTMENT (nb_RL_adj), 1, 0);
  gtk_widget_show (nb_RL);
  gtk_fixed_put (GTK_FIXED (fixed9), nb_RL, 232, 360);
  gtk_widget_set_size_request (nb_RL, 164, 27);

  tarif_RL = gtk_entry_new ();
  gtk_widget_show (tarif_RL);
  gtk_fixed_put (GTK_FIXED (fixed9), tarif_RL, 232, 320);
  gtk_widget_set_size_request (tarif_RL, 164, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (tarif_RL), 8226);

  id_Rl = gtk_entry_new ();
  gtk_widget_show (id_Rl);
  gtk_fixed_put (GTK_FIXED (fixed9), id_Rl, 232, 120);
  gtk_widget_set_size_request (id_Rl, 164, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (id_Rl), 8226);

  label91 = gtk_label_new_with_mnemonic (_("<span foreground=\"darkblue\">Nom du Parking : </span>\n"));
  gtk_widget_show (label91);
  gtk_fixed_put (GTK_FIXED (fixed9), label91, 24, 168);
  gtk_widget_set_size_request (label91, 126, 25);
  gtk_label_set_use_markup (GTK_LABEL (label91), TRUE);
  gtk_label_set_justify (GTK_LABEL (label91), GTK_JUSTIFY_CENTER);
  gtk_misc_set_alignment (GTK_MISC (label91), 0, 0.5);

  label92 = gtk_label_new_with_mnemonic (_("<span foreground=\"darkblue\">Adresse :</span>"));
  gtk_widget_show (label92);
  gtk_fixed_put (GTK_FIXED (fixed9), label92, 24, 200);
  gtk_widget_set_size_request (label92, 118, 25);
  gtk_label_set_use_markup (GTK_LABEL (label92), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label92), 0, 0.5);

  label93 = gtk_label_new_with_mnemonic (_("<span foreground=\"darkblue\">Capacit\303\251 maximale : </span> "));
  gtk_widget_show (label93);
  gtk_fixed_put (GTK_FIXED (fixed9), label93, 24, 240);
  gtk_widget_set_size_request (label93, 136, 25);
  gtk_label_set_use_markup (GTK_LABEL (label93), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label93), 0, 0.5);

  label94 = gtk_label_new_with_mnemonic (_("<span foreground=\"darkblue\">Type de Parking :  </span>"));
  gtk_widget_show (label94);
  gtk_fixed_put (GTK_FIXED (fixed9), label94, 24, 280);
  gtk_widget_set_size_request (label94, 126, 25);
  gtk_label_set_use_markup (GTK_LABEL (label94), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label94), 0, 0.5);

  label101 = gtk_label_new_with_mnemonic (_("<span foreground=\"darkblue\">Ajouter parking</span> \n\n\n"));
  gtk_widget_show (label101);
  gtk_fixed_put (GTK_FIXED (fixed9), label101, 280, 32);
  gtk_widget_set_size_request (label101, 176, 48);
  gtk_label_set_use_markup (GTK_LABEL (label101), TRUE);
  gtk_label_set_justify (GTK_LABEL (label101), GTK_JUSTIFY_CENTER);
  gtk_misc_set_alignment (GTK_MISC (label101), 0.49, 0.38);

  image34 = create_pixmap (RL_Admin, "icone.jpg");
  gtk_widget_show (image34);
  gtk_fixed_put (GTK_FIXED (fixed9), image34, 440, 72);
  gtk_widget_set_size_request (image34, 328, 288);

  label103 = gtk_label_new_with_mnemonic (_("<span foreground=\"darkblue\">Gestion des parkings </span>"));
  gtk_widget_show (label103);
  gtk_fixed_put (GTK_FIXED (fixed9), label103, 1096, 24);
  gtk_widget_set_size_request (label103, 200, 24);
  gtk_label_set_use_markup (GTK_LABEL (label103), TRUE);

  label90 = gtk_label_new_with_mnemonic (_("<span foreground=\"darkblue\">ID-Parking :</span>\n"));
  gtk_widget_show (label90);
  gtk_fixed_put (GTK_FIXED (fixed9), label90, 24, 120);
  gtk_widget_set_size_request (label90, 102, 17);
  gtk_label_set_use_markup (GTK_LABEL (label90), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label90), 0, 0.5);

  label95 = gtk_label_new_with_mnemonic (_("<span foreground=\"darkblue\">Tarif Horaire :  </span>Tarif Horaire : "));
  gtk_widget_show (label95);
  gtk_fixed_put (GTK_FIXED (fixed9), label95, 24, 320);
  gtk_widget_set_size_request (label95, 99, 25);
  gtk_label_set_use_markup (GTK_LABEL (label95), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label95), 0, 0.5);

  label99 = gtk_label_new_with_mnemonic (_("<span foreground=\"darkblue\">Nombre de place disponible :   </span>"));
  gtk_widget_show (label99);
  gtk_fixed_put (GTK_FIXED (fixed9), label99, 24, 360);
  gtk_widget_set_size_request (label99, 199, 25);
  gtk_label_set_use_markup (GTK_LABEL (label99), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label99), 0, 0.5);

  label96 = gtk_label_new_with_mnemonic (_("<span foreground=\"darkblue\">Services Offerts : </span>"));
  gtk_widget_show (label96);
  gtk_fixed_put (GTK_FIXED (fixed9), label96, 24, 400);
  gtk_widget_set_size_request (label96, 129, 25);
  gtk_label_set_use_markup (GTK_LABEL (label96), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label96), 0, 0.5);

  label97 = gtk_label_new_with_mnemonic (_("<span foreground=\"darkblue\">Horaires d'Ouverture :</span>"));
  gtk_widget_show (label97);
  gtk_fixed_put (GTK_FIXED (fixed9), label97, 24, 448);
  gtk_widget_set_size_request (label97, 159, 25);
  gtk_label_set_use_markup (GTK_LABEL (label97), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label97), 0, 0.5);

  _Statut_RL = gtk_label_new (_("<span foreground=\"darkblue\"> Statut du Parking :</span>\n"));
  gtk_widget_show (_Statut_RL);
  gtk_fixed_put (GTK_FIXED (fixed9), _Statut_RL, 8, 504);
  gtk_widget_set_size_request (_Statut_RL, 152, 24);
  gtk_label_set_use_markup (GTK_LABEL (_Statut_RL), TRUE);

  Actif_RL = gtk_radio_button_new_with_mnemonic (NULL, _("Actif"));
  gtk_widget_show (Actif_RL);
  gtk_fixed_put (GTK_FIXED (fixed9), Actif_RL, 232, 504);
  gtk_widget_set_size_request (Actif_RL, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (Actif_RL), Actif_RL_group);
  Actif_RL_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (Actif_RL));

  Inactif_RL = gtk_radio_button_new_with_mnemonic (NULL, _("Inactif"));
  gtk_widget_show (Inactif_RL);
  gtk_fixed_put (GTK_FIXED (fixed9), Inactif_RL, 408, 504);
  gtk_widget_set_size_request (Inactif_RL, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (Inactif_RL), Actif_RL_group);
  Actif_RL_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (Inactif_RL));

  button16 = gtk_button_new ();
  gtk_widget_show (button16);
  gtk_fixed_put (GTK_FIXED (fixed9), button16, 536, 544);
  gtk_widget_set_size_request (button16, 110, 40);

  alignment19 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment19);
  gtk_container_add (GTK_CONTAINER (button16), alignment19);

  hbox17 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox17);
  gtk_container_add (GTK_CONTAINER (alignment19), hbox17);

  image28 = gtk_image_new_from_stock ("gtk-undo", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image28);
  gtk_box_pack_start (GTK_BOX (hbox17), image28, FALSE, FALSE, 0);

  label100 = gtk_label_new_with_mnemonic (_("R\303\251initialiser"));
  gtk_widget_show (label100);
  gtk_box_pack_start (GTK_BOX (hbox17), label100, FALSE, FALSE, 0);

  type_RL = gtk_combo_box_entry_new_text ();
  gtk_widget_show (type_RL);
  gtk_fixed_put (GTK_FIXED (fixed9), type_RL, 232, 280);
  gtk_widget_set_size_request (type_RL, 164, 27);
  gtk_combo_box_append_text (GTK_COMBO_BOX (type_RL), _("Prive"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (type_RL), _("Public"));

  checkbutton1 = gtk_check_button_new_with_mnemonic (_("Borne de recharge"));
  gtk_widget_show (checkbutton1);
  gtk_fixed_put (GTK_FIXED (fixed9), checkbutton1, 232, 400);
  gtk_widget_set_size_request (checkbutton1, 155, 24);

  checkbutton3 = gtk_check_button_new_with_mnemonic (_("Abri V\303\251lo"));
  gtk_widget_show (checkbutton3);
  gtk_fixed_put (GTK_FIXED (fixed9), checkbutton3, 712, 400);
  gtk_widget_set_size_request (checkbutton3, 118, 24);

  checkbutton4 = gtk_check_button_new_with_mnemonic (_("Vid\303\251o surveillance"));
  gtk_widget_show (checkbutton4);
  gtk_fixed_put (GTK_FIXED (fixed9), checkbutton4, 400, 400);
  gtk_widget_set_size_request (checkbutton4, 152, 24);

  checkbutton2 = gtk_check_button_new_with_mnemonic (_("Acc\303\250s handicap\303\251s"));
  gtk_widget_show (checkbutton2);
  gtk_fixed_put (GTK_FIXED (fixed9), checkbutton2, 560, 400);
  gtk_widget_set_size_request (checkbutton2, 151, 24);

  confirmer_RL = gtk_button_new ();
  gtk_widget_show (confirmer_RL);
  gtk_fixed_put (GTK_FIXED (fixed9), confirmer_RL, 648, 544);
  gtk_widget_set_size_request (confirmer_RL, 112, 40);

  alignment18 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment18);
  gtk_container_add (GTK_CONTAINER (confirmer_RL), alignment18);

  hbox16 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox16);
  gtk_container_add (GTK_CONTAINER (alignment18), hbox16);

  image27 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image27);
  gtk_box_pack_start (GTK_BOX (hbox16), image27, FALSE, FALSE, 0);

  label89 = gtk_label_new_with_mnemonic (_("Confirmer"));
  gtk_widget_show (label89);
  gtk_box_pack_start (GTK_BOX (hbox16), label89, FALSE, FALSE, 0);

  fixed13 = gtk_fixed_new ();
  gtk_widget_show (fixed13);
  gtk_fixed_put (GTK_FIXED (fixed9), fixed13, 880, 64);
  gtk_widget_set_size_request (fixed13, 608, 757);

  cellview7 = gtk_cell_view_new ();
  gtk_widget_show (cellview7);
  gtk_fixed_put (GTK_FIXED (fixed13), cellview7, 384, 264);
  gtk_widget_set_size_request (cellview7, 50, 50);

  idRecherche_RL = gtk_entry_new ();
  gtk_widget_show (idRecherche_RL);
  gtk_fixed_put (GTK_FIXED (fixed13), idRecherche_RL, 536, 40);
  gtk_widget_set_size_request (idRecherche_RL, 160, 32);
  gtk_entry_set_text (GTK_ENTRY (idRecherche_RL), _("id \303\240 rechercher..."));
  gtk_entry_set_invisible_char (GTK_ENTRY (idRecherche_RL), 8226);

  treeviewParking_RL = gtk_tree_view_new ();
  gtk_widget_show (treeviewParking_RL);
  gtk_fixed_put (GTK_FIXED (fixed13), treeviewParking_RL, 16, 80);
  gtk_widget_set_size_request (treeviewParking_RL, 752, 216);

  actualiser1_RL = gtk_button_new ();
  gtk_widget_show (actualiser1_RL);
  gtk_fixed_put (GTK_FIXED (fixed13), actualiser1_RL, 16, 8);
  gtk_widget_set_size_request (actualiser1_RL, 66, 29);

  image42 = gtk_image_new_from_stock ("gtk-refresh", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image42);
  gtk_container_add (GTK_CONTAINER (actualiser1_RL), image42);

  hbuttonbox7 = gtk_hbutton_box_new ();
  gtk_widget_show (hbuttonbox7);
  gtk_fixed_put (GTK_FIXED (fixed13), hbuttonbox7, 680, 392);
  gtk_widget_set_size_request (hbuttonbox7, 170, 29);

  button23 = gtk_button_new ();
  gtk_widget_show (button23);
  gtk_fixed_put (GTK_FIXED (fixed13), button23, 656, 304);
  gtk_widget_set_size_request (button23, 112, 40);

  alignment23 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment23);
  gtk_container_add (GTK_CONTAINER (button23), alignment23);

  hbox21 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox21);
  gtk_container_add (GTK_CONTAINER (alignment23), hbox21);

  image38 = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image38);
  gtk_box_pack_start (GTK_BOX (hbox21), image38, FALSE, FALSE, 0);

  label122 = gtk_label_new_with_mnemonic (_("Supprimer"));
  gtk_widget_show (label122);
  gtk_box_pack_start (GTK_BOX (hbox21), label122, FALSE, FALSE, 0);

  button24 = gtk_button_new ();
  gtk_widget_show (button24);
  gtk_fixed_put (GTK_FIXED (fixed13), button24, 536, 304);
  gtk_widget_set_size_request (button24, 112, 40);

  alignment24 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment24);
  gtk_container_add (GTK_CONTAINER (button24), alignment24);

  hbox22 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox22);
  gtk_container_add (GTK_CONTAINER (alignment24), hbox22);

  image39 = gtk_image_new_from_stock ("gtk-edit", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image39);
  gtk_box_pack_start (GTK_BOX (hbox22), image39, FALSE, FALSE, 0);

  label123 = gtk_label_new_with_mnemonic (_("Modifier"));
  gtk_widget_show (label123);
  gtk_box_pack_start (GTK_BOX (hbox22), label123, FALSE, FALSE, 0);

  chercher_RL = gtk_button_new ();
  gtk_widget_show (chercher_RL);
  gtk_fixed_put (GTK_FIXED (fixed13), chercher_RL, 704, 40);
  gtk_widget_set_size_request (chercher_RL, 64, 32);

  image41 = gtk_image_new_from_stock ("gtk-find", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image41);
  gtk_container_add (GTK_CONTAINER (chercher_RL), image41);

  label125 = gtk_label_new_with_mnemonic (_("<span foreground=\"brown\">Liste des parkings</span>"));
  gtk_widget_show (label125);
  gtk_fixed_put (GTK_FIXED (fixed13), label125, 8, 40);
  gtk_widget_set_size_request (label125, 144, 40);
  gtk_label_set_use_markup (GTK_LABEL (label125), TRUE);

  fixed14 = gtk_fixed_new ();
  gtk_widget_show (fixed14);
  gtk_fixed_put (GTK_FIXED (fixed9), fixed14, 880, 424);
  gtk_widget_set_size_request (fixed14, 725, 397);

  treeviewAgent_RL = gtk_tree_view_new ();
  gtk_widget_show (treeviewAgent_RL);
  gtk_fixed_put (GTK_FIXED (fixed14), treeviewAgent_RL, 24, 128);
  gtk_widget_set_size_request (treeviewAgent_RL, 280, 240);

  button33 = gtk_button_new ();
  gtk_widget_show (button33);
  gtk_fixed_put (GTK_FIXED (fixed14), button33, 624, 344);
  gtk_widget_set_size_request (button33, 152, 45);

  alignment29 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment29);
  gtk_container_add (GTK_CONTAINER (button33), alignment29);

  hbox27 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox27);
  gtk_container_add (GTK_CONTAINER (alignment29), hbox27);

  image48 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image48);
  gtk_box_pack_start (GTK_BOX (hbox27), image48, FALSE, FALSE, 0);

  label140 = gtk_label_new_with_mnemonic (_("Affecter"));
  gtk_widget_show (label140);
  gtk_box_pack_start (GTK_BOX (hbox27), label140, FALSE, FALSE, 0);

  comboboxParky_RL = gtk_combo_box_entry_new_text ();
  gtk_widget_show (comboboxParky_RL);
  gtk_fixed_put (GTK_FIXED (fixed14), comboboxParky_RL, 440, 128);
  gtk_widget_set_size_request (comboboxParky_RL, 165, 36);

  label137 = gtk_label_new_with_mnemonic (_("<span foreground=\"brown\">Parking sans agent : </span>"));
  gtk_widget_show (label137);
  gtk_fixed_put (GTK_FIXED (fixed14), label137, 448, 80);
  gtk_widget_set_size_request (label137, 144, 40);
  gtk_label_set_use_markup (GTK_LABEL (label137), TRUE);

  label136 = gtk_label_new_with_mnemonic (_("<span foreground=\"darkblue\">Affecter un agent \303\240 un parking </span>"));
  gtk_widget_show (label136);
  gtk_fixed_put (GTK_FIXED (fixed14), label136, 216, 8);
  gtk_widget_set_size_request (label136, 248, 48);
  gtk_label_set_use_markup (GTK_LABEL (label136), TRUE);

  label138 = gtk_label_new_with_mnemonic (_("<span foreground=\"brown\">Liste des agents non affect\303\251s </span>"));
  gtk_widget_show (label138);
  gtk_fixed_put (GTK_FIXED (fixed14), label138, 48, 88);
  gtk_widget_set_size_request (label138, 213, 17);
  gtk_label_set_use_markup (GTK_LABEL (label138), TRUE);

  label141 = gtk_label_new (_("Gestion des parkings "));
  gtk_widget_show (label141);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook2), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook2), 0), label141);

  g_signal_connect ((gpointer) Actif_RL, "toggled",
                    G_CALLBACK (on_radiobutton_RL_toggled),
                    NULL);
  g_signal_connect ((gpointer) Inactif_RL, "toggled",
                    G_CALLBACK (on_Inactif_RL_toggled),
                    NULL);
  g_signal_connect ((gpointer) button16, "clicked",
                    G_CALLBACK (on_RL_buttonR_clicked),
                    NULL);
  g_signal_connect ((gpointer) checkbutton1, "toggled",
                    G_CALLBACK (on_checkbutton1_toggled),
                    NULL);
  g_signal_connect ((gpointer) checkbutton3, "toggled",
                    G_CALLBACK (on_checkbutton3_toggled),
                    NULL);
  g_signal_connect ((gpointer) checkbutton4, "toggled",
                    G_CALLBACK (on_checkbutton4_toggled),
                    NULL);
  g_signal_connect ((gpointer) checkbutton2, "toggled",
                    G_CALLBACK (on_checkbutton2_toggled),
                    NULL);
  g_signal_connect ((gpointer) confirmer_RL, "clicked",
                    G_CALLBACK (on_RL_BCom_clicked),
                    NULL);
  g_signal_connect ((gpointer) treeviewParking_RL, "map",
                    G_CALLBACK (on_treeviewParking_RL_map),
                    NULL);
  g_signal_connect ((gpointer) actualiser1_RL, "clicked",
                    G_CALLBACK (on_actualiser1_RL_clicked),
                    NULL);
  g_signal_connect ((gpointer) button23, "clicked",
                    G_CALLBACK (on_Rl_buttonSupp_clicked),
                    NULL);
  g_signal_connect ((gpointer) button24, "clicked",
                    G_CALLBACK (on_RL_buttonMod_clicked),
                    NULL);
  g_signal_connect ((gpointer) chercher_RL, "clicked",
                    G_CALLBACK (on_chercher_RL_clicked),
                    NULL);
  g_signal_connect ((gpointer) treeviewAgent_RL, "map",
                    G_CALLBACK (on_treeviewAgent_RL_map),
                    NULL);
  g_signal_connect ((gpointer) button33, "clicked",
                    G_CALLBACK (on_RL_Affecter_clicked),
                    NULL);
  g_signal_connect ((gpointer) comboboxParky_RL, "map",
                    G_CALLBACK (on_comboboxParky_RL_map),
                    NULL);

  gtk_label_set_mnemonic_widget (GTK_LABEL (label92), add_RL);
  gtk_label_set_mnemonic_widget (GTK_LABEL (label93), cap_RL);
  gtk_label_set_mnemonic_widget (GTK_LABEL (label90), id_Rl);
  gtk_label_set_mnemonic_widget (GTK_LABEL (label95), tarif_RL);
  gtk_label_set_mnemonic_widget (GTK_LABEL (label99), nb_RL);
  gtk_label_set_mnemonic_widget (GTK_LABEL (label96), checkbutton1);
  gtk_label_set_mnemonic_widget (GTK_LABEL (label97), horaire_RL);
  gtk_label_set_mnemonic_widget (GTK_LABEL (label125), idRecherche_RL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (RL_Admin, RL_Admin, "RL_Admin");
  GLADE_HOOKUP_OBJECT (RL_Admin, alignment12, "alignment12");
  GLADE_HOOKUP_OBJECT (RL_Admin, notebook2, "notebook2");
  GLADE_HOOKUP_OBJECT (RL_Admin, fixed9, "fixed9");
  GLADE_HOOKUP_OBJECT (RL_Admin, nom_RL, "nom_RL");
  GLADE_HOOKUP_OBJECT (RL_Admin, add_RL, "add_RL");
  GLADE_HOOKUP_OBJECT (RL_Admin, cap_RL, "cap_RL");
  GLADE_HOOKUP_OBJECT (RL_Admin, horaire_RL, "horaire_RL");
  GLADE_HOOKUP_OBJECT (RL_Admin, nb_RL, "nb_RL");
  GLADE_HOOKUP_OBJECT (RL_Admin, tarif_RL, "tarif_RL");
  GLADE_HOOKUP_OBJECT (RL_Admin, id_Rl, "id_Rl");
  GLADE_HOOKUP_OBJECT (RL_Admin, label91, "label91");
  GLADE_HOOKUP_OBJECT (RL_Admin, label92, "label92");
  GLADE_HOOKUP_OBJECT (RL_Admin, label93, "label93");
  GLADE_HOOKUP_OBJECT (RL_Admin, label94, "label94");
  GLADE_HOOKUP_OBJECT (RL_Admin, label101, "label101");
  GLADE_HOOKUP_OBJECT (RL_Admin, image34, "image34");
  GLADE_HOOKUP_OBJECT (RL_Admin, label103, "label103");
  GLADE_HOOKUP_OBJECT (RL_Admin, label90, "label90");
  GLADE_HOOKUP_OBJECT (RL_Admin, label95, "label95");
  GLADE_HOOKUP_OBJECT (RL_Admin, label99, "label99");
  GLADE_HOOKUP_OBJECT (RL_Admin, label96, "label96");
  GLADE_HOOKUP_OBJECT (RL_Admin, label97, "label97");
  GLADE_HOOKUP_OBJECT (RL_Admin, _Statut_RL, "_Statut_RL");
  GLADE_HOOKUP_OBJECT (RL_Admin, Actif_RL, "Actif_RL");
  GLADE_HOOKUP_OBJECT (RL_Admin, Inactif_RL, "Inactif_RL");
  GLADE_HOOKUP_OBJECT (RL_Admin, button16, "button16");
  GLADE_HOOKUP_OBJECT (RL_Admin, alignment19, "alignment19");
  GLADE_HOOKUP_OBJECT (RL_Admin, hbox17, "hbox17");
  GLADE_HOOKUP_OBJECT (RL_Admin, image28, "image28");
  GLADE_HOOKUP_OBJECT (RL_Admin, label100, "label100");
  GLADE_HOOKUP_OBJECT (RL_Admin, type_RL, "type_RL");
  GLADE_HOOKUP_OBJECT (RL_Admin, checkbutton1, "checkbutton1");
  GLADE_HOOKUP_OBJECT (RL_Admin, checkbutton3, "checkbutton3");
  GLADE_HOOKUP_OBJECT (RL_Admin, checkbutton4, "checkbutton4");
  GLADE_HOOKUP_OBJECT (RL_Admin, checkbutton2, "checkbutton2");
  GLADE_HOOKUP_OBJECT (RL_Admin, confirmer_RL, "confirmer_RL");
  GLADE_HOOKUP_OBJECT (RL_Admin, alignment18, "alignment18");
  GLADE_HOOKUP_OBJECT (RL_Admin, hbox16, "hbox16");
  GLADE_HOOKUP_OBJECT (RL_Admin, image27, "image27");
  GLADE_HOOKUP_OBJECT (RL_Admin, label89, "label89");
  GLADE_HOOKUP_OBJECT (RL_Admin, fixed13, "fixed13");
  GLADE_HOOKUP_OBJECT (RL_Admin, cellview7, "cellview7");
  GLADE_HOOKUP_OBJECT (RL_Admin, idRecherche_RL, "idRecherche_RL");
  GLADE_HOOKUP_OBJECT (RL_Admin, treeviewParking_RL, "treeviewParking_RL");
  GLADE_HOOKUP_OBJECT (RL_Admin, actualiser1_RL, "actualiser1_RL");
  GLADE_HOOKUP_OBJECT (RL_Admin, image42, "image42");
  GLADE_HOOKUP_OBJECT (RL_Admin, hbuttonbox7, "hbuttonbox7");
  GLADE_HOOKUP_OBJECT (RL_Admin, button23, "button23");
  GLADE_HOOKUP_OBJECT (RL_Admin, alignment23, "alignment23");
  GLADE_HOOKUP_OBJECT (RL_Admin, hbox21, "hbox21");
  GLADE_HOOKUP_OBJECT (RL_Admin, image38, "image38");
  GLADE_HOOKUP_OBJECT (RL_Admin, label122, "label122");
  GLADE_HOOKUP_OBJECT (RL_Admin, button24, "button24");
  GLADE_HOOKUP_OBJECT (RL_Admin, alignment24, "alignment24");
  GLADE_HOOKUP_OBJECT (RL_Admin, hbox22, "hbox22");
  GLADE_HOOKUP_OBJECT (RL_Admin, image39, "image39");
  GLADE_HOOKUP_OBJECT (RL_Admin, label123, "label123");
  GLADE_HOOKUP_OBJECT (RL_Admin, chercher_RL, "chercher_RL");
  GLADE_HOOKUP_OBJECT (RL_Admin, image41, "image41");
  GLADE_HOOKUP_OBJECT (RL_Admin, label125, "label125");
  GLADE_HOOKUP_OBJECT (RL_Admin, fixed14, "fixed14");
  GLADE_HOOKUP_OBJECT (RL_Admin, treeviewAgent_RL, "treeviewAgent_RL");
  GLADE_HOOKUP_OBJECT (RL_Admin, button33, "button33");
  GLADE_HOOKUP_OBJECT (RL_Admin, alignment29, "alignment29");
  GLADE_HOOKUP_OBJECT (RL_Admin, hbox27, "hbox27");
  GLADE_HOOKUP_OBJECT (RL_Admin, image48, "image48");
  GLADE_HOOKUP_OBJECT (RL_Admin, label140, "label140");
  GLADE_HOOKUP_OBJECT (RL_Admin, comboboxParky_RL, "comboboxParky_RL");
  GLADE_HOOKUP_OBJECT (RL_Admin, label137, "label137");
  GLADE_HOOKUP_OBJECT (RL_Admin, label136, "label136");
  GLADE_HOOKUP_OBJECT (RL_Admin, label138, "label138");
  GLADE_HOOKUP_OBJECT (RL_Admin, label141, "label141");

  return RL_Admin;
}

